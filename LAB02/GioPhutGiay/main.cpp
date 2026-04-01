#include <iostream>
#include "GioPhutGiay.h"

using namespace std;

int main() {
    GioPhutGiay a;
    //Nhập dữ liệu cho Gio Phut Giay
    a.Nhap();

    //Tính cộng thêm 1 giây vào bộ giờ hiện tại
    a.TinhCongThemMotGiay();

    //in ra màn hình Gio Phut Giay
    a.Xuat();

}