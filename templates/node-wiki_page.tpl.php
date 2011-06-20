<?php
// $Id$

/**
 * @file
 * Template to render wiki pages.
 */
?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix">
<?php if ($teaser == TRUE): ?>
  <div class="picture"><?php print $field_wiki_images[0]['view']; ?></div>

  <div class="content">

    <?php if ($node->title): ?>
      <h3><?php print l($node->title, 'node/' . $node->nid); ?></h3>
    <?php endif; ?>
    
    <div class="meta">
      <span class="time">
        <?php print format_date($node->created, 'custom', "j F Y") ?>
      </span>
      <span class="author">
        <?php print t('by') . ' ' . theme('username', $user); ?>
      </span>

      <?php print $node->field_library_ref[0]['view'];  ?>
    </div>

    <?php print $node->field_teaser[0]['value']; ?>

    <?php if (count($taxonomy)) { ?>
      <div class="taxonomy">
        <?php print $terms; ?>
      </div>
    <?php } ?>    
    
  </div>
<?php else: ?>
	<div class="content">
		<?php print $content ?>
	</div>

	<?php if ($links){ ?>
    <?php  print $links; ?>
	<?php } ?>
<?php endif; ?>
</div>
