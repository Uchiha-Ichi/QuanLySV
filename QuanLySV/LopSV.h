//#pragma once
//#include"Const.h"
//#include"SV.h"
//
//
//// ==============================================================================================================================================================
//class Lop {
//private:
//	char maLop[MAX_LOPSV];
//	DSSV ds;
//public:
//	Lop();
//	Lop(const char* maLop);
//	Lop(const char* maLop, DSSV ds);
//	void setMaLop(const char* maLop);
//	char* getMaLop();
//	void setDSSV(DSSV ds);
//	DSSV& getDSSV();
//};
//class NodeLop {
//private:
//	Lop dataLop;
//	NodeLop* nextLH;
//public:
//	NodeLop();
//	NodeLop(Lop dataLop);
//	void setDataLop(Lop dataLop);
//	Lop& getDataLop();
//	void setNextLH(NodeLop* nextLH);
//	NodeLop*& getNextLH();
//	void setNodeLop(NodeLop* lop);
//	NodeLop* getNodeLop();
//};
//class DSLH {
//private:
//	NodeLop* headLH;
//public:
//	DSLH();
//	void setHeadLH(NodeLop* headLH);
//	NodeLop*& getHeadLH();
//	void freeDSLH(NodeLop*& node);
//	void themVaoDau(Lop lop);
//	int viTriThem(char* maLop);
//	void themLH(Lop lop);
//	int xoaLH(string ma);
//	int soLuongLSV(NodeLop* tmp);
//	void locMaLH(string key, DSLH& ds, int& n);
//	void timLSV(string maLop, NodeLop*& tmp);
//	void vietDSSV();
//	void vietLH(Lop LopSV, ofstream& fileOut);
//	NodeSV* timDataSinhVien(string sv);
//	void vietDSLH();
//	void xuatDSSV();
//	void xuatDSLH();
//	void xuat1TrangDSL(NodeLop* headLop, int batDau, int ketThuc, Table newTable);
//	void xuatTrangDSLH(int tongSoDong, thaoTac& hD, char* s, int& on, thaoTac& hDSV);
//	void nhapLH();
//	void menuSetLop(int& on);
//	void checkTimSV();
//};
//
//// class lop
//Lop::Lop() {
//	strcpy_s(this->maLop, 1, "");
//	ds.setHeadSV(NULL);
//}
//Lop::Lop(const char* maLop) {
//	strcpy_s(this->maLop, strlen(maLop) + 1, maLop);
//	this->ds.setHeadSV(NULL);
//}
//Lop::Lop(const char* maLop, DSSV ds) {
//	strcpy_s(this->maLop, strlen(maLop) + 1, maLop);
//	this->ds.setHeadSV(ds.getHeadSV());
//}
//void Lop::setMaLop(const char* maLop) {
//	strcpy_s(this->maLop, strlen(maLop) + 1, maLop);
//}
//char* Lop::getMaLop() {
//	return this->maLop;
//}
//void Lop::setDSSV(DSSV ds) {
//	this->ds.setHeadSV(ds.getHeadSV());
//}
//DSSV& Lop::getDSSV() {
//	return this->ds;
//}
//// class NodeLop
//
//NodeLop::NodeLop() {
//	this->nextLH = NULL;
//}
//NodeLop::NodeLop(Lop dataLop) {
//	this->dataLop = dataLop;
//	this->nextLH = NULL;
//}
//void NodeLop::setDataLop(Lop dataLop) {
//	this->dataLop = dataLop;
//}
//Lop& NodeLop::getDataLop() {
//	return this->dataLop;
//}
//void NodeLop::setNextLH(NodeLop* nextLH) {
//	this->nextLH = nextLH;
//}
//NodeLop*& NodeLop::getNextLH() {
//	return this->nextLH;
//}
//void NodeLop::setNodeLop(NodeLop* lop) {
//	this->dataLop = lop->dataLop;
//	this->nextLH = lop->nextLH;
//}
//NodeLop* NodeLop::getNodeLop() {
//	return this;
//}
//// class danh sach lop hoc
//
//DSLH::DSLH() {
//	this->headLH = NULL;
//}
//void DSLH::setHeadLH(NodeLop* head) {
//	this->headLH = head;
//}
//NodeLop*& DSLH::getHeadLH() {
//	return this->headLH;
//}
//void DSLH::freeDSLH(NodeLop*& lop) {
//	NodeLop* temp = NULL;
//
//	while (lop != NULL) {
//		temp = lop;
//		temp->getDataLop().getDSSV().freeSV(temp->getDataLop().getDSSV().getHeadSV());
//		lop = lop->getNextLH();
//		delete temp;
//	}
//}
//void DSLH::themVaoDau(Lop lop) {
//	NodeLop* tmp = new NodeLop();
//	tmp->setDataLop(lop);
//	tmp->setNextLH(this->headLH);
//	this->headLH = tmp->getNodeLop();
//}
//int DSLH::viTriThem(char* maLop) {
//	int i = 1;
//	NodeLop* tmp = this->headLH;
//	while (tmp != NULL) {
//		if (strcmp(tmp->getDataLop().getMaLop(), maLop) > 0) {
//			return i;
//		}
//		if (strcmp(tmp->getDataLop().getMaLop(), maLop) == 0) {
//			i = 0;
//			return i;
//		}
//		i++;
//
//		tmp = tmp->getNextLH();
//	}
//	return i;
//}
//void DSLH::themLH(Lop lop) {
//	int viTri = this->viTriThem(convertStringToChar(lop.getMaLop()));
//	if (viTri == 0) return;
//	if (headLH == NULL || viTri == 1) {
//		themVaoDau(lop);
//		return;
//	}
//	NodeLop* tmp = getHeadLH();
//	for (int i = 1; i < viTri - 1; i++) {
//		tmp = tmp->getNextLH();
//	}
//	NodeLop* temp = new NodeLop();
//	temp->setDataLop(lop);
//	temp->setNextLH(tmp->getNextLH());
//	tmp->setNextLH(temp);
//}
//int DSLH::xoaLH(string ma) {
//	if (this->headLH == NULL) return -1;
//	NodeLop* tmp = headLH;
//	int n = tmp->getDataLop().getDSSV().soLuongSV();
//	if (strcmp(tmp->getDataLop().getMaLop(), convertStringToChar(ma)) == 0) {
//		if (n == 0) {
//			headLH = tmp->getNextLH();
//			tmp->setNextLH(NULL);
//			delete tmp;
//			return 1;
//		}
//		else  return -1;
//	}
//	while (tmp->getNextLH() != NULL && strcmp(tmp->getNextLH()->getDataLop().getMaLop(), convertStringToChar(ma)) != 0) {
//		tmp = tmp->getNextLH();
//	}
//	n = tmp->getNextLH()->getDataLop().getDSSV().soLuongSV();
//	if (strcmp(tmp->getNextLH()->getDataLop().getMaLop(), convertStringToChar(ma)) == 0) {
//		if (n == 0) {
//			NodeLop* temp = tmp->getNextLH();
//			tmp->setNextLH(temp->getNextLH());
//			temp->setNextLH(NULL);
//			delete temp;
//			return 1;
//		}
//		else return -1;
//	}
//
//}
//int DSLH::soLuongLSV(NodeLop* tmp) {
//	int soLuong = 0;
//	while (tmp != NULL) {
//		++soLuong;
//		tmp = tmp->getNextLH();
//	}
//	return soLuong;
//}
////void DSLH::locMaLH(string key, DSLH& ds, int& n) {
////	ds.freeDSLH(ds.getHeadLH());//ds này là ds mới giống ds gốcx`
////	ds.setHeadLH(NULL);
////	NodeLop* tmp = this->headLH;//lấy head từ ds hiện tại 
////	n = 0;
////	if (key == " ") {
////		while (tmp != NULL) {
////			NodeLop* LH = new NodeLop(tmp->getDataLop());
////			ds.	(LH->getDataLop());
////			n++;
////			tmp = tmp->getNextLH();
////		}
////	}
////	else {
////		while (tmp != NULL) {
////			if (string(tmp->getDataLop().getMaLop()).find(key) != string::npos) {
////				NodeLop* LH = new NodeLop(tmp->getDataLop());
////				ds.themLH(LH->getDataLop());
////				n++;
////			}
////			tmp = tmp->getNextLH();
////		}
////	}
////}
//void DSLH::timLSV(string maLop, NodeLop*& tmp) {
//	tmp = getHeadLH();
//	while (tmp != NULL) {
//		if (strcmp(tmp->getDataLop().getMaLop(), convertStringToChar(maLop)) == 0) break;
//		tmp = tmp->getNextLH();
//	}
//}
//void DSLH::vietDSSV() {
//	ofstream fileOut(dataSV.c_str(), ios::trunc);
//	if (fileOut.is_open()) {
//		NodeLop* tmp = headLH;
//		while (tmp != NULL) {
//			if (tmp->getDataLop().getDSSV().checkRong() != true) {
//				for (NodeSV* SV = tmp->getDataLop().getDSSV().getHeadSV(); SV != NULL; SV = SV->getNextSV()) {
//					SV->vietSV(SV->getDataSV(), fileOut);
//				}
//			}
//			tmp = tmp->getNextLH();
//		}
//	}
//}
//void DSLH::vietLH(Lop LopSV, ofstream& fileOut) {
//	char temp = ',';
//	fileOut << LopSV.getMaLop();
//	fileOut << "\n";
//}
//void DSLH::vietDSLH() {
//	ofstream fileOut;
//	fileOut.open(dataLSV.c_str(), ios::trunc);
//	if (fileOut.is_open()) {
//		for (NodeLop* tmp = headLH; tmp != NULL; tmp = tmp->getNextLH()) {
//			vietLH(tmp->getDataLop(), fileOut);
//		}
//
//	}
//	fileOut.close();
//}
//void DSLH::xuatDSSV() {
//	ifstream fileIn; char temp; string tempStr;
//	fileIn.open(dataSV.c_str(), ios::in);
//	if (fileIn.is_open())
//	{
//		//if(DSSV.pHead==NULL)
//		while (!fileIn.eof())
//		{
//			SinhVien data;
//
//			getline(fileIn, tempStr, ',');
//			if (tempStr == "") break;
//			data.setMaSV(tempStr.c_str());
//			getline(fileIn, tempStr, ',');
//			data.setHo(tempStr.c_str());
//			getline(fileIn, tempStr, ',');
//			data.setTen(tempStr.c_str());
//			getline(fileIn, tempStr, ',');
//			data.setSex(tempStr.c_str());
//			getline(fileIn, tempStr, ',');
//			data.setSdt(tempStr.c_str());
//			getline(fileIn, tempStr, ',');
//			data.setNamNhap(tempStr.c_str());
//			getline(fileIn, tempStr, '\n');
//			data.setMaLop(tempStr.c_str());
//			NodeSV* SV = new NodeSV(data);
//
//			NodeLop* tmp = getHeadLH();
//
//			timLSV(tempStr, tmp);
//			if (tmp != NULL) {
//				int check = 0;
//				tmp->getDataLop().getDSSV().themSV(SV->getDataSV(), check);
//			}
//			if (fileIn.eof()) break;
//
//		}
//	}
//	fileIn.close();
//}
//void DSLH::xuatDSLH() {
//
//	ifstream fileIn; char temp;
//	fileIn.open(dataLSV.c_str(), ios::in);
//	if (fileIn.is_open()) {
//		string str;
//		while (!fileIn.eof()) {
//
//			getline(fileIn, str, '\n');
//			if (str == "") break;
//			Lop lop(str.c_str());
//			themLH(lop);
//			if (fileIn.eof()) break;
//		}
//	}
//	fileIn.close();
//}
//NodeSV* DSLH::timDataSinhVien(string sv) {
//	for (NodeLop* temp = getHeadLH(); temp != NULL; temp = temp->getNextLH()) {
//		if (temp->getDataLop().getDSSV().soLuongSV() > 0) {
//			NodeSV* tmp = temp->getDataLop().getDSSV().timSV(sv);
//			if (tmp != NULL) return tmp;
//		}
//	}
//	return NULL;
//}
//void DSLH::xuat1TrangDSL(NodeLop* headLop, int batDau, int ketThuc, Table Bang) {
//	int soDong = ketThuc % maxDong;
//	if (soDong == 0) soDong = maxDong;
//	if (ketThuc == 0 && batDau == 0) soDong = maxDong;
//	else {
//		int soDongTrong = maxDong - ketThuc % maxDong;
//		soDong = ketThuc % maxDong == 0 ? ketThuc : ketThuc + soDongTrong;
//	}
//	char* STT = convertIntToChar(0);
//
//	for (int i = 0; i < batDau; i++) {
//		headLop = headLop->getNextLH();
//	}
//	int x = tableLeft;
//	int y = tableTop + kcY / 2 - textheight(STT) / 2;
//	setbkcolor(BlueNhat); setcolor(Den); settextstyle(10, 0, 1);
//	for (int i = batDau; i < soDong; i++) {
//		y += kcY;
//		if (i >= ketThuc) {
//			setbkcolor(BlueNhat); setcolor(Den); settextstyle(10, 0, 1);
//			x = tableLeft;
//			STT = convertIntToChar(i + 1);
//			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
//			x += Bang.getCols(0)->getChieuRong();
//
//			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
//
//			x += Bang.getCols(1)->getChieuRong();
//			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
//
//			x += Bang.getCols(2)->getChieuRong();
//
//			continue;
//		}
//
//		x = tableLeft;
//		//STT
//		STT = convertIntToChar(i + 1);
//		//Xoa STT cu
//		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
//		//Xuat STT moi
//		outtextxy(x + (Bang.getCols(0)->getChieuRong() / 2 - textwidth(STT) / 2), y, STT);
//		x += Bang.getCols(0)->getChieuRong();
//		// MaLop
//		// Xoa maLop cu
//		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
//		// Xuat maLop moi
//		outtextxy(x + (Bang.getCols(1)->getChieuRong() / 2 - textwidth(headLop->getDataLop().getMaLop()) / 2), y, headLop->getDataLop().getMaLop());
//		x += Bang.getCols(1)->getChieuRong();
//		// SoSV
//		// Xoa SoSV cu
//		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
//		// Xuat SoSV moi
//		outtextxy(x + (Bang.getCols(2)->getChieuRong() / 2 - textwidth(convertIntToChar(headLop->getDataLop().getDSSV().soLuongSV())) / 2), y, convertIntToChar(headLop->getDataLop().getDSSV().soLuongSV()));
//		x = tableLeft;
//
//		//clearmouseclick(WM_LBUTTONDOWN);
//		headLop = headLop->getNextLH();
//	}
//
//}
//void DSLH::xuatTrangDSLH(int tongSoDong, thaoTac& hD, char* s, int& on, thaoTac& hDSV) {
//	int x = -1, y = -1;
//	int batDau = 0;
//	int ketThuc = (tongSoDong >= maxDong) ? maxDong : tongSoDong;
//	Table newTable = table_Lop();
//	newTable.drawTable(maxDong);
//	int trangHienTai = 1;
//	int tongSoTrang = ((tongSoDong - 1) / maxDong) + 1;
//	string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
//	settextstyle(10, 0, 1);
//	setbkcolor(BlueNhat); setcolor(Den);
//	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
//	bool ok = true;
//	xuat1TrangDSL(getHeadLH(), batDau, ketThuc, newTable);
//	NodeLop* temp = getHeadLH();
//	int h = 0;
//	while (ok) {
//		//xuat1TrangDSL(ds.getHeadLH(), batDau, ketThuc, newTable);
//		if (ismouseclick(WM_RBUTTONDOWN)) {
//			getmouseclick(WM_RBUTTONDOWN, x, y);
//			clearmouseclick(WM_RBUTTONDOWN);
//			if (tableLeft <= x && x <= tableRightLop && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
//
//				int tmp = MessageBox(
//					NULL,
//					(LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON XOA MON LOP"),
//					(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
//					MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
//				);
//				if (tmp == IDYES) {
//					for (int i = 0; i < ((y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong); i++) {
//						temp = temp->getNextLH();
//					}
//					h = this->xoaLH(string(temp->getDataLop().getMaLop()));
//					if (h == -1) {
//						MessageBox(
//							NULL,
//							(LPCWSTR)convertCharArrayToLPCWSTR("KHONG THE XOA LOP HOC DA MO"),
//							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
//							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
//						);
//						continue;
//					}
//					else if (h == 1) {
//						//vietDSLH();
//						cleardevice();
//						break;
//					}
//				}
//			}
//		}
//		else if (ismouseclick(WM_LBUTTONDOWN)) {
//			getmouseclick(WM_LBUTTONDOWN, x, y);
//			clearmouseclick(WM_LBUTTONDOWN);
//
//			if (tableLeft <= x && x <= tableRightLop && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
//				temp = getHeadLH();
//				for (int i = 0; i < ((y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong); i++) {
//					temp = temp->getNextLH();
//				}
//
//				if (temp->getDataLop().getDSSV().soLuongSV() == 0) {
//					int yess = MessageBox(
//						NULL,
//						(LPCWSTR)convertCharArrayToLPCWSTR("LOP CHUA CO SINH VIEN NAO "),
//						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
//						MB_ICONERROR | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
//					);
//					if (yess == IDYES) {
//						cleardevice();
//						temp->getDataLop().getDSSV().setHeadSV(NULL);
//						hDSV = THEM;
//						temp->getDataLop().getDSSV().menuSetSV(on, hDSV, string(temp->getDataLop().getMaLop()));
//						hDSV = XUAT;
//						//vietDSSV();
//						if (on == 0) hD = BACK;
//					}
//					break;
//				}
//				cleardevice();
//				hDSV = XUAT;
//				temp->getDataLop().getDSSV().getHeadSV()->getDataSV().setMaLop((const char*)temp->getDataLop().getMaLop());
//				temp->getDataLop().getDSSV().menuSetSV(on, hDSV, string(temp->getDataLop().getMaLop()));
//				hDSV = XUAT;
//				//vietDSSV();
//				if (on == 0) hD = BACK;
//				break;
//			}
//			else if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {
//				batDau = batDau - maxDong;
//				ketThuc = batDau + maxDong;
//				trangHienTai--;
//				xuat1TrangDSL(getHeadLH(), batDau, ketThuc, newTable);
//				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
//				settextstyle(10, 0, 1);
//				setbkcolor(BlueNhat); setcolor(Den);
//				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
//			}
//			else if ((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang) {
//
//				batDau = batDau + maxDong;
//				ketThuc = (ketThuc + maxDong > tongSoDong) ? tongSoDong : ketThuc + maxDong;
//				trangHienTai++;
//				xuat1TrangDSL(getHeadLH(), batDau, ketThuc, newTable);
//				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
//				settextstyle(10, 0, 1);
//				setbkcolor(BlueNhat); setcolor(Den);
//				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
//			}
//			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
//				hD = BACK;
//
//				break;
//			}
//			else if (1390 <= x && x <= 1490 && 169 <= y && y <= 214) {
//				hD = THEM;
//
//				break;
//			}
//			//else if (563 <= x && x <= 630 && 169 <= y && y <= 205) {
//			//	hD = LOC;
//			//	t = 1;
//			//	break;
//			//}
//			//else if (183 <= x && x <= 559 && 169 <= y && y <= 205) {
//			//	/*nhapLocLH(s, hD, t);*/// nhập dự liệu lọc vào ô để lấy ra string để ném vào hàm locSV t
//			//	break;
//			//}
//			else if (1400 <= x && x <= 1490 && 10 <= y && y <= 60) {
//				on = 0;
//				hD = BACK;
//				break;
//			}
//		}
//	}
//	newTable.freeTable();
//}
//
//
//
//
//
//void DSLH::nhapLH() {
//	Input* input[1];
//	input[0] = new Input("", 2, "Ma Mon Hoc", 15, 0, 667, 1101, 240, 295, graynhat, 0, 4);
//	int x = -1; int y = -1;
//	input[0]->draw();
//	while (1) {
//		if (ismouseclick(WM_LBUTTONDOWN)) {
//			getmouseclick(WM_LBUTTONDOWN, x, y);
//			clearmouseclick(WM_LBUTTONDOWN);
//			if (667 <= x && x <= 1101 && 240 <= y && y <= 295) {
//				input[0]->setCheck(true);
//				input[0]->addChar();
//			}
//			else if (417 <= x && x <= 512 && 709 <= y && y <= 748) {
//				int tmp = MessageBox(
//					NULL,
//					(LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON HUY THEM LOP"),
//					(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
//					MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
//				);
//				if (tmp == IDYES) {
//					cleardevice();
//					break;
//				}
//			}
//			else if (1057 <= x && x <= 1151 && 709 <= y && y <= 748) {
//				if (input[0]->checkRong() == true) {
//					if (viTriThem(input[0]->chuanHoa(input[0]->getContent())) == 0) {
//						MessageBox(
//							NULL,
//							(LPCWSTR)convertCharArrayToLPCWSTR("LOP DA TON TAI "),
//							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
//							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
//						);
//						continue;
//					}
//
//					int tmp = MessageBox(
//						NULL,
//						(LPCWSTR)convertCharArrayToLPCWSTR("BAN CO MUON LUU LOP"),
//						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
//						MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
//					);
//					if (tmp == IDYES) {
//						/*xuatDSLH();
//						xuatDSSV();*/
//						Lop lop(string(input[0]->chuanHoa(input[0]->getContent())).c_str());
//						themLH(lop);
//						//vietDSLH();
//						cleardevice();
//						break;
//					}
//				}
//				else {
//					MessageBox(
//						NULL,
//						(LPCWSTR)convertCharArrayToLPCWSTR("VUI LONG NHAP DAY DU THONG TIN "),
//						(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
//						MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
//					);
//					continue;
//				}
//			}
//
//		}
//	}
//}
//
//void menuLop() {
//	setfillstyle(SOLID_FILL, mauNen);
//	bar(0, 0, 1525, 777);
//	tieuDeLopSV();
//	buttonBack();
//	buttonThem();
//
//
//	setfillstyle(SOLID_FILL, BlueNhat);
//	bar(40, 243, 1490, 744);
//	vien(40, 1490, 243, 744);
//	buttonTien();
//	buttonLui();
//	//buttonLoc();
//	buttonThoat();
//}
//
//
//
//
//// ck để check xem đã thực hiện thao tác trên SV chưa nếu 
//void DSLH::menuSetLop(int& on) {
//	menuLop();
//	int x = -1; int y = -1;
//	int n = 0;
//	char s[100];
//	s[0] = ' ';
//	s[1] = '\0';
//	/*Input* input[1];
//	input[0] = new Input("", 1, "TIM KIEM", 50, 0, 183, 559, 169, 205, graynhat, 0, 3);
//	input[0]->draw();
//	vien(183, 559, 169, 205);*/
//	xuatDSLH();
//	xuatDSSV();
//	int tongSoDong = soLuongLSV(getHeadLH());
//	thaoTac hD = XUAT;
//	thaoTac hDSV = XUAT;
//	bool ok = true;
//
//	while (ok) {
//		//delay(200);
//		switch (hD) {
//		case XUAT: {
//			cleardevice();
//			menuLop();
//			/*input[0]->draw();
//			buttonTimKiem();*/
//			/*vien(183, 559, 169, 205);*/
//			n = 0;
//			tongSoDong = soLuongLSV(getHeadLH());
//			/*outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);*/
//			xuatTrangDSLH(tongSoDong, hD, s, on, hDSV);
//			break;
//		}
//				 //case LOC: {
//				 //	cleardevice();
//				 //	menuLop();
//				 //	//input[0]->draw();
//				 //	//buttonTimKiem();
//				 //	ds.freeDSLH(ds.getHeadLH());
//				 //	for (NodeLop* p = this->headLH; p != NULL; p = p->getNextLH()) {
//				 //		ds.themLH(p->getDataLop());
//				 //	}
//				 //	int tongSoDong = soLuongLSV(getHeadLH());
//				 //	locMaLH(string(s), ds, n);
//				 //	outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
//				 //	xuatTrangDSLH(ds, n, hD, thaoTacRoi, s, on);
//				 //	break;
//
//				 //}
//		case THEM: {
//			menuThemLop();
//			nhapLH();
//			cleardevice();
//			menuLop();
//			//input[0]->draw();
//			//buttonTimKiem();
//			int tongSoDong = soLuongLSV(getHeadLH());
//			xuatTrangDSLH(tongSoDong, hD, s, on, hDSV);
//
//			if (hD != BACK)  hD = XUAT;
//			break;
//		}
//		case BACK: {
//			cleardevice();
//			/*for (NodeSV* p = this->headSV; p != NULL; p = p->getNextSV()) {
//				dssv.themSV(p->getDataSV(), 0);
//			}*/
//			ok = false;
//			vietDSSV();
//			vietDSLH();
//			freeDSLH(getHeadLH());
//			return;
//			break;
//		}
//		}
//
//	}
//}
