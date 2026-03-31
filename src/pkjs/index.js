Pebble.addEventListener( 'ready', function () {
    console.log( "JS Ready" );
    Pebble.sendAppMessage({ 'PING': 1 }, (e) => {}, (e) => {});
});

Pebble.addEventListener( 'appmessage', function (e) {
    if ( e.payload[ 'PONG' ]) {
        console.log( "Received pong" );
    }
});
