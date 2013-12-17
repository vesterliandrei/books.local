<?php

/**
 * @file
 *
 * Plugin to provide an argument handler for a language context.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Language'),
  // keyword to use for %substitution
  'keyword' => 'language',
  'description' => t('Creates a language context from a language code.'),
  'context' => 'ctools_argument_language_context',
);

/**
 * Discover if this argument gives us the node we crave.
 */
function ctools_argument_language_context($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If unset it wants a generic, unfilled context.
  if (!isset($arg)) {
    return ctools_context_create_empty('language');
  }

  return ctools_context_create('language', $arg);
}
