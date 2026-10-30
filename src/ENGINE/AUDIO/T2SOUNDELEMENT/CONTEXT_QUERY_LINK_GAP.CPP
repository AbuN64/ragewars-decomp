/* Retained bytes at the measured link boundary; not executable source or original module provenance. */

#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_ContextQueryLinkGapTrailingBytesBlock1AlignmentPad[4] = { 0x84, 0x82, 0x00, 0x02 };
#endif

#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_ContextQueryLinkGapTrailingBytesAlignmentPad[4] = { 0x00, 0x43, 0x10, 0x23 };
#endif
