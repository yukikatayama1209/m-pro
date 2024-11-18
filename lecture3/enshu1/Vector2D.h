#include <iostream>

class Vector2D{
      private:
            double x;
            double y;
      public:
      Vector2D(double x_cord = 0, double y_cord = 0) : x(x_cord), y(y_cord) {}
      double getX() const {
            return x;
      }

      double getY() const {
            return y;
      }

      double dotProduct(const Vector2D& other) const {
            return (x * other.x) + (y * other.y);
      }
};