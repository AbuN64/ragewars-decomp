#ifndef RSP_GEOMETRY_DRAWBLENDPARTS_H
#define RSP_GEOMETRY_DRAWBLENDPARTS_H
#include "TYPES.H"
struct TreeNode {
    unsigned int key;
    unsigned char padding[12];
    struct TreeNode *link10;
    struct TreeNode *link14;
    struct TreeNode *link18;
    struct TreeNode *link1c;
};
#endif
