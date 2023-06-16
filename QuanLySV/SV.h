#pragma once
#include"Const.h"
#include"Convert.h"
#include"Input.h"
#include"Button.h"


class SinhVien {
private:
	string maSV;
	string ho;
	string ten;
	string sex;
	string sdt;
	string maLop;
	string namNhap;
public:
	void setMaSV(string maSV);
	void setHo(string ho);
	void setTen(string ten);
	void setSex(string sex);
	void setSdt(string sdt);
	void setMaLop(string maLop);
	void setNamNhap(string namNhap);
	string getMaSV();
	string getHo();
	string getTen();
	string getSex();
	string getSdt();
	string getMaLop();
	string getNamNhap();
	void setData(SinhVien data);
};
class NodeSV {
private:
	SinhVien dataSV;
	NodeSV* nextSV;
public:
	NodeSV();
	NodeSV(SinhVien dataSV);
	void setDataSV(SinhVien dataSV);
	SinhVien& getDataSV();
	void setNextSV(NodeSV* nextSV);
	NodeSV* getNextSV();
	void setNodeSV(NodeSV* SV);
	NodeSV* getNodeSV();
	void vietSV(SinhVien SV, ofstream& fileOut);
};
class DSSV {
private:
	NodeSV* headSV;
public:
	DSSV();
	void setHeadSV(NodeSV* headSV);
	NodeSV*& getHeadSV();
	bool checkRong();
	void freeSV(NodeSV*& SV);
	void pushFrontSv(NodeSV* SV);
	//int viTriThem(NodeSV* SV);
	bool viTriThem(NodeSV* tmp, NodeSV* sv);
	void themSV(SinhVien& SV, int& check);
	NodeSV* timSV(string maSV);
	void xoaSV(string maSV);
	bool checkTrung(string maSV);
	int soLuongSV();
	int soLuongSVLop(string maLop );
	void vietDSSV();
	void mangLop(string arr[100],int& n);
	void xuatDSSV();
	void locSV(string key, DSSV& dssv, int& n);
	void xuat1TrangDSV(NodeSV* SV, int batDau, int ketThuc, Table Bang);
	void xuatTrangDSSV(DSSV dssv, int tongSoSV, thaoTac& hD, char* s, int& on);
	void nhapLocSV(char* s, thaoTac& hD);
	void nhapSV(string str1, string str2, string str3, string str4, string str5, string str6, string str7, int check);
	void menuSV();
	void menuSetSV(int& on);
};
//class SinhVien
void SinhVien::setMaSV(string maSV) {
	this->maSV = maSV;
}
void SinhVien::setHo(string ho) {
	this->ho = ho;
}
void SinhVien::setTen(string ten) {
	this->ten = ten;
}
void SinhVien::setSex(string sex) {
	this->sex = sex;
}
void SinhVien::setSdt(string sdt) {
	this->sdt = sdt;
}
void SinhVien::setMaLop(string maLop) {
	this->maLop = maLop;
}
void SinhVien::setNamNhap(string namNhap) {
	this->namNhap = namNhap;
}
string SinhVien::getMaSV() {
	return this->maSV;
}
string SinhVien::getHo() {
	return this->ho;
}
string SinhVien::getTen() {
	return this->ten;
}
string SinhVien::getSex() {
	return this->sex;
}
string SinhVien::getSdt() {
	return this->sdt;
}
string SinhVien::getMaLop() {
	return this->maLop;
}
string SinhVien::getNamNhap() {
	return this->namNhap;
}
void SinhVien::setData(SinhVien data) {
	this->maSV = data.maSV;
	this->ho = data.ho;
	this->ten = data.ten;
	this->sex = data.sex;
	this->sdt = data.sdt;
	
	this->namNhap = data.namNhap;
    this->maLop = data.maLop;
}
// class NodeSV
NodeSV::NodeSV() {
	this->nextSV = NULL;
}
NodeSV::NodeSV(SinhVien data) {
	this->dataSV = data;
	this->nextSV = NULL;
}
void NodeSV::setDataSV(SinhVien dataSV) {
	this->dataSV = dataSV;
}
SinhVien& NodeSV::getDataSV() {
	return this->dataSV;
}
void NodeSV::setNextSV(NodeSV* nextSV) {
	this->nextSV = nextSV;
}
NodeSV* NodeSV::getNextSV() {
	return this->nextSV;
}
void NodeSV::setNodeSV(NodeSV* SV) {
	this->dataSV = SV->dataSV;
	this->nextSV = SV->nextSV;
}
NodeSV* NodeSV::getNodeSV() {
	return this;
}
void NodeSV::vietSV(SinhVien SV, ofstream& fileOut) {
	char tmp = ',';
	fileOut << SV.getMaSV();
	fileOut << tmp;
	fileOut << SV.getHo();
	fileOut << tmp;
	fileOut << SV.getTen();
	fileOut << tmp;
	fileOut << SV.getSex();
	fileOut << tmp;
	fileOut << SV.getSdt();
	fileOut << tmp;
	fileOut << SV.getNamNhap();
	fileOut << tmp;
	fileOut << SV.getMaLop();
	fileOut << "\n";

}
// class danh sach sinh vien
DSSV::DSSV() {
	this->headSV = NULL;
}

void DSSV::setHeadSV(NodeSV* headSV) {
	this->headSV = headSV;
}
NodeSV*& DSSV::getHeadSV() {
	return this->headSV;
}
void DSSV::freeSV(NodeSV*& SV) {
	NodeSV* tmp = NULL;
	if (SV == NULL) return;
	while (SV != NULL) {
		tmp = headSV;
		SV = SV->getNextSV();
		delete tmp;
	}
}
// viet data

void DSSV::vietDSSV() {
	ofstream fileOut(dataSV.c_str(), ios::trunc);
	if (fileOut.is_open()) {
		NodeSV* tmp = getHeadSV();
		while (tmp != NULL) {
			tmp->vietSV(tmp->getDataSV(), fileOut);
		}
	}
}

void DSSV::xuatDSSV() {
	ifstream fileIn; char temp; string tempStr;
	fileIn.open(dataSV.c_str(), ios::in);
	int check = 0;
	int a = 1;
	if (fileIn.is_open())
	{
		//if(DSSV.pHead==NULL)
		while (!fileIn.eof())
		{
			SinhVien data;
			getline(fileIn, tempStr, ',');
			if (tempStr == "") break;
			data.setMaSV(tempStr.c_str());
			getline(fileIn, tempStr, ',');
			data.setHo(tempStr.c_str());
			getline(fileIn, tempStr, ',');
			data.setTen(tempStr.c_str());
			getline(fileIn, tempStr, ',');
			data.setSex(tempStr.c_str());
			getline(fileIn, tempStr, ',');
			data.setSdt(tempStr.c_str());
			getline(fileIn, tempStr, ',');
			data.setNamNhap(tempStr.c_str());
			getline(fileIn, tempStr, '\n');
			data.setMaLop(tempStr.c_str());
			NodeSV* SV = new NodeSV(data);
			/*cout << a << " ";
			cout << data.getTen() <<endl;
			a++;*/
			
			themSV(SV->getDataSV(), check);
			if (fileIn.eof()) break;

		}
	}
	fileIn.close();
}
bool DSSV::checkRong() {
	return this->headSV == NULL ? true : false;
}
void DSSV::pushFrontSv(NodeSV* SV) {
	SV->setNextSV(this->headSV);
	this->headSV = SV->getNodeSV();

}
bool DSSV::viTriThem(NodeSV* tmp,NodeSV* sv) {
	if (tmp->getDataSV().getMaLop() < sv->getDataSV().getMaLop()) {
		return true;
	}
	else if (tmp->getDataSV().getMaLop() > sv->getDataSV().getMaLop()) {
		return false;
	}
	else {
		if (tmp->getDataSV().getTen() < sv->getDataSV().getTen()) {
			return true;
		}
		else if (tmp->getDataSV().getTen() > sv->getDataSV().getTen()) {
			return false;
		}
		else {
			return tmp->getDataSV().getHo() < sv->getDataSV().getHo();
		}
	}
}
//
void DSSV::mangLop(string arr[100],int &n) {
	NodeSV* tmp = getHeadSV();
	int ok = 0;
	while (tmp != NULL) {
		ok = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == tmp->getDataSV().getMaLop()) {
				ok = 1;
				break;
			}
		}
		if (ok == 0) arr[n++] = tmp->getDataSV().getMaLop();
		tmp = tmp->getNextSV();
	}
}
void  DSSV::themSV(SinhVien& sv, int& check) {

	if (checkRong() == false) {
		NodeSV* tmp = timSV(sv.getMaSV());
		if (tmp != NULL) {
			
			if (check == 0) {
				check = 1;
				return;
			}
			else if (check == 2) {
				check = 0;
				xoaSV(tmp->getDataSV().getMaSV());
				themSV(sv, check);
				check = 2;
				return;
			}
		}
	}
	

	NodeSV* SV = new NodeSV(sv);

	/*cout << viTriThem << " ";
	cout << sv.getMaSV() << endl;*/
	if (headSV == NULL ) {
		pushFrontSv(SV);
		return;
	}
	NodeSV* tmp = this->headSV;
	while (tmp->getNextSV() != NULL && viTriThem(tmp->getNextSV(), SV)) {
		tmp = tmp->getNextSV();
	}

	SV->setNextSV(tmp->getNextSV());

	tmp->setNextSV(SV);
	return;
}
NodeSV* DSSV::timSV(string maSV) {
	NodeSV* tmp = headSV;
	while (tmp != NULL) {
		if (tmp->getDataSV().getMaSV() == maSV) {
			return tmp;
		}
		tmp = tmp->getNextSV();
	}
	return NULL;
}
void DSSV::xoaSV(string maSV) {
	if (this->headSV == NULL) return;
	NodeSV* tmp = headSV;

	if (tmp->getDataSV().getMaSV() == maSV) {

		headSV = tmp->getNextSV();
		tmp->setNextSV(NULL);
		delete tmp;
		return;

	}
	while (tmp->getNextSV() != NULL && tmp->getNextSV()->getDataSV().getMaSV() != maSV) {
		tmp = tmp->getNextSV();
	}
	if (tmp->getNextSV()->getDataSV().getMaSV() == maSV) {

		NodeSV* temp = tmp->getNextSV();
		tmp->setNextSV(temp->getNextSV());
		temp->setNextSV(NULL);
		delete temp;
		return;
	}
}
bool DSSV::checkTrung(string maSV) {
	if (getHeadSV() == NULL) return false;
	NodeSV* tmp = getHeadSV();
	while (tmp != NULL) {
		if (tmp->getDataSV().getMaSV() == maSV) {
			return true;
		}
		tmp = tmp->getNextSV();
	}
	return false;
}
int DSSV::soLuongSV() {
	int soLuong = 0;
	NodeSV* tmp = getHeadSV();
	while (tmp != NULL) {
		++soLuong;
		tmp = tmp->getNextSV();
	}
	return soLuong;
}
int DSSV::soLuongSVLop(string maLop) {
	int n = 0;
	NodeSV* tmp = getHeadSV();
	while (tmp != NULL) {
		if (tmp->getDataSV().getMaLop() == maLop) {
			n++;
		}
		tmp = tmp->getNextSV();
	}
	return n;
}

void DSSV::locSV(string key, DSSV& dssv, int& n) {
	dssv.freeSV(dssv.getHeadSV());
	dssv.setHeadSV(NULL);
	NodeSV* tmp = this->headSV;
	n = 0;
	int check = 0;
	if (!key.empty()) {
		while (tmp != NULL) {
			if (string(tmp->getDataSV().getTen()).find(key) != string::npos) {
				dssv.themSV(tmp->getDataSV(), check);
				n++;
			}

			tmp = tmp->getNextSV();
		}
	}
	else {
		for (NodeSV* p = this->headSV; p != NULL; p = p->getNextSV()) {
			dssv.themSV(p->getDataSV(), check);
			n++;
		}
	}
}
void DSSV::xuat1TrangDSV(NodeSV* SV, int batDau, int ketThuc, Table Bang) {
	int soDong = ketThuc % maxDong;
	if (soDong == 0) soDong = maxDong;
	if (ketThuc == 0 && batDau == 0) soDong = maxDong;
	else {
		int soDongTrong = maxDong - ketThuc % maxDong;
		soDong = ketThuc % maxDong == 0 ? ketThuc : ketThuc + soDongTrong;
	}
	char* STT = convertIntToChar(0);

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
			x += Bang.getCols(4)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(5)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(6)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
			x += Bang.getCols(6)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(7)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

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
		// Gioi tinh
		//Xoa gioi tinh cu 
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//Xuat gioi tinh moi 
		outtextxy(x + (Bang.getCols(4)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getSex())) / 2), y, convertStringToChar(SV->getDataSV().getSex()));
		x += Bang.getCols(4)->getChieuRong();
		//Sdt
		//Xoa Sdt cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//xuat SDt moi
		outtextxy(x + (Bang.getCols(5)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getSdt())) / 2), y, convertStringToChar(SV->getDataSV().getSdt()));
		x += Bang.getCols(5)->getChieuRong();
		//Nam Nhap Hoc
		//Xoa nam cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(6)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//xuat Nam moi
		outtextxy(x + (Bang.getCols(6)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getNamNhap())) / 2), y, convertStringToChar(SV->getDataSV().getNamNhap()));
		x += Bang.getCols(6)->getChieuRong();
		//Ma Lop
		//Xoa nam cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(7)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//xuat Nam moi
		outtextxy(x + (Bang.getCols(7)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getMaLop())) / 2), y, convertStringToChar(SV->getDataSV().getMaLop()));

		x = tableLeft;

		//clearmouseclick(WM_LBUTTONDOWN);
		SV = SV->getNextSV();
	}
}
void DSSV::xuatTrangDSSV(DSSV dssv, int tongSoSV, thaoTac& hDSV, char* s, int& on) {
	int x = -1, y = -1;
	int batDau = 0;
	int ketThuc = (tongSoSV >= maxDong) ? maxDong : tongSoSV;
	Table newTable = table_SV();
	newTable.drawTable(maxDong);
	int trangHienTai = 1;
	int tongSoTrang = ((tongSoSV - 1) / maxDong) + 1;
	string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	settextstyle(10, 0, 1);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
	bool ok = true;
	xuat1TrangDSV(dssv.getHeadSV(), batDau, ketThuc, newTable);
	NodeSV* temp = getHeadSV();
	int h = 0;
	while (ok) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (tableLeft <= x && x <= tableRightLop && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {

				int tmp = MessageBox(
					NULL,
					(LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON XOA MON LOP"),
					(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
					MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
				);
				if (tmp == IDYES) {
					temp = getHeadSV();
					for (int i = 0; i < ((y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong); i++) {
						temp = temp->getNextSV();
					}
					this->xoaSV(string(temp->getDataSV().getMaSV()));

					cleardevice();
					break;
				}
			}
			else if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {

				batDau = batDau - maxDong;
				ketThuc = batDau + maxDong;
				trangHienTai--;
				xuat1TrangDSV(dssv.getHeadSV(), batDau, ketThuc, newTable);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				settextstyle(10, 0, 1);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if (((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang)) {

				batDau = batDau + maxDong;
				ketThuc = (ketThuc + maxDong > tongSoSV) ? tongSoSV : ketThuc + maxDong;
				trangHienTai++;
				xuat1TrangDSV(dssv.getHeadSV(), batDau, ketThuc, newTable);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				settextstyle(10, 0, 1);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
				hDSV = BACK;

				break;
			}
			else if (1390 <= x && x <= 1490 && 169 <= y && y <= 214) {
				hDSV = THEM;

				break;
			}
			else if (563 <= x && x <= 630 && 169 <= y && y <= 205) {
				hDSV = LOC;

				break;
			}
			else if (183 <= x && x <= 559 && 169 <= y && y <= 205) {
				nhapLocSV(s, hDSV);// nhập dự liệu lọc vào ô để lấy ra string để ném vào hàm locSV t
				break;
			}
			else if (1400 <= x && x <= 1490 && 10 <= y && y <= 60) {
				on = 0;
				hDSV = BACK;
				break;
			}
		}
		else if (ismouseclick(WM_RBUTTONDOWN)) {
			getmouseclick(WM_RBUTTONDOWN, x, y);
			clearmouseclick(WM_RBUTTONDOWN);
			if (tableLeft <= x && x <= tableRightLop && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
				temp = dssv.getHeadSV();
				for (int i = 0; i < ((y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong); i++) {
					temp = temp->getNextSV();
				}
				menuSuaSV();
				nhapSV(string(temp->getDataSV().getMaSV()), string(temp->getDataSV().getHo()), string(temp->getDataSV().getTen()), string(temp->getDataSV().getSex()), string(temp->getDataSV().getSdt()), string(temp->getDataSV().getNamNhap()),string(temp->getDataSV().getMaLop()), 2 );
				cleardevice();
				break;
			}
		}
	}
	newTable.freeTable();
}
void DSSV::nhapSV(string str1, string str2, string str3, string str4, string str5, string str6,string str7, int check ) {
	Input* input[7];
	input[0] = new Input(str1, 2, "Ma Sinh Vien", 15, 0, 650, 1050, 210, 250, graynhat, 0, 3);
	input[1] = new Input(str2, 1, "Ho", 50, 0, 650, 1050, 280, 320, graynhat, 0, 3);
	input[2] = new Input(str3, 1, "Ten", 15, 0, 650, 1050, 350, 390, graynhat, 0, 3);
	input[3] = new Input(str4, 1, "Gioi Tinh", 4, 0, 650, 1050, 420, 460, graynhat, 0, 3);
	input[4] = new Input(str5, 3, "So Dien Thoai", 11, 0, 650, 1050, 490, 530, graynhat, 0, 3);
	input[5] = new Input(str6, 3, "Nam Nhap Hoc", 5, 0, 650, 1050, 560, 600, graynhat, 0, 3);
	input[6]= new Input(str7, 2, "Ma Lop ", 15, 0, 650, 1050, 630, 670, graynhat, 0, 3);
	input[0]->draw();
	input[1]->draw();
	input[2]->draw();
	input[3]->draw();
	input[4]->draw();
	input[5]->draw();
	input[6]->draw();
	int x = -1;
	int y = -1;
	SinhVien SV;
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (650 <= x && x <= 1050 && 210 <= y && y <= 250 && check != 2) {
				input[0]->setCheck(true);
				input[1]->setCheck(false);
				input[2]->setCheck(false);
				input[3]->setCheck(false);
				input[4]->setCheck(false);
				input[5]->setCheck(false);
				input[6]->setCheck(false);
				input[0]->addChar();
				input[1]->draw();
				input[2]->draw();
				input[3]->draw();
				input[4]->draw();
				input[5]->draw();
				input[6]->draw();
			}
			else if (650 <= x && x <= 1050 && 280 <= y && y <= 320) {
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
			else if (650 <= x && x <= 1050 && 350 <= y && y <= 390) {
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
			else if (650 <= x && x <= 1050 && 420 <= y && y <= 460) {
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
			else if (650 <= x && x <= 1050 && 490 <= y && y <= 530) {
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
			else if (650 <= x && x <= 1050 && 560 <= y && y <= 600) {
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
			else if (650 <= x && x <= 1050 && 630 <= y && y <= 670) {
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
			else if (755 <= x && x <= 835 && 695 <= y && y <= 734) {
				if (check == 0) {
					if (input[0]->checkRong() == true && input[1]->checkRong() == true && input[2]->checkRong() == true && input[3]->checkRong() == true && input[4]->checkRong() == true && input[5]->checkRong() == true) {
						int tmp = MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN CO MUON LUU SINH VIEN"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
						);
						if (tmp == IDYES) {
							SV.setMaSV(string(input[0]->chuanHoa(input[0]->getContent())));
							SV.setHo(string(input[1]->chuanHoa(input[1]->getContent())));
							SV.setTen(string(input[2]->chuanHoa(input[2]->getContent())));
							SV.setSex(string(input[3]->chuanHoa(input[3]->getContent())));
							SV.setSdt(string(input[4]->chuanHoa(input[4]->getContent())));
							SV.setNamNhap(string(input[5]->chuanHoa(input[5]->getContent())));
							SV.setMaLop(string(input[6]->chuanHoa(input[6]->getContent())));
							themSV(SV, check);
							if (check == -1) {
								MessageBox(
									NULL,
									(LPCWSTR)convertCharArrayToLPCWSTR("MA SINH VIEN DA BI TRUNG "),
									(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
									MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
								);
								continue;
							}
							nhapSV("", "", "", "", "", "","", 0);
							break;
						}
					}
					else if (input[0]->checkRong() == false) {
						int tmp = MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN CO MUON DUNG THEM SINH VIEN"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
						);
						if (tmp == IDYES) {
							cleardevice();
							break;
						}
					}
					else {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("VUI LONG NHAP DAY DAU THONG TIN "),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);
						continue;
					}
				}
				else if (check == 2) {
					if (input[0]->checkRong() == true && input[1]->checkRong() == true && input[2]->checkRong() == true && input[3]->checkRong() == true && input[4]->checkRong() == true && input[5]->checkRong() == true) {

						int tmp = MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN CO MUON LUU CHINH SUA "),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
						);
						if (tmp == IDYES) {
							SV.setMaSV(string(input[0]->chuanHoa(input[0]->getContent())));
							SV.setHo(string(input[1]->chuanHoa(input[1]->getContent())));
							SV.setTen(string(input[2]->chuanHoa(input[2]->getContent())));
							SV.setSex(string(input[3]->chuanHoa(input[3]->getContent())));
							SV.setSdt(string(input[4]->chuanHoa(input[4]->getContent())));
							SV.setNamNhap(string(input[5]->chuanHoa(input[5]->getContent())));
							SV.setMaLop(string(input[6]->chuanHoa(input[6]->getContent())));
							themSV(SV, check);
							break;
						}

					}
				}
			}
			else if (1100 <= x && x <= 1140 && 125 <= y && y <= 165) {
				int tmp = MessageBox(
					NULL,
					(LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON HUY SUA SINH VIEN"),
					(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
					MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
				);
				if (tmp == IDYES) {

					break;
				}
			}
		}
	}
}

void DSSV::nhapLocSV(char* s, thaoTac& hDSV) {
	int x = -1, y = -1;

	int tmp = strlen(s);
	if (tmp > 0 && s[0] == ' ') {
		tmp = 0;
	}
	s[tmp + 1] = '\0';
	s[tmp] = '|';
	char c;
	setbkcolor(graynhat);
	settextstyle(10, 0, 1);
	setcolor(Den);
	while (kbhit()) c = getch();
	while (1) {
		delay(10);
		outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
				s[tmp] = '\0';

				hDSV = BACK;
				break;

			}
			else if (1390 <= x && x <= 1490 && 169 <= y && y <= 214) {
				s[tmp] = '\0';
				hDSV = THEM;

				break;
			}
			else if (563 <= x && x <= 630 && 169 <= y && y <= 205) {
				s[tmp] = '\0';

				hDSV = LOC;
				break;
			}
			else {
				s[tmp] = '\0';
				if (hDSV == LOC) break;
				hDSV = XUAT;
				break;
			}
		}
		else if (kbhit()) {
			c = getch();
			if (c == 8 && tmp > 0) {
				if (strlen(s) > 0) {
					s[tmp] = ' ';
					s[tmp + 1] = '\0';
					s[--tmp] = '|';
				}


			}
			else if (c != 8 && tmp < 50) {
				if (strlen(s) < 50) {
					s[tmp++] = c;
					s[tmp] = '\0';

				}

			}
		}

		else if (!kbhit()) {
			s[tmp] = '|';
			s[tmp + 1] = '\0';
			delay(100);
			outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
			s[tmp] = ' ';
			s[tmp + 1] = '\0';
			delay(100);
			outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
		}

	}
}

void DSSV::menuSV() {
	setfillstyle(SOLID_FILL, mauNen);
	bar(0, 0, 1525, 777);
	setbkcolor(Be);
	setfillstyle(SOLID_FILL, Be);
	bar(397, 20, 1173, 100);
	settextstyle(10, 0, 7);
	setcolor(Blue);
	outtextxy((397 + 1173) / 2 - textwidth(convertStringToChar("SINH VIEN")) / 2, (20 + 100) / 2 - textheight(convertStringToChar("SINH VIEN")) / 2, convertStringToChar("SINH VIEN"));
	vien(397, 1173, 20, 100);
	//tieuDeLopSV();
	buttonBack();
	buttonThem();


	setfillstyle(SOLID_FILL, BlueNhat);
	bar(40, 243, 1490, 744);
	vien(40, 1490, 243, 744);
	buttonTien();
	buttonLui();
	buttonLoc();
	buttonThoat();
}

void DSSV::menuSetSV(int& on) {
	menuSV();
	thaoTac hDSV = XUAT;
	int colorNen = BACKGROUND_COLOR;
	int colorText = 0;
	int x = -1; int y = -1;
	char s[100];
	s[0] = ' ';
	s[1] = '\0';
	int n = 0;
	int check = 0;

	/*xuatDSSV();*/
	NodeSV* tmp = getHeadSV();
	//while (tmp != NULL) {
	//	cout << tmp->getDataSV().getMaSV() << endl;
	//	tmp = tmp->getNextSV();
	//}
	//cout << soLuongSV();
	Input* input[1];
	input[0] = new Input("", 1, "TIM KIEM", 50, 0, 183, 559, 169, 205, graynhat, 0, 3);
	input[0]->draw();
	DSSV dssv;
	int tongSoSV = 0;

	if (hDSV != THEM) {

		locSV("", dssv, n);
		tongSoSV = soLuongSV();
	}

	bool ok = true;
	//xuatTrangDSSV(dssv, tongSoSV, hD, thaoTacRoi, s, on);
	while (ok) {
		switch (hDSV) {
		case XUAT: {
			cleardevice();
			menuSV();
			input[0]->draw();
			buttonTimKiem();
			locSV("", dssv, n);
			tongSoSV = soLuongSV();
			outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
			xuatTrangDSSV(dssv, tongSoSV, hDSV, s, on);

			break;
		}
		case LOC: {
			cleardevice();
			menuSV();
			input[0]->draw();
			buttonTimKiem();
			tongSoSV = soLuongSV();
			locSV(string(s), dssv, n);
			outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
			xuatTrangDSSV(dssv, n, hDSV, s, on);
			break;

		}
		case THEM: {
			menuThemSV();
			/*cout << "tao o them " << endl;*/
			nhapSV("", "", "", "", "", "","", 0);
			menuSV();
			input[0]->draw();
			buttonTimKiem();
			tongSoSV = soLuongSV();
			locSV("", dssv, n);
			outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
			xuatTrangDSSV(dssv, tongSoSV, hDSV, s, on);
			if (hDSV != BACK)  hDSV = XUAT;
			break;
		}
		case BACK: {
			/*for (NodeSV* p = this->headSV; p != NULL; p = p->getNextSV()) {
				dssv.themSV(p->getDataSV(), 0);
			}*/

			ok = false;
			dssv.freeSV(dssv.getHeadSV());
			return;
			break;
		}
		}

	}
}
