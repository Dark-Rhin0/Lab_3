#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class cNhanVienSX
{
private:
    string MaSo, HoTen, Date;
    int SoSP;
    double DonGia;
public:
    //constructor
    cNhanVienSX();
    cNhanVienSX(string ms, string ten, string date, int sosp, double gia);
    //getter & setter
    string getmaSo() const;
    void setmaSo(string ms);
    string gethoTen();
    void sethoTen(string ten);
    string getDatee();
    void setDatee(string date);
    int getsoSP() const;
    void setsoSP(int sosp);
    double getdonGia();
    void setdonGia(double gia);

    void Nhap();
    void Xuat();
    double TinhLuong() const;
    int NamSinh() const;
};

#endif