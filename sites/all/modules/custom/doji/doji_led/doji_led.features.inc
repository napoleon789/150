<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function doji_led_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function doji_led_node_info() {
  $items = array(
    'doji_led' => array(
      'name' => t('LED'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Tiêu đề'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
