#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    return 8 / (4 + x * x);
}
float g(float x)
{
    return 2 * sqrt(1 - (x * x));
}
float midpoint(float x1, float x2)
{
    return ((x1 + x2) / 2);
}

void main()
{
    int z, n = 1, d, position_of_term, no_of_run, method;
    float s, h, i, E, p, q, e, m, a, b;
    float arr[20];

    //Step1--Giving user choice
    FILE *fp = NULL;
    // fp = fopen("errorslog222.csv", "w");

    /* code */
    while (1)
    {

        printf("Press 1 for Midpoint method\n");
        printf("Press 2 for trapezoidal method\n");
        printf("Press 3 for simpson 1/3 method\n");
        printf("Press 4 for simpson 3/8 method\n");
        scanf("%d", &z);

        switch (z)
        {
        case 1:
            E = 0;
            e = 3.1415926;
            s = 0;
            for (n = 1; n <= 20; n++)
            {

                a = 0, b = 2;

                h = (b - a) / (6 * n);

                for (i = 0; i <= 2; i = i + h)
                {

                    m = midpoint(a, a + h);
                    a = a + h;
                    s = s + f(m);
                }
                s = s * h;
                printf("the value of integral in division n=%d is %f\n", n, s);

                E = (e - s);
                E = E / e;
                E = fabs(E);
                arr[n - 1] = E;
                printf("error is %f\n", arr[n - 1]);
                fp = NULL;
                fp = fopen("errorscase1.csv", "w");
                fprintf(fp, "%f\n", log10(E));
            }
            fclose(fp);
            fp = 0;
            system("pause");
            break;

        case 2:
            a = 0;
            E = 0;
            b = 2;
            e = 3.1415926;
            s = 0;
            s = f(a) + f(b);

            for (n = 1; n <= 20; n++)
            {

                h = b - a;
                d = 6 * n;
                h = h / d;

                for (i = a + h; i < b; i = i + h)
                {
                    s = s + 2 * f(i);
                }

                s = s * h / 2;
                printf("the value of integral on   n=%d   by trapezoidal     %f\n", n, s);

                E = (e - s);
                E = E / e;
                E = fabs(E);
                arr[n - 1] = E;
                printf("error is %f\n", arr[n - 1]);
                fp = NULL;
                fp = fopen("errorscase2.csv", "w");
                fprintf(fp, "%f\n", log10(E));
            }
            fclose(fp);
            fp = 0;
            system("pause");

            break;
        case 3:
            a = 0;
            E = 0;
            b = 2;
            e = 3.1415926;
            s = 0;
            //**formula for simpson 1/3 rule**//
            //I=*h/3[(y0+yn)+4(terms which are not multiple of 2)+2(terms multiple of 2)]**//
            s = f(a) + f(b);
            for (n = 1; n <= 20; n++)
            {
                h = b - a;
                d = 6 * n;
                h = h / d;

                for (i = a + h; i < b - h; i = i + 2 * h) //** terms which are not multiple of 2 **//

                    s = s + 4 * f(i);

                for (i = a + 2 * h; i < b - 2 * h; i = i + 2 * h) //**terms multiple of 2**//
                    s = s + 2 * f(i);

                s = s * h / 3;
                printf("the value of integral on   n=%d   by  simpsons 1/3     %f\n", n, s);

                E = (e - s);
                E = E / e;
                E = fabs(E);
                arr[n - 1] = E;
                printf("error is %f\n", arr[n - 1]);
                fp = NULL;
                fp = fopen("errorscase3.csv", "w");
                fprintf(fp, "%f\n", log10(E));
            }
            fclose(fp);
            fp = 0;
            system("pause");

            break;
        case 4:
            a = 0;
            E = 0;
            b = 2;
            e = 3.1415926;
            s = 0;
            h = (b - a) / (6 * n); //** here 6*n, so that we can evaluate on multiple n=1,2,3,...and so on**//

            //**formula for simpson 3/8 rule**//
            //I=3*h/8[(y0+yn)+3(terms which are not multiple of 3)+2(terms multiple of 3)]**//

            s = f(a) + f(b); //
            for (n = 1; n <= 20; n++)
            {
                h = b - a;
                d = 6 * n;
                h = h / d;
                for (i = a + h; i < b; i = i + h)

                {
                    if (position_of_term % 3 == 0) //**for terms multiple of 3**//
                        s = s + 2 * f(i);
                    else
                        s = s + 3 * f(i);
                    position_of_term++;
                }
                s = s * h * 3 / 8;
                printf("the value of integral on   n=%d   by  simpsons 3 /8    %f\n", n, s);

                E = (e - s);
                E = E / e;
                E = fabs(E);
                arr[n - 1] = E;
                printf("error is %f\n", arr[n - 1]);
                fp = NULL;
                fp = fopen("errorsscase4.csv", "w");
                fprintf(fp, "%f\n", log10(E));
            }
            fclose(fp);
            fp = 0;
            system("pause");

            break;
        default:
            printf("Invalid input\n");
        }
    }
}