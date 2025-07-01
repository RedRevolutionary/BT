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
    int getX() { return x; }
    int getY() { return y; }
    void setX(int value) { x = value; }
    void setY(int value) { y = value; }

    Point(int _x = 0, int _y = 0) { x = _x; y = _y; }
    Point(const Point& p) { x = p.x; y = p.y; }
    ~Point() {}

    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }

    friend ostream& operator<<(ostream& os, Point p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }

    float KhoangCach(Point p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

class Line {
private:
    Point A, B;
public:
    Line() {}
    Line(int x1, int y1, int x2, int y2) : A(x1, y1), B(x2, y2) {}
    ~Line() {}

    void set(int x1, int y1, int x2, int y2) {
        A.setX(x1); A.setY(y1);
        B.setX(x2); B.setY(y2);
    }

    void print() {
        cout << "Doan thang AB voi A" << A << " va B" << B << endl;
    }

    void xuatPhuongTrinh() {
        int a = B.getY() - A.getY();
        int b = A.getX() - B.getX();
        int c = A.getY() * (B.getX() - A.getX()) - A.getX() * (B.getY() - A.getY());

        cout << a << "x + " << b << "y + " << c << " = 0" << endl;
    }

    float TinhDoDai() {
        return A.KhoangCach(B);
    }
};

int main() {
    Point p1, p2;

    cout << "Nhap toa do diem A (x y): ";
    cin >> p1;
    cout << "Nhap toa do diem B (x y): ";
    cin >> p2;

    Line l1;
    l1.set(p1.getX(), p1.getY(), p2.getX(), p2.getY());

    l1.print();
    l1.xuatPhuongTrinh();
    cout << "Do dai doan thang AB: " << l1.TinhDoDai() << endl;

    return 0;
}
