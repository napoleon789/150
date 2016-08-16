// generic JS fixes

// various JavaScript object.
var doji_gold = {};

// jump to the value in a select drop down
doji_gold.go = function(e) {
  var destination = e.options[e.selectedIndex].value;
  if (destination && destination != 0) location.href = destination;
};


  $(window).load(function(){
    jQuery(document).ready(function ($) {
        if(navigator.userAgent.match(/(iPhone|iPod|iPad)/i)) {
      $('[data-popup-target]').click(function () {
        $('html').addClass('overlay');
        var activePopup = $(this).attr('data-popup-target');
        $(activePopup).addClass('visible');

      });
        $('[data-popup-target]').click();
      $(document).keyup(function (e) {
        if (e.keyCode == 27 && $('html').hasClass('overlay')) {
          clearPopup();
        }
      });

      $('.popup-exit').click(function () {
        clearPopup();

      });

      $('.popup-overlay').click(function () {
        clearPopup();
          $('.popup-overlay').css("width",'0');
      });

      function clearPopup() {
        $('.popup.visible').addClass('transitioning').removeClass('visible');
        $('html').removeClass('overlay');

        setTimeout(function () {
          $('.popup').removeClass('transitioning');
        }, 200);
      }
        }
    });
  });//]]>


