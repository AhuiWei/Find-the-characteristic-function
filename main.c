#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double N = 1000;
typedef double(*P2Fun)(double);
typedef double(*P2Fun_2args)(double,double);
double integration(P2Fun f,
				   P2Fun_2args k,
				   double a,         /*积分上限*/
				   double b,         /*积分下限*/
				   double x,         /*参变量*/
				   double precision);

int main()
{
	double f(double t);
	double k(double x, double t);
	int precision = N;
	double a,b,t,x;

	printf("Please input the floor of the integration a:\n");
	scanf("%lf",&a);
	printf("Please input the ceiling of the integration b:\n");
	scanf("%lf",&b);
	printf("Please input the value of x:\n");
	scanf("%lf",&x);
	printf("The integration of K(x,y)f(x) from %Lf to %lf is %lf \n",a,b,integration(f,k,a,b,x,precision));
}

double integration(P2Fun f,
				   P2Fun_2args k,
				   double a,
				   double b,
				   double x,
				   double precision)

				  {
					  int j;
					  double sum = 0;
					  double delta = (b-a)/N;
					  for(j = 0;j <= N-1 ;j++)
					  {
						  sum += f(a+j*delta)*k(x,a+j*delta)*delta;
					  }
					  return sum;
				  }

double f(double t)
{
	double f = 0;
	f = t;
	return f;
}

double k(double x, double t)
{
	return x*t;
}
