#include <stdio.h>
#include <math.h>

void difftable(float y[], float diff[][11], int n, int val)
{
  for (int i = 0; i < n; i++)
  {
    diff[0][i] = y[i];
  }
  for (int j = 1; j < n; j++)
  {
    for (int i = 0; i < n - j; i++)
    {
      diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
    }
  }
}
float newtonbackward(float x[], float y[], float diff[][10], int n, int val)
{
  float result = diff[n - 1][0];
  float u = (val - x[n - 1]) / (x[1] - x[0]);
  float u1 = u;
  int fact = 1;
  for (int i = 1; i < n; i++)
  {
    result = result + (u1 * diff[n - 1][i]) / fact;
    fact *= (i + 1);
    u1 = u1 * (u - i);
  }
}