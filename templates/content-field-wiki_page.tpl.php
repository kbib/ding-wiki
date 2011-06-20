<?php
// $Id: content-field.tpl.php,v 1.1.2.5 2008/11/03 12:46:27 yched Exp $

/**
 * @file content-field.tpl.php
 * Default theme implementation to display the value of a field.
 *
 * Available variables:
 * - $node: The node object.
 * - $field: The field array.
 * - $items: An array of values for each item in the field array.
 * - $teaser: Whether this is displayed as a teaser.
 * - $page: Whether this is displayed as a page.
 * - $field_name: The field name.
 * - $field_type: The field type.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $label: The item label.
 * - $label_display: Position of label display, inline, above, or hidden.
 * - $field_empty: Whether the field has any valid value.
 *
 * Each $item in $items contains:
 * - 'view' - the themed view for that item
 *
 * @see template_preprocess_field()
 */
?>

<?php if (!$field_empty) : ?>
<div class="field <?php print $field_name_css ?>">

  <?php if ($label_display == 'above') : ?>
    <h3><?php print t($label) ?></h3>
  <?php endif;?>

  <?php foreach ($items as $delta => &$item) :
      if ($item['empty']) :
        unset($items[$delta]);
      else :
        $item = $item['view'];
      endif;
    endforeach;
    print (sizeof($items) > 1) ? theme('item_list', $items) : array_pop($items);
  ?>


</div>
<?php endif; ?>
