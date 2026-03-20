#include <iostream>
using namespace std;
// Hàm tìm UCLN
int UCLN(int a, int b) {
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}
int main() {
    int tu, mau;
    // Nhập tử số (kiểm tra hợp lệ)
    while (true) {
        cout << "Nhap tu so: ";
        cin >> tu;
        // Nếu nhập sai (chữ/ký tự đặc biệt)
        if (cin.fail()) {
            cout << "Nhap sai! Vui long nhap so nguyen.\n";
            cin.clear();              // Xóa trạng thái lỗi
            cin.ignore(1000, '\n');   // Bỏ dữ liệu sai trong bộ nhớ
        } else {
            break; // Nhập đúng thì thoát vòng lặp
        }
    }
    // Nhập mẫu số (kiểm tra hợp lệ + khác 0)
    while (true) {
        cout << "Nhap mau so: ";
        cin >> mau;

        if (cin.fail()) {
            cout << "Nhap sai! Vui long nhap so nguyen.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (mau == 0) {
            cout << "Mau so phai khac 0! Nhap lai.\n";
        } else {
            break;
        }
    }
    // Tìm UCLN
    int ucln = UCLN(abs(tu), abs(mau));
    // Rút gọn
    tu /= ucln;
    mau /= ucln;
    // Đưa mẫu về dương
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
    // Xuất kết quả
    if (tu == 0)
    cout << "0";
else
    cout << tu << "/" << mau;
    return 0;
}
