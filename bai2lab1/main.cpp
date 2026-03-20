#include <iostream>
#include <cstdlib> // dùng abs()
using namespace std;
// Hàm tìm UCLN
int UCLN(int a, int b) {
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}
// Hàm rút gọn phân số
void rutGon(int &tu, int &mau) {
    if (tu == 0) {
        mau = 1;
        return;
    }
    int ucln = UCLN(abs(tu), abs(mau));
    tu /= ucln;
    mau /= ucln;
    // Đưa mẫu về dương
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}
// Hàm nhập phân số (có kiểm tra)
void nhapPhanSo(int &tu, int &mau) {
    // Nhập tử
    while (true) {
        cout << "Nhap tu so: ";
        cin >> tu;

        if (cin.fail()) {
            cout << "Nhap sai! Vui long nhap so nguyen.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    }
    // Nhập mẫu
    while (true) {
        cout << "Nhap mau so: ";
        cin >> mau;

        if (cin.fail()) {
            cout << "Nhap sai! Vui long nhap so nguyen.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (mau == 0) {
            cout << "Mau so phai khac 0!\n";
        } else break;
    }

    rutGon(tu, mau);
}
// Hàm xuất phân số (in 0 nếu tử = 0)
void xuatPhanSo(int tu, int mau) {
    if (tu == 0)
        cout << "0";
    else
        cout << tu << "/" << mau;
}
int main() {
    int tu1, mau1, tu2, mau2;
    cout << "Nhap phan so thu 1:\n";
    nhapPhanSo(tu1, mau1);
    cout << "Nhap phan so thu 2:\n";
    nhapPhanSo(tu2, mau2);
    // Tổng
    int tu_tong = tu1 * mau2 + tu2 * mau1;
    int mau_tong = mau1 * mau2;
    rutGon(tu_tong, mau_tong);
    // Hiệu
    int tu_hieu = tu1 * mau2 - tu2 * mau1;
    int mau_hieu = mau1 * mau2;
    rutGon(tu_hieu, mau_hieu);
    // Tích
    int tu_tich = tu1 * tu2;
    int mau_tich = mau1 * mau2;
    rutGon(tu_tich, mau_tich);
    // Thương
    int tu_thuong = tu1 * mau2;
    int mau_thuong = mau1 * tu2;
    cout << "\nKet qua:\n";
    cout << "Tong: ";
    xuatPhanSo(tu_tong, mau_tong);
    cout << endl;
    cout << "Hieu: ";
    xuatPhanSo(tu_hieu, mau_hieu);
    cout << endl;
    cout << "Tich: ";
    xuatPhanSo(tu_tich, mau_tich);
    cout << endl;
    if (tu2 == 0) {
        cout << "Thuong: Khong xac dinh (chia cho 0)\n";
    } else {
        rutGon(tu_thuong, mau_thuong);
        cout << "Thuong: ";
        xuatPhanSo(tu_thuong, mau_thuong);
        cout << endl;
    }

    return 0;
}
