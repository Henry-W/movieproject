<?php
/*
 * Implements hook_admin().
 */
function contact_admin_settings_form($form, &$form_state) {
  $form = array();

  $form['contact_email_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Recipient Email Address'),
    '#default_value' => t(variable_get('contact_email_to', 'myemail@example.com')),
    '#description' => t("The email address which will receive the contact submissions."),
    '#required' => TRUE,
  );

  $form['contact_email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Subject'),
    '#default_value' => t(variable_get('contact_email_subject', 'New Message Received')),
    '#description' => t("The subject line to be used in the email."),
    '#required' => TRUE,
  );

  $form['contact_email_success_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Contact Success Message'),
    '#default_value' => t(variable_get('contact_email_success_message', 'Thank you for your message! We will get back to you soon.')),
    '#description' => t("The message to display to a user who has just submitted a message."),
    '#required' => FALSE,
  );

  return (system_settings_form($form));
}