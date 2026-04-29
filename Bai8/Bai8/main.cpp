#include "cNhanVienSX.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

void xuatTieuDe() {
    cout << left << setw(10) << "Ma NV" << setw(20) << "Ho Ten"
        << setw(15) << "Ngay Sinh" << setw(10) << "SL" << setw(12) << "DonGia" << endl;
    cout << string(67, '-') << endl;
}
int main()
{
    // Nhap danh sach nhan vien
    int n;
    cout << "So luong nhan vien: ";
    cin >> n;

    vector<cNhanVienSX> ds;
    for (int i = 0; i < n; i++)
    {
        cout << "nhan vien thu " << i + 1;
        cNhanVienSX nv;
        nv.Nhap();
        ds.push_back(nv);
    }

    // Xuat danh sach nhan vien
    cout << "\n~~~~~`DANH SACH NHAN VIEN`~~~~~\n";
    xuatTieuDe();
    for (auto& nv : ds)
    {
        nv.Xuat();
    }
    // Tim nhan vien luong thap nhat
    double minLuong = ds[0].TinhLuong();
    for (auto& nv : ds)
    {

        if (minLuong > nv.TinhLuong())
            minLuong = nv.TinhLuong();
    }
    cout << "Nhan vien co luong thap nhat la: ";
    for (auto& nv : ds)
    {

        if (minLuong == nv.TinhLuong())
        {
            cout << nv.gethoTen() << "\n";
            break;
        }
    }

    // Tong luong cty phai tra
    double TongLuong = 0;
    for (auto& nv : ds)
    {
        TongLuong += nv.TinhLuong();
    }
    cout << fixed << setprecision(0);
    cout << "Tong tien luong ma cong ty phai tra cho tat ca nhan vien: " << TongLuong << "\n";

    // Tim nhan vien co tuoi cao nhat
    int oldest = ds[0].NamSinh();
    for (auto& nv : ds)
    {
        if (oldest > nv.NamSinh())
            oldest = nv.NamSinh();
    }
    cout << "Nhan vien lon tuoi nhat: ";
    for (auto& nv : ds)
    {
        if (oldest == nv.NamSinh())
            cout << nv.gethoTen() << "\n";
    }

    // Sap xep danh sach theo luong tang dan
    cout << "\n~~~~~`DANH SACH LUONG TANG DAN`~~~~~\n";
    sort
    (
        ds.begin(), ds.end(), [](cNhanVienSX& a, cNhanVienSX& b)
        {
            return a.TinhLuong() < b.TinhLuong();
        }
    );
    xuatTieuDe();
    for (auto& nv : ds)
        nv.Xuat();

    return 0;
}