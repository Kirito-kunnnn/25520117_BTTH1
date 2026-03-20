#include <iostream>
using namespace std;
// Hàm kiểm tra năm nhuận
bool laNamNhuan(int nam) {
    return (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0));
}
// Hàm trả về số ngày trong tháng
int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return laNamNhuan(nam) ? 29 : 28;
        default:
            return 0;
    }
}
// Hàm kiểm tra ngày hợp lệ
bool hopLe(int ngay, int thang, int nam) {
    if (nam < 1 || thang < 1 || thang > 12)
        return false;
    if (ngay < 1 || ngay > soNgayTrongThang(thang, nam))
        return false;
    return true;
}
// Hàm nhập số nguyên an toàn
int nhapSo(string ten) {
    int x;
    while (true) {
        cout << "Nhap " << ten << ": ";
        cin >> x;

        if (cin.fail()) {
            cout << "Nhap sai! Vui long nhap so nguyen.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            return x;
        }
    }
}
int main() {
    int ngay, thang, nam;
    // Nhập và kiểm tra hợp lệ
    while (true) {
        cout << "\nNhap ngay thang nam:\n";
        ngay = nhapSo("ngay");
        thang = nhapSo("thang");
        nam = nhapSo("nam");
        if (hopLe(ngay, thang, nam)) {
            break;
        } else {
            cout << "Ngay khong hop le! Nhap lai.\n";
        }
    }
    // Tìm ngày kế tiếp
    ngay++;
    if (ngay > soNgayTrongThang(thang, nam)) {
        ngay = 1;
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }
    // Xuất kết quả
    cout << "\nNgay ke tiep la: "
         << ngay << "/" << thang << "/" << nam << endl;
    return 0;
}
