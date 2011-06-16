<?php
// $Id$

/**
 * @file
 * Template to render wiki pages.
 */
?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix">
	<div class="content">
		<?php print $content ?>
	</div>

	<?php if ($links){ ?>
    <?php  print $links; ?>
	<?php } ?>

</div>
