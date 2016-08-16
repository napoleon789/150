
<div id="gv-left" class="left width-565">
    <div class="node-node">

        <?php  print '<h1 class="page-title">'. $title .'</h1>'; ?>
        <div class="new-node"><span>Ngày đăng: </span> <?php echo date('H:i m-d-Y',$node -> created)?></div>
        <h3> <?php echo $node->field_teaser[0]['value'];?></h3>
    <?php print_r ($content); ?>
</div>
</div>
<div id="gv-right" class="right width-335">
    <?php
    $right_contents = array();
    $doji_chart_block_views = variable_get('doji_chart_block_views', array());

    if (count($doji_chart_block_views)) {
        unset($doji_chart_block_views['block_3']);
        unset($doji_chart_block_views['block_4']);

        foreach ($doji_chart_block_views as $doji_chart_block) {
            $right_contents[] = doji_charts_view(array('width' => '335px', 'height' => '220px', 'title_fontsize' => '16px', 'chart_block' => $doji_chart_block));
        }
    }

    if (count($right_contents)) {
        $right_content = implode('', $right_contents);
    }
    else {
        $right_content = doji_charts_view(array('width' => '335px', 'height' => '240px'));
    }

    echo $right_content . doji_get_bieu_do_gia_vang_quoc_te();
    // advertisement;
    echo '<img src="/sites/all/themes/doji_gold/images/ad1.jpg" style="padding-left:10px;margin-top:20px;"/>';

    ?>
</div>

