<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function doji_gold_price_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function doji_gold_price_node_info() {
  $items = array(
    'goldprice' => array(
      'name' => t('Nhập Giá Vàng'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Tiêu đề'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => t('Đơn vị tính = 1000'),
    ),
  );
  return $items;
}
