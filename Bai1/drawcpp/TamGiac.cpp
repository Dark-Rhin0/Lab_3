#include "cTamGiac.h"
#include <iostream>
#include <cmath>
#include <cstdio>
#define M_PI 3.14159265358979323846 //số pi
#include "graphics.h"

using namespace std;

// Định nghĩa hàm nhập các điểm of 1 tam giác
void cTamGiac::Nhap() {
	cout << "Nhap toa do diem A: " << endl; A.Nhap();
	cout << "Nhap toa do diem B: " << endl; B.Nhap();
	cout << "Nhap toa do diem C: " << endl; C.Nhap();
}


// Định nghĩa hàm xuất các điểm of 1 tam giác
void cTamGiac::Xuat() {
	cout << "Toa do diem A: " << endl; A.Xuat();
	cout << "Toa do diem B: " << endl; B.Xuat();
	cout << "Toa do diem C: " << endl; C.Xuat();
}

// Định nghĩa hàm tính chuvi
double cTamGiac::ChuVi() {
	double a = A.KhoangCach(B);//độ dài AB
	double b = B.KhoangCach(C);//độ dài BC
	double c = C.KhoangCach(A);//độ dài AC
	return a + b + c;
}

// Định nghĩa hàm tính dtich
double cTamGiac::DienTich() {
	double a = A.KhoangCach(B);
	double b = B.KhoangCach(C);
	double c = C.KhoangCach(A);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}


// Định nghĩa hàm phân loại
const char* cTamGiac::PhanLoai() {
	double a = A.KhoangCach(B);
	double b = B.KhoangCach(C);
	double c = C.KhoangCach(A);

	bool can = false; // ban đầu mặc định ko cân

	// Kiểm tra vuông
	double a2 = a * a, b2 = b * b, c2 = c * c;
	bool vuong = fabs(a2 + b2 - c2) < 1e-6 ||
		fabs(b2 + c2 - a2) < 1e-6 ||
		fabs(a2 + c2 - b2) < 1e-6;


	if (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6)
		return "Tam giac deu";
	else if (fabs(a - b) < 1e-6 || fabs(b - c) < 1e-6 || fabs(a - c) < 1e-6)
	{
		if (vuong) return "Tam giac vuong can";

		else return "Tam giac can";
	}
	else if (vuong) return "Tam giac vuong";
	else
		return "Tam giac thuong";
}

void cTamGiac::TinhTien(double dx, double dy) {
	A.x += dx; A.y += dy;
	B.x += dx; B.y += dy;
	C.x += dx; C.y += dy;
}

void cTamGiac::PhongTo(double s) {
	A.x *= s; A.y *= s;
	B.x *= s; B.y *= s;
	C.x *= s; C.y *= s;
}

void cTamGiac::ThuNho(double s) {
	A.x /= s; A.y /= s;
	B.x /= s; B.y /= s;
	C.x /= s; C.y /= s;
}

// Hàm xoay hình quanh trọng tâm G
void cTamGiac::Xoay(double goc) {
	double rad = goc * M_PI / 180;
	double cosGoc = cos(rad);
	double sinGoc = sin(rad);

	// Tính trọng tâm
	double gx = (A.x + B.x + C.x) / 3;
	double gy = (A.y + B.y + C.y) / 3;

	// Hàm xoay 1 điểm quanh tâm
	auto xoayDiem = [&](double& x, double& y) {
		// Tịnh tiến về gốc
		double tx = x - gx;
		double ty = y - gy;

		// Xoay
		double rx = tx * cosGoc - ty * sinGoc;
		double ry = tx * sinGoc + ty * cosGoc;

		// Tịnh tiến ngược lại
		x = rx + gx;
		y = ry + gy;
		};

	xoayDiem(A.x, A.y);
	xoayDiem(B.x, B.y);
	xoayDiem(C.x, C.y);
}

void cTamGiac::Ve() {
	setcolor(GREEN);

	line((int)A.x, (int)A.y, (int)B.x, (int)B.y);
	line((int)B.x, (int)B.y, (int)C.x, (int)C.y);
	line((int)C.x, (int)C.y, (int)A.x, (int)A.y);
}

void cTamGiac::HienThiThongTin(int x, int y) {
	char text[100];

	sprintf_s(text, "Chu vi: %.2f", ChuVi()); //%.2f lấy 2 chữ số sau dấu thập phân
	outtextxy(x, y, text);

	sprintf_s(text, "Dien tich: %.2f", DienTich());
	outtextxy(x, y + 20, text);

	sprintf_s(text, "Loai: %s", PhanLoai());
	outtextxy(x, y + 40, text);
}
