/* Zero alignment between the preceding Huffman table and pre-boot trailer at DD83C.
 * Only DD834-DD83C is zero fill; DD83C-DD840 remains unresolved.
 */
.section .rsp.alignment,"a",@progbits
.globl ragewars_rsp_resource_alignment
ragewars_rsp_resource_alignment:
    .zero 8
.size ragewars_rsp_resource_alignment, .-ragewars_rsp_resource_alignment
