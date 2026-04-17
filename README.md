# TaiKhoanNganHang-KanyeWest
demo TAI KHOAN NGAN HANG - Nhóm KANYE WEST
# Hệ Thống Quản Lý Tài Khoản Ngân Hàng

## Giới thiệu
Đây là chương trình C++ mô phỏng **hệ thống quản lý tài khoản ngân hàng** theo hướng **lập trình hướng đối tượng (OOP)**.  
Chương trình cho phép người dùng tạo và quản lý hai loại tài khoản:

- **Tài khoản tiết kiệm**
- **Tài khoản thanh toán**

Ngoài ra, chương trình còn hỗ trợ các chức năng cơ bản như:

- Tạo tài khoản
- Nạp tiền
- Rút tiền
- Hiển thị thông tin tài khoản

---

## Mục tiêu của chương trình
Dự án được xây dựng nhằm:

- Minh họa cách áp dụng **lớp cơ sở**, **lớp dẫn xuất**
- Sử dụng **kế thừa**
- Sử dụng **hàm ảo** và **đa hình**
- Quản lý dữ liệu tài khoản bằng con trỏ lớp cơ sở
- Xử lý nhập liệu và kiểm tra dữ liệu hợp lệ

---

## Các lớp trong chương trình

### 1. Lớp `TaiKhoan`
Đây là **lớp cơ sở trừu tượng**, chứa các thông tin chung của một tài khoản ngân hàng:

- `soTaiKhoan`: Số tài khoản
- `tenChuTaiKhoan`: Tên chủ tài khoản
- `soDu`: Số dư hiện tại

#### Các chức năng chính:
- `NapTien(double soTien)`: nạp tiền vào tài khoản
- `RutTien(double soTien)`: hàm ảo thuần túy, được cài đặt ở lớp con
- `HienThiThongTin()`: hiển thị thông tin tài khoản

---

### 2. Lớp `TaiKhoanTietKiem`
Lớp này kế thừa từ `TaiKhoan`, dùng để biểu diễn **tài khoản tiết kiệm**.

#### Thuộc tính bổ sung:
- `laiSuat`: lãi suất của tài khoản

#### Quy tắc rút tiền:
- Chỉ được rút khi:
  - số tiền rút > 0
  - sau khi rút, số dư còn lại **ít nhất 100000**

---

### 3. Lớp `TaiKhoanThanhToan`
Lớp này kế thừa từ `TaiKhoan`, dùng để biểu diễn **tài khoản thanh toán**.

#### Thuộc tính bổ sung:
- `hanMucTinDung`: hạn mức cho phép âm tài khoản

#### Quy tắc rút tiền:
- Chỉ được rút khi:
  - số tiền rút > 0
  - sau khi rút, số dư không nhỏ hơn `-hanMucTinDung`

---

## Chức năng của chương trình

Chương trình có menu gồm các lựa chọn:

1. Tạo tài khoản tiết kiệm  
2. Tạo tài khoản thanh toán  
3. Nạp tiền  
4. Rút tiền  
5. Hiển thị tất cả tài khoản  
0. Thoát  

---

## Kiến thức OOP được sử dụng

### Kế thừa
- `TaiKhoanTietKiem` và `TaiKhoanThanhToan` kế thừa từ `TaiKhoan`

### Đa hình
- Sử dụng con trỏ `TaiKhoan*` để quản lý nhiều loại tài khoản khác nhau
- Gọi `RutTien()` và `HienThiThongTin()` theo đúng loại tài khoản thực tế

### Hàm ảo
- `RutTien()` là hàm ảo thuần túy trong lớp cơ sở
- `HienThiThongTin()` là hàm ảo để có thể ghi đè ở lớp con

### Đóng gói
- Dữ liệu được đặt trong lớp
- Các thao tác được thực hiện thông qua phương thức của lớp

---

## Cấu trúc chương trình

```cpp
class TaiKhoan
class TaiKhoanTietKiem : public TaiKhoan
class TaiKhoanThanhToan : public TaiKhoan
