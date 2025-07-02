/*
	Bài 10 : Giả sử ta cần tính toán trên các số có dạng a+b*sqrt(7)
	với a,b là các số nguyên. Các thao tác trên kiểu số này bao gồm :
	+ nhập, xuất, phép cộng, phép trừ, phép đổi dấu, phép nhân.

	- bạn hãy khai báo lớp đối tượng và các thao tác cho kiểu số này .
	- Hãy cài đặt mã cho các thao tác kể trên .
*/


#include <iostream>
#include <cmath>
using namespace std;

class SoCanBacHai {
private:
    int a;  // Phần nguyên
    int b;  // Hệ số của √7

public:
    // Constructor mặc định
    SoCanBacHai(int a = 0, int b = 0) : a(a), b(b) {}

    // Nhập số
    friend istream& operator>>(istream& in, SoCanBacHai& num) {
        cout << "Nhap phan nguyen a: ";
        in >> num.a;
        cout << "Nhap he so cua sqrt(7) (b): ";
        in >> num.b;
        return in;
    }

    // Xuất số
    friend ostream& operator<<(ostream& out, const SoCanBacHai& num) {
        if (num.b == 0) {
            out << num.a;
        }
        else {
            if (num.a != 0) {
                out << num.a;
                if (num.b > 0) out << "+";
            }
            if (num.b == -1) out << "-";
            else if (num.b != 1) out << num.b;
            out << "sqrt(7)";
        }
        return out;
    }

    // Phép cộng
    SoCanBacHai operator+(const SoCanBacHai& other) const 
    {
        return SoCanBacHai(a + other.a, b + other.b);
    }

    // Phép trừ
    SoCanBacHai operator-(const SoCanBacHai& other) const 
    {
        return SoCanBacHai(a - other.a, b - other.b);
    }

    // Phép đổi dấu
    SoCanBacHai operator-() const 
    {
        return SoCanBacHai(-a, -b);
    }

    // Phép nhân
    SoCanBacHai operator*(const SoCanBacHai& other) const 
    {
        // (a1 + b1√7) * (a2 + b2√7) = (a1a2 + 7b1b2) + (a1b2 + a2b1)√7
        int new_a = a * other.a + 7 * b * other.b;
        int new_b = a * other.b + b * other.a;
        return SoCanBacHai(new_a, new_b);
    }

    // Tính giá trị thực (double) của số
    double giaTriThuc() const {
        return a + b * sqrt(7);
    }
};

int main() {
    SoCanBacHai num1, num2;

    cout << "Nhap so thu nhat:\n";
    cin >> num1;

    cout << "Nhap so thu hai:\n";
    cin >> num2;

    cout << "\nSo thu nhat: " << num1 << " ≈ " << num1.giaTriThuc() << endl;
    cout << "So thu hai: " << num2 << " ≈ " << num2.giaTriThuc() << endl;

    SoCanBacHai tong = num1 + num2;
    cout << "Tong: " << tong << " ≈ " << tong.giaTriThuc() << endl;

    SoCanBacHai hieu = num1 - num2;
    cout << "Hieu: " << hieu << " ≈ " << hieu.giaTriThuc() << endl;

    SoCanBacHai tich = num1 * num2;
    cout << "Tich: " << tich << " ≈ " << tich.giaTriThuc() << endl;

    SoCanBacHai doiDau = -num1;
    cout << "Doi dau so thu nhat: " << doiDau << " ≈ " << doiDau.giaTriThuc() << endl;

    return 0;
}