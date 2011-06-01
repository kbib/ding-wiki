<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function ding_wiki_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function ding_wiki_node_info() {
  $items = array(
    'wiki_page' => array(
      'name' => t('Wiki page'),
      'module' => 'features',
      'description' => t('A page where content can be created and edited by all authenticated users wiki style.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
