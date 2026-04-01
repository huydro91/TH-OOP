#ifndef SoPhuc_H
#define SoPhuc_H

class SoPhuc {
    private:
        double iThuc, iAo; // dùng kiểu dữ liệu double để khi thực hiện phép chia
    public:

        void Nhap();
        void Xuat();
        
        SoPhuc Tinh_Tong(SoPhuc b);
        SoPhuc Tinh_Hieu(SoPhuc b);
        SoPhuc Tinh_Tich(SoPhuc b);
        SoPhuc Tinh_Thuong(SoPhuc b);
};

#endif