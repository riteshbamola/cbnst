#include <stdio.h>
float lagrangeInterpolation(float x[], float y[], int n, float value)
{
  float result = 0.0;
  for (int i = 0; i < n; i++)
  {
    float term = y[i];
    for (int j = 0; j < n; j++)
    {
      if (i != j)
        term = term * (value - x[j]) / (x[i] - x[j]);
    }
    result += term;
  }
  return result;
}
int main()
{
  int n;
  float value;
  printf("Enter the number of data points: ");
  scanf("%d", &n);
  float x[10], y[10];
  printf("Enter the values of x and y:\n");
  for (int i = 0; i < n; i++)
  {
    printf("x[%d] = ", i);
    scanf("%f", &x[i]);
    printf("y[%d] = ", i);
    scanf("%f", &y[i]);
  }
  printf("Enter the value to interpolate: ");
  scanf("%f", &value);
  float result = lagrangeInterpolation(x, y, n, value);
  printf("The interpolated value at %.2f is %.6f\n", value, result);

  return 0;
}
