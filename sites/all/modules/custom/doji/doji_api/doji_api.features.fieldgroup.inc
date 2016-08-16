<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function doji_api_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_api_giavang_quocte
  $groups['api-group_api_giavang_quocte'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'api',
    'group_name' => 'group_api_giavang_quocte',
    'label' => 'Giá vàng quốc tế',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => NULL,
      ),
      'multigroup' => array(
        'multiple-columns' => 1,
        'required' => 0,
        'multiple' => '1',
        'labels' => array(
          '0' => '',
          '1' => '',
          '2' => '',
          '3' => '',
          '4' => '',
          '5' => '',
          '6' => '',
          '7' => '',
          '8' => '',
          '9' => '',
        ),
      ),
    ),
    'weight' => '34',
    'parent' => '',
    'fields' => array(
      '0' => 'field_api_goldprice_label_1',
      '1' => 'field_api_goldprice_key_1',
      '2' => 'field_api_goldprice_status_1',
      '3' => 'field_api_goldprice_field_1',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_api_giavang_trangsuc
  $groups['api-group_api_giavang_trangsuc'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'api',
    'group_name' => 'group_api_giavang_trangsuc',
    'label' => 'Giá vàng trang sức và các giá tham khảo',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => NULL,
      ),
      'multigroup' => array(
        'multiple-columns' => 1,
        'required' => 0,
        'multiple' => '1',
        'labels' => array(
          '0' => '',
          '1' => '',
          '2' => '',
          '3' => '',
          '4' => '',
          '5' => '',
          '6' => '',
          '7' => '',
          '8' => '',
          '9' => '',
        ),
      ),
    ),
    'weight' => '35',
    'parent' => '',
    'fields' => array(
      '0' => 'field_api_goldprice_label_2',
      '1' => 'field_api_goldprice_key_2',
      '2' => 'field_api_goldprice_status_2',
      '3' => 'field_api_goldprice_field_2',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_api_giavang_trongnuoc
  $groups['api-group_api_giavang_trongnuoc'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'api',
    'group_name' => 'group_api_giavang_trongnuoc',
    'label' => 'Giá vàng trong nước',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => NULL,
      ),
      'multigroup' => array(
        'multiple-columns' => 1,
        'required' => 0,
        'multiple' => '1',
        'labels' => array(
          '0' => '',
          '1' => '',
          '2' => '',
          '3' => '',
          '4' => '',
          '5' => '',
          '6' => '',
          '7' => '',
          '8' => '',
          '9' => '',
        ),
      ),
    ),
    'weight' => '33',
    'parent' => '',
    'fields' => array(
      '0' => 'field_api_goldprice_label',
      '1' => 'field_api_goldprice_key',
      '2' => 'field_api_goldprice_status',
      '3' => 'field_api_goldprice_field',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_api_led
  $groups['api-group_api_led'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'api',
    'group_name' => 'group_api_led',
    'label' => 'Giá hiển thị trên bảng LED',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => NULL,
      ),
      'multigroup' => array(
        'multiple-columns' => 1,
        'required' => 0,
        'multiple' => '1',
        'labels' => array(
          '0' => '',
          '1' => '',
          '2' => '',
          '3' => '',
          '4' => '',
          '5' => '',
          '6' => '',
          '7' => '',
          '8' => '',
          '9' => '',
        ),
      ),
    ),
    'weight' => '56',
    'parent' => '',
    'fields' => array(
      '0' => 'field_api_led_label',
      '1' => 'field_api_led_key',
      '2' => 'field_api_led_status',
      '3' => 'field_api_led_field',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Giá hiển thị trên bảng LED');
  t('Giá vàng quốc tế');
  t('Giá vàng trang sức và các giá tham khảo');
  t('Giá vàng trong nước');

  return $groups;
}
