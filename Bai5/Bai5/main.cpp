#include "cDaThuc.h"

using namespace std;

int main()
{
    cDaThuc A, B;

    cout << "Da Thuc A: \n";
    A.Nhap();
    cout << "Da Thuc B: \n";
    B.Nhap();

    cout << "\nA = ";   A.Xuat();
    cout << "\nGia tri cua da thuc A: " << A.GiaTri();
    cout << "\nB = ";   B.Xuat();
    cout << "\nGia tri cua da thuc B: " << B.GiaTri();

    cout << "\nA + B = ";
    (A + B).Xuat();
    cout << "\nA - B = ";
    (A - B).Xuat();

    return 0;
}