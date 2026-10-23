#ifndef AI_ACTOR_SETUP_VERSIONS_H
#define AI_ACTOR_SETUP_VERSIONS_H
/* The actor-record builder and its two behaviour tables sit at different addresses in each cartridge. */
#if defined(VERSION_EU)
#define ACTOR_TABLE_A D_0024B54C_eu
#define ACTOR_TABLE_B D_0024B8FC_eu
#elif defined(VERSION_EU_X)
#define ACTOR_TABLE_A D_0024B57C_eu_x
#define ACTOR_TABLE_B D_0024B92C_eu_x
#elif defined(VERSION_US)
#define ACTOR_TABLE_A D_0024B51C_us
#define ACTOR_TABLE_B D_0024B8CC_us
#elif defined(VERSION_US_REV1)
#define ACTOR_TABLE_A D_0024B52C_us_rev1
#define ACTOR_TABLE_B D_0024B8DC_us_rev1
#else
#define ACTOR_TABLE_A D_0024B53C_de
#define ACTOR_TABLE_B D_0024B8EC_de
#endif
#endif
