<?php
// $Id$
/**
 * Available variables:
 * - $materials_number: Materials number (optional).
 * - $title: Item title, possibly a link.
 * - $authors: Authors (optional).
 * - $type: Item type (optional).
 */
?>
<span class="title"><?php print $title; ?></span>
<?php if ($authors or $type) { ?>
  <span class="creator">
  <?php if ($authors) { ?>
    <span class="byline"><?php print t('by'); ?></span>
    <?php print $authors; ?>
  <?php } ?>
  <?php if ($type) { ?>
    <span class="type">(<?php print $type; ?>)</span>
  <?php } ?>
</span>
<?php } ?>