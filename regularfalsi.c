#include <stdio.h>
#include <math.h>

#define e 0.001

float f(float x)
{
  return (x * x * x - 4 * x + 1);
}

int main()
{
  float x1, x2, x;
  float f0, f1, f2;

  printf("Enter the values of x1 and x2 : ");
  scanf("%f %f", &x1, &x2);

  f1 = f(x1);
  f2 = f(x2);

  if (f1 * f2 > 0)
  {
    printf("Invalid guess");
    return -1;
  }
  int it = 0;
  do
  {
    f1 = f(x1);
    f2 = f(x2);
    x = (x1 * f2 - x2 * f1) / (f2 - f1);
    f0 = f(x);
    if (f0 * f1 < 0)
    {
      x2 = x;
      f2 = f0;
    }
    else
    {
      x1 = x;
      f1 = f0;
    }
    it++;
    printf("Iteration %d Root value = %f Fn value = %f\n", it, x, f0);

  } while (fabs(f0) > e);
  printf("Final root found: %f after %d iterations.\n", x, it);
  return 0;
}

// #include <stdio.h>
// #include <math.h>
// #define e 0.001 // minimum precision value
// #define f(x) (x * x * x - 4 * x + 1)

// int main()
// {
//   int i = 0; // check for iteration
//   float x0, x1, x2;
//   float f0, f1, f2;

//   printf("Enter the value of x1 , x2: ");
//   scanf("%f %f", &x1, &x2);

//   f1 = f(x1);
//   f2 = f(x2);
//   if (f1 * f2 > 0)
//   {
//     printf("Incorrect initial guesses.\n");
//     return -1;
//   }

//   do
//   {
//     f1 = f(x1);
//     f2 = f(x2);

//     // formula use to find x0
//     x0 = x1 - ((x2 - x1) / (f2 - f1)) * f1;
//     f0 = f(x0);

//     if (f1 * f0 < 0)
//     {
//       x2 = x0;
//       f2 = f0;
//     }
//     else
//     {
//       x1 = x0;
//       f1 = f0;
//     }

//     i++; // check for next iteration

//     printf("Number of iteration %d\t ", i);
//     printf("root %f\t ", x0);
//     printf("Value of function %f\n", f0);

//   } while (fabs(f0) > e); // to represent absolute value  and check for tolerance.

//   printf("Final root found: %f after %d iterations.\n", x0, i);
//   return 0;
// }