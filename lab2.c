#include <stdio.h>
#include <math.h>
int main ()
{
  double x;
  printf ("Enter x { -1.0 <= x <= 0.293} -> ");
  scanf ("%lf", &x);
  if (-1.0 <= x && x <= 0.293 )
  {
    double y = acos (( 2 * x ) / ( 1.0 + x * x));
    double z = log (sin( M_PI / y ));
    printf ("y (x) = %lf\nz(y) = %lf\n", y, z);
  }
  else
    printf ("x value is incorrect!\n");
  return 0;
}
