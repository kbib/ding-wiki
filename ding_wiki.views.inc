<?php

/**
 * Implementation of hook_views_pre_execute().
 */
function ding_wiki_views_pre_execute(&$view) {
  // Manually insert a GROUP BY element to ensure that each node is only shown once on the
  // users' wiki pages list. There does not seem to be a proper way to achieve this
  if ($view->name == 'wiki_revisions_list' && $view->current_display == 'panel_pane_1') {
    $view->build_info['query'] = str_replace('ORDER BY', 'GROUP BY node.nid ORDER BY', $view->build_info['query']);
  }
}
