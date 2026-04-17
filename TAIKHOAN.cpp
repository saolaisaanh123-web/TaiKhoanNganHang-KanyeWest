#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// =================================================
// LOP CO SO: TAI KHOAN
// =================================================
class TaiKhoan {
protected:
    string soTaiKhoan;
    string tenChuTaiKhoan;
    double soDu;

public:
    TaiKhoan(string soTK = "", string tenTK = "", double sd = 0)
        : soTaiKhoan(soTK), tenChuTaiKhoan(tenTK), soDu(sd) {}

    virtual ~TaiKhoan() {}

    string getSoTaiKhoan() const { return soTaiKhoan; }
    double getSoDu() const { return soDu; }

    void NapTien(double soTien) {
        if (soTien > 0)
            soDu += soTien;
        else
            cout << "So tien nap khong hop le!\n";
    }

    virtual bool RutTien(double soTien) = 0;

    virtual void HienThiThongTin() const {
        cout << "------------------------------------------\n";
        cout << left << setw(20) << "So tai khoan:" << soTaiKhoan << endl;
        cout << setw(20) << "Ten chu TK:" << tenChuTaiKhoan << endl;
        cout << setw(20) << "So du:" << fixed << setprecision(2) << soDu << endl;
    }
};

// =================================================
// TAI KHOAN TIET KIEM
// =================================================
class TaiKhoanTietKiem : public TaiKhoan {
private:
    double laiSuat;

public:
    TaiKhoanTietKiem(string soTK, string tenTK, double sd, double ls)
        : TaiKhoan(soTK, tenTK, sd), laiSuat(ls) {}

    bool RutTien(double soTien) override {
        if (soTien <= 0) return false;
        if (soDu - soTien >= 100000) {
            soDu -= soTien;
            return true;
        }
        return false;
    }

    void HienThiThongTin() const override {
        cout << "\n=== TAI KHOAN TIET KIEM ===\n";
        TaiKhoan::HienThiThongTin();
        cout << setw(20) << "Lai suat:" << laiSuat << " %\n";
    }
};

// =================================================
// TAI KHOAN THANH TOAN
// =================================================
class TaiKhoanThanhToan : public TaiKhoan {
private:
    double hanMucTinDung;

public:
    TaiKhoanThanhToan(string soTK, string tenTK, double sd, double hm)
        : TaiKhoan(soTK, tenTK, sd), hanMucTinDung(hm) {}

    bool RutTien(double soTien) override {
        if (soTien <= 0) return false;
        if (soDu - soTien >= -hanMucTinDung) {
            soDu -= soTien;
            return true;
        }
        return false;
    }

    void HienThiThongTin() const override {
        cout << "\n=== TAI KHOAN THANH TOAN ===\n";
        TaiKhoan::HienThiThongTin();
        cout << setw(20) << "Han muc tin dung:" << hanMucTinDung << endl;
    }
};

// =================================================
// CAC HAM HO TRO
// =================================================
bool KiemTraTrungSoTaiKhoan(TaiKhoan* ds[], int soLuong, string soTK) {
    for (int i = 0; i < soLuong; i++) {
        if (ds[i]->getSoTaiKhoan() == soTK)
            return true;
    }
    return false;
}

bool KiemTraViTriHopLe(int viTri, int soLuong) {
    return (viTri >= 0 && viTri < soLuong);
}

void XoaBoDemNhap() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// =================================================
// MENU CHINH
// =================================================
int main() {
    TaiKhoan* ds[10];
    int soLuong = 0;
    int luaChon;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Tao tai khoan tiet kiem\n";
        cout << "2. Tao tai khoan thanh toan\n";
        cout << "3. Nap tien\n";
        cout << "4. Rut tien\n";
        cout << "5. Hien thi tat ca tai khoan\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";

        cin >> luaChon;
        if (cin.fail()) {
            cout << "Du lieu nhap vao khong hop le!\n";
            XoaBoDemNhap();
            continue;
        }

        if (luaChon == 1) {
            if (soLuong >= 10) {
                cout << "Danh sach tai khoan da day, khong the tao them!\n";
                continue;
            }

            string soTK, tenTK;
            double soDu, laiSuat;

            cout << "So tai khoan: ";
            cin >> soTK;

            if (KiemTraTrungSoTaiKhoan(ds, soLuong, soTK)) {
                cout << "So tai khoan da ton tai!\n";
                continue;
            }

            cout << "Ten chu TK: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, tenTK);

            cout << "So du ban dau: ";
            cin >> soDu;
            if (cin.fail() || soDu < 0) {
                cout << "So du ban dau khong hop le!\n";
                XoaBoDemNhap();
                continue;
            }

            cout << "Lai suat: ";
            cin >> laiSuat;
            if (cin.fail() || laiSuat < 0) {
                cout << "Lai suat khong hop le!\n";
                XoaBoDemNhap();
                continue;
            }

            ds[soLuong++] = new TaiKhoanTietKiem(soTK, tenTK, soDu, laiSuat);
            cout << "Tao tai khoan tiet kiem thanh cong!\n";
        }

        else if (luaChon == 2) {
            if (soLuong >= 10) {
                cout << "Danh sach tai khoan da day, khong the tao them!\n";
                continue;
            }

            string soTK, tenTK;
            double soDu, hanMuc;

            cout << "So tai khoan: ";
            cin >> soTK;

            if (KiemTraTrungSoTaiKhoan(ds, soLuong, soTK)) {
                cout << "So tai khoan da ton tai!\n";
                continue;
            }

            cout << "Ten chu TK: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, tenTK);

            cout << "So du ban dau: ";
            cin >> soDu;
            if (cin.fail() || soDu < 0) {
                cout << "So du ban dau khong hop le!\n";
                XoaBoDemNhap();
                continue;
            }

            cout << "Han muc tin dung: ";
            cin >> hanMuc;
            if (cin.fail() || hanMuc < 0) {
                cout << "Han muc tin dung khong hop le!\n";
                XoaBoDemNhap();
                continue;
            }

            ds[soLuong++] = new TaiKhoanThanhToan(soTK, tenTK, soDu, hanMuc);
            cout << "Tao tai khoan thanh toan thanh cong!\n";
        }

        else if (luaChon == 3) {
            if (soLuong == 0) {
                cout << "Chua co tai khoan nao de nap tien!\n";
                continue;
            }

            int i;
            double tien;
            cout << "Nhap vi tri tai khoan (0 -> " << soLuong - 1 << "): ";
            cin >> i;

            if (cin.fail() || !KiemTraViTriHopLe(i, soLuong)) {
                cout << "Vi tri tai khoan khong hop le!\n";
                XoaBoDemNhap();
                continue;
            }

            cout << "So tien nap: ";
            cin >> tien;
            if (cin.fail() || tien <= 0) {
                cout << "So tien nap khong hop le!\n";
                XoaBoDemNhap();
                continue;
            }

            ds[i]->NapTien(tien);
            cout << "Nap tien thanh cong!\n";
        }

        else if (luaChon == 4) {
            if (soLuong == 0) {
                cout << "Chua co tai khoan nao de rut tien!\n";
                continue;
            }

            int i;
            double tien;
            cout << "Nhap vi tri tai khoan (0 -> " << soLuong - 1 << "): ";
            cin >> i;

            if (cin.fail() || !KiemTraViTriHopLe(i, soLuong)) {
                cout << "Vi tri tai khoan khong hop le!\n";
                XoaBoDemNhap();
                continue;
            }

            cout << "So tien rut: ";
            cin >> tien;
            if (cin.fail() || tien <= 0) {
                cout << "So tien rut khong hop le!\n";
                XoaBoDemNhap();
                continue;
            }

            if (ds[i]->RutTien(tien))
                cout << "Rut tien thanh cong!\n";
            else
                cout << "Rut tien THAT BAI!\n";
        }

        else if (luaChon == 5) {
            if (soLuong == 0) {
                cout << "Danh sach tai khoan dang rong!\n";
            } else {
                for (int i = 0; i < soLuong; i++)
                    ds[i]->HienThiThongTin();
            }
        }

        else if (luaChon != 0) {
            cout << "Lua chon khong hop le!\n";
        }

    } while (luaChon != 0);

    for (int i = 0; i < soLuong; i++)
        delete ds[i];

    return 0;
}