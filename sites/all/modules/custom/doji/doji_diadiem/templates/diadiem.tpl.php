<?php if (!isset($_GET['tid'])):?>
<div class="clear-block p-10 size-18">
	<div id="gv-left" class="left" style="width:600px;">
		<div class="w-100 diadiem_title">Danh sách Trung tâm/Cửa hàng:</div>
		<div id="map-canvas" class="w-100"></div>
	</div>

	<div id="list-diadiem" class="right" style="width:280px;">
		<select class="w-100" id="diadiem-area">
          <?php $all = taxonomy_get_tree(1)?>
          <?php foreach($all as $term):?>
  			<option value="<?php echo $term -> tid?>"><?php echo $term -> name?></option>
  		  <?php endforeach;?>
		</select>
      <div id ="contentaj">
      <?php $j = 0;?>
		<?php foreach ($content as $nd ) { ?>
            <?php
            $j++;
            $long = $nd['field_diadiem_long_value'] ;
            $lat = $nd['field_diadiem_lat_value'];
            $info = $nd['field_diadiem_diachi_value'] . ' - SĐT: ' . $nd['field_diadiem_phone_value'];
            $name = $nd['field_diadiem_ten_value'];
            ?>
			<div class="w-100 diadiem_cuahang insert<?php echo $j;?>" onclick='map_init(<?php echo $long.','; echo $lat.','; echo '"'. $info. '"'.','; echo '"'.$name.'"'?>)'>
				<div class="w-100 diadiem_ten"><?php echo $nd['field_diadiem_ten_value'];?></div>
				<div class="w-100 diadiem_info"><?php echo $nd['field_diadiem_diachi_value'] . ' ĐT: ' . $nd['field_diadiem_phone_value'];?></div>
				<div class="diadiem_addr"><?php echo $nd['field_diadiem_diachi_value'].'-'.$nd['field_diadiem_long'];?></div>
			</div>
		<?php } ?>
      </div>
	</div>
</div>
<?php else:?>
  <div id ="contentaj">
    <?php $i = 0?>
    <?php foreach ($content as $nd ) { ?>
      <?php
      $i++;
      $long = $nd['field_diadiem_long_value'] ;
      $lat = $nd['field_diadiem_lat_value'];
      $info = $nd['field_diadiem_diachi_value'] . ' - SĐT: ' . $nd['field_diadiem_phone_value'];
      $name = $nd['field_diadiem_ten_value'];
      ?>
      <div class="w-100 diadiem_cuahang insert<?php echo $i?>" title="<?php echo $long?>" rel ="<?php echo $lat?>" onclick='map_init(<?php echo $long.','; echo $lat.','; echo '"'. $info. '"'.','; echo '"'.$name.'"'?>)'>
        <div class="w-100 diadiem_ten"><?php echo $nd['field_diadiem_ten_value'];?></div>
        <div class="w-100 diadiem_info"><?php echo $nd['field_diadiem_diachi'] . ' ĐT: ' . $nd['field_diadiem_phone_value'];?></div>
        <div class="diadiem_addr"><?php echo $nd['field_diadiem_diachi_value'].'-'.$nd['field_diadiem_long'];?></div>
      </div>
    <?php } ?>
  </div>
<?php endif;?>