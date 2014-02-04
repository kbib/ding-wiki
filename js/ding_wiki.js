
/**
 * REVIEW: Missing documentation and file description.
 */

Drupal.behaviors.dingWikiCarousel = function(context) {
  if($('.ding-wiki-carousel .field-wiki-images ul li').length > 1) {
    if (jQuery.jcarousel) {
      $('.ding-wiki-carousel .field-wiki-images ul').jcarousel({
        vertical: false, //
        scroll: 3, //amount of items to scroll by
        animation: "fast", // slow - fast
        auto: "0", //autoscroll in seconds
        wrap: "last"
      });
    }
  }
};

Drupal.behaviors.dingWikiGallery = function(context) {
  var gallery = $('body:not(.page-admin) .ding-wiki-gallery-thumbs .field-wiki-images');
  if (gallery.length > 0) {
    gallery.parents('.ding-wiki-gallery-thumbs').find('.count').html(Drupal.t('%num of %count images', { '%num' : 1, '%count' : gallery.find('li').length}));
    gallery.find('ul').addClass('thumbs').find('a').addClass('thumb');
    gallery.find('.description').addClass('caption');
    gallery.galleriffic({
        delay:                     3000, // in milliseconds
        numThumbs:                 1000, // The number of thumbnails to show page. We show all images as jCarousel handles pagination
        preloadAhead:              40, // Set to -1 to preload all images
        enableTopPager:            false,
        enableBottomPager:         false,
        maxPagesToShow:            false,  // The maximum number of pages to display in either the top or bottom pager
        imageContainerSel:         '.ding-wiki-gallery-images', // The CSS selector for the element within which the main slideshow image should be rendered
        controlsContainerSel:      '.ding-wiki-gallery-thumbs .controls', // The CSS selector for the element within which the slideshow controls should be rendered
        captionContainerSel:       '.ding-wiki-gallery-caption', // The CSS selector for the element within which the captions should be rendered
        loadingContainerSel:       '', // The CSS selector for the element within which should be shown when an image is loading
        renderSSControls:          true, // Specifies whether the slideshow's Play and Pause links should be rendered
        renderNavControls:         false, // Specifies whether the slideshow's Next and Previous links should be rendered
        playLinkText:              Drupal.t('Play'),
        pauseLinkText:             Drupal.t('Pause'),
        prevLinkText:              Drupal.t('Previous'),
        nextLinkText:              Drupal.t('Next'),
        nextPageLinkText:          Drupal.t('Next &rsaquo;'),
        prevPageLinkText:          Drupal.t('&lsaquo; Prev'),
        enableHistory:             false, // Specifies whether the url's hash and the browser's history cache should update when the current slideshow image changes
        enableKeyboardNavigation:  true, // Specifies whether keyboard navigation is enabled
        autoStart:                 false, // Specifies whether the slideshow should be playing or paused when the page first loads
        syncTransitions:           false, // Specifies whether the out and in transitions occur simultaneously or distinctly
        defaultTransitionDuration: 1000, // If using the default transitions, specifies the duration of the transitions
        onSlideChange:             Drupal.dingWiki.updateCount
    });
  }
};

Drupal.dingWiki = {

  updateCount: function(currentIndex, newIndex) {
    $('.ding-wiki-gallery-thumbs').find('.count em:first').text(newIndex + 1);  
  }

};
