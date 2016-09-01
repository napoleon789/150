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

        // DOJI HN lẻ mua > DOJI buôn bán
        var dojiLeMua = $('#doji-add-user-get-form tbody tr:first-child td:nth-child(2) input').val();
        var TT_dojiLeMua = $('#doji-add-user-get-form tbody tr:first-child td:nth-child(2) input').attr("name_t");

        var dojiBuonBan = $('#doji-add-user-get-form tbody tr:nth-child(2) td:nth-child(3) input').val();
        var TT_dojiBuonBan = $('#doji-add-user-get-form tbody tr:nth-child(2) td:nth-child(3) input').attr("name_t");

        var dojiBuonMua = $('#doji-add-user-get-form tbody tr:nth-child(2) td:nth-child(2) input').val();
        var TT_dojiBuonMua = $('#doji-add-user-get-form tbody tr:nth-child(2) td:nth-child(2) input').attr("name_t");

        if (dojiLeMua > dojiBuonBan){
            error = 1
            $('#doji-add-user-get-form tbody tr:first-child td:nth-child(2) input').addClass('error');
            $('#doji-add-user-get-form tbody tr:nth-child(2) td:nth-child(3) input').addClass('error');
            $ul.append('<li class="error">'+ TT_dojiLeMua +' không được lớn hơn '+ TT_dojiBuonBan+ '</li>');
        }

        if (dojiLeMua > dojiBuonMua){
            error = 1
            $('#doji-add-user-get-form tbody tr:first-child td:nth-child(2) input').addClass('error');
            $('#doji-add-user-get-form tbody tr:nth-child(2) td:nth-child(2) input').addClass('error');
            $ul.append('<li class="error">'+ TT_dojiLeMua +' không được lớn hơn '+ TT_dojiBuonMua+ '</li>');
        }

        var NL_999Mua = $('#doji-add-user-get-form tbody tr:nth-child(4) td:nth-child(2) input').val();
        var TT_NL_999Mua = $('#doji-add-user-get-form tbody tr:nth-child(4) td:nth-child(2) input').attr("name_t");
        var NL_9999Ban = $('#doji-add-user-get-form tbody tr:nth-child(5) td:nth-child(3) input').val();
        var TT_NL_9999Ban = $('#doji-add-user-get-form tbody tr:nth-child(5) td:nth-child(3) input').attr("name_t");
        var NL_9999Mua = $('#doji-add-user-get-form tbody tr:nth-child(5) td:nth-child(2) input').val();
        var TT_NL_9999Mua = $('#doji-add-user-get-form tbody tr:nth-child(5) td:nth-child(2) input').attr("name_t");
        if (NL_999Mua > NL_9999Ban){
            error = 1;
            $('#doji-add-user-get-form tbody tr:nth-child(4) td:nth-child(2) input').addClass('error');
            $('#doji-add-user-get-form tbody tr:nth-child(5) td:nth-child(3) input').addClass('error');
            $ul.append('<li class="error">'+ TT_NL_999Mua +' không được lớn hơn '+ TT_NL_9999Ban+ '</li>');
        }
        if (NL_999Mua > NL_9999Mua){
            error = 1;
            $('#doji-add-user-get-form tbody tr:nth-child(4) td:nth-child(2) input').addClass('error');
            $('#doji-add-user-get-form tbody tr:nth-child(5) td:nth-child(2) input').addClass('error');
            $ul.append('<li class="error">'+ TT_NL_999Mua +' không được lớn hơn '+ TT_NL_9999Mua+ '</li>');
        }

        var NL_999Ban = $('#doji-add-user-get-form tbody tr:nth-child(4) td:nth-child(3) input').val();
        var TT_NL_999Ban = $('#doji-add-user-get-form tbody tr:nth-child(4) td:nth-child(3) input').attr("name_t");
        if (NL_999Ban > NL_9999Ban){
            error = 1;
            $('#doji-add-user-get-form tbody tr:nth-child(4) td:nth-child(3) input').addClass('error');
            $('#doji-add-user-get-form tbody tr:nth-child(5) td:nth-child(3) input').addClass('error');
            $ul.append('<li class="error">'+ TT_NL_999Ban +' không được lớn hơn '+ TT_NL_9999Ban+ '</li>');
        }


        if(error == 1) {
            $noitce_message.append($ul);
            $('#noitce-message').show();
        }
        else {
            $('#goldprice-form .form-submit').click();
        }
    });
});

