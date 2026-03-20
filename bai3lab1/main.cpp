#include <iostream>
#include <cstdlib>
using namespace std;

// Hàm tìm UCLN
int UCLN(int a, int b) {
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}
// Hàm rút gọn
void rutGon(int &tu, int &mau) {
    if (tu == 0) {
        mau = 1;
        return;
    }

    int ucln = UCLN(abs(tu), abs(mau));
    tu /= ucln;
    mau /= ucln;

    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}
// Hàm nhập
void nhapPhanSo(int &tu, int &mau) {
    while (true) {
        cout << "Nhap tu so: ";
        cin >> tu;

        if (cin.fail()) {
            cout << "Nhap sai! Vui long nhap so nguyen.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    }

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
// Hàm xuất
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
    cout << "\nPhan so 1: ";
    xuatPhanSo(tu1, mau1);
    cout << "\nPhan so 2: ";
    xuatPhanSo(tu2, mau2);
    // So sánh bằng nhân chéo
    int left = tu1 * mau2;
    int right = tu2 * mau1;
    cout << "\n\nKet qua so sanh:\n";
    if (left > right) {
        xuatPhanSo(tu1, mau1);
        cout << " > ";
        xuatPhanSo(tu2, mau2);
    }
    else if (left < right) {
        xuatPhanSo(tu1, mau1);
        cout << " < ";
        xuatPhanSo(tu2, mau2);
    }
    else {
        xuatPhanSo(tu1, mau1);
        cout << " = ";
        xuatPhanSo(tu2, mau2);
    }
    cout << endl;
    return 0;
}
