#pragma once
#pragma once
#include "graphics.h" // lib graphics
//#include "conio.h"
#include <iostream>	
#include <string.h>
#include <fstream>
#include <ctime>
#include <cmath>
#include <sstream> 
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <Windows.h>
#include "winbgim.h"
#include <cstring>
#pragma comment(lib,"graphics.lib")
using namespace std;

const int black = 0;
const int blue = 1;
const int green = 2;
const int aqua = 3;
const int red = 4;
const int purple = 5;
const int brown = 6;
const int white = 7;
const int gray = 8;
const int lightblue = 9;
const int lightgreen = 10;
const int lightaqua = 11;
const int lightred = 12;
const int lightpurple = 13;
const int yellow = 14;
const int lightwhite = 15;


/*
**  Danh sach mon hoc
*/

const int MAX_MAMH = 10;
const int MAX_TENMH = 50;

/*
**  Danh sach sinh vien
*/

const int MAX_MASV = 15;
const int MAX_SDT = 11;
const int MAX_MALOPSV = 15;
const int MAX_HOSV = 21;
const int MAX_TENSV = 12;

/*
**  Lop sinh vien
*/

const int MAX_LOPSV = 200;
const int MAXLENGTH_DIEM = 3;

/*
** Lop tin chi
*/

const int MAX_LOPTC = 10000;
#define  SV_MAX 1000 
/*
** File data
*/
string dataMH = "MH.txt";
string dataSV = "SV.txt";
string dataLSV = "LopSV.txt";
string dataLTC = "DSLTC.txt";
string dataDK = "DSDK.txt";

//----------------SCREEN----------
#define SCREEN_WIDTH  1525
#define SCREEN_HEIGHT  800


//-----------------BACKGROUND COLOR
#define BACKGROUND_TABLE COLOR(167, 206, 225)
#define BACKGROUND_COLOR COLOR(255, 246, 245)
#define BORDER_TABLE COLOR(52, 113, 235)
#define  BORDER_COLOR COLOR(241, 208, 215)
//#define DISABLE_COLOR COLOR(127,124,132) 



//-------------------------Button --------------------

#define TAB_DEFAULT_BACKGROUND COLOR(241, 208, 215)
#define TAB_ON_SELECTED_BACKGROUND COLOR(167, 206, 225)
char _tieuDe[] = { "Quan Ly Sinh Vien" };
char _tieuDe2[] = { "Do An QLSV" };
char _luuY[] = { "*Luu Y:" };
char _lopTinChi[] = { "LOP TIN CHI" };
char _sinhVien[] = { "SINH VIEN" };
char _lopSV[] = { "LOP SINH VIEN" };
char _themLop[] = { "THEM LOP" };
char _monHoc[] = { "MON HOC" };
char _themMH[] = { "THEM MON HOC" };
char _suaMH[] = { "SUA MON HOC" };
char _diem[] = { "DIEM" };
char _back[] = { "BACK" };
char _them[] = { "THEM" };
char _huy[] = { "HUY" };
char _save[] = { "SAVE" };
char _locM[] = { "LOC" };
char _sangTrai[] = { ">" };
char _sangPhai[] = { "<" };
char _loc[] = { "LOC" };
char _thoat[] = { "X" };
char _themSinhVien[] = { "THEM SINH VIEN" };
char _suaSinhVien[] = { "SUA SINH VIEN" };
char _timkiem[] = { "TIM KIEM" };
char _themLTC[] = { "THEM LTC" };
char _suaLTC[] = { "SUA LTC" };
char _huyLTC[] = { "HUY LTC" };
char _dkTC[] = { "DANG KY TC" };
char _xemDSSV[] = { "XEM DSSV" };
char _dssv[] = { "DANH SACH SINH VIEN" };
char _SV[] = { "SINH VIEN: " };
char _dkLopTC[] = { "DANG KY LOP TIN CHI" };
char _continue[] = { "TIEP TUC" };
char _diemTK[] = { "DIEM TK" };
char _diemTB[] = { "DIEM TB" };
char _diem1SV[] = { "DIEM 1 SV" };
char _suadiem[] = { "SUA DIEM" };
char _bangdiem1lop[] = { "BANG DIEM 1 LOP" };
char _xemdiem[] = { "Xem Diem" };
char _xemdiem1SV[] = { "Xem Diem 1 SV" };
char _bangDiem[] = { "BANG DIEM" };
char _bangDiemTB1Lop[] = { "BANG THONG KE DIEM TRUNG BINH KHOA HOC" };
//-------------------------Enum --------------------
enum thaoTac { THEM, LOC, BACK, XUAT, SUA, HUY, XEM, DANGKY, XUATDK, THOAT, XEM_DSDK, DIEM1SV, DIEMTB, DIEMTK };
//-------------------------Trang --------------------

int maxDong = 10;
int maxMH = 5;
int kcY = 35; // khoảng cách giữa y trên và y dưới 
int tableTop = 280;
int tableLeft = 100;
int tableBottom = 610;
//MH
int tableRightMH = 1435;

//Lop
int tableRightLop = 1140;
//LopTC
int tableRightLopTC = 1340;

/*
int maxDong = 10;
int kcY = 30; // khoảng cách giữa y trên và y dưới
int tableTop =    150;  // 280;
int tableLeft =  50; // 100;
int tableRight =   1200; // 1435;
int tableBottom =   400; // 610;
*/
//---------------------Mau--------------------------
#define XanhLe COLOR(108,135,126)
#define HongNhat COLOR(241,208,215)
#define Blue COLOR(19,6,189)
#define Be COLOR(210,207,157)
#define Den COLOR(2,50,53)
#define mauNen COLOR(250,241,241)
#define gray COLOR(127,125,125)
#define graynhat COLOR(217,241,214)
#define BlueNhat COLOR(191,207,255)
#define Red COLOR(199,51,51)