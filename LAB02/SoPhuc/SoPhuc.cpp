#include <iostream>
#include <cmath>
#include "SoPhuc.h"
#include <limits>

using namespace std;

// Nhập phần thực và phần ảo từ bàn phím để khởi tạo số phức
void SoPhuc:: Nhap() {
    while (true) {
        cout <<"Nhap Phan Thuc: ";
        cin >> iThuc;
        cout <<"Nhap Phan Ao: ";
        cin >> iAo;

        // KT kí tự đặc biệt
        if ( cin.fail())
        {
            cout <<"Du lieu khong hop le (Ko duoc nhap chu cai hay ki tu dac biet)" << endl;

            cin.clear(); // xoa trang thai loi
            //tuy đã xoá cờ báo lỗi nhưng, nhưng dữ liệu nhập sai vẫn còn lưu trong buff nên cần xoá
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//xoá dữ liệu lỗi
            // nếu ko xoá thì khi nhập lại nó sẽ tiếp tục đọc dữ liệu lỗi
            continue;
        }
        break;
    }
}

// Xuất số phức với định dạng tối ưu dấu (ví dụ: 3 - 4i thay vì 3 + -4i)
void SoPhuc:: Xuat() {
    if (iAo >= 0) {
        if (iAo == 1) // nếu iAo = 1 thì chỉ cần in ra i thôi
            cout << iThuc << " + " << "i" << endl;
        else
            cout << iThuc << " + " << iAo << "i" << endl;
    } else {
        // Nếu ảo âm, ví dụ -5, nó sẽ in ra: 3 - 5i (thay vì 3 + -5i)
        if (abs(iAo) ==1) // nếu abs(iAo) = 1 thì chỉ cầ in ra i thôi
            cout << iThuc << " - " << "i" << endl;
        else
            cout << iThuc << " - " << abs(iAo) << "i" << endl;
    }
}

// Tính tổng của số phức hiện tại với một số phức b khác
// Trả về: Một đối tượng SoPhuc mới là kết quả của phép cộng
SoPhuc SoPhuc:: Tinh_Tong(SoPhuc b) {
    // A - B = (a1 - b1, a2 - b2)
    SoPhuc c;
    c.iThuc = iThuc + b.iThuc;
    c.iAo = iAo + b.iAo;
    return c;
}

// Tính Hiệu của số phức hiện tại với một số phức b khác
// Trả về: Một đối tượng SoPhuc mới là kết quả của phép hiệu
SoPhuc SoPhuc:: Tinh_Hieu(SoPhuc b) {
    // A - B = (a1 - b1, a2 - b2)
    SoPhuc c;
    c.iThuc = iThuc - b.iThuc;
    c.iAo = iAo - b.iAo;
    return c;
}

// Tính tích của số phức hiện tại với một số phức b khác
// Trả về: Một đối tượng SoPhuc mới là kết quả của phép tích
SoPhuc SoPhuc:: Tinh_Tich(SoPhuc b) {
    SoPhuc c;
    // Phần thực: a1*b1 - a2*b2
    c.iThuc = iThuc*b.iThuc - iAo*b.iAo;

    // Phần ảo: a1*b2 + a2*b1
    c.iAo = iThuc*b.iAo + iAo*b.iThuc;

    return c;
}


// Tính thương của số phức hiện tại với một số phức b khác
// Trả về: Một đối tượng SoPhuc mới là kết quả của phép chia
SoPhuc SoPhuc:: Tinh_Thuong(SoPhuc b) {
    SoPhuc c;

    double mauSo = (double)b.iThuc * b.iThuc + (double)b.iAo * b.iAo;

    if (mauSo == 0) {
        cout << "Loi: Khong the chia cho so phuc 0!" << endl;
        cout << "Ta quy dinh Phan Thuc va Phan Ao dong thoi bang 0" << endl;
        c.iThuc =0; c.iAo =0;
        return c; 
    }
    
    // Tính toán và ép kiểu trực tiếp để giữ phần thập phân (nếu thuộc tính là double)
    c.iThuc = ((double)iThuc * b.iThuc + (double)iAo * b.iAo) / mauSo;
    c.iAo = ((double)b.iThuc * iAo - (double)iThuc * b.iAo) / mauSo;
    
    return c;
}