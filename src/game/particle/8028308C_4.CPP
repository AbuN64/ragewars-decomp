#include "COMMON/OBJECTLINKS1E8.H"

/* Passes the first non-null handle among entries 0 to count of the object's twenty-byte table at
   0xFC28 to func_80284570_de together with the object. */


extern void Particle_Release(char *obj, void *handle);

void Particle_ReleaseFirstHandle(char *obj, unsigned char count) {
    int i;

    for (i = 0; i <= count; i++) {
        EntryRecAt4V1 *e = (EntryRecAt4V1 *)(obj + i * sizeof(EntryRecAt4V1) + 0xFC28);
        if (e->handle != 0) {
            Particle_Release(obj, e->handle);
            return;
        }
    }
}
