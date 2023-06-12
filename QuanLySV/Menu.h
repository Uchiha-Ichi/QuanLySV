#pragma once

#include "Const.h"
#include "MH.h"
#include"LopSV.h"
#include "DSLTC.h"



void menuFirst() {
	setfillstyle(SOLID_FILL, mauNen);
	bar(305, 95, 1540, 777);

	tieuDe();
	// ten sv giang vien 
	setfillstyle(SOLID_FILL, mauNen);
	bar(0, 95, 303, 335);
	settextstyle(10, 0, 4);
	setbkcolor(XanhLe);
	setcolor(Den);
	outtextxy((47 + 241) / 2 - textwidth(_tieuDe2) / 2, (103 + 148) / 2 - textheight(_tieuDe2) / 2, _tieuDe2);
	// luy y
	setfillstyle(SOLID_FILL, mauNen);
	bar(0, 339, 304, 777);
	settextstyle(10, 0, 4);
	setbkcolor(HongNhat);
	setcolor(Blue);
	outtextxy((81 + 205) / 2 - textwidth(_luuY) / 2, (363 + 412) / 2 - textheight(_luuY) / 2, _luuY);
	// nut
	_buttonLopTinChi();

	_buttonSinhVien();

	_buttonMonHoc();

	_buttonDiem();
	buttonThoat();
}


void free(treeMH cayMH, DSLH lop) {
	lop.freeDSLH(lop.getHeadLH());
	cayMH.DeleteNode(cayMH.getRoot());


}



void menuFirstSet() {
	menuFirst();
	treeMH cayMH;
	DSLH lop;
	DSLTC LTC;
	int colorNen = YELLOW;
	int colorText = BLACK;
	LTC.loadDataDS_LTC();
	LTC.loadDataDS_DK();
	int x = -1, y = -1;
	int on = 1;
	while (on) {
		delay(10);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (x >= 679 && x <= 1011 && y >= 228 && y <= 296) {
				// Lop Tin Chi   
				cleardevice();
				LTC.menuLTC();
				menuFirst();
			}
			else if (x >= 679 && x <= 1011 && y >= 354 && y <= 421) {
				cleardevice();
				lop.menuSetLop(on);
				menuFirst();
				// Sinh vien  
			}
			else if (x >= 679 && x <= 1011 && y >= 470 && y <= 537) {
				cleardevice();
				cayMH.menuSetMH(on);
				menuFirst();
				// Mon Hoc   
			}
			else if (x >= 679 && x <= 1011 && y >= 583 && y <= 651) {
				cleardevice();
				LTC.menuDiem();
				// diem 
			}
			else if (1400 <= x && x <= 1490 && 10 <= y && y <= 60) {
				on = 0;
				LTC.writeDataDS_DK();
				LTC.writeDataDS_LTC();
				LTC.freeDS_LTC();
				break;
			}
		}
	}
	free(cayMH, lop);
}