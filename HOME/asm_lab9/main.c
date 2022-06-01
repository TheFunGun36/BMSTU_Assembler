#include "main.h"

void print_result(
    double t, 
    char *operation_name,
    char *platform,
    double result
) {
    printf("\
platform: %s \n\
operation: %s \n\
    result = %lf \n\
    measured time = %lf \n\
\n", platform, operation_name, result, t
    );
}

int main(void)
{ 
    {
        clock_t begin, time_of_launch;
        double time;
        float a = 1e9;
        float b = 1e5;
        float result = 100;
        printf("\nFLOAT\n\n");

        CALC_TIME("addition", "C", C_ADD);
        CALC_TIME("addition", "ASM", ASM_ADD);
        CALC_TIME("subtraction", "C", C_SUB);
        CALC_TIME("subtraction", "ASM", ASM_SUB);
        CALC_TIME("multiple", "C", C_MUL);
        CALC_TIME("multiple", "ASM", ASM_MUL);
        CALC_TIME("division", "C", C_DIV);
        CALC_TIME("division", "ASM", ASM_DIV);
        // CALC_TIME("sin pi", "C", C_SIN_PI);
        // CALC_TIME("sin pi", "ASM", ASM_SIN_PI);
        // CALC_TIME("sin pi/2", "C", C_SIN_PI_2);
        // CALC_TIME("sin pi/2", "ASM", ASM_SIN_PI_2);
    }
    {
        clock_t begin, time_of_launch;
        double time;
        double a = 1e9;
        double b = 1e5;
        double result = 100;
        printf("\nDOUBLE\n\n");

        CALC_TIME("addition", "C", C_ADD);
        CALC_TIME("addition", "ASM", ASM_ADD);
        CALC_TIME("subtraction", "C", C_SUB);
        CALC_TIME("subtraction", "ASM", ASM_SUB);
        CALC_TIME("multiple", "C", C_MUL);
        CALC_TIME("multiple", "ASM", ASM_MUL);
        CALC_TIME("division", "C", C_DIV);
        CALC_TIME("division", "ASM", ASM_DIV);
        // CALC_TIME("sin pi", "C", C_SIN_PI);
        // CALC_TIME("sin pi", "ASM", ASM_SIN_PI);
        // CALC_TIME("sin pi/2", "C", C_SIN_PI_2);
        // CALC_TIME("sin pi/2", "ASM", ASM_SIN_PI_2);
    }
    
    return 0;
}