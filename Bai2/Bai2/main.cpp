#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include "cDaGiac.h"
#include <windows.h>

int main() {
    int w = GetSystemMetrics(SM_CXSCREEN) - 50;
    int h = GetSystemMetrics(SM_CYSCREEN) - 80;

    initwindow(w, h, "Da Giac");

    cDaGiac dg, temp;
    dg.Nhap();

    // In thông số
    cleardevice();
    dg.HienThiThongTin(10, 30);
    getch();// nhấn phím bất kỳ để vẽ tiếp

    // Gốc
    cleardevice();
    dg.Ve();
    outtextxy(10, 10, (char*)"Ban dau");
    getch();

    // Tịnh tiến
    temp = dg;
    cleardevice();
    temp.TinhTien(50, 50);
    temp.Ve();
    outtextxy(10, 10, (char*)"Tinh tien");
    getch();

    // Phóng to
    temp = dg;
    cleardevice();
    temp.PhongTo(1.5);
    temp.Ve();
    outtextxy(10, 10, (char*)"Phong to");
    getch();

    // Thu Nhỏ
    temp = dg;
    cleardevice();
    temp.ThuNho(1.5);
    temp.Ve();
    outtextxy(10, 10, (char*)"Thu Nho");
    getch();

    // Xoay
    temp = dg;
    cleardevice();
    temp.Xoay(180);
    temp.Ve();
    outtextxy(10, 10, (char*)"Xoay 180 do");
    getch();

    closegraph();
    return 0;
}