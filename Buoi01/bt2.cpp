#include <iostream>
// nhap vao 2 phan so, xuat ket qua phan so lon hon
using namespace std;
struct Phanso { // dữ liệu phân số
    int tuso;
    int mauso;
};

// hàm tìm phân số lớn hơn (trong 2 phân số)
//Input: Nhập vào tử số và mẫu số của 2 phân số
//Output: in ra màn hình KQ của phân số lơn hơn
void Find_Phanso_lonhon (Phanso a, Phanso b)
{
    //chú thích -- QĐ: quy đồng --- PS: phân số

    //tiến hành chỉnh để mẫu số luôn dương
    if (a.mauso < 0) {
        a.tuso = -a.tuso;
        a.mauso = -a.mauso;
    }
    if (b.mauso < 0) {
        b.tuso = -b.tuso;
        b.mauso = -b.mauso;
    }

    // TH: mẫu số khác nhau
    if ( a.mauso != b.mauso) 
    {
        // tiến hành QĐ mẫu số
        long long v = a.tuso * b.mauso, m = b.tuso * a.mauso;
        // sau khi QĐ nếu tử số của PS1 > tử số PS2 thì PS1 là PS lớn hơn
        if ( v > m) cout << "result = "<< a.tuso <<"/"<< a.mauso << endl;
        // không thì PS2 là phân số lớn hơn
        else if ( v < m) cout << "result = "<< b.tuso <<"/"<< b.mauso << endl;
        // ngược lại đây là 2 phân số bằng nhau
        else cout <<"Hai phan so bang nhau" << endl;
    }
    else {//TH: khi đã cùng mẫu số
        //tử số của PS1 > tử số PS2 thì PS1 là PS lớn hơn
        if ( a.tuso > b.tuso) cout << "result = "<< a.tuso <<"/"<< a.mauso << endl;
        // không thì PS2 là phân số lớn hơn
        else if (a.tuso < b.tuso) cout << "result = "<< b.tuso <<"/"<< b.mauso << endl;
        // ngược lại đây là hai phân số bằng nhau
        else cout <<"Hai phan so bang nhau" << endl;
    }

}

int main() {
    Phanso a, b;
    cin >> a.tuso >> a.mauso;
    cin >> b.tuso >> b.mauso;

    // kiểm tra xem mẫu số có = 0 hay không
    if ( a.mauso ==0 || b.mauso ==0)
    {
        cout << "mau so khong hop le" << endl;
        return 0;
    }
    Find_Phanso_lonhon (a,b);

    return 0;
}