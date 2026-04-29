#ifndef CDATHUC_H
#define CDATHUC_H

#include <iostream>
#include <vector>

class cDaThuc
{
private:
    std::vector<double> HeSo;
    int Bac;
    double GiaTriX;
public:
    cDaThuc();
    cDaThuc(int bac);

    void Nhap();
    void Xuat();
    double GiaTri();
    friend cDaThuc operator+(const cDaThuc& a, const cDaThuc& b);
    friend cDaThuc operator-(const cDaThuc& a, const cDaThuc& b);
};

#endif#pragma once

