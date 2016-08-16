<?php

/**
 * Implementation of hook_strongarm().
 */
function doji_update_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_doji_goldprice_wget';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '11',
    'author' => '10',
    'options' => '12',
    'menu' => '9',
    'path' => '13',
  );
  $export['content_extra_weights_doji_goldprice_wget'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'doji_chart_block_views';
  $strongarm->value = array(
    'block_1' => array(
      'title' => 'DOJI HN',
      'time' => '1d',
      'width' => '335',
      'height' => '220',
      'group_name' => 'sjc',
    ),
    'block_2' => array(
      'title' => 'Biểu đồ 3 ngày',
      'time' => '3d',
      'width' => '335',
      'height' => '220',
      'group_name' => 'sjc',
    ),
    'block_5' => array(
      'title' => 'Biểu đồ 1 tuần',
      'time' => '7d',
      'width' => '335',
      'height' => '220',
      'group_name' => 'sjc',
    ),
    'block_3' => array(
      'title' => 'none',
      'time' => '1d',
      'width' => '335',
      'height' => '220',
      'group_name' => 'sjc',
    ),
    'block_4' => array(
      'title' => 'none',
      'time' => '1d',
      'width' => '335',
      'height' => '220',
      'group_name' => 'sjc',
    ),
  );
  $export['doji_chart_block_views'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'doji_chart_price_setting';
  $strongarm->value = array(
    'active' => 1,
    '1d' => array(
      'min' => '44000',
      'max' => '44400',
      'step' => '80',
    ),
    '3d' => array(
      'min' => '43920',
      'max' => '44520',
      'step' => '120',
    ),
  );
  $export['doji_chart_price_setting'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_doji_goldprice_wget';
  $strongarm->value = '0';
  $export['language_content_type_doji_goldprice_wget'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_doji_goldprice_wget';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_doji_goldprice_wget'] = $strongarm;

  return $export;
}
