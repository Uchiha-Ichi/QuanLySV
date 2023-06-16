#pragma once
#include"UI.h"
#include "Convert.h"
class Input : public UI {
protected:
    // char id[2];
    char content[50];
    int type;
    char title[30];
    int maxChar;
    int textColor;
    bool check = false;
    int size;
public:
    Input(string content, int type, string title, int maxChar, int textColor, int left, int right, int top, int bottom, int backgroundColor, int borderColor, int size) :UI(left, right, top, bottom, backgroundColor, borderColor) {
        strcpy_s(this->content, content.size() + 1, content.c_str());
        this->type = type;
        strcpy_s(this->title, title.c_str());
        this->maxChar = maxChar;
        this->textColor = textColor;
        this->size = size;
    }
    void draw() {
        UI::draw();
        settextstyle(10, 0, size);
        setbkcolor(backgroundColor);
        setcolor(textColor);
        outtextxy(left - textwidth(title) - 2, (top + bottom - textheight(title)) / 2, title);
        outtextxy(left + 5, (top + bottom - textheight(content)) / 2, content);

    }
    void setCheck(bool check) {
        this->check = check;
    }
    bool getCheck() {
        return this->check;
    }
    wchar_t* convertCharArrayToLPCWSTR(const char* charArray)
    {
        wchar_t* wString = new wchar_t[4096];
        MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
        return wString;
    }
    char* getContent() {
        return this->content;
    }

    string getContentStr() {
        string ans(this->content);
        return ans;
    }

    float getContentFoat() {
        float Diem;
        float diem1, diem2;
        string diem = getContentStr();
        if (diem[0] == '.') {
            Diem = -1;
            return Diem;
        }

        if (diem.size() == 1) {
            Diem = atoi(getContent());
            return Diem;
        }
        else if (diem.size() == 2) {
            if (diem == "10") {
                Diem = atoi(getContent());
                return Diem;
            }
            Diem = -1;
            return Diem;
        }
        else if (diem.size() == 3) {
            if (diem[2] == '.' || diem[1] != '.') {
                Diem = -1;
                return Diem;
            }
            diem1 = (int)(diem[0]) - 48;
            diem2 = (int)(diem[2]) - 48;;
            Diem = diem1 + diem2 / 10;
            Diem = static_cast<float>(static_cast<int>(Diem * 10)) / 10;
            return Diem;

        }



    }

    char* chuanHoa(char* a) {
        if (strlen(a) == 0) {
            return a;
        }
        else {
            bool check = 0;
            char s[50];
            int tmp = 0;
            for (int i = 0; i < strlen(a); i++) {
                if (check == 1 || a[i] != ' ') {
                    s[tmp++] = a[i];
                }
                if (a[i] != ' ') check = 1;
                else check = 0;
            }
            s[tmp] = '\0';
            char* temp = new char[strlen(s) + 1];
            strcpy_s(temp, strlen(s) + 1, s);
            return temp;
        }
    }

    string chuanHoaStr(char* a) {
        if (a == nullptr)
            return "";

        string result(a);
        return result;
    }
    bool kiTu(char c) {
        if (48 <= c && c <= 57) return 1;
        else if (65 <= c && c <= 90) return 1;
        else if (97 <= c && c <= 122)return 1;
        else if (c == 32 || c == 45 || c == 46) return 1;
        else return false;
    }
    void addChar() {
        int tmp = strlen(content);
        if (tmp > 0 && content[0] == ' ') {
            tmp = 0;
        }
        content[tmp + 1] = '\0';
        content[tmp] = '|';
        char c;
        while (kbhit()) c = getch();
        while (1) {
            delay(10);
            outtextxy(left + 5, (top + bottom - textheight(content)) / 2, content);
            if (check = true) {
                if (kbhit()) {
                    c = getch();
                    if (this->type == 2) {
                        if (97 <= c && c <= 122) {
                            c = c - 32;
                        }
                    }
                    else if (this->type == 3) {
                        while (1) {
                            if ((97 <= c && c <= 122) || (65 <= c && c <= 90)) {
                                MessageBox(
                                    NULL,
                                    (LPCWSTR)convertCharArrayToLPCWSTR("VUI LONG NHAP SO"),
                                    (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                                    MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
                                );
                                c = getch();
                            }
                            else {
                                break;
                            }
                        }
                    }
                    else if (this->type == 4) {
                        while (1) {
                            if ((97 <= c && c <= 122) || (65 <= c && c <= 90) || c == 32 || c == 45) {

                                c = getch();
                            }
                            else {
                                break;
                            }
                        }
                    }
                    if (c == 8 && tmp > 0) {
                        if (strlen(content) > 0) {
                            content[tmp] = ' ';
                            content[tmp + 1] = '\0';
                            content[--tmp] = '|';
                        }
                    }
                    else if (kiTu(c) == 1 && tmp < this->maxChar && this->check == true) { // type != 4&&
                        if (strlen(content) < 50) {
                            content[tmp++] = c;
                            content[tmp] = '\0';
                        }
                    }
                }

                else if (!kbhit()) {
                    content[tmp] = '|';
                    content[tmp + 1] = '\0';
                    delay(100);
                    outtextxy(left + 5, (top + bottom - textheight(content)) / 2, content);
                    content[tmp] = ' ';
                    content[tmp + 1] = '\0';
                    delay(100);
                    outtextxy(left + 5, (top + bottom - textheight(content)) / 2, content);
                }
            }


            if (ismouseclick(WM_LBUTTONDOWN)) {
                content[tmp] = '\0';
                break;
            }
        }
    }
    bool checkRong() {
        return (strlen(content) != 0);
    }
};
