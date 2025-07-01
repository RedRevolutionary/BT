/*
	Xây dựng lớp DaThuc để biểu diễn các đối tượng đa thức một biến với các thành phần dữ liệu và các hàm sau :
	
    a.) 
    Thành phần dữ liệu:
	    + N là số nguyên biểu diễn lũy thừa cao nhất của x.
	    + Data: là một mảng chứa các hệ số của x( data[k] chứa hệ số của x^k ).

	b.) 
    Các hàm:
	    + Phương thức thiết lập và phương thức hủy bỏ.
	    + Hàm void input() để nhập thông tin cho đa thức.
	    + Hàm void print() để xuất thông tin đa thức.
	    + Toán tử  nhập ( >> ) , xuất ( << ) .
	    + Hàm tính giá trị đa thức.
	    + Hàm tính đạo hàm.
	    + Hàm tính tích phân.
	    + Cài đặt các phép toán + ( cộng 2 đa thức ), -( trừ hai đa thức ), * ( nhân hai đa thức ).
	    + Cài đặt quá tải toán tử [] để trích hệ số thành phần trong đa thức .
	    + Cài đặt quá tải toán tử ++ , -- để nâng (hoặc giảm) các hệ số của đa thức đi 1.

*/

#include <iostream>
#include "DaThuc.h"
using namespace std;
int main() {
    DaThuc A, B;
    // Nhap da thuc A
    cin >> A;
    // Nhap da thuc B
    cin >> B;

    cout << "\nDa thuc A: " << A <<  endl;
    cout << "Da thuc B: " << B <<  endl;

    DaThuc C = A + B;
     cout << "\nA + B = " << C <<  endl;

    DaThuc D = A - B;
     cout << "A - B = " << D <<  endl;

    DaThuc E = A * B;
     cout << "A * B = " << E <<  endl;

    double x;
     cout << "\nNhap gia tri x de tinh A(x): ";
     cin >> x;
     cout << "A(" << x << ") = " << A.tinhGiaTri(x) <<  endl;

     cout << "\nDao ham cua A: " << A.daoHam() <<  endl;
     cout << "Tich phan cua A: " << A.tichPhan() <<  endl;

     cout << "\nHe so bac 2 cua A: " << A[2] <<  endl;

    ++A;
     cout << "\nDa thuc A sau ++: " << A <<  endl;

    --A;
     cout << "Da thuc A sau --: " << A <<  endl;

    return 0;
}
