#pragma once

#include "Const.h"
#include "SV.h"


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
public:
	DSDK();

	DSDK(int maxSV);

	SVDangKy** getSV();

	string getMaSVDK(int index);

	float getDiemSV(int index);

	float getDiemSVBangMa(string MASV);

	void suaDiemSV(int viTri, float diem);

	//	void getDSDK();

	bool isNull_DSDK();

	bool isFull_DSDK();

	int timNhiPhan(int l, int r, string masv);

	int timSV_DK(string MASV);

	int themDau_DK(SVDangKy Sv);

	int them_DK(SVDangKy Sv);

	int xoaSV_DK(string MASV);

	float timDiemSV_DK(string MASV);

	bool checkSV_DK(string maSV);

	void sortDSDK(int left, int right);

	void writeData_DK(int maLopTC, ofstream& fileOut);

	void xuatDS1Trang_DK(DSSV sv, int batDau, int ketThuc, Table newTable);

	void xuatDSTrang_DK(DSSV sv, int tongSoDong, thaoTac& hDDK, int& kiemTra);

	void xuatDS(DSSV sv);

	void free_DSDK();


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
}

DSDK::DSDK(int maxSV) {
	SV = new SVDangKy[maxSV];
	n = 0;
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

float DSDK::getDiemSVBangMa(string MASV) {
	int index = timSV_DK(MASV);
	return SV[index].getDiem();

}

void DSDK::suaDiemSV(int viTri, float diem) {
	if (diem < 0 || diem>10) {
		MessageBox(
			NULL,
			(LPCWSTR)convertCharArrayToLPCWSTR("DIEM KHONG HOP LE !!!"),
			(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
			MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
		);
	}
	else {
		SV[viTri].setDiem(diem);
	}
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
	if (n == 0) {
		SV[n++] = Sv;
		return 1;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (Sv.getMaSV() < SV[i].getMaSV()) {

				for (int j = n; j > i; j--) {
					SV[j] = SV[j - 1];
				}
				SV[i] = Sv;
				n++;
				return 1;
			}
		}
	}

	SV[n++] = Sv;
	//SV[n] = Sv;

	//sortDSDK(0, n);



	return 1;

}

int DSDK::timNhiPhan(int l, int r, string masv) {
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (SV[mid].getMaSV() == masv)
			return mid;

		if (SV[mid].getMaSV() > masv)
			return timNhiPhan(l, mid - 1, masv);

		return timNhiPhan(mid + 1, r, masv);
	}
	return -1;

}

int DSDK::timSV_DK(string MASV) {
	return timNhiPhan(0, n - 1, MASV);
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
	for (int i = 0; i < n; i++) {
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


void DSDK::xuatDS1Trang_DK(DSSV sv, int batDau, int ketThuc, Table Bang) {
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
		//Sv = dslop.timDataSinhVien()
		Sv = sv.timSV(SV[i].getMaSV());

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


void DSDK::xuatDSTrang_DK(DSSV sv, int tongSoDong, thaoTac& hDDK, int& kiemTra) {

	cout << "1";

	int soDu = (tongSoDong % maxDong > 0) ? 1 : 0;

	int tongSoTrang = tongSoDong / maxDong + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc = (tongSoDong > maxDong) ? maxDong : tongSoDong;

	Table newTable = table_DK();
	newTable.drawTable(maxDong);

	xuatDS1Trang_DK(sv, batDau, ketThuc, newTable);

	string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));

	int x = -1, y = -1;

	while (1) {
		//delay(200);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (tableLeft <= x && x <= tableRightLopTC && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
				int check = false;
				for (int i = 0; i < n; i++) {
					if (SV[i].getDiem() > 0) {
						check = true;
						break;
					}
				}
				if (check == true) {
					MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR("LOP DA NHAP DIEM. KHONG THE HUY DANG KY"),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					);
				}
				else {
					string str1 = "SV ";
					string str2 = SV[(y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong].getMaSV();
					string str3 = " MUON HUY DANG KY LOP ?";
					str1 = str1 + str2;
					str1 = str1 + str3;
					int tmp = MessageBox(
						NULL,
						(LPCWSTR)convertCharArrayToLPCWSTR(str1.c_str()),
						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
						MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
					);
					if (tmp == IDYES) {
						xoaSV_DK(SV[(y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong].getMaSV());
						kiemTra++;
						tongSoDong--;
						xuatDSTrang_DK(sv, tongSoDong, hDDK, kiemTra);

						break;
					}
				}


			}
			if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {

				batDau = batDau - maxDong;
				ketThuc = batDau + maxDong;
				trangHienTai--;
				xuatDS1Trang_DK(sv, batDau, ketThuc, newTable);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if ((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang) {
				batDau = batDau + maxDong;
				ketThuc = (ketThuc + maxDong > tongSoDong) ? tongSoDong : ketThuc + maxDong;
				trangHienTai++;
				xuatDS1Trang_DK(sv, batDau, ketThuc, newTable);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
				//	thaoTacRoi = 1;
				hDDK = XUAT;
				break;

			}
		}
	}

	newTable.freeTable();

}



void DSDK::xuatDS(DSSV sv) {
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

	delete[] SV;
	n = 0;
}


void DSDK::sortDSDK(int l, int r) {
	string p = SV[(l + r) / 2].getMaSV();
	int i = l, j = r;
	while (i < j) {
		while (SV[i].getMaSV() < p) {
			i++;
		}
		while (SV[j].getMaSV() > p) {
			j--;
		}
		if (i <= j) {
			string tmp = SV[i].getMaSV();
			SV[i].setMaSV(SV[j].getMaSV()); // = SV[j].setMaSV(SV[i].getMaSV());
			SV[j].setMaSV(tmp);

			float tam = SV[i].getDiem();
			SV[i].setDiem(SV[j].getDiem());
			SV[j].setDiem(tam);
			i++;
			j--;
		}
	}
	if (i < r) {
		sortDSDK(i, r);
	}
	if (l < j) {
		sortDSDK(l, j);
	}
}



