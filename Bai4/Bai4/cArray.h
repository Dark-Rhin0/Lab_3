#pragma once
#ifndef CARRAY_H
#define CARRAY_H

#include <vector>
class cArray
{
private:
    std::vector<int> PhanTu;
    int SoPhanTu;
public:
    cArray();

    void Nhap();
    void Xuat();

    int SoLanXuatHien(int x);
    void KiemTraTangDan();
    int LeNhoNhat();
    int SNTLonNhat();
    void SapXepMangTang();
    void SapXepMangGiam();
};

#endif
