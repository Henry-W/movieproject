<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * This template is derived from the Zen default node.tpl.php template. It adds:
 * - Conditional linking of the node title depending on whether the $node_url
 *   variable is set or not.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<?php dpm($content); ?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php
  hide($content['field_review_date']);
  hide($content['field_reviewer']);
  hide($content['field_trailers_external_link']);
  hide($content['field_in_cinemas_external_link']);
  hide($content['field_buy_dvd_external_link']);
  hide($content['field_netflix_external_link']);
  ?>

  <p>by <b><?php print render($content['field_reviewer']); ?></b> on <b><i><?php print render($content['field_review_date'][0]); ?></i></b></p>

  <ul class="group-review-links">
    <li><?php print render($content['field_trailers_external_link']); ?> | </li>
    <li><?php print render($content['field_in_cinemas_external_link']); ?> | </li>
    <li><?php print render($content['field_buy_dvd_external_link']); ?> | </li>
    <li><?php print render($content['field_netflix_external_link']); ?></li>
  </ul>

  <?php print render($content); ?>

</article>
