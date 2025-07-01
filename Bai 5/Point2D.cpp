#include "Point2D.h"

Point2D::Point2D(int x, int y) : x(x), y(y) {}

int Point2D::getX() const { return x; }
int Point2D::getY() const { return y; }

void Point2D::setX(int x) { this->x = x; }
void Point2D::setY(int y) { this->y = y; }
