<?php
/**
 * @file
 * feature_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_users_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}