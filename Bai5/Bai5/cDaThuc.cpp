#include "cDaThuc.h"
using namespace std;

cDaThuc::cDaThuc() : Bac(0), GiaTriX(0)
{
    HeSo.resize(1, 0);
}
cDaThuc::cDaThuc(int bac) :Bac(bac), GiaTriX(0)
{
    HeSo.resize(bac + 1, 0);
}

void cDaThuc::Nhap()
{
    cout << "Bac cua da thuc: ";
    cin >> Bac;
    HeSo.assign(Bac + 1, 0);
    for (int i = Bac; i >= 0; i--)
    {
        cout << "He so x^" << i << ": ";
        cin >> HeSo[i];
    }

    cout << "Nhap gia tri cua x: ";
    cin >> GiaTriX;
}

void cDaThuc::Xuat()
{
    bool HeSoDau = true;
    for (int i = Bac; i >= 0; i--)
    {
        if (HeSo[i] == 0) continue;

        // Xử lý dấu
        if (HeSo[i] > 0) {
            if (!HeSoDau) cout << " + ";
        }
        else {
            if (HeSoDau) cout << "-"; // Số âm đầu tiên: in dấu sát số
            else cout << " - ";       // Số âm phía sau: in cách ra cho đẹp
        }

        // không in số 1 nếu gắn với x
        double triTuyetDoi = abs(HeSo[i]);
        if (triTuyetDoi != 1 || i == 0) cout << triTuyetDoi;

        // bậc của x
        if (i > 0)
        {
            cout << "x";
            if (i > 1) cout << "^" << i;
        }
        HeSoDau = false;
    }
    if (HeSoDau) cout << "0";
}

double cDaThuc::GiaTri()
{
    double val = 0;
    for (int i = 0; i <= Bac; i++)
    {
        val += HeSo[i] * pow(GiaTriX, i);
    }
    return val;

}
cDaThuc operator+(const cDaThuc& a, const cDaThuc& b)
{
    cDaThuc res;
    res.Bac = max(a.Bac, b.Bac);
    res.HeSo.assign(res.Bac + 1, 0);

    for (int i = 0; i <= a.Bac; i++)
    {
        res.HeSo[i] += a.HeSo[i];
    }
    for (int i = 0; i <= b.Bac; i++)
    {
        res.HeSo[i] += b.HeSo[i];
    }
    return res;
}

cDaThuc operator-(const cDaThuc& a, const cDaThuc& b)
{
    cDaThuc res;
    res.Bac = max(a.Bac, b.Bac);
    res.HeSo.assign(res.Bac + 1, 0);

    for (int i = 0; i <= a.Bac; i++)
    {
        res.HeSo[i] += a.HeSo[i];
    }
    for (int i = 0; i <= b.Bac; i++)
    {
        res.HeSo[i] -= b.HeSo[i];
    }
    return res;
}