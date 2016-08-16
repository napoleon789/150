angular.module('front', [])
    .directive('ngIf', function() {
        return {
            link: function(scope, element, attrs) {
                if(scope.$eval(attrs.ngIf)) {
                    element.replaceWith(element.children());
                } else {
                    element.replaceWith(' ');
                }
            }
        }
    })
    .directive('onFinishRender', function () {
                return {
                        restrict: 'A',
                        link: function (scope, element, attr) {
                            if (scope.$last === true) {
                                    element.ready(function () {
                                           scope.afterLoad();
                                        });
                                }
                        }
                }
            })
    .controller("home", function($scope, $http, $interval,$timeout) {
        function f5(){
            $http.get('/giavangmobileui/canhbao')
                .success(function(datas, status, headers, config) {
                    $scope.datas = {};
                    $scope.datas = datas;
                    $scope.afterLoad = function(){
                        var check_canhbao = $('.wt-cb .row').html();
                        if(check_canhbao ===''){$('.wt-cb').hide();}else{$('.wt-cb').show();}
                        $('.canhBaoLoading').remove();
                        $('.canhBaoTop').show();
                        $('#block-doji_area-canhbao_ajax .content').jScrollPane();
                    }
                })
                .error(function(data, status, headers, config) {
                    // log error
                   // console.log(status,headers,config);

                });

        }
        var interval = null;
        $scope.Start = function() {
            return interval =  $interval(f5, 4000);//goi lai f5 de lay du lieu sau 900 ms
        }

        $scope.Stop = function() { $interval.cancel( interval); console.log("------------ STOP -------------"+interval);return interval = undefined; }

    });
jQuery(document).ready(function() {

    // Bảng thiết lập giá nhanh của admin HÀ NỘI
    var admin_menu = $('body').hasClass('ad_class');
    if (admin_menu){
        $('.ad_class #block-doji_area-setting_value_vung .content thead').remove();
        $('.dk_edit').hide();
        $('span.save').hide();
        $('span.huy').hide();

        $('<div class="cloneFormHeader table">'
        +'<div class="table-cell first">TT</div>'
        +'<div class="table-cell chungloai">Chủng loại</div>'
        +'<div class="table-cell gia">Giá</div>'
        +'<div class="table-cell thamchieu">Giá tham chiếu</div>'
        +'<div class="table-cell gia">Giá </div>'
        +'<div class="table-cell biendo">Biên độ giá</div>'
        +'<div class="table-cell dieukien">Điều kiện</div>'
        +'<div class="table-cell chinhsua">Điều chỉnh</div>'
        +'</div>').insertBefore('#block-doji_area-setting_value_vung .content');

        $('.ad_class #block-doji_area-setting_value_vung .content').jScrollPane();

        $('span.sua').click(function(){
            $(this).parent().children('span').show();
            $(this).hide();
            $(this).parents('tr').children('.input_dk').hide();
            $(this).parents('tr').children('.dk_edit').show();
        });

        $('span.huy').click(function(){
            $(this).parent().children('span').hide();
            $(this).parent().children('span.sua').show();
            $(this).parents('tr').children('.input_dk').show();
            $(this).parents('tr').children('.dk_edit').hide();
        });

        $('span.save').click(function(){
            var giaThamChieu = $(this).parents('tr').children('.gia_thamchieu').text()
                ,giaThamChieu = parseInt(giaThamChieu)
                ,bienDoGia = $(this).parents('tr').children('.dk_edit').find('input').val()
                ,bienDoGia = parseInt(bienDoGia)
                ,giaTriTren = giaThamChieu + bienDoGia
                ,giaTriDuoi = giaThamChieu - bienDoGia
                ,position = $(this).parents('tr').children('td:first-child').text()


                ,bdo = $(this).parents('tr').children('.bdo')
                ,dk_edit = $(this).parents('tr').children('.dk_edit')
                ,input_dk = $(this).parents('tr').children('.input_dk')
                ,ctr = $(this).parent();

            $.ajax({ url: 'biendo/thietlap'+'?biendo='+bienDoGia+'&delta='+position+'&giaban='+giaThamChieu,
                dataType: 'JSON',
                beforeSend:function(){
                    ctr.children('span').hide();
                    ctr.append('<p>Loading...</p>');
                },
                success: function(output) {
                    var result = Drupal.parseJson(output);
                    ctr.children('p').remove();
                    ctr.children('span.sua').show();
                    dk_edit.hide();
                    input_dk.show().html(bienDoGia);
                    bdo.html(giaTriDuoi+' - '+giaTriTren);
                }
            });

        });

    }else{return 0;}

    //popup canh bao gia vang
   // popUpCanhBao();
});




function checkAdminVung(){
    var adminHanoi = $('body').hasClass('ad_class'),
        adminVung = $('body').hasClass('ad_quantri');
    if(adminHanoi){
        return '<div  ng-click= Start();  class="ctr"><a href ="#"class="cho-phep">Cho phép</a><a href ="#" class="right tu-choi">Từ chối</a></div>';
    }else if(adminVung){return '';}
}
function clickToRemove(){
    var top =  $('#col-center-top').position().top
        ,left =  $('#col-center-top').position().left
        ,wd_wigth = $(document).width()
        ,wd_height = $(document).height();
    $( "#clickToRemove" ).live( "click", function() {
        $('#popup').remove();
        $(this).remove();
        $('body').removeClass('canhBaoPopup');
        angular.element(document.getElementById('col-center-top')).scope().$apply(function(scope){
           scope.Start();
        });
    });
    $('<div id="clickToRemove" ng-click=" Start()"  style=" width: '+wd_wigth+'px; height:'+wd_height+'px; position:absolute; left:-'+left+'px; top: -'+top+'px;"></div>').appendTo('#col-center-top');
    $('body').addClass('canhBaoPopup');
}
//popup canh bao gia vang
function popUpCanhBao(){
    $("li.canhbao").live('click',function(){
        angular.element(document.getElementById('col-center-top')).scope().$apply(function(scope){
            scope.Stop();
        });
        $('#popup').remove();
        $('#clickToRemove').remove();
        $(".arrow").removeClass('arrow-bottom arrow-top');
        var top =  $(this).offset().top
            ,left =  $(this).offset().left
        /*top =  $(this).position().top
         ,left =  $(this).position().left*/
            ,height = $(this).height()
            ,popup_content = $(this).children('.table-left').children('.hienthi_rowpoup').clone()
            ,rel = $(this).attr('rel')
            ,ctr = checkAdminVung();
        if( top < 145){
            $('<div id="popup" style="top:'+top+'px;/*left:'+left+'px;*/left:965px;margin-top:'+height+'px" rel= '+rel+'><div class="top-popover"><div class="arrow arrow-top"></div></div><div class="content-popover"></div>'+ctr+'</div> ').appendTo('#col-center-top');
        }
        else {$('<div id="popup" style="top:'+top+'px;/*left:'+left+'px;*/left:965px;"rel= '+rel+'><div class="top-popover"><div class="arrow arrow-top"></div></div><div class="content-popover"></div>'+ctr+'</div>').appendTo('#col-center-top'); }
        clickToRemove();
        $('#popup .content-popover').html(popup_content);
        $('#popup .content-popover .hienthi_rowpoup').show();
        $(this).addClass('this-active');
    });

    // xu ly popup canh bao
    $( "#popup a.cho-phep" ).live( "click", function() {
        var id = $(this).parents('#popup').attr('rel');
        $(this).parents('.ctr').html('<span class="popUpLoad">loading...</span>');

        $.ajax({ url: 'duyet/content/'+id,
            dataType: 'JSON',
            success: function(output) {
                var result = Drupal.parseJson(output);
                $('#popup').remove();
                $('#clickToRemove').remove();
                //  location.reload();
                angular.element(document.getElementById('col-center-top')).scope().$apply(function(scope){
                    scope.Start();
                });
                $('.canhBaoTop').html('Loading....');
                location.reload();
            }
        });
    });
    $( "#popup a.tu-choi" ).live( "click", function() {
        var id = $(this).parents('#popup').attr('rel');
        $(this).parents('.ctr').html('<span class="popUpLoad">loading...</span>');
        $.ajax({ url: 'tuchoi/content/'+id,
            dataType: 'JSON',
            success: function(output) {
                //location.reload();
                var result = Drupal.parseJson(output);
                $('#clickToRemove').remove();
                $('#popup').remove();
                angular.element(document.getElementById('col-center-top')).scope().$apply(function(scope){
                    scope.Start();
                });
                $('.canhBaoTop').html('Loading....');
                location.reload();
            }
        });
    });

    $( window ).resize(function() {
        var admin_menu = $('body').hasClass('canhBaoPopup');
        if (admin_menu){ console.log('true!');$('#clickToRemove').remove();clickToRemove();}else{console.log('false !');return 0;}
    });
}
