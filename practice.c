// bisection
#include <stdio.h>
#include <math.h>

#define e 0.001

float f(float x)
{
  return x * x * x - 4 * x + 1;
}
float df(float x)
{
  return 3 * x * x - 4;
}
int main()
{
  float x1;
  float x0;
  printf("Enter the initial guess");
  scanf("%f", &x0);
  int it = 1;
  float h = f(x0) / df(x0);
  do
  {
    h = f(x0) / df(x0);
    x1 = x0 - h;
    x0 = x1;
    printf("Iteration %d value of x0 = %f\n", it, x0);
    it++;

  } while (fabs(f(x0)) > e);

  printf("Root = %f", x0);
  return 0;
}