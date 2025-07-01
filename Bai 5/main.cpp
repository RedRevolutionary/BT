/*
Câu 5:
	Xây dựng lớp TamGiac để biểu diễn các đối tượng tam giác với các thành phần
	dữ liệu và các hàm sau :
		A . Thành phần dữ liệu: A (Diem A) , B (Diem B) , C (Diem C) là
	ba biến từ lớp Point2D
		B. Các hàm:
		+ Phương thức thiết lập và phương thức hủy bỏ.
		+ Hàm void set(int, int, int, int, int, int)
		+ Hàm float tinhChuVi() để tính chu vi tam giác.
		+ Hàm float tinhDienTich() để tính diện tích tam giác.
		+ Hàm void print() để xuất thông tin tam giác.
		+ Hàm int phanLoai() để xác định loại tam giác
		(0: Tam giác thường, 1: tam giác vuông, 2: Tam giác cân, 3: Tam giác vuông cân, 4: Tam giác đều )
*/

#include "TamGiac.h"
#include "Point2D.h"
int main() {
	TamGiac tg1; // Tam giác mặc định
	tg1.set(0, 0, 3, 0, 0, 4); // Tam giác vuông

	std::cout << "Thong tin tam giac:\n";
	tg1.print();
	std::cout << "Chu vi: " << tg1.tinhChuVi() << "\n";
	std::cout << "Dien tich: " << tg1.tinhDienTich() << "\n";
	std::cout << "Loai tam giac: " << tg1.phanLoai() << "\n";

	return 0;
}
