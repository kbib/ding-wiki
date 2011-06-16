<?php

/**
 * Implementation of hook_strongarm().
 */
function ding_wiki_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_wiki_page';
  $strongarm->value = '';

  $export['ant_pattern_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_wiki_page';
  $strongarm->value = 0;

  $export['ant_php_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_wiki_page';
  $strongarm->value = '0';

  $export['ant_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_formats_allowed_wiki_page';
  $strongarm->value = array(
    0 => 3,
  );

  $export['better_formats_allowed_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_wiki_page';
  $strongarm->value = 0;

  $export['comment_anonymous_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_wiki_page';
  $strongarm->value = '3';

  $export['comment_controls_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_wiki_page';
  $strongarm->value = '4';

  $export['comment_default_mode_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_wiki_page';
  $strongarm->value = '1';

  $export['comment_default_order_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_wiki_page';
  $strongarm->value = '50';

  $export['comment_default_per_page_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_wiki_page';
  $strongarm->value = '0';

  $export['comment_form_location_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_wiki_page';
  $strongarm->value = '1';

  $export['comment_preview_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_wiki_page';
  $strongarm->value = '1';

  $export['comment_subject_field_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_wiki_page';
  $strongarm->value = '2';

  $export['comment_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_wiki_page';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-1',
    'revision_information' => '5',
    'author' => '4',
    'options' => '6',
    'comment_settings' => '8',
    'menu' => '-4',
    'taxonomy' => '0',
    'path' => '9',
    'path_redirect' => '7',
  );

  $export['content_extra_weights_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_wiki_page';
  $strongarm->value = 0;

  $export['content_profile_use_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_wiki_page';
  $strongarm->value = '0';

  $export['language_content_type_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_defaultnum_wiki_page';
  $strongarm->value = '0';

  $export['location_defaultnum_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_maxnum_wiki_page';
  $strongarm->value = '0';

  $export['location_maxnum_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_settings_node_wiki_page';
  $strongarm->value = array(
    'multiple' => array(
      'min' => '0',
      'max' => '0',
      'add' => '0',
    ),
    'form' => array(
      'weight' => 0,
      'collapsible' => 1,
      'collapsed' => 1,
      'fields' => array(
        'name' => array(
          'collect' => '1',
          'default' => '',
          'weight' => '2',
        ),
        'street' => array(
          'collect' => '1',
          'default' => '',
          'weight' => '4',
        ),
        'additional' => array(
          'collect' => '1',
          'default' => '',
          'weight' => '6',
        ),
        'city' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '8',
        ),
        'province' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '10',
        ),
        'postal_code' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '12',
        ),
        'country' => array(
          'collect' => '1',
          'default' => 'us',
          'weight' => '14',
        ),
        'locpick' => array(
          'collect' => '1',
          'weight' => '20',
        ),
        'phone' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '25',
        ),
        'fax' => array(
          'collect' => '0',
          'default' => '',
          'weight' => '30',
        ),
      ),
    ),
    'display' => array(
      'weight' => 0,
      'hide' => array(
        'name' => 0,
        'street' => 0,
        'additional' => 0,
        'city' => 0,
        'province' => 0,
        'postal_code' => 0,
        'country' => 0,
        'locpick' => 0,
        'fax' => 0,
        'phone' => 0,
        'province_name' => 0,
        'country_name' => 0,
        'map_link' => 0,
        'coords' => 0,
      ),
      'teaser' => 1,
      'full' => 1,
    ),
    'rss' => array(
      'mode' => 'simple',
    ),
  );

  $export['location_settings_node_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_wiki_page';
  $strongarm->value = array();

  $export['menu_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_access_settings';
  $strongarm->value = array(
    'per_node' => 1,
    'priority' => '10',
    'view' => array(
      1 => 1,
      2 => 2,
    ),
    'update' => array(
      1 => 1,
      2 => 2,
    ),
    'delete' => array(),
  );

  $export['node_access_settings'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_wiki_page';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );

  $export['node_options_wiki_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_type_wiki-page_access_settings';
  $strongarm->value = array(
    'per_node' => 1,
    'priority' => '10',
    'view' => array(
      1 => 1,
      2 => 2,
      3 => 3,
      4 => 4,
      5 => 5,
    ),
    'update' => array(
      1 => 1,
      2 => 2,
      3 => 3,
      4 => 4,
      5 => 5,
    ),
    'delete' => array(
      3 => 3,
      5 => 5,
    ),
  );

  $export['node_type_wiki-page_access_settings'] = $strongarm;
  return $export;
}
