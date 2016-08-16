
$(document).ready(function() {
    $("#group-field-cua-hang-items table tr").each(function(){
        $(this).find(".form-select").change(function() {
            var fid = $(this).val();

            $.ajax({ url: 'doji/get_field?fid='+fid,
                dataType: 'JSON',
                success: function(output) {

                    var result = Drupal.parseJson(output);
                    $(this).find('.form-text text').html(result.data);
                }
            });

        })
    })

    $("#edit-field-path-0-value").val( window.location.href).select();
    $('.copy-path').zclip({
        path:'/sites/all/themes/doji_gold/scripts/ZeroClipboard.swf',
        copy:$('input#edit-field-path-0-value').val()
    });

});