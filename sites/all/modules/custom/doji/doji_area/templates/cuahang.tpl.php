<div class="system_store">
  <div class="add_store"><a href="/node/add/store">Thêm bảng hiện thị</a></div>
  <?php $header = doji_cuahang_get_header();?>
  <div class ="table_four">
  <?php foreach($content as $k => $list):?>
    <div class="num_table">
   <h2 class="title"><?php echo $list['title']?></h2>
    <?php $n  = $k +1; ?>
    <div class="item_table">
      <?php echo theme('table',$header,$list)?>
    </div>
    <div class="system_footer"><a href="/node/<?php echo $list['vid']?>/edit">Edit</a>
    <a href="/system/<?php print 'doji_'.$list['vid'].'/'.$list['vid']?>">Xem hiển thị</a>
    <a href="/system/<?php print 'doji_'.$list['vid'].'/'.$list['vid']?>">Xóa bảng</a>
    </div>
    </div>
    <?php if((($k+1) % 4) == 0 ) :?>
    </div><div class="table_four">
    <?php endif;?>
  <?php endforeach;?>
    </div>
  <div class="add_store"><a href="/node/add/store">Thêm bảng hiện thị</a></div>
</div>