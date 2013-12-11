<?php
/**
 * @file
 * feature_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu_about:node/17
  $menu_links['menu-footer-menu_about:node/17'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/17',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'identifier' => 'menu-footer-menu_about:node/17',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-footer-menu_contact:node/18
  $menu_links['menu-footer-menu_contact:node/18'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/18',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'identifier' => 'menu-footer-menu_contact:node/18',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Contact');


  return $menu_links;
}
