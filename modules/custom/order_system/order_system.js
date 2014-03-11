/**
  * @file
  * JS support for order system module.
*/

(function($, Drupal) {
  jQuery(document).ready(function() {
    /**
     * Create increase/decrease/remove methods for cart view page.
     */
    Drupal.cart_page_operations = function() {
      jQuery('#cart-wrapper .operations img').click(function() {
        var element_class = $(this).attr('class'),
            input = $(this).parent().prev().find('input');

        switch (element_class) {
          case 'increase':
            input.val(parseInt(input.val())+1);
            break;
          case 'decrease':
            input.val(parseInt(input.val())-1);
            break;
          case 'remove':
            input.val(0);
            break;
        }
        jQuery('input[name="update"]').mousedown();
      });
    };

    Drupal.cart_page_operations();

    // Execute same function after ajax handler submit.
    if (Drupal.ajax) {
      Drupal.ajax.prototype.commands.cart_page_operations = function(ajax, response, status) {
        Drupal.cart_page_operations();
      };
    }
  });
})(jQuery, Drupal);
