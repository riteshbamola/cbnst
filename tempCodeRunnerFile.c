#include <stdio.h>
#include <math.h>
#define e 0.001
#define f(x) pow(x, 3) - 4 * x + 1 // function definition
#define df(x) 3 * x *x - 4         // Derivative of the function

int main()
{
  float x0, x1; // x0 -> user input   x1-> particular root conatin
  float f0, f1, df0;
  int i = 0;

  printf("Enter x1");
  scanf("%f", &x0);

  do
  {
    f0 = f(x0);
    df0 = df(x0);

    x1 = x0 - (f0 / df0);
    f1 = f(x1);

    x0 = x1;
    i++;

    printf("No. of iteration %d\t", i);
    printf("root %f\t", x1);
    printf("Value of func %f\n", f1);

  } while (fabs(f1) > e);

  printf("Final root found: %f after %d iterations.\n", x1, i);

  // Check if the final value is close to zero
  if (fabs(f1) <= e)
  {
    printf("x0 = %f is a correct root approximation.\n", x1);
  }
  else
  {
    printf("x0 = %f might not be a correct root approximation.\n", x1);
  }
}