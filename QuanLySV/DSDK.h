#pragma once

#include "Const.h"
#include "SV.h"
#include "LopSV.h"


class SVDangKy {
private:
	string MASV;
	float DIEM;
public:
	SVDangKy();

	SVDangKy(string MASV);

	// setter getter
	void setMaSV(string MASV);

	void setDiem(float DIEM);

	string getMaSV();

	float getDiem();
	//
};

class DSDK {
private:
	SVDangKy* SV;// = new SVDangKy[10000];
	int n;
	int ndk;
public:
	DSDK();

	void setNdk(int n);

	int getNdk();

	// setter getter
	int getN_DK();

	void setN_DK(int n_);

	SVDangKy** getSV();

	string getMaSVDK(int index);

	float getDiemSV(int index);

	//	void getDSDK();

	bool isNull_DSDK();

	bool isFull_DSDK();

	int timSV_DK(string MASV);

	int themDau_DK(SVDangKy Sv);

	int them_DK(SVDangKy Sv);

	int xoaSV_DK(string MASV);

	float timDiemSV_DK(string MASV);

	bool checkSV_DK(string maSV);

	int them(SVDangKy* Sv) {
		if (isFull_DSDK() == true) return 0;
		/*
		if (isNull_DSDK() == true) {
			themDau_DK(Sv);
			return 1;
		}
		*/
		SV[n++] = *Sv;
		return 1;

	}

	void xuat() {
		//cout << getNdk();
		cout << " _" << getN_DK() << "_ ";
		for (int i = 0; i < n; i++) {
			cout << SV[i].getMaSV() << " ^ ";
		}
		if (n == 0) cout << ":((((";
	}


	void writeData_DK(int maLopTC, ofstream& fileOut);

	void xuatDS1Trang_DK(DSLH dslop, int batDau, int ketThuc, Table newTable);

	void xuatDSTrang_DK(DSLH dslop, int tongSoDong);

	void xuatDS(DSLH dslop);

	void free_DSDK();

	void swapSVDK(string maSV1, string maSV2);

	void sortDSDK();
};


// ================= Sinh Vien Dang Ky ==================

SVDangKy::SVDangKy() {
	this->MASV = "";
	this->DIEM = -1;
}

SVDangKy::SVDangKy(string MASV) {
	this->MASV = MASV;
	this->DIEM = -1;
}

void SVDangKy::setMaSV(string MASV) {
	this->MASV = MASV;
}

void SVDangKy::setDiem(float DIEM) {
	this->DIEM = DIEM;
}

float SVDangKy::getDiem() {
	return this->DIEM;
}

string SVDangKy::getMaSV() {
	return this->MASV;
}


// ================= Danh Sach Dang Ky ===================


DSDK::DSDK() {
	SV = new SVDangKy[1000];
	n = 0;
	ndk = 0;
}

void DSDK::setNdk(int a) {
	ndk = a;
}

int DSDK::getNdk() {
	int ans = 0;
	for (int i = 0; i < 10000; i++)
	{
		if (SV[i].getMaSV() != "") {
			ans++;
		}
	}
	return ans;
}

int DSDK::getN_DK() {
	/*
	for (int i = 0; i < 10000; i++)
	{
		if (SV[i].getMaSV() == "") {
			return i;
		}
	}
	*/
	return this->n;
	// return sizeof(SV) / sizeof(SVDangKy);
	//return
}

void DSDK::setN_DK(int n_) {
	this->n = n_;
}

SVDangKy** DSDK::getSV() {
	return &SV;
}


string DSDK::getMaSVDK(int index) {
	return SV[index].getMaSV();
}

float DSDK::getDiemSV(int index) {
	return SV[index].getDiem();
}


bool DSDK::isNull_DSDK() {
	return this->n == 0;
}

bool DSDK::isFull_DSDK() {
	return this->n = SV_MAX;
}

int DSDK::themDau_DK(SVDangKy Sv) {
	if (isFull_DSDK() == true) return 0;

	if (isNull_DSDK() == false) {
		for (int i = n; i > 0; i--) {
			SV[i] = SV[i - 1];

		}
	}
	SV[0] = Sv;
	n++;
	return 1;
}



int DSDK::them_DK(SVDangKy Sv) {
	//if (isFull_DSDK() == true) return 0;
	/*
	if (isNull_DSDK() == true) {
		themDau_DK(Sv);
		return 1;
	}
	*/
	if (Sv.getMaSV() == "") return 0;
	SV[n] = Sv;
	n++;
	//	getN_DK();
	return 1;

}

int DSDK::timSV_DK(string MASV) {
	for (int i = 0; i < n; i++)
	{
		if (this->SV[i].getMaSV() == MASV) {
			return i;
		}
	}
	return -1;
}

int DSDK::xoaSV_DK(string _MASV) {
	if (isNull_DSDK() == true) return -1;

	int viTri = timSV_DK(_MASV);

	if (viTri < 0 || viTri > n) return -1;

	for (int i = viTri; i < n; i++)
	{
		SV[i] = SV[i + 1];
	}
	n--;
	return 1;
}


float DSDK::timDiemSV_DK(string MASV) {
	if (isNull_DSDK() == true) return -1;

	if (timSV_DK(MASV) == -1) return -1;

	return SV[timSV_DK(MASV)].getDiem();
}


bool DSDK::checkSV_DK(string maSV) {
	for (int i = 0; i < n; i++) {
		if (SV[i].getMaSV() == maSV) return true;
	}
	return false;
}

void DSDK::writeData_DK(int maLopTC, ofstream& fileOut) {
	char temp = ',';
	for (int i = 0; i < getN_DK(); i++) {
		fileOut << maLopTC;
		fileOut << temp;
		fileOut << SV[i].getMaSV();
		fileOut << temp;
		fileOut << SV[i].getDiem();
		//	if (i != getN_DK() - 1) {
		fileOut << "\n";
		//	}

	}
	/*
	fileOut << maLopTC;
	fileOut << temp;
	fileOut << DK.getMaSV();
	fileOut << temp;
	fileOut << DK.getDiem();
	*/
	//fileOut <<"\n";
}


void DSDK::xuatDS1Trang_DK(DSLH dslop, int batDau, int ketThuc, Table Bang) {
	int soDong = ketThuc % maxDong;
	if (soDong == 0) soDong = maxDong;
	if (ketThuc == 0 && batDau == 0) soDong = maxDong;
	else {
		int soDongTrong = maxDong - ketThuc % maxDong;
		soDong = ketThuc % maxDong == 0 ? ketThuc : ketThuc + soDongTrong;
	}

	string strSTT;
	NodeSV* Sv = { NULL };

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


			continue;
		}




		strSTT = convertIntToString(i + 1);

		x = tableLeft;

		Sv = dslop.timDataSinhVien(SV[i].getMaSV());

		// xoa STT cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat STT moi
		outtextxy(x + (Bang.getCols(0)->getChieuRong() / 2 - textwidth(convertStringToChar(strSTT)) / 2), y, convertStringToChar(strSTT));
		x += Bang.getCols(0)->getChieuRong();

		// xoa MA SV
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat MA SV moi
		outtextxy(x + (Bang.getCols(1)->getChieuRong() / 2 - textwidth(convertStringToChar(Sv->getDataSV().getMaSV())) / 2), y, convertStringToChar(Sv->getDataSV().getMaSV()));
		x += Bang.getCols(1)->getChieuRong();

		// xoa HO cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat  HO moi
		outtextxy(x + (Bang.getCols(2)->getChieuRong() / 2 - textwidth(convertStringToChar(Sv->getDataSV().getHo())) / 2), y, convertStringToChar(Sv->getDataSV().getHo()));
		x += Bang.getCols(2)->getChieuRong();

		// xoa TEN  cu 
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat TEN moi
		outtextxy(x + (Bang.getCols(3)->getChieuRong() / 2 - textwidth(convertStringToChar(Sv->getDataSV().getTen())) / 2), y, convertStringToChar(Sv->getDataSV().getTen()));
		x += Bang.getCols(3)->getChieuRong();

		// xoa SDT cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat SDT moi
		outtextxy(x + (Bang.getCols(4)->getChieuRong() / 2 - textwidth(convertStringToChar(Sv->getDataSV().getSdt())) / 2), y, convertStringToChar(Sv->getDataSV().getSdt()));
		x += Bang.getCols(4)->getChieuRong();

		// xoa LOP cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y,
			convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// xuat LOP moi
		outtextxy(x + (Bang.getCols(5)->getChieuRong() / 2 - textwidth(convertStringToChar(Sv->getDataSV().getMaLop())) / 2), y, convertStringToChar(Sv->getDataSV().getMaLop()));
		x += Bang.getCols(5)->getChieuRong();

		x = tableLeft;

		//SV = SV->getNextSV();
	}
}


void DSDK::xuatDSTrang_DK(DSLH dslop, int tongSoDong) {



	int soDu = (tongSoDong % maxDong > 0) ? 1 : 0;

	int tongSoTrang = tongSoDong / maxDong + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc = (tongSoDong > maxDong) ? maxDong : tongSoDong;

	Table newTable = table_DK();
	newTable.drawTable(maxDong);

	xuatDS1Trang_DK(dslop, batDau, ketThuc, newTable);

	string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));

	int x = -1, y = -1;

	while (1) {
		//delay(200);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if ((600 <= x && x <= 670 && 670 <= y && y <= 700) && trangHienTai > 1) {

				batDau = batDau - maxDong;
				ketThuc = batDau + maxDong;
				trangHienTai--;
				xuatDS1Trang_DK(dslop, batDau, ketThuc, newTable);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				outtextxy((670 + 770) / 2 - textwidth(convertStringToChar(str)) / 2, (670 + 700) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if ((770 <= x && x <= 830 && 670 <= y && y <= 700) && trangHienTai < tongSoTrang) {
				batDau = batDau + maxDong;
				ketThuc = (ketThuc + maxDong > tongSoDong) ? tongSoDong : ketThuc + maxDong;
				trangHienTai++;
				xuatDS1Trang_DK(dslop, batDau, ketThuc, newTable);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				outtextxy((670 + 770) / 2 - textwidth(convertStringToChar(str)) / 2, (670 + 700) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
				//	thaoTacRoi = 1;
			//		hDLTC = BACK;
				break;

			}
		}
	}

	newTable.freeTable();

}



void DSDK::xuatDS(DSLH dslop) {
	string str1 = "";

	int nInput = 1;
	Input* input[1];

	input[0] = new Input(str1, 3, "Ma Lop", 50, 0, 500, 900, 200, 225, graynhat, 0, 4);

	int x = -1; int y = -1;
	input[0]->draw();

	while (1) {
		// delay(10);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (500 <= x && x <= 900 && 200 <= y && y <= 225) {
				input[0]->setCheck(true);

				input[0]->addChar();
			}
			else if (417 <= x && x <= 512 && 709 <= y && y <= 848) {

				//
				break;
			}
			else if (1057 <= x && x <= 1151 && 709 <= y && y <= 748) {

			}
		}
	}
}




void DSDK::free_DSDK() {
	/*
	for (int i = 0; i < n; i++) {
		if (SV[i] != nullptr) {
			delete SV[i];

			}
	}
	*/
	delete[] SV;
	n = 0;
}


void DSDK::swapSVDK(string maSV1, string maSV2) {
	string	tmp = maSV1;
	maSV1 = maSV2;
	maSV2 = tmp;
}

void DSDK::sortDSDK() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (SV[i].getMaSV() > SV[j].getMaSV()) {
				swapSVDK(SV[i].getMaSV(), SV[j].getMaSV());
			}
		}
	}
}


