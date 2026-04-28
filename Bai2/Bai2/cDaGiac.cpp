#include "cDaGiac.h"
#include <iostream>
#include <cmath>
#include <cstdio>
#include "graphics.h"
#include <algorithm>

#define M_PI 3.14159265358979323846

using namespace std;

// Xếp lại thứ tự nối các điểm
void cDaGiac::SapXepDiem() {
    // Tính trọng tâm
    double cx = 0, cy = 0;
    for (int i = 0; i < n; i++) {
        cx += ds[i].x;
        cy += ds[i].y;
    }
    cx /= n;
    cy /= n;

    // Sắp xếp theo góc
    sort(ds.begin(), ds.end(), [cx, cy](cDiem a, cDiem b) {
        double gocA = atan2(a.y - cy, a.x - cx);
        double gocB = atan2(b.y - cy, b.x - cx);
        return gocA < gocB;
        });
}

void cDaGiac::Nhap() {
    cout << "Nhap so dinh: ";
    cin >> n;

    ds.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "Nhap diem " << i + 1 << ":\n";
        ds[i].Nhap();
    }
    SapXepDiem();
}

void cDaGiac::Xuat() {
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}

double cDaGiac::ChuVi() {
    double cv = 0;
    for (int i = 0; i < n; i++) {
        cv += ds[i].KhoangCach(ds[(i + 1) % n]);
    }
    return cv;
}

// Shoelace formula
double cDaGiac::DienTich() {
    double dt = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        dt += ds[i].x * ds[j].y - ds[j].x * ds[i].y;
    }
    return fabs(dt) / 2;
}

void cDaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < n; i++) {
        ds[i].x += dx;
        ds[i].y += dy;
    }
}

void cDaGiac::PhongTo(double s) {
    for (int i = 0; i < n; i++) {
        ds[i].x *= s;
        ds[i].y *= s;
    }
}

void cDaGiac::ThuNho(double s) {
    for (int i = 0; i < n; i++) {
        ds[i].x /= s;
        ds[i].y /= s;
    }
}

void cDaGiac::Xoay(double goc) {
    // 1. Tìm trọng tâm (G) của đa giác
    double tamX = 0, tamY = 0;
    for (int i = 0; i < n; i++) {
        tamX += ds[i].x;
        tamY += ds[i].y;
    }
    tamX /= n;
    tamY /= n;

    double rad = goc * M_PI / 180;
    double cosG = cos(rad);
    double sinG = sin(rad);

    for (int i = 0; i < n; i++) {
        // 2. Dịch điểm về gốc (0,0) so với tâm
        double tempX = ds[i].x - tamX;
        double tempY = ds[i].y - tamY;

        // 3. Xoay
        double xMoi = tempX * cosG - tempY * sinG;
        double yMoi = tempX * sinG + tempY * cosG;

        // 4. Dịch ngược lại vị trí ban đầu
        ds[i].x = xMoi + tamX;
        ds[i].y = yMoi + tamY;
    }
}

void cDaGiac::Ve() {
    setcolor(GREEN);
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        line(ds[i].x, ds[i].y, ds[j].x, ds[j].y);
    }
}

void cDaGiac::HienThiThongTin(int x, int y) {
    char text[100];

    sprintf_s(text, "Chu vi: %.2f", ChuVi());
    outtextxy(x, y, text);

    sprintf_s(text, "Dien tich: %.2f", DienTich());
    outtextxy(x, y + 20, text);
}