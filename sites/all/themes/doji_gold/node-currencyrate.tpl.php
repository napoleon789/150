<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?> <?php if ($page) { print ' node-full '; } ?> <?php if (!$status) { print ' node-unpublished'; } ?> clear-block">
  <?php
    $currencyrates = array();
    $currencyrate_defined = dpji_get_currencyrate_defined();
    foreach ($currencyrate_defined as $key=>$values) {
      $k = trim($key);
      if (isset($node->{"field_currencyrate_" . strtolower($k)}[0]['value'])) {
        $currencyrates[$key][0] = isset($node->{"field_currencyrate_" . strtolower($k)}[0]['value']) ? $node->{"field_currencyrate_" . strtolower($k)}[0]['value'] : 0;
        $currencyrates[$key][1] = isset($node->{"field_currencyrate_" . strtolower($k)}[1]['value']) ? $node->{"field_currencyrate_" . strtolower($k)}[1]['value'] : 0;
        $currencyrates[$key][2] = isset($node->{"field_currencyrate_" . strtolower($k)}[2]['value']) ? $node->{"field_currencyrate_" . strtolower($k)}[2]['value'] : 0;
        $currencyrates[$key][3] = isset($node->{"field_currencyrate_" . strtolower($k)}[3]['value']) ? $node->{"field_currencyrate_" . strtolower($k)}[3]['value'] : 0;
        $currencyrates[$key][4] = isset($node->{"field_currencyrate_" . strtolower($k)}[4]['value']) ? $node->{"field_currencyrate_" . strtolower($k)}[4]['value'] : 0;
        $currencyrates[$key][5] = isset($node->{"field_currencyrate_" . strtolower($k)}[5]['value']) ? $node->{"field_currencyrate_" . strtolower($k)}[5]['value'] : 0;
        $currencyrates[$key][6] = isset($node->{"field_currencyrate_" . strtolower($k)}[6]['value']) ? $node->{"field_currencyrate_" . strtolower($k)}[6]['value'] : 0;
      }
    }
    print theme('doji_get_currencyrate', $currencyrates);
    drupal_set_title($node->title);
  ?>
</div>