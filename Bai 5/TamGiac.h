#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "Point2D.h"
#include <cmath>
#include<iostream>
using namespace std;
class TamGiac {
private:
    Point2D A, B, C;

    float tinhKhoangCach(const Point2D& p1, const Point2D& p2) const;

public:
    TamGiac();
    TamGiac(int x1, int y1, int x2, int y2, int x3, int y3);
    ~TamGiac();

    void set(int x1, int y1, int x2, int y2, int x3, int y3);

    float tinhChuVi() const;
    float tinhDienTich() const;
    void print() const;
    int phanLoai() const;
};

#endif