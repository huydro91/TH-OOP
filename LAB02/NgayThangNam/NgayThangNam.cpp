#include <iostream>
#include <limits>
#include "NgayThangNam.h"

using namespace std;
// day: ngày, month: tháng, year: năm

//khai báo các hàm sử dụng
bool kiemtra_ngaynhap(int day, int month, int year);// ham KT tra Ngay Thang Nam Nhap
bool Kiemtra_namNhuan( int year);// Ham kiem tra nam nhuan
int soNgay_trong_Thang(int month, int year);// Ham tra ve so ngay trong 1 thang

// Ham tra ve so ngay trong 1 thang
// Input: month (thang), year (nam)
// Output: so ngay cua thang do
int soNgay_trong_Thang(int month, int year)
{
    switch ( month )
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;// nếu các tháng nhập vào thuộc trường hợp này sẽ trả về giá trị 31 ngày

        case 4: case 6: case 9: case 11:
        return 30;// nếu các tháng nhập vào thuộc trường hợp này sẽ trả về giá trị 30 ngày

        case 2:
            if (Kiemtra_namNhuan(year))
                return 29; // nếu hàm KT năm nhuận trả về kq true, thì tháng 2 này sẽ trả về giá trị 29
            else
                return 28;
        default:
            return -1; // tháng không hợp lệ
    }
}

//Ham: KT Ngay Thang Nam Nhập
//Input: day, month, year (kiểu dữ liệu int)
bool kiemtra_ngaynhap(int day, int month, int year)
{
    if ( year < 1 || year > 9999) return false;

    if ( month  < 1 || month > 12) return false;

    int maxday = soNgay_trong_Thang(month, year);// tìm số ngày của tháng đó và lưu vào biến maxday

    if ( day <1 || day > maxday) return false;

    return true;
}

//Hàm KT Năm Nhuận
//Input: year (int)
//Output: 1 (nếu đó là năm nhuận), 0 (nếu đó không phải năm nhuận)
bool Kiemtra_namNhuan( int year)
{
    return (year % 400 ==0) || (year % 4==0 && year % 100 != 0);
}

//Hàm Nhập vào ngày tháng năm từ bàn phím để khởi tạo giá trị iNgay-iThang-iNam
void NgayThangNam:: Nhap() {

    while (true) {
        cout << "Nhap Ngay: "; cin >> iNgay;
        cout << "Nhap Thang: "; cin >> iThang;
        cout << "Nhap Nam: "; cin >> iNam;

        // Kiểm tra xem cin có bị lỗi (nhập chữ) hoặc dữ liệu ngày tháng không hợp lệ không
        if (cin.fail() || !kiemtra_ngaynhap(iNgay, iThang, iNam)) {
            cout << "Du lieu KHONG HOP LE (co the do nhap chu hoac sai Ngay Thang Nam)!\n";
            
            cin.clear(); // Xóa trạng thái lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa sạch bộ đệm đến tận dấu xuống dòng
            
            cout << "Hay nhap lai Ngay-Thang-Nam.\n";
        } else {
            break; // Dữ liệu đúng thì thoát vòng lặp
        }
    }
}

// Ham NgayThangNamTiepTheo
// Input: day, month, year (ở hiện tại)
// Output: ngay ke tiep
void NgayThangNam:: NgayThangNamTiepTheo ()
{
    int ngay = soNgay_trong_Thang(iThang, iNam); // lưu số ngày của tháng này vào biến ngày

    if (iNgay < ngay) 
    {//TH: nếu ngày hiện tại bé hơn số ngày của tháng
        iNgay++; // cộng thêm 1 ngày
    }
    else { //TH: nếu ngày hiện tại = ngày của tháng
        if ( iThang < 12)
        {// KT xem tháng có thuộc từ tháng 1 đến tháng 11 không

            iNgay = 1;// nếu có thì reset Ngay =1
            iThang++; // cộng thêm 1 tháng
        }
        else { // nếu rơi vào tháng 12
            // ta reset Ngay = 1 và Thang = 1 
            // cộng thêm 1 năm
            iNgay = 1;
            iThang = 1;
            iNam++;
        }
    }
}

//Hàm in ra màn hình Ngày-Tháng-Năm, theo dạng: ngày/tháng/năm
void NgayThangNam:: Xuat() {
    cout <<"Ngay Thang Nam tiep theo la:" << endl;
    cout << iNgay << "/" << iThang << "/" << iNam;
}