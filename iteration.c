#include <stdio.h>
#include <math.h>
#define e 0.001
#define f(x) (pow(x, 3) - 2 * pow(x, 2) - 4)
#define g(x) pow((2 * pow(x, 2) + 4), (1.0 / 3))
#define dg(x) ((4 * x) / (3 * pow((2 * x * x + 4), (2.0 / 3))))
int main()
{
  float a, b, x0, x1;
  float fa, fb;
  int i = 0;
  printf("Enter the value of a and b: ");
  scanf("%f %f", &a, &b);
  fa = f(a);
  fb = f(b);
  if (fa * fb > 0)
  {
    printf("Incorrect initial guesses.\n");
    return -1;
  }
  else
  {
    x0 = (a + b) / 2;
  }
  if (fabs(dg(a)) < 1 && fabs(dg(b)) < 1)
  {
    do
    {
      x1 = g(x0);
      printf("%d\t %f\n", i, x1);
      if (fabs(x1 - x0) < e)
      {
        printf("Root: %.4f\n", x1);
        break;
      }
      x0 = x1;
      i++;
    } while (1);
  }
  else
  {
    printf("g(x) and dg(x) are not correct for convergence.\n");
  }
  return 0;
}
