<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function ding_wiki_user_default_permissions() {
  $permissions = array();

  // Exported permission: access nodes
  $permissions['access nodes'] = array(
    'name' => 'access nodes',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: administer node access settings
  $permissions['administer node access settings'] = array(
    'name' => 'administer node access settings',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer node settings
  $permissions['administer node settings'] = array(
    'name' => 'administer node settings',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'author',
      '2' => 'editor',
    ),
  );

  // Exported permission: administer node type access settings
  $permissions['administer node type access settings'] = array(
    'name' => 'administer node type access settings',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: create node content
  $permissions['create node content'] = array(
    'name' => 'create node content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: create wiki_page content
  $permissions['create wiki_page content'] = array(
    'name' => 'create wiki_page content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: delete any wiki_page content
  $permissions['delete any wiki_page content'] = array(
    'name' => 'delete any wiki_page content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'editor',
    ),
  );

  // Exported permission: delete node content
  $permissions['delete node content'] = array(
    'name' => 'delete node content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own wiki_page content
  $permissions['delete own wiki_page content'] = array(
    'name' => 'delete own wiki_page content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'author',
      '2' => 'editor',
    ),
  );

  // Exported permission: edit any wiki_page content
  $permissions['edit any wiki_page content'] = array(
    'name' => 'edit any wiki_page content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'author',
      '4' => 'editor',
    ),
  );

  // Exported permission: edit node content
  $permissions['edit node content'] = array(
    'name' => 'edit node content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own wiki_page content
  $permissions['edit own wiki_page content'] = array(
    'name' => 'edit own wiki_page content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'author',
      '2' => 'editor',
    ),
  );

  return $permissions;
}
