<?php
// $Id$

/**
 * @file
 * Plugin to provide access control based upon language comparison.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Language: Compare"),
  'description' => t('Control access by language comparison.'),
  'callback' => 'ctools_language_compare_ctools_access_check',
  'default' => array('type' => array()),
  'settings form' => 'ctools_language_compare_ctools_access_settings',
  'settings form submit' => 'ctools_language_compare_ctools_access_settings_submit',
  'summary' => 'ctools_language_compare_ctools_access_summary',
  'required context' => array(
    new ctools_context_required(t('Language'), 'language'),
    new ctools_context_required(t('Language'), 'language')
  ),
);

/**
 * Settings form for the 'language compare' access plugin.
 */
function ctools_language_compare_ctools_access_settings($form, &$form_state, $conf) {
  return $form;
}

/**
 * Check for access.
 */
function ctools_language_compare_ctools_access_check($conf, $context, $plugin) {
  if (!isset($context[0]) || !isset($context[1])) {
    return FALSE;
  }
  $language = $context[0]->data;
  $language2 = $context[1]->data;
  if (!is_object($language) || !is_object($language2)) {
    return FALSE;
  }
  return $language->language == $language2->language;
}

/**
 * Provide a summary description based upon the language entities.
 */
function ctools_language_compare_ctools_access_summary($conf, $context, $plugin) {
  return t('@language equals @language2', array('@language' => $context[0]->identifier, '@language2' => $context[1]->identifier));
}

