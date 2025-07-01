/*
	Bài 7: Xây dựng lớp Ngay với các yêu cầu sau:
	
	+ Cài đặt hàm nhập xuất (có sử dụng toán tử >>,<<)
	+ Thiết lập các toán tử +,-,++,--,<,>
	+ Kiểm tra hợp lệ ngày nhập vào.
	+ Tìm ngày kế tiếp, tìm ngày trước đó k ngày .
	+ Tính khoảng cách giữa 2 ngày.
	+ Tìm ngày lớn nhất .
*/

#include <iostream>
#include<ctime>
#include<algorithm>

using namespace std;
// Ham kiem tra ngay hop le
class Ngay {
private:

	int ngay, thang, nam;

public:
	// get-set
	int getNgay() { return ngay; }
	int getThang() { return thang; }
	int getNam() { return nam; }

	void setNgay(int n) { ngay = n; }
	void setThang(int t) { thang = t; }
	void setNam(int m) { nam = m; }

	bool LaNamNhuan() const
	{
		return (nam % 400 == 0 || (nam % 100 != 0 && nam % 4 == 0));
	}

	int SoNgayTrongThang() const
	{
		if (thang == 2) return LaNamNhuan() ? 29 : 28;
		if (thang == 4 || thang == 6 || thang == 9 || thang == 11) return 30;
		return 31;
	}

	void ChuanHoa()
	{
		while (ngay > SoNgayTrongThang())
		{
			ngay -= SoNgayTrongThang(); // ngay = ngay - SoNgayTrongThang()
			thang++;
			if (thang > 12)
			{
				thang = 1;
				nam++;
			}
		}

		while (ngay < 1)
		{
			thang--;
			if (thang < 1)
			{
				thang = 12;
				nam--;
			}
			ngay = ngay + SoNgayTrongThang();

		}
	}


	int ChuyenDoiNgay() const
	{
		int m = (thang + 9) % 12; // Thang 1,2 la thang 13,14 cua nam truoc
		int y = nam - m / 10;
		return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (ngay - 1);
	}

	// Constructor 
	Ngay() {}
	// Destructor
	~Ngay() {}

	// Kiem tra ngay hop le

	bool LaNgayHopLe()
	{
		if (nam < 1 || thang < 1 || thang > 12 || ngay < 1 || ngay > SoNgayTrongThang())
		{
			return false; // Ngay khong hop le
		}
		return true; // Ngay hop le
	}

	// Nhap / Xuat
	friend istream& operator>> (istream& is, Ngay& n)
	{

		do
		{
			is >> n.ngay >> n.thang >> n.nam;
			if (!n.LaNgayHopLe())
			{
				cout << "Ngay khong hop le. Vui long nhap lai: ";
			}
		} while (!n.LaNgayHopLe());

		return is;

	}

	friend ostream& operator<< (ostream& os, const Ngay& n)
	{
		os << n.ngay << "/" << n.thang << "/" << n.nam;
		return os;
	}

	// toan tu +, -, ++, --

    Ngay operator+(int soNgay) const
    {
    Ngay kq = *this;
	kq.ngay += soNgay;// ngay = ngay + soNgay
    kq.ChuanHoa();
    return kq;
    }

	Ngay operator-(int soNgay) const
	{
		Ngay kq = *this;
		kq.ngay -= soNgay;// ngay = ngay - soNgay
		kq.ChuanHoa();
		return kq;
	}

    // Toán tử tiền tố ++
    Ngay& operator++() {
    ngay++;
    ChuanHoa();
    return *this;
    }

    // Toán tử hậu tố ++
    Ngay operator++(int) {
    Ngay temp = *this;
    ngay++;
    ChuanHoa();
    return temp;
    }

    // Toán tử tiền tố --
    Ngay& operator--() {
    ngay--;
    ChuanHoa();
    return *this;
    }

    // Toán tử hậu tố --
    Ngay operator--(int) {
    Ngay temp = *this;
    ngay--;
    ChuanHoa();
    return temp;
    }
	// toan tu so sanh <, >
	bool operator<(const Ngay& other) const {
		return ChuyenDoiNgay() < other.ChuyenDoiNgay();
	}
	bool operator>(const Ngay& other) const {
		return ChuyenDoiNgay() > other.ChuyenDoiNgay();
	}

};

int main() 
{
    Ngay n1, n2;
    cout << "Nhap ngay thu nhat (d/m/y): ";
    cin >> n1;
    cout << "Nhap ngay thu hai (d/m/y): ";
    cin >> n2;

    cout << "Ngay thu nhat: " << n1 << endl;
    cout << "Ngay thu hai: " << n2 << endl;

    // Test toán tử +
    int themNgay;
    cout << "Nhap so ngay muon cong vao ngay thu nhat: ";
    cin >> themNgay;
    Ngay n1_cong = n1 + themNgay;
    cout << "Ngay thu nhat sau khi cong " << themNgay << " ngay: " << n1_cong << endl;

    // Test toán tử -
    int truNgay;
    cout << "Nhap so ngay muon tru khoi ngay thu nhat: ";
    cin >> truNgay;
    Ngay n1_tru = n1 - truNgay;
    cout << "Ngay thu nhat sau khi tru " << truNgay << " ngay: " << n1_tru << endl;

    // Test ++, --
    cout << "Ngay thu nhat sau khi ++ (tien to): " << ++n1 << endl;
    cout << "Ngay thu nhat sau khi -- (tien to): " << --n1 << endl;
    cout << "Ngay thu nhat sau khi ++ (hau to): " << n1++ << endl;
    cout << "Ngay thu nhat hien tai: " << n1 << endl;
    cout << "Ngay thu nhat sau khi -- (hau to): " << n1-- << endl;
    cout << "Ngay thu nhat hien tai: " << n1 << endl;

    // So sánh
    if (n1 < n2)
        cout << n1 << " < " << n2 << endl;
    else if (n1 > n2)
        cout << n1 << " > " << n2 << endl;
    else
        cout << n1 << " = " << n2 << endl;

    // Tính khoảng cách giữa 2 ngày
    int khoangCach = abs(n1.ChuyenDoiNgay() - n2.ChuyenDoiNgay());
    cout << "Khoang cach giua hai ngay: " << khoangCach << " ngay" << endl;

    // Tìm ngày lớn nhất
    Ngay maxNgay = (n1 > n2) ? n1 : n2;
    cout << "Ngay lon nhat: " << maxNgay << endl;

    return 0;
}