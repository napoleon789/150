<?php

/**
 * Implementation of hook_strongarm().
 */
function doji_gold_price_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_goldprice';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '-2',
    'author' => '-3',
    'options' => '-1',
    'menu' => '-4',
    'path' => '0',
  );
  $export['content_extra_weights_goldprice'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'doji_global_settings';
  $strongarm->value = array(
    'url_currencyrate' => 'http://vn.easy-forex.com/int/currencyratespage.aspx',
    'url_exchangerate' => 'http://www.vietcombank.com.vn/exchangerates/ExrateXML.aspx',
    'url_bieudo_giavang_quocte' => 'http://www.kitco.com/images/live/gold.gif',
    'spread' => '30',
    'banle_spread' => '0',
    'banbuon_spread' => '0',
    'click_spread' => '1',
  );
  $export['doji_global_settings'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'formula_groups';
  $strongarm->value = array(
    'formula_group_sjc_le' => array(
      'field_sjc_le_muavao' => array(
        'id' => '1',
        'operator' => 'B1',
        'variable' => 'B1',
        'active' => '1',
      ),
      'field_sjc_le_banra' => array(
        'id' => '1',
        'operator' => 'C1',
        'variable' => 'C1',
        'active' => '1',
      ),
      'field_sjc_le_chenhlech' => array(
        'id' => '1',
        'operator' => 'C1-B1',
        'variable' => 'D1',
        'active' => '1',
      ),
    ),
    'formula_group_sjc_buon' => array(
      'field_sjc_buon_muavao' => array(
        'id' => '2',
        'operator' => 'B2',
        'variable' => 'B2',
        'active' => '1',
      ),
      'field_sjc_buon_banra' => array(
        'id' => '2',
        'operator' => 'C2',
        'variable' => 'C2',
        'active' => '1',
      ),
      'field_sjc_buon_chenhlech' => array(
        'id' => '2',
        'operator' => 'C2-B2',
        'variable' => 'D2',
        'active' => '1',
      ),
    ),
    'formula_group_gold' => array(
      'field_gold_muavao' => array(
        'id' => '3',
        'variable' => 'B3',
        'operator' => '-',
        'active' => '1',
      ),
      'field_gold_banra' => array(
        'id' => '3',
        'variable' => 'C3',
        'active' => '1',
        'operator' => '-',
      ),
      'field_gold_chenhlech' => array(
        'id' => '3',
        'variable' => 'D3',
        'active' => '1',
        'operator' => '-',
      ),
    ),
    'formula_group_quidoi' => array(
      'field_quidoi_muavao' => array(
        'id' => '4',
        'variable' => 'B4',
        'active' => '1',
        'operator' => '-',
      ),
      'field_quidoi_banra' => array(
        'id' => '4',
        'variable' => 'C4',
        'active' => '1',
        'operator' => '-',
      ),
      'field_quidoi_chenhlech' => array(
        'id' => '4',
        'variable' => 'D4',
        'active' => '1',
        'operator' => '-',
      ),
    ),
    'formula_group_usdvnd_tudo' => array(
      'field_usdvnd_tudo_muavao' => array(
        'id' => '5',
        'operator' => 'B5',
        'variable' => 'B5',
        'active' => '1',
      ),
      'field_usdvnd_tudo_banra' => array(
        'id' => '5',
        'operator' => 'C5',
        'variable' => 'C5',
        'active' => '1',
      ),
      'field_usdvnd_tudo_chenhlech' => array(
        'id' => '5',
        'operator' => 'C5-B5',
        'variable' => 'D5',
        'active' => '1',
      ),
    ),
    'formula_group_usdvnd' => array(
      'field_usdvnd_muavao' => array(
        'id' => '6',
        'variable' => 'B6',
        'active' => '1',
        'operator' => 'B6',
      ),
      'field_usdvnd_banra' => array(
        'id' => '6',
        'variable' => 'C6',
        'active' => '1',
        'operator' => 'C6',
      ),
      'field_usdvnd_chenhlech' => array(
        'id' => '6',
        'variable' => 'D6',
        'active' => '1',
        'operator' => 'C6-B6',
      ),
    ),
    'formula_group_nhan_loc1' => array(
      'field_nhan_loc1_muavao' => array(
        'id' => '7',
        'variable' => 'B7',
        'active' => '1',
        'operator' => 'B1',
      ),
      'field_nhan_loc1_banra' => array(
        'id' => '7',
        'variable' => 'C7',
        'active' => '1',
        'operator' => 'C1',
      ),
      'field_nhan_loc1_chenhlech' => array(
        'id' => '7',
        'variable' => 'D7',
        'active' => '1',
        'operator' => 'C7-B7',
      ),
    ),
    'formula_group_nhan_phat2' => array(
      'field_nhan_phat2_muavao' => array(
        'id' => '8',
        'variable' => 'B8',
        'active' => '1',
        'operator' => 'B1*2',
      ),
      'field_nhan_phat2_banra' => array(
        'id' => '8',
        'variable' => 'C8',
        'active' => '1',
        'operator' => 'C1*2',
      ),
      'field_nhan_phat2_chenhlech' => array(
        'id' => '8',
        'variable' => 'D8',
        'active' => '1',
        'operator' => 'C8-B8',
      ),
    ),
    'formula_group_nhan_tai5' => array(
      'field_nhan_tai5_muavao' => array(
        'id' => '9',
        'variable' => 'B9',
        'active' => '1',
        'operator' => 'B1*5',
      ),
      'field_nhan_tai5_banra' => array(
        'id' => '9',
        'variable' => 'C9',
        'active' => '1',
        'operator' => 'C1*5',
      ),
      'field_nhan_tai5_chenhlech' => array(
        'id' => '9',
        'variable' => 'D9',
        'active' => '1',
        'operator' => 'C9-B9',
      ),
    ),
    'formula_group_vang_24k' => array(
      'field_vang_24k_muavao' => array(
        'id' => '10',
        'variable' => 'B10',
        'active' => '1',
        'operator' => 'C10-D10',
      ),
      'field_vang_24k_banra' => array(
        'id' => '10',
        'variable' => 'C10',
        'active' => '1',
        'operator' => 'C1-50',
      ),
      'field_vang_24k_chenhlech' => array(
        'id' => '10',
        'variable' => 'D10',
        'active' => '1',
        'operator' => '300',
      ),
    ),
    'formula_group_vang_18k' => array(
      'field_vang_18k_muavao' => array(
        'id' => '11',
        'variable' => 'B11',
        'active' => '1',
        'operator' => 'C11-D11',
      ),
      'field_vang_18k_banra' => array(
        'id' => '11',
        'variable' => 'C11',
        'active' => '1',
        'operator' => 'ROUND(C10*18/24)+15',
      ),
      'field_vang_18k_chenhlech' => array(
        'id' => '11',
        'variable' => 'D11',
        'active' => '1',
        'operator' => '320',
      ),
    ),
    'formula_group_vang_14k' => array(
      'field_vang_14k_muavao' => array(
        'id' => '12',
        'variable' => 'B12',
        'active' => '1',
        'operator' => 'C12-D12',
      ),
      'field_vang_14k_banra' => array(
        'id' => '12',
        'variable' => 'C12',
        'active' => '1',
        'operator' => 'ROUND(C10*14/24)+15',
      ),
      'field_vang_14k_chenhlech' => array(
        'id' => '12',
        'variable' => 'D12',
        'active' => '1',
        'operator' => '320',
      ),
    ),
    'formula_group_sj0' => array(
      'field_sj0_muavao' => array(
        'id' => '13',
        'variable' => 'B13',
        'active' => '1',
        'operator' => 'b1*10',
      ),
      'field_sj0_banra' => array(
        'id' => '13',
        'variable' => 'C13',
        'active' => '1',
        'operator' => 'c1*10',
      ),
      'field_sj0_chenhlech' => array(
        'id' => '13',
        'variable' => 'D13',
        'active' => '1',
        'operator' => 'c13-b13',
      ),
    ),
    'formula_group_sj3' => array(
      'field_sj3_muavao' => array(
        'id' => '14',
        'variable' => 'B14',
        'active' => '1',
        'operator' => 'B2*10',
      ),
      'field_sj3_banra' => array(
        'id' => '14',
        'variable' => 'C14',
        'active' => '1',
        'operator' => 'c2*10',
      ),
      'field_sj3_chenhlech' => array(
        'id' => '14',
        'variable' => 'D14',
        'active' => '1',
        'operator' => 'd2*10',
      ),
    ),
    'formula_group_van5' => array(
      'field_van5_muavao' => array(
        'id' => '15',
        'variable' => 'B15',
        'active' => '1',
        'operator' => 'B15',
      ),
      'field_van5_banra' => array(
        'id' => '15',
        'variable' => 'C15',
        'active' => '1',
        'operator' => 'C15',
      ),
      'field_van5_chenhlech' => array(
        'id' => '15',
        'variable' => 'D15',
        'active' => '1',
        'operator' => 'C15-B15',
      ),
    ),
    'formula_group_sjc_sg_le' => array(
      'field_sjc_sg_le_muavao' => array(
        'id' => '16',
        'variable' => 'B16',
        'active' => '1',
        'operator' => 'B16',
      ),
      'field_sjc_sg_le_banra' => array(
        'id' => '16',
        'variable' => 'C16',
        'active' => '1',
        'operator' => 'C16',
      ),
      'field_sjc_sg_le_chenhlech' => array(
        'id' => '16',
        'variable' => 'D16',
        'active' => '1',
        'operator' => 'C16-B16',
      ),
    ),
    'formula_group_sjc_sg_buon' => array(
      'field_sjc_sg_buon_muavao' => array(
        'id' => '17',
        'variable' => 'B17',
        'active' => '1',
        'operator' => 'B17',
      ),
      'field_sjc_sg_buon_banra' => array(
        'id' => '17',
        'variable' => 'C17',
        'active' => '1',
        'operator' => 'C17',
      ),
      'field_sjc_sg_buon_chenhlech' => array(
        'id' => '17',
        'variable' => 'D17',
        'active' => '1',
        'operator' => 'C17-B17',
      ),
    ),
    'formula_group_doji_9' => array(
      'field_doji_9_muavao' => array(
        'id' => '18',
        'variable' => 'B18',
        'active' => '1',
        'operator' => 'B16*10',
      ),
      'field_doji_9_banra' => array(
        'id' => '18',
        'variable' => 'C18',
        'active' => '1',
        'operator' => 'C16*10',
      ),
      'field_doji_9_chenhlech' => array(
        'id' => '18',
        'variable' => 'D18',
        'active' => '1',
        'operator' => 'c18-b18',
      ),
    ),
    'formula_group_doji_3' => array(
      'field_doji_3_muavao' => array(
        'id' => '19',
        'variable' => 'B19',
        'active' => '1',
        'operator' => 'B17*10',
      ),
      'field_doji_3_banra' => array(
        'id' => '19',
        'variable' => 'C19',
        'active' => '1',
        'operator' => 'C17*10',
      ),
      'field_doji_3_chenhlech' => array(
        'id' => '19',
        'variable' => 'D19',
        'active' => '1',
        'operator' => 'C19-b19',
      ),
    ),
    'formula_group_va4' => array(
      'field_va4_muavao' => array(
        'id' => '20',
        'variable' => 'B20',
        'active' => '1',
        'operator' => 'B20-D20',
      ),
      'field_va4_banra' => array(
        'id' => '20',
        'variable' => 'C20',
        'active' => '1',
        'operator' => 'ROUND(C10*16/24)',
      ),
      'field_va4_chenhlech' => array(
        'id' => '20',
        'variable' => 'D20',
        'active' => '1',
        'operator' => '320',
      ),
    ),
    'formula_group_vang_7' => array(
      'field_vang_7_muavao' => array(
        'id' => '21',
        'variable' => 'B21',
        'active' => '1',
        'operator' => 'B21',
      ),
      'field_vang_7_banra' => array(
        'id' => '21',
        'variable' => 'C21',
        'active' => '1',
        'operator' => 'C21',
      ),
      'field_vang_7_chenhlech' => array(
        'id' => '21',
        'variable' => 'D21',
        'active' => '1',
        'operator' => 'D21',
      ),
    ),
    'formula_group_nguyen_lieu_99' => array(
      'field_nguyen_lieu_99_muavao' => array(
        'id' => '22',
        'variable' => 'B22',
        'active' => '1',
        'operator' => 'B22',
      ),
      'field_nguyen_lieu_99_banra' => array(
        'id' => '22',
        'variable' => 'C22',
        'active' => '1',
        'operator' => 'C22',
      ),
      'field_nguyen_lieu_99_chenhlech' => array(
        'id' => '22',
        'variable' => 'D22',
        'active' => '1',
        'operator' => 'C22-B22',
      ),
    ),
    'formula_group_nguyen_lieu_999' => array(
      'field_nguyen_lieu_999_muavao' => array(
        'id' => '23',
        'variable' => 'B23',
        'active' => '1',
        'operator' => 'B23',
      ),
      'field_nguyen_lieu_999_banra' => array(
        'id' => '23',
        'variable' => 'C23',
        'active' => '1',
        'operator' => 'C23',
      ),
      'field_nguyen_lieu_999_chenhlech' => array(
        'id' => '23',
        'variable' => 'D23',
        'active' => '1',
        'operator' => 'C23-B23',
      ),
    ),
    'formula_group_phi_sjc_9999' => array(
      'field_phi_sjc_9999_muavao' => array(
        'id' => '24',
        'variable' => 'B24',
        'active' => '1',
        'operator' => 'B24',
      ),
      'field_phi_sjc_9999_banra' => array(
        'id' => '24',
        'variable' => 'C24',
        'active' => '1',
        'operator' => 'C24',
      ),
      'field_phi_sjc_9999_chenhlech' => array(
        'id' => '24',
        'variable' => 'D24',
        'active' => '1',
        'operator' => 'C24-B24',
      ),
    ),
  );
  $export['formula_groups'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_goldprice';
  $strongarm->value = '0';
  $export['language_content_type_goldprice'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_goldprice';
  $strongarm->value = array();
  $export['node_options_goldprice'] = $strongarm;

  return $export;
}
