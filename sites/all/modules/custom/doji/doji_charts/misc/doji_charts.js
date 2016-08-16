(function ($) {   
Drupal.behaviors.doji_charts = function(context) {
  $('#doji-chart-short-form .form-text', context).focus(function(){
    $(this).parents('form:first').find('.form-submit').css({'color' : '#666'});     
  });
  $('#doji-chart-short-form .form-text', context).blur(function(){
    $(this).parents('form:first').find('.form-submit').css({'color' : '#000'});     
  });  
  $('#doji-chart-short-form .form-submit', context).click(function(){
    var $this = $(this);
    var $form = $this.parents('form:first');    
    $time1 = $form.find('input[@name="from[date]"]:eq(0)').val();
    $time2 = $form.find('input[@name="to[date]"]:eq(1)').val();
    
    if ($time1 != '' || $time2 != '') {
      $('iframe#iframe-chart').attr('src', $this.attr('action') + '&' + $form.serialize());
      $('iframe#iframe-chart').show(1500);
    }
    return false;
  });         
}; 
})(jQuery);  
