#ifndef CAPTUREINPUTS
#define CAPTUREINPUTS

#include <iostream>
#include <string>
#include <stdexcept>
#include <graphics.h>

template <typename T>
std::string to_string(const T& value) 
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

int stringToInt(const std::string& str) {
    int result = 0;
    bool isNegative = false;
    std::size_t startIndex = 0;

    if (str.empty()) {
        throw std::invalid_argument("Empty string cannot be converted to an integer");
    }

    // Check for a negative sign at the beginning of the string
    if (str[0] == '-') {
        isNegative = true;
        startIndex = 1;
    }

    for (std::size_t i = startIndex; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            throw std::invalid_argument("String contains non-numeric characters");
        }

        result = result * 10 + (str[i] - '0');
    }

    return isNegative ? -result : result;
}




void captureMemberNumber(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box
    
    setbkcolor(WHITE);
    setcolor(BLACK); // Change the text color   
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Change the text style and size

    while (true) {
        // Draw the input box
        //rectangle(left, top, right, bottom);

        // Display the current input text
        outtextxy(x, y, (char*)inputText.c_str());

        // Get a character from the user
        ch = getch();

        // If Enter key is pressed and input is up to 3 digits, break the loop
        if (ch == 13 && inputText.length() <= 3) {
            break;
        }

        // If Backspace key is pressed, remove the last character
        if (ch == 8 && !inputText.empty()) {
            inputText.erase(inputText.size() - 1);  // Use erase method instead of pop_back
        } else if (isdigit(ch) && inputText.length() < 3) {
            // Append the digit to the input text
            inputText.push_back(ch);
        }

        // Clear the previous text display area
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(left + 1, top + 1, right - 1, bottom - 1);

        // Redraw the input box with the updated text
        outtextxy(x, y, (char*)inputText.c_str());
    }
}

//****************************************************************************

void captureContactInput(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box
    
    setbkcolor(WHITE);
    setcolor(BLACK); // Change the text color
    
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Change the text style and size

    while (true) {
        // Draw the input box
        //rectangle(left, top, right, bottom);

        // Display the current input text
        outtextxy(x, y, (char*)inputText.c_str());

        // Get a character from the user
        ch = getch();

        // If Enter key is pressed and input is up to 10 digits, break the loop
        if (ch == 13 && inputText.length() <= 10) {
            break;
        }

        // If Backspace key is pressed, remove the last character
        if (ch == 8 && !inputText.empty()) {
            inputText.erase(inputText.size() - 1);  // Use erase method instead of pop_back
        } else if (isdigit(ch) && inputText.length() < 10) {
            // Append the digit to the input text
            inputText.push_back(ch);
        }

        // Clear the previous text display area
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(left + 1, top + 1, right - 1, bottom - 1);

        // Redraw the input box with the updated text
        outtextxy(x, y, (char*)inputText.c_str());
    }
}

//********************************************************************************************************************


void captureTextInput(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box
    
    setcolor(WHITE); // Change the text color
    
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Change the text style and size

    while (true) {
    // Draw the input box
    //rectangle(240, 340, 480, 380);
        
        // Display the current input text
        outtextxy(x, y, (char*)inputText.c_str());

        // Get a character from the user
        ch = getch();

        // If Enter key is pressed, break the loop
        if (ch == 13) {
            break;
        }
        
        // If Backspace key is pressed, remove the last character
        if (ch == 8 && !inputText.empty()) {
            inputText.erase(inputText.size() - 1);  // Use erase method instead of pop_back
        } else if (ch != 8 && ch != 13) {
            // Append the character to the input text
            inputText.push_back(ch);
            
        }

        // Clear the previous text display area
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(left + 1, top + 1, right - 1, bottom - 1);

        // Redraw the input box with the updated text
        outtextxy(x, y, (char*)inputText.c_str());
        
    }
}

//***************************************************************************

void capturePasswordInput(int left, int top, int right, int bottom, std::string &password) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box

	setbkcolor(WHITE);
    setcolor(BLACK); // Change the text color
    
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Change the text style and size


    while (true) {
        // Display asterisks for the length of the password
        std::string maskedPassword(password.length(), '*');
        outtextxy(x, y, (char*)maskedPassword.c_str());

        // Get a character from the user
        ch = getch();

        // If Enter key is pressed, break the loop
        if (ch == 13) {
            break;
        }
        
        // If Backspace key is pressed, remove the last character
        if (ch == 8 && !password.empty()) {
            password.erase(password.size() - 1);  // Use erase method instead of pop_back
        } else if (ch != 8 && ch != 13) {
            // Append the character to the password
            password.push_back(ch);
        }

        // Clear the previous text display area
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(left + 1, top + 1, right - 1, bottom - 1);

        // Redraw the input box with the updated password
        std::string maskedPasswordUpdated(password.length(), '*');
        outtextxy(x, y, (char*)maskedPasswordUpdated.c_str());
    }
}

//***************************************************************************


void captureDayCountInput(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box

    // Set the text color and style
    setbkcolor(WHITE);
    setcolor(BLACK); // Change the text color
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Change the text style and size

    while (true) {
        // Draw the input box
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        

        // Clear the text display area with the background color
        
        bar(left + 1, top + 1, right - 1, bottom - 1);

        // Display the current input text
        outtextxy(x, y, (char*)inputText.c_str());

        // Get a character from the user
        ch = getch();

        // If Enter key is pressed and input is up to 3 digits, break the loop
        if (ch == 13 && inputText.length() <= 3) {
            break;
        }

        // If Backspace key is pressed, remove the last character
        if (ch == 8 && !inputText.empty()) {
            inputText.erase(inputText.size() - 1);  // Use erase method instead of pop_back
        } else if (isdigit(ch) && inputText.length() < 3) {
            // Append the digit to the input text
            inputText.push_back(ch);
        }
        // Clear the previous text display area
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(left + 1, top + 1, right - 1, bottom - 1);
    }
}

//***************************************************************************



void captureWeightInput(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box

    // Set the text color and style
    setbkcolor(WHITE);
    setcolor(BLACK); // Change the text color
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Change the text style and size

    bool decimalPointUsed = false;

    while (true) {

        // Clear the text display area with the background color
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        //bar(left + 1, top + 1, right - 1, bottom - 1);

        // Display the current input text
        outtextxy(x, y, (char*)inputText.c_str());

        // Get a character from the user
        ch = getch();

        // If Enter key is pressed and input is up to 5 characters, break the loop
        if (ch == 13 && inputText.length() <= 5) {
            break;
        }

        // If Backspace key is pressed, remove the last character
        if (ch == 8 && !inputText.empty()) {
            inputText.erase(inputText.size() - 1);  // Use erase method instead of pop_back
        } else if ((isdigit(ch) || (ch == '.' && !decimalPointUsed)) && inputText.length() < 5) {
            // Append the digit or decimal point to the input text
            if (ch == '.') {
                decimalPointUsed = true;
            }
            inputText.push_back(ch);
        }
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(left + 1, top + 1, right - 1, bottom - 1);
    }
}





void captureAdminName(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box
    
    setbkcolor(WHITE);
    setcolor(BLACK); // Change the text color
    
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Change the text style and size

    while (true) {
    // Draw the input box
    //rectangle(240, 340, 480, 380);
        
        // Display the current input text
        outtextxy(x, y, (char*)inputText.c_str());

        // Get a character from the user
        ch = getch();

        // If Enter key is pressed, break the loop
        if (ch == 13) {
            break;
        }
        
        // If Backspace key is pressed, remove the last character
        if (ch == 8 && !inputText.empty()) {
            inputText.erase(inputText.size() - 1);  // Use erase method instead of pop_back
        } else if (ch != 8 && ch != 13) {
            // Append the character to the input text
            inputText.push_back(ch);
            
        }

        // Clear the previous text display area
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(left + 1, top + 1, right - 1, bottom - 1);

        // Redraw the input box with the updated text
        outtextxy(x, y, (char*)inputText.c_str());
        
    }
}


//***************************************************************************************************

void captureAdminPassword(int left, int top, int right, int bottom, std::string &password) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box

setbkcolor(WHITE);
setcolor(BLACK); // Change the text color
    
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Change the text style and size


    while (true) {
        // Display asterisks for the length of the password
        std::string maskedPassword(password.length(), '*');
        outtextxy(x, y, (char*)maskedPassword.c_str());

        // Get a character from the user
        ch = getch();

        // If Enter key is pressed, break the loop
        if (ch == 13) {
            break;
        }
        
        // If Backspace key is pressed, remove the last character
        if (ch == 8 && !password.empty()) {
            password.erase(password.size() - 1);  // Use erase method instead of pop_back
        } else if (ch != 8 && ch != 13) {
            // Append the character to the password
            password.push_back(ch);
        }

        // Clear the previous text display area
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(left + 1, top + 1, right - 1, bottom - 1);

        // Redraw the input box with the updated password
        std::string maskedPasswordUpdated(password.length(), '*');
        outtextxy(x, y, (char*)maskedPasswordUpdated.c_str());
    }
}

//***************************************************************************************************

void captureDeleteMemberNum(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box
    
    setbkcolor(WHITE);
    setcolor(BLACK); // Change the text color   
    
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Change the text style and size

    while (true) {
        // Draw the input box
        rectangle(left, top, right, bottom);

        // Display the current input text
        outtextxy(x, y, (char*)inputText.c_str());

        // Get a character from the user
        ch = getch();

        // If Enter key is pressed and input is up to 3 digits, break the loop
        if (ch == 13 && inputText.length() <= 3) {
            break;
        }

        // If Backspace key is pressed, remove the last character
        if (ch == 8 && !inputText.empty()) {
            inputText.erase(inputText.size() - 1);  // Use erase method instead of pop_back
        } else if (isdigit(ch) && inputText.length() < 3) {
            // Append the digit to the input text
            inputText.push_back(ch);
        }

        // Clear the previous text display area
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(left + 1, top + 1, right - 1, bottom - 1);

        // Redraw the input box with the updated text
        outtextxy(x, y, (char*)inputText.c_str());
    }
}

//*********************************************************************************************************

void captureAdminEdit(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box
    
    setbkcolor(WHITE);
    setcolor(BLACK); // Change the text color   
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Change the text style and size

    while (true) {
        // Draw the input box
        rectangle(left, top, right, bottom);

        // Display the current input text
        outtextxy(x, y, (char*)inputText.c_str());

        // Get a character from the user
        ch = getch();

        // If Enter key is pressed and input is up to 3 digits, break the loop
        if (ch == 13 && inputText.length() <= 3) {
            break;
        }

        // If Backspace key is pressed, remove the last character
        if (ch == 8 && !inputText.empty()) {
            inputText.erase(inputText.size() - 1);  // Use erase method instead of pop_back
        } else if (isdigit(ch) && inputText.length() < 3) {
            // Append the digit to the input text
            inputText.push_back(ch);
        }

        // Clear the previous text display area
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(left + 1, top + 1, right - 1, bottom - 1);

        // Redraw the input box with the updated text
        outtextxy(x, y, (char*)inputText.c_str());
    }
}

//*******************************************************************************************************
void captureAdminSearch(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box
    
    setbkcolor(WHITE);
    setcolor(BLACK); // Change the text color   
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Change the text style and size

    while (true) {
        // Draw the input box
        rectangle(left, top, right, bottom);

        // Display the current input text
        outtextxy(x, y, (char*)inputText.c_str());

        // Get a character from the user
        ch = getch();

        // If Enter key is pressed and input is up to 3 digits, break the loop
        if (ch == 13 && inputText.length() <= 3) {
            break;
        }

        // If Backspace key is pressed, remove the last character
        if (ch == 8 && !inputText.empty()) {
            inputText.erase(inputText.size() - 1);  // Use erase method instead of pop_back
        } else if (isdigit(ch) && inputText.length() < 3) {
            // Append the digit to the input text
            inputText.push_back(ch);
        }

        // Clear the previous text display area
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(left + 1, top + 1, right - 1, bottom - 1);

        // Redraw the input box with the updated text
        outtextxy(x, y, (char*)inputText.c_str());
    }
}
#endif
