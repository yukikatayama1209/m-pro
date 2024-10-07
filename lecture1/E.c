#include <stdio.h>

typedef struct {
      double x;
      double y;
      double radius;
} circle;

int main(){
      circle c;
      scanf("%lf %lf %lf", &c.x, &c.y, &c.radius);

      printf("円の中心座標: (%.2lf, %.2lf)\n", c.x, c.y);
      printf("円の半径: %.2lf\n", c.radius);

      return 0;
}