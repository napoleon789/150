jQuery(document).ready(function() {
    $("#block-block-6 .form-select").change(function() {
        var uid = $(this).val();
        console.log(uid);
        var url = 'sites/default/files/data/hienthi/vungmien_'+uid+'.dat';
        $.ajax({
            url: url,
            type: "GET",
            success: function(data) {
                console.log(data);
                $('.show_ex').html(data);
            }
        })
    });
    //thay doi hop select trang chu cho user khong dang nhap
    $("#block-block-3 .form-select").change(function() {
        var uid = $(this).val();
        console.log(uid);
        var url = 'sites/default/files/data/hienthi/vungmien_'+uid+'.dat';
        $.ajax({
            url: url,
            type: "GET",
            success: function(data) {
                $('.dn.midle').html('<div class="clear-block block-bg border-gray p-10 size-12 noibat">'+data+'</div>');
            }
        })
    });
});