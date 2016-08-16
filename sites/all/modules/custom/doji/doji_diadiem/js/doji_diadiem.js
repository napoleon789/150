var map;
var markers = new Array();

window.map_init = function(long ,lat, info, name) {
    if(typeof(long)==='undefined') long = 105.855201;
    if(typeof(lat)==='undefined') lat = 21.015842;
    if(typeof(name)==='undefined') name = 'Trung tâm trang sức cao cấp DOJI - Ruby Plaza';
    if(typeof(info)==='undefined') info = '44 Lê Ngọc Hân, Hai Bà Trưng, Hà Nội - (04) 2220 6688';

     myLatlng = new google.maps.LatLng(lat, long);
    var mapOptions = {
        zoom: 16,
        center: myLatlng
    };
	map = new google.maps.Map(document.getElementById("map-canvas"), mapOptions);
    var contentString = '<table class="showmap"> <tr><td style="font-size: 14px;font-weight: bold">'+ name +'</td></tr><tr> <td style="font-size: 11px;">'+
        info
        +'</td><td>'+'</tr></table>';
    var infowindow = new google.maps.InfoWindow({
        content: contentString
    });

     marker = new google.maps.Marker({
        position: myLatlng,
        map: map,
        title: name
    });
    infowindow.open(map,marker);
    google.maps.event.addListener(marker, 'click', function() {
        infowindow.open(map,marker);
    });
}

map_init();

function showAllPlaces() {
	i = 0;
	var bounds = new google.maps.LatLngBounds ();
	$('.diadiem_cuahang').each(function(index) {
		loc = $(this).find('.diadiem_addr');
		loc = $(loc).text().split('-');
		var latlng = new google.maps.LatLng(loc[0],loc[1]);
		bounds.extend(latlng);

		ten = $(this).find('.diadiem_ten');

		markers[i++] = new google.maps.Marker({
		      position: latlng,
		      map: map,
		      title: ten.text()
		  });

		ten.click(function() {
			loc = $(this).parent().find('.diadiem_addr');
			loc = $(loc).text().split('-');
			map.setCenter(new google.maps.LatLng(loc[0],loc[1]));
		});

	});

	map.setCenter(bounds.getCenter());
	map.fitBounds(bounds);
}



$(document).ready(function() {

	//showAllPlaces();
   $("#diadiem-area").change(function() {
       var id = $("#diadiem-area").val();
       $.ajax({ url: '../doji/diadiem/callback'+'?tid='+id,
           dataType: 'JSON',
           success: function(output) {
               var result = Drupal.parseJson(output);
               $('#contentaj').html(result.data);
               $(".insert1").click();
           }
       });

   });



});