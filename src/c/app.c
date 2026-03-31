#include <pebble.h>
#include "src/c/app_prv.h"

Window* s_window;

void app_process_message( DictionaryIterator* message )
{
    APP_LOG( APP_LOG_LEVEL_INFO, "Received a message of %d bytes", dict_size( message ) );
    
    const Tuple* const tuple = dict_find( message, MESSAGE_KEY_PING );
    if ( tuple )
    {
        APP_LOG( APP_LOG_LEVEL_INFO, "Received ping" );
        DictionaryIterator* response;
        app_message_outbox_begin( &response );
        dict_write_int8( response, MESSAGE_KEY_PONG, 1 );
        app_message_outbox_send();
    }
}

static void inbox_received_callback( DictionaryIterator* iterator, void* context )
{
    app_process_message( iterator );
}

void app_init( void )
{
    s_window = window_create();
    window_stack_push( s_window, true );
    
    app_message_register_inbox_received( inbox_received_callback );
    app_message_open( 256, 256 );
}

void app_deinit( void )
{
    window_destroy( s_window );
}
