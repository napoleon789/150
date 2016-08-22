<?php
$m = array(1,2,3,4,5,6,7,8,9,10);
$i = 0;
foreach($m as $k => $value) {
  $i++;
  if($value % 3 ==0)
    continue;
  echo $i;
}