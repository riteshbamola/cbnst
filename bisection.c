// #include <stdio.h>
// #include <math.h>
// #define e 0.001

// float f(float x)
// {
//   return x * x * x - 4 * x + 1;
// }

// void bisection(float x1, float x2)
// {
//   float x;
//   if (f(x1) * f(x2) >= 0)
//   {
//     printf("Roots cannot be determined");
//   }
//   int it = 0;
//   do
//   {
//     x = (x1 + x2) / 2;
//     if (f(x1) * f(x) < 0)
//     {
//       x2 = x;
//     }
//     else
//     {
//       x1 = x;
//     }
//     printf("Value of root at %d interation = %f \n", it, x);
//     it++;
//   } while (fabs(f(x)) > e);
// }
// int main()
// {

//   float x1 = 1;
//   float x2 = 2;
//   bisection(x1, x2);
// }

#include <stdio.h>
#include <math.h>

#define e 0.001
#define f(x) (pow(x, 3) - 4 * x + 1)

int main()
{
  float x0, x1, x2;
  float f0, f1, f2;
  int i = 0;

  printf("Enter the value of x1,x2: ");
  scanf("%f %f", &x1, &x2);

  f1 = f(x1);
  f2 = f(x2);
  if (f1 * f2 > 0)
  {
    printf("Incorrect inital guess.\n");
    return -1;
  }

  do
  {
    x0 = (x1 + x2) / 2; // Midpoint
    f0 = f(x0);
    if (f1 * f0 < 0)
    {
      x2 = x0;
      f2 = f0;
    }
    else
    {
      x1 = x0;
      f1 = f0;
    }
    i++;
    printf("Iteration %d: ", i);
    printf("Root approximation:%f: ", x0);
    printf("function value at root:%f\n", f0);
  } while (fabs(f0) > e);
  printf("\nFinal root found: %f after %d iteration: \n", x0, i);
}
