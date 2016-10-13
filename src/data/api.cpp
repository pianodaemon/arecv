#include "data/api.hpp"
#include <dlfcn.h>

extern int
ds_map( struct ds_api** new_ds_ptr, const char* share_lib )
{
    int rc = 0;

    for(;;)
    {
        if( new_ds_ptr == nullptr )
        {
            rc = -1;
            break;
        }

        *new_ds_ptr = new ds_api;

        if( *new_ds_ptr == nullptr )
        {
            rc = -1;
            break;
        }

        {        
            auto ds_ptr = *new_ds_ptr;

            ds_ptr->handle = dlopen (share_lib, RTLD_LAZY);
            if ( ds_ptr->handle == nullptr )
            {
            ds_ptr->emsg = dlerror();
                rc = -1;
                break;
            }

            ds_ptr->initialize = (init_handler) (
                dlsym(ds_ptr->handle, "initialize")
            );

            if ( (ds_ptr->emsg = dlerror()) != nullptr )
            {
                rc = -1;
                break;
            }

            ds_ptr->terminate = (term_handler) (
                dlsym(ds_ptr->handle, "terminate")
            );
            if ( (ds_ptr->emsg = dlerror()) != nullptr )
            {
                rc = -1;
                break;
            }
        }

        break;
    }

    return rc;
}

extern void
ds_unmap( struct ds_api* ds_ptr )
{
    if ( ds_ptr )
    {
        ds_ptr->emsg = nullptr;
        ds_ptr->initialize = nullptr;
        ds_ptr->terminate = nullptr;
        dlclose(ds_ptr->handle);
        ds_ptr->handle = nullptr;
        delete ds_ptr;
    }
}
