<?php

/**
 * @file
 * Ganeral JS content
 */

function doji_calculator_js() {  
  $formula_groups = variable_get('formula_groups', array());
  $js = array();  
  foreach ($formula_groups as $group_name => $groups) {
    if (is_array($groups) && count($groups)) {
      foreach ($groups as $fieldname => $element) {
        if (!$element['active']) {
          break;
        }
        $variable = strtolower(trim($element['variable']));        
        $operator = doji_js_replace_operator(strtolower(trim($element['operator'])));
        $js['vars'][$variable] = $variable . ' = 0;';
        //$js['get-variables'][$variable] = $variable . ' = ' . '$(\'input[var="' . $variable . '"]\').val();';
        $js['set-variables'][$variable] = "
          if (Math.abs($variable) > 0 && \$element.attr('var') != '$variable') {            
            $('input[var=\"$variable\"]').val($variable);  
          }
        ";        
        $js['get-variables'][$variable] = $variable . ' = ' . 'Drupal.goldpriceCalculator.clearThousandsSep($(\'input[var="' . $variable . '"]\'));';
        
        if (is_numeric($operator)) {
          $js['get-variables'][$variable] = $variable . ' = ' . $operator . ';';   
        }
        else if ($variable != $operator && $operator != '-') {
          $js['operators'][$variable] = $variable . ' = ' . $operator . ';';            
          $var_dependencies = doji_js_get_variable($operator);          
          if ($var_dependencies) {
            $js['operators'][$variable] = $variable . ' = Drupal.goldpriceCalculator.toFixed(' . $operator . ');';
            $str_dependencies = implode('>0 && ', $var_dependencies);
            $js['operators'][$variable] = '
              if (' . $str_dependencies . '>0) {
                 ' . $js['operators'][$variable] . '
              }
            ';
          }
                  
        }        
      } 
    }    
  }
  //array_shift($js['set-variables']);
  $jscontent = implode("\n", $js['get-variables']);
  $jscontent .= "\n";  
  $jscontent .= implode("\n", $js['operators']);
  $jscontent .= "\n";  
  //$jscontent .= "alert(e2);";
  $jscontent .= implode("\n", $js['set-variables']);
  $jscontent .= "\n";    
  $jscontent = '   
    Drupal.behaviors.doji = function(context) {
      $(\'input.gold-price-input\', context).each(function() {
        var $element = $(this);
    
        // Number of decimal places for this element.
        var decimals = $element.attr(\'decimals\');
        decimals = (decimals == undefined ? -1 : Math.max(-1, parseInt(decimals)));
    
        // The element is properly formatted on page load.
        Drupal.numericElement.formatElement($element, decimals);
    
        // Bind element events.
        $element.bind(\'blur\', function() {
          Drupal.numericElement.formatElement($element, decimals);
        });

        $element.keyup(function (event) {          
          Drupal.goldpriceCalculator.onkeyup($element, event);  
          Drupal.goldpriceCalculator.formatAll(context);                         
        });                         
      });
    }

    Drupal.goldpriceCalculator = Drupal.goldpriceCalculator || {};
    Drupal.goldpriceCalculator.setval = function($element, value) {
      var decimals = $element.attr(\'decimals\');
      decimals = (decimals == undefined ? -1 : Math.max(-1, parseInt(decimals)));
      if (value.length > 0) {
        value = Drupal.parseNumber(value, false);
        if (typeof(value) == \'number\') {
          number = Drupal.formatNumber(value, decimals);
        }
        $element.val(value);
      }
    };    
    Drupal.goldpriceCalculator.toFixed = function (n) {
      return Math.round(n * 100000)/100000;
    };    
    Drupal.goldpriceCalculator.calculator = function($element) {
      ' . $jscontent . '          
    };    
    Drupal.goldpriceCalculator.formatAll = function(context) {
      $(\'input.gold-price-input\', context).each(function() {
        var decimals = $(this).attr(\'decimals\');
        decimals = (decimals == undefined ? -1 : Math.max(-1, parseInt(decimals)));            
        Drupal.numericElement.formatElement($(this), decimals);
      });      
    }
	
    Drupal.goldpriceCalculator.clearThousandsSep = function($element) {
      var number = $element.val();      
	  if ( typeof number !== "undefined" && number)  {
      if (number.length > 0 && Drupal.settings.format_number.thousands_sep.length > 0) {
        var thsep = Drupal.settings.format_number.thousands_sep;
        if (thsep == \'\u00A0\') {
          thsep += \' \';
        }
        number = number.replace(new RegExp(\'[\'+ thsep +\']\', \'g\'), \'\');        
      }  
      }
      number = parseFloat(number);    
      
      if (isNaN(number)) {
        number = 0;
      }
      
      return number;
    };   
    Drupal.goldpriceCalculator.onkeyup = function (input, e) {
      if (!e) {
        e = window.event;
      }
      switch (e.keyCode) {
        case 16: // shift
        case 17: // ctrl
        case 18: // alt
        case 20: // caps lock
        case 33: // page up
        case 34: // page down
        case 35: // end
        case 36: // home
        case 37: // left arrow
        case 38: // up arrow
        case 39: // right arrow
        case 40: // down arrow
          return true;
    
        case 9:  // tab
        case 13: // enter
        case 27: // esc 
          return true;
    
        default: // all other keys
          if (input.val().length) {
            Drupal.goldpriceCalculator.calculator(input);
          }
          
          if (input.hasClass(\'error\')) {
            var error = 0;
            input.parents(\'tr:first\').find(\'.form-text\').each(function(){
              if (Drupal.goldpriceCalculator.clearThousandsSep($(this)) < 0) {
                error = 1;                             
              }                 
            }) 
            
            if (!error) {
              input.parents(\'tr:first\').find(\'.form-text\').each(function(){
                $(this).removeClass(\'error\');                 
              })               
            } 
          }

                                                
          return true;
      }
    };            
  ';
  
  $jscontent = '
    (function ($) {
      ' . $jscontent . '
    })(jQuery);  
  ';
  print $jscontent;
  exit;
}

function doji_js_get_variable($text = NULL) {
  static $cached;
  if (!isset($cached[$text])) {
    preg_match_all('|([a-z]+(\d+))|i', $text, $t);
    if (isset($t[1]) && count($t[1])) {
      $cached[$text] = $t[1];  
    }  
  }
  
  if (!isset($cached[$text])) {
    $cached[$text] = FALSE;  
  }
  
  return $cached[$text];
}

function doji_js_replace_operator($text = NULL) {
  static $cached;
  if (!isset($cached[$text])) {
    $text = str_replace('round', 'Math.round', $text);
    $text = str_replace(',', '', $text);
    $cached[$text] = $text; 
  }
  
  if (!isset($cached[$text])) {
    $cached[$text] = FALSE;  
  }
  
  return $cached[$text];
}