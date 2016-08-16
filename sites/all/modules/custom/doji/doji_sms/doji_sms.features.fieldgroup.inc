<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function doji_sms_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_sms_sort
  $groups['doji_sms-group_sms_sort'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'doji_sms',
    'group_name' => 'group_sms_sort',
    'label' => 'Sắp xếp thứ tự giá vàng',
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
    'weight' => '-4',
    'parent' => '',
    'fields' => array(
      '0' => 'field_sms_label',
      '1' => 'field_sms_field',
      '2' => 'field_sms_status',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Sắp xếp thứ tự giá vàng');

  return $groups;
}
