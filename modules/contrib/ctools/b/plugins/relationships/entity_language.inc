<?php

/**
 * @file
 * Plugin to provide an relationship handler for a language from an entity.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Language from Entity'),
  'get child' => 'ctools_entity_language_get_child',
  'get children' => 'ctools_entity_language_get_children',
);

function ctools_entity_language_get_child($plugin, $parent, $child) {
  $plugins = ctools_entity_language_get_children($plugin, $parent);
  return $plugins[$parent . ':' . $child];
}

function ctools_entity_language_get_children($parent_plugin, $parent) {
  $entities = entity_get_info();
  $plugins = array();

  foreach (module_implements('entity_info') as $module) {
    module_load_install($module);
    $schemas = drupal_get_schema();

    foreach ($entities as $entity_type => $entity_info) {
      if (empty($entity_info['base table'])) {
        continue;
      }

      $table = $entity_info['base table'];
      if (isset($schemas[$table]['fields']['language'])) {
        $plugin_id = $parent . ':' . $entity_type;
        $plugin['title'] = t('Language from @entity', array('@entity' => $entity_info['label']));
        $plugin['description'] = t('Creates a language context from the @entity schema.', array('@entity' => $entity_info['label']));
        $plugin['keyword'] = 'language';
        $plugin['context name'] = 'language';
        $plugin['name'] = $plugin_id;
        $plugin['context'] = 'ctools_entity_language_context';
        $plugin['required context'] = new ctools_context_required($entity_info['label'], $entity_type);
        $plugins[$plugin_id] = $plugin;
      }
    }
  }
  drupal_alter('ctools_entity_language_relationships', $plugins);
  return $plugins;
}

/**
 * Return a new context based on an existing context.
 */
function ctools_entity_language_context($context, $conf) {
  $plugin = $conf['name'];
  list($plugin, $entity_type) = explode(':', $plugin);
  // If unset it wants a generic, unfilled context, which is just NULL.
  $entity_info = entity_get_info($entity_type);
  if (empty($context->data) || !isset($context->data->{$entity_info['entity keys']['id']})) {
    $language = language_default();
    return ctools_context_create_empty('language', $language);
  }

  if (isset($context->data->{$entity_info['entity keys']['id']})) {
    return ctools_context_create('language', $context->data->language);
  }
}
