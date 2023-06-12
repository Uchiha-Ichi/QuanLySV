#include"Const.h"
#include"Menu.h"

void screen() {
    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test UI");

}



void closeScreen() {

    closegraph();
}
int main() {

    screen();

    menuFirstSet();

    closeScreen();

    return 0;
}