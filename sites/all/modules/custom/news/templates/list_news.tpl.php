<div class="clear-block p-10 size-18">
  <div id="gv-left" class="left width-565">
    <?php
    foreach ($content as $post) { ?>
        <?php $hottem = $post->field_hot[0]['value'];?>
      <div class=" news_entity <?php if(!empty($hottem)) echo "newhost";?> clear-block">
        <div class="left news_left">
          <?php  global $base_path; $field = $post -> field_image;$img = $field[0]['filepath'];?>
          <?php if(isset($img)) : ?>
            <?php  echo '<img width="134" src="'.$base_path.$img.'">'; ?>
          <?php else: ?>
            <?php echo $post->field_avatar_url[0]['value']; ?>
          <?php endif;?>
        </div>
        <div class="right news_right">
          <?php $soure =  $post->field_source[0]['value'];?>
          <?php if(!isset($soure)) :?>
          <?php $post->field_source[0]['value'] = "Giavang";?>
         <?php endif;?>

          <div class="news_source">
              <?php if(!empty($post->field_hot[0]['value'])):?>
                <div class="hot"><img src="/sites/all/themes/doji_gold/images/hot.png"/></div>
              <?php endif;?>
              <?php echo date(" H:i d-m-Y", $post->created) . ' | ' . $post->field_source[0]['value'];?></div>
          <?php global $user; if($user->uid ==1):?>
           <div class="edit_node"> <?php print l('Sửa','node/'.$post->nid.'/edit');?> </div>
          <?php endif; ?>
          <?php $link = $post->field_guid[0]['value']; ?>
          <?php if(!isset($link)) : ?>
          <?php $post->field_guid[0]['value'] =  $base_path.'node/'.$post ->nid;?>
          <?php endif;?>
          <a target="_blank" class="news_desktop" href="<?php echo $post->field_guid[0]['value']; ?>"><div class="news_title"><?php echo $post->title;?></div></a>
          <a class="news_mobile" href="<?php echo $post->field_guid[0]['value']; ?>"><div class="news_title"><?php echo $post->title;?></div></a>
          <div class="news_desc"><?php echo $post->field_teaser[0]['value']?></div>
        </div>
      </div>
    <?php }
    echo news_pagination($page, $total, 'news');
    ?>
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
</div>