#include "main.h"

void print_result(
    double t, 
    char *operation_name,
    char *platform
) {
    printf("\
    %s \n\
operation: %s \n\
    measured time = %lf \n\
\n", platform, operation_name, t
    );
}

#define COUNT_OF_LAUNCHES 1000000


double result;
int main(void)
{
    clock_t begin, time_of_launch;
    double time;
    double  x1 = 3.4, 
            y1 = 4.4,
            x2 = 3.5,
            y2 = -4.4;
    printf("\n");

    // double result = 100;
    // ASM_SCALAR_MUL;
    // printf("result = %lf\n", result);

    // usual C addition
    time = 0; time_of_launch = 0; begin = 0;
    for (int i = 0; i < COUNT_OF_LAUNCHES; i++) {
        begin = clock();
        C_SCALAR_MUL;
        time_of_launch = clock() - begin;
        time += time_of_launch;
    }
    time /= COUNT_OF_LAUNCHES;

    print_result(time, "scalar multiple of vectors", "C");

    // asm addition
    time = 0; time_of_launch = 0; begin = 0;
    for (int i = 0; i < COUNT_OF_LAUNCHES; i++) {
        begin = clock();
        ASM_SCALAR_MUL;
        time_of_launch = clock() - begin;
        time += time_of_launch;
    }
    time /= COUNT_OF_LAUNCHES;

    print_result(time, "scalar multiple of vectors", "ASM");

    return 0;
}