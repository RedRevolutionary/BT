/*
    Câu 4 : Xây dựng lớp Line để biểu diễn các đối tượng đường thẳng
    với thành phần dữ liệu và các hàm như sau:
     a . Thành phần dữ liệu: A (Điểm A) và B (Điểm B) là hai Point
     b . Các hàm:
        + Phương thức thiết lập và phương thức hủy bỏ
        + Hàm void set (int, int ,int ,int) để xác định đoạn thẳng
        + Hàm print() để xuất ra thông tin đường thẳng
        + Hàm void xuatPhuongTrinh() để xuất phương trình đường thẳng
*/

#include <iostream>
#include <cmath>
using namespace std;


class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
};


class Line {
private:
    Point A, B;

public:
    //Line() : A(Point()), B(Point()) {}
    Line() 
    {
        A = Point(0, 0);  // Khởi tạo điểm A tại gốc tọa độ (0,0)
        B = Point(0, 0);  // Khởi tạo điểm B tại gốc tọa độ (0,0)
    }
    //Line(int x1, int y1, int x2, int y2) : A(Point(x1, y1)), B(Point(x2, y2)) {} 
    Line(int x1, int y1, int x2, int y2) 
    {
		A = Point(x1, y1);
		B = Point(x2, y2);
    }

    ~Line() {};

    void set(int x1, int y1, int x2, int y2) {
        A.setX(x1);
        A.setY(y1);
        B.setX(x2);
        B.setY(y2);
    }

    Point getA() const { return A; }
    Point getB() const { return B; }
};


void XuatLine(const Line& line) {
    cout << "Dong di qua A(" << line.getA().getX() << "," << line.getA().getY()
        << ") va B(" << line.getB().getX() << "," << line.getB().getY() << ")" << endl;
}


void XuatPhuongTrinh(const Line& line) {
    int a = line.getB().getY() - line.getA().getY();
    int b = line.getA().getX() - line.getB().getX();
    int c = line.getA().getY() * (line.getB().getX() - line.getA().getX())
        - line.getA().getX() * (line.getB().getY() - line.getA().getY());

    cout << "Phuong Trinh " << a << "x + " << b << "y + " << c << " = 0" << endl;
}

int main() {
    Line line;
    line.set(1, 2, 3, 4);

    XuatLine(line);
    XuatPhuongTrinh(line);

    return 0;
}