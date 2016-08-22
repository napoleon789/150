// $Id: doji.js,v 1.0 2011/10/13 13:25:57 tvazone Exp $
jQuery(document).ready(function() {
//    $(".admin-tbl-gold tr:eq(0)").before("<div class='pre_table'>Show</div>");
//    var item = $('.page-doji .admin-tbl-gold tbody tr').length - $('.page-doji .admin-tbl-gold tbody tr').length%30;
//    var itemNone = Math.floor($('.page-doji .admin-tbl-gold tbody tr').length/30);
//    console.log(itemNone);
//    var i=1;
//    $('.page-doji .admin-tbl-gold tbody tr').each(function(){
//        i++;
//        if (i<=item +1){
//            $(this).hide();
//        }
//    });
//    $('.page-doji .admin-tbl-gold tbody tr:first-child').show();
//
//    var clickNum =1;
//    if (clickNum<=itemNone){
//        $('.pre_table').click(function(){
//            for (j=1;j< clickNum*30; j++) {
//                $('.page-doji .admin-tbl-gold tbody tr:eq('+ j + ')').show();
//            }
//            clickNum++;
//        });
//
//    }
    $('.logged-in.page-admin .column-main #edit-submit-1').click(function(){
        $('#noitce-message').bPopup().show();
    });
    $('.logged-in.page-admin .column-side #edit-submit').click(function(){
        $('#noitce-message').bPopup().show();
    });
});