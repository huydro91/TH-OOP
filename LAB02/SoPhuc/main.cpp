#include <iostream>
#include "SoPhuc.h"
using namespace std;

int main() {
    SoPhuc a, b;
    //Nhập 2 Số Phức a và b
    cout <<"Nhap So Phuc a:" << endl;
    a.Nhap();
    cout <<"Nhap So Phuc b:" << endl;
    b.Nhap();

    //Tính Toán
    SoPhuc Tong = a.Tinh_Tong(b);
    SoPhuc Hieu = a.Tinh_Hieu(b);
    SoPhuc Tich = a.Tinh_Tich(b);
    SoPhuc Thuong = a.Tinh_Thuong(b);

    // in ra ngoài màn hình
    cout <<"\nTong 2 so phuc: ";
    Tong.Xuat();
    
    cout <<"\nHieu 2 so phuc: ";
    Hieu.Xuat();

    cout <<"\nTich 2 so phuc: ";
    Tich.Xuat();

    cout <<"\nThuong 2 so phuc: ";
    Thuong.Xuat();
    
    return 0;
}