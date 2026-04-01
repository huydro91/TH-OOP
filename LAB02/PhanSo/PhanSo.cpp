#include <iostream>
#include "PhanSo.h"
#include <limits>
using namespace std;

// Ham tim Uoc Chung Lon Nhat
// Input: a, b (hai so nguyen)
// Output: UCLN cua a va b
int UCLN (int a, int b) 
{
    a = abs(a);
    b = abs(b);

    while ( b != 0) 
    {
        int r = a % b; // chia lay phan du cua a cho b roi luu vao r, sau do dat a = b, va b = r
        a = b;  // tiep tuc lam nhu the cho den khi b = 0 thi a luc nay chinh la UCLN
        b = r;
    }
    return a;
}

//Hàm nhập vào tử số và mẫu số của một phân số
void PhanSo:: Nhap() {
    while (true)
    {
        cout <<"Nhap tu: ";
        cin >> iTu;
        cout <<"Nhap mau (Khac 0): ";
        cin >> iMau;

        //KT ki tu dac biet
        if ( cin.fail())
        {
            cout <<"Du lieu khong hop le (Ko duoc nhap chu cai hay ki tu dac biet)" << endl;

            cin.clear(); // xoa trang thai loi
            //tuy đã xoá cờ báo lỗi nhưng, nhưng dữ liệu nhập sai vẫn còn lưu trong buff nên cần xoá
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//xoá dữ liệu lỗi
            // nếu ko xoá thì khi nhập lại nó sẽ tiếp tục đọc dữ liệu lỗi
            continue;
        }
        //KT mau so
        if (iMau == 0) {
            cout <<"mau so phai khac khong. Nhap lai mau so\n";
            cin >> iMau;
            break;
        }
        break;
    }
}

//Hàm xuất phân số dưới dạng "tử/mẫu"
void PhanSo:: Xuat() {
    if (iMau ==0) cout <<"Phep tinh nay bi loi" << endl;
    if (iMau ==1) {// Mau =1, thi chi in ra Tu
        cout << iTu << endl;
    }
    else {
        if (iTu ==0) // Tu = 0, thi in ra 0
            cout << 0 << endl;
        else
            cout << iTu <<"/"<< iMau << endl; // TH binh thuong thi in ra Tu/Mau
    }
}

//Hàm rút gọn Phân Số
//Input: Tử số (iTu) và Mẫu số (iMau)
//Output: in ra màn hình phân số đã được rút gọn
void PhanSo:: RutGon() {
    int ucln = UCLN(iTu, iMau);

    iTu = iTu/ucln;
    iMau = iMau/ucln;

    // chuẩn hoá dấu, ưu tiên để dấu trừ ở trước tử số
    if (iMau < 0)
    {
        iTu = -iTu;
        iMau = -iMau;
    }
}
//Hàm Tính Tổng 2 phân số
//Input: Phân Số a(PhanSo a)
//Output: Tổng của 2 phân số
PhanSo PhanSo:: Tinh_Tong(PhanSo a) {
    PhanSo c;
    // Chuẩn hoá quy đồng tử số và mẫu số
    c.iTu = a.iTu*iMau + a.iMau*iTu;
    c.iMau = a.iMau*iMau;
    c.RutGon();
    return c;
}

//Hàm Tính Hiệu 2 phân số
//Input: Phân Số a(PhanSo a)
//Output: Hiệu của 2 phân số
PhanSo PhanSo:: Tinh_Hieu(PhanSo a) {
    PhanSo c;
    // Chuẩn hoá quy đồng tử số và mẫu số
    c.iTu = iTu*a.iMau - a.iTu*iMau;
    c.iMau = a.iMau*iMau;
    c.RutGon();
    return c;
}

//Hàm Tính Tich 2 phân số
//Input: Phân Số a(PhanSo a)
//Output: Tich của 2 phân số
PhanSo PhanSo:: Tinh_Tich(PhanSo a) {
    PhanSo c;
    // Chuẩn hoá quy đồng tử số và mẫu số
    c.iTu = a.iTu*iTu;
    c.iMau = a.iMau*iMau;
    c.RutGon();
    return c;
}

//Hàm Tính Thương 2 phân số
//Input: Phân Số a(PhanSo a)
//Output: Tổng của 2 phân số
PhanSo PhanSo:: Tinh_Thuong(PhanSo a) {
    PhanSo c;
    // Chuẩn hoá quy đồng tử số và mẫu số
    c.iTu = iTu*a.iMau;
    c.iMau = iMau*a.iTu;
    c.RutGon();
    return c;
}

//Hàm So Sánh 2 phân số
//Input: Phân Số a(PhanSo a)
//Output: nếu PS > a (result = 1), PS < a (result = 1), ngược lại PS = a (result =0)
int PhanSo:: SoSanh(PhanSo a) {
    // Chuẩn hoá 2 phân số, để có cùng 1 mẫu số.
    // Quy đồng tử số của 2 phân số.
    long long tu_a = iTu*a.iMau;
    long long tu_b = iMau*a.iTu;
    
    // Kiem Tra
    if ( tu_a > tu_b) return 1;
    else if (tu_a < tu_b) return -1;
    return 0;
}