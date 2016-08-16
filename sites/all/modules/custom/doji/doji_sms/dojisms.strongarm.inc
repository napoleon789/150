<?php

/**
 * Implementation of hook_strongarm().
 */
function doji_sms_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_doji_sms';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '0',
    'author' => '-1',
    'options' => '1',
    'menu' => '-2',
    'path' => '2',
  );
  $export['content_extra_weights_doji_sms'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_doji_sms';
  $strongarm->value = '0';
  $export['language_content_type_doji_sms'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_doji_sms';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_doji_sms'] = $strongarm;

  return $export;
}
