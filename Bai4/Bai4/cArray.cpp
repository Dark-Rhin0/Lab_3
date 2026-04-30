#include "cArray.h"
#include <iostream>

using namespace std;

cArray::cArray() :SoPhanTu(0) {}
void cArray::Nhap()
{
    cout << "So phan tu trong mang: ";
    cin >> SoPhanTu;
    PhanTu.assign(SoPhanTu, 0);
    cout << "Nhap cac phan tu trong mang: ";
    for (int i = 0; i < SoPhanTu; i++)
    {
        cin >> PhanTu[i];
    }
}

void cArray::Xuat()
{
    for (auto& phantu : PhanTu)
    {
        cout << phantu << " ";
    }
}

int cArray::SoLanXuatHien(int x)
{
    int Dem = 0;
    for (auto& phantu : PhanTu)
    {
        if (x == phantu) Dem++;
    }
    return Dem;
}

void cArray::KiemTraTangDan()
{
    bool check = true;
    for (int i = 0; i < SoPhanTu - 1; i++)
    {
        if (PhanTu[i] > PhanTu[i + 1])
            check = false;
    }
    if (check)
        cout << "Day la mang tang dan\n";
    else
        cout << "Day khong la mang tang dan\n";
}

int cArray::LeNhoNhat()
{
    int Min = -1;
    bool timThayle = false;

    for (auto& phantu : PhanTu)
    {
        if (phantu % 2 != 0)
        {
            if (!timThayle || phantu < Min)
            {
                Min = phantu;
                timThayle = true;
            }
        }
    }

    if (!timThayle) {
        return -1;
    }

    return Min;
}

bool KiemTraSNT(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int cArray::SNTLonNhat()
{
    int Max = 0;
    for (auto& phantu : PhanTu)
    {
        if (KiemTraSNT(phantu))
        {
            if (Max < phantu)
                Max = phantu;
        }
    }
    return Max;
}

void cArray::SapXepMangTang()
{
    int n = PhanTu.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (PhanTu[i] > PhanTu[j])
                swap(PhanTu[i], PhanTu[j]);
        }
    }
}
void cArray::SapXepMangGiam()
{
    int n = PhanTu.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (PhanTu[i] < PhanTu[j])
                swap(PhanTu[i], PhanTu[j]);
        }
    }
}
