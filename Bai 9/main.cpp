/*
	Xây dựng chương trình cho phép thực hiện các thao tác trên ngăn xếp (Stack)
	+ Nhận ngăn xếp.
	+ Xuất ngăn xếp.
	+ Đếm số phần tử trong ngăn xếp.
	+ Đưa phần tử vào ngăn xếp.
	+ Lấy phần tử ra khỏi ngăn xếp.
	+ Làm trống ngăn xếp.
	+ các toán tử: <<,>>
*/

#include <iostream>
using namespace std;

class Stack {
private:
    int* data;      // Mảng động lưu trữ các phần tử
    int capacity;   // Sức chứa tối đa của stack
    int top;        // Vị trí phần tử trên cùng (-1 nếu stack rỗng)

public:
    // Constructor mặc định
    Stack() : data(nullptr), capacity(0), top(-1) {}

    // Constructor với kích thước ban đầu
    Stack(int initialCapacity) : capacity(initialCapacity), top(-1) {
        data = new int[capacity];
    }

    // Destructor
    ~Stack() {
        delete[] data;
    }

    // Copy constructor
    Stack(const Stack& other) : capacity(other.capacity), top(other.top) {
        data = new int[capacity];
        for (int i = 0; i <= top; i++) {
            data[i] = other.data[i];
        }
    }

    // Toán tử gán
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            top = other.top;
            data = new int[capacity];
            for (int i = 0; i <= top; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Kiểm tra stack rỗng
    bool isEmpty() const {
        return top == -1;
    }

    // Kiểm tra stack đầy
    bool isFull() const {
        return top == capacity - 1;
    }

    // Mở rộng sức chứa stack
    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i <= top; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    // Thêm phần tử vào stack (push)
    void push(int value) {
        if (isFull()) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[++top] = value;
    }

    // Lấy phần tử khỏi stack (pop)
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack rong, khong the pop");
        }
        return data[top--];
    }

    // Xem phần tử trên cùng (peek)
    int peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack rong");
        }
        return data[top];
    }

    // Đếm số phần tử trong stack
    int count() const {
        return top + 1;
    }

    // Làm trống stack
    void clear() {
        top = -1;
    }

    // Toán tử nhập >>
    friend istream& operator>>(istream& in, Stack& s) {
        cout << "Nhap so phan tu: ";
        int n;
        in >> n;

        s.clear();
        if (n > s.capacity) {
            s.resize(n);
        }

        cout << "Nhap cac phan tu:\n";
        for (int i = 0; i < n; i++) {
            int value;
            cout << "Phan tu thu " << i << ": ";
            in >> value;
            s.push(value);
        }
        return in;
    }

    // Toán tử xuất <<
    friend ostream& operator<<(ostream& out, const Stack& s) {
        out << "[";
        for (int i = 0; i <= s.top; i++) {
            out << s.data[i];
            if (i < s.top) out << ", ";
        }
        out << "]";
        return out;
    }
};

int main() {
    Stack s;

    // Nhập stack từ bàn phím
    cin >> s;
    cout << "Stack vua nhap: " << s << endl;

    // Thêm phần tử vào stack
    s.push(100);
    cout << "Stack sau khi push 100: " << s << endl;

    // Lấy phần tử ra khỏi stack
    cout << "Pop: " << s.pop() << endl;
    cout << "Stack sau pop: " << s << endl;

    // Xem phần tử trên cùng
    cout << "Phan tu tren cung: " << s.peek() << endl;

    // Đếm số phần tử
    cout << "So phan tu trong stack: " << s.count() << endl;

    // Làm trống stack
    s.clear();
    cout << "Stack sau khi clear: " << s << endl;

    return 0;
}