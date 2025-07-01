#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>
#include <vector>

class DaThuc {
private:
    int N; // Bậc cao nhất
    std::vector<double> data; // hệ số data[k] là hệ số của x^k

public:
    DaThuc();                     // Constructor mặc định
    DaThuc(int n);                // Constructor với bậc
    ~DaThuc();                    // Destructor

    void input();                 // Nhập đa thức
    void print() const;           // Xuất đa thức
    double tinhGiaTri(double x);  // Tính giá trị tại x
    DaThuc daoHam() const;        // Tính đạo hàm
    DaThuc tichPhan() const;      // Tính tích phân (bỏ C)

    DaThuc operator+(const DaThuc&) const;
    DaThuc operator-(const DaThuc&) const;
    DaThuc operator*(const DaThuc&) const;

    double operator[](int k) const; // Truy cập hệ số
    double& operator[](int k);      // Cho phép sửa hệ số

    DaThuc& operator++();           // Tăng tất cả hệ số lên 1 (tiền tố)
    DaThuc& operator--();           // Giảm tất cả hệ số xuống 1 (tiền tố)

    friend std::istream& operator>>(std::istream&, DaThuc&);
    friend std::ostream& operator<<(std::ostream&, const DaThuc&);
};

#endif
