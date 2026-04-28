#ifndef CTAMGIAC_H
#define CTAMGIAC_H

#include "cDiem.h"

class cTamGiac {
	private:
		cDiem A, B, C;
	public:
		void Nhap();
		void Xuat();

		void HienThiThongTin(int x, int y);
		double ChuVi();
		double DienTich();
		const char* PhanLoai(); // chỉnh kiểu trả về là char
		void TinhTien(double dx, double dy);
		void PhongTo(double s);
		void ThuNho(double s);
		void Xoay(double goc);

		void Ve();
};


#endif
