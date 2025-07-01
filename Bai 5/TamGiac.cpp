#include "TamGiac.h"
#include <iostream>

TamGiac::TamGiac() : A(), B(), C() {}

TamGiac::TamGiac(int x1, int y1, int x2, int y2, int x3, int y3)
    : A(x1, y1), B(x2, y2), C(x3, y3) {
}

TamGiac::~TamGiac() {}

void TamGiac::set(int x1, int y1, int x2, int y2, int x3, int y3) {
    A.setX(x1); A.setY(y1);
    B.setX(x2); B.setY(y2);
    C.setX(x3); C.setY(y3);
}

float TamGiac::tinhKhoangCach(const Point2D& p1, const Point2D& p2) const {
    return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}

float TamGiac::tinhChuVi() const {
    float a = tinhKhoangCach(B, C);
    float b = tinhKhoangCach(A, C);
    float c = tinhKhoangCach(A, B);
    return a + b + c;
}

float TamGiac::tinhDienTich() const {
    float a = tinhKhoangCach(B, C);
    float b = tinhKhoangCach(A, C);
    float c = tinhKhoangCach(A, B);
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void TamGiac::print() const {
    std::cout << "Tam giac co 3 dinh:\n";
    std::cout << "A(" << A.getX() << "," << A.getY() << ")\n";
    std::cout << "B(" << B.getX() << "," << B.getY() << ")\n";
    std::cout << "C(" << C.getX() << "," << C.getY() << ")\n";
}

int TamGiac::phanLoai() const {
    float a = tinhKhoangCach(B, C);
    float b = tinhKhoangCach(A, C);
    float c = tinhKhoangCach(A, B);

    // Kiểm tra điều kiện các loại tam giác
    // ... (phần này bạn tự hoàn thiện theo yêu cầu)

    return 0; // Tam giác thường
}