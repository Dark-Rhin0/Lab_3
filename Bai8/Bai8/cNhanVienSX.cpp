#include "cNhanVienSX.h"
using namespace std;

cNhanVienSX::cNhanVienSX() :
    MaSo(""), HoTen(""), Date(""), SoSP(0), DonGia(0) {
}

cNhanVienSX::cNhanVienSX(string ms, string ten, string date, int sosp, double gia) :
    MaSo(ms), HoTen(ten), Date(date), SoSP(sosp), DonGia(gia) {
}

string cNhanVienSX::getmaSo()const { return MaSo; }

string cNhanVienSX::gethoTen() { return HoTen; }

string cNhanVienSX::getDatee() { return Date; }

int cNhanVienSX::getsoSP()const { return SoSP; }

double cNhanVienSX::getdonGia() { return DonGia; }

void cNhanVienSX::setmaSo(string ms) { MaSo = ms; }

void cNhanVienSX::sethoTen(string ten) { HoTen = ten; }

void cNhanVienSX::setDatee(string date) { Date = date; }

void cNhanVienSX::setsoSP(int sosp)
{
    if (sosp >= 0)
        SoSP = sosp;
}

void cNhanVienSX::setdonGia(double gia) { DonGia = gia; }


void cNhanVienSX::Nhap()
{
    cin.ignore();
    cout << "\nNhap ma so nhan vien: ";           getline(cin, MaSo); // lấy luôn khoảng trắng để in
    cout << "Nhap ten nhan vien: ";               getline(cin, HoTen);
    cout << "Nhap ngay sinh nhan vien: ";         getline(cin, Date);
    cout << "So san pham da lam: ";        cin >> SoSP;
    cout << "Don gia cua 1 san pham: ";    cin >> DonGia;
}

void cNhanVienSX::Xuat()
{
    cout << left << setw(10) << MaSo << setw(20) << HoTen
        << setw(15) << Date << setw(10) << SoSP << setw(12) << DonGia << endl;
    cout << string(67, '-') << endl;
}

double cNhanVienSX::TinhLuong()const
{
    return SoSP * DonGia;
}

int cNhanVienSX::NamSinh() const
{
    string Nam = Date.substr(Date.length() - 4);
    return stoi(Nam);
}
