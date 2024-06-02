#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

// Function Prototypes
void drawLandingPage();
void drawLoginForm();
void loginButtonClick();
void getTextInput(char* input, int maxLength, int left, int top);
bool isClickInBounds(int x, int y, int left, int top, int right, int bottom);

// Constants for input boxes
#define USERNAME_BOX_LEFT 250
#define USERNAME_BOX_TOP 115
#define USERNAME_BOX_RIGHT 350
#define USERNAME_BOX_BOTTOM 135

#define PASSWORD_BOX_LEFT 250
#define PASSWORD_BOX_TOP 165
#define PASSWORD_BOX_RIGHT 350
#define PASSWORD_BOX_BOTTOM 185

const char *img = "Graffiti_.bmp";

enum Page { LANDING, LOGIN_USER, LOGIN_ADMIN };

Page currentPage = LANDING;

void drawLandingPage() {
    setfillstyle(LTSLASH_FILL, LIGHTMAGENTA);
    bar(0, 0, getmaxx(), getmaxy());

    readimagefile(img, 10, 11, 10, 10);

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(100, 50, "Gym Management & Fitness Suggestion System");

    settextstyle(2, HORIZ_DIR, 4.5);
    rectangle(150, 200, 450, 250);
    outtextxy(250, 210, "User");

    rectangle(150, 300, 450, 350);
    outtextxy(250, 310, "Admin");

    rectangle(200, 400, 400, 430);
    outtextxy(280, 410, "Exit");
}

void drawLoginForm() {
    setfillstyle(SOLID_FILL, RED);
    bar(0, 0, getmaxx(), getmaxy());

    setcolor(WHITE);
    rectangle(100, 100, 400, 300); // Main form border
    outtextxy(150, 120, "Username:");
    rectangle(USERNAME_BOX_LEFT, USERNAME_BOX_TOP, USERNAME_BOX_RIGHT, USERNAME_BOX_BOTTOM); // Username input box
    outtextxy(150, 170, "Password:");
    rectangle(PASSWORD_BOX_LEFT, PASSWORD_BOX_TOP, PASSWORD_BOX_RIGHT, PASSWORD_BOX_BOTTOM); // Password input box
    rectangle(200, 230, 300, 260); // Login button
    outtextxy(225, 240, "Login");
}

void loginButtonClick() {
    cleardevice();
    outtextxy(200, 200, "Login Successful!");
}

bool isClickInBounds(int x, int y, int left, int top, int right, int bottom) {
    return (x >= left && x <= right && y >= top && y <= bottom);
}

void getTextInput(char* input, int maxLength, int left, int top) {
    int len = 0;
    char ch;
    while (true) {
        ch = getch();
        if (ch == 13) { // Enter key
            input[len] = '\0';
            break;
        } else if (ch == 8) { // Backspace key
            if (len > 0) {
                len--;
                input[len] = '\0';
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                bar(left, top, left + 100, top + 20);
                outtextxy(left, top, input);
            }
        } else if (len < maxLength - 1) {
            input[len] = ch;
            len++;
            input[len] = '\0';
            outtextxy(left, top, input);
        }
    }
}

void handleLandingPageClick(int x, int y) {
    if (isClickInBounds(x, y, 150, 200, 450, 250)) {
        currentPage = LOGIN_USER;
        cleardevice();
        drawLoginForm();
    } else if (isClickInBounds(x, y, 150, 300, 450, 350)) {
        currentPage = LOGIN_ADMIN;
        cleardevice();
        drawLoginForm();
    } else if (isClickInBounds(x, y, 200, 400, 400, 430)) {
        closegraph();
        exit(0);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    initwindow(1280, 720, "Landing Page");

    char username[20] = "";
    char password[20] = "";
    bool usernameActive = false;
    bool passwordActive = false;

    drawLandingPage();

    int x, y;
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);

            if (currentPage == LANDING) {
                handleLandingPageClick(x, y);
            } else if (currentPage == LOGIN_USER || currentPage == LOGIN_ADMIN) {
                // Check if the click is within the username input box
                if (isClickInBounds(x, y, USERNAME_BOX_LEFT, USERNAME_BOX_TOP, USERNAME_BOX_RIGHT, USERNAME_BOX_BOTTOM)) {
                    usernameActive = true;
                    passwordActive = false;
                    setfillstyle(SOLID_FILL, LIGHTGRAY);
                    bar(USERNAME_BOX_LEFT + 1, USERNAME_BOX_TOP + 1, USERNAME_BOX_RIGHT - 1, USERNAME_BOX_BOTTOM - 1);
                    outtextxy(USERNAME_BOX_LEFT + 5, USERNAME_BOX_TOP + 5, username);
                }
                // Check if the click is within the password input box
                else if (isClickInBounds(x, y, PASSWORD_BOX_LEFT, PASSWORD_BOX_TOP, PASSWORD_BOX_RIGHT, PASSWORD_BOX_BOTTOM)) {
                    usernameActive = false;
                    passwordActive = true;
                    setfillstyle(SOLID_FILL, LIGHTGRAY);
                    bar(PASSWORD_BOX_LEFT + 1, PASSWORD_BOX_TOP + 1, PASSWORD_BOX_RIGHT - 1, PASSWORD_BOX_BOTTOM - 1);
                    outtextxy(PASSWORD_BOX_LEFT + 5, PASSWORD_BOX_TOP + 5, password);
                }
                // Check if the click is within the login button bounds
                else if (isClickInBounds(x, y, 200, 230, 300, 260)) {
                    loginButtonClick();
                    delay(2000);
                    break;
                }
            }
        }

        if (usernameActive) {
            getTextInput(username, 20, USERNAME_BOX_LEFT + 5, USERNAME_BOX_TOP + 5);
            usernameActive = false;
        }
        if (passwordActive) {
            getTextInput(password, 20, PASSWORD_BOX_LEFT + 5, PASSWORD_BOX_TOP + 5);
            passwordActive = false;
        }
    }

    closegraph();
    return 0;
}
