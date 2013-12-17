<?php

/**
 * @file
 *
 * Plugin to provide a language context
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Language'),
  'description' => t('A language context.'),
  'context' => 'ctools_context_create_language',
  'keyword' => 'language',
  'edit form' => 'ctools_context_language_settings_form',
  'context name' => 'language',
  'convert list' => 'ctools_context_language_convert_list',
  'convert' => 'ctools_context_language_convert',
);

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function ctools_context_create_language($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('language');
  $context->plugin = 'language';

  if ($empty) {
    return $context;
  }

  // We've been given a full language object.
  if (is_object($data)) {
    $context->data = $data;
    $context->title = $data->native;
    return $context;
  }
  // We've been given a UI configured language.
  if (is_array($data) && isset($data['language'])) {
    switch ($data['language']) {
      case 'current':
        global $language;
        break;
      default:
        // Assume we have a language code.
        $languages = language_list();
        $language = $languages[$data['language']];
        break;
    }
    $context->data = $language;
    $context->title = $language->native;
    return $context;
  }
  // This is probably a programatically passed language code.
  if (is_string($data)) {
    $languages = language_list();
    if (isset($languages[$data])) {
      $language = $languages[$data];
      $context->data = $language;
      $context->title = $language->native;
    }
    return $context;
  }
}

function ctools_context_language_settings_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $options = array(
    'current' => t('Current Language'),
  );
  $languages = language_list();
  foreach ($languages as $code => $language) {
    $options[$code] = $language->native;
  }

  $form['language'] = array(
    '#type' => 'select',
    '#title' => t('Choose Language Context'),
    '#default_value' => $conf['language'],
    '#options' => $options,
  );
  return $form;
}

function ctools_context_language_settings_form_submit($form, &$form_state) {
  $form_state['conf']['language'] = $form_state['values']['language'];
}

/**
 * Provide a list of ways that this context can be converted to a string.
 */
function ctools_context_language_convert_list() {
  return array (
    'language' => t('Language Code'),
    'name' => t('English Language Name'),
    'native' => t('Native Language Name'),
    'direction' => t('Language Direction'),
    'enabled' => t('Language Status'),
    'plurals' => t('Plurals'),
    'formula' => t('Plural Formula'),
    'domain' => t('Domain Prefix Language Code'),
    'prefix' => t('URL Prefix Language Code'),
    'weight' => t('Language Weight'),
  );
}

/**
 * Convert a context into a string.
 */
function ctools_context_language_convert($context, $type) {
  return $context->data->{$type};
}
