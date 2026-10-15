#include "shared/texture_request.h"

/* Request a texture resource with synchronous loading. */
void **func_80295EAC_de(s32 *resource, s32 variation)
{
    return rw_request_texture(resource, variation, 1);
}
