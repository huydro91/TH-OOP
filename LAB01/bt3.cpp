#include <iostream>
#include <limits>
#include <cmath>
//tính tổng-hiệu-tích-thương giữa 2 phân số
using namespace std;

typedef long long ll;

struct Phanso { // dữ liệu phân số
    ll tuso;
    ll mauso;
};

// khai báo các hàm được sử dụng
ll UCLN(ll a, ll b);// hàm tìm UCLN
void inPhanSo(ll tu, ll mau); // hàm in phân số
void tinhToan_PS(Phanso a, Phanso b); // hàm tính toán giữa 2 phân số
void Nhap_Phanso(Phanso &a);

// hàm nhập phân số hợp lệ
// Input: phân số a
// Output: Phân số hợp lệ (ko có chữ, kí tự đặc biệt, mẫu số khác 0)
void Nhap_Phanso(Phanso &a)
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

// hàm tìm ước chung lớn nhất giữa 2 số a và b
// Input: 2 số a và b
// Output : UCLN của a và b
ll UCLN(ll a, ll b) {
    // dùng hàm abs để lấy trị tuyệt đối của số
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        ll r = a % b;// chia lay phan du cua a cho b roi luu vao r, sau do dat a = b, va b = r
        a = b; // // tiep tuc lam nhu the cho den khi b = 0 thi a luc nay chinh la UCLN
        b = r;
    }
    return a;
}

// hàm in phân số:
//Input: tử và mẫu của phân số (số nguyên)
//Output: in ra phân số sau khi đã được chuẩn hoá
void inPhanSo(ll tu, ll mau) {
    if (mau == 0) {
        cout << "Khong xac dinh";
        return;
    }
    if (tu == 0) {
        cout << "0" << endl;
        return;
    }
    
    // tìm UCLN của tử số và mẫu số
    ll ucln = UCLN(tu, mau);
    // rút gọn phân số
    tu /= ucln;
    mau /= ucln;

    // Đưa dấu trừ lên tử số nếu mẫu âm
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }

    if (mau == 1) cout << tu << endl;
    else cout << tu << "/" << mau << endl;
}

// hàm tính toán phân số
//Input: 2 phân số
//Output: in ra phân số sau khi đã được tính toán
void tinhToan_PS(Phanso a, Phanso b) {

    // chuẩn hoá quy đồng tử số và mẫu số, rồi sau đó truyền vào hàm in phân số

    cout << "Phep cong = "; 
    inPhanSo(a.tuso * b.mauso + b.tuso * a.mauso, a.mauso * b.mauso);

    cout << "Phep tru = "; 
    inPhanSo(a.tuso * b.mauso - b.tuso * a.mauso, a.mauso * b.mauso);

    cout << "Phep nhan = "; 
    inPhanSo(a.tuso * b.tuso, a.mauso * b.mauso);

    cout << "Phep chia = "; 
    inPhanSo(a.tuso * b.mauso, a.mauso * b.tuso);
}

int main() {
    Phanso a, b;
    
    //nhap phan so
    Nhap_Phanso(a);
    Nhap_Phanso(b);

    tinhToan_PS(a, b);

    return 0;
}