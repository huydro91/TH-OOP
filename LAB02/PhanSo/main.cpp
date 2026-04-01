#include <iostream>
#include "PhanSo.h"

using namespace std;

int main() {
    PhanSo a, b;
    //Nhập 2 phân số A và B
    cout <<"Nhap phan so A:"<<endl;
    a.Nhap();
    cout <<"Nhap Phan so B:"<<endl;
    b.Nhap();

    cout <<"\nPhan so A: ";
    a.RutGon();
    a.Xuat();

    cout <<"Phan so B: ";
    b.RutGon();
    b.Xuat();

    // Tính Toán
    PhanSo Tong = a.Tinh_Tong(b);
    PhanSo Hieu = a.Tinh_Hieu(b);
    PhanSo Tich = a.Tinh_Tich(b);
    PhanSo Thuong = a.Tinh_Thuong(b);

    cout <<"\nTong 2 phan so: ";
    Tong.Xuat();

    cout <<"Hieu 2 phan so: ";
    Hieu.Xuat();

    cout <<"Tich 2 phan so: ";
    Tich.Xuat();

    cout <<"Thuong 2 phan so: ";
    Thuong.Xuat();

    //So sanh
    int temp = a.SoSanh(b);
    if (temp ==1)
        cout <<"A > B";
    else if (temp == -1)
        cout <<"A < B";
    else
        cout <<"A = B";

    return 0;
}