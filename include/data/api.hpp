#ifndef __DS_API_HPP__
#define __DS_API_HPP__

typedef void (*init_handler)(void);
typedef void (*term_handler)(void);

struct ds_api
{
    void *handle;
    char *emsg;
    init_handler initialize;
    term_handler terminate;
};

extern int
ds_map( struct ds_api** new_ds_ptr, const char* share_lib );

extern void
ds_unmap( struct ds_api* ds_ptr );

#endif /* __DS_API_HPP__ */
