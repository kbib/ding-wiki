<?php

/**
 * Implementation of hook_page_manager_tasks().
 * 
 * This is used as using a $plugin variable doesn't seem to work.
 *
 * @TODO: Consider moving this to a more general location. If other modules want to build
 * on the revisions panel they shouldn't depend on ding_wiki.
 */
function ding_wiki_node_revisions_page_manager_tasks() {
	return array(
	  // This is a 'page' task and will fall under the page admin UI
	  'task type' => 'page',

	  'title' => t('Node revisions'),
	  'admin title' => t('Node revisions'),
	  'admin description' => t('When enabled, this overrides the default Drupal behavior for the revisions page at <em>/node/%node/revsions</em>.'),
	  'admin path' => 'node/%node/revisions',

	  // Menu hooks so that we can alter the default entry
	  // samvirke_quiz is the name of the module; take is the name of the task.
	  //   (this is arbitrary and the name-structure is a convention
	  //    to avoid function-name collisions with other modules.)
	  'hook menu alter' => 'ding_wiki_node_revisions_menu_alter',

	  // This task provides the 'node' context to content-types on the panel
	  'handler type' => 'context',
	  'get arguments' => 'ding_wiki_node_revisions_get_arguments',
	  'get context placeholders' => 'ding_wiki_node_revisions_get_contexts',

	  // Allow this panel-page to be enabled or disabled:
	  'disabled' => variable_get('ding_wiki_node_revisions_disabled', TRUE),
	  'enable callback' => 'ding_wiki_node_revisions_enable',
	);
}

function ding_wiki_node_revisions_menu_alter(&$items, $task) {
  // the enable/disable callback will set a variable to control whether the panel is enabled.
  if (variable_get('ding_wiki_node_revisions_disabled', TRUE)) {
    // the panel is disabled: don't run the menu-alter, leave the default menu entry.
    return;
  }

  // Check whether the callbacks at node/%node/take match those
  // provided by the take module.  If not, then the URL has been overridden already.
  $page_callback = $items['node/%node/revisions']['page callback'];
  $page_arguments = $items['node/%node/revisions']['page arguments'];

  //Diff module also overrides node/%node/revisions
  $known_callbacks = array('node_revision_overview', 'diff_diffs_overview');
  $is_using_default = (in_array($page_callback, $known_callbacks)  && $page_arguments == array(1));

  // check that it either matches the callback provided by take,
  // or if not, it's already been overridden by another module, so check
  // whether page-manager is configured to override already-overridden pages.
  if ($is_using_default || variable_get('page_manager_override_anyway', FALSE)) {
    $items['node/%node/revisions']['page callback'] = 'ding_wiki_node_revisions_page';
    $items['node/%node/revisions']['file path'] = $task['path'];
    $items['node/%node/revisions']['file'] = $task['file'];
  } else {
    // disable the panel page
    variable_set('ding_wiki_node_revisions_disabled', TRUE);
    // the enable-function sets a global, so the message is only displayed when trying to enable the panel, not on every cache-clear.
    if (!empty($GLOBALS['ding_wiki_node_enabling_revisions'])) {
      drupal_set_message(t('ding_wiki module is unable to enable the revisions panel page because some other module already has overridden with %callback.', array('%callback' => $page_callback)), 'warning');
    }
    return;
  }
}

function ding_wiki_node_revisions_enable($cache, $status) {
  variable_set('ding_wiki_node_revisions_disabled', $status);
  // Set a global flag so that the menu routine knows it needs
  // to set a message if enabling cannot be done.
  if (!$status) {
    $GLOBALS['ding_wiki_node_enabling_revisions'] = TRUE;
  }
}

function ding_wiki_node_revisions_get_arguments($task, $subtask_id) {
  return array(
    array(
      'keyword' => 'node',
      'identifier' => t('Node'),
      'id' => 1,
      'name' => 'nid',
      'settings' => array(),
    ),
  );
}

/**
 * Callback to get context placeholders provided by this handler.
 */
function ding_wiki_node_revisions_get_contexts($task, $subtask_id) {
  return ctools_context_get_placeholders_from_argument(ding_wiki_node_revisions_get_arguments($task, $subtask_id));
}

/**
 * Entry point for our overridden take URL.
 *
 * This function asks its assigned handlers who, if anyone, would like
 * to run with it. If no one does, it passes through to take's
 * handler.
 */
function ding_wiki_node_revisions_page($node) {
  // Load my task plugin
  $task = page_manager_get_task('node_revisions');
 
  // Load the node into a context.
  ctools_include('context');
  ctools_include('context-task-handler');
  $contexts = ctools_context_handler_get_task_contexts($task, '', array($node));
  $args = array($node->nid);

  $output = ctools_context_handler_render($task, '', $contexts, $args);
  if ($output !== FALSE) {
    return $output;
  }

  // fallback to the default take handler:
	$function = 'node_revision_overview';
	module_load_include('inc', 'node', 'node.pages');
	if (module_exists('diff')) {
	  $function = 'diff_diffs_overview';
	  module_load_include('inc', 'diff', 'diff.pages');
	} 
  $args = array($node);

  foreach (module_implements('page_manager_override') as $module) {
    $callback = $module . '_page_manager_override';
    if (($rc = $callback('node_revisions')) && function_exists($rc)) {
      $function = $rc;
      break;
    }
  }
  // Otherwise, fall back.
  return call_user_func_array($function, $args);
}