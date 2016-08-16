jQuery(document).ready(function() {
    $('#edit-submit-gold').click(function() {

        $("#noitce-message ul").html("");
        var $form = $(this).parents('form');
        var error = 0;
        var mes = '';
        var $messages = $('<div id="messages"><div class="messages error"> </div></div>');
        var $noitce_message = $('#noitce-message');
        var $ul = $('#noitce-message ul');
        $form.find('input.form-text').each(function(){
            Drupal.doji_gold_price.goldprice_form_set_value($form, $(this), 0, 0);

            var bien_do = $(this).attr('biendo');
            bien_do = parseInt(bien_do);
            var gia_cu = $(this).attr('oldvalue');
            gia_cu = parseInt(gia_cu.replace(',',''));
            var name = $(this).attr('name_t');

            var gia_tri = $(this).val();
            gia_tri = parseInt(gia_tri.replace(',',''));
            if(gia_tri > gia_cu + bien_do || gia_tri < gia_cu - bien_do) {
                error = 1;
                $(this).addClass('error');
                $ul.append('<li class="error">'+ name+ ' vượt quá biên độ </li>');
            }
         });
        $("#doji-add-user-get-form tbody tr:not(:last)").each(function() {
           var mua = $(this).find("td.mua input.form-text").val();
           mua = parseInt(mua.replace(',',''));
           var title_mua = $(this).find("td.mua input.form-text").attr("name_t");
           var ban = $(this).find("td.ban input").val();
           ban = parseInt(ban.replace(',',''));
           var title_ban = $(this).find("td.ban input.form-text").attr("name_t");

           if(mua > ban) {
               error = 1;
               $(this).find("input").addClass('error');
               $ul.append('<li class="error">'+ title_mua +' không được lớn hơn '+title_ban+ '</li>');
           }
        });

        if(error == 1) {
            $noitce_message.append($ul);
            $('#noitce-message').show();
        }
        else {
            $('#goldprice-form .form-submit').click();
        }
    });
});

