#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
private:
    int x, y;

public:
    Point2D(int x = 0, int y = 0);

    // Getter methods
    int getX() const;
    int getY() const;

    // Setter methods
    void setX(int x);
    void setY(int y);
    ~Point2D() {} ;
};

#endif
