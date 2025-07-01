/*

**Câu 3:** Xây dựng các lớp đối tượng và vẽ sơ đồ kế thừa cho các lớp 
cho các lớp sau.

**Lớp MANG1C** để biểu diễn đối tượng là một mảng một chiều các số nguyên gồm 
thành phần dữ liệu và các phương thức sau:

* **Thành phần dữ liệu**:
  ○ `sopt`: là một số nguyên thể hiện số phần tử của mảng.
  ○ `data`: là một mảng các số nguyên có tối đa 100 phần tử.

* **Các phương thức**:
  ○ Phương thức thiết lập và phương thức huỷ bỏ (khởi tạo sopt được cho là -1).
  ○ Phương thức `void input()` để nhập mảng.
  ○ Phương thức `void print()` để xuất mảng.

---

**Lớp STACK** để biểu diễn đối tượng là một ngăn xếp chứa các số nguyên dương 
kế thừa từ lớp **MANG1C** gồm thành phần dữ liệu và các phương thức được mô tả 
như sau:

* **Thành phần dữ liệu**: Không bổ sung gì thêm.

* **Các phương thức**:
  ○ Phương thức thiết lập và phương thức huỷ bỏ (chỉ cần hiện thông báo ra màn hình).
  ○ Phương thức `int isEmpty()` để kiểm tra STACK có rỗng không (nếu sopt = -1 thì STACK rỗng).
  ○ Phương thức `void push(int)` để đưa một số nguyên vào STACK (thêm vào cuối mảng, sopt tăng thêm 1 đơn vị).
  ○ Phương thức `int pop()` lấy một số nguyên ra khỏi STACK (lấy ở cuối mảng, sopt giảm đi 1 đơn vị).

---

**Lớp BINARY** để biểu diễn đối tượng liên quan đến việc chuyển đổi số nhị phân 
được kế thừa từ lớp **STACK** gồm thành phần dữ liệu và các phương thức 
được mô tả như sau:

* **Thành phần dữ liệu**: Không bổ sung gì thêm.

* **Các phương thức**:
  ○ Phương thức thiết lập và phương thức huỷ bỏ 
  (chỉ cần hiện thông báo ra màn hình).
  ○ Phương thức `doiNhiPhan(int n)`: Dùng để đổi số n thành dạng nhị phân 
  và xuất ra màn hình.
*/