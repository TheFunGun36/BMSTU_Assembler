#include <stdio.h>
#include <time.h>
#include <math.h>

#define COUNT_OF_LAUNCHES 500000

#define CALC_TIME(oper, platform, macro) \
time = 0; time_of_launch = 0; begin = 0;\
for (int i = 0; i < COUNT_OF_LAUNCHES; i++) {\
    begin = clock();\
    macro;\
    time_of_launch = clock() - begin;\
    time += time_of_launch;\
}\
time /= COUNT_OF_LAUNCHES;\
print_result(time, oper, platform, result)\

#define C_ADD result = (a + b)
#define ASM_ADD \        
__asm__( \
    "flds %2\n\t"\
    "flds %1\n\t"\
    "faddp\n\t"\
    "fstps %0\n\t"\
    : "=m"(result)\
    : "m"(a), "m"(b)\
    : "%st"\
)

#define C_SUB result = (a - b)
#define ASM_SUB \        
__asm__( \
    "flds %2\n\t"\
    "flds %1\n\t"\
    "fsubp\n\t"\
    "fstps %0\n\t"\
    : "=m"(result)\
    : "m"(a), "m"(b)\
    : "%st"\
)

#define C_MUL result = (a * b)
#define ASM_MUL \        
__asm__( \
    "flds %2\n\t"\
    "flds %1\n\t"\
    "fmulp\n\t"\
    "fstps %0\n\t"\
    : "=m"(result)\
    : "m"(a), "m"(b)\
    : "%st"\
)

#define C_DIV result = (a / b)
#define ASM_DIV \        
__asm__( \
    "flds %2\n\t"\
    "flds %1\n\t"\
    "fdivp\n\t"\
    "fstps %0\n\t"\
    : "=m"(result)\
    : "m"(a), "m"(b)\
    : "%st"\
)

#define C_SIN_PI result = sin(M_PI)
#define ASM_SIN_PI \        
__asm__( \
    "fldpi\n\t"\
    "fsin\n\t"\
    "fstps %0\n\t"\
    : "=m"(result)\
    :: "%st"\
)

#define C_SIN_PI_2 result = sin(M_PI / 2)
#define ASM_SIN_PI_2 \        
__asm__( \
    "fld1\n\t"\
    "fld1\n\t"\
    "faddp\n\t"\
    "fldpi\n\t"\
    "fdivp\n\t"\
    "fsin\n\t"\
    "fstps %0\n\t"\
    : "=m"(result)\
    :: "%st"\
)