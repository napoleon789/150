<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function doji_led_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_led_sort
  $groups['doji_led-group_led_sort'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_led',
    'group_name' => 'group_led_sort',
    'label' => 'Sắp xếp thứ tự hiển thị',
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
      '0' => 'field_led_field',
      '1' => 'field_led_label',
      '2' => 'field_led_status',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Sắp xếp thứ tự hiển thị');

  return $groups;
}
