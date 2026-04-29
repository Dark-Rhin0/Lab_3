#include "cArray.h"
#include <iostream>

using namespace std;

int main()
{
    cArray a;
    a.Nhap();
    a.Xuat();
    int x;
    cout << "\nSo lan xuat hien cua x: ";
    cin >> x;
    cout << "la " << a.SoLanXuatHien(x) << " lan" << "\n";
    a.KeimTraTangDan();
    if (a.LeNhoNhat() < 0)
        {cout << "Mang khong co phan tu le\n";} // TH không có
    else 
        {cout << "Phan tu le nho nhat cua mang: " << a.LeNhoNhat() << "\n";}

    if (a.LeNhoNhat() < 2)
        {cout << "Mang khong co so nguyen to\n";} // TH không có
    else
        {cout << "So nguyen to lon nhat cua mang: " << a.SNTLonNhat() << "\n";}

    a.SapXepMangTang();
    cout << "Mang theo chieu tang: ";
    a.Xuat();
    cout << "\nMang theo chieu giam: ";
    a.SapXepMangGiam();
    a.Xuat();
    return 0;
}