#include "client.hpp"

extern "C" void
initialize(void)
{
    curl_global_init( CURL_GLOBAL_ALL );
}


extern "C" void
terminate(void)
{
    curl_global_cleanup();
}
