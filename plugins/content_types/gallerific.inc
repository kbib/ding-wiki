<?php

$plugin = array(
  'title' => t('Wiki gallerific content'),
  'single' => TRUE,
  'title' => t('Wiki gallerific content'),
  'description' => t('Contains images and caption placeholders for wiki jQuery gallerific galleries.'),
  'category' => t('Miscellaneous'),
  'required context' => new ctools_context_required(t('node'), 'node'),
);

function ding_wiki_gallerific_content_type_render($subtype, $conf, $panel_args) {
  $block->title = '';
  $block->content = '<div class="ding-wiki-gallery-images"></div>
										<div class="ding-wiki-gallery-caption">
										</div>';
  return $block;
}

/**
 * Empty function required to support editing the content type.
 */
function ding_wiki_gallerific_content_type_edit_form(&$form, &$form_state) {
}

/**
 * Returns the administrative title for the content type.
 */
function ding_wiki_gallerific_content_type_admin_title($subtype, $conf) {
  return t('Wiki gallerific content');
}