<?php

/**
 * @file
 * Plugin to provide access control based upon language.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
if (module_exists('locale')) {
  $plugin = array(
    'title' => t('Language'),
    'description' => t('Control access by the language the user or site currently uses, or an existing language context.'),
    'callback' => 'ctools_site_language_ctools_access_check',
    'default' => array('language' => array()),
    'settings form' => 'ctools_site_language_ctools_access_settings',
    'settings form submit' => 'ctools_site_language_ctools_access_settings_submit',
    'summary' => 'ctools_site_language_ctools_access_summary',
    'required context' => new ctools_context_optional(t('Language Source'), 'language'),
  );
}

/**
 * Settings form for the 'by site_language' access plugin
 */
function ctools_site_language_ctools_access_settings($form, &$form_state, $conf) {
  $options = array(
    'default' => t('Default site language'),
  );
  $options = array_merge($options, locale_language_list());
  $form['settings']['language'] = array(
    '#title' => t('Language to compare with'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#description' => t('Pass only if the current site language (or chosen language source) is one of the selected languages.'),
    '#default_value' => $conf['language'],
  );
  return $form;
}

/**
 * Check for access.
 */
function ctools_site_language_ctools_access_check($conf, $context) {
  // We use the site's current language if there is no specified languaged context.
  if (!$context->is_type('language')) {
    global $language;
  }

  elseif (isset($context) && !empty($context->data)) {
    $language = $context->data;
  }

  else {
    return FALSE;
  }

  // Specialcase: If 'default' is checked, return TRUE if the default site language
  // matches the node language.
  if (!empty($conf['language']['default'])) {
    if ($language->language == language_default('language')) {
      return TRUE;
    }
  }

  if (array_filter($conf['language']) && empty($conf['language'][$language->language])) {
    return FALSE;
  }

  return TRUE;
}

/**
 * Provide a summary description based upon the checked site_languages.
 */
function ctools_site_language_ctools_access_summary($conf, $context) {
  $language_identifier = $context->is_type('language') ? $context->get_identifier() : t('Site language');

  $languages = array(
    'default' => t('Default site language'),
  );
  $languages = array_merge($languages, locale_language_list());

  if (!isset($conf['language'])) {
    $conf['language'] = array();
  }

  $names = array();
  foreach (array_filter($conf['language']) as $language) {
    $names[] = $languages[$language];
  }

  if (empty($names)) {
    return t('@language_identifier is any language', array('@language_identifier' => $language_identifier));
  }

  return format_plural(count($names), '@language_identifier is "@languages"', '@language_identifier is one of "@languages"', array('@language_identifier' => $language_identifier, '@languages' => implode(', ', $names)));
}

