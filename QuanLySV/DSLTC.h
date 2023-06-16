#pragma once
#include "Const.h"
#include "DSDK.h"
#include "UI.h"
#include "MH.h"
#include"Input.h"
#include "Button.h"

class LopTC {
private:
	int maLopTC;
	string maMH;
	int nienKhoa;
	int hocKy;
	int nhom;
	int SVMIN;
	int SVMAX;
	bool huyLop;
	int soSVDK;
	DSDK dsdk;
public:

	LopTC();

	void setMaLopTC(int maLopTC);

	void setMaMH(string maMH);

	void setNienKhoa(int khoa);

	void setHocKy(int hocKy);

	void setNhom(int nhom);

	void setSVMax(int svMax);

	void setSVMin(int svMin);

	void setTrangThai(bool huyLop);

	void setSoSVDK(int soSVDK);

	void setDSDK(DSDK DS);

	int getMaLopTC();

	string getMaMH();

	int getNienKhoa();

	int getHocKy();

	int getNhom();

	int getSVMax();

	int getSVMin();

	bool getTrangThai();

	int getSoSVDK();

	DSDK& getDSDK();

	bool checkTrung_LTC(LopTC ltc);

	void taoMaLop_LTC(int nLTC);

	void huyLopTC();
};

class DSLTC {
private:
	LopTC* lopTC[MAX_LOPTC] = { NULL };
	int n;
	int maxN;
public:
	DSLTC();

	int getN();

	void findMaxN();

	int getMaxN();

	bool isNull_LTC();

	bool isFull_LTC();

	LopTC*& getLopTC(int viTri);

	int them_LTC(LopTC* LTC);

	void update_LTC(LopTC* LTC, int viTri);

	bool checkSVDK_LTC(int maLopTC, string maSV);

	bool checkDK_LTC(int viTri, string maSV);


	int xoa_LTC(int maLopTC);   // nondone

	int tim_LTC(int maLopTC);

	void dk_LTC(int viTri, SVDangKy sv);

	void dkMH_LTC(int maLopTC, SVDangKy sv);

	bool checkTrung(LopTC* lop);

	int checkTrungDS_LTC(LopTC* ltc, int viTri);

	void huyLopTCTheoKhoaVaHK_LTC(int khoa, int HK);

	int checkLopTheoKhoaVaHK_LTC(int khoa, int HK);

	int checkLopDaDK(int vitri, string masv);

	void writeData_LTC(LopTC* LTC, ofstream& fileOut);

	void writeDataDS_LTC();

	void writeDataDS_DK();

	void loadDataDS_LTC();

	void loadDataDS_DK();  // nondone

	void nhapDiem(string str,int left,int right,int top ,int bottom,int viTriTC,int viTriSV);

	void xuatDS1Trang_LTC(LopTC* loptc[], Subject arrMH[], int soLuongMH, int batDau, int ketThuc, Table Bang, int checkOut, string maSV);


	void xuatDSTheoTrang_LTC(treeMH DSMH, int& viTriChon, int tongSoDong, thaoTac& hDLTC, char* s, int& thaoTacRoi, DSSV sv);

	void inputNhapLTC(string str1, string str2, string str3, string str4,
		string str5, string str6, string str7, int check, treeMH DSMH, int& viTriChon, thaoTac& hDLTC);

	void dangKyTheoLTC(treeMH DSMH, string maSV, int khoa, int HK, thaoTac& hDLTC);

	void inputDkLTC(treeMH DSMH, string str1, string str2, string str3, DSSV sv, thaoTac& hDLTC);

	void huyLTC(string str1, string str2, thaoTac& hDLTC);

	void xuatDSDK(DSSV sv, thaoTac& hDLTC, treeMH DSMH);

	void xuatDiem1Trang1LTC(LopTC* loptc, DSSV sv, int batDau, int ketThuc, Table Bang, thaoTac& hDLTC);

	void xuatDiemTheoTrang1LTC(LopTC* loptc, DSSV sv, int tongSoDong, thaoTac& hDLTC);

	void xuatDiemLTC(treeMH DSMH, DSSV sv, int tongSoDong, thaoTac& hDLTC);

	void xuatDiem1Trang1SV(LopTC* loptc[], Subject arrMH[], int soLuongMon, int batDau, int ketThuc, Table Bang, string maSV);

	void xuatDiemTheoTrang1SV(LopTC* loptc[], treeMH DSMH, int tongSoDong, thaoTac& hDLTC, string masv, string hoTen);

	void xuatDiem1SV(treeMH DSMH, DSSV sv, thaoTac& hDMH);

	void xuatDiem(treeMH DSMH, DSSV sv, int diemGi);

	void xuat1TrangDiem(DSSV sv,string arrLop[100], int batDau, int ketThuc, Table newTable);

	void xuatDiemTB1Lop(DSSV sv,string str, int n);

	void xuat1TrangDiemTB1Lop(DSSV sv,string str, int batDau, int ketThuc, Table newTable);

	float diemMax1Mon(string monHoc, string maSV);

	void xuatDiemTK1Lop(treeMH DSMH, DSSV sv,string str, int tongSoSV);

	void xuat1TrangDiemTK1Lop(DSSV sv,string str, int batDau, int ketThuc, Table newTable, int& nhan, Subject* arr, int batDauMH, int ktMH, int tongSoTrang, int tongSoMH);

	void freeDS_LTC();

	void menuLTC();

	void menuDiem();
};



// ============= Lop Tin Chi ==============

LopTC::LopTC() {
	this->maLopTC = 0;
	this->maMH = "";
	this->nienKhoa = 0;
	this->hocKy = 0;
	this->nhom = 0;
	this->SVMIN = 0;
	this->SVMAX = 0;
	this->huyLop = true;
	this->soSVDK = 0;

}

void LopTC::setMaLopTC(int maLopTC) {
	this->maLopTC = maLopTC;
}

void LopTC::setMaMH(string maMH) {
	this->maMH = maMH;
}

void LopTC::setNienKhoa(int khoa) {
	this->nienKhoa = khoa;
}

void LopTC::setHocKy(int hocKy) {
	this->hocKy = hocKy;
}

void LopTC::setNhom(int nhom) {
	this->nhom = nhom;
}

void LopTC::setSVMin(int SVMin) {
	this->SVMIN = SVMin;
}

void LopTC::setSVMax(int SVMax) {
	this->SVMAX = SVMax;
}

void LopTC::setTrangThai(bool trangThai) {
	this->huyLop = trangThai;
}

void LopTC::setDSDK(DSDK DS) {
	this->dsdk = DS;
}

int LopTC::getMaLopTC() {
	return this->maLopTC;
}

string LopTC::getMaMH() {
	return this->maMH;
}

int LopTC::getNienKhoa() {
	return this->nienKhoa;
}

int LopTC::getHocKy() {
	return this->hocKy;
}

int LopTC::getNhom() {
	return  this->nhom;
}

int LopTC::getSVMax() {
	return this->SVMAX;
}

int LopTC::getSVMin() {
	return this->SVMIN;
}

bool LopTC::getTrangThai() {
	return this->huyLop;
}

void LopTC::setSoSVDK(int soSVDK) {
	this->soSVDK = soSVDK;
}

int LopTC::getSoSVDK() {
	return this->soSVDK;
}

DSDK& LopTC::getDSDK() {
	return this->dsdk;
}

bool LopTC::checkTrung_LTC(LopTC ltc) {

	if (this->maMH == ltc.maMH && this->nienKhoa == ltc.nienKhoa &&
		(this->hocKy == ltc.hocKy && this->nhom == ltc.nhom)) {
		return true;
	}

	return false;
}

void LopTC::huyLopTC() {
	if (soSVDK < SVMIN && huyLop == false)
		//if(soSVDK != 0 && soSVDK < svMin && huyLop == false)
		this->huyLop = true;
}


void LopTC::taoMaLop_LTC(int nLTC) {
	this->maLopTC = nLTC + 1;
}

//	============= Danh Sach Lop Tin Chi ==============

DSLTC::DSLTC() {
	this->n = 0;
	this->maxN = 0;
}

int DSLTC::getN() {
	return this->n;
}

void DSLTC::findMaxN() {
	maxN = 0;
	if (isNull_LTC() != true) {
		for (int i = 0; i < n; i++) {
			if (lopTC[i]->getMaLopTC() > maxN) {
				maxN = lopTC[i]->getMaLopTC();
			}
		}
	}
}

int DSLTC::getMaxN() {
	return ++maxN;
}

bool DSLTC::isFull_LTC() {
	return this->n == MAX_LOPTC;
}

bool DSLTC::isNull_LTC() {
	return this->n == 0;
}

int DSLTC::tim_LTC(int maLopTC) {
	for (int i = 0; i < this->n; i++) {
		if (this->lopTC[i]->getMaLopTC() == maLopTC) {
			return i;
		}
	}
	return -1;
}

int DSLTC::them_LTC(LopTC* LTC) {
	if (isFull_LTC() == true) return 0;
	lopTC[this->n] = new LopTC();
	this->lopTC[this->n++] = LTC;
	return 1;
}

void DSLTC::update_LTC(LopTC* LTC, int viTri) {
	lopTC[viTri]->setMaLopTC(LTC->getMaLopTC());
	lopTC[viTri]->setMaMH(LTC->getMaMH());
	lopTC[viTri]->setNienKhoa(LTC->getNienKhoa());
	lopTC[viTri]->setHocKy(LTC->getHocKy());
	lopTC[viTri]->setNhom(LTC->getNhom());
	lopTC[viTri]->setSVMin(LTC->getSVMin());
	lopTC[viTri]->setSVMax(LTC->getSVMax());

}

bool DSLTC::checkSVDK_LTC(int maLopTC, string maSV) {
	int vt = 0;
	for (; vt < n && this->lopTC[vt]->getMaLopTC() != maLopTC; vt++) {
		if (lopTC[vt]->getMaLopTC() == maLopTC) {
			return this->lopTC[vt]->getDSDK().checkSV_DK(maSV);
		}
	}


	return false;
}

bool DSLTC::checkDK_LTC(int viTri, string maSV) {
	return this->lopTC[viTri]->getDSDK().checkSV_DK(maSV);

	return false;
}

LopTC*& DSLTC::getLopTC(int viTri) {
	return lopTC[viTri];
}

int DSLTC::xoa_LTC(int maLopTC) {
	int viTri = tim_LTC(maLopTC);
	if (viTri >= 0) {
		if (!lopTC[viTri]->getDSDK().isNull_DSDK())
			lopTC[viTri]->getDSDK().free_DSDK();

		delete this->lopTC[viTri];
		for (int i = viTri; i < this->n; i++)
			this->lopTC[i] = this->lopTC[i + 1];

		this->n--;

		MessageBox(
			NULL,
			(LPCWSTR)convertCharArrayToLPCWSTR("XOA LOP TIN CHI THANH CONG !!!"),
			(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
			MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
		);
		return 1;
	}

	return -1;
}

void DSLTC::dk_LTC(int viTri, SVDangKy sv) {
	if (viTri < n) {
		if (this->lopTC[viTri]->getSoSVDK() == 0) {
			DSDK SV(this->lopTC[viTri]->getSVMax());
			lopTC[viTri]->setDSDK(SV);
		}
		this->lopTC[viTri]->getDSDK().them_DK(sv);
		this->lopTC[viTri]->setSoSVDK(this->lopTC[viTri]->getSoSVDK() + 1);

	}
}

void DSLTC::dkMH_LTC(int maLopTC, SVDangKy sv) {
	for (int i = 0; i < n; i++) {
		if (this->lopTC[i]->getMaLopTC() == maLopTC) {
			//cout << " 1 ";

			dk_LTC(i, sv); return;
		}
	}
}

bool DSLTC::checkTrung(LopTC* lop) {
	if (this->isNull_LTC()) return false;

	for (int i = 0; i < n; i++) {
		if (lop->getMaMH() == lopTC[i]->getMaMH() && lop->getNienKhoa() == lopTC[i]->getNienKhoa()
			&& lop->getHocKy() == lopTC[i]->getHocKy() && lop->getNhom() == lopTC[i]->getNhom()) {
			return true;
		}
	}
	return false;
}

int DSLTC::checkTrungDS_LTC(LopTC* ltc, int viTri) {
	if (this->isNull_LTC()) return false;

	for (int i = 0; i < n; i++) {
		if (i != viTri)
			if (this->lopTC[i]->checkTrung_LTC(*(ltc))) return ltc->getNienKhoa();
	}

	return -1;
}

int DSLTC::checkLopTheoKhoaVaHK_LTC(int khoa, int HK) {
	for (int i = 0; i < n; i++) {

		if (this->lopTC[i]->getNienKhoa() == khoa && this->lopTC[i]->getHocKy() == HK)
			return i;
	}

	return  -1;
}

int DSLTC::checkLopDaDK(int viTri, string masv) {
	for (int i = 0; i < n; i++) {
		if (viTri != i && lopTC[i]->getMaMH() == lopTC[viTri]->getMaMH() &&
			lopTC[i]->getNienKhoa() == lopTC[viTri]->getNienKhoa() && lopTC[i]->getHocKy() == lopTC[viTri]->getHocKy() && lopTC[i]->getSoSVDK() > 0) {
			if (checkDK_LTC(i, masv) == true) return lopTC[i]->getNhom();
		}
	}
	return -1;
}


void DSLTC::huyLopTCTheoKhoaVaHK_LTC(int khoa, int HK) {
	for (int i = 0; i < n; i++) {
		if (this->lopTC[i]->getNienKhoa() == khoa && this->lopTC[i]->getHocKy() == HK && lopTC[i]->getSoSVDK() < lopTC[i]->getSVMin()) {
			this->lopTC[i]->huyLopTC();
			this->lopTC[i]->getDSDK().free_DSDK();
		}

	}
	MessageBox(
		NULL,
		(LPCWSTR)convertCharArrayToLPCWSTR("DA HUY CAC LOP TIN CHI KHONG DU DIEU KIEN MO"),
		(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
		MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
	);

}


void DSLTC::writeData_LTC(LopTC* LTC, ofstream& fileOut) {
	char temp = ',';
	fileOut << LTC->getMaLopTC();
	fileOut << temp;
	fileOut << LTC->getMaMH();
	fileOut << temp;
	fileOut << LTC->getNienKhoa();
	fileOut << temp;
	fileOut << LTC->getHocKy();
	fileOut << temp;
	fileOut << LTC->getNhom();
	fileOut << temp;
	fileOut << LTC->getSVMax();
	fileOut << temp;
	fileOut << LTC->getSVMin();
	fileOut << temp;
	fileOut << LTC->getTrangThai();

}




void DSLTC::writeDataDS_LTC() {
	ofstream fileOut;
	fileOut.open(dataLTC.c_str(), ios::out);
	if (fileOut.is_open()) {
		fileOut << this->n;
		fileOut << "\n";
		for (int i = 0; i < this->n; i++) {
			writeData_LTC(this->lopTC[i], fileOut);
			if (i != n - 1) {
				fileOut << "\n";
			}
		}

	}
	fileOut.close();
}



void DSLTC::writeDataDS_DK() {
	ofstream fileOut(dataDK.c_str(), ios::out);
	if (fileOut.is_open()) {
		int maLopTC;
		int nSV;
		for (int i = 0; i < n; i++) {
			maLopTC = lopTC[i]->getMaLopTC();
			nSV = lopTC[i]->getSoSVDK();
			lopTC[i]->getDSDK().writeData_DK(maLopTC, fileOut);


		}
		fileOut.close();
	}

}


void DSLTC::loadDataDS_LTC() {
	ifstream fileIn; char temp;
	fileIn.open(dataLTC.c_str(), ios::in);

	if (fileIn.is_open()) {
		int tempInt; string tempStr;
		int soLuong = 0;


		fileIn >> soLuong;

		for (int i = 0; i < soLuong; i++) {
			lopTC[n] = new LopTC;
			fileIn >> tempInt;	lopTC[n]->setMaLopTC(tempInt); //cout << tempInt << " ";
			//	if (tempInt == 0) break;
			fileIn >> temp;
			getline(fileIn, tempStr, ','); lopTC[n]->setMaMH(tempStr); //cout << tempStr << " ";
			fileIn >> tempInt; lopTC[n]->setNienKhoa(tempInt);// cout << tempInt << " ";
			fileIn >> temp;
			fileIn >> tempInt; lopTC[n]->setHocKy(tempInt);//cout << tempInt << " ";
			fileIn >> temp;
			fileIn >> tempInt; lopTC[n]->setNhom(tempInt); //cout << tempInt << " ";
			fileIn >> temp;
			fileIn >> tempInt; lopTC[n]->setSVMax(tempInt);// cout << tempInt << " ";
			fileIn >> temp;
			fileIn >> tempInt; lopTC[n]->setSVMin(tempInt); //cout << tempInt << " ";
			fileIn >> temp;
			fileIn >> tempInt; lopTC[n]->setTrangThai(bool(tempInt)); //cout << tempInt << " ";


			this->n++;
			if (fileIn.eof()) break;

		}
	}
	else cout << "NOOO";
	findMaxN();

	fileIn.close();
}



void DSLTC::loadDataDS_DK() {
	ifstream fileIn; char temp; int maLop; int viTriLop = 0; string tempStr; float tempFloat;
	fileIn.open(dataDK.c_str(), ios::in);
	if (fileIn.is_open()) {

		while (!fileIn.eof()) {
			fileIn >> maLop;
			viTriLop = this->tim_LTC(maLop);
			fileIn >> temp;
			SVDangKy sv;

			getline(fileIn, tempStr, ',');
			sv.setMaSV(tempStr);
			fileIn >> tempFloat;
			sv.setDiem(tempFloat);

			if (this->lopTC[viTriLop]->getDSDK().checkSV_DK(sv.getMaSV())) continue;

			this->lopTC[viTriLop]->getDSDK().them_DK(sv);
			this->lopTC[viTriLop]->setSoSVDK(this->lopTC[viTriLop]->getSoSVDK() + 1);


			if (fileIn.eof()) break;

		}
	}


	fileIn.close();
}



void DSLTC::xuatDS1Trang_LTC(LopTC* loptc[], Subject arrMH[], int soLuongMH, int batDau, int ketThuc, Table Bang, int checkOut, string masv) {

	int soDong = ketThuc % maxDong;
	if (soDong == 0) soDong = maxDong;
	if (ketThuc == 0 && batDau == 0) soDong = maxDong;
	else {
		int soDongTrong = maxDong - ketThuc % maxDong;
		soDong = ketThuc % maxDong == 0 ? ketThuc : ketThuc + soDongTrong;
	}

	string strSTT;	string trangThai = "TRUE"; int viTriMH = 0;
	int x = tableLeft;
	int y = tableTop + kcY / 2 - textheight(convertStringToChar(strSTT)) / 2;
	setbkcolor(BlueNhat); setcolor(Den); settextstyle(10, 0, 1);


	for (int i = batDau; i < soDong; i++) {
		setbkcolor(BlueNhat); setcolor(Den); settextstyle(10, 0, 1);
		y += kcY;
		if (i >= ketThuc) {
			x = tableLeft;
			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(0)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(1)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(2)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(3)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(4)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(5)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(6)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(6)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(7)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(7)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(8)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(8)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(9)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(9)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(10)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(10)->getChieuRong();

			//		outtextxy(x, y ,
				//		convertStringToChar(string((Bang.getCols(11)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
				//	khoangTrang(x, y - kcY + textheight(convertStringToChar(strSTT)), x + Bang.getCols(11)->getChieuRong(), y + textheight(convertStringToChar(strSTT)));


			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(11)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));




			continue;
		}


		strSTT = convertIntToString(i + 1);

		x = tableLeft;

		// xoa STT cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat STT moi
		outtextxy(x + (Bang.getCols(0)->getChieuRong() / 2 - textwidth(convertStringToChar(strSTT)) / 2), y, convertStringToChar(strSTT));
		x += Bang.getCols(0)->getChieuRong();

		// xoa MA LOP
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat MA LOP moi
		outtextxy(x + (Bang.getCols(1)->getChieuRong() / 2 - textwidth(convertIntToChar(loptc[i]->getMaLopTC())) / 2), y, convertIntToChar(loptc[i]->getMaLopTC()));
		x += Bang.getCols(1)->getChieuRong();


		// xoa MA MON HOC cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat MA MON HOC moi
		outtextxy(x + (Bang.getCols(2)->getChieuRong() / 2 - textwidth(convertStringToChar(loptc[i]->getMaMH())) / 2), y, convertStringToChar(loptc[i]->getMaMH()));
		x += Bang.getCols(2)->getChieuRong();

		// xoa TEN MON HOC cu 
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat TEN MON HOC moi
		for (int j = 0; j < soLuongMH; j++) {
			if (arrMH[j].getMaMH() == loptc[i]->getMaMH()) {
				viTriMH = j; break; //j = soLuongMH;
			}
		}
		outtextxy(x + (Bang.getCols(3)->getChieuRong() / 2 - textwidth(arrMH[viTriMH].getTenMH()) / 2), y, arrMH[viTriMH].getTenMH());
		x += Bang.getCols(3)->getChieuRong();

		// xoa KHOA cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat KHOA moi
		outtextxy(x + (Bang.getCols(4)->getChieuRong() / 2 - textwidth(convertIntToChar(loptc[i]->getNienKhoa())) / 2), y, convertIntToChar(loptc[i]->getNienKhoa()));
		x += Bang.getCols(4)->getChieuRong();

		// xoa HK cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat HK moi
		outtextxy(x + (Bang.getCols(5)->getChieuRong() / 2 - textwidth(convertIntToChar(loptc[i]->getHocKy())) / 2), y, convertIntToChar(loptc[i]->getHocKy()));
		x += Bang.getCols(5)->getChieuRong();

		// xoa NHOM cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(6)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat NHOM moi
		outtextxy(x + (Bang.getCols(6)->getChieuRong() / 2 - textwidth(convertIntToChar(loptc[i]->getNhom())) / 2), y, convertIntToChar(loptc[i]->getNhom()));
		x += Bang.getCols(6)->getChieuRong();

		// xoa SL cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(7)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat SL moi
		outtextxy(x + (Bang.getCols(7)->getChieuRong() / 2 - textwidth(convertIntToChar(loptc[i]->getSVMax())) / 2), y, convertIntToChar(loptc[i]->getSVMax()));
		x += Bang.getCols(7)->getChieuRong();

		// xoa SL CON LAI  cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(8)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat SL CON LAI moi
		outtextxy(x + (Bang.getCols(8)->getChieuRong() / 2 - textwidth(convertIntToChar(loptc[i]->getSVMax() - loptc[i]->getSoSVDK())) / 2), y, convertIntToChar(loptc[i]->getSVMax() - loptc[i]->getSoSVDK()));
		x += Bang.getCols(8)->getChieuRong();

		// xoa MIN cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(9)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat MIN moi
		outtextxy(x + (Bang.getCols(9)->getChieuRong() / 2 - textwidth(convertIntToChar(loptc[i]->getSVMin())) / 2), y, convertIntToChar(loptc[i]->getSVMin()));
		x += Bang.getCols(9)->getChieuRong();

		// xoa SL cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(10)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat SL moi
		string trangThai;
		if (loptc[i]->getTrangThai() == 0) trangThai = "FALSE";
		else trangThai = "TRUE";
		outtextxy(x + (Bang.getCols(10)->getChieuRong() / 2 - textwidth(convertStringToChar(trangThai)) / 2), y, convertStringToChar(trangThai));
		x += Bang.getCols(10)->getChieuRong();
		//   moi themmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm

		// xoa Trang thai  cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(11)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat trang the moi
		setbkcolor(BlueNhat); setcolor(Red); settextstyle(10, 0, 1);
		if (checkOut == 1) {
			string textDK = "Da DK";

			if (checkDK_LTC(tim_LTC(loptc[i]->getMaLopTC()), masv) == true) {
				outtextxy(x + (Bang.getCols(11)->getChieuRong() / 2 - textwidth(convertStringToChar(textDK)) / 2), y, convertStringToChar(textDK));

			}

		}
		else if (checkOut == 2) {
			if (lopTC[i]->getSoSVDK() > 0 && lopTC[i]->getDSDK().getDiemSV(0) >= 0) {
				outtextxy(x + (Bang.getCols(11)->getChieuRong() / 2 - textwidth(convertStringToChar("Xem Diem")) / 2), y, convertStringToChar("Xem Diem"));

			}
			else if (lopTC[i]->getSoSVDK() >= lopTC[i]->getSVMin() && lopTC[i]->getDSDK().getDiemSV(0) < 0) {
				outtextxy(x + (Bang.getCols(11)->getChieuRong() / 2 - textwidth(convertStringToChar("Nhap Diem")) / 2), y, convertStringToChar("Nhap Diem"));

			}
		}
		else {

			outtextxy(x + (Bang.getCols(11)->getChieuRong() / 2 - textwidth(convertStringToChar("Xem DSSV")) / 2), y, convertStringToChar("Xem DSSV"));

			//string textXemDSSV = "Xem DSSV";
			//outtextxy(x + (Bang.getCols(11)->getChieuRong() / 2 - textwidth(convertStringToChar(textXemDSSV)) / 2), y, convertStringToChar(textXemDSSV));
			// (y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong;
			//buttonXemDSSV(x, y - kcY + textheight(convertStringToChar(strSTT)), x + Bang.getCols(11)->getChieuRong(), y + textheight(convertStringToChar(strSTT)));
		}

	}

}




void DSLTC::xuatDSTheoTrang_LTC(treeMH DSMH, int& viTriChon, int tongSoDong, thaoTac& hDLTC, char* s, int& thaoTacRoi, DSSV sv) {
	int checkOut = 0; string masv = "";
	int nFilter = n; int soLuongMH = 0;
	soLuongMH = DSMH.soNode(DSMH.getRoot());
	Subject* arrMH = new Subject[soLuongMH];
	soLuongMH = 0;
	DSMH.nhapCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH);

	LopTC* loptc[MAX_LOPTC];// = { NULL };
	for (int i = 0; i < n; i++) {
		loptc[i] = new LopTC();
		loptc[i] = this->lopTC[i];
	}


	int soDu = (tongSoDong % maxDong > 0) ? 1 : 0;

	int tongSoTrang = tongSoDong / maxDong + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc = (tongSoDong > maxDong) ? maxDong : tongSoDong;

	Table newTable = table_LTC();
	newTable.drawTable(maxDong);

	xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, newTable, checkOut, masv);



	string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));


	int x, y;
	bool ok = true;

	while (ok) {
		//delay(200);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (tableLeft <= x && x <= tableRightLopTC && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
				int viTri = (y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong;

				if (lopTC[viTri]->getSoSVDK() > 0) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("KHONG THE XOA LOP DA CO SINH VIEN DANG KY !!!"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
				}
				else {
					int tmp = MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON XOA LOP TIN CHI?"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
					);
					if (tmp == IDYES) {

						this->xoa_LTC(lopTC[(y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong]->getMaLopTC());

						//	writeDataDS_LTC();

						break;
					}
				}


			}
			else if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {

				batDau = batDau - maxDong;
				ketThuc = batDau + maxDong;
				trangHienTai--;
				xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, newTable, checkOut, masv);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if ((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang) {
				batDau = batDau + maxDong;
				ketThuc = (ketThuc + maxDong > tongSoDong) ? tongSoDong : ketThuc + maxDong;
				trangHienTai++;
				xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, newTable, checkOut, masv);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));

			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
				thaoTacRoi = 1;
				hDLTC = BACK;
				break;

			}
			else if (850 <= x && x <= 990 && 169 <= y && y <= 214) {
				hDLTC = THEM;
				thaoTacRoi = 1;
				break;
			}
			else if (1010 <= x && x <= 1150 && 169 <= y && y <= 214) {
				hDLTC = HUY;
				thaoTacRoi = 1;
				break;
			}
			else if (1170 <= x && x <= 1330 && 169 <= y && y <= 214) {
				hDLTC = DANGKY;
				thaoTacRoi = 1;
				break;
			}
			else if (1359 <= x && x <= 1490 && 169 <= y && y <= 214) {
				hDLTC = XUATDK;
				break;
			}


			else if (tableRightLopTC < x && x <= 1440 && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
				int indexXemDiem = (y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong;
				if (lopTC[indexXemDiem]->getSoSVDK() == 0) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("CHUA CO SINH VIEN DANG KY !!! "),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
					break;
				}
				else {
					int index = (y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong;
					int maLop = lopTC[index]->getMaLopTC();
					int viTriMH;
					for (int j = 0; j < soLuongMH; j++) {
						if (arrMH[j].getMaMH() == lopTC[index]->getMaMH()) {
							viTriMH = j; break; //j = soLuongMH;
						}
					}
					string monHoc(arrMH[viTriMH].getTenMH());
					cleardevice();
					buttonBack();
					tieuDeDSSV();
					_menuxemDSSV();
					int xoa = 0;
					DSSV1LTC(convertIntToString(maLop), monHoc, convertIntToString(lopTC[index]->getSoSVDK()), convertIntToString(lopTC[index]->getNienKhoa()),
						convertIntToString(lopTC[index]->getHocKy()), convertIntToString(lopTC[index]->getNhom()));
					// " danh sach sinh vien" ....
					lopTC[indexXemDiem]->getDSDK().xuatDSTrang_DK(sv, lopTC[indexXemDiem]->getSoSVDK(), hDLTC, xoa);
					lopTC[indexXemDiem]->setSoSVDK(lopTC[indexXemDiem]->getSoSVDK() - xoa);
					//writeDataDS_DK();
					//writeDataDS_LTC();
					break;
				}
			}
		}
		else if (ismouseclick(WM_RBUTTONDOWN)) {
			getmouseclick(WM_RBUTTONDOWN, x, y);
			clearmouseclick(WM_RBUTTONDOWN);

			if (tableLeft <= x && x <= tableRightLopTC && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {

				viTriChon = (y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong;
				if (lopTC[viTriChon]->getSoSVDK() > 0 && lopTC[viTriChon]->getDSDK().getDiemSV(0) > 0) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("LOP DA NHAP DIEM. KHONG THE SUA !!!"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
					hDLTC = XUAT;
					break;
				}
				menuSuaLTC();

				inputNhapLTC(convertIntToString(lopTC[viTriChon]->getMaLopTC()), lopTC[viTriChon]->getMaMH(), convertIntToString(lopTC[viTriChon]->getNienKhoa()),
					convertIntToString(lopTC[viTriChon]->getHocKy()), convertIntToString(lopTC[viTriChon]->getNhom()), convertIntToString(lopTC[viTriChon]->getSVMin()),
					convertIntToString(lopTC[viTriChon]->getSVMax()), 2, DSMH, viTriChon, hDLTC);
				hDLTC = XUAT;
				break;
			}

		}

	}

	delete[] arrMH;
	newTable.freeTable();
}



void DSLTC::inputNhapLTC(string str1, string str2, string str3, string str4,
	string str5, string str6, string str7, int check, treeMH DSMH, int& viTriChon, thaoTac& hDDK) {

	if (check == 0 && n == MAX_LOPTC) {
		MessageBox(
			NULL,
			(LPCWSTR)convertCharArrayToLPCWSTR("DANH SACH DA DAY. KHONG THE THEM LOP !!!"),
			(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
			MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
		);
		hDDK = XUAT;
		return;
	}

	int nInput = 7;
	Input* input[7];
	int abc = 0;
	if (check == 0) {
		abc = getMaxN();
		str1 = convertIntToString(abc);

	}




	input[0] = new Input(str1, 3, "Ma Lop", 50, 0, 600, 1100, 200, 240, graynhat, 0, 3);
	input[1] = new Input(str2, 2, "Ma Mon Hoc", 50, 0, 600, 1100, 270, 310, graynhat, 0, 3);
	input[2] = new Input(str3, 3, "Nien Khoa", 4, 0, 600, 1100, 340, 380, graynhat, 0, 3);
	input[3] = new Input(str4, 3, "Hoc Ky", 1, 0, 600, 1100, 410, 450, graynhat, 0, 3);
	input[4] = new Input(str5, 3, "Nhom", 2, 0, 600, 1100, 480, 520, graynhat, 0, 3);
	input[5] = new Input(str6, 3, "SL Min", 4, 0, 600, 1100, 550, 590, graynhat, 0, 3);
	input[6] = new Input(str7, 3, "SL Max", 4, 0, 600, 1100, 620, 660, graynhat, 0, 3);

	int x = -1; int y = -1;
	input[0]->draw();
	input[1]->draw();
	input[2]->draw();
	input[3]->draw();
	input[4]->draw();
	input[5]->draw();
	input[6]->draw();

	LopTC* lop = new LopTC();
	if (check == 0) {
		while (1) {
			// delay(10);
			if (ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				clearmouseclick(WM_LBUTTONDOWN);

				if (600 <= x && x <= 1100 && 200 <= y && y <= 240 && check != 2) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("BAN KHONG DUOC SUA THONG TIN NAY"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);

				}
				else if (600 <= x && x <= 1100 && 270 <= y && y <= 310) {
					input[0]->setCheck(false);
					input[1]->setCheck(true);
					input[2]->setCheck(false);
					input[3]->setCheck(false);
					input[4]->setCheck(false);
					input[5]->setCheck(false);
					input[6]->setCheck(false);

					input[0]->draw();
					input[1]->addChar();
					input[2]->draw();
					input[3]->draw();
					input[4]->draw();
					input[5]->draw();
					input[6]->draw();
				}
				else if (600 <= x && x <= 1100 && 340 <= y && y <= 380) {
					input[0]->setCheck(false);
					input[1]->setCheck(false);
					input[2]->setCheck(true);
					input[3]->setCheck(false);
					input[4]->setCheck(false);
					input[5]->setCheck(false);
					input[6]->setCheck(false);

					input[0]->draw();
					input[1]->draw();
					input[2]->addChar();
					input[3]->draw();
					input[4]->draw();
					input[5]->draw();
					input[6]->draw();
				}
				else if (600 <= x && x <= 1100 && 410 <= y && y <= 450) {
					input[0]->setCheck(false);
					input[1]->setCheck(false);
					input[2]->setCheck(false);
					input[3]->setCheck(true);
					input[4]->setCheck(false);
					input[5]->setCheck(false);
					input[6]->setCheck(false);

					input[0]->draw();
					input[1]->draw();
					input[2]->draw();
					input[3]->addChar();
					input[4]->draw();
					input[5]->draw();
					input[6]->draw();

				}
				else if (600 <= x && x <= 1100 && 480 <= y && y <= 520) {
					input[0]->setCheck(false);
					input[1]->setCheck(false);
					input[2]->setCheck(false);
					input[3]->setCheck(false);
					input[4]->setCheck(true);
					input[5]->setCheck(false);
					input[6]->setCheck(false);

					input[0]->draw();
					input[1]->draw();
					input[2]->draw();
					input[3]->draw();
					input[4]->addChar();
					input[5]->draw();
					input[6]->draw();

				}
				else if (600 <= x && x <= 1100 && 550 <= y && y <= 590) {
					input[0]->setCheck(false);
					input[1]->setCheck(false);
					input[2]->setCheck(false);
					input[3]->setCheck(false);
					input[4]->setCheck(false);
					input[5]->setCheck(true);
					input[6]->setCheck(false);

					input[0]->draw();
					input[1]->draw();
					input[2]->draw();
					input[3]->draw();
					input[4]->draw();
					input[5]->addChar();
					input[6]->draw();

				}
				else if (600 <= x && x <= 1100 && 620 <= y && y <= 660) {
					input[0]->setCheck(false);
					input[1]->setCheck(false);
					input[2]->setCheck(false);
					input[3]->setCheck(false);
					input[4]->setCheck(false);
					input[5]->setCheck(false);
					input[6]->setCheck(true);

					input[0]->draw();
					input[1]->draw();
					input[2]->draw();
					input[3]->draw();
					input[4]->draw();
					input[5]->draw();
					input[6]->addChar();

				}

				if (425 <= x && x <= 520 && 695 <= y && y <= 734) {
					int tmp = MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON HUY THEM LOP TINH CHI"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
					);
					if (tmp == IDYES) {
						maxN--;
						break;
					}
				}
				else if (1057 <= x && x <= 1137 && 695 <= y && y <= 734) {
					if (input[0]->checkRong() == true && input[1]->checkRong() == true && input[2]->checkRong() == true && input[3]->checkRong() == true && input[4]->checkRong() == true &&
						input[5]->checkRong() == true && input[6]->checkRong() == true) {
						bool good = 0;
						lop->setMaLopTC(atoi(input[0]->getContent()));

						lop->setMaMH(input[1]->getContentStr());
						lop->setNienKhoa(atoi(input[2]->getContent()));
						lop->setHocKy(atoi(input[3]->getContent()));
						lop->setNhom(atoi(input[4]->getContent()));
						lop->setSVMin(atoi(input[5]->getContent()));
						lop->setSVMax(atoi(input[6]->getContent()));
						lop->setTrangThai(good);



						int nien_khoa = checkTrungDS_LTC(lop, -1);
						if (DSMH.checkTrung(lop->getMaMH()) == false) {
							MessageBox(
								NULL,
								(LPCWSTR)convertCharArrayToLPCWSTR("MA MON HOC KHONG TON TAI !!! "),
								(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
								MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							);
							continue;
						}
						else if (lop->getSVMin() >= lop->getSVMax()) {
							MessageBox(
								NULL,
								(LPCWSTR)convertCharArrayToLPCWSTR("SL MAX PHAI LON HON SL MIN !!! "),
								(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
								MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							);
							continue;
						}
						else if (nien_khoa > 0) {
							string str1 = "LOP TIN CHI DA CO TAI NIEN KHOA ";
							string str2 = convertIntToString(nien_khoa);
							str1 = str1 + str2;
							MessageBox(
								NULL,
								(LPCWSTR)convertCharArrayToLPCWSTR(str1.c_str()),
								(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
								MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							);
							continue;
						}
						else {
							int tmp = MessageBox(
								NULL,
								(LPCWSTR)convertCharArrayToLPCWSTR("BAN CO MUON LUU LOP TIN CHI"),
								(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
								MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
							);
							if (tmp == IDYES) {
								this->them_LTC(lop);
								MessageBox(
									NULL,
									(LPCWSTR)convertCharArrayToLPCWSTR("THEM LOP TIN CHI THANH CONG !!!"),
									(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
									MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
								);
								//writeDataDS_LTC();
								break;
							}

						}

					}
					else {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("VUI LONG NHAP DAY DU THONG TIN "),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);
						continue;
					}
				}

			}
		}
	}
	else if (check == 2) {

		while (1) {
			// delay(10);
			if (ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				clearmouseclick(WM_LBUTTONDOWN);
				if (lopTC[viTriChon]->getSoSVDK() > 0) {
					if (600 <= x && x <= 1100 && 200 <= y && y <= 240 && check != 2) {

						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN KHONG DUOC SUA THONG TIN NAY"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);

					}
					else if (600 <= x && x <= 1100 && 270 <= y && y <= 310) {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN KHONG DUOC SUA THONG TIN NAY"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);

					}
					else if (600 <= x && x <= 1100 && 340 <= y && y <= 380) {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN KHONG DUOC SUA THONG TIN NAY"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);

					}
					else if (600 <= x && x <= 1100 && 410 <= y && y <= 450) {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN KHONG DUOC SUA THONG TIN NAY"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);

					}
					else if (600 <= x && x <= 1100 && 480 <= y && y <= 520) {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN KHONG DUOC SUA THONG TIN NAY"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);


					}
					else if (600 <= x && x <= 1100 && 550 <= y && y <= 590) {
						input[0]->setCheck(false);
						input[1]->setCheck(false);
						input[2]->setCheck(false);
						input[3]->setCheck(false);
						input[4]->setCheck(false);
						input[5]->setCheck(true);
						input[6]->setCheck(false);

						input[0]->draw();
						input[1]->draw();
						input[2]->draw();
						input[3]->draw();
						input[4]->draw();
						input[5]->addChar();
						input[6]->draw();

					}
					else if (600 <= x && x <= 1100 && 620 <= y && y <= 660) {
						input[0]->setCheck(false);
						input[1]->setCheck(false);
						input[2]->setCheck(false);
						input[3]->setCheck(false);
						input[4]->setCheck(false);
						input[5]->setCheck(false);
						input[6]->setCheck(true);

						input[0]->draw();
						input[1]->draw();
						input[2]->draw();
						input[3]->draw();
						input[4]->draw();
						input[5]->draw();
						input[6]->addChar();

					}

				}
				else {
					if (600 <= x && x <= 1100 && 200 <= y && y <= 240 && check != 2) {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN KHONG DUOC SUA THONG TIN NAY"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);

					}
					else if (600 <= x && x <= 1100 && 270 <= y && y <= 310) {
						input[0]->setCheck(false);
						input[1]->setCheck(true);
						input[2]->setCheck(false);
						input[3]->setCheck(false);
						input[4]->setCheck(false);
						input[5]->setCheck(false);
						input[6]->setCheck(false);

						input[0]->draw();
						input[1]->addChar();
						input[2]->draw();
						input[3]->draw();
						input[4]->draw();
						input[5]->draw();
						input[6]->draw();
					}
					else if (600 <= x && x <= 1100 && 340 <= y && y <= 380) {
						input[0]->setCheck(false);
						input[1]->setCheck(false);
						input[2]->setCheck(true);
						input[3]->setCheck(false);
						input[4]->setCheck(false);
						input[5]->setCheck(false);
						input[6]->setCheck(false);

						input[0]->draw();
						input[1]->draw();
						input[2]->addChar();
						input[3]->draw();
						input[4]->draw();
						input[5]->draw();
						input[6]->draw();
					}
					else if (600 <= x && x <= 1100 && 410 <= y && y <= 450) {
						input[0]->setCheck(false);
						input[1]->setCheck(false);
						input[2]->setCheck(false);
						input[3]->setCheck(true);
						input[4]->setCheck(false);
						input[5]->setCheck(false);
						input[6]->setCheck(false);

						input[0]->draw();
						input[1]->draw();
						input[2]->draw();
						input[3]->addChar();
						input[4]->draw();
						input[5]->draw();
						input[6]->draw();

					}
					else if (600 <= x && x <= 1100 && 480 <= y && y <= 520) {
						input[0]->setCheck(false);
						input[1]->setCheck(false);
						input[2]->setCheck(false);
						input[3]->setCheck(false);
						input[4]->setCheck(true);
						input[5]->setCheck(false);
						input[6]->setCheck(false);

						input[0]->draw();
						input[1]->draw();
						input[2]->draw();
						input[3]->draw();
						input[4]->addChar();
						input[5]->draw();
						input[6]->draw();

					}
					else if (600 <= x && x <= 1100 && 550 <= y && y <= 590) {
						input[0]->setCheck(false);
						input[1]->setCheck(false);
						input[2]->setCheck(false);
						input[3]->setCheck(false);
						input[4]->setCheck(false);
						input[5]->setCheck(true);
						input[6]->setCheck(false);

						input[0]->draw();
						input[1]->draw();
						input[2]->draw();
						input[3]->draw();
						input[4]->draw();
						input[5]->addChar();
						input[6]->draw();

					}
					else if (600 <= x && x <= 1100 && 620 <= y && y <= 660) {
						input[0]->setCheck(false);
						input[1]->setCheck(false);
						input[2]->setCheck(false);
						input[3]->setCheck(false);
						input[4]->setCheck(false);
						input[5]->setCheck(false);
						input[6]->setCheck(true);

						input[0]->draw();
						input[1]->draw();
						input[2]->draw();
						input[3]->draw();
						input[4]->draw();
						input[5]->draw();
						input[6]->addChar();

					}
				}
				if (1057 <= x && x <= 1137 && 695 <= y && y <= 734) {
					lop->setMaLopTC(atoi(input[0]->getContent()));
					lop->setMaMH(input[1]->getContentStr());
					lop->setNienKhoa(atoi(input[2]->getContent()));
					lop->setHocKy(atoi(input[3]->getContent()));
					lop->setNhom(atoi(input[4]->getContent()));
					lop->setSVMin(atoi(input[5]->getContent()));
					lop->setSVMax(atoi(input[6]->getContent()));
					int nien_khoa = checkTrungDS_LTC(lop, viTriChon);
					if (nien_khoa > 0) {

						string str1 = "LOP TIN CHI DA CO TAI NIEN KHOA ";
						string str2 = convertIntToString(nien_khoa);
						str1 = str1 + str2;
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR(str1.c_str()),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);

						continue;
					}
					else if (lop->getSVMin() >= lop->getSVMax()) {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("SL MAX PHAI LON HON SL MIN !!! "),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);
						continue;
					}
					else if (lopTC[viTriChon]->getSoSVDK() > lop->getSVMax()) {

						string str1 = "SL MAX KHONG DUOC NHO HON SO SINH VIEN DA DK ( ";
						string str3 = " )";
						string str2 = convertIntToString(lopTC[viTriChon]->getSoSVDK());
						str1 = str1 + str2;
						str1 = str1 + str3;
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR(str1.c_str()),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);
						continue;
					}
					else {
						int tmp = MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN CO MUON LUU SUA LOP TIN CHI"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
						);
						if (tmp == IDYES) {

							this->update_LTC(lop, viTriChon);
							//writeDataDS_LTC();
							MessageBox(
								NULL,
								(LPCWSTR)convertCharArrayToLPCWSTR("SUA LOP TIN CHI THANH CONG !!!"),
								(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
								MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							);
							hDDK = XUAT;
							break;
						}

					}


				}
				else if (425 <= x && x <= 520 && 695 <= y && y <= 734) {
					int tmp = MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON HUY SUA MON HOC"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
					);
					if (tmp == IDYES) {
						hDDK = XUAT;
						cleardevice();
						break;
					}
					else continue;
				}


			}
		}
	}
}






void DSLTC::dangKyTheoLTC(treeMH DSMH, string _maSV, int khoa, int HK, thaoTac& hDDK) {
	int checkOut = 1;
	int tongSoDong = 0;

	_menuDKLTC();
	maSV(_maSV);
	// dem xem co bao nhieu ltc thoa man khoa, hk duoc nhap vao
	for (int i = 0; i < n; i++) {
		if (lopTC[i]->getNienKhoa() == khoa && lopTC[i]->getHocKy() == HK)
			tongSoDong++;
	}

	if (tongSoDong == 0) {
		hDDK = BACK;
		return;
	}

	int soLuongMH = 0;
	soLuongMH = DSMH.soNode(DSMH.getRoot());
	Subject* arrMH = new Subject[soLuongMH];
	soLuongMH = 0;
	DSMH.nhapCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH);
	int soDong = 0;
	LopTC* loptc[MAX_LOPTC];// = { NULL };

	for (int i = 0; i < n; i++) {
		loptc[i] = new LopTC();
		if (lopTC[i]->getNienKhoa() == khoa && lopTC[i]->getHocKy() == HK)
			loptc[soDong++] = lopTC[i];
	}

	int soDu = (tongSoDong % maxDong > 0) ? 1 : 0;

	int tongSoTrang = tongSoDong / maxDong + soDu;
	int trangHienTai = 1;
	string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	settextstyle(10, 0, 1);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
	int batDau = 0;
	int ketThuc = (tongSoDong > maxDong) ? maxDong : tongSoDong;

	Table newTable = table_LTC();
	newTable.drawTable(maxDong);
	cout << "ahihi  ";
	xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, newTable, checkOut, _maSV);

	int x, y; //char ch;
	while (true) {
		//delay(0.0000);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);

			if (tableLeft <= x && x <= tableRightLopTC && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
				int index = (y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong;
				int nhom = checkLopDaDK(tim_LTC(loptc[index]->getMaLopTC()), _maSV);
				if (checkSVDK_LTC(loptc[index]->getMaLopTC(), _maSV) == true) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("SINH VIEN DA DANG KY LOP TIN CHI! "),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
					continue;
				}
				if (loptc[index]->getSoSVDK() == loptc[index]->getSVMax()) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("LOP TIN CHI DA DAY !!!"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
				}
				else if (nhom >= 0) {
					string str1 = "SV DA DANG KY MON HOC NAY TAI NHOM ";
					string str2 = convertIntToString(nhom);
					str1 = str1 + str2;
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR(str1.c_str()),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
				}
				else if (loptc[index]->getTrangThai() == 1) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("LOP TIN CHI DA BI HUY. KHONG THE DANG KY !!!"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
				}
				else if (loptc[index]->getSoSVDK() > 0 && loptc[index]->getDSDK().getDiemSV(0) >= 0) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("LOP TIN CHI DA NHAP DIEM. KHONG THE DANG KY !"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
				}
				else if (checkSVDK_LTC(loptc[index]->getMaLopTC(), _maSV) == false) {

					//cout << " ." << lopTC[index]->getMaLopTC() << ". ";
					int tmp = MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON DANG KY LOP TIN CHI?"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
					);
					if (tmp == IDYES) {


						SVDangKy sv(_maSV);


						dkMH_LTC(loptc[index]->getMaLopTC(), sv);

						//	writeDataDS_DK();
							//writeDataDS_LTC();
							//break;
					}
				}

			}
			else if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {

				batDau = batDau - maxDong;
				ketThuc = batDau + maxDong;
				trangHienTai--;
				xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, newTable, checkOut, _maSV);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				settextstyle(10, 0, 1);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if ((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang) {
				batDau = batDau + maxDong;
				ketThuc = (ketThuc + maxDong > tongSoDong) ? tongSoDong : ketThuc + maxDong;
				trangHienTai++;
				xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, newTable, checkOut, _maSV);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				settextstyle(10, 0, 1);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));

			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {

				hDDK = XUAT;
				break;
			}


		}

	}


}


void DSLTC::inputDkLTC(treeMH DSMH, string str1, string str2, string str3, DSSV sv, thaoTac& hDDK) {
	Input* input[3];
	input[0] = new Input(str1, 2, "Ma SV", 15, 0, 570, 1100, 260, 310, graynhat, 0, 3);
	input[1] = new Input(str2, 3, "Nien Khoa", 4, 0, 570, 1100, 360, 410, graynhat, 0, 3);
	input[2] = new Input(str3, 3, "Hoc Ky", 1, 0, 570, 1100, 460, 510, graynhat, 0, 3);

	int x = -1; int y = -1;
	input[0]->draw();
	input[1]->draw();
	input[2]->draw();

	string ma_sv;
	int nien_Khoa;
	int hoc_Ky;

	while (1) {
		// delay(10);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (570 <= x && x <= 1100 && 260 <= y && y <= 310) {
				input[0]->setCheck(true);
				input[1]->setCheck(false);
				input[2]->setCheck(false);

				input[0]->addChar();
				input[1]->draw();
				input[2]->draw();

			}
			else if (570 <= x && x <= 1100 && 360 <= y && y <= 410) {
				input[0]->setCheck(false);
				input[1]->setCheck(true);
				input[2]->setCheck(false);

				input[0]->draw();
				input[1]->addChar();
				input[2]->draw();

			}
			else if (570 <= x && x <= 1100 && 460 <= y && y <= 510) {
				input[0]->setCheck(false);
				input[1]->setCheck(false);
				input[2]->setCheck(true);

				input[0]->draw();
				input[1]->draw();
				input[2]->addChar();

			}
			if (417 <= x && x <= 512 && 709 <= y && y <= 748) {
				// thoat nhap
				hDDK = XUAT;
				break;
			}
			else if (1057 <= x && x <= 1151 && 709 <= y && y <= 748) {
				if (input[0]->checkRong() == true && input[1]->checkRong() == true && input[2]->checkRong() == true) {
					ma_sv = input[0]->getContentStr();
					nien_Khoa = atoi(input[1]->getContent());
					hoc_Ky = atoi(input[2]->getContent());
					cout << "ah0h0";
					//				DSLH dslop;
						//			dslop.xuatDSSV();
					NodeSV* tmp = sv.timSV(ma_sv);
					cout << "ahaha";
					int check = checkLopTheoKhoaVaHK_LTC(nien_Khoa, hoc_Ky);

					if (tmp == NULL) {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("KHONG TIM THAY SINH VIEN !!!"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);
						continue;
					}
					else if (check == -1) {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("KHONG TIM THAY LOP TIN CHI !!!"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);
						continue;
					}
					else {
						cout << "siuuuuu";
						cleardevice();
						dangKyTheoLTC(DSMH, ma_sv, nien_Khoa, hoc_Ky, hDDK);
						//writeDataDS_DK();
						//writeDataDS_LTC();
						break;
					}


				}
				else {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("VUI LONG NHAP DAY DU THONG TIN "),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
					continue;
				}
			}

		}
	}
}


void DSLTC::huyLTC(string str1, string str2, thaoTac& hDLTC) {
	Input* input[2];
	input[0] = new Input(str1, 3, "Khoa", 50, 0, 570, 1100, 300, 350, graynhat, 0, 4);
	input[1] = new Input(str2, 3, "Hoc ky", 50, 0, 570, 1100, 450, 500, graynhat, 0, 4);

	int x = -1; int y = -1;
	input[0]->draw();
	input[1]->draw();

	int _khoa = 0;
	int _hocKy = 0;

	while (1) {
		// delay(10);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (570 <= x && x <= 1100 && 300 <= y && y <= 350) {
				input[0]->setCheck(true);
				input[1]->setCheck(false);

				input[0]->addChar();
				input[1]->draw();
			}
			else if (570 <= x && x <= 1100 && 450 <= y && y <= 500) {
				input[0]->setCheck(false);
				input[1]->setCheck(true);

				input[0]->draw();
				input[1]->addChar();
			}

			else if (417 <= x && x <= 512 && 709 <= y && y <= 748) {
				// thoat nhap
				break;
			}
			else if (1057 <= x && x <= 1151 && 709 <= y && y <= 748) {
				if (input[0]->checkRong() == true && input[1]->checkRong() == true) {
					_khoa = atoi(input[0]->getContent());
					_hocKy = atoi(input[1]->getContent());
					//cout << _khoa;
					int check = checkLopTheoKhoaVaHK_LTC(_khoa, _hocKy);
					if (check == -1) {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("KHONG TON TAI LOP TIN CHI"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);
						continue;
					}
					else {
						int tmp = MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON HUY LOP TIN CHI?"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
						);
						if (tmp == IDYES) {
							huyLopTCTheoKhoaVaHK_LTC(_khoa, _hocKy);
							//writeDataDS_LTC();
							break;
						}
					}


				}
				else {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("VUI LONG NHAP DAY DU THONG TIN "),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
					continue;
				}

			}
		}
	}
}




void DSLTC::xuatDSDK(DSSV sv, thaoTac& hDLTC, treeMH DSMH) {
	int soLuongMH = 0;
	soLuongMH = DSMH.soNode(DSMH.getRoot());
	Subject* arrMH = new Subject[soLuongMH];
	soLuongMH = 0;
	DSMH.nhapCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH);

	string str1 = "";
	int nInput = 1;
	Input* input[1];
	input[0] = new Input(str1, 3, "Nhap Ma Lop:", 50, 0, 700, 1100, 300, 350, graynhat, 0, 4);
	int x = -1;
	int y = -1;
	input[0]->draw();
	while (1) {
		// delay(10);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (700 <= x && x <= 1100 && 300 <= y && y <= 350) {
				input[0]->setCheck(true);
				input[0]->addChar();
			}
			else if (1035 <= x && x <= 1137 && 695 <= y && y <= 734) {
				int maLop = atoi(input[0]->getContent());
				if (tim_LTC(maLop) < 0) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("KHONG TIM THAY LOP TIN CHI !!!"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
					continue;
				}
				else if (lopTC[tim_LTC(maLop)]->getSoSVDK() == 0) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("CHUA CO SINH VIEN DANG KY !!! "),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
					break;
				}
				else {
					int viTriMH = 0;
					int viTriLTC = tim_LTC(maLop);
					for (int j = 0; j < soLuongMH; j++) {
						if (arrMH[j].getMaMH() == lopTC[viTriLTC]->getMaMH()) {
							viTriMH = j; break; //j = soLuongMH;
						}
					}
					string monHoc(arrMH[viTriMH].getTenMH());
					cleardevice();
					buttonBack();
					tieuDeDSSV();
					_menuxemDSSV();
					DSSV1LTC(convertIntToString(maLop), monHoc, convertIntToString(lopTC[viTriLTC]->getSoSVDK()), convertIntToString(lopTC[viTriLTC]->getNienKhoa()),
						convertIntToString(lopTC[viTriLTC]->getHocKy()), convertIntToString(lopTC[viTriLTC]->getNhom()));
					// " danh sach sinh vien" ....
					int xoa = 0;
					lopTC[viTriLTC]->getDSDK().xuatDSTrang_DK(sv, lopTC[viTriLTC]->getSoSVDK(), hDLTC, xoa);
					lopTC[viTriLTC]->setSoSVDK(lopTC[viTriLTC]->getSoSVDK() - xoa);
					//writeDataDS_DK();
					//writeDataDS_LTC();

					break;
					//	hDLTC = XUAT;
				}
			}
			else if (417 <= x && x <= 512 && 709 <= y && y <= 748) {
				hDLTC = XUAT;
				break;
			}


		}
	}

}


void DSLTC::xuatDiem1Trang1LTC(LopTC* loptc, DSSV sv, int batDau, int ketThuc, Table Bang, thaoTac& hDMH) {
	int soDong = ketThuc % maxDong;
	if (soDong == 0) soDong = maxDong;
	if (ketThuc == 0 && batDau == 0) soDong = maxDong;
	else {
		int soDongTrong = maxDong - ketThuc % maxDong;
		soDong = ketThuc % maxDong == 0 ? ketThuc : ketThuc + soDongTrong;
	}

	string strSTT;
	int x = tableLeft;
	int y = tableTop + kcY / 2 - textheight(convertStringToChar(strSTT)) / 2;
	setbkcolor(BlueNhat); setcolor(Den); settextstyle(10, 0, 1);

	for (int i = batDau; i < soDong; i++) {
		y += kcY;
		if (i >= ketThuc) {
			x = tableLeft;
			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(0)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(1)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(2)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(3)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(4)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));




			continue;
		}


		strSTT = convertIntToString(i + 1);

		x = tableLeft;

		// xoa STT cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat STT moi
		outtextxy(x + (Bang.getCols(0)->getChieuRong() / 2 - textwidth(convertStringToChar(strSTT)) / 2), y, convertStringToChar(strSTT));
		x += Bang.getCols(0)->getChieuRong();

		string maSV = loptc->getDSDK().getMaSVDK(i);
		float diem = loptc->getDSDK().getDiemSV(i);
		if (diem < 0) diem = 0;
		NodeSV* tmp = sv.timSV(maSV);


		// xoa MA SV
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat MA SV moi
		outtextxy(x + (Bang.getCols(1)->getChieuRong() / 2 - textwidth(convertStringToChar(maSV)) / 2), y, convertStringToChar(maSV));
		x += Bang.getCols(1)->getChieuRong();


		// xoa HO cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat HO moi
		outtextxy(x + (Bang.getCols(2)->getChieuRong() / 2 - textwidth(convertStringToChar(tmp->getDataSV().getHo())) / 2), y, convertStringToChar(tmp->getDataSV().getHo()));
		x += Bang.getCols(2)->getChieuRong();

		// xoa TEN  cu 
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat TEN  moi
		outtextxy(x + (Bang.getCols(3)->getChieuRong() / 2 - textwidth(convertStringToChar(tmp->getDataSV().getTen())) / 2), y, convertStringToChar(tmp->getDataSV().getTen()));
		x += Bang.getCols(3)->getChieuRong();

		// xoa LOP cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat LOP moi
		outtextxy(x + (Bang.getCols(4)->getChieuRong() / 2 - textwidth(convertStringToChar(tmp->getDataSV().getMaLop())) / 2), y, convertStringToChar(tmp->getDataSV().getMaLop()));
		x += Bang.getCols(4)->getChieuRong();

		// xoa Diem cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat Diem moi
		outtextxy(x + (Bang.getCols(5)->getChieuRong() / 2 - textwidth(convertFloatToChar(diem)) / 2), y, convertFloatToChar(diem));
		x += Bang.getCols(5)->getChieuRong();



	}




}



void DSLTC::xuatDiemTheoTrang1LTC(LopTC* loptc, DSSV sv, int tongSoDong, thaoTac& hDLTC) {


	int soDu = (tongSoDong % maxDong > 0) ? 1 : 0;

	int tongSoTrang = tongSoDong / maxDong + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc = (tongSoDong > maxDong) ? maxDong : tongSoDong;

	Table newTable = table_Diem1Lop();
	newTable.drawTable(maxDong);

	xuatDiem1Trang1LTC(loptc, sv, batDau, ketThuc, newTable, hDLTC);



	string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));

	int x, y;
	bool ok = true;
	int viTriChon = 0;
	int choClick = 0;
	while (ok) {
		//delay(200);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);

			if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {

				batDau = batDau - maxDong;
				ketThuc = batDau + maxDong;
				trangHienTai--;
				xuatDiem1Trang1LTC(loptc, sv, batDau, ketThuc, newTable, hDLTC);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if ((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang) {
				batDau = batDau + maxDong;
				ketThuc = (ketThuc + maxDong > tongSoDong) ? tongSoDong : ketThuc + maxDong;
				trangHienTai++;
				xuatDiem1Trang1LTC(loptc, sv, batDau, ketThuc, newTable, hDLTC);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));

			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
				for (int i = 0; i < loptc->getSoSVDK(); i++) {
					if (loptc->getDSDK().getDiemSV(i) < 0) {
						loptc->getDSDK().suaDiemSV(i, 0);
					}
				}
				hDLTC = XUAT;
				break;

			}
			else if (tableLeft <= x && x <= tableRightLopTC && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
				viTriChon = (y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong;
				choClick = (y - tableTop - kcY) / kcY;
				outtextxy(1285, (choClick + 1) * kcY + tableTop+kcY/2,
					convertStringToChar(string(90 / textwidth(convertStringToChar(string(" "))), ' ')));
				//cout << choClick << " ";
				nhapDiem(convertFloatToString(loptc->getDSDK().getDiemSV(viTriChon)),1300,1380,(choClick+1)*kcY+ tableTop+15, (choClick + 2) * kcY + tableTop,tim_LTC(loptc->getMaLopTC()), viTriChon);
				xuatDiem1Trang1LTC(loptc, sv, batDau, ketThuc, newTable, hDLTC);
			}

		}
		else if (ismouseclick(WM_RBUTTONDOWN)) {
			getmouseclick(WM_RBUTTONDOWN, x, y);
			clearmouseclick(WM_RBUTTONDOWN);
			if (tableLeft <= x && x <= tableRightLopTC && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
				 viTriChon = (y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong;

				hDLTC = XUAT;
				break;
			}
		}
	}


}
void DSLTC::nhapDiem(string str, int left, int right, int top, int bottom, int viTriLtc, int viTriSV) {
	//menuNhapDiem();
	if (str == "-1") str = "";
	Input* input[1];
	input[0] = new Input(str, 4, "", 3, 0, left, right, top, bottom, graynhat, 0, 3);
	//input[0]->draw();


	//input[1]->draw();
	int x = -1; int y = -1;
	float diem;
	while (1) {
		// delay(10);



		input[0]->setCheck(true);
		input[0]->addChar();


		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (left > x || x > right || top > y || y > bottom) {
				diem = input[0]->getContentFoat();
				if (diem < 0) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("DIEM KHONG HOP LE"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
					continue;
				}
				else {

					lopTC[viTriLtc]->getDSDK().suaDiemSV(viTriSV, diem);
					break;
				}

			}
		}
	}
}



void DSLTC::xuatDiemLTC(treeMH DSMH, DSSV sv, int tongSoDong, thaoTac& hDLTC) {

	int checkOut = 2; string masv = "";
	int nFilter = n; int soLuongMH = 0;
	soLuongMH = DSMH.soNode(DSMH.getRoot());
	Subject* arrMH = new Subject[soLuongMH];
	soLuongMH = 0;
	DSMH.nhapCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH);

	//LopTC* loptc[MAX_LOPTC];
	//for (int i = 0; i < n; i++) {
	//	loptc[i] = new LopTC();
	//	loptc[i] = this->lopTC[i];
	//}


	int soDu = (tongSoDong % maxDong > 0) ? 1 : 0;

	int tongSoTrang = tongSoDong / maxDong + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc = (tongSoDong > maxDong) ? maxDong : tongSoDong;

	Table newTable = table_LTC();
	newTable.drawTable(maxDong);

	xuatDS1Trang_LTC(lopTC, arrMH, soLuongMH, batDau, ketThuc, newTable, checkOut, masv);

	string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));

	int x, y;
	bool ok = true;

	while (ok) {
		//delay(200);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (1320 <= x && x <= 1420 && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
				int index = (y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong;
				if (lopTC[index]->getSoSVDK() == 0) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("LOP CHUA CO SINH VIEN DANG KY !"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
				}
				else if (lopTC[index]->getSoSVDK()<lopTC[index]->getSVMin()) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("LOP CHUA DU DIEU KIEN NHAP DIEM!"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
				}
				else {
					cleardevice();
					int maLop = lopTC[index]->getMaLopTC();
					int viTriMH = 0;
					int viTriLTC = tim_LTC(maLop);
					for (int j = 0; j < soLuongMH; j++) {
						if (arrMH[j].getMaMH() == lopTC[viTriLTC]->getMaMH()) {
							viTriMH = j; break; //j = soLuongMH;
						}
					}
					string monHoc(arrMH[viTriMH].getTenMH());
					menuXemDiem();

					DSSV1LTC(convertIntToString(maLop), monHoc, convertIntToString(lopTC[viTriLTC]->getSoSVDK()), convertIntToString(lopTC[viTriLTC]->getNienKhoa()),
						convertIntToString(lopTC[viTriLTC]->getHocKy()), convertIntToString(lopTC[viTriLTC]->getNhom()));
					xuatDiemTheoTrang1LTC(lopTC[index], sv, lopTC[index]->getSoSVDK(), hDLTC);
					hDLTC = XUAT;
					break;


				}


			}
			else if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {

				batDau = batDau - maxDong;
				ketThuc = batDau + maxDong;
				trangHienTai--;
				xuatDS1Trang_LTC(lopTC, arrMH, soLuongMH, batDau, ketThuc, newTable, checkOut, masv);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if ((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang) {
				batDau = batDau + maxDong;
				ketThuc = (ketThuc + maxDong > tongSoDong) ? tongSoDong : ketThuc + maxDong;
				trangHienTai++;
				xuatDS1Trang_LTC(lopTC, arrMH, soLuongMH, batDau, ketThuc, newTable, checkOut, masv);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));

			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {

				hDLTC = BACK;
				break;

			}
			else if (1010 <= x && x <= 1150 && 169 <= y && y <= 214) {
				hDLTC = DIEM1SV;
				break;
			}
			else if (1350 <= x && x <= 1490 && 169 <= y && y <= 214) {
				hDLTC = DIEMTK;
				break;
			}

			else if (1359 <= x && x <= 1490 && 169 <= y && y <= 214) {
				hDLTC = XUATDK;
				break;
			}
			else if (1170 <= x && x <= 1330 && 169 <= y && y <= 214) {
				hDLTC = DIEMTB;
				break;
			}
		}
	}
	delete[] arrMH;
	newTable.freeTable();
}

void DSLTC::xuatDiem1Trang1SV(LopTC* loptc[], Subject arrMH[], int soLuongMon, int batDau, int ketThuc, Table Bang, string maSV) {

	int soDong = ketThuc % maxDong;
	if (soDong == 0) soDong = maxDong;
	if (ketThuc == 0 && batDau == 0) soDong = maxDong;
	else {
		int soDongTrong = maxDong - ketThuc % maxDong;
		soDong = ketThuc % maxDong == 0 ? ketThuc : ketThuc + soDongTrong;
	}

	string strSTT;	string trangThai = "TRUE"; int viTriMH = 0;
	int x = tableLeft;
	int y = tableTop + kcY / 2 - textheight(convertStringToChar(strSTT)) / 2;
	setbkcolor(BlueNhat); setcolor(Den); settextstyle(10, 0, 1);


	for (int i = batDau; i < soDong; i++) {
		y += kcY;
		if (i >= ketThuc) {
			x = tableLeft;
			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(0)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(1)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(2)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(3)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(4)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(5)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(6)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(6)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(7)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(7)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(8)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(8)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
				convertStringToChar(string((Bang.getCols(9)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(9)->getChieuRong();

			continue;
		}


		strSTT = convertIntToString(i + 1);

		x = tableLeft;

		// xoa STT cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat STT moi
		outtextxy(x + (Bang.getCols(0)->getChieuRong() / 2 - textwidth(convertStringToChar(strSTT)) / 2), y, convertStringToChar(strSTT));
		x += Bang.getCols(0)->getChieuRong();

		// xoa MA LOP
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat MA LOP moi
		outtextxy(x + (Bang.getCols(1)->getChieuRong() / 2 - textwidth(convertIntToChar(loptc[i]->getMaLopTC())) / 2), y, convertIntToChar(loptc[i]->getMaLopTC()));
		x += Bang.getCols(1)->getChieuRong();


		// xoa MA MON HOC cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat MA MON HOC moi
		outtextxy(x + (Bang.getCols(2)->getChieuRong() / 2 - textwidth(convertStringToChar(loptc[i]->getMaMH())) / 2), y, convertStringToChar(loptc[i]->getMaMH()));
		x += Bang.getCols(2)->getChieuRong();

		// xoa TEN MON HOC cu 
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat TEN MON HOC moi
		for (int j = 0; j < soLuongMon; j++) {
			if (arrMH[j].getMaMH() == loptc[i]->getMaMH()) {
				viTriMH = j; break; //j = soLuongMH;
			}
		}
		outtextxy(x + (Bang.getCols(3)->getChieuRong() / 2 - textwidth(arrMH[viTriMH].getTenMH()) / 2), y, arrMH[viTriMH].getTenMH());
		x += Bang.getCols(3)->getChieuRong();

		// xoa KHOA cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat KHOA moi
		outtextxy(x + (Bang.getCols(4)->getChieuRong() / 2 - textwidth(convertIntToChar(loptc[i]->getNienKhoa())) / 2), y, convertIntToChar(loptc[i]->getNienKhoa()));
		x += Bang.getCols(4)->getChieuRong();

		// xoa HK cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat HK moi
		outtextxy(x + (Bang.getCols(5)->getChieuRong() / 2 - textwidth(convertIntToChar(loptc[i]->getHocKy())) / 2), y, convertIntToChar(loptc[i]->getHocKy()));
		x += Bang.getCols(5)->getChieuRong();

		// xoa NHOM cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(6)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat NHOM moi
		outtextxy(x + (Bang.getCols(6)->getChieuRong() / 2 - textwidth(convertIntToChar(loptc[i]->getNhom())) / 2), y, convertIntToChar(loptc[i]->getNhom()));
		x += Bang.getCols(6)->getChieuRong();

		// xoa STCLT cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(7)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat STCLT moi
		arrMH[viTriMH].getTCTH();
		outtextxy(x + (Bang.getCols(7)->getChieuRong() / 2 - textwidth(convertIntToChar(arrMH[viTriMH].getTCLT())) / 2), y, convertIntToChar(arrMH[viTriMH].getTCLT()));
		x += Bang.getCols(7)->getChieuRong();

		// xoa STCTH  cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(8)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat STCTH moi
		outtextxy(x + (Bang.getCols(8)->getChieuRong() / 2 - textwidth(convertIntToChar(arrMH[viTriMH].getTCTH())) / 2), y, convertIntToChar(arrMH[viTriMH].getTCTH()));
		x += Bang.getCols(8)->getChieuRong();

		// xoa Diem cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(9)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat Diem moi
		if (loptc[i]->getDSDK().getDiemSV(0) < 0) {
			string diem = "0";
			outtextxy(x + (Bang.getCols(9)->getChieuRong() / 2 - textwidth(convertStringToChar(diem)) / 2), y, convertStringToChar(diem));
			x += Bang.getCols(9)->getChieuRong();
		}
		else {
			outtextxy(x + (Bang.getCols(9)->getChieuRong() / 2 - textwidth(convertFloatToChar(loptc[i]->getDSDK().timDiemSV_DK(maSV))) / 2), y, convertFloatToChar(loptc[i]->getDSDK().timDiemSV_DK(maSV)));
			x += Bang.getCols(9)->getChieuRong();
		}

	}
}





void DSLTC::xuatDiemTheoTrang1SV(LopTC* loptc[], treeMH DSMH, int tongSoDong, thaoTac& hDLTC, string maSV, string hoTen) {

	setfillstyle(SOLID_FILL, mauNen);
	bar(0, 0, 1525, 777);
	tieuDebangdiem1SV();
	setbkcolor(mauNen);
	setcolor(Blue);
	settextstyle(10, 0, 3);
	outtextxy(500, 140, convertStringToChar(_SV));
	outtextxy(500 + textwidth(convertStringToChar(_SV)) + 10, 140, convertStringToChar(hoTen));
	outtextxy(500 + textwidth(convertStringToChar(_SV)) + 20 + textwidth(convertStringToChar(hoTen)), 140, convertStringToChar(maSV));
	buttonBack();


	setfillstyle(SOLID_FILL, BlueNhat);
	bar(40, 243, 1490, 744);
	vien(40, 1490, 243, 744);
	buttonTien();
	buttonLui();
	int soLuongMH = 0;
	soLuongMH = DSMH.soNode(DSMH.getRoot());
	Subject* arrMH = new Subject[soLuongMH];
	soLuongMH = 0;
	DSMH.nhapCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH);

	int soDu = (tongSoDong % maxDong > 0) ? 1 : 0;

	int tongSoTrang = tongSoDong / maxDong + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc = (tongSoDong > maxDong) ? maxDong : tongSoDong;

	Table newTable = table_Diem1SV();
	newTable.drawTable(maxDong);


	string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
	xuatDiem1Trang1SV(loptc, arrMH, soLuongMH, batDau, ketThuc, newTable, maSV);
	int x, y;
	bool ok = true;

	while (ok) {
		//delay(200);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {

				batDau = batDau - maxDong;
				ketThuc = batDau + maxDong;
				trangHienTai--;
				xuatDiem1Trang1SV(loptc, arrMH, soLuongMH, batDau, ketThuc, newTable, maSV);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if ((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang) {
				batDau = batDau + maxDong;
				ketThuc = (ketThuc + maxDong > tongSoDong) ? tongSoDong : ketThuc + maxDong;
				trangHienTai++;
				xuatDiem1Trang1SV(loptc, arrMH, soLuongMH, batDau, ketThuc, newTable, maSV);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));

			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
				hDLTC = BACK;
				break;
			}

		}
	}
}


void DSLTC::xuatDiem1SV(treeMH DSMH, DSSV sv, thaoTac& hDLTC) {


	string str1 = "";
	Input* input[1];
	input[0] = new Input(str1, 2, "Nhap Ma SV:", 50, 0, 650, 1050, 200, 225, graynhat, 0, 4);
	input[0]->draw();

	int x = -1;
	int y = -1;

	LopTC* loptc[MAX_LOPTC];

	int soLuongLop = 0;
	for (int i = 0; i < n; i++) {
		loptc[i] = new LopTC();
		loptc[i] = this->lopTC[i];
	}
	string strho;
	string strten;
	while (1) {
		// delay(10);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (500 <= x && x <= 900 && 200 <= y && y <= 225) {
				input[0]->setCheck(true);
				input[0]->addChar();
			}
			else if (1057 <= x && x <= 1151 && 709 <= y && y <= 748) {
				string maSV = input[0]->getContentStr();
				NodeSV* Sv = sv.timSV(maSV);
				if (Sv == nullptr) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("KHONG TIM THAY SINH VIEN !!!"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
					continue;
				}
				else {

					for (int i = 0; i < n; i++) {
						if (checkDK_LTC(i, maSV) == true) {
							loptc[soLuongLop] = new LopTC();
							loptc[soLuongLop++] = this->lopTC[i];
						}
					}
					if (soLuongLop > 0) {
						strho = Sv->getDataSV().getHo();
						strten = Sv->getDataSV().getTen();
						strho = strho + " ";
						strho = strho + strten;
						cleardevice();
						xuatDiemTheoTrang1SV(loptc, DSMH, soLuongLop, hDLTC, maSV, strho);
						if (hDLTC == BACK) break;
					}
					else {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("SINH VIEN CHUA DANG KY LOP HOC NAO !!!"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);
						continue;
					}
				}


			}
			else if (425 <= x && x <= 520 && 695 <= y && y <= 734) {
				//on = 0;
				//hDDK = BACK;
				break;
			}


		}
	}


}

void DSLTC::xuatDiem(treeMH DSMH, DSSV sv, int diemGi) {
	menuBangDiemTB();
	int tongSoDong = 0;
	string arrLop[100];
	cout << "0";
	sv.mangLop(arrLop, tongSoDong);

	cout << "1";
	setbkcolor(mauNen);
	setcolor(Blue);
	settextstyle(10, 0, 3);
	outtextxy(600, 140, convertStringToChar("TONG SO LOP SV : "));
	outtextxy(600 + textwidth(convertStringToChar("TONG SO LOP SV : ")), 140, convertIntToChar(tongSoDong));
	int x = -1, y = -1;
	int batDau = 0;
	int ketThuc = (tongSoDong >= maxDong) ? maxDong : tongSoDong;
	Table newTable = table_Lop();
	newTable.drawTable(maxDong);
	int trangHienTai = 1;
	int tongSoTrang = ((tongSoDong - 1) / maxDong) + 1;
	string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	settextstyle(10, 0, 1);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
	bool okTB = true;
	xuat1TrangDiem(sv,arrLop, batDau, ketThuc, newTable);
	int viTriClick = 0;
	while (okTB) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (tableLeft <= x && x <= tableRightLop && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
				viTriClick = 0;
				for (int i = 0; i < ((y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong); i++) {
					viTriClick++;
				}

				if (sv.soLuongSVLop(arrLop[viTriClick]) == 0) {
					int yess = MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("LOP CHUA CO SINH VIEN NAO KHONG THE XEM DIEM"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);

					continue;

				}
				if (diemGi == 1) {
					xuatDiemTB1Lop(sv, arrLop[viTriClick], sv.soLuongSVLop(arrLop[viTriClick]));
					break;
				}
				else if (diemGi == 2) {
					xuatDiemTK1Lop(DSMH, sv, arrLop[viTriClick], sv.soLuongSVLop(arrLop[viTriClick]));
					break;
				}
				//temp->getDataLop().getDSSV().menuSetSV(on, hDSV, string(temp->getDataLop().getMaLop()));

				//break;
			}
			else if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {
				batDau = batDau - maxDong;
				ketThuc = batDau + maxDong;
				trangHienTai--;
				xuat1TrangDiem(sv,arrLop, batDau, ketThuc, newTable);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				settextstyle(10, 0, 1);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if ((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang) {

				batDau = batDau + maxDong;
				ketThuc = (ketThuc + maxDong > tongSoDong) ? tongSoDong : ketThuc + maxDong;
				trangHienTai++;
				xuat1TrangDiem(sv,arrLop, batDau, ketThuc, newTable);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				settextstyle(10, 0, 1);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
				okTB = false;
				break;
			}
		}
	}
}

void DSLTC::xuat1TrangDiem(DSSV sv,string arrLop[100], int batDau, int ketThuc, Table newTable) {
	int soDong = ketThuc % maxDong;
	if (soDong == 0) soDong = maxDong;
	if (ketThuc == 0 && batDau == 0) soDong = maxDong;
	else {
		int soDongTrong = maxDong - ketThuc % maxDong;
		soDong = ketThuc % maxDong == 0 ? ketThuc : ketThuc + soDongTrong;
	}
	char* STT = convertIntToChar(0);

	int x = tableLeft;
	int y = tableTop + kcY / 2 - textheight(STT) / 2;
	setbkcolor(BlueNhat); setcolor(Den); settextstyle(10, 0, 1);
	for (int i = batDau; i < soDong; i++) {
		y += kcY;
		if (i >= ketThuc) {
			setbkcolor(BlueNhat); setcolor(Den); settextstyle(10, 0, 1);
			x = tableLeft;
			STT = convertIntToChar(i + 1);
			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((newTable.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += newTable.getCols(0)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((newTable.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

			x += newTable.getCols(1)->getChieuRong();
			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((newTable.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

			x += newTable.getCols(2)->getChieuRong();

			continue;
		}

		x = tableLeft;
		//STT
		STT = convertIntToChar(i + 1);
		//Xoa STT cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((newTable.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//Xuat STT moi
		outtextxy(x + (newTable.getCols(0)->getChieuRong() / 2 - textwidth(STT) / 2), y, STT);
		x += newTable.getCols(0)->getChieuRong();
		// MaLop
		// Xoa maLop cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((newTable.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// Xuat maLop moi
		outtextxy(x + (newTable.getCols(1)->getChieuRong() / 2 - textwidth(convertStringToChar(arrLop[i])) / 2), y, convertStringToChar(arrLop[i]));
		x += newTable.getCols(1)->getChieuRong();
		// SoSV
		// Xoa SoSV cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((newTable.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// Xuat SoSV moi
		outtextxy(x + (newTable.getCols(2)->getChieuRong() / 2 - textwidth(convertIntToChar(sv.soLuongSVLop(arrLop[i]))) / 2), y, convertIntToChar(sv.soLuongSVLop(arrLop[i])));
		x = tableLeft;

		//clearmouseclick(WM_LBUTTONDOWN);
	}
}

void DSLTC::xuatDiemTB1Lop(DSSV sv,string str, int tongSoSV) {
	setfillstyle(SOLID_FILL, mauNen);
	bar(0, 0, 1525, 777);
	setbkcolor(Be);
	setfillstyle(SOLID_FILL, Be);
	bar(397, 20, 1173, 100);
	settextstyle(10, 0, 7);
	setcolor(Blue);
	outtextxy((397 + 1173) / 2 - textwidth(convertStringToChar(str)) / 2, (20 + 100) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
	vien(397, 1173, 20, 100);
	//tieuDeLopSV();
	buttonBack();
	setfillstyle(SOLID_FILL, BlueNhat);
	bar(40, 243, 1490, 744);
	vien(40, 1490, 243, 744);
	buttonTien();
	buttonLui();
	//textDiem1Lop(sv->getDataSV().getMaLop());
	int x = -1, y = -1;
	int batDau = 0;
	int ketThuc = (tongSoSV >= maxDong) ? maxDong : tongSoSV;
	Table newTable = table_DiemTB1Lop();
	newTable.drawTable(maxDong);
	int trangHienTai = 1;
	int tongSoTrang = ((tongSoSV - 1) / maxDong) + 1;
	string strSTT = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	settextstyle(10, 0, 1);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(strSTT)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(strSTT)) / 2, convertStringToChar(strSTT));
	bool ok = true;
	xuat1TrangDiemTB1Lop(sv,str, batDau, ketThuc, newTable);
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {

				batDau = batDau - maxDong;
				ketThuc = batDau + maxDong;
				trangHienTai--;
				xuat1TrangDiemTB1Lop(sv,str, batDau, ketThuc, newTable);
				strSTT = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				settextstyle(10, 0, 1);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(strSTT)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(strSTT)) / 2, convertStringToChar(strSTT));
			}
			else if (((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang)) {

				batDau = batDau + maxDong;
				ketThuc = (ketThuc + maxDong > tongSoSV) ? tongSoSV : ketThuc + maxDong;
				trangHienTai++;
				xuat1TrangDiemTB1Lop(sv,str, batDau, ketThuc, newTable);
				strSTT = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				settextstyle(10, 0, 1);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(strSTT)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(strSTT)) / 2, convertStringToChar(strSTT));
			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
				break;
			}
		}
	}
}

void DSLTC::xuat1TrangDiemTB1Lop(DSSV sv,string str, int batDau, int ketThuc, Table Bang) {
	int soDong = ketThuc % maxDong;
	if (soDong == 0) soDong = maxDong;
	if (ketThuc == 0 && batDau == 0) soDong = maxDong;
	else {
		int soDongTrong = maxDong - ketThuc % maxDong;
		soDong = ketThuc % maxDong == 0 ? ketThuc : ketThuc + soDongTrong;
	}
	char* STT = convertIntToChar(0);
	NodeSV* SV = sv.getHeadSV();
	while (SV != NULL) {
		if (SV->getDataSV().getMaLop() == str) break;
		SV = SV->getNextSV();
	}
	for (int i = 0; i < batDau; i++) {
		SV = SV->getNextSV();
	}
	int x = tableLeft;
	int y = tableTop + kcY / 2 - textheight(STT) / 2;
	setbkcolor(BlueNhat); setcolor(Den); settextstyle(10, 0, 1);
	for (int i = batDau; i < soDong; i++) {
		y += kcY;
		if (i >= ketThuc) {
			x = tableLeft;
			STT = convertIntToChar(i + 1);
			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(0)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

			x += Bang.getCols(1)->getChieuRong();
			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

			x += Bang.getCols(2)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(3)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

			continue;
		}



		x = tableLeft;
		//STT
		STT = convertIntToChar(i + 1);
		//Xoa STT cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//Xuat STT moi
		outtextxy(x + (Bang.getCols(0)->getChieuRong() / 2 - textwidth(STT) / 2), y, STT);
		x += Bang.getCols(0)->getChieuRong();
		// MaSV
		// Xoa maSV cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// Xuat maSV moi
		outtextxy(x + (Bang.getCols(1)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getMaSV())) / 2), y, convertStringToChar(SV->getDataSV().getMaSV()));
		x += Bang.getCols(1)->getChieuRong();
		// HO
		// Xoa Ho cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// Xuat Ho moi
		outtextxy(x + (Bang.getCols(2)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getHo())) / 2), y, convertStringToChar(SV->getDataSV().getHo()));
		x += Bang.getCols(2)->getChieuRong();
		//Ten
		//Xoa Ten cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//Xuat Ten moi
		outtextxy(x + (Bang.getCols(3)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getTen())) / 2), y, convertStringToChar(SV->getDataSV().getTen()));
		x += Bang.getCols(3)->getChieuRong();
		//DIEM
		//Xoa DIEM cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//Xuat DIEM moi
		string maSV = SV->getDataSV().getMaSV();
		int soLuongLop = 0;
		float diem = 0;;
		for (int i = 0; i < n; i++) {
			if (checkDK_LTC(i, maSV) == true) {
				soLuongLop++;
				float diemsv = lopTC[i]->getDSDK().getDiemSVBangMa(maSV);
				if (diemsv < 0) diemsv = 0;
				diem += diemsv;// soLuongLop ben trong la vi tri cua masv tai lop
			}
		}
		float diemtb;
		if (soLuongLop == 0) {
			diemtb = 0;
		}
		else {
			diemtb = diem / soLuongLop;
			diemtb = static_cast<float>(static_cast<int>(diemtb * 10)) / 10;
		}

		outtextxy(x + (Bang.getCols(4)->getChieuRong() / 2 - textwidth(convertFloatToChar(diemtb)) / 2), y, convertFloatToChar(diemtb));

		x = tableLeft;

		//clearmouseclick(WM_LBUTTONDOWN);
		SV = SV->getNextSV();
	}
}


float DSLTC::diemMax1Mon(string maMH, string masv) {
	int soMon = 0;
	LopTC* loptc[MAX_LOPTC];
	for (int i = 0; i < n; i++) {
		if (lopTC[i]->getMaMH() == maMH) {
			loptc[soMon] = new LopTC();
			loptc[soMon++] = this->lopTC[i];
		}

	}
	float maxDiem = 0;
	//if (soMon == 0) return -1;
	int monDaHoc = 0;
	for (int i = 0; i < soMon; i++) {
		int viTri = tim_LTC(loptc[i]->getMaLopTC());
		if (lopTC[viTri]->getDSDK().getDiemSV(0) > 0 && checkDK_LTC(viTri, masv) == true) {
			monDaHoc++;
			if (maxDiem < lopTC[viTri]->getDSDK().getDiemSVBangMa(masv)) {

				maxDiem = lopTC[viTri]->getDSDK().getDiemSVBangMa(masv);
				//cout << "  -" << maMH << "-0-" << masv << "    ";
			}
		}
	}
	if (monDaHoc == 0) return -1;


	return maxDiem;
}


void DSLTC::xuatDiemTK1Lop(treeMH MH,DSSV sv,string str, int tongSoSV) {
	int tongMH = 0;
	Subject* arrDaMo = new Subject[100];
	MH.nhapMHMoVaoMang(arrDaMo, MH.getRoot(), tongMH);
	setfillstyle(SOLID_FILL, mauNen);
	bar(0, 0, 1525, 777);
	setbkcolor(Be);
	setfillstyle(SOLID_FILL, Be);
	bar(397, 20, 1173, 100);
	settextstyle(10, 0, 7);
	setcolor(Blue);
	outtextxy((397 + 1173) / 2 - textwidth(convertStringToChar(str)) / 2, (20 + 100) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
	vien(397, 1173, 20, 100);
	//tieuDeLopSV();
	buttonBack();
	setfillstyle(SOLID_FILL, BlueNhat);
	bar(40, 243, 1490, 744);
	vien(40, 1490, 243, 744);
	buttonTien();
	buttonLui();
	buttonTienMH();
	buttonLuiMH();
	//textDiemTK1Lop(sv->getDataSV().getMaLop());
	int x = -1, y = -1;
	int batDau = 0;
	int ketThuc = (tongSoSV >= maxDong) ? maxDong : tongSoSV;
	Table newTable = table_DiemTK1Lop();
	newTable.drawTable(maxDong);
	int trangHienTai = 1;
	int tongSoTrang = ((tongSoSV - 1) / maxDong) + 1;
	int batDauMH = 0;
	int ktMH = (tongMH >= 5) ? 5 : tongMH;
	int trangMHHT = 1;
	int tongSoTrangMH = ((tongMH - 1) / 5) + 1;
	string strSTT = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	settextstyle(10, 0, 1);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(strSTT)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(strSTT)) / 2, convertStringToChar(strSTT));

	string strSTT1 = to_string(trangMHHT) + " / " + to_string(tongSoTrangMH);
	settextstyle(10, 0, 1);
	setbkcolor(mauNen); setcolor(Den);
	outtextxy((1020 + 1100) / 2 - textwidth(convertStringToChar(strSTT1)) / 2, (230 + 190) / 2 - textheight(convertStringToChar(strSTT1)) / 2, convertStringToChar(strSTT1));

	bool ok = true;
	int hD = 0;
	bool On = true;
	xuat1TrangDiemTK1Lop(sv,str, batDau, ketThuc, newTable, hD, arrDaMo, batDauMH, ktMH, tongSoSV, tongMH);
	while (On) {
		switch (hD) {
		case 1: {
			batDau = batDau - maxDong;
			ketThuc = batDau + maxDong;
			trangHienTai--;

			strSTT = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
			settextstyle(10, 0, 1);
			setbkcolor(BlueNhat); setcolor(Den);
			outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(strSTT)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(strSTT)) / 2, convertStringToChar(strSTT));
			xuat1TrangDiemTK1Lop(sv,str, batDau, ketThuc, newTable, hD, arrDaMo, batDauMH, ktMH, tongSoSV, tongMH);
			break;
		}
		case 2: {
			batDau = batDau + maxDong;
			ketThuc = (ketThuc + maxDong > tongSoSV) ? tongSoSV : ketThuc + maxDong;
			trangHienTai++;

			strSTT = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
			settextstyle(10, 0, 1);
			setbkcolor(BlueNhat); setcolor(Den);
			outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(strSTT)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(strSTT)) / 2, convertStringToChar(strSTT));
			xuat1TrangDiemTK1Lop(sv,str, batDau, ketThuc, newTable, hD, arrDaMo, batDauMH, ktMH, tongSoSV, tongMH);
			break;
		}
		case 3: {
			On = 0;
			break;
		}
		case 4: {
			batDauMH = batDauMH - 5;
			ktMH = batDauMH + 5;
			trangMHHT--;

			strSTT1 = to_string(trangMHHT) + " / " + to_string(tongSoTrangMH);
			settextstyle(10, 0, 1);
			setbkcolor(mauNen); setcolor(Den);
			outtextxy((1020 + 1100) / 2 - textwidth(convertStringToChar(strSTT1)) / 2, (230 + 190) / 2 - textheight(convertStringToChar(strSTT1)) / 2, convertStringToChar(strSTT1));
			xuat1TrangDiemTK1Lop(sv,str, batDau, ketThuc, newTable, hD, arrDaMo, batDauMH, ktMH, tongSoSV, tongMH);
			break;
		}
		case 5: {
			batDauMH = batDauMH + 5;
			ktMH = (ktMH + 5 > tongMH) ? tongMH : (ktMH + 5);
			trangMHHT++;
			strSTT1 = to_string(trangMHHT) + " / " + to_string(tongSoTrangMH);
			settextstyle(10, 0, 1);
			setbkcolor(mauNen); setcolor(Den);
			outtextxy((1020 + 1100) / 2 - textwidth(convertStringToChar(strSTT1)) / 2, (230 + 190) / 2 - textheight(convertStringToChar(strSTT1)) / 2, convertStringToChar(strSTT1));
			xuat1TrangDiemTK1Lop(sv,str, batDau, ketThuc, newTable, hD, arrDaMo, batDauMH, ktMH, tongSoSV, tongMH);
			break;
		}
		}


	}
	delete[] arrDaMo;
}


void DSLTC::xuat1TrangDiemTK1Lop(DSSV sv,string str, int batDau, int ketThuc, Table Bang, int& hD, Subject* arr, int batDauMH, int ktMH, int tongSoSV, int tongSoMH) {
	hD = 0;
	int soDong = ketThuc % maxDong;
	if (soDong == 0) soDong = maxDong;
	if (ketThuc == 0 && batDau == 0) soDong = maxDong;
	else {
		int soDongTrong = maxDong - ketThuc % maxDong;
		soDong = ketThuc % maxDong == 0 ? ketThuc : ketThuc + soDongTrong;
	}
	int soMH = ktMH % 5;
	if (soMH == 0) soMH = 5;
	if (ktMH == 0 && batDauMH == 0) soMH = 5;
	else {
		int soDongMH = 5 - ktMH % 5;
		soMH = ktMH % 5 == 0 ? ktMH : ktMH + soDongMH;
	}
	char* STT = convertIntToChar(0);

	NodeSV* SV = sv.getHeadSV();
	while (SV != NULL) {
		if (SV->getDataSV().getMaLop() == str) break;
		SV = SV->getNextSV();
	}
	for (int i = 0; i < batDau; i++) {
		SV = SV->getNextSV();
	}
	int x = tableLeft;
	int x1 = x + 680;
	int y = tableTop + kcY / 2 - textheight(STT) / 2;
	setbkcolor(BlueNhat); setcolor(Den); settextstyle(10, 0, 1);
	for (int i = 0; i < 5; i++) {
		outtextxy(x1 + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		x1 += Bang.getCols(4)->getChieuRong();

		outtextxy(x1 + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

		x1 += Bang.getCols(5)->getChieuRong();
		outtextxy(x1 + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(6)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

		x1 += Bang.getCols(6)->getChieuRong();

		outtextxy(x1 + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(7)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		x1 += Bang.getCols(7)->getChieuRong();

		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(8)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
	}
	x1 = x + 680;
	for (int i = batDauMH; i < soMH; i++) {
		outtextxy(x1 + (Bang.getCols(4)->getChieuRong() / 2 - textwidth(convertStringToChar(arr[i].getMaMH())) / 2), y, convertStringToChar(convertStringToChar(arr[i].getMaMH())));
		x1 += Bang.getCols(4)->getChieuRong();
	}
	for (int i = batDau; i < soDong; i++) {
		y += kcY;
		if (i >= ketThuc) {
			x = tableLeft;
			STT = convertIntToChar(i + 1);
			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(0)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

			x += Bang.getCols(1)->getChieuRong();
			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

			x += Bang.getCols(2)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(3)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(4)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

			x += Bang.getCols(5)->getChieuRong();
			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(6)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

			x += Bang.getCols(6)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(7)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(7)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(8)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));


			continue;
		}



		x = tableLeft;
		//STT
		STT = convertIntToChar(i + 1);
		//Xoa STT cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//Xuat STT moi
		outtextxy(x + (Bang.getCols(0)->getChieuRong() / 2 - textwidth(STT) / 2), y, STT);
		x += Bang.getCols(0)->getChieuRong();
		// MaSV
		// Xoa maSV cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// Xuat maSV moi
		outtextxy(x + (Bang.getCols(1)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getMaSV())) / 2), y, convertStringToChar(SV->getDataSV().getMaSV()));
		x += Bang.getCols(1)->getChieuRong();
		// HO
		// Xoa Ho cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// Xuat Ho moi
		outtextxy(x + (Bang.getCols(2)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getHo())) / 2), y, convertStringToChar(SV->getDataSV().getHo()));
		x += Bang.getCols(2)->getChieuRong();
		//Ten
		//Xoa Ten cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//Xuat Ten moi
		outtextxy(x + (Bang.getCols(3)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getTen())) / 2), y, convertStringToChar(SV->getDataSV().getTen()));
		x += Bang.getCols(3)->getChieuRong();
		//DIEM
		//Xoa DIEM cu
		x1 = x;
		for (int i = 0; i < 5; i++) {
			outtextxy(x1 + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x1 += Bang.getCols(4)->getChieuRong();

			outtextxy(x1 + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

			x1 += Bang.getCols(5)->getChieuRong();
			outtextxy(x1 + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(6)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

			x1 += Bang.getCols(6)->getChieuRong();

			outtextxy(x1 + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(7)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x1 += Bang.getCols(7)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(8)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		}
		//them diem moi 
		x1 = x;
		// nhập điêm vào đây 
		int dem = 4;
		float diem = 0;
		for (int i = batDauMH; i < soMH; i++) {
			/*outtextxy(x + (Bang.getCols(4)->getChieuRong() / 2 - textwidth(convertStringToChar(arr[i].getMaMH())) / 2), y, convertStringToChar(convertStringToChar(arr[i].getMaMH())));
			x1 += Bang.getCols(4)->getChieuRong();*/

			diem = diemMax1Mon(arr[i].getMaMH(), SV->getDataSV().getMaSV());
			if (diem >= 0) {
				outtextxy(x + (Bang.getCols(dem)->getChieuRong() / 2 - textwidth(convertFloatToChar(diem)) / 2), y, convertFloatToChar(diem));

			}
			x += Bang.getCols(dem)->getChieuRong();
			dem++;
		}
		x = tableLeft;

		//clearmouseclick(WM_LBUTTONDOWN);
		SV = SV->getNextSV();
	}
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && (batDau) / 10 > 0) {
				cout << "lui";
				hD = 1;
				break;
			}
			else if (((777 <= x && x <= 848 && 703 <= y && y <= 734) && (ketThuc - 1) / 10 < (tongSoSV - 1) / 10)) {
				hD = 2;
				cout << "Tien";
				break;
			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
				hD = 3;
				break;
			}
			else if (950 <= x && x <= 1020 && 190 <= y && y <= 230 && batDauMH / 5 > 0) {
				hD = 4;
				break;
			}
			else if (1100 <= x && x <= 1180 && 190 <= y && y <= 230 && (ktMH - 1) / 5 < (tongSoMH - 1) / 5) {
				hD = 5; break;


			}
		}
	}
}

void DSLTC::freeDS_LTC() {
	for (int i = 0; i < n; i++) {
		if (this->lopTC[i] != NULL) {
			lopTC[i]->getDSDK().free_DSDK();
			delete lopTC[i];

		}
	}

	n = 0;
}


void DSLTC::menuLTC() {

	_menuLTC();


	treeMH DSMH;
	DSMH.xuatDataMH();

	DSSV sv;
	sv.xuatDSSV();

	char s[] = { "" };
	int x = -1, y = -1;

	thaoTac hDLTC = XUAT;
	int thaoTacRoi = 0;
	int soLuong = 0;
	int viTriChon = 0;
	int ok = 1;
	while (ok) {
		if (thaoTacRoi == 0) {
			if (ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				clearmouseclick(WM_LBUTTONDOWN);
				if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
					hDLTC = BACK;
				}
				else if (850 <= x && x <= 990 && 169 <= y && y <= 214) {
					hDLTC = THEM;
				}
				else if (1010 <= x && x <= 1150 && 169 <= y && y <= 214) {
					hDLTC = HUY;
				}
				else if (320 <= x && x <= 1170 && 1330 <= y && y <= 214) {
					hDLTC = DANGKY;
				}
				else if (1359 <= x && x <= 1490 && 169 <= y && y <= 214) {
					hDLTC = XUATDK;
				}
			}
		}
		switch (hDLTC) {
		case XUAT: {
			NodeSV* Sv = { NULL };

			cleardevice();
			_menuLTC();
			soLuong = n;
			xuatDSTheoTrang_LTC(DSMH, viTriChon, soLuong, hDLTC, s, thaoTacRoi, sv);

			break;
		}
		case THEM: {
			//cleardevice();
			menuThemLTC();
			soLuong = n;
			int viTri = 0;
			inputNhapLTC("", "", "", "", "", "", "", 0, DSMH, viTri, hDLTC);
			cleardevice();
			hDLTC = XUAT;
			break;
		}
		case DANGKY: {
			//cleardevice();
			tieuDeLTC();
			menuDkLTC();
			soLuong = n;

			inputDkLTC(DSMH, "", "", "", sv, hDLTC);
			hDLTC = XUAT;
			break;
		}
		case HUY: {
			//cleardevice();
			menuHuyLTC();
			//soLuong = n;
			huyLTC("", "", hDLTC);
			hDLTC = XUAT;
			//	cleardevice();
				//_menuLTC();
				//soLuong = n;
				//xuatDSTheoTrang_LTC(DSMH, viTriChon, soLuong, hDLTC, s, thaoTacRoi, dsLop);
				//hDLTC = XUAT;
				//
			break;
		}
		case XUATDK: {
			menuXuatSVDK();

			xuatDSDK(sv, hDLTC, DSMH);
			cleardevice();
			_menuLTC();
			soLuong = n;
			xuatDSTheoTrang_LTC(DSMH, viTriChon, soLuong, hDLTC, s, thaoTacRoi, sv);
			break;
		}
		case BACK: {

			cleardevice();
			ok = 0;
			break;
		}


		}

	}

}


void DSLTC::menuDiem() {


	treeMH DSMH;
	DSMH.xuatDataMH();

	DSSV sv;
	sv.xuatDSSV();

	thaoTac hDLTC = XUAT;
	int soLuong;
	int x = -1, y = -1;
	bool ok = true;
	while (ok) {

		switch (hDLTC) {
		case XUAT: {


			cleardevice();
			_menuDiem();
			soLuong = n;
			xuatDiemLTC(DSMH, sv, soLuong, hDLTC);
			break;
		}
		case DIEM1SV: {
			//cleardevice();

			menuInputDiem1SV();
			xuatDiem1SV(DSMH, sv, hDLTC);
			cleardevice();
			hDLTC = XUAT;
			break;
		}
		case BACK: {
			//delete dsLop;
			//freeDS_LTC();
			cleardevice();
			ok = 0;
			break;
		}
		case DIEMTB: {
			cleardevice();
			xuatDiem(DSMH, sv,1);
			hDLTC = XUAT;
			break;
		}
		case DIEMTK: {
			cleardevice();
			xuatDiem(DSMH, sv,2);
			hDLTC = XUAT;
			break;
		}
		}
	}

}
