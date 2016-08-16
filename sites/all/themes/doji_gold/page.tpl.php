<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>">
<head>
  <title><?php print $head_title ?></title>
  <meta name="viewport" content="width=device-width,initial-scale=1.0" />
  <meta http-equiv="content-language" content="<?php print $language->language ?>" />
  <?php print $meta; ?>

    <script src="<?php global $theme_path;global $base_url; echo $base_url."/". $theme_path;?>/scripts/angular.min.js"></script>
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
</head>
<?php  if(arg(1) == 'diadiem') :?>

    <script async defer src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCXLGdyqwDSRqZ1gCIJIKqqY5g8B4zmyqk&callback=map_init"
            type="text/javascript"></script>
 <?php endif;?>
</head>

<?php global $user;?>
<?php if ($user->uid ==1):?>
<?php $m = "ad_class "?>
<?php endif;?>
<?php if ($user->uid >1):?>
  <?php $m = "ad_quantri "?>
<?php endif;?>
<body class="<?php print $body_classes;echo $m; if(arg(2)=='store' || arg(1) =='banggia') echo "page-store"?>"  ng-app="front"  >

  <div id="container"ng-controller="home" >
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

  <div class="<?php print $center_classes; ?>"  >
    <div id="col-center-top" class="clear-block" data-ng-init= Start()>
      <?php print $logo2_path;?>

        <div id="col-center-bottom" class="clear clear-block">
        <div id="col-center-middle" class="clear-block">
            <div class="content_home">
                <div class="content-middle">
                  <?php global $user; if($user -> uid > 0):?>
                    <?php if ($user -> uid ==1):?>
                  <div class="left_menu_main">
                    <ul>
                      <li class="hide"><a href="#"></a> </li>
                      <li class="home"><a href="#"></a> </li>
                      <li class="biedo"><a href="#"></a> </li>
                      <li class="tintuc"><a href="#"></a> </li>
                      <li class="diadiem"><a href="#"></a> </li>
                    </ul>
                  </div>
                    <?php endif;?>
                  <?php endif;?>
                    <?php
                    if (isset($tabs)) {
                        print '<div class="tabs">'. $tabs .'</div>';
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
                <?php if ($right): ?>
                    <div class="<?php print $right_classes; ?>"><?php print $right; ?></div>
                <?php endif ?>
            </div>
        </div>
      </div>
    </div>
  </div>
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

<?php if(!isset($_SESSION['popup'])) :?>
  <?php $_SESSION['popup'] = 1; ?>
<button id="popup_window" data-popup-target="#example-popup">Open The Light Weight Popup Modal</button>

<div id="example-popup" class="popup">
  <div class="popup-body">
    <h2 class="popup-title">Thông báo</h2>
    <div class="popup-content">

      <p>Giá vàng DOJI - ứng dụng toàn diện nhất về thị trường vàng đã có trên App Store! Bấm OK để tải ngay!</p>
     <div class="p_btom"> <a href="https://itunes.apple.com/us/app/gia-vang-doji/id866767924?mt=8"><span id ="ok_tat">Ok </span></a><a href ="javascript:void(0);" id ="p_cancel"><span class="popup-exit"> Bỏ qua</span></a></div>
    </div>
  </div>


</div>
<div class="popup-overlay"></div>

<?php endif ;?>

</body>
</html>