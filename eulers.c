 
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

void main()
{
    int i, N;
    float x0, y0, L, h, euler, Analytical, Eerror, midpoint, midy, midx, rk, rk1, rk2, Rk1, Rk2, Rk3, Rk4, runga_kuttax, runga_kuttay, Runga_kutta_2,Runga_kutta_4,Runga_kuttax,Runga_kuttay;
    printf("Enter tNe initial condition for y0: ");
    scanf("%f", &y0);
    printf("Enter tNe initial condition for x0: ");
    scanf("%f", &x0);
    printf("Enter tNe value of L ");
    scanf("%f", &L);
    // printf("Enter tNe step-widtN N: ");
    // scanf("%f",&N);
    // printf("x\t\ty\t\ty'\t\tNy'\t\ty+Ny'\n");


 
    printf("__________________________________________________________________________________________________________________________________________________\n");

    //Begin Euler Routine
    for (N = 5; N <= 20; N = N + 5)
    {
        printf("For No of Interval N=%d\n",N);
           printf("x\t\t\t Analytical\t\t Euler\t\t\tMidpoint\t\tRunga-kutta 2nd order\t\tRunga_kutta_4\t\tEerror\n");
    printf("__________________________________________________________________________________________________________________________________________________\n");
        x0 = 1;
        y0 = 6;
        midx = x0;
        midy = y0;
        runga_kuttax = 1;
        runga_kuttay = 6;
        Runga_kuttax = 1;
        Runga_kuttay = 6;

        h = (L - x0) / N;
        while (x0 <= L)
        {

            euler = y0 + h * f(x0, y0);

            midpoint = midy + 2 * h * f(midx, midy);


            rk1 = h * f(runga_kuttax, runga_kuttay);
            rk2 = h * f(runga_kuttax + h, runga_kuttay + rk1);
            rk = (rk1 + rk2) / 2;
            Runga_kutta_2 = runga_kuttay + rk;


            Rk1=h* f(Runga_kuttax, Runga_kuttay);
            Rk2=h*f(Runga_kuttax+h/2, Runga_kuttay+Rk1/2);
            Rk3=h*f(Runga_kuttax+h/2, Runga_kuttay+Rk2/2);
            Rk4=h*f(Runga_kuttax+h, Runga_kuttay+Rk3);

            Runga_kutta_4=Runga_kuttay+(Rk1+2*Rk2+2*Rk3+Rk4)/6;

            Analytical = g(x0);

           // Eerror = Analytical - euler;

            // printf("%f\t%f\t%f\t%f\t%f\n",x0,y0,f(x0,y0),h*f(x0,y0),y);
            printf("%f\t\t%f\t\t%f\t\t%f\t\t%f\t\t\t%f\t\t%f\n", x0,   Analytical,euler, midpoint, Runga_kutta_2,Runga_kutta_4,Eerror);

            runga_kuttax = runga_kuttax + h;
            runga_kuttay = Runga_kutta_2;

            Runga_kuttax=Runga_kuttax+h;
            Runga_kuttay=Runga_kutta_4;
            y0 = euler;
            midy = midpoint;
            midx = midx + h;
            x0 = x0 + h;
        }
        printf("__________________________________________________________________________________________________________________________________________________\n");
        //printf("__________________________________________________________________________________________________________________________________________________\n");
    }
    // printf("%f\t%f\n",x0,y0);
    // printf("___________________________________________________________________________________________________________________________________________________\n");
    //printf("TNe value of y is %f\n\n",y);
}