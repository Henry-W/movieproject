<?php

/*
 * Implements /contact
 */
function contact_form() {
  return drupal_get_form('contact_form_func');
}

function contact_form_func() {
  $form = array();

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#required' => TRUE,
  );

  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

function contact_form_func_validate(&$form, &$form_state) {
  if ($form_state['values']['name'] == 'test') {
    form_set_error('name', t('Please use a real name'));
  }
}

function contact_form_func_submit(&$form, &$form_state) {

  $module = 'contact';
  $key = 'key';
  $message = drupal_mail($module, $key, t(variable_get('contact_email_to', NULL)), language_default(), $form_state, NULL, TRUE);

  $message['subject'] = variable_get('contact_email_subject', 'New Message Received');

  $message['body'] = array($form_state['values']['message']);

  $system = drupal_mail_system($module, $key);

  // Format the message body.
  $message = $system->format($message);

  // Send e-mail.
  $system->mail($message);

  drupal_set_message(t(variable_get('contact_email_success_message', 'Thank you for your message! We will get back to you soon.')));
}