<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function doji_update_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_display_1
  $groups['doji_goldprice_wget-group_display_1'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_1',
    'label' => 'Giá Vàng',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-4',
        'parent' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'settings' => array(),
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'description' => '',
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
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
        'subgroup' => array(
          'weight' => -20,
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
        ),
      ),
    ),
    'weight' => '-3',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_1',
      '1' => 'field_goldprice_field_1',
      '2' => 'field_goldprice_field_b_1',
      '3' => 'field_goldprice_field_s_1',
      '4' => 'field_goldprice_field_status_1',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_10
  $groups['doji_goldprice_wget-group_display_10'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_10',
    'label' => 'Giá vàng trang sức Tại Tp.HCM',
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
    'weight' => '8',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_10',
      '1' => 'field_goldprice_field_10',
      '2' => 'field_goldprice_field_b_10',
      '3' => 'field_goldprice_field_s_10',
      '4' => 'field_goldprice_field_status_10',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_2
  $groups['doji_goldprice_wget-group_display_2'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_2',
    'label' => 'Giá vàng Tập đoàn VBĐQ DOJI',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-2',
        'parent' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'settings' => array(),
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'description' => '',
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
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
        'subgroup' => array(
          'weight' => -20,
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
        ),
      ),
    ),
    'weight' => '-2',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_2',
      '1' => 'field_goldprice_field_2',
      '2' => 'field_goldprice_field_b_2',
      '3' => 'field_goldprice_field_s_2',
      '4' => 'field_goldprice_field_status_2',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_3
  $groups['doji_goldprice_wget-group_display_3'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_3',
    'label' => 'Vị Trí Trái',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '0',
        'parent' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'settings' => array(),
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'description' => '',
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
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
        'subgroup' => array(
          'weight' => -20,
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
        ),
      ),
    ),
    'weight' => '-1',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_3',
      '1' => 'field_goldprice_field_3',
      '2' => 'field_goldprice_field_b_3',
      '3' => 'field_goldprice_field_s_3',
      '4' => 'field_goldprice_field_status_3',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_4
  $groups['doji_goldprice_wget-group_display_4'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_4',
    'label' => 'Vị Trí Phải',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '1',
        'parent' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'settings' => array(),
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'description' => '',
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
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
        'subgroup' => array(
          'weight' => -20,
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
        ),
      ),
    ),
    'weight' => '0',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_4',
      '1' => 'field_goldprice_field_4',
      '2' => 'field_goldprice_field_b_4',
      '3' => 'field_goldprice_field_s_4',
      '4' => 'field_goldprice_field_status_4',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_5
  $groups['doji_goldprice_wget-group_display_5'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_5',
    'label' => 'Giá vàng quốc tế, USD/VND',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '2',
        'parent' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'settings' => array(),
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'description' => '',
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
      'multigroup' => array(
        'multiple-columns' => 1,
        'required' => 0,
        'multiple' => '4',
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
        'subgroup' => array(
          'weight' => -20,
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
        ),
      ),
    ),
    'weight' => '3',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_field_5',
      '1' => 'field_goldprice_field_b_5',
      '2' => 'field_goldprice_field_s_5',
      '3' => 'field_goldprice_field_status_5',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_6
  $groups['doji_goldprice_wget-group_display_6'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_6',
    'label' => 'Giá vàng trang sức',
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
    'weight' => '1',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_6',
      '1' => 'field_goldprice_field_6',
      '2' => 'field_goldprice_field_b_6',
      '3' => 'field_goldprice_field_s_6',
      '4' => 'field_goldprice_field_status_6',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_7
  $groups['doji_goldprice_wget-group_display_7'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_7',
    'label' => 'Giá vàng trang sức',
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
    'weight' => '2',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_7',
      '1' => 'field_goldprice_field_7',
      '2' => 'field_goldprice_field_b_7',
      '3' => 'field_goldprice_field_s_7',
      '4' => 'field_goldprice_field_status_7',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_8
  $groups['doji_goldprice_wget-group_display_8'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_8',
    'label' => 'Giá vàng nguyên liệu',
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
    'weight' => '4',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_8',
      '1' => 'field_goldprice_field_8',
      '2' => 'field_goldprice_field_b_8',
      '3' => 'field_goldprice_field_s_8',
      '4' => 'field_goldprice_field_status_8',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_9
  $groups['doji_goldprice_wget-group_display_9'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_9',
    'label' => 'Giá vàng trang sức Tại Hà Nội',
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
    'weight' => '7',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_9',
      '1' => 'field_goldprice_field_9',
      '2' => 'field_goldprice_field_b_9',
      '3' => 'field_goldprice_field_s_9',
      '4' => 'field_goldprice_field_status_9',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_hcm
  $groups['doji_goldprice_wget-group_display_hcm'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_hcm',
    'label' => 'Bảng Giá Tại Tp.HCM',
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
    'weight' => '6',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_hcm',
      '1' => 'field_goldprice_field_hcm',
      '2' => 'field_goldprice_field_b_hcm',
      '3' => 'field_goldprice_field_s_hcm',
      '4' => 'field_goldprice_field_status_hcm',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_hn
  $groups['doji_goldprice_wget-group_display_hn'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_hn',
    'label' => 'Bảng Giá Tại Hà Nội',
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
    'weight' => '5',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_hn',
      '1' => 'field_goldprice_field_hn',
      '2' => 'field_goldprice_field_b_hn',
      '3' => 'field_goldprice_field_s_hn',
      '4' => 'field_goldprice_field_status_hn',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_display_home
  $groups['doji_goldprice_wget-group_display_home'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_goldprice_wget',
    'group_name' => 'group_display_home',
    'label' => 'Giá hiển thị trên trang chủ',
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
    'weight' => '-4',
    'parent' => '',
    'fields' => array(
      '0' => 'field_goldprice_label_home',
      '1' => 'field_goldprice_field',
      '2' => 'field_goldprice_field_b',
      '3' => 'field_goldprice_field_s',
      '4' => 'field_goldprice_field_status',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bảng Giá Tại Hà Nội');
  t('Bảng Giá Tại Tp.HCM');
  t('Giá Vàng');
  t('Giá hiển thị trên trang chủ');
  t('Giá vàng Tập đoàn VBĐQ DOJI');
  t('Giá vàng nguyên liệu');
  t('Giá vàng quốc tế, USD/VND');
  t('Giá vàng trang sức');
  t('Giá vàng trang sức Tại Hà Nội');
  t('Giá vàng trang sức Tại Tp.HCM');
  t('Vị Trí Phải');
  t('Vị Trí Trái');

  return $groups;
}
