// nhap vao thong tin hoc sinh va in ra man hinh diem trung binh cua hoc sinh
#include <iostream>
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

int main() {
    HOCSINH a;
    getline (cin, a.name);
    cin >> a.diem_toan >> a.diem_van;
    float diemtb = Diemtb(a.diem_toan, a.diem_van);
  
    // in ra tên và điểm trung bình của học sinh a
    cout << "Ho ten: " <<a.name << endl;
    cout << "Diem tb: " << setprecision(2) << fixed << diemtb << endl; // làm tròn đến 2 số sau dấu ","

    return 0;
}