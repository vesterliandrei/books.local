<?php
/**
 * @file
 * feature_panels.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function feature_panels_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'custom_layout';
  $layout->admin_title = 'Custom Layout';
  $layout->admin_description = 'Custom Layout';
  $layout->category = 'Custom';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '29.952850480959505',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'right',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'top_full',
        ),
        'parent' => 'main',
        'class' => 'Top Full',
      ),
      'top_full' => array(
        'type' => 'region',
        'title' => 'Top Full',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'top-full',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '70.04714951904049',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'left',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'bottom',
        ),
        'parent' => 'main',
        'class' => 'bottom',
      ),
      'bottom' => array(
        'type' => 'region',
        'title' => 'Bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'bottom',
      ),
    ),
  );
  $export['custom_layout'] = $layout;

  return $export;
}
