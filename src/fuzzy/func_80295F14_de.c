#include "shared/texture_request.h"

/* Request a texture resource with asynchronous loading. */
void **func_80295F14_de(s32 *resource, s32 variation)
{
    return rw_request_texture(resource, variation, 0);
}
