#include <stdio.h>
#include <math.h>

double z1(double alpha)
{
    return 1.0 - 0.25 * pow(sin(2*alpha), 2) + cos(2*alpha);
}

double z2(double alpha)
{
    return pow(cos(alpha), 2) + pow(cos(alpha), 4);
}

int main()
{
    printf("-----Task 2-----\nVariant 5\n");
    
    int numberOfIter = 0;
    double alpha = 0.0;

    printf("How much iterations would you like to have? ");
    scanf("%d", &numberOfIter);

    while(numberOfIter > 0)
    {
        printf("Please, enter alpha value: ");
        scanf("%lf", &alpha);
        
        printf("your alpha is %lf\n", alpha);
        
        printf("z1(alpha) = %lf;\n", z1(alpha));
        printf("z1(alpha) = %lf;\n", z1(alpha));
        printf("------------------------------------\n");

        --numberOfIter;
    }
    
    system("pause");

    return 0;
}