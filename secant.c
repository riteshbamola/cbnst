#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITER 20
float f(float x)
{
  return x * x * x - 5 * x + 1;
}

void secantMethod(float a, float b, float allowedError, int maxIter)
{
  float x0 = a, x1 = b, x2;
  int iteration = 1;

  printf("iteration no.\t  x\n");

  for (iteration = 1; iteration <= maxIter; iteration++)
  {
    x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
    printf("iteration no.  %2d x=   %.6f\n", iteration, x2);
    if (fabs(x2 - x1) < allowedError)
    {
      printf("after %d iterations, root=  %.6f\n", iteration, x2);
      return;
    }
    x0 = x1;
    x1 = x2;
  }
  printf("after %d iterations, root=  %.6f\n", iteration - 1, x2);
}

int main()
{
  float a, b, allowedError;
  int maxIter;
  printf("Enter the value of a, b, allowed error, maximum iteration:\n");
  scanf("%f %f %f %d", &a, &b, &allowedError, &maxIter);
  secantMethod(a, b, allowedError, maxIter);

  return 0;
}
