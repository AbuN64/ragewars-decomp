#ifndef COMMON_DEBUG_HELPERS_H
#define COMMON_DEBUG_HELPERS_H
/* Debug range watch: when `value` falls outside [low, high] it is copied into `seen` for the debugger. The caller
 * passes a local that the code overwrites next, so in the release build the watch has no effect: only the tests are
 * compiled, and gcc deletes them after register allocation (jump2) once it has kept their operands live. */
#define RW_DEBUG_RANGE(seen, value, low, high)                                                                       \
    do {                                                                                                             \
        if ((value) < (low) || (value) > (high)) (seen) = (value);                                                   \
    } while (0)
#endif
