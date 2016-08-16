<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>">
<head>
  <title><?php print $head_title ?></title>
  <meta name="viewport" content="width=device-width,initial-scale=1.0" />
  <meta http-equiv="content-language" content="<?php print $language->language ?>" />
  <?php print $meta; ?>
  <?php print $head; ?>
  <?php print $styles; ?>
  <!--[if lte IE 7]>
    <link rel="stylesheet" href="<?php print $base_path . $bp_library_path; ?>doji_gold/ie.css" type="text/css" media="screen, projection">
    <link href="<?php print $path_parent; ?>css/ie.css" rel="stylesheet"  type="text/css"  media="screen, projection" />
    <?php $styles_ie_rtl['ie']; ?>
  <![endif]-->
  <!--[if lte IE 6]>
    <link href="<?php print $path_parent; ?>css/ie6.css" rel="stylesheet"  type="text/css"  media="screen, projection" />
    <?php $styles_ie_rtl['ie6']; ?>
  <![endif]-->  
  <script type="text/javascript" src="https://maps.googleapis.com/maps/api/js?key=AIzaSyBCCCPgC3bft1lSsxZ2V3_MhovxoI-oEn4&sensor=false" ></script>
</head>

<body class="<?php print $body_classes; ?>">
<!--
<div class="ban_destop" ><img src="<?php echo $base_url?>/sites/all/themes/doji_gold/images/banner.jpg" width="970" ></div>
<div class="ban_mobile" ><img src="<?php echo $base_url?>/sites/all/themes/doji_gold/images/banner.jpg"  ></div>
-->
<div id="container">
  <div id="header" class="clear-block">
      <?php if ($title): ?>
        <div id="logo" class="site_title">
          <?php print $logo_block; ?>

        </div>
      <?php else: ?>
        <h1 id="logo">
          <?php print $logo_block; ?>

        </h1>
      <?php endif; ?>
  </div>

  <?php if ($left): ?>
    <div class="<?php print $left_classes; ?>"><?php print $left; ?></div>
  <?php endif ?>

  <div class="<?php print $center_classes; ?>">
    <div id="col-center-top" class="clear-block">
      <?php print $logo2_path;?>
     <a href="/"> <img class="icon20" src="<?php echo $base_url?>/sites/all/themes/doji_gold/icon20.png" width="58"></a>
      <div id="col-center-bottom" class="clear clear-block">
        <div id="col-center-middle" class="clear-block">
          <?php
            if ($tabs != '') {
              print '<div class="tabs">'. $tabs .'</div>';
            }
             if($user -> uid <= 0) {
               ?>
          <div class="tabs"><ul class="tabs primary">
              <li  ><a href="/trangchu.html" >Trang chủ</a></li>
              <li ><a href="/bieudo.html">Biểu đồ</a></li>
              <li><a href="/doji/tintuc" >Tin Tức</a></li>
              <li><a href="/doji/diadiem" >Địa điểm</a></li>
          </div>
          <?php
             }
            if ($messages != '') {
              print '<div id="messages">'. $messages .'</div>';
            }
      
            if ($title != '') {
              print '<h1 class="page-title">'. $title .'</h1>';
            }
      
            print $help; // Drupal already wraps this one in a class
      
            print $content;
          ?>          
        </div>    
      </div>  
    </div>
  </div>

  <?php if ($right): ?>
    <div class="<?php print $right_classes; ?>"><?php print $right; ?></div>
  <?php endif ?>
  
  <?php if ($footer_message || $footer): ?>
    <div id="footer" class="clear-block">
      <?php if ($footer): ?>
        <?php print $footer; ?>
      <?php endif; ?>
      <?php if ($footer_message): ?>
        <div id="footer-message"><?php print $footer_message; ?></div>
      <?php endif; ?>
    </div>
  <?php endif; ?>      
  <?php print $closure; ?>
</div>
  <?php print $scripts ?>
  <?php if (user_access('create goldprice content')):?>
    <script type="text/javascript" src="<?php print url('doji/js/doji_calculator.js');?>"></script>
  <?php endif;?>  
</body>
</html>