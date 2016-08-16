(function ($) {   
  $('#statistics-print .print').click(function(){
    $('#goldprice-report .sticky-header').hide();
    $('#goldprice-report').printElement();
    return false;  
  });
})(jQuery);  
