#pragma once
#ifndef CDIEM_H
#define CDIEM_H

#include <iostream>

class cDiem {
public:
	double x, y;
	void Nhap();
	void Xuat();
	double KhoangCach(cDiem p);
};


#endif
