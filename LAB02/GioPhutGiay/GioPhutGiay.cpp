#include <iostream>
#include <limits>
#include "GioPhutGiay.h"

using namespace std;

//Khai bao ham
bool KT_GioPhutGiay( int h, int m, int s);

//Hàm KT giờ-phút-giây nhập
//Input: h,m,s (int)
//Output: 1-nếu dữ liệu đúng yêu cầu, 0-nếu dữ liệu sai
bool KT_GioPhutGiay( int h, int m, int s)
{
    // KT giay
    if ( s <0 || s > 59) return false;

    // KT Phut
    if ( m < 0 || m > 59) return false;

    // KT Gio
    if ( h < 0 || h > 23) return false;

    return true; // neu cac du lieu dung het thi tra ve true
}

//Hàm nhập vào giờ phút giây từ bàn phím để khởi tạo giá trị cho iGio-iPhut-iGiay
void GioPhutGiay:: Nhap() {
    while (true) {
        cout << "Nhap Gio: "; cin >> iGio;
        cout << "Nhap Phut: "; cin >> iPhut;
        cout<< "Nhap Giay: "; cin >> iGiay;

        // tien hanh kiem tra du lieu Gio-Phut-giay
        // Kiểm tra xem cin có bị lỗi (nhập chữ) hoặc dữ liệu ngày tháng không hợp lệ không
        if (cin.fail() || ! KT_GioPhutGiay(iGio, iPhut, iGiay)) {
            cout << "Du lieu KHONG HOP LE (co the do nhap chu hoac sai Gio Phut Giay)!\n";
            
            cin.clear(); // Xóa trạng thái lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa sạch bộ đệm đến tận dấu xuống dòng
            
            cout << "Hay nhap lai Gio-Phut-Giay.\n";
        } else {
            break; // Dữ liệu đúng thì thoát vòng lặp
        }
    }
}

//Hàm in ra màn hình giờ phút giây, theo định dạng: Gio:Phut:Giay
void GioPhutGiay:: Xuat() {
    cout << "Bay gio la:" << endl;
    // nếu giờ < 10 thì in ra số '0' phía trước giờ
    if (iGio < 10)
        cout << "0" << iGio <<":";
    else cout << iGio <<":";

    // nếu phút < 10 thì in ra số '0' phía trước phút
    if (iPhut < 10)
        cout << "0" << iPhut <<":";
    else cout << iPhut <<":";

    // nếu giây < 10 thì in ra số '0' phía trước giây
    if (iGiay < 10)
        cout << "0" << iGiay;
    else cout << iGiay;
}

//Hàm Tính cộng thêm 1 giây
//Input: Giờ Phút Giây hiện tại
//Output: cập nhật Giờ Phút Giây sau khi đã cộng thêm một giây
void GioPhutGiay:: TinhCongThemMotGiay() {

    if (iGiay < 59) { // nếu số giây < hơn 59 giây
        iGiay++; // thì cộng thêm 1 giây
    }
    else { // nếu giây hiện tại = 59 giây
        if (iPhut < 59) { // nếu số phút < 59 phút, reset số giây =0
            iGiay = 0;
            iPhut++; // tăng số phút thêm 1
        }
        else { // nếu số phút = 59 phút, reset số giây = 0, reset số phút = 0
            iGiay = 0; 
            iPhut = 0;
            iGio++; // tăng số giờ thêm 1
            if (iGio == 24) // nếu số giờ = 24 giờ thì reset giờ bằng 0
                iGio =0; 
        }
    }
}