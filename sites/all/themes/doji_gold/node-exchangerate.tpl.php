<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?> <?php if ($page) { print ' node-full '; } ?> <?php if (!$status) { print ' node-unpublished'; } ?> clear-block">
  <?php
    $exchangerate_defined = doji_get_exchangerate_defined(); 
    foreach ($exchangerate_defined as $key=>$values) {
      $k = trim($key);
      if (isset($node->{"field_exchangerate_" . strtolower($k)}[0]['value'])) {
        $exchangerates[$key]['CURRENCYCODE'] = $key;
        $exchangerates[$key]['CURRENCYNAME'] = $values;    
        $exchangerates[$key]['BUY'] = isset($node->{"field_exchangerate_" . strtolower($k)}[0]['value']) ? $node->{"field_exchangerate_" . strtolower($k)}[0]['value'] : 0;
        $exchangerates[$key]['TRANSFER'] = isset($node->{"field_exchangerate_" . strtolower($k)}[1]['value']) ? $node->{"field_exchangerate_" . strtolower($k)}[1]['value'] : 0;
        $exchangerates[$key]['SELL'] = isset($node->{"field_exchangerate_" . strtolower($k)}[2]['value']) ? $node->{"field_exchangerate_" . strtolower($k)}[2]['value'] : 0;
      }
    }          
    print theme('doji_get_exchangerate', $exchangerates);
    drupal_set_title($node->title);
  ?>
</div>