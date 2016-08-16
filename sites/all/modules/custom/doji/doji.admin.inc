<?php

/**
 * @file
 * Admin page callbacks for the system module.
 */
function doji_admin_page($arg = NULL) {
  drupal_set_title('Trang quản trị', array(), 'vi');
  return t('Trang này chưa được kích hoạt', array(), 'vi');
}

/**
 * @file
 * Admin page callback file for the user module.
 */

function doji_user_admin($callback_arg = '') {
  drupal_set_title('');
  module_load_include('inc', 'user', 'user.admin');
  $op = isset($_POST['op']) ? $_POST['op'] : $callback_arg;

  switch ($op) {
    case t('Create new account'):
    case 'create':
      $output = drupal_get_form('user_register');
      break;
    default:
      if (!empty($_POST['accounts']) && isset($_POST['operation']) && ($_POST['operation'] == 'delete')) {
        $output = drupal_get_form('user_multiple_delete_confirm');
      }
      else {
        $output = drupal_get_form('user_filter_form');
        $output .= drupal_get_form('user_admin_account');
      }
  }
  return $output;
}

/**
 * Menu callback: administer permissions.
 *
 * @ingroup forms
 * @see user_admin_perm_submit()
 * @see theme_user_admin_perm()
 */
function doji_user_admin_perm() {
  drupal_set_title('');
  module_load_include('inc', 'user', 'user.admin');  
  return drupal_get_form('user_admin_perm');
}  
//tri
function doji_admin_settings_set_value($form) {

  $ascii_code = '66';
  $suffix = array('_muavao', '_banra', '_chenhlech');
  $inc = 0;
  $formula_form = &$form['formula_groups'];
  $formula_groups = variable_get('formula_groups', array());
  foreach ($formula_form as $k => &$element) {
    if (is_object($element)) {
      $element = (array)$element;
    }
    if (!isset($element['#type'])) {
      continue;
    }
    if ($element['#type'] != 'fieldset') {
      continue;
    }

    $fieldname = str_replace('formula_group_', 'field_', $k);

    if (!isset($element[$fieldname .'_muavao'])) {
      continue;
    }

    $inc++;

    foreach ($suffix as $key => $suffix_value) {
      if (isset($element[$fieldname . $suffix_value])) {
        $variable = chr($ascii_code + $key) . $inc;
        $element[$fieldname . $suffix_value]['id']['#default_value'] =  $inc;
        $element[$fieldname . $suffix_value]['variable']['#default_value'] =  $variable;
        $element[$fieldname . $suffix_value]['operator']['#default_value'] =  $variable;
        $element[$fieldname . $suffix_value]['active']['#default_value'] =  1;

        if (isset($formula_groups[$k][$fieldname . $suffix_value]['variable'])) {
          //$element[$fieldname . $suffix_value]['variable']['#default_value'] = $formula_groups[$k][$fieldname . $suffix_value]['variable'];
        }
        if (isset($formula_groups[$k][$fieldname . $suffix_value]['operator'])) {
          $element[$fieldname . $suffix_value]['operator']['#default_value'] = $formula_groups[$k][$fieldname . $suffix_value]['operator'];
        }
        if (isset($formula_groups[$k][$fieldname . $suffix_value]['active'])) {
          $element[$fieldname . $suffix_value]['active']['#default_value'] = $formula_groups[$k][$fieldname . $suffix_value]['active'];
        }
      }
    }
  }

  return $form;
}

function doji_admin_settings() {
  $form = doji_get_node_form();

  $groups = $form['#groups'];
  $fields = $form['#fields'];     
  $formula_form = array();  
  $formula_form['formula_groups'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,       
  );
  foreach ($groups as $group_name) {
    $formula_group_name = 'formula_' . $group_name;
    $formula_form['formula_groups'][$formula_group_name] = array(
      '#type' => 'fieldset',
      '#title' => $form[$group_name]['label']['#value'],
      '#tree' => TRUE,      
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,    
    );
    if (isset($form[$group_name]['#weight'])) {
      $formula_form['formula_groups'][$formula_group_name]['#weight'] = $form[$group_name]['#weight'];   
    }

    if (isset($form[$group_name]['group']['#value']['fields'])) {

      $group_desciption = NULL;

      if (isset($form[$group_name]['group']['#value']['settings']['display']['description'])) {
        $group_desciption = $form[$group_name]['group']['#value']['settings']['display']['description'];
      }

      $formula_form['formula_groups'][$formula_group_name]['group_name'] = array(
        '#type' => 'hidden',
        '#default_value' => $group_name,                   
      );

      $formula_form['formula_groups'][$formula_group_name]['group_label'] = array(
        '#type' => 'textfield',
        '#title' => NULL,
        '#default_value' => $form[$group_name]['label']['#value'],
        '#attributes' => array('class' => 'group-label', 'group_name'=>$group_name, 'group_description'=>$group_desciption),
        '#size' => 20,
      );
      foreach ($form[$group_name]['group']['#value']['fields'] as $field_name => $children) {
        $formula_form['formula_groups'][$formula_group_name][$field_name]['id'] = array(
          '#type' => 'hidden',                    
        );
        $formula_form['formula_groups'][$formula_group_name][$field_name]['operator'] = array(
          '#type' => 'textfield',               
          '#title' => $form[$field_name]['label']['#value'],
          '#weight' => $form[$field_name]['#weight'],
          '#size' => 10,       
        );
        $formula_form['formula_groups'][$formula_group_name][$field_name]['variable'] = array(
          '#type' => 'hidden',                    
        );  
        $formula_form['formula_groups'][$formula_group_name][$field_name]['active'] = array(
          '#type' => 'hidden'
        );
      }  
    }    
  }

  $formula_form = doji_admin_settings_set_value($formula_form);
  $formula_form['buttons']['add_goldprice'] = array(
    '#type' => 'button',
    '#value' => t('Thêm giá mới', array(), 'vi'),
    '#attributes' => array('onclick' => 'return false;'),
  );   
  $formula_form['#validate'][] = 'doji_admin_settings_validate';  
  drupal_set_title('');
  return $formula_form;
}

function doji_admin_settings_submit($form, &$form_state) {
  $formula_groups = variable_get('formula_groups', array());
  if (!arg(3)) {
    $formula_groups = $form_state['values']['formula_groups'];    
    variable_set('formula_groups', $formula_groups);
    drupal_set_message(t('Thiết lập thành công.', array(), 'vi'));
  }
  else {    
    $object = new stdClass;
    if (isset($formula_groups[arg(3)]) && isset($form_state['values']['formula_groups'][arg(3)])){
      $formula_groups[arg(3)] = $form_state['values']['formula_groups'][arg(3)]; 
      variable_set('formula_groups', $formula_groups);
      drupal_set_message(t('Thiết lập thành công.', array(), 'vi'));
      $object->error = 0;
    }     
    else {
      drupal_set_message(t('Thiết lập không thành công.', array(), 'vi'));  
      $object->error = 1;
    }
    drupal_json($object);exit;    
  }   
}

function doji_admin_settings_validate($form, &$form_state) {
  return;
  $form_values = $form_state['values'];
  $edit = $form_values;
  foreach ($edit as $delta => $item) {
    if ($item['calc'] == '' || !is_numeric($delta)) {
      // remove blank fields, don't save them
      unset($form_values[$delta]);
    } else {
      // Remove all valid values from calc, if anything is left over, it is invalid.

      // First, remove all field names.
      $repl = array();
      $patterns = array();
      foreach (_views_calc_substitutions() as $key => $value) {
        $key = trim($value);
        $count = strlen($value);
        $replace = preg_quote($value);
        $patterns[] = "`(^|[^\\\\\\\\])". $replace ."`";
        $repl[] = '${1}';
      }
      $remaining = trim(preg_replace($patterns, $repl, $item['calc']));
      // Next, remove functions and numbers.
      $repl = array();
      $patterns = array();
      foreach (_views_calc_replacements() as $value) {
        $patterns[] = "`(^|[^\\\\\\\\])". preg_quote(trim($value)) ."`";
        $repl[] = '${1}';
      }
      $remaining = trim(preg_replace($patterns, $repl, $remaining));
      if (!empty($remaining)) {
        form_set_error($form_values[$delta]['calc'], t('The values %remaining in %field are not allowed.', array('%remaining' => $remaining, '%field' => $item['label'])));
      }
    }
  }  
}

function doji_admin_global_settings() {
  $global_settings = variable_get('doji_global_settings', array());
  $form = array();
  $form['doji_global_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Thiết lập chung', array(), 'vi'),
    '#tree' => TRUE,      
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,   
    '#attributes' => array('class' => 'global-settings'),
  );
  $form['doji_global_settings']['url_currencyrate'] = array(
    '#title' => t('URL lấy tỷ giá tiền tệ trực tiếp', array(), 'vi'),    
    '#type' => 'textfield',
    '#default_value' => isset($global_settings['url_currencyrate']) ? $global_settings['url_currencyrate'] : '',                           
  ); 
  $form['doji_global_settings']['url_exchangerate'] = array(
    '#title' => t('URL lấy tỷ giá ngoại tệ', array(), 'vi'),    
    '#type' => 'textfield',
    '#default_value' => isset($global_settings['url_exchangerate']) ? $global_settings['url_exchangerate'] : '',                           
  );   
  $form['doji_global_settings']['url_bieudo_giavang_quocte'] = array(
    '#title' => t('URL biểu đồ giá vàng quốc tế', array(), 'vi'),    
    '#type' => 'textfield',
    '#default_value' => isset($global_settings['url_bieudo_giavang_quocte']) ? $global_settings['url_bieudo_giavang_quocte'] : '',                           
  );      
  $form['doji_global_settings']['spread'] = array(
    '#title' => t('Độ chênh lệch', array(), 'vi'),
    '#type' => 'textfield',
    '#description' => t('Sử dụng độ chênh lệch cho các dữ liệu', array(), 'vi'),
    '#default_value' => isset($global_settings['spread']) ? $global_settings['spread'] : 0,                     
  );   
  $form['doji_global_settings']['banle_spread'] = array(
    '#title' => t('Độ chênh lệch cho giá bán lẻ', array(), 'vi'),
    '#type' => 'textfield',
    '#description' => t('Sử dụng độ chênh lệch cho dữ liệu giá bán lẻ', array(), 'vi'),
    '#default_value' => isset($global_settings['banle_spread']) ? $global_settings['banle_spread'] : 0,                     
  );   
  $form['doji_global_settings']['banbuon_spread'] = array(
    '#title' => t('Độ chênh lệch cho giá bán bán buôn', array(), 'vi'),
    '#type' => 'textfield',  
    '#description' => t('Sử dụng độ chênh lệch cho dữ liệu giá bán buôn', array(), 'vi'),  
    '#default_value' => isset($global_settings['banbuon_spread']) ? $global_settings['banbuon_spread'] : 0,                     
  );       
  $form['doji_global_settings']['click_spread'] = array(
    '#title' => t('Độ tăng/giảm cho mỗi lần click', array(), 'vi'),    
    '#type' => 'textfield',
    '#description' => t('Thông số này có hiệu lực với nhập 2 nút : Tăng/Giảm trong quá trình nhập giá', array(), 'vi'),
    '#default_value' => isset($global_settings['click_spread']) ? $global_settings['click_spread'] : 1,                     
  );        
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Lưu thiết lập', array(), 'vi')
  );   
  drupal_set_title('');
  return system_settings_form($form);
}

function doji_admin_goldprice_view_setting() {
  module_load_include('inc', 'node', 'node.pages');
  $node = node_load(1);
  $form = node_page_edit($node);
  $form = '<div class="clear-form goldprice-sxht">' . $form . '</div>';
  return $form;
}

function doji_admin_group_description_setting() {
  $obj = db_fetch_object(db_query_range('SELECT * FROM {content_group} WHERE type_name="%s" AND group_name="%s"', arg(4), arg(3), 0, 1));

  if (!isset($obj->type_name)) {
    drupal_set_message(t('Dữ liệu không hợp lê, xin vui lòng kiểm tra lại.', array(), 'vi'));
    drupal_goto();
  }

  $description = '';

  if (isset($obj->settings)) {
    $settings = unserialize($obj->settings);
    if (isset($settings['display']['description'])) {
      $description = $settings['display']['description'];
    }
  }

  $form = array();
  $form['type_name'] = array(
    '#type' => 'value',
    '#value' => $obj->type_name,
  ); 
  $form['group_name'] = array(
    '#type' => 'value',
    '#value' => $obj->group_name,
  ); 
  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Mô tả', array(), 'vi'),
    '#default_value' => $description,
  );    
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Lưu thiết lập', array(), 'vi')
  );   
  return $form;
}

function doji_admin_group_description_setting_submit($form, &$form_state) {
  $values = $form_state['values'];
  $obj = db_fetch_object(db_query_range('SELECT * FROM {content_group} WHERE type_name="%s" AND group_name="%s"', $values['type_name'], $values['group_name'], 0, 1));

  if (isset($obj->settings)) {
    $settings = unserialize($obj->settings);

    if (isset($settings['display']['description'])) {
      $settings['display']['description'] = $values['description'];
    }

    $settings = serialize($settings);
    db_query('UPDATE {content_group} SET settings = "%s" WHERE type_name="%s" AND group_name="%s"', $settings, $values['type_name'], $values['group_name']);
  }

  drupal_set_message(t('Cập nhật <strong>Mô tả</strong> thành công.', array(), 'vi'));
}