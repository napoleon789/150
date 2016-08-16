jQuery.fn.extend({
	everyTime: function(interval, label, fn, times, belay) {
		return this.each(function() {
			jQuery.timer.add(this, interval, label, fn, times, belay);
		});
	},
	oneTime: function(interval, label, fn) {
		return this.each(function() {
			jQuery.timer.add(this, interval, label, fn, 1);
		});
	},
	stopTime: function(label, fn) {
		return this.each(function() {
			jQuery.timer.remove(this, label, fn);
		});
	}
});

jQuery.extend({
	timer: {
		guid: 1,
		global: {},
		regex: /^([0-9]+)\s*(.*s)?$/,
		powers: {
			// Yeah this is major overkill...
			'ms': 1,
			'cs': 10,
			'ds': 100,
			's': 1000,
			'das': 10000,
			'hs': 100000,
			'ks': 1000000
		},
		timeParse: function(value) {
			if (value == undefined || value == null)
				return null;
			var result = this.regex.exec(jQuery.trim(value.toString()));
			if (result[2]) {
				var num = parseInt(result[1], 10);
				var mult = this.powers[result[2]] || 1;
				return num * mult;
			} else {
				return value;
			}
		},
		add: function(element, interval, label, fn, times, belay) {
			var counter = 0;
			
			if (jQuery.isFunction(label)) {
				if (!times) 
					times = fn;
				fn = label;
				label = interval;
			}
			
			interval = jQuery.timer.timeParse(interval);

			if (typeof interval != 'number' || isNaN(interval) || interval <= 0)
				return;

			if (times && times.constructor != Number) {
				belay = !!times;
				times = 0;
			}
			
			times = times || 0;
			belay = belay || false;
			
			if (!element.$timers) 
				element.$timers = {};
			
			if (!element.$timers[label])
				element.$timers[label] = {};
			
			fn.$timerID = fn.$timerID || this.guid++;
			
			var handler = function() {
				if (belay && this.inProgress) 
					return;
				this.inProgress = true;
				if ((++counter > times && times !== 0) || fn.call(element, counter) === false)
					jQuery.timer.remove(element, label, fn);
				this.inProgress = false;
			};
			
			handler.$timerID = fn.$timerID;
			
			if (!element.$timers[label][fn.$timerID]) 
				element.$timers[label][fn.$timerID] = window.setInterval(handler,interval);
			
			if ( !this.global[label] )
				this.global[label] = [];
			this.global[label].push( element );
			
		},
		remove: function(element, label, fn) {
			var timers = element.$timers, ret;
			
			if ( timers ) {
				
				if (!label) {
					for ( label in timers )
						this.remove(element, label, fn);
				} else if ( timers[label] ) {
					if ( fn ) {
						if ( fn.$timerID ) {
							window.clearInterval(timers[label][fn.$timerID]);
							delete timers[label][fn.$timerID];
						}
					} else {
						for ( var fn in timers[label] ) {
							window.clearInterval(timers[label][fn]);
							delete timers[label][fn];
						}
					}
					
					for ( ret in timers[label] ) break;
					if ( !ret ) {
						ret = null;
						delete timers[label];
					}
				}
				
				for ( ret in timers ) break;
				if ( !ret ) 
					element.$timers = null;
			}
		}
	}
});

if (jQuery.browser.msie) {
	jQuery(window).one("unload", function() {
		var global = jQuery.timer.global;
		for ( var label in global ) {
			var els = global[label], i = els.length;
			while ( --i )
				jQuery.timer.remove(els[i], label);
		}
	});  
}


(function ($) {   
Drupal.behaviors.doji_get = function(context) {
  function doji_get_fresh() {
    $('#giavangquocte', context).oneTime(2500, 'gia_vang_quoc_te', function(i) {
      var $this = $(this); 
      $.get('/?q=doji/get/json/gia_vang_quoc_te', null, function(res){  
          if (!res.error && res.text) {
            $('#giavangquocte').find('table.goldprice-view').html(res.text);  
            
            /*$('#banggia-style-3 td.group_gold:eq(0) span:eq(0)').text($('tr.group_gold td:eq(1)', res.text).text());
            $('#banggia-style-3 td.group_gold:eq(1) span:eq(0)').text($('tr.group_gold td:eq(2)', res.text).text());
            
            $('#banggia-style-3 td.group_quidoi:eq(0) span:eq(0)').text($('tr.group_quidoi td:eq(1)', res.text).text());
            $('#banggia-style-3 td.group_quidoi:eq(1) span:eq(0)').text($('tr.group_quidoi td:eq(2)', res.text).text());
            */
            $('#bang-gia-theo-vung-mien td.goldprice-td-0.group_gold span').text($('tr.group_gold td:eq(1)', res.text).text());
            $('#bang-gia-theo-vung-mien td.goldprice-td-1.group_gold span').text($('tr.group_gold td:eq(2)', res.text).text());
            $('#bang-gia-theo-vung-mien td.goldprice-td-0.group_quidoi span').text($('tr.group_quidoi td:eq(1)', res.text).text());
            $('#bang-gia-theo-vung-mien td.goldprice-td-1.group_quidoi span').text($('tr.group_quidoi td:eq(2)', res.text).text());       
          }     
          
          if (res.main_price) {
            $('.ant-home-price').html(res.main_price); 
          } 
              
          if (res.status == 1) {
             setTimeout(doji_get_fresh, 100);
          }        
        }
      , "json");       
    });           
  }
  
  if ($('#giavangquocte').length > 0) {
    doji_get_fresh();     
  }
              
}; 

})(jQuery);  
