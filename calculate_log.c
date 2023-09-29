#include <stdio.h>
#include <float.h>
#define b 10.0

int main(void)
{
    double x, d, log;
    int i, di, xi, xj;

    printf("      ");

    for(xj = 0; xj < 10; xj++)
        printf("%+9.2lf", xj / 100.0);
    printf("\n      +");

    for(xj = 0; xj < 10; xj++)
        printf("  -------");
    printf("\n");

    for(xi = 10; xi < 100; xi++) {
        printf("%5.2lf |", xi / 10.0);

        for(xj = 0; xj < 10; xj++){
            x = xi / 10.0 + xj / 100.0;
            // Log_b(x) hesaplama
            d = 1.0;
            log = 0.0;
            for(i = 1; i <= DBL_DIG; i++) {
                x = x*x*x*x*x;
                x *= x;
                for (di = 0; x > b; x /= b, di++)
                    ;
                d *= 10.0;
                log += di / d;
            } // for i
            printf("%9.5lf", log);
        } // for xj
        printf("\n");
    }
}
