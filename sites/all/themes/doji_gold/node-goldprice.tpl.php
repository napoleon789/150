<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?> <?php if ($page) { print ' node-full '; } ?> <?php if (!$status) { print ' node-unpublished'; } ?> clear-block">
  <?php
    print theme('doji_goldprice_view', $node);
  ?>
</div>