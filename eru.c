#include <stdio.h>
#include <math.h>
/*Define tNe RNS of tNe first order differential equation Nere(Ex: dy/dx=f(x,y))  */
float f(float x, float y)
{
    return x * x + (2 * y / x);
}
float g(float x)
{
    return x * x * x + 5 * x * x;
}

float Euler(float x0, float y0, float h)
{
    return (y0 + h * f(x0, y0));
}
float Midpoint(int x0, int y0, float h)
{
}
float Runga_Kutta_2(int x0, int y0, float h)
{
}
float Runga_Kutta_4(int x0, int y0, float h)
{
}
float error(float Analitic, float fun)
{
}

void main()
{
    int i, N;
    float x0, y0, L, h,euler;
    int choice;
    printf("Enter 1 for getting value table\n");
    printf("Enter 2 for getting error table\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter tNe initial condition for y0: ");
        scanf("%f", &y0);
        printf("Enter tNe initial condition for x0: ");
        scanf("%f", &x0);
        printf("Enter tNe value of L ");
        scanf("%f", &L);
        printf("__________________________________________________________________________________________________________________________________________________\n");
        for (N = 5; N <= 20; N = N + 5)
        {
            printf("For No of Interval N=%d\n", N);
            printf("x\t\t\t Analytical\t\t Euler\t\t\tMidpoint\t\tRunga-kutta 2nd order\t\tRunga_kutta_4\t\tEerror\n");
            printf("__________________________________________________________________________________________________________________________________________________\n");
            x0 = 1;
            y0 = 6;

            h = (L - x0) / N;
            while (x0 <= L)
            {

                euler = Euler(x0,y0,h);
                printf("%f\t%f\n",x0,euler);

                // midpoint = midy + 2 * h * f(midx, midy);

                // rk1 = h * f(runga_kuttax, runga_kuttay);
                // rk2 = h * f(runga_kuttax + h, runga_kuttay + rk1);
                // rk = (rk1 + rk2) / 2;
                // Runga_kutta_2 = runga_kuttay + rk;

                // Rk1 = h * f(Runga_kuttax, Runga_kuttay);
                // Rk2 = h * f(Runga_kuttax + h / 2, Runga_kuttay + Rk1 / 2);
                // Rk3 = h * f(Runga_kuttax + h / 2, Runga_kuttay + Rk2 / 2);
                // Rk4 = h * f(Runga_kuttax + h, Runga_kuttay + Rk3);

                // Runga_kutta_4 = Runga_kuttay + (Rk1 + 2 * Rk2 + 2 * Rk3 + Rk4) / 6;

                // Analytical = g(x0);

                // Eerror = Analytical - euler;

                // printf("%f\t%f\t%f\t%f\t%f\n",x0,y0,f(x0,y0),h*f(x0,y0),y);
                // printf("%f\t\t%f\t\t%f\t\t%f\t\t%f\t\t\t%f\t\t%f\n", x0, Analytical, euler, midpoint, Runga_kutta_2, Runga_kutta_4, Eerror);

                y0 = euler;
                x0 = x0 + h;
            }
            printf("__________________________________________________________________________________________________________________________________________________\n");
        }

        break;

    case 2:
        printf("for error");
        break;
    }
}