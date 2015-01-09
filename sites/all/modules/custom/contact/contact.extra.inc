<?php

function contact_extra($wildcard) {
  $content = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('The wildcard: "%wildcard".', array('%wildcard' => $wildcard)) . '</p>',
  );

  return $content;
}