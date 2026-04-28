#pragma once
#ifndef CDAGIAC_H
#define CDAGIAC_H

#include "cDiem.h"
#include <vector>

class cDaGiac {
private:
    int n;
    std::vector<cDiem> ds;

public:
    void Nhap();
    void Xuat();

    void SapXepDiem();

    double ChuVi();
    double DienTich();

    void TinhTien(double dx, double dy);
    void PhongTo(double s);
    void ThuNho(double s);
    void Xoay(double goc);

    void Ve();
    void HienThiThongTin(int x, int y);
};

#endif