<?php
/**
 * @file
 * Includes order system module mail settings.
 */

/**
 * Implements hook_mail().
 */
function order_system_mail($key, &$message, $params) {
  global $user;

  $options = array(
    'langcode' => $message['language']->language,
  );

  switch ($key) {
    // Send notification message from order system.
    case 'order_system_email_notification':
      // Get order system mail notification template.
      $mail_notification_template = variable_get('order_system_mail_notification_template');

      $message['subject'] = $mail_notification_template['subject'];

      $message['body'][] = $mail_notification_template['body'];
      $message['body'][] = check_plain($params['message']);
      break;
  }
}

/**
 * Sends an e-mail process function.
 */
function order_system_mail_send() {
  global $user;

  $module = 'order_system';
  $key = 'order_system_email_notification';

  // Specify 'to' address.
  $to = $user->mail;

  $language = language_default();
  $send = TRUE;

  $result = drupal_mail($module, $key, $to, $language, array(), NULL, $send);
  if ($result['result'] == TRUE) {
    drupal_set_message(t('Your message has been sent.'));
  }
  else {
    drupal_set_message(t('There was a problem sending your message and it was not sent.'), 'error');
  }
}
