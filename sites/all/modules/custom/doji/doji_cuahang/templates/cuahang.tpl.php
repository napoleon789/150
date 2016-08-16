<?php
$bien = arg(2);
$mn ='';
$mt ='';
$mb ='';
  if(arg(3) == 2)
    $mn = 'class="active"';
  if(arg(3) == 1)
    $mt = 'class ="active"';
  if(!isset($bien))
    $mb = 'class="active"';
?>

<div class="system_store">
<ul>
  <li><a <?php echo $mb ?> href="/doji/banggia">Miền Bắc</a> </li>
  <li><a <?php echo $mt ?> href="/doji/banggia/he-thong-ban-le/1">Miền Trung</a> </li>
  <li><a <?php echo $mn ?> href="/doji/banggia/he-thong-ban-le/2">Miền Nam</a> </li>
</ul>
  <?php $header = doji_cuahang_get_header();?>
  <div class ="table_four">
  <?php foreach($content as $k => $list):?>
    <div class="num_table">
   <h2 class="title"><?php echo $list['title']?></h2>
    <?php $n  = $k +1; ?>
    <div class="item_table">
      <?php echo theme('table',$header,$list)?>
    </div>
    <div class="system_footer">
        <ul>
            <li class="view"><a target="_blank" href="/system/<?php print 'doji_'.$list['vid'].'/'.$list['vid']?>">Xem hiển thị</a></li>
            <li class="edit"><a href="/node/<?php echo $list['vid']?>/edit">Edit</a></li>
            <li class="delete"><a  href="/node/<?php print $list['vid']?>/delete?destination=doji/banggia">Xóa bảng</a></li>
        </ul>
    </div>
    </div>
    <?php if((($k+1) % 4) == 0 ) :?>
    </div><div class="table_four">
    <?php endif;?>
  <?php endforeach;?>
    </div>

</div>