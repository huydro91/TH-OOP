#ifndef PhanSo_H
#define PhanSo_H

class PhanSo {
    private:
        int iTu, iMau;
    public:

        void Nhap();
        void Xuat();
        void RutGon();

        PhanSo Tinh_Tong(PhanSo a);
        PhanSo Tinh_Hieu(PhanSo a);
        PhanSo Tinh_Tich(PhanSo a);
        PhanSo Tinh_Thuong(PhanSo a);

        int SoSanh(PhanSo a); // 1: >, 0: =, -1: <

};

#endif