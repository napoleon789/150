(function ($) {
    Drupal.doji_gold_price = Drupal.doji_gold_price || {}
    Drupal.doji_gold_price.suggest = Drupal.doji_gold_price.suggest || {}

    //Return number
    Drupal.doji_gold_price.toNumber = function($input) {
        var number = $input.val();
        if ( typeof number !== "undefined" && number)  {
            if (number.length > 0 && Drupal.settings.format_number.thousands_sep.length > 0) {
                var thsep = Drupal.settings.format_number.thousands_sep;
                if (thsep == '\u00A0') {
                    thsep += ' ';
                }
                number = number.replace(new RegExp('['+ thsep +']', 'g'), '');
            }
        }
        number = parseFloat(number);

        if (isNaN(number)) {
            number = 0;
        }
        return number;
    };

    //Set value into Goldprice Form
    Drupal.doji_gold_price.goldprice_form_set_value = function($form, $input, $click_spread, $i) {
        var id = $input.attr('id').replace('edit-', 'edit-field-') + '-0-value';
        if ($input.parents('.form-ngunggiaodich:eq(0)').length) {
            return false;
        }
        if ($('#' + id).length > 0) {
            $('#' + id).val(Drupal.doji_gold_price.toNumber($input));
            Drupal.goldpriceCalculator.calculator($('#' + id));
        }
    }

    //Caculator function
    Drupal.doji_gold_price.calculator = function($form, $input, $click_spread, $i) {
        var value = Drupal.doji_gold_price.toNumber($input);

        value += $click_spread*$i;
        $input.val(value);
        Drupal.numericElement.formatElement($input, -1);
//    Drupal.doji_gold_price.goldprice_form_set_value($form, $input, $click_spread, $i);
        //Drupal.doji_gold_price.suggest.rule_1($form, $input, $click_spread, $i);
    }

    //Suggest rule 1 function
    Drupal.doji_gold_price.suggest.rule_1 = function($form, $input, $click_spread, $i) {
        if ($input.hasClass('hn-pushall')) {
            $('input.form-text.hn', $form).each(function(){
                Drupal.doji_gold_price.calculator($form, $(this), $click_spread, $i);
            });
        }
        if ($input.hasClass('sg-pushall')) {
            $('input.form-text.sg', $form).each(function(){
                Drupal.doji_gold_price.calculator($form, $(this), $click_spread, $i);
            });
        }
        if ($input.hasClass('dn-pushall')) {
            $('input.form-text.dn', $form).each(function(){
                Drupal.doji_gold_price.calculator($form, $(this), $click_spread, $i);
            });
        }
        if ($input.hasClass('phi-pushall')) {
            $('input.form-text.phi', $form).each(function(){
                Drupal.doji_gold_price.calculator($form, $(this), $click_spread, $i);
            });
        }
        if ($input.hasClass('nl999-pushall')) {
            $('input.form-text.nl999', $form).each(function(){
                Drupal.doji_gold_price.calculator($form, $(this), $click_spread, $i);
            });
        }
        if ($input.hasClass('nl99-pushall')) {
            $('input.form-text.nl99', $form).each(function(){
                Drupal.doji_gold_price.calculator($form, $(this), $click_spread, $i);
            });
        }
    }

    //Suggest rule 2 function
    Drupal.doji_gold_price.suggest.rule_2 = function($sjc_le_muavao, $sjc_le_banra, $sjc_buon_muavao, $sjc_buon_banra) {
        //Drupal.doji_gold_price.goldprice_form_set_value($form, $input, $click_spread, $i);
        var $res = new Array();
        var $sjc_le_muavao_value = Drupal.doji_gold_price.toNumber($sjc_le_muavao);
        var $sjc_le_banra_value = Drupal.doji_gold_price.toNumber($sjc_le_banra);
        var $sjc_buon_muavao_value = Drupal.doji_gold_price.toNumber($sjc_buon_muavao);
        var $sjc_buon_banra_value = Drupal.doji_gold_price.toNumber($sjc_buon_banra);
        var $messages = $('<div id="messages"><div class="messages error"> </div></div>');
        var $noitce_message = $('#noitce-message');
        var $ul = $('#noitce-message ul');
        $('#giavangtrongnuoc #noitce-message ul li:not(".first")').remove();
        $res['warning'] = 0;
        $res['error'] = 0;

        if ($sjc_le_banra_value < $sjc_le_muavao_value) {
            $res['error'] += 1;
            $sjc_le_muavao.addClass('error');
            $sjc_le_banra.addClass('error');
            $ul.append('<li class="error">DOJI HN mua lẻ > DOJI HN bán lẻ</li>');
        }
        else if ($sjc_le_muavao_value > 0 && $sjc_le_banra_value > 0 && ((($sjc_le_banra_value - $sjc_le_muavao_value)/$sjc_le_banra_value) > 0.01)) {
            $res['warning'] += 1;
            $ul.append('<li class="warning">DOJI HN lẻ có biên độ thay đổi quá 1%</li>');
        }
        else {
            $sjc_le_muavao.removeClass('error');
            $sjc_le_banra.removeClass('error');
        }

        if ($sjc_buon_banra_value < $sjc_buon_muavao_value) {
            $res['error'] += 1;
            $sjc_buon_banra.addClass('error');
            $sjc_buon_muavao.addClass('error');
            $ul.append('<li class="error">DOJI HN mua buôn > DOJI HN bán buôn</li>');
        }
        else if ($sjc_buon_muavao_value > 0 && $sjc_buon_banra_value > 0 && ((($sjc_buon_banra_value - $sjc_buon_muavao_value)/$sjc_buon_muavao_value) > 0.01)) {
            $res['warning'] += 1;
            $ul.append('<li class="warning">DOJI HN buôn có biên độ thay đổi quá 1%</li>');
        }
        else {
            $sjc_buon_banra.removeClass('error');
            $sjc_buon_muavao.removeClass('error');
        }

        if ($sjc_le_muavao_value > $sjc_buon_muavao_value) {
            $res['error'] += 1;
            $sjc_buon_muavao.addClass('error');
            $sjc_le_muavao.removeClass('error');
            $ul.append('<li class="error">DOJI HN mua lẻ > DOJI HN mua buôn</li>');
        }
        else if (!$res['error']) {
            $sjc_buon_muavao.removeClass('error');
            $sjc_le_muavao.removeClass('error');
        }

        if ($sjc_le_banra_value > $sjc_buon_banra_value) {
            $res['error'] += 1;
            $sjc_le_banra.addClass('error');
            $sjc_buon_banra.removeClass('error');
            $ul.append('<li class="error">DOJI HN bán buôn < DOJI HN bán lẻ</li>');
        }
        else if (!$res['error']) {
            $sjc_le_banra.removeClass('error');
            $sjc_buon_banra.removeClass('error');
        }

        if ($res['error'] > 0 || $res['warning'] > 0 ) {
            $noitce_message.append($ul);
        }
        else {
            // $noitce_message.html();
        }
        return $res;
    }

    //Suggest rule 3 function
    Drupal.doji_gold_price.suggest.rule_3 = function($sjc_le_muavao, $sjc_le_banra, $sjc_buon_muavao, $sjc_buon_banra,$dk_sg_le_mua,$dk_sg_le_ban,$dk_sg_buon_mua,$dk_sg_buon_ban) {
        //Drupal.doji_gold_price.goldprice_form_set_value($form, $input, $click_spread, $i);
        var $res = new Array();

        var $sjc_le_muavao_value = Drupal.doji_gold_price.toNumber($sjc_le_muavao);
        var $sjc_le_banra_value = Drupal.doji_gold_price.toNumber($sjc_le_banra);
        var $sjc_buon_muavao_value = Drupal.doji_gold_price.toNumber($sjc_buon_muavao);
        var $sjc_buon_banra_value = Drupal.doji_gold_price.toNumber($sjc_buon_banra);

        var $dk_sg_le_mua_value = parseInt($dk_sg_le_mua);
        var $dk_sg_le_ban_value = parseInt($dk_sg_le_ban);
        var $dk_sg_buon_mua_value =parseInt ($dk_sg_buon_mua);
        var $dk_sg_buon_ban_value = parseInt($dk_sg_buon_ban);

        var $gia_cu_sg_le_mua = parseInt($("#edit-sjc-sg-le-muavao").attr("hn"));
        var $gia_cu_sg_le_ban = parseInt($("#edit-sjc-sg-le-banra").attr("hn"));
        var $gia_cu_sg_buon_mua = parseInt($("#edit-sjc-sg-buon-muavao").attr("hn"));
        var $gia_cu_sg_buon_ban = parseInt($("#edit-sjc-sg-buon-banra").attr("hn"));

        var $messages = $('<div id="messages"><div class="messages error"> </div></div>');
        var $noitce_message = $('#noitce-message');
        var $ul = $('#noitce-message ul');
        $res['warning'] = 0;
        $res['error'] = 0;
        if($sjc_buon_banra_value > $gia_cu_sg_buon_ban + $dk_sg_buon_ban_value || $sjc_buon_banra_value< $gia_cu_sg_buon_ban - $dk_sg_buon_ban_value ) {
            $res['error'] += 1;
            $sjc_le_muavao.addClass('error');
            $sjc_le_banra.addClass('error');
            $ul.append('<li class="error">DOJI HCM bán buôn thay đổi ngoài biên độ cho phép</li>');
        }
        if($sjc_buon_muavao_value > $gia_cu_sg_buon_mua + $dk_sg_buon_mua_value || $gia_cu_sg_buon_mua< $gia_cu_sg_le_mua - $dk_sg_buon_mua_value ) {
            $res['error'] += 1;
            $sjc_le_muavao.addClass('error');
            $sjc_le_banra.addClass('error');
            $ul.append('<li class="error">DOJI HCM mua buôn thay đổi ngoài biên độ cho phép</li>');
        }
        if($sjc_le_muavao_value > $gia_cu_sg_le_mua + $dk_sg_le_mua_value || $sjc_le_muavao_value< $gia_cu_sg_le_mua - $dk_sg_le_mua_value ) {
            $res['error'] += 1;
            $sjc_le_muavao.addClass('error');
            $sjc_le_banra.addClass('error');
            $ul.append('<li class="error">DOJI HCM mua lẻ thay đổi ngoài biên độ cho phép</li>');
        }
        if($sjc_le_banra_value > $gia_cu_sg_le_ban + $dk_sg_le_ban_value || $sjc_le_banra_value< $gia_cu_sg_le_ban - $dk_sg_le_ban_value ) {
            $res['error'] += 1;
            $sjc_le_muavao.addClass('error');
            $sjc_le_banra.addClass('error');
            $ul.append('<li class="error">DOJI HCM bán lẻ thay đổi ngoài biên độ cho phép</li>');
        }
        if ($sjc_le_banra_value < $sjc_le_muavao_value) {
            $res['error'] += 1;
            $sjc_le_muavao.addClass('error');
            $sjc_le_banra.addClass('error');
            $ul.append('<li class="error">DOJI HCM mua lẻ > DOJI HCM bán lẻ</li>');
        }
        else if ($sjc_le_muavao_value > 0 && $sjc_le_banra_value > 0 && ((($sjc_le_banra_value - $sjc_le_muavao_value)/$sjc_le_banra_value) > 0.01)) {
            $res['warning'] += 1;
            $ul.append('<li class="warning">DOJI HCM lẻ có biên độ thay đổi quá 1%</li>');
        }
        else {
            $sjc_le_muavao.removeClass('error');
            $sjc_le_banra.removeClass('error');
        }

        if ($sjc_buon_banra_value < $sjc_buon_muavao_value) {
            $res['error'] += 1;
            $sjc_buon_banra.addClass('error');
            $sjc_buon_muavao.addClass('error');
            $ul.append('<li class="error">DOJI HCM mua buôn > DOJI HCM bán buôn</li>');
        }
        else if ($sjc_buon_muavao_value > 0 && $sjc_buon_banra_value > 0 && ((($sjc_buon_banra_value - $sjc_buon_muavao_value)/$sjc_buon_muavao_value) > 0.01)) {
            $res['warning'] += 1;
            $ul.append('<li class="warning">DOJI HCM buôn có biên độ thay đổi quá 1%</li>');
        }
        else {
            $sjc_buon_banra.removeClass('error');
            $sjc_buon_muavao.removeClass('error');
        }

        if ($sjc_le_muavao_value > $sjc_buon_muavao_value) {
            $res['error'] += 1;
            $sjc_buon_muavao.addClass('error');
            $sjc_le_muavao.removeClass('error');
            $ul.append('<li class="error">DOJI HCM mua lẻ > DOJI HCM mua buôn</li>');
        }
        else if (!$res['error']) {
            $sjc_buon_muavao.removeClass('error');
            $sjc_le_muavao.removeClass('error');
        }

        if ($sjc_le_banra_value > $sjc_buon_banra_value) {
            $res['error'] += 1;
            $sjc_le_banra.addClass('error');
            $sjc_buon_banra.removeClass('error');
            $ul.append('<li class="error">DOJI HCM bán buôn < DOJI HCM bán lẻ</li>');
        }
        else if (!$res['error']) {
            $sjc_le_banra.removeClass('error');
            $sjc_buon_banra.removeClass('error');
        }

        if ($res['error'] > 0 || $res['warning'] > 0 ) {
            $noitce_message.append($ul);
        }
        return $res;
    }

    /******************************************
     * Kiem tra cho Vang Phi SJC (99.99)
     * Mua <= DOJI HN mua lẻ
     * Bán <= DOJI HN bán lẻ
     * Mua <= Bán
     ******************************************/
    Drupal.doji_gold_price.suggest.rule_4 = function($sjc_hn_le_muavao, $sjc_hn_le_banra, $phi_sjc_9999_muavao, $phi_sjc_9999_banra) {
        var $res = new Array();
        var $sjc_hn_le_muavao_value = Drupal.doji_gold_price.toNumber($sjc_hn_le_muavao);
        var $sjc_hn_le_banra_value = Drupal.doji_gold_price.toNumber($sjc_hn_le_banra);
        var $phi_sjc_9999_muavao_value = Drupal.doji_gold_price.toNumber($phi_sjc_9999_muavao);
        var $phi_sjc_9999_banra_value = Drupal.doji_gold_price.toNumber($phi_sjc_9999_banra);
        var $messages = $('<div id="messages"><div class="messages error"> </div></div>');
        var $noitce_message = $('#noitce-message');
        var $ul = $('#noitce-message ul');
        $res['warning'] = 0;
        $res['error'] = 0;

        if ($phi_sjc_9999_banra_value < $phi_sjc_9999_muavao_value) {
            $res['error'] += 1;
            $phi_sjc_9999_muavao.addClass('error');
            $phi_sjc_9999_banra.addClass('error');
            $ul.append('<li class="error">Phi SJC (99.99) mua > Phi SJC (99.99) bán</li>');
        }
        else if ($phi_sjc_9999_muavao_value > 0 && $phi_sjc_9999_banra_value > 0 && ((($phi_sjc_9999_banra_value - $phi_sjc_9999_muavao_value)/$phi_sjc_9999_banra_value) > 0.01)) {
            $res['warning'] += 1;
            $ul.append('<li class="warning">Phi SJC (99.99) có biên độ thay đổi quá 1%</li>');
        }
        else {
            $phi_sjc_9999_muavao.removeClass('error');
            $phi_sjc_9999_banra.removeClass('error');
        }

        if ($res['error'] > 0 || $res['warning'] > 0 ) {
            $noitce_message.append($ul);
        }
        return $res;
    }

    /******************************************
     * Kiem tra cho Vàng Nguyên liệu (999.9)
     * Mua <= Vàng phi SJC mua x 999.9/999.99
     * Bán <= Vàng phi SJC bán x 999.9/999.99
     * Mua <= Bán
     ******************************************/
    Drupal.doji_gold_price.suggest.rule_5 = function($nguyen_lieu_999_muavao, $nguyen_lieu_999_banra, $phi_sjc_9999_muavao, $phi_sjc_9999_banra) {
        var $res = new Array();
        var $nguyen_lieu_999_muavao_value = Drupal.doji_gold_price.toNumber($nguyen_lieu_999_muavao);
        var $nguyen_lieu_999_banra_value = Drupal.doji_gold_price.toNumber($nguyen_lieu_999_banra);
        var $phi_sjc_9999_muavao_value = Drupal.doji_gold_price.toNumber($phi_sjc_9999_muavao);
        var $phi_sjc_9999_banra_value = Drupal.doji_gold_price.toNumber($phi_sjc_9999_banra);
        var $messages = $('<div id="messages"><div class="messages error"> </div></div>');
        var $noitce_message = $('#noitce-message');
        var $ul = $('#noitce-message ul');
        $res['warning'] = 0;
        $res['error'] = 0;

        if ($nguyen_lieu_999_banra_value < $nguyen_lieu_999_muavao_value) {
            $res['error'] += 1;
            $nguyen_lieu_999_muavao.addClass('error');
            $nguyen_lieu_999_banra.addClass('error');
            $ul.append('<li class="error">Nguyên liệu 999.9 mua > Nguyên liệu 999.9 bán</li>');
        }
        else if ($nguyen_lieu_999_muavao_value > 0 && $nguyen_lieu_999_banra_value > 0 && ((($nguyen_lieu_999_banra_value - $nguyen_lieu_999_muavao_value)/$nguyen_lieu_999_banra_value) > 0.01)) {
            $res['warning'] += 1;
            $ul.append('<li class="warning">Nguyên liệu 999.9 có biên độ thay đổi quá 1%</li>');
        }
        else {
            $nguyen_lieu_999_muavao.removeClass('error');
            $nguyen_lieu_999_banra.removeClass('error');
        }

        if ($res['error'] > 0 || $res['warning'] > 0 ) {
            $noitce_message.append($ul);
        }

        return $res;
    }

    /******************************************
     * Kiem tra cho Vàng Nguyên liệu (99.9)
     * Mua <= Vàng Phi SJC mua x 99.9/99.99
     * Bán <= Vàng phi SJC bán x 99.9/99.99
     * Mua <= Bán
     ******************************************/
    Drupal.doji_gold_price.suggest.rule_6 = function($nguyen_lieu_99_muavao, $nguyen_lieu_99_banra, $phi_sjc_9999_muavao, $phi_sjc_9999_banra) {
        var $res = new Array();
        var $nguyen_lieu_99_muavao_value = Drupal.doji_gold_price.toNumber($nguyen_lieu_99_muavao);
        var $nguyen_lieu_99_banra_value = Drupal.doji_gold_price.toNumber($nguyen_lieu_99_banra);
        var $phi_sjc_9999_muavao_value = Drupal.doji_gold_price.toNumber($phi_sjc_9999_muavao);
        var $phi_sjc_9999_banra_value = Drupal.doji_gold_price.toNumber($phi_sjc_9999_banra);
        var $messages = $('<div id="messages"><div class="messages error"> </div></div>');
        var $noitce_message = $('#noitce-message');
        var $ul = $('#noitce-message ul');
        $res['warning'] = 0;
        $res['error'] = 0;

        if ($nguyen_lieu_99_banra_value < $nguyen_lieu_99_muavao_value) {
            $res['error'] += 1;
            $nguyen_lieu_99_banra.addClass('error');
            $nguyen_lieu_99_muavao.addClass('error');
            $ul.append('<li class="error">Nguyên liệu 99.9 mua > Nguyên liệu 99.9 bán </li>');
        }
        else if ($nguyen_lieu_99_muavao_value > 0 && $nguyen_lieu_99_banra_value > 0 && ((($nguyen_lieu_99_banra_value - $nguyen_lieu_99_muavao_value)/$nguyen_lieu_99_banra_value) > 0.01)) {
            $res['warning'] += 1;
            $ul.append('<li class="warning">Nguyên liệu 99.9 có biên độ thay đổi quá 1%</li>');
        }
        else {
            $nguyen_lieu_99_banra.removeClass('error');
            $nguyen_lieu_99_muavao.removeClass('error');
        }

        if ($res['error'] > 0 || $res['warning'] > 0 ) {
            $noitce_message.append($ul);
        }
        return $res;
    }


    //Suggest rule 7 function
    Drupal.doji_gold_price.suggest.rule_7 = function($form) {
        //Drupal.doji_gold_price.goldprice_form_set_value($form, $input, $click_spread, $i);
        var $res = new Array();

        var $doji_muale = Drupal.doji_gold_price.toNumber($("#edit-doji6-muavao").val());
        var $doji_banle = Drupal.doji_gold_price.toNumber($("#edit-doji6-banra").val());
        var $doji_muabuon = Drupal.doji_gold_price.toNumber($("#edit-doji-7-muavao").val());
        var $doji_banbuon = Drupal.doji_gold_price.toNumber($("#edit-doji-7-banra").val());
        var $nlieu4_muavao = Drupal.doji_gold_price.toNumber($("#edit-nguye6-muavao").val());
        var $nlieu4_banra = Drupal.doji_gold_price.toNumber($("#edit-nguye6-banra").val());
        var $nlieu3_muavao = Drupal.doji_gold_price.toNumber($("#edit-nguy2-muavao").val());
        var $nlieu3_banra = Drupal.doji_gold_price.toNumber($("#edit-nguy2-banra").val());

        var $bdo_muale = parseInt($("#edit-doji6-muavao").attr("biendo"));
        var $bdo_banle = parseInt($("#edit-doji6-banra").attr("biendo"));
        var $bdo_muabuon = parseInt($("#edit-doji-7-muavao").attr("biendo"));
        var $bdo_banbuon = parseInt($("#edit-doji-7-banra").attr("biendo"));
        var $bdo_nlieu4_mua = parseInt($("#edit-nguye6-muavao").attr("biendo"));
        var $bdo_nlieu4_ban = parseInt($("#edit-nguye6-banra").attr("biendo"));
        var $bdo_nlieud3_mua = parseInt($("#edit-nguy2-muavao").attr("biendo"));
        var $bdo_nlieu3_ban = parseInt($("#edit-nguy2-banra").attr("biendo"));

        var $dn_muale = parseInt($("#edit-doji6-muavao").attr("hn"));
        var $dn_banle = parseInt($("#edit-doji6-banra").attr("hn"));
        var $dn_muabuon = parseInt($("#edit-doji-7-muavao").attr("hn"));
        var $dn_banbuon = parseInt($("#edit-doji-7-banra").attr("hn"));
        var $nlieu4_mua = parseInt($("#edit-nguye6-muavao").attr("hn"));
        var $nlieu4_ban = parseInt($("#edit-nguye6-banra").attr("hn"));
        var $nlieud3_mua = parseInt($("#edit-nguy2-muavao").attr("hn"));
        var $nlieu3_ban = parseInt($("#edit-nguy2-banra").attr("hn"));

        var $messages = $('<div id="messages"><div class="messages error"> </div></div>');
        var $noitce_message = $('#noitce-message');
        var $ul = $('#noitce-message ul');
        $res['warning'] = 0;
        $res['error'] = 0;
        if($doji_muale > $bdo_muale + $dn_muale || $doji_muale< $dn_muale - $bdo_muale ) {
            $res['error'] += 1;
            $('#edit-doji6-muavao').addClass('error');
            $ul.append('<li class="error">DOJI DN mua lẻ thay đổi ngoài biên độ cho phép</li>');
        }
        if($doji_banle > $doji_banle + $bdo_banle || $doji_banle< $doji_banle - $bdo_banle ) {
            $res['error'] += 1;
            $('#edit-doji6-banra').addClass('error');
            $ul.append('<li class="error">DOJI DN bán lẻ thay đổi ngoài biên độ cho phép</li>');
        }
        if($doji_muabuon > $bdo_muabuon + $dn_muabuon || $dn_muabuon < $dn_muabuon - $bdo_muabuon ) {
            $res['error'] += 1;
            $('#edit-doji-7-muavao').addClass('error');
            $ul.append('<li class="error">DOJI DN mua buôn thay đổi ngoài biên độ cho phép</li>');
        }
        if($doji_banbuon > $bdo_banbuon + $dn_banbuon || $doji_banbuon< $dn_banbuon - $bdo_banbuon ) {
            $res['error'] += 1;
            $('#edit-doji-7-banra').addClass('error');
            $ul.append('<li class="error">DOJI DN bán buôn thay đổi ngoài biên độ cho phép</li>');
        }
        if($nlieu4_muavao > $bdo_nlieu4_mua + $nlieu4_mua || $nlieu4_muavao< $nlieu4_mua - $bdo_nlieu4_mua ) {
            $res['error'] += 1;
            $('#edit-nguye6-muavao').addClass('error');
            $ul.append('<li class="error">Nguyên liệu 9999 mua thay đổi ngoài biên độ cho phép</li>');
        }
        if($nlieu4_banra > $bdo_nlieu4_ban + $nlieu4_ban || $nlieu4_banra< $nlieu4_ban - $bdo_nlieu4_ban ) {
            $res['error'] += 1;
            $('#edit-nguye6-banra').addClass('error');
            $ul.append('<li class="error">Nguyên liệu 9999 bán ra thay đổi ngoài biên độ cho phép</li>');
        }
        if($nlieu3_muavao > $nlieud3_mua + $bdo_nlieud3_mua || $nlieu3_muavao< $nlieud3_mua - $bdo_nlieud3_mua ) {
            $res['error'] += 1;
            $('#edit-nguye6-muavao').addClass('error');
            $ul.append('<li class="error">Nguyên liệu 999 mua thay đổi ngoài biên độ cho phép</li>');
        }
        if($nlieu3_banra > $bdo_nlieu3_ban + $nlieu3_ban || $nlieu3_banra< $nlieu3_ban - $bdo_nlieu3_ban ) {
            $res['error'] += 1;
            $('#edit-nguye6-muavao').addClass('error');
            $ul.append('<li class="error">Nguyên liệu 999 bán ra thay đổi ngoài biên độ cho phép</li>');
        }
        if ($sjc_le_banra_value < $sjc_le_muavao_value) {
            $res['error'] += 1;
            $sjc_le_muavao.addClass('error');
            $sjc_le_banra.addClass('error');
            $ul.append('<li class="error">DOJI DN mua lẻ > DOJI DN bán lẻ</li>');
        }
        else if ($sjc_le_muavao_value > 0 && $sjc_le_banra_value > 0 && ((($sjc_le_banra_value - $sjc_le_muavao_value)/$sjc_le_banra_value) > 0.01)) {
            $res['warning'] += 1;
            $ul.append('<li class="warning">DOJI DN lẻ có biên độ thay đổi quá 1%</li>');
        }
        else {
            $sjc_le_muavao.removeClass('error');
            $sjc_le_banra.removeClass('error');
        }

        if ($sjc_buon_banra_value < $sjc_buon_muavao_value) {
            $res['error'] += 1;
            $sjc_buon_banra.addClass('error');
            $sjc_buon_muavao.addClass('error');
            $ul.append('<li class="error">DOJI DN mua buôn > DOJI DN bán buôn</li>');
        }
        else if ($sjc_buon_muavao_value > 0 && $sjc_buon_banra_value > 0 && ((($sjc_buon_banra_value - $sjc_buon_muavao_value)/$sjc_buon_muavao_value) > 0.01)) {
            $res['warning'] += 1;
            $ul.append('<li class="warning">DOJI DN buôn có biên độ thay đổi quá 1%</li>');
        }
        else {
            $sjc_buon_banra.removeClass('error');
            $sjc_buon_muavao.removeClass('error');
        }

        if ($sjc_le_muavao_value < $sjc_buon_muavao_value) {
            $res['error'] += 1;
            $sjc_buon_muavao.addClass('error');
            $sjc_le_muavao.removeClass('error');
            $ul.append('<li class="error">DOJI DN mua lẻ < DOJI DN mua buôn</li>');
        }
        else if (!$res['error']) {
            $sjc_buon_muavao.removeClass('error');
            $sjc_le_muavao.removeClass('error');
        }

        if ($sjc_le_banra_value > $sjc_buon_banra_value) {
            $res['error'] += 1;
            $sjc_le_banra.addClass('error');
            $sjc_buon_banra.removeClass('error');
            $ul.append('<li class="error">DOJI DN bán buôn < DOJI DN bán lẻ</li>');
        }
        else if (!$res['error']) {
            $sjc_le_banra.removeClass('error');
            $sjc_buon_banra.removeClass('error');
        }

        if ($res['error'] > 0 || $res['warning'] > 0 ) {
            $noitce_message.append($ul);
        }
        return $res;
    }

    Drupal.doji_gold_price.suggest.rule_73 = function($form){
        var $res = new Array();
        var $messages = $('<div id="messages"><div class="messages error"> </div></div>');
        var $noitce_message = $('#noitce-message');
        var $ul = $('#noitce-message ul');
        $res['error'] = 0;
        var $tr = $form.find("tbody tr");
        $tr.each(function(){
            var $mua = $(this).find("td:nth-child(2) input");
            var $ban = $(this).find("td:nth-child(3) input");
            if($mua.val() >= $ban.val()){
                $res['error'] = 1;
                $mua.addClass('error');
                var name = $mua.attr('namet');
                $ul.append('<li class="error">'+name+' không được lớn hơn giá bán ra. ' + '</li>');
            };
        });
        var $999mua = $form.find('tbody tr:nth-child(3) td:nth-child(2) input');
        var $999ban = $form.find('tbody tr:nth-child(3) td:nth-child(3) input');
        var $9999mua = $form.find('tbody tr:nth-child(2) td:nth-child(2) input');
        var $9999ban = $form.find('tbody tr:nth-child(2) td:nth-child(3) input');
        // check nguyen lieu 999
        if($999mua.val() >= $9999mua.val()){
            $res['error'] = 1;
            $999mua.addClass('error');
            var name = $999mua.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá nguyên liệu 9999 mua vào. ' + '</li>');
        };
        if($999mua.val() >= $9999ban.val()){
            $res['error'] = 1;
            $999mua.addClass('error');
            var name = $999mua.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá nguyên liệu 9999 bán ra. ' + '</li>');
        };

        if($999ban.val() >= $9999ban.val()){
            $res['error'] = 1;
            $999ban.addClass('error');
            var name = $999ban.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá nguyên liệu 9999 bán ra. ' + '</li>');
        };
        return $res;
    };

    Drupal.doji_gold_price.suggest.rule_72 = function($form) {
        var $res = new Array();
        var $messages = $('<div id="messages"><div class="messages error"> </div></div>');
        var $noitce_message = $('#noitce-message');
        var $ul = $('#noitce-message ul');
        $res['error'] = 0;
        var $muale = $form.find("tbody tr:first td:nth-child(2) input");
        var $banle = $form.find("tbody tr:first td:nth-child(3) input");
        var $muabuon = $form.find("tbody tr:nth-child(2) td:nth-child(2) input");
        var $banbuon = $form.find("tbody tr:nth-child(2) td:nth-child(3) input");
        // check mua ban
        if ($muale.val() >= $banle.val()){
            $res['error'] = 1;
            $muale.addClass('error');
            var name = $muale.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng lẻ giá bán ra. ' + '</li>');
        }
        if ($muale.val() >= $banbuon.val()){
            $res['error'] = 1;
            $muale.addClass('error');
            var name = $muale.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng buôn bán ra. ' + '</li>');
        }

        if ($muale.val() > $muabuon.val()){
            $res['error'] = 1;
            $muale.addClass('error');
            var name = $muale.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn giá buôn mua vào. ' + '</li>');
        };
        // check gia buon
        if ($muabuon.val() >= $banbuon.val()){
            $res['error'] = 1;
            $muabuon.addClass('error');
            var name = $muabuon.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá buôn bán ra. ' + '</li>');
        };

        if ($muabuon.val() >= $banle.val()){
            $res['error'] = 1;
            $muabuon.addClass('error');
            var name = $muabuon.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá lẻ bán ra. ' + '</li>');
        };
//
//        if ($banle.val() < $banbuon.val()){
//            $res['error'] = 1;
//            $banle.addClass('error');
//            var name = $banle.attr('namet');
//            $ul.append('<li class="error">'+name+' không được lớn hơn giá bán buôn. ' + '</li>');
//        };

        return $res;
    };


    //suggest rule 8 custom mr.vatri
    Drupal.doji_gold_price.suggest.rule_71 = function($form) {
        var $input = $form.find('input[type ="text"]');
        var $res = new Array();
        var $messages = $('<div id="messages"><div class="messages error"> </div></div>');
        var $noitce_message = $('#noitce-message');
        var $ul = $('#noitce-message ul');
        $res['error'] = 0;
        var $ipmuale = $form.find('tbody tr:first td:nth-child(2) input');
        var $ipbanle = $form.find('tbody tr:first td:nth-child(3) input');
        var $ipmuabuon = $form.find('tbody tr:nth-child(2) td:nth-child(2) input');
        var $ipbanbuon = $form.find('tbody tr:nth-child(2) td:nth-child(3) input');
        // check le mua
        if ($ipmuale.val() >= $ipbanle.val()){
            $res['error'] += 1;
            $ipmuale.addClass('error');
            var name = $ipmuale.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá bán ra. ' + '</li>');
        };
        if ($ipmuale.val() >= $ipbanbuon.val()){
            $res['error'] += 1;
            $ipmuale.addClass('error');
            var name = $ipmuale.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá buôn bán ra. ' + '</li>');
        };

        if ($ipmuale.val() > $ipmuabuon.val()){
            $res['error'] += 1;
            $ipmuale.addClass('error');
            var name = $ipmuale.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn giá buôn mua vào. ' + '</li>');
        };

        // check buon mua
        if ($ipmuabuon.val() >= $ipbanbuon.val()){
            $res['error'] += 1;
            $ipbanle.addClass('error');
            var name = $ipbanle.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá buôn bán ra. ' + '</li>');
        };
        if ($ipmuabuon.val() >= $ipbanle.val()){
            $res['error'] += 1;
            $ipbanle.addClass('error');
            var name = $ipbanle.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá lẻ bán ra. ' + '</li>');
        };


        var $ipmuanguyenlieu9999 = $form.find('tbody tr:nth-child(3) td:nth-child(2) input');
        var $ipbannguyenlieu9999 = $form.find('tbody tr:nth-child(3) td:nth-child(3) input');
        var $ipmuanguyenlieu999 = $form.find('tbody tr:nth-child(4) td:nth-child(2) input');
        var $ipbannguyenlieu999 = $form.find('tbody tr:nth-child(4) td:nth-child(3) input');

        // check nguyen lieu 9999
        if ($ipmuanguyenlieu9999.val() >= $ipbannguyenlieu9999.val()){
            $res['error'] += 1;
            $ipmuanguyenlieu9999.addClass('error');
            var name = $ipmuanguyenlieu9999.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá nguyên liệu 9999 bán ra. ' + '</li>');
        };

        // check nguyen lieu 999
        if ($ipmuanguyenlieu999.val() >= $ipbannguyenlieu999.val()){
            $res['error'] += 1;
            $ipmuanguyenlieu999.addClass('error');
            var name = $ipmuanguyenlieu999.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá nguyên liệu 999 bán ra. ' + '</li>');
        };

        if ($ipmuanguyenlieu999.val() >= $ipmuanguyenlieu9999.val()){
            $res['error'] += 1;
            $ipmuanguyenlieu999.addClass('error');
            var name = $ipmuanguyenlieu999.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá nguyên liệu 9999 mua vào. ' + '</li>');
        };
        if ($ipmuanguyenlieu999.val() >= $ipbannguyenlieu9999.val()){
            $res['error'] += 1;
            $ipmuanguyenlieu999.addClass('error');
            var name = $ipmuanguyenlieu999.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá nguyên liệu 9999 bán ra. ' + '</li>');
        };

        if ($ipbannguyenlieu999.val() >= $ipbannguyenlieu9999.val()){
            $res['error'] += 1;
            $ipbannguyenlieu999.addClass('error');
            var name = $ipbannguyenlieu999.attr('namet');
            $ul.append('<li class="error">'+name+' không được lớn hơn hoặc bằng giá nguyên liệu 9999 bán ra. ' + '</li>');
        };

        // check ngoai bien do
        $input.each(function() {
            var biendo = parseInt($(this).attr('biendo'));
            var origin = parseInt($(this).attr('hn'));
            var gtri = Drupal.doji_gold_price.toNumber($(this));
            var name = $(this).attr('namet');
            if(gtri < origin - biendo || gtri > biendo + origin) {

                $res['error'] += 1;
                $(this).addClass('error');
                $ul.append('<li class="error">'+name+' thay đổi ngoài biên độ cho phép. ' + '</li>');
            }
        });

        return $res;
    }

    Drupal.behaviors.doji_gold_price = function(context) {
        $('#doji-admin-settings table.admin-tbl-gold .do-edit', context).each(function() {
            var $do_edit = $(this);
            var $tr = $(this).parents('tr:first');
            var $do_cancel = $tr.find('.do-cancel:first');
            var $do_save = $tr.find('.do-save:first');
            var $do_update_status = $tr.find('.do-update-status:first');
            var $span = $(this).next('span');
            $tr.find('.form-text').attr('disabled', 'true');

            $do_edit.click(function(){
                $(this).hide();
                $span.show();
                $tr.addClass('active');
                $tr.find('.form-text').removeAttr('disabled');
                return false;
            });
            $do_cancel.click(function(){
                $tr.removeClass('active');
                $tr.find('.form-text').attr('disabled', 'true');
                $span.hide();
                $do_edit.show();
                return false;
            });
            $do_save.click(function(){
                var $form = $do_save.parents('form:first');
                $span.after('<span>' + Drupal.t("Lưu dữ liệu") + '<span class="views-throbbing">&nbsp</span></span>');
                $span.hide();
                $.post($(this).attr('action'), $form.serialize(),
                    function(data){
                        $do_edit.show();
                        $tr.removeClass('active');
                        $tr.find('.form-text').attr('disabled', 'true');
                        $span.next('span').remove();
                    }
                    , "json");
                return false;
            });
            $do_update_status.click(function(){
                $tr.find('.form-text').removeAttr('disabled');
                var $form = $do_save.parents('form:first');
                $span.after('<span>' + Drupal.t("Lưu dữ liệu") + '<span class="views-throbbing">&nbsp</span></span>');
                $span.hide();
                $.post($(this).attr('action'), $form.serialize(),
                    function(data){
                        if (data.text) {
                            $do_update_status.text(data.text);
                        }
                        $tr.find('.form-text').attr('disabled', 'true');
                        $span.next('span').remove();
                    }
                    , "json");
                return false;
            });
        });

        // Bind submit event callback to the form.
        $('#doji-admin-settings .form-submit').click(function() {
            $('#doji-admin-settings input.form-text').removeAttr('disabled');
        });

        $('.form-goldprice-updown .btn-updown-children', context).each(function() {
            var $element = $(this);
            var $form = $element.parents('form:first');
            var $input = $element.parents('.goldprice-td:first').find('input:first');
            //DOJI HN
            var $sjc_le_muavao = $form.find('#edit-sjc-le-muavao');
            var $sjc_le_banra = $form.find('#edit-sjc-le-banra');
            var $sjc_buon_muavao = $form.find('#edit-sjc-buon-muavao');
            var $sjc_buon_banra = $form.find('#edit-sjc-buon-banra');
            //DOJI SG
            var $sjc_sg_le_muavao = $form.find('#edit-sjc-sg-le-muavao');
            var $sjc_sg_le_banra = $form.find('#edit-sjc-sg-le-banra');
            var $sjc_sg_buon_muavao = $form.find('#edit-sjc-sg-buon-muavao');
            var $sjc_sg_buon_banra = $form.find('#edit-sjc-sg-buon-banra');

            //DOJI DN
            var $sjc_dn_le_muavao = $form.find('#edit-doji-8-muavao');
            var $sjc_dn_le_banra = $form.find('#edit-doji-8-banra');
            var $sjc_dn_buon_muavao = $form.find('#edit-doji-4-muavao');
            var $sjc_dn_buon_banra = $form.find('#edit-doji-4-banra');
            //PHI SJC (99.99)
            var $phi_sjc_9999_muavao = $form.find('#edit-phi-sjc-9999-muavao');
            var $phi_sjc_9999_banra = $form.find('#edit-phi-sjc-9999-banra');
            //NGUYÊN LIỆU (99.9)
            var $nguyen_lieu_999_muavao = $form.find('#edit-nguyen-lieu-999-muavao');
            var $nguyen_lieu_999_banra = $form.find('#edit-nguyen-lieu-999-banra');
            //NGUYÊN LIỆU (99)
            var $nguyen_lieu_99_muavao = $form.find('#edit-nguyen-lieu-99-muavao');
            var $nguyen_lieu_99_banra = $form.find('#edit-nguyen-lieu-99-banra');

            //GET VARIABLE
            var $spread = parseFloat(Drupal.settings.doji_gold_price.spread);
            var $banle_spread = parseFloat(Drupal.settings.doji_gold_price.banle_spread);
            var $banle_banbuon = parseFloat(Drupal.settings.doji_gold_price.banle_banbuon);
            var $click_spread = parseFloat(Drupal.settings.doji_gold_price.click_spread);

            //BIN ELEMENT EVENT
            $element.bind('click', function() {
                Drupal.numericElement.formatElement($input, decimals);
            }, function(){
                $i = 0;
                if ($element.hasClass('btn-up') || $element.hasClass('btn-down')) {
                    $i = 1;
                    if ($element.hasClass('btn-down')) {
                        $i = -1;
                    }
                    if ($element.hasClass('disabled')) {
                        $i = 0;
                    }
                }

                Drupal.doji_gold_price.calculator($form, $input, $click_spread, $i);

  //                Drupal.doji_gold_price.suggest.rule_2($sjc_le_muavao, $sjc_le_banra, $sjc_buon_muavao, $sjc_buon_banra);
//                Drupal.doji_gold_price.suggest.rule_3($sjc_sg_le_muavao, $sjc_sg_le_banra, $sjc_sg_buon_muavao, $sjc_sg_buon_banra);
//                Drupal.doji_gold_price.suggest.rule_4($sjc_le_muavao, $sjc_le_banra, $phi_sjc_9999_muavao, $phi_sjc_9999_banra);
//                Drupal.doji_gold_price.suggest.rule_5($nguyen_lieu_999_muavao, $nguyen_lieu_999_banra, $phi_sjc_9999_muavao, $phi_sjc_9999_banra);
//                Drupal.doji_gold_price.suggest.rule_6($nguyen_lieu_99_muavao, $nguyen_lieu_99_banra, $phi_sjc_9999_muavao, $phi_sjc_9999_banra);
//                Drupal.doji_gold_price.suggest.rule_7($sjc_dn_le_muavao, $sjc_dn_le_banra, $sjc_dn_buon_muavao, $sjc_dn_buon_banra);
            });

            // Bind element events.
            $input.bind('keyup', function(e) {
                if (!e) {
                    e = window.event;
                }

                if ($(this).hasClass('processed')) {
                    $(this).removeClass('processed');
                    return true;
                }

                $(this).addClass('processed');

                switch (e.keyCode) {
                    case 16: // shift
                    case 17: // ctrl
                    case 18: // alt
                    case 20: // caps lock
                    case 33: // page up
                    case 34: // page down
                    case 35: // end
                    case 36: // home
                    case 37: // left arrow
                    case 39: // right arrow
                    case 9:  // tab
                    case 13: // enter
                    case 27: // esc
                    //case 38: // up arrow
                    //case 40: // down arrow
                    case 190: // down arrow
                    case 188: // down arrow
                        return true;
                    default:
                        if (e.keyCode == 38) {
                            Drupal.doji_gold_price.calculator($form, $input, $click_spread, 1);
                        }
                        else if (e.keyCode == 40) {
                            Drupal.doji_gold_price.calculator($form, $input, $click_spread, -1);
                        }
                        else if (e.keyCode < 48 || e.keyCode > 57) {
                            return true;
                        }

//                        Drupal.doji_gold_price.suggest.rule_2($sjc_le_muavao, $sjc_le_banra, $sjc_buon_muavao, $sjc_buon_banra);
//                        Drupal.doji_gold_price.suggest.rule_3($sjc_sg_le_muavao, $sjc_sg_le_banra, $sjc_sg_buon_muavao, $sjc_sg_buon_banra);
//                        Drupal.doji_gold_price.suggest.rule_4($sjc_le_muavao, $sjc_le_banra, $phi_sjc_9999_muavao, $phi_sjc_9999_banra);
//                        Drupal.doji_gold_price.suggest.rule_5($nguyen_lieu_999_muavao, $nguyen_lieu_999_banra, $phi_sjc_9999_muavao, $phi_sjc_9999_banra);
//                       Drupal.doji_gold_price.suggest.rule_6($nguyen_lieu_99_muavao, $nguyen_lieu_99_banra, $phi_sjc_9999_muavao, $phi_sjc_9999_banra);
//                       Drupal.doji_gold_price.suggest.rule_7($sjc_dn_le_muavao, $sjc_dn_le_banra, $sjc_dn_buon_muavao, $sjc_dn_buon_banra);
                }
                $input.addClass('processed');
            });

            $input.bind('blur', function() {
                Drupal.numericElement.formatElement($input, -1);
            });
        });
        // event when submit form Phi SJC.
        $('.form-footer-container #edit-submit1').click(function() {
            $("#noitce-message ul").html("");
            var $form = $(this).parents('table:first');
            var $form1 = $(this).parents('form:first');
            $form1.find('input.form-text').each(function(){
                Drupal.doji_gold_price.goldprice_form_set_value($form1, $(this), 0, 0);
            });
            $res = Drupal.doji_gold_price.suggest.rule_73($form);
            if (!$res['error'] && !$res['warning']) {
                $('#goldprice-form .form-submit').click();
            }

            else {
                popover($(this));
                if (!$res['error']) {
                    $('#noitce-message .form-submit').show();
                }

                $('#noitce-message #edit-calcel').show();
                $("#edit-submit").click(function() {
                    $('#goldprice-form .form-submit').click();
                });

            }
            return false;
        });
        // event when submit form HN.
        $('.form-footer-container #edit-submit2').click(function() {
            $("#noitce-message ul").html("");
            var $form = $(this).parents('table:first');
            var $form1 = $(this).parents('form:first');
            $form1.find('input.form-text').each(function(){
                Drupal.doji_gold_price.goldprice_form_set_value($form1, $(this), 0, 0);
            });
            $res = Drupal.doji_gold_price.suggest.rule_72($form);

            if (!$res['error'] && !$res['warning']) {
                $('#goldprice-form .form-submit').click();
            }
            else {
                popover($(this));
                if (!$res['error']) {
                    $('#noitce-message .form-submit').show();
                }

                $('#noitce-message #edit-calcel').show();
                $("#edit-submit").click(function() {
                    $('#goldprice-form .form-submit').click();
                });

            }
            return false;
        });

        // event when submit form DN.
        $('.form-footer-container #edit-submit3').click(function() {

            $("#noitce-message ul").html("");
            var $form = $(this).parents('table:first');
            var $form1 = $(this).parents('form:first');
            $form1.find('input.form-text').each(function(){
                Drupal.doji_gold_price.goldprice_form_set_value($form1, $(this), 0, 0);
            });

            $res = Drupal.doji_gold_price.suggest.rule_71($form);
            if (!$res['error']) {
                $('#goldprice-form .form-submit').click();
            }

            else {
                popover($(this));
                if (!$res['error']) {
                    $('#noitce-message .form-submit').show();
                }

                $('#noitce-message #edit-calcel').show();
                $("#edit-submit").click(function() {
                    $('#goldprice-form .form-submit').click();
                });

            }
            return false;

        });

        // event when submit form SG.

        $('.front .form-footer-container #edit-submit').click(function() {
            $("#noitce-message ul").html("");
            var $form = $(this).parents('table:first');
            var $form1 = $(this).parents('form:first');
            $form1.find('input.form-text').each(function(){
                Drupal.doji_gold_price.goldprice_form_set_value($form1, $(this), 0, 0);
            });
            $res = Drupal.doji_gold_price.suggest.rule_71($form);
            if (!$res['error']) {
                $('#goldprice-form .form-submit').click();
            }
            else {
                popover($(this));
                if (!$res['error']) {
                    $('#noitce-message .form-submit').show();
                }

                $('#noitce-message #edit-calcel').show();
                $("#edit-submit").click(function() {
                    $('#goldprice-form .form-submit').click();
                });

            }
            return false;
        });

        // Bind submit event callback to the form.
        $('#goldprice-form-v2 form.goldprice-form #edit-submit').click(function() {
            var $form = $(this).parents('form:first');
            var $sjc_le_muavao = $form.find('#edit-field-sjc-le-muavao-0-value');
            var $sjc_le_banra = $form.find('#edit-field-sjc-le-banra-0-value');
            var $sjc_buon_muavao = $form.find('#edit-field-sjc-buon-muavao-0-value');
            var $sjc_buon_banra = $form.find('#edit-field-sjc-buon-banra-0-value');

            //Add noitce message
            $('#noitce-message ul li:not(".first")').remove();
            var $res = Drupal.doji_gold_price.suggest.rule_2($sjc_le_muavao, $sjc_le_banra, $sjc_buon_muavao, $sjc_buon_banra);

            $form.bind('submit', function() {
                $('input.gold-price-input', this).each(function() {
                    $(this).removeAttr('disabled');

                    Drupal.numericElement.clearThousandsSep($(this));
                    if (Drupal.goldpriceCalculator.clearThousandsSep($(this)) < 0) {
                        $res['error'] += 1;
                        $(this).parents('tr:first').find('.form-text').addClass('error');
                    }
                });

                if ($res['error'] > 0) {
                    $('form.goldprice_js_disabled input.gold-price-input-disabled', context).each(function(){
                        var $this = $(this);
                        $this.attr('disabled', 'true');
                    });
                    /* $noitce_message.show();
                     return false;*/
                    popover($(this));
                }
                else {
                    $('input.gold-price-input', $form).each(function() {
                        $(this).removeAttr('disabled');
                    })
                    /*
                     if ($res['warning'] > 0) {
                     $('#noitce-message .form-submit').show();
                     $noitce_message.show();
                     return false;
                     }
                     */
                }
            });

        });

        $('#noitce-message #edit-submit').click(function(){
            $('#goldprice-form .form-submit').click();
        });

        $('#noitce-message #edit-calcel').click(function(){
            $('#noitce-message').hide();
            //Kiem tra cac truong hien dang duoc disable hay enable va them truong ao
            if ($('#goldprice-form-container').length) {
                $('form.goldprice_js_disabled input.form-text').each(function(){
                    Drupal.numericElement.formatElement($(this), -1);
                    if ($(this).hasClass('gold-price-input-disabled')) {
                        $(this).attr('disabled', 'true');
                    }
                });
            }
            return false;
        });

        function goldprice_auto_index(context) {
            $('form.goldprice-form', context).each(function(){
                var $thisform = $(this);
                var index = 1;
                $thisform.find('.auto-index:visible').each(function(){
                    $(this).text(index);
                    index++;
                });
            });
        }

        function goldprice_auto_position($element) {
            var $formparent = $element.parents('form.goldprice-form:first');
            $addpriceitem = $formparent.find('.add-price-item:first');
            position      = $addpriceitem.position();
            width       = $addpriceitem.width();
            height      = $addpriceitem.height();
            $element.css({
                top             : position.top + height,
                left            : position.left
            });
        }

        $('form.goldprice-form .add-price-item', context).click(function(){
            var position      = $(this).position();
            var width       = $(this).width();
            var height      = $(this).height();
            $('#goldfield-item-hidden').css({
                top             : position.top + height,
                left            : position.left
            });
            $('#goldfield-item-hidden').toggle();
        });

        $('#goldfield-item-hidden .close', context).click(function(){
            $('#goldfield-item-hidden').toggle();
        });

        $('#goldfield-item-hidden .form-item .form-checkbox', context).each(function(){
            var $thischeckbox = $(this);
            $thischeckbox.click(function(){
                if ($(this).is(':checked')) {
                    $('form.goldprice-form .'+ $(this).attr('fieldname')).show();
                    goldprice_auto_position($(this).parents('#goldfield-item-hidden:first'));
                    goldprice_auto_index(context);
                    goldprice_status = 1;
                }
                else {
                    $('form.goldprice-form .'+ $(this).attr('fieldname')).hide();
                    goldprice_auto_position($(this).parents('#goldfield-item-hidden:first'));
                    goldprice_auto_index(context);
                    goldprice_status = 0;
                }
                //console.log($thischeckbox.attr('action') + '/' + $(this).attr('fieldname') + '/' + goldprice_status)
                $.get($thischeckbox.attr('action') + '/' + $(this).attr('fieldname') + '/' + goldprice_status, null,
                    function(data){
                        //oop
                    }
                    , "json");
            });
        });

        goldprice_auto_index(context);

        //Kiem tra cac truong hien dang duoc disable hay enable va them truong ao
        $('form.goldprice_js_disabled input.gold-price-input-disabled', context).each(function(){
            var $this = $(this);
            $this.attr('disabled', 'true');
        });

        $('#edit-add-goldprice').click(function(){
            $('#block-doji_gold_price-add_new_field').show();
            $(this).hide();
        });

        $('#doji-gold-price-add-new-field .form-submit').click(function(){
            var $form = $(this).parents('form:first');
            var error = 0;
            $form.find('.form-text').each(function(){
                if ($(this).hasClass('required') && $(this).val() == '') {
                    $(this).addClass('error');
                    error++;
                }
                else {
                    $(this).removeClass('error');
                }
            })
            if (error) {
                return false;
            }
        });
    };
    //hide popover khi resize trinh duyet
    $(window).resize(function(){
        $('#noitce-message').hide();
        $('.popover').hide();
        $(".sticky-header").remove();
    })
    $( document ).ready(function() {
        $('.hienthi_rowpoup').hide();
        $(".sticky-header").remove();//xoa phan table header
        updateItemHeight();
        bangGiaVungMien();


        $('#block-doji_area-history_node .content').jScrollPane();

        $('.jspVerticalBar').hover(function(){
            $("li.canhbao").removeClass('active-click top bottom');
            $('#popup').remove();
        });
        $('#block-doji_area-canhbao').mouseleave(function(){
            $("li.canhbao").removeClass('active-click top bottom');
        });



    });
    /**/


})(jQuery)

/* popover cua table */
function popover(element){
    var thisOffset = element.offset()
        ,noitce_top = thisOffset.top - $('#gv-left').offset().top
        ,noitce_left = thisOffset.left - $('#gv-left').offset().left

    // console.log(noitce_top+","+noitce_left);
        ,$noitce_message = $('#noitce-message')
        ,noitce_margin_left = -($noitce_message.width()+50);
    //  console.log(noitce_margin_left);
    $noitce_message.css({'top': noitce_top,'left': noitce_left,'margin-left':noitce_margin_left+'px', 'margin-top':'-25px'});
    $noitce_message.show();
    return false;
};


/*kiem tra chieu cao cua 2 table dung canh nhau. chieu cao cua bang nao lon hon thi ap dung cho ca 2 table*/
function selectHeight(e){
    return $(e).height();
}
function checkHeight(e1, e2){
    var     h1 = selectHeight(e1)
        ,   h2 = selectHeight(e2);
    if (h1<=h2){return h2} else{return h1}
}

function checkmozilla(){
    if ( $.browser.mozilla == true) {
        return true;
    }else { return false;}
}
function updateItemHeight(){
    var i=1;

    do {
        var e1 = i
            ,e2 = e1+1;
        var e1 = '.page-doji.logged-in.ad_class .goldprice-view:nth-child('+e1+')'
            ,e2 = '.page-doji.logged-in.ad_class .goldprice-view:nth-child('+e2+')';
        var height = null,
            height = checkHeight(e1,e2);
        if ((height)&&(checkmozilla()== true)){
            height = height +48;
            $(e1).css({'height': height+'px'});
            $(e2).css({'height': height+'px'});
            i=i+2;
        }else{
            $(e1).css({'height': height+'px'});
            $(e2).css({'height': height+'px'});
            i=i+2;
        }
    }
    while (height);
}

// tao tab cho bang gia vung mien
function bangGiaVungMien(){
    var admin_vungmien = $('body').hasClass('ad_quantri');
    if( admin_vungmien){
        var tabHeader = '<div class="table"><div class="table-cell lable">Bảng giá</div><div class="table-cell hn active" rel=hn> <a href="#">Hà Nội</a></div><div class="table-cell hcm" rel=hcm><a href="#">Hồ Chí Minh</a></div><div class="table-cell dn" rel=dn><a href="#">Đà Nẵng</a></div></div>';
        $( tabHeader).insertBefore( "#bang-gia-theo-vung-mien" );
        $('#bang-gia-theo-vung-mien').children('.clear-block').children().hide();
        $('#bang-gia-theo-vung-mien .clear').remove();
        $('.ad_quantri #bang-gia-theo-vung-mien .hn').show();
        $( "#block-block-3 .table-cell" ).live( "click", function() {
            var id = $(this).attr('rel');
            if(id === undefined){
                return 0;
            }else{
                $('#bang-gia-theo-vung-mien').children('.clear-block').children().hide();
                $('.ad_quantri #bang-gia-theo-vung-mien .'+id).show();
                $('.ad_quantri #block-block-3 .table .table-cell').removeClass('active');
                $(this).addClass('active');
            }
        });
    }else{
        return 0;
    }

}


