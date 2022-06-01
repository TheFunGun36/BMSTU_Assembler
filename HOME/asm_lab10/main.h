#include <stdio.h>
#include <time.h>

#define C_SCALAR_MUL result = (x1 * x2 + y1 * y2)
// avx а.операции только с регистром
#define ASM_SCALAR_MUL __asm__(\
    "vmovq %1, %%xmm0\n\t"\
    "vmovq %3, %%xmm1\n\t"\
    "vmovq %2, %%xmm2\n\t"\
    "vmovq %4, %%xmm3\n\t"\
    "vmulsd %%xmm0, %%xmm1, %%xmm4\n\t"\
    "vmulsd %%xmm2, %%xmm3, %%xmm5\n\t"\
    "vaddsd %%xmm4, %%xmm5, %%xmm6\n\t"\
    "vmovq %%xmm6, %0\n\t"\
    : "=m"(result)\
    : "m"(x1), "m"(y1), "m"(x2), "m"(y2)\
    : "%xmm0", "%xmm1", "%xmm2", "%xmm3", "%xmm4", "%xmm5", "%xmm6"\
)