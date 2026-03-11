#include <iostream>
// viet chuong trinh Nhap vao 1 ngay, xuat ra kq ngay ke tiep
using namespace std;

//khai báo các hàm sử dụng
bool kiemtra_ngaynhap(int day, int month, int year);// ham kiem tra ngay nhap
bool Kiemtra_namNhuan( int year);// Ham kiem tra nam nhuan
int soNgay_trong_Thang(int month, int year);// Ham tra ve so ngay trong 1 thang
void In_raNgay_ketiep (int day, int month, int year);// Ham in ra ngay ke tiep

// ham kiem tra ngay nhap
// Input: month (thang), year (nam)
// Output: trả về false nếu ngày nhập vào bị sai, true nếu ngày nhập vào đúng
bool kiemtra_ngaynhap(int day, int month, int year)
{
    if ( year <= 0) return false;

    if ( month  < 1 || month > 12) return false;

    int maxday = soNgay_trong_Thang(month, year);// tìm số ngày của tháng đó và lưu vào biến maxday

    if ( day <1 || day > maxday) return false;

    return true;
}
// Ham kiem tra nam nhuan
// Input: year (nam can kiem tra)
// Output: true neu la nam nhuan, false neu khong phai
bool Kiemtra_namNhuan( int year)
{
    return (year % 400 ==0) || (year % 4 ==0 && year % 100 != 0);
    // nếu năm nhập chia hết cho 400 or chia hết cho 4 nhưng không chia hết cho 100
    // thì đó là năm nhuận, kết quả trả về sẽ là true
}

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

// Ham in ra ngay ke tiep
// Input: day, month, year (ở hiện tại)
// Output: in ra ngay ke tiep
void In_raNgay_ketiep (int day, int month, int year)
{
    int ngay = soNgay_trong_Thang(month, year); // lưu số ngày của tháng này vào biến ngày
    if (day < ngay) 
    {//TH: nếu ngày hiện tại bé hơn số ngày của tháng
        cout << "Ngay ke tiep la: ";
        cout << day+1 <<"/"<< month << "/" << year << endl;// ta in ra ngày kế tin
        return; 
    }
    else { //TH: nếu ngày hiện tại = ngày của tháng
        if ( month < 12)
        {// KT xem tháng có thuộc từ tháng 1 đến tháng 11 không
            cout << "Ngay ke tiep la: ";
            cout << 1 <<"/"<< month+1 << "/" << year << endl; // có thì in ra ngày 1 và tháng kế tiếp
            return;
        }
        else { // nếu rơi vào tháng 12
            cout << "Ngay ke tiep la: ";
            cout << 1 <<"/"<< 1 << "/" << year+1 << endl;// ta cần in ra ngay 1 tháng 1 và năm kế tiếp
            return;
        }
    }
}
int main() {
    int day,month,year; // day: ngày, month: tháng, year: năm
    cin >> day >> month >> year;

    while ( ! kiemtra_ngaynhap(day, month, year)) // nếu ngày nhập vào trả về giá trị sai
    {
        cout <<"Nhap lai ngay-thang-nam" << endl; // ta cần nhập lại
        cin >> day >> month >> year;
    }

    In_raNgay_ketiep(day, month, year);

    return 0;
}