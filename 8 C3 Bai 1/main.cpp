/*
	Xây dụng lớp TamGiacDeu (tam giác đều) kế thừa từ lớp TamGiac( tam giác )
	với thành phần dữ liệu tương ứng số đo 3 cạnh và phương thức tính
	chu vi, diện tích.
*/

#include <iostream>
#include <cmath>
using namespace std;

class TamGiac {
protected:
    double a, b, c; // Độ dài 3 cạnh

public:
    // Constructor
    TamGiac(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}

    // Nhập độ dài 3 cạnh
    virtual void nhap() {
        cout << "Nhap do dai 3 canh: ";
        cin >> a >> b >> c;
    }

    // Kiểm tra tam giác hợp lệ
    virtual bool hopLe() const {
        return (a + b > c) && (a + c > b) && (b + c > a) && (a > 0) && (b > 0) && (c > 0);
    }

    // Tính chu vi
    virtual double chuVi() const {
        if (!hopLe()) return 0;
        return a + b + c;
    }

    // Tính diện tích (dùng công thức Heron)
    virtual double dienTich() const {
        if (!hopLe()) return 0;
        double p = chuVi() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    // Xuất thông tin
    virtual void xuat() const {
        cout << "Tam giac co 3 canh: " << a << ", " << b << ", " << c << endl;
        cout << "Chu vi: " << chuVi() << endl;
        cout << "Dien tich: " << dienTich() << endl;
    }
};

class TamGiacDeu : public TamGiac {
public:
    // Constructor
    TamGiacDeu(double canh = 0) : TamGiac(canh, canh, canh) {}

    // Nhập độ dài 1 cạnh (override)
    void nhap() override {
        cout << "Nhap do dai canh tam giac deu: ";
        cin >> a;
        b = c = a; // Cả 3 cạnh bằng nhau
    }

    // Kiểm tra tam giác đều hợp lệ (override)
    bool hopLe() const override {
        return (a == b) && (b == c) && (a > 0);
    }

    // Tính diện tích tam giác đều (tối ưu hơn)
    double dienTich() const override {
        if (!hopLe()) return 0;
        return (sqrt(3) / 4) * a * a; // Công thức đặc biệt cho tam giác đều
    }

    // Xuất thông tin (override)
    void xuat() const override {
        cout << "Tam giac deu co canh: " << a << endl;
        cout << "Chu vi: " << chuVi() << endl;
        cout << "Dien tich: " << dienTich() << endl;
    }
};

int main() {
    // Test TamGiac
    TamGiac tg;
    cout << "Nhap tam giac thuong:\n";
    tg.nhap();
    if (tg.hopLe()) {
        tg.xuat();
    }
    else {
        cout << "Tam giac khong hop le!\n";
    }

    // Test TamGiacDeu
    TamGiacDeu tgd;
    cout << "\nNhap tam giac deu:\n";
    tgd.nhap();
    if (tgd.hopLe()) {
        tgd.xuat();
    }
    else {
        cout << "Tam giac deu khong hop le!\n";
    }

    // Đa hình
    TamGiac* p = new TamGiacDeu();
    cout << "\n Da hinh:\n";
    p->nhap();
    p->xuat();
    delete p;

    return 0;
}