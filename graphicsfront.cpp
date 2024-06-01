#include <graphics.h>
#include <conio.h>
#include <dos.h>

// Function to draw the login form
void drawLoginForm() {
    setcolor(WHITE);
    rectangle(100, 100, 400, 300); // Main form border
    outtextxy(150, 120, "Username:");
    rectangle(250, 115, 350, 135); // Username input box
    outtextxy(150, 170, "Password:");
    rectangle(250, 165, 350, 185); // Password input box
    rectangle(200, 230, 300, 260); // Login button
    outtextxy(225, 240, "Login");
}

// Function to handle login button click
void loginButtonClick() {
    cleardevice();
    outtextxy(200, 200, "Login Successful!");
}

// Function to check if click is within the button bounds
bool isClickInBounds(int x, int y, int left, int top, int right, int bottom) {
    return (x >= left && x <= right && y >= top && y <= bottom);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    drawLoginForm();

    int x, y;
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            
            // Check if the click is within the login button bounds
            if (isClickInBounds(x, y, 200, 230, 300, 260)) {
                loginButtonClick();
                delay(2000);
                break;
            }
        }
    }

    closegraph();
    return 0;
}
