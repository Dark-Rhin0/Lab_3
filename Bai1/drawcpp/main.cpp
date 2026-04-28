#include "graphics.h"
#pragma comment(lib, "graphics.lib") //import thư viện ngoài để vẽ hình
#include "cTamGiac.h"
#include <iostream>
#include <windows.h>

using namespace std;


int main() {
	//lấy chiều dài và chiều rộng màn hình để tạo của sổ
	int CR_VW = GetSystemMetrics(SM_CXSCREEN) -50;
	int CD_VW = GetSystemMetrics(SM_CYSCREEN);
	initwindow(CR_VW, CD_VW, "");

	cTamGiac tg, temp;
	tg.Nhap();

	// In thông số
	cleardevice();
	tg.HienThiThongTin(10, 30);
	getch();// nhấn phím bất kỳ để vẽ tiếp
	
	// Gốc
	cleardevice();
	tg.Ve();
	outtextxy(10, 10, (char*)"Ban dau");
	getch();// nhấn phím bất kỳ để vẽ tiếp


	// Tịnh tiến
	temp = tg;
	cleardevice();
	temp.TinhTien(50, 50);
	temp.Ve();
	outtextxy(10, 10, (char*)"Tinh tien");
	getch();

	// Phóng to
	temp = tg;
	cleardevice();
	temp.PhongTo(1.5);
	temp.Ve();
	outtextxy(10, 10, (char*)"Phong to");
	getch();

	// Thu nhỏ
	temp = tg;
	cleardevice();
	temp.ThuNho(1.5);
	temp.Ve();
	outtextxy(10, 10, (char*)"Thu nho");
	getch();

	// Xoay
	temp = tg;
	cleardevice();
	temp.Xoay(45);
	temp.Ve();
	outtextxy(10, 10, (char*)"Xoay 45 do");
	getch();


	closegraph();
	return 0;
}