<?php


/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function doji_gold_price_fieldgroup_default_groups() {
  $groups = array();
  // Exported group: group_doji_3
  $groups['goldprice-group_doji_3'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_doji_3',
    'label' => 'DOJI HCM buôn (Nghìn/lượng)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '30',
    'parent' => '',
    'fields' => array(
      '0' => 'field_doji_3_muavao',
      '1' => 'field_doji_3_banra',
      '2' => 'field_doji_3_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_doji_9
  $groups['goldprice-group_doji_9'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_doji_9',
    'label' => 'DOJI HCM lẻ (Nghìn/lượng)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '29',
    'parent' => '',
    'fields' => array(
      '0' => 'field_doji_9_muavao',
      '1' => 'field_doji_9_banra',
      '2' => 'field_doji_9_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_gold
  $groups['goldprice-group_gold'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_gold',
    'label' => 'Gold (usd/oz)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '3',
    'parent' => '',
    'fields' => array(
      '0' => 'field_gold_muavao',
      '1' => 'field_gold_banra',
      '2' => 'field_gold_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_nguyen_lieu_99
  $groups['goldprice-group_nguyen_lieu_99'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_nguyen_lieu_99',
    'label' => 'Nguyên liệu (99)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '36',
    'parent' => '',
    'fields' => array(
      '0' => 'field_nguyen_lieu_99_muavao',
      '1' => 'field_nguyen_lieu_99_banra',
      '2' => 'field_nguyen_lieu_99_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_nguyen_lieu_999
  $groups['goldprice-group_nguyen_lieu_999'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_nguyen_lieu_999',
    'label' => 'Nguyên liệu (99.9)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '36',
    'parent' => '',
    'fields' => array(
      '0' => 'field_nguyen_lieu_999_muavao',
      '1' => 'field_nguyen_lieu_999_banra',
      '2' => 'field_nguyen_lieu_999_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_nhan_loc1
  $groups['goldprice-group_nhan_loc1'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_nhan_loc1',
    'label' => 'Nhẫn lộc (1 chỉ)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '7',
    'parent' => '',
    'fields' => array(
      '0' => 'field_nhan_loc1_muavao',
      '1' => 'field_nhan_loc1_banra',
      '2' => 'field_nhan_loc1_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_nhan_phat2
  $groups['goldprice-group_nhan_phat2'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_nhan_phat2',
    'label' => 'Nhẫn phát (2 chỉ)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '8',
    'parent' => '',
    'fields' => array(
      '0' => 'field_nhan_phat2_muavao',
      '1' => 'field_nhan_phat2_banra',
      '2' => 'field_nhan_phat2_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_nhan_tai5
  $groups['goldprice-group_nhan_tai5'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_nhan_tai5',
    'label' => 'Nhẫn tài (5 chỉ)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '9',
    'parent' => '',
    'fields' => array(
      '0' => 'field_nhan_tai5_muavao',
      '1' => 'field_nhan_tai5_banra',
      '2' => 'field_nhan_tai5_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_phi_sjc_9999
  $groups['goldprice-group_phi_sjc_9999'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_phi_sjc_9999',
    'label' => 'Phi SJC (99.99)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '36',
    'parent' => '',
    'fields' => array(
      '0' => 'field_phi_sjc_9999_muavao',
      '1' => 'field_phi_sjc_9999_banra',
      '2' => 'field_phi_sjc_9999_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_quidoi
  $groups['goldprice-group_quidoi'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_quidoi',
    'label' => 'Quy đổi (nghìn/lượng)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '4',
    'parent' => '',
    'fields' => array(
      '0' => 'field_quidoi_muavao',
      '1' => 'field_quidoi_banra',
      '2' => 'field_quidoi_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_sj0
  $groups['goldprice-group_sj0'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_sj0',
    'label' => 'SJC (nghìn/lượng)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '13',
    'parent' => '',
    'fields' => array(
      '0' => 'field_sj0_muavao',
      '1' => 'field_sj0_banra',
      '2' => 'field_sj0_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_sj3
  $groups['goldprice-group_sj3'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_sj3',
    'label' => 'SJC DOJI (nghìn/lượng)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '14',
    'parent' => '',
    'fields' => array(
      '0' => 'field_sj3_muavao',
      '1' => 'field_sj3_banra',
      '2' => 'field_sj3_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_sjc_buon
  $groups['goldprice-group_sjc_buon'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_sjc_buon',
    'label' => 'SJC buôn (nghìn/chỉ)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '2',
    'parent' => '',
    'fields' => array(
      '0' => 'field_sjc_buon_muavao',
      '1' => 'field_sjc_buon_banra',
      '2' => 'field_sjc_buon_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_sjc_le
  $groups['goldprice-group_sjc_le'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_sjc_le',
    'label' => 'SJC lẻ (nghìn/chỉ)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '1',
    'parent' => '',
    'fields' => array(
      '0' => 'field_sjc_le_muavao',
      '1' => 'field_sjc_le_banra',
      '2' => 'field_sjc_le_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_sjc_sg_buon
  $groups['goldprice-group_sjc_sg_buon'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_sjc_sg_buon',
    'label' => 'SJC SG buôn (nghìn/chỉ)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
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
    'weight' => '28',
    'parent' => '',
    'fields' => array(
      '0' => 'field_sjc_sg_buon_muavao',
      '1' => 'field_sjc_sg_buon_banra',
      '2' => 'field_sjc_sg_buon_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_sjc_sg_le
  $groups['goldprice-group_sjc_sg_le'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_sjc_sg_le',
    'label' => 'SJC SG lẻ (nghìn/chỉ)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
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
    'weight' => '25',
    'parent' => '',
    'fields' => array(
      '0' => 'field_sjc_sg_le_muavao',
      '1' => 'field_sjc_sg_le_banra',
      '2' => 'field_sjc_sg_le_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_usdvnd
  $groups['goldprice-group_usdvnd'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_usdvnd',
    'label' => 'USD/VND (Liên NH)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '6',
    'parent' => '',
    'fields' => array(
      '0' => 'field_usdvnd_muavao',
      '1' => 'field_usdvnd_banra',
      '2' => 'field_usdvnd_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_usdvnd_tudo
  $groups['goldprice-group_usdvnd_tudo'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_usdvnd_tudo',
    'label' => 'USD/VND (Tự do)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
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
    'weight' => '5',
    'parent' => '',
    'fields' => array(
      '0' => 'field_usdvnd_tudo_muavao',
      '1' => 'field_usdvnd_tudo_banra',
      '2' => 'field_usdvnd_tudo_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_va4
  $groups['goldprice-group_va4'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_va4',
    'label' => 'Vàng 68',
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
        'label' => 'above',
      ),
    ),
    'weight' => '31',
    'parent' => '',
    'fields' => array(
      '0' => 'field_va4_muavao',
      '1' => 'field_va4_banra',
      '2' => 'field_va4_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_van5
  $groups['goldprice-group_van5'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_van5',
    'label' => 'Vàng 99.9',
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
        'label' => 'above',
      ),
    ),
    'weight' => '15',
    'parent' => '',
    'fields' => array(
      '0' => 'field_van5_muavao',
      '1' => 'field_van5_banra',
      '2' => 'field_van5_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_vang_14k
  $groups['goldprice-group_vang_14k'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_vang_14k',
    'label' => 'Vàng 14k (nghìn/chỉ)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '12',
    'parent' => '',
    'fields' => array(
      '0' => 'field_vang_14k_muavao',
      '1' => 'field_vang_14k_banra',
      '2' => 'field_vang_14k_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_vang_18k
  $groups['goldprice-group_vang_18k'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_vang_18k',
    'label' => 'Vàng 18k (nghìn/chỉ)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '11',
    'parent' => '',
    'fields' => array(
      '0' => 'field_vang_18k_muavao',
      '1' => 'field_vang_18k_chenhlech',
      '2' => 'field_vang_18k_banra',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_vang_24k
  $groups['goldprice-group_vang_24k'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_vang_24k',
    'label' => 'Vàng 24k (nghìn/chỉ)',
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
        'label' => 'above',
      ),
    ),
    'weight' => '10',
    'parent' => '',
    'fields' => array(
      '0' => 'field_vang_24k_muavao',
      '1' => 'field_vang_24k_banra',
      '2' => 'field_vang_24k_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_vang_7
  $groups['goldprice-group_vang_7'] = array(
    'group_type' => 'standard',
    'type_name' => 'goldprice',
    'group_name' => 'group_vang_7',
    'label' => 'Vàng 99.99',
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
        'label' => 'above',
      ),
    ),
    'weight' => '36',
    'parent' => '',
    'fields' => array(
      '0' => 'field_vang_7_muavao',
      '1' => 'field_vang_7_banra',
      '2' => 'field_vang_7_chenhlech',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('DOJI HCM buôn (Nghìn/lượng)');
  t('DOJI HCM lẻ (Nghìn/lượng)');
  t('Gold (usd/oz)');
  t('Nguyên liệu (99)');
  t('Nguyên liệu (99.9)');
  t('Nhẫn lộc (1 chỉ)');
  t('Nhẫn phát (2 chỉ)');
  t('Nhẫn tài (5 chỉ)');
  t('Phi SJC (99.99)');
  t('Quy đổi (nghìn/lượng)');
  t('SJC (nghìn/lượng)');
  t('SJC DOJI (nghìn/lượng)');
  t('SJC SG buôn (nghìn/chỉ)');
  t('SJC SG lẻ (nghìn/chỉ)');
  t('SJC buôn (nghìn/chỉ)');
  t('SJC lẻ (nghìn/chỉ)');
  t('USD/VND (Liên NH)');
  t('USD/VND (Tự do)');
  t('Vàng 14k (nghìn/chỉ)');
  t('Vàng 18k (nghìn/chỉ)');
  t('Vàng 24k (nghìn/chỉ)');
  t('Vàng 68');
  t('Vàng 99.9');
  t('Vàng 99.99');

  return $groups;
}
