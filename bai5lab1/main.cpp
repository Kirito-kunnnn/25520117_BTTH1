#include <iostream>
#include <iomanip>   // dùng setprecision
#include <cctype>    // kiểm tra ký tự
using namespace std;

// Hàm kiểm tra họ tên hợp lệ (chỉ chữ và khoảng trắng)
bool hopLeTen(string ten) {
    for (int i = 0; i < ten.length(); i++) {
        if (!isalpha(ten[i]) && ten[i] != ' ') {
            return false;
        }
    }
    return !ten.empty();
}
// Hàm nhập điểm hợp lệ (không chữ, trong khoảng 0-10)
double nhapDiem(string mon) {
    double diem;
    while (true) {
        cout << "Nhap diem " << mon << ": ";
        cin >> diem;

        if (cin.fail()) {
            cout << "Nhap sai! Vui long nhap so.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (diem < 0 || diem > 10) {
            cout << "Diem phai tu 0 den 10!\n";
        } else {
            return diem;
        }
    }
}
int main() {
    string hoten;
    double toan, van, dtb;
    // Nhập họ tên
    cin.ignore(); // xóa bộ đệm
    while (true) {
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        if (hopLeTen(hoten)) {
            break;
        } else {
            cout << "Ten khong hop le (khong chua so/ky tu dac biet)!\n";
        }
    }
    // Nhập điểm
    toan = nhapDiem("Toan");
    van = nhapDiem("Van");
    // Tính điểm trung bình
    dtb = (toan + van) / 2;
    // Xuất kết quả (làm tròn 2 chữ số)
    cout << fixed << setprecision(2);
    cout << "\nKet qua:\n";
    cout << "Ho ten: " << hoten << endl;
    cout << "Diem Toan: " << toan << endl;
    cout << "Diem Van: " << van << endl;
    cout << "Diem trung binh: " << dtb << endl;
    return 0;
}
