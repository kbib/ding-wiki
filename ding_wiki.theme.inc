<?php

function template_preprocess_ding_wiki_formatter_text($vars) {
  $collection = _ting_reference_get_collection($vars['element']['#item']['ting_ref_type'], $vars['element']['#item']['ting_object_id'], $vars['element']['#item']['description']);
  if ($collection) {
    $object = array_shift($collection->objects);
    $vars['title'] = $vars['title_plain'] = check_plain($object->title);

    if ($object->url) {
      $vars['url'] = $object->url;
      $vars['title'] = l($object->title, $object->url);
    }
    $vars['authors'] = $object->creators_string ? check_plain($object->creators_string) : '';
    $image_url = ting_covers_object_url($object, '80_x');
    $vars['image'] = $image_url ? theme('image', $image_url, '', '', NULL, FALSE) : '';
    $vars['type'] = $object->type ? check_plain($object->type) : '';
  }
}

/**
 * Theme function for 'combined' Ting reference field formatter.
 */
function theme_ding_wiki_formatter_mixed($element) {
  // We use a static variable to keep track of how many times we have rendered a node field
  static $items;
  if (!$items) {
    $items = array();
  }

  // Generate a key for the variable based on node and field name.
  // NB: This will mess things up if the same node and the same field is rendered
  // multiple times on the same page
  $key = md5(serialize(array($element['#fieldname'], $element['#node'])));
  if (!isset($items[$key])) {
    $items[$key] = 1;
    return theme('ting_reference_formatter_default', $element);
  } else {
    $items[$key]++; //Increment the value to keep track of how many times it has been used for good measure
    $class = (($items[$key] % 2) == 1) ? '' : 'even';
    return '<li class="format-text '.$class.'">'.theme('ding_wiki_formatter_text', $element) .'</li>';
  }
}

function theme_ding_wiki_formatter_thumbnail_description($element) {
  // Inside a view $element may contain NULL data. In that case, just return.
  if (empty($element['#item']['fid'])) {
    return '';
  }

  $presetname = 'ding_wiki_thumbnail';

  $item = $element['#item'];
  $item['data']['alt'] = isset($item['data']['alt']) ? $item['data']['alt'] : '';
  $item['data']['title'] = isset($item['data']['title']) ? $item['data']['title'] : NULL;

  $class = "imagecache imagecache-$presetname imagecache-$style imagecache-{$element['#formatter']}";
  return '<div class="' . $class .'">' .
    theme('imagecache', $presetname, $item['filepath'], $item['data']['alt'], $item['data']['title'], array('class' => $class)) .
    (($item['data']['title']) ? '<div class="description">' . $item['data']['title'] . '</div>' : '') .
  '</div>';
}

function theme_ding_wiki_formatter_thumbnail_link_description($element) {
  // Inside a view $element may contain NULL data. In that case, just return.
  if (empty($element['#item']['fid'])) {
    return '';
  }

  $presetname = 'ding_wiki_thumbnail';

  $item = $element['#item'];
  $item['data']['alt'] = isset($item['data']['alt']) ? $item['data']['alt'] : '';
  $item['data']['title'] = isset($item['data']['title']) ? $item['data']['title'] : NULL;


  $imagetag = theme('imagecache', $presetname, $item['filepath'], $item['data']['alt'], $item['data']['title']);
  $path = file_create_url($item['filepath']);
  $class = "imagecache imagecache-$presetname imagecache-$style imagecache-{$element['#formatter']}";

  return '<div class="' . $class .'">' .
    l($imagetag, $path, array('attributes' => array('class' => $class), 'html' => TRUE)) .
    (($item['data']['description']) ? '<div class="description"><h2>' . $item['data']['title'] . '</h2><div>' . $item['data']['description'] . '</div></div>' : '') .
  '</div>';
}