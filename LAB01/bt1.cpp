#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

struct PhanSo // du lieu phan so
{
    int mauso;
    int tuso;
};

//khai bao cac ham su dung
int UCLN (int a, int b); // ham tim UOC CHUNG LON NHAT cua 2 so
void In_Phanso_Darutgon (int &tuso, int &mauso); // ham rut gon va in ra phan so
void Nhap_Phanso(PhanSo &a); // ham nhap phan so

// hàm nhập phân số hợp lệ
// Input: phân số a
// Output: Phân số hợp lệ (ko có chữ, kí tự đặc biệt, mẫu số khác 0)
void Nhap_Phanso(PhanSo &a)
{
    while (true)
    {
        cout <<"Nhap tu so va mau so: " << endl;
        cin >> a.tuso >> a.mauso;

        //KT ki tu dac biet
        if ( cin.fail())
        {
            cout <<"Du lieu khong hop le (Ko duoc nhap chu cai hay ki tu dac biet)";

            cin.clear(); // xoa trang thai loi
            //tuy đã xoá cờ báo lỗi nhưng, nhưng dữ liệu nhập sai vẫn còn lưu trong buff nên cần xoá
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//xoá dữ liệu lỗi
            // nếu ko xoá thì khi nhập lại nó sẽ tiếp tục đọc dữ liệu lỗi
            continue;
        }
        //KT mau so
        if (a.mauso == 0) {
            cout <<"mau so phai khac khong. Nhap lai mau so\n";
            cin >> a.mauso;
            break;
        }
        break;
    }

}
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

// hàm rút gọn phân số và in ra
//Input: tử số và mẫu số (số nguyên)
//Output: in ra tử số và mẫu số sau khi rút gọn
void In_Phanso_Darutgon (int &tuso, int &mauso)
{
    int ucln = UCLN(tuso,mauso); // tim UCLN giua tu so va mau so

    // rut gon phan so
    tuso /= ucln;
    mauso /= ucln;

    // chuẩn hoá dấu, ưu tiên để dấu trừ ở trước tử số
    if (mauso < 0)
    {
        tuso = -tuso;
        mauso = -mauso;
    }

    // in phân số sau khi đã rút gọn
    if ( mauso ==1) {
        cout << tuso << endl; // mẫu = 1 thì in ra tử rồi end
        return;
    } else {
        if ( tuso ==0) {
            cout << 0 << endl; // tử = 0 thì in ra 0 rồi end
            return;
        }
        else {
            cout << tuso << "/" << mauso << endl; // không rơi vào TH đặc biệt thì in ra tử số mẫu số
            return;
        }
    }
        
}

int main() {
    PhanSo a;
    
    //nhap phan so
    Nhap_Phanso(a);

    In_Phanso_Darutgon(a.tuso, a.mauso);
    return 0;
}