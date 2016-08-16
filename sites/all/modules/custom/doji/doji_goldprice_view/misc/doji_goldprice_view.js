(function ($) {   
Drupal.behaviors.doji_goldprice = function(context) {
  $('.goldprice_status_save', context).each(function() {
    $(this).click(function(){
        var $this = $(this);     
        $this.hide();
        $this.after('<span>' + Drupal.t("Đang lưu dữ liệu") + '<span class="views-throbbing">&nbsp</span></span>');              
        $.get($this.attr('href'), null,
          function(data){  
            $this.text(data.textshow);
            $this.next('span').remove();
            $this.fadeIn();
          }
        , "json");                            
      return false;  
    });                       
  });       
}; 

})(jQuery);  
