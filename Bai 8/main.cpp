//	Câu 8: Xây dựng lớp Mang với các yeu cầu sau:
//	+ Cài đặt hàm nhập xuất(có sử dụng toán tử >>, <<).
//	+ Lấy số phần tử của mảng.
//	+ Lấy giá trị của phần tử thứ i.
//	+ Thêm / xóa một phần tử của mảng.
//	+ Hủy mảng.
//	+ Sắp xếp mảng .
//	+ Tìm phần tử nhỏ nhất.
//	+ Tính tổng các phần tử có trong mảng.


#include<iostream>
#include <algorithm>

using namespace std;

class Mang
{
	private:
		int* arr;
		int size, capacity;
	
	public:
		// Ham mo rong mang khi them gia tri 
		void resize(int newCapacity) 
		{	
			int* newArr = new int[newCapacity];

			for (int i = 0; i < size; i++) 
			{
				newArr[i] = arr[i];
			}
			delete[] arr;
			arr = newArr;
			capacity = newCapacity;
		}

		// Constructor mac dinh

		Mang() : arr(nullptr), size(0), capacity(0) {}

		// Constructor voi kich thuoc ban dau
		Mang(int initialCapacity) : capacity(initialCapacity), size(0)
		{
			arr = new int[capacity];
		}

		// Destructor
		~Mang() { delete[] arr; }


		// Nhap - Xuat
		friend istream& operator>>(istream& in, Mang& m) 
		{
			cout << "Nhap so phan tu: " << endl;
			int n;
			in >> n;

			if (n > m.capacity) { m.resize(n); }
			m.size = n;

			cout << "Nhap cac phan tu: \n" << endl;

			for (int i = 0; i < n; i++) 
			{
				cout << " Phan tu thu " << i << ": ";
				in >> m.arr[i];
			}
			return in;
		}


		friend ostream& operator<<(ostream& out,const Mang& m) 
		{
			out << " [ ";
			for (int i = 0; i < m.size; i++) 
			{
				out << m.arr[i];
				if (i < m.size - 1) out << ", ";
			}
			out << " ] ";

			return out;
		}

		// Lay phan tu cua mang

		int getSize() const 
		{
			return size;
		}

		// lay gia tri phan tu thu i

		int getAt(int index) const 
		{
			if (index < 0 || index >= size) 
			{
				throw out_of_range("Chi so vuot qua pham vi");
			}
			return arr[index];
		}

		// Them phan tu vao vi tri bat ky

		void insert(int index, int value) 
		{
			if (index < 0 || index > size) 
			{
				throw out_of_range(" Chi so khong hop le ");
			}

			if (size == capacity) { resize(capacity == 0 ? 1 : capacity * 2); }

			for (int i = size; i > index; i--) { arr[i] = arr[i - 1]; }

			arr[index] = value;
			size++;
		}

		// xoa phan tu tai vi tri bat ky
		
		void remove(int index) 
		{
			if (index < 0 || index >= size) {
				throw out_of_range("Chi so khong hop le");
			}

			for (int i = index; i < size - 1; i++) {
				arr[i] = arr[i + 1];
			}
			size--;
		}
		
		// Sắp xếp mảng (tăng dần hoặc giảm dần)
        void sort(bool ascending = true) 
		{
			if (ascending) 
			{
				std::sort(arr, arr + size);
			}
			else 
			{
				std::sort(arr, arr + size, std::greater<int>());
			}
        }

		// Tìm phần tử nhỏ nhất
		int findMin() const {
			if (size == 0) 
			{
				throw logic_error("Mang rong");
			}
			return *min_element(arr, arr + size);
		}

		// Tính tổng các phần tử
		int sum() const {
			int total = 0;
			for (int i = 0; i < size; i++) 
			{
				total += arr[i];
			}
			return total;
		}

};

int main() 
{ 
	// Nhập mảng
	Mang m;
	cin >> m;
	cout << "Mang vua nhap: " << m << endl;

	// Thêm phần tử
	m.insert(2, 100);
	cout << "Mang sau khi them 100 vao vi tri 2: " << m << endl;

	// Xóa phần tử
	m.remove(1);
	cout << "Mang sau khi xoa phan tu thu 1: " << m << endl;

	// Sắp xếp tăng dần
	m.sort();
	cout << "Mang sap xep tang dan: " << m << endl;

	// Sắp xếp giảm dần
	m.sort(false);
	cout << "Mang sap xep giam dan: " << m << endl;

	// Tìm phần tử nhỏ nhất
	cout << "Phan tu nho nhat: " << m.findMin() << endl;

	// Tính tổng
	cout << "Tong cac phan tu: " << m.sum() << endl;


	return 0;
}