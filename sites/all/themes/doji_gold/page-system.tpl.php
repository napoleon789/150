<?php
global $theme_path;
global $base_url;
$path_jquery =$base_url."/".drupal_get_path('module', 'jquery_update')."/replace/jquery.min.js";
$path = $base_url.'/banggia/'.arg(1).'/'.arg(2);
?>
<!DOCTYPE html>
<html><head>
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title>Giá vàng doji</title>
    <script type="text/javascript" src="<?php echo $path_jquery;?>"></script>
    <script type="text/javascript" src="<?php echo $base_url."/". $theme_path;?>/scripts/xml2json.js"></script>

    <script src="<?php echo $base_url."/". $theme_path;?>/scripts/angular.min.js"></script>


    <link rel="stylesheet" href="<?php echo $base_url."/". $theme_path;?>/css/banggia/stylesheets/screen.css" type="text/css" media="screen">




    <script type="text/javascript">//<![CDATA[
        angular.module('front', [])
            .controller("home", function($scope, $http, $interval,$timeout) {
                function f5(){
                    $http.get('<?php echo $path?>').
                        success(function(data, status, headers, config) {
                            $scope.data = {};
                            $scope.data = data;

                            var x2js = new X2JS();
                            $scope.data2 = x2js.xml_str2json($scope.data);
                            $scope.bgs =$scope.data2.GoldList.LED.Row;
                            $scope.info = $scope.data2.GoldList.LED.info;
                            console.log($scope.data2);
                        }).
                        error(function(data, status, headers, config) {
                            // log error
                            console.log(status,headers,config);
                        });

                }
               var interval = null;
                    interval = $interval(f5, 900);//goi lai f5 de lay du lieu sau 100 ms
                /*   $scope.myStopFunction = function() { $interval.cancel( interval);interval = undefined; console.log("------------ STOP -------------");}
*/


            });


        //đồng hồ bảng giá
        var sec = true;
        function startTime(sec) {
            var today=new Date();
            var d=today.getDate();
            var mth=1+today.getMonth();
            var y= today.getFullYear();
            var h=today.getHours();
            var m=today.getMinutes();
            var s=today.getSeconds();
            h = checkTime(h);
            m = checkTime(m);
            s = checkTime(s);
            document.getElementById('day').innerHTML = d+'-'+mth+'-'+y;
            document.getElementById('clock').innerHTML = h+'<span id="dot">:</span>'+m;
            if (sec) {
                sec = false;
                $("#dot").addClass("second");
            } else {
                sec = true;
                $("#dot").removeClass("second");
            }
            var t = setTimeout(function(){startTime(sec)},1000);
        }

        function checkTime(i) {
            if (i<10) {i = "0" + i};  // add zero in front of numbers < 10
            return i;
        }
    </script>

</head>
<body ng-app="front" onload="startTime()">


<div class="banggia" ng-controller="home" >
    <header ng-click=myStopFunction()>
        <div class="table"><a class="logo"><img src="<?php echo $base_url;?>/<?php echo $theme_path;?>/images/banggia/logo.png"></a> <span class="doji">tập đoàn vàng bạc đá quý doji</span></div>
        <h1>bảng giá vàng - nữ trang</h1>
        <div class="table">
            <div class="table-cell"><em class="time"> ngày</em><span id="day" class="color-red"></span></div>
            <div class="table-cell">Khu vực: {{info._area}}</div>
        </div>
        <div class="table">
            <div class="table-cell"><em class="time">giờ</em><span id="clock" class="color-red"></span></div>
            <div class="table-cell">Đơn vị: Nghìn VNĐ/Chỉ</div>
        </div>
    </header>
    <aside >
        <div class="table lable">
            <div class="table-cell class"><span>loại vàng</span></div>
            <div class="table-cell buy"><span>mua vào</span></div>
            <div class="table-cell send"><span>bán ra</span></div>
        </div>
        <div ng-repeat="bg in bgs">
            <div class="table" >
                <div class="table-cell class g">{{bg._Name}}</div>
                <div class="table-cell buy g">{{bg._Buy}}</div>
                <div class="table-cell send g">{{bg._Sell}}</div>
            </div>
        </div>
    </aside>
    <footer><span class="hotline">{{info._hotline}}</span><span class="website">Website: www.giavang.doji.vn</span></footer>
</div>
</body>
</html>