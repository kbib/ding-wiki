<?php

/**
 * @file
 * Plugin to handle the 'node' content type which allows node revion overviews
 * to be embedded into a panel.
 */

$plugin = array(
  'title' => t('Node revisions'),
  'single' => TRUE,
  'title' => t('Node revision overview'),
  'description' => t('The node revision overview.'),
  'category' => t('Node'),
  'required context' => new ctools_context_required(t('node'), 'node'),
);

/**
 * Output function for the 'node' content type.
 *
 * Outputs a node based on the module and delta supplied in the configuration.
 */
function ding_wiki_node_revisions_content_type_render($subtype, $conf, $panel_args) {
  // Load the node
	$node = node_load($panel_args[0]);

	// If the Diff module is enabled then we show the diff overview. Otherwise we
	// fall back to basic node revisions
	$content_function = 'node_revision_overview';
	module_load_include('inc', 'node', 'node.pages');
	if (module_exists('diff')) {
	  $content_function = 'diff_diffs_overview';
	  module_load_include('inc', 'diff', 'diff.pages');
	} 
	
  $block->title = t('Revisions');
  $block->content = call_user_func_array($content_function, array($node));
  
  return $block;
}

/**
 * Empty function required to support editing the content type.
 */
function ding_wiki_node_revisions_content_type_edit_form(&$form, &$form_state) {
}

/**
 * Returns the administrative title for the content type. 
 */
function ding_wiki_node_revisions_content_type_admin_title($subtype, $conf) {
  return t('Node revisions overview');
}