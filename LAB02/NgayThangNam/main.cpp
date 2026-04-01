#include <iostream>
#include "NgayThangNam.h"

using namespace std;

int main() {
    NgayThangNam a;

    // Nhập dữ liệu cho Ngay-Thang-Nam
    a.Nhap();
    
    //Tính toán ngày tháng năm kế tiếp
    a.NgayThangNamTiepTheo();

    //In ra ngoài màn hình ngày tháng năm
    a.Xuat();

    return 0;
}