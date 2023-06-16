
#pragma once
#include"Const.h"
//-----------------------------Menu--------------------------------------------------------

void khoangTrang(int left, int top, int right, int bottom) {
    setcolor(Blue);

    rectangle(left, top, right, bottom);

    setbkcolor(BlueNhat);

    bar(left + textwidth(convertStringToChar(string("|"))), top + textheight(convertStringToChar(string("|"))), right - textwidth(convertStringToChar(string("|"))), bottom - textheight(convertStringToChar(string("|"))));

}

void vien(int left, int right, int top, int bottom) {
    setfillstyle(SOLID_FILL, Den);
    bar(left - 1, top, left + 1, bottom);
    setfillstyle(SOLID_FILL, Den);
    bar(left, top - 1, right, top + 1);
    setfillstyle(SOLID_FILL, Den);
    bar(right - 1, top, right + 1, bottom);
    setfillstyle(SOLID_FILL, Den);
    bar(left, bottom - 1, right, bottom + 1);
}

void _buttonLopTinChi() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(679, 228, 1011, 296);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((679 + 1011) / 2 - textwidth(_lopTinChi) / 2, (228 + 296) / 2 - textheight(_lopTinChi) / 2, _lopTinChi);
    vien(679, 1011, 228, 296);
}

void _buttonSinhVien() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(679, 354, 1011, 421);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((679 + 1011) / 2 - textwidth(_sinhVien) / 2, (354 + 421) / 2 - textheight(_sinhVien) / 2, _sinhVien);
    vien(679, 1011, 354, 421);
}


void _buttonMonHoc() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(679, 470, 1011, 537);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((679 + 1011) / 2 - textwidth(_monHoc) / 2, (470 + 537) / 2 - textheight(_monHoc) / 2, _monHoc);
    vien(679, 1011, 470, 537);
}


void _buttonDiem() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(679, 583, 1011, 651);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((679 + 1011) / 2 - textwidth(_diem) / 2, (583 + 651) / 2 - textheight(_diem) / 2, _diem);
    vien(679, 1011, 583, 651);
}

//void tenDoAn() {
//	setfillstyle(SOLID_FILL, XanhLe);
//	bar(1, 94, 305, SCREEN_HEIGHT);
//}
void buttonThoat() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1400, 10, 1490, 60);
    settextstyle(10, 0, 5);
    setcolor(RED);
    outtextxy((1490 + 1400) / 2 - textwidth(_thoat) / 2, (10 + 60) / 2 - textheight(_thoat) / 2, _thoat);
    vien(1400, 1490, 10, 60);
}


void tieuDe() {
    setbkcolor(HongNhat);
    setfillstyle(SOLID_FILL, HongNhat);
    bar(0, 0, 1540, 94);
    settextstyle(10, 0, 6);
    setcolor(Den);
    outtextxy((1540) / 2 - textwidth(convertStringToChar("QUAN LY SINH VIEN THEO HE TIN CHI")) / 2, (95) / 2 - textheight(convertStringToChar("QUAN LY SINH VIEN THEO HE TIN CHI")) / 2, convertStringToChar("QUAN LY SINH VIEN THEO HE TIN CHI"));
    vien(0, 1540, 0, 94);
}

void buttonTimKiem() {
    setbkcolor(graynhat);
    setfillstyle(SOLID_FILL, graynhat);
    bar(55, 169, 180, 205);
    settextstyle(10, 0, 1);
    setcolor(Den);
    outtextxy((55 + 180) / 2 - textwidth(_timkiem) / 2, (169 + 205) / 2 - textheight(_timkiem) / 2, _timkiem);
    vien(55, 180, 169, 205);
}

//-------------------------OUTTEXT----------------
void tongLTC(string str1) {
    string tongsoLTC = "Tong So Lop: ";
    tongsoLTC = tongsoLTC + str1;
    settextstyle(8, 0, 1);
    setcolor(Blue);
    outtextxy((500 + 800) / 2 - textwidth(convertStringToChar(tongsoLTC)) / 2, (120 + 150) / 2 - textheight(convertStringToChar(tongsoLTC)) / 2, convertStringToChar(tongsoLTC));
}
void DSSV1LTC(string str2, string str3, string str4, string str5, string str6, string str7) {
    string maLTC = "Ma Lop: ";
    string tenMH = "Ten Mon: ";
    string soSV = "So SV: ";
    string khoa = "Khoa: ";
    string HK = " Hoc Ki: ";
    string nhom = "Nhom: ";
    maLTC = maLTC + str2;
    tenMH = tenMH + str3;
    soSV = soSV + str4;
    khoa = khoa + str5;
    HK = HK + str6;
    nhom = nhom + str7;
    settextstyle(8, 0, 2);
    setbkcolor(mauNen);
    setcolor(Den);
    outtextxy((400 + 500) / 2 - textwidth(convertStringToChar(maLTC)) / 2, (140 + 150) / 2 - textheight(convertStringToChar(maLTC)) / 2, convertStringToChar(maLTC));
    outtextxy((600 + 1000) / 2 - textwidth(convertStringToChar(tenMH)) / 2, (140 + 150) / 2 - textheight(convertStringToChar(tenMH)) / 2, convertStringToChar(tenMH));
    outtextxy((400 + 500) / 2 - textwidth(convertStringToChar(soSV)) / 2, (160 + 170) / 2 - textheight(convertStringToChar(soSV)) / 2, convertStringToChar(soSV));
    outtextxy((550 + 650) / 2 - textwidth(convertStringToChar(khoa)) / 2, (160 + 170) / 2 - textheight(convertStringToChar(khoa)) / 2, convertStringToChar(khoa));
    outtextxy((700 + 800) / 2 - textwidth(convertStringToChar(HK)) / 2, (160 + 170) / 2 - textheight(convertStringToChar(HK)) / 2, convertStringToChar(HK));
    outtextxy((850 + 1000) / 2 - textwidth(convertStringToChar(nhom)) / 2, (160 + 170) / 2 - textheight(convertStringToChar(nhom)) / 2, convertStringToChar(nhom));
}
void tongLSV(string str8) {
    string tongsoLSV = "Tong So Lop: ";
    tongsoLSV = tongsoLSV + str8;
    settextstyle(8, 0, 1);
    setcolor(Blue);
    outtextxy((500 + 800) / 2 - textwidth(convertStringToChar(tongsoLSV)) / 2, (120 + 150) / 2 - textheight(convertStringToChar(tongsoLSV)) / 2, convertStringToChar(tongsoLSV));
}
void DS1Lop(string str9, string str10) {
    string malopSV = "Lop: ";
    string siso = "So sinh vien: ";
    malopSV = malopSV + str9;
    siso = siso + str10;
    settextstyle(8, 0, 1);
    setcolor(Blue);
    outtextxy((500 + 800) / 2 - textwidth(convertStringToChar(malopSV)) / 2, (120 + 130) / 2 - textheight(convertStringToChar(malopSV)) / 2, convertStringToChar(malopSV));
    outtextxy((500 + 800) / 2 - textwidth(convertStringToChar(malopSV)) / 2, (150 + 160) / 2 - textheight(convertStringToChar(malopSV)) / 2, convertStringToChar(malopSV));
}
void tongMH(string str11) {
    string tongsoMH = "So Luong Mon Hoc: ";
    tongsoMH = tongsoMH + str11;
    settextstyle(8, 0, 1);
    setcolor(Blue);
    outtextxy((500 + 800) / 2 - textwidth(convertStringToChar(tongsoMH)) / 2, (120 + 150) / 2 - textheight(convertStringToChar(tongsoMH)) / 2, convertStringToChar(tongsoMH));
}

void maSV(string str1) {
    string maSV = "Ma sinh vien: ";
    maSV = maSV + str1;
    settextstyle(8, 0, 2);
    setbkcolor(mauNen);
    setcolor(Den);
    outtextxy((600 + 800) / 2 - textwidth(convertStringToChar(maSV)) / 2, (120 + 150) / 2 - textheight(convertStringToChar(maSV)) / 2, convertStringToChar(maSV));
}


// ------------------------------MON HOC--------------------------------------
void menuFirstSet();

void menuSetMH();

void buttonBack();

void buttonHuyMH();

void menuThemMH();

void menuSetThemMH();

void buttonThem();

void buttonSaveMH();

void buttonLui();

void buttonTien();

void buttonLoc(int colorBK, int colortext, bool active);

void menuSuaMH();

void tieuDeMH();
/*
void vien(int left, int right, int top, int bottom) {
    setfillstyle(SOLID_FILL, Den);
    bar(left - 1, top, left + 1, bottom);
    setfillstyle(SOLID_FILL, Den);
    bar(left, top - 1, right, top + 1);
    setfillstyle(SOLID_FILL, Den);
    bar(right - 1, top, right + 1, bottom);
    setfillstyle(SOLID_FILL, Den);
    bar(left, bottom - 1, right, bottom + 1);
}
*/


void buttonSaveMH() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1057, 695, 1137, 734);
    settextstyle(10, 0, 1);
    setcolor(Blue);
    outtextxy((1057 + 1137) / 2 - textwidth(_save) / 2, (695 + 734) / 2 - textheight(_save) / 2, _save);
    vien(1057, 1137, 695, 734);
}

void buttonContinue() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1035, 695, 1137, 734);
    settextstyle(10, 0, 1);
    setcolor(Blue);
    outtextxy((1035 + 1137) / 2 - textwidth(_continue) / 2, (695 + 734) / 2 - textheight(_continue) / 2, _continue);
    vien(1035, 1137, 695, 734);
}

void buttonSaveSV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(755, 695, 835, 734);
    settextstyle(10, 0, 1);
    setcolor(Blue);
    outtextxy((755 + 835) / 2 - textwidth(_save) / 2, (695 + 734) / 2 - textheight(_save) / 2, _save);
    vien(755, 835, 695, 734);
}
void buttonHuyMH() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(425, 695, 520, 734);
    settextstyle(10, 0, 1);
    setcolor(Blue);
    outtextxy((425 + 520) / 2 - textwidth(_huy) / 2, (695 + 734) / 2 - textheight(_huy) / 2, _huy);
    vien(425, 520, 695, 734);
}

void buttonBack() {
    setbkcolor(HongNhat);
    setfillstyle(SOLID_FILL, HongNhat);
    bar(21, 21, 193, 71);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((21 + 193) / 2 - textwidth(_back) / 2, (21 + 71) / 2 - textheight(_back) / 2, _back);
    vien(21, 193, 21, 71);
}



void menuSuaMH() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(631, 125, 933, 180);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((631 + 933) / 2 - textwidth(_suaMH) / 2, (125 + 170) / 2 - textheight(_suaMH) / 2, _suaMH);
    vien(631, 933, 125, 180);
    buttonHuyMH();
    buttonSaveMH();
}

void menuThemMH() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(631, 125, 933, 180);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((631 + 933) / 2 - textwidth(_themMH) / 2, (125 + 170) / 2 - textheight(_themMH) / 2, _themMH);
    vien(631, 933, 125, 180);
    buttonHuyMH();
    buttonSaveMH();

}


void buttonThem() {
    setbkcolor(HongNhat);
    setfillstyle(SOLID_FILL, HongNhat);
    bar(1390, 169, 1490, 214);
    settextstyle(10, 0, 2);
    setcolor(Blue);
    outtextxy((1390 + 1490) / 2 - textwidth(_them) / 2, (169 + 214) / 2 - textheight(_them) / 2, _them);
    vien(1390, 1490, 169, 214);
}

void buttonLui() {
    setbkcolor(gray);
    setfillstyle(SOLID_FILL, gray);
    bar(613, 703, 685, 734);
    settextstyle(10, 0, 1);
    setcolor(Den);
    outtextxy((613 + 685) / 2 - textwidth(_sangPhai) / 2, (703 + 734) / 2 - textheight(_sangPhai) / 2, _sangPhai);
    vien(613, 685, 703, 734);
}

void buttonTienMH() {
    setbkcolor(gray);
    setfillstyle(SOLID_FILL, gray);
    bar(1100, 190, 1180, 230);
    settextstyle(10, 0, 1);
    setcolor(Den);
    outtextxy((1100 + 1180) / 2 - textwidth(_sangTrai) / 2, (190 + 230) / 2 - textheight(_sangTrai) / 2, _sangTrai);
    vien(1100, 1180, 190, 230);
}
void buttonLuiMH() {
    setbkcolor(gray);
    setfillstyle(SOLID_FILL, gray);
    bar(950, 190, 1020, 230);
    settextstyle(10, 0, 1);
    setcolor(Den);
    outtextxy((950 + 1020) / 2 - textwidth(_sangPhai) / 2, (190 + 230) / 2 - textheight(_sangPhai) / 2, _sangPhai);
    vien(950, 1020, 190, 230);
}

void buttonTien() {
    setbkcolor(gray);
    setfillstyle(SOLID_FILL, gray);
    bar(777, 703, 848, 734);
    settextstyle(10, 0, 1);
    setcolor(Den);
    outtextxy((777 + 848) / 2 - textwidth(_sangTrai) / 2, (703 + 734) / 2 - textheight(_sangTrai) / 2, _sangTrai);
    vien(777, 848, 703, 734);
}
void buttonLoc() {
    setbkcolor(graynhat);
    setfillstyle(SOLID_FILL, graynhat);
    bar(563, 169, 630, 205);
    settextstyle(10, 0, 1);
    setcolor(Den);
    outtextxy((563 + 630) / 2 - textwidth(_loc) / 2, (169 + 205) / 2 - textheight(_loc) / 2, _loc);
    vien(563, 630, 169, 205);
}

void tieuDeMH() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(397, 20, 1173, 100);
    settextstyle(10, 0, 8);
    setcolor(Blue);
    outtextxy((397 + 1173) / 2 - textwidth(_monHoc) / 2, (20 + 100) / 2 - textheight(_monHoc) / 2, _monHoc);
    vien(397, 1173, 20, 100);
}


// ------------------------------Lop--------------------------------------

void tieuDeLopSV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(397, 20, 1173, 100);
    settextstyle(10, 0, 8);
    setcolor(Blue);
    outtextxy((397 + 1173) / 2 - textwidth(_lopSV) / 2, (20 + 100) / 2 - textheight(_lopSV) / 2, _lopSV);
    vien(397, 1173, 20, 100);
}

void tieuDeDSSV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(254, 20, 1316, 100);
    settextstyle(10, 0, 8);
    setcolor(Blue);
    outtextxy((254 + 1316) / 2 - textwidth(_dssv) / 2, (20 + 100) / 2 - textheight(_dssv) / 2, _dssv);
    vien(254, 1316, 20, 100);
}

void menuThemLop() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(631, 125, 933, 180);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((631 + 933) / 2 - textwidth(_themLop) / 2, (125 + 170) / 2 - textheight(_themLop) / 2, _themLop);
    vien(631, 933, 125, 180);
    buttonHuyMH();
    buttonSaveMH();
}
// ------------------------------SINH VIEN--------------------------------------


void buttonThoatSV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1100, 125, 1140, 165);
    settextstyle(10, 0, 5);
    setcolor(RED);
    outtextxy((1100 + 1140) / 2 - textwidth(_thoat) / 2, (125 + 165) / 2 - textheight(_thoat) / 2, _thoat);
    vien(1100, 1140, 125, 165);
}

void tieuDeSV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(397, 20, 1173, 100);
    settextstyle(10, 0, 8);
    setcolor(Blue);
    outtextxy((397 + 1173) / 2 - textwidth(_sinhVien) / 2, (20 + 100) / 2 - textheight(_sinhVien) / 2, _sinhVien);
    vien(397, 1173, 20, 100);
}

void menuThemSV() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(560, 125, 1011, 180);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((560 + 1011) / 2 - textwidth(_themSinhVien) / 2, (125 + 180) / 2 - textheight(_themSinhVien) / 2, _themSinhVien);
    vien(560, 1011, 125, 180);
    buttonSaveSV();
}

void menuSuaSV() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(560, 125, 1011, 180);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((560 + 1011) / 2 - textwidth(_suaSinhVien) / 2, (125 + 170) / 2 - textheight(_suaSinhVien) / 2, _suaSinhVien);
    vien(560, 1011, 125, 180);
    buttonSaveSV();
    buttonThoatSV();
}


//----------------------------LOP TIN CHI------------------------

// Nút xem DSSV  nhỏ
void buttonXemDSSV(int x1, int y1, int x2, int y2) {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(x1, y1, x2, y2);
    settextstyle(10, 0, 1);
    setcolor(Blue);
    outtextxy((x1 + x2) / 2 - textwidth(_xemDSSV) / 2, (y1 + y2) / 2 - textheight(_xemDSSV) / 2, _xemDSSV);
    vien(x1, x2, y1, y2);
}

void tieuDeLTC() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(397, 20, 1173, 100);
    settextstyle(10, 0, 8);
    setcolor(Blue);
    outtextxy((397 + 1173) / 2 - textwidth(_lopTinChi) / 2, (20 + 100) / 2 - textheight(_lopTinChi) / 2, _lopTinChi);
    vien(397, 1173, 20, 100);
}


void tieuDeLDK() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(397, 20, 1173, 100);
    settextstyle(10, 0, 7);
    setcolor(Blue);
    outtextxy((397 + 1173) / 2 - textwidth(_dkLopTC) / 2, (20 + 100) / 2 - textheight(_dkLopTC) / 2, _dkLopTC);
    vien(397, 1173, 20, 100);
}

void _menuxemDSSV() {
    setfillstyle(SOLID_FILL, mauNen);
    bar(0, 0, 1525, 777);
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(40, 243, 1490, 744);
    vien(40, 1490, 243, 744);
    settextstyle(10, 0, 3);
    setcolor(Blue);
    // outtextxy(650, 180, _SV);
    tieuDeDSSV();
    buttonBack();
    buttonTien();
    buttonLui();
}

void menuThemLTC() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(560, 125, 1011, 180);
    settextstyle(10, 0, 6);
    setcolor(Blue);
    outtextxy((560 + 1011) / 2 - textwidth(_themLTC) / 2, (125 + 180) / 2 - textheight(_themLTC) / 2, _themLTC);
    vien(560, 1011, 125, 180);
    buttonHuyMH();
    buttonSaveMH();
}

void menuSuaLTC() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(560, 125, 1011, 180);
    settextstyle(10, 0, 6);
    setcolor(Blue);
    outtextxy((560 + 1011) / 2 - textwidth(_suaLTC) / 2, (125 + 180) / 2 - textheight(_suaLTC) / 2, _suaLTC);
    vien(560, 1011, 125, 180);
    buttonHuyMH();
    buttonSaveMH();
}

void menuHuyLTC() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(560, 125, 1011, 180);
    settextstyle(10, 0, 6);
    setcolor(Blue);
    outtextxy((560 + 1011) / 2 - textwidth(_huyLTC) / 2, (125 + 180) / 2 - textheight(_huyLTC) / 2, _huyLTC);
    vien(560, 1011, 125, 180);
    buttonHuyMH();
    buttonSaveMH();
}


// menu hien thi form dang dk ltc
void menuDkLTC() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(560, 125, 1011, 180);
    settextstyle(10, 0, 6);
    setcolor(Blue);
    outtextxy((560 + 1011) / 2 - textwidth(_dkTC) / 2, (125 + 180) / 2 - textheight(_dkTC) / 2, _dkTC);
    vien(560, 1011, 125, 180);
    buttonHuyMH();
    buttonContinue();
}

// menu tong xuat danh sach mon de dang ky

void _menuDKLTC() {
    setfillstyle(SOLID_FILL, mauNen);

    bar(0, 0, 1525, 777);
    tieuDeLDK();

    setfillstyle(SOLID_FILL, BlueNhat);
    bar(40, 243, 1490, 744);
    vien(40, 1490, 243, 744);
    settextstyle(10, 0, 3);
    setcolor(Blue);
    // outtextxy(650, 180, _SV);
    buttonTien();
    buttonLui();
    buttonBack();
}

void buttonThemLTC() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(850, 169, 990, 214);
    settextstyle(10, 0, 2);
    setcolor(Blue);
    outtextxy((850 + 990) / 2 - textwidth(_themLTC) / 2, (169 + 214) / 2 - textheight(_themLTC) / 2, _themLTC);
    vien(850, 990, 169, 214);
}


void buttonHuyLTC() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1010, 169, 1150, 214);
    settextstyle(10, 0, 2);
    setcolor(Blue);
    outtextxy((1010 + 1150) / 2 - textwidth(_huyLTC) / 2, (169 + 214) / 2 - textheight(_huyLTC) / 2, _huyLTC);
    vien(1010, 1150, 169, 214);
}


void buttonDKTC() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1170, 169, 1330, 214);
    settextstyle(10, 0, 2);
    setcolor(Blue);
    outtextxy((1170 + 1330) / 2 - textwidth(_dkTC) / 2, (169 + 214) / 2 - textheight(_dkTC) / 2, _dkTC);
    vien(1170, 1330, 169, 214);
}


void buttonXemDSSV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1350, 169, 1490, 214);
    settextstyle(10, 0, 2);
    setcolor(Blue);
    outtextxy((1350 + 1490) / 2 - textwidth(_xemDSSV) / 2, (169 + 214) / 2 - textheight(_xemDSSV) / 2, _xemDSSV);
    vien(1350, 1490, 169, 214);
}


void _menuLTC() {
    setfillstyle(SOLID_FILL, mauNen);
    bar(0, 0, 1525, 777);
    tieuDeLTC();
    buttonBack();
    buttonThemLTC();
    buttonHuyLTC();
    buttonDKTC();
    buttonXemDSSV();



    setfillstyle(SOLID_FILL, BlueNhat);
    bar(40, 243, 1490, 744);
    vien(40, 1490, 243, 744);
    buttonTien();
    buttonLui();
    //buttonLoc();
   //buttonThoat();
}


void menuXuatSVDK() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(631, 125, 933, 180);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((631 + 933) / 2 - textwidth(_xemDSSV) / 2, (125 + 170) / 2 - textheight(_xemDSSV) / 2, _xemDSSV);
    vien(631, 933, 125, 180);
    buttonHuyMH();
    buttonContinue();
}








// _____________________DIEM_________________________

void buttonDiemTK() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1350, 169, 1490, 214);
    settextstyle(10, 0, 2);
    setcolor(Blue);
    outtextxy((1350 + 1490) / 2 - textwidth(_diemTK) / 2, (169 + 214) / 2 - textheight(_diemTK) / 2, _diemTK);
    vien(1350, 1490, 169, 214);
}

void buttonDiemTB() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1170, 169, 1330, 214);
    settextstyle(10, 0, 2);
    setcolor(Blue);
    outtextxy((1170 + 1330) / 2 - textwidth(_diemTB) / 2, (169 + 214) / 2 - textheight(_diemTB) / 2, _diemTB);
    vien(1170, 1330, 169, 214);
}

void buttonDiem1SV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1010, 169, 1150, 214);
    settextstyle(10, 0, 2);
    setcolor(Blue);
    outtextxy((1010 + 1150) / 2 - textwidth(_diem1SV) / 2, (169 + 214) / 2 - textheight(_diem1SV) / 2, _diem1SV);
    vien(1010, 1150, 169, 214);
}

void buttonSuaDiem() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1350, 169, 1490, 214);
    settextstyle(10, 0, 2);
    setcolor(Blue);
    outtextxy((1350 + 1490) / 2 - textwidth(_suadiem) / 2, (169 + 214) / 2 - textheight(_suadiem) / 2, _suadiem);
    vien(1350, 1490, 169, 214);
}

void tieuDebangdiem() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(397, 20, 1173, 100);
    settextstyle(10, 0, 7);
    setcolor(Blue);
    outtextxy((397 + 1173) / 2 - textwidth(_bangdiem1lop) / 2, (20 + 100) / 2 - textheight(_bangdiem1lop) / 2, _bangdiem1lop);
    vien(397, 1173, 20, 100);
}

void _menuDiem() {
    setfillstyle(SOLID_FILL, mauNen);
    bar(0, 0, 1525, 777);
    tieuDeLTC();
    buttonBack();
    buttonDiemTK();
    buttonDiemTB();
    buttonDiem1SV();

    setfillstyle(SOLID_FILL, BlueNhat);
    bar(40, 243, 1490, 744);
    vien(40, 1490, 243, 744);
    buttonTien();
    buttonLui();
    //buttonLoc();
   //buttonThoat();
}

void menuXemDiem() {
    setfillstyle(SOLID_FILL, mauNen);
    bar(0, 0, 1525, 777);
    tieuDebangdiem();
    buttonBack();


    setfillstyle(SOLID_FILL, BlueNhat);
    bar(40, 243, 1490, 744);
    vien(40, 1490, 243, 744);
    buttonTien();
    buttonLui();
    //buttonLoc();

}
//Nút xem Diem nhỏ
void buttonXemDiem(int x1, int y1, int x2, int y2) {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(x1, y1, x2, y2);
    settextstyle(10, 0, 2);
    setcolor(Blue);
    outtextxy((x1 + x2) / 2 - textwidth(_xemdiem) / 2, (y1 + y2) / 2 - textheight(_xemdiem) / 2, _xemdiem);
    vien(x1, x2, y1, y2);
}

void menuInputDiem1SV() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(585, 125, 975, 180);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((585 + 975) / 2 - textwidth(_xemdiem1SV) / 2, (125 + 180) / 2 - textheight(_xemdiem1SV) / 2, _xemdiem1SV);
    vien(585, 975, 125, 180);
    buttonHuyMH();
    buttonContinue();
}

void tieuDebangdiem1SV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(397, 20, 1173, 100);
    settextstyle(10, 0, 7);
    setcolor(Blue);
    outtextxy((397 + 1173) / 2 - textwidth(_bangDiem) / 2, (20 + 100) / 2 - textheight(_bangDiem) / 2, _bangDiem);
    vien(397, 1173, 20, 100);
}

void tieuDeBangDiemTB() {
    setfillstyle(SOLID_FILL, Be);
    bar(397, 20, 1173, 100);
    settextstyle(10, 0, 6);
    setcolor(Blue);
    outtextxy((397 + 1173) / 2 - textwidth(convertStringToChar("BANG DIEM TRUNG BINH")) / 2, (20 + 100) / 2 - textheight(convertStringToChar("BANG DIEM TRUNG BINH")) / 2, convertStringToChar("BANG DIEM TRUNG BINH"));
    vien(397, 1173, 20, 100);
}
void menuBangDiemTB() {
    setfillstyle(SOLID_FILL, mauNen);
    bar(0, 0, 1525, 777);
    tieuDeLopSV();
    buttonBack();
    //  buttonThem();


    setfillstyle(SOLID_FILL, BlueNhat);
    bar(40, 243, 1490, 744);
    vien(40, 1490, 243, 744);
    buttonTien();
    buttonLui();
    //buttonLoc();
    //buttonThoat();
}
void textDiem1Lop(string tenLop) {
    string lop = "LOP: ";
    lop = lop + tenLop;
    settextstyle(8, 0, 2);
    setbkcolor(mauNen);
    setcolor(Den);
    outtextxy((500 + 1000) / 2 - textwidth(convertStringToChar(_bangDiemTB1Lop)) / 2, (140 + 150) / 2 - textheight(convertStringToChar(_bangDiemTB1Lop)) / 2, convertStringToChar(_bangDiemTB1Lop));
    outtextxy((700 + 800) / 2 - textwidth(convertStringToChar(lop)) / 2, (160 + 170) / 2 - textheight(convertStringToChar(lop)) / 2, convertStringToChar(lop));
}
void textDiemTK1Lop(string tenLop) {
    string lop = "LOP: ";
    lop = lop + tenLop;
    settextstyle(8, 0, 2);
    setbkcolor(mauNen);
    setcolor(Den);
    outtextxy((500 + 1000) / 2 - textwidth(convertStringToChar("DIEM TONG KET CUA LOP")) / 2, (140 + 150) / 2 - textheight(convertStringToChar("DIEM TONG KET CUA LOP")) / 2, convertStringToChar("DIEM TONG KET CUA LOP"));
    outtextxy((700 + 800) / 2 - textwidth(convertStringToChar(lop)) / 2, (160 + 170) / 2 - textheight(convertStringToChar(lop)) / 2, convertStringToChar(lop));
}
void menuNhapDiem() {
        setfillstyle(SOLID_FILL, BlueNhat);
        bar(402, 121, 1151, 748);
        vien(402, 1151, 121, 748);
        setbkcolor(Be);
        setfillstyle(SOLID_FILL, Be);
        bar(631, 125, 933, 180);
        settextstyle(10, 0, 5);
        setcolor(Blue);
        outtextxy((631 + 933) / 2 - textwidth(convertStringToChar("Nhap Diem SV")) / 2, (125 + 170) / 2 - textheight(convertStringToChar("Nhap Diem SV")) / 2, convertStringToChar("Nhap Diem SV"));
        vien(631, 933, 125, 180);
        buttonHuyMH();
        buttonSaveMH();

}