#include <pebble.h>
#include "src/c/app.h"

int main( void )
{
    app_init();
    app_event_loop();
    app_deinit();
    return 0;
}
