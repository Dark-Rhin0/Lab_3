#include "cDiem.h"
#include <iostream>
#include <cmath>

using namespace std;

// Định nghĩa hàm nhập tọa độ(x,y)
void cDiem::Nhap() {
	cout << "Nhap toa do diem x: ";
	cin >> x;
	cout << "Nhap toa do diem y: ";
	cin >> y;
}

void cDiem::Xuat() {
	cout << "(" << x << "," << y << ")" << "\n"; //(x,y)
}

double cDiem::KhoangCach(cDiem p) {
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}