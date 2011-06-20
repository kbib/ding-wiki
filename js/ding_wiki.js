Drupal.behaviors.dingWikiCarousel = function(context) {
  $('.node-wiki_page .field-wiki-images ul').jcarousel({
    vertical: false, //
    scroll: 3, //amount of items to scroll by
    animation: "fast", // slow - fast
    auto: "0", //autoscroll in seconds
    wrap: "last",
  });
}