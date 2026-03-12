// nhap vao thong tin hoc sinh va in ra man hinh diem trung binh cua hoc sinh
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstring>
using namespace std;

struct HOCSINH { // dữ liệu học sinh
    string name;
    float diem_toan, diem_van;

};

// hàm tính điểm trung bình
//Input: điểm toán và văn (số thực)
//Output: điểm TB của toán và văn
float Diemtb (float a, float b)
{
    return (a+b)/2.0 ;
}

void Nhap_Diem(float &a)
{
    while (true)
    {
        cout << "Nhap diem: "<<endl;
        cin >> a;

        // KT du lieu nhap co phai roi vao ki tu loi khong
        if ( cin.fail())
        {
            cout << "Diem nhap khong hop le. Nhap lai. \n";

            cin.clear();// xoa co bao loi
            //tuy đã xoá cờ báo lỗi nhưng, nhưng dữ liệu nhập sai vẫn còn lưu trong buff nên cần xoá
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//xoá dữ liệu lỗi
            // nếu ko xoá thì khi nhập lại nó sẽ tiếp tục đọc dữ liệu lỗi
            continue;
        }
        break;
    }
}

int main() {
    HOCSINH a;
    getline (cin, a.name);
    Nhap_Diem(a.diem_toan); // nhap diem toan
    Nhap_Diem(a.diem_van); //Nhap diem van
    float diemtb = Diemtb(a.diem_toan, a.diem_van);
  
    // in ra tên và điểm trung bình của học sinh a
    cout << "Ho ten: " <<a.name << endl;
    cout << "Diem tb: " << setprecision(2) << fixed << diemtb << endl; // làm tròn đến 2 số sau dấu ","

    return 0;
}