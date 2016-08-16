<?php
/**
 * Created by JetBrains PhpStorm.
 * User: taole
 * Date: 7/15/14
 * Time: 10:29 AM
 * To change this template use File | Settings | File Templates.
 */
?>
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
<body class="<?php print $body_classes;?> page-admin-cuahang">
<div class="bn20">
    <div class="ban_destop" ><img src="http://giavang-dev.doji.vn/sites/all/themes/doji_gold/images/banner.jpg" width="970" ></div>
    <div class="ban_mobile" ><img src="http://giavang-dev.doji.vn/sites/all/themes/doji_gold/images/banner.jpg" width ="auto" ></div>
</div>
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