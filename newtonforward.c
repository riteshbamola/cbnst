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

float newtonforward(float x[], float y[], float diff[][10], int n, int val)
{
  float u = (val - x[0]) / x[1] - x[0];
  float result = y[0];
  float u1 = u;
  int fact = 1;
  for (int i = 1; i < n; i++)
  {
    result = result + (u1 * diff[0][i] / fact);
    fact *= (i + 1);
    u1 = u1 * (u - i);
  }
  return result;
}
int main()
{

  int n;
  float value;
  printf("Enter the number of data points: ");
  scanf("%d", &n);
  float x[10], y[10], diffTable[10][10];

  printf("Enter the values of x and y: \n");

  for (int i = 0; i < n; i++)
  {
    printf("Enter the value of x[%d]: ", i);
    scanf("%f", &x[i]);
    printf("Enter the value of y[%d]: ", i);
    scanf("%f", &y[i]);

    printf("\n");
  }
}