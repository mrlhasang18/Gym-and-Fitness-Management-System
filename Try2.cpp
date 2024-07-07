#include <graphics.h>
#include <conio.h>
#include <string.h>

//***************************************************************************


// Enum for managing different pages
enum Page { LANDING, LOGIN_USER, ADMIN_LOG, SIGN_UP , SUBSCRIPTION, GYMTIME_SELECT, THANK_YOU, 
			USER_MENU, USER_EDIT, DIET_SUGGESTION, USER_RECORDS, USER_QUIT, LOGIN_POPUP,
			ADMIN_MENU, ADD_MEMBER, DELETE_MEMBER, ADMIN_RECORDS, ADMIN_SEARCH, EDIT_MEMBER};

Page currentPage = LANDING;

std::string username, password, mem_no, contacts;

//***************************************************************************

// Function to check if click is within the button bounds
bool isClickInBounds(int x, int y, int left, int top, int right, int bottom) {
    return (x >= left && x <= right && y >= top && y <= bottom);
}

//***************************************************************************


void captureTextInput(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box

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

void drawLandingPage() {
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 0, getmaxx(), getmaxy());

    setcolor(WHITE);
    
    readimagefile("Landing_Page.jpg", 0, 0, 1280, 720);
    
    
    rectangle(1004, 666, 1003+108, 668+15);
    

   /* settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    rectangle(150, 200, 450, 250);
    outtextxy(200, 210, "Login as User"); 

    rectangle(150, 300, 450, 350);
    outtextxy(200, 310, "Login as Admin");

    rectangle(200, 400, 400, 430);
    outtextxy(230, 410, "Exit from the app"); */
    
    // "JOIN US" BUtton == rectangle(972, 597, 1143, 647.5);
    
}


//************************************************************************


void drawLoginPopup(){ 

readimagefile("Login_Popup.jpg", 0, 0,1280, 720); 

setcolor(RED);

rectangle(435, 511, 435+398, 511+48);
rectangle(435, 576, 435+398, 576+48); 
} 


//****************************************************************************

void drawLoginForm() {
	
    setfillstyle(1,LIGHTBLUE);
      
    bar(0, 0, getmaxx(), getmaxy());
    
    
    // Placeholder for the image
 
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 0, getmaxx(), getmaxy());
    
    setcolor(RED);
    readimagefile("User_Login.jpg", 00, 00, 1280, 720);
    
    
    setbkcolor(LIGHTGRAY);
    
    rectangle( 209, 338, 209+292, 338+45);

	rectangle( 209, 432, 209+292, 432+45); 	

    rectangle( 208, 527, 208+293, 527+38 );
   
    setcolor(RED);
    rectangle(329, 608, 380, 623);

    rectangle(1038, 480, 1038+169, 480+169);
   
   	
}

//***************************************************************************************


void drawSubscriptionPlan(){ 

readimagefile("4.jpg", 00, 00, 1280, 720);
rectangle(221, 642, 560, 683);

rectangle(720, 642, 1059, 683);


//Silver tier SIGNUP 221, 642, 560, 683
//GOLD tier SIGNUP 720, 642, 1059, 683


}


//***************************************************************************************

// Function to draw the login form
void drawSignUpPage() 
{
	
    readimagefile("SIGN_UP.jpg", 0, 0, 1280, 720);
    
    rectangle(208, 286, 208+292, 286+45); 
    
    rectangle(207, 354, 207+292, 354+45); 
    
    rectangle(207, 423, 207+292, 423+45); 
    
    rectangle(207, 491, 207+292, 491+45);
    
    rectangle(208, 560, 207+292, 560+38); 
    
}


//***************************************************************************************

void drawGymTimeSelect()
{ 

readimagefile("6.jpg", 0,0, 1280, 720); 

rectangle(355, 269, 548, 462);
rectangle(355+277, 269, 548+277, 462);
rectangle(355+277+277, 269, 548+277+277, 462); 

rectangle(355, 269+210, 548, 462+210);
rectangle(355+277, 269+210, 548+277, 462+210);
rectangle(355+277+277, 269+210, 548+277+277, 462+210); 

}


//***************************************************************************************


void drawRegistrationThanks(){ 

readimagefile("ThankYou.jpg", 0, 0, 1280, 720); 

rectangle( 463, 551, 804, 593);
}

//***************************************************************************************


void drawUserMenu(){ 

readimagefile("UserMenu.jpg", 0, 0, 1280, 720); 

rectangle(139, 252, 139+216 ,252+216);
rectangle(415, 252, 415+216, 252+216);
rectangle(692, 252, 692+216, 252+216); 
rectangle(969, 252, 969+216, 252+216); 
rectangle(867, 627, 867+340, 627+42);
}


//***************************************************************************************


void drawAdminLogin(){ 

readimagefile("ADMIN_LOG.jpg", 0, 0 , 1280, 720); 

setcolor(RED); 

rectangle( 209, 338, 209+292, 338+45);

rectangle( 209, 432, 209+292, 432+45); 


}

//***************************************************************************************

void drawAdminMenu(){ 

readimagefile("ADMIN_MENU.jpg",0,0,1280,720); 

rectangle( 151, 170, 151+216, 170+216); 

rectangle( 523, 170, 523+216, 170+216); 

rectangle( 895, 170, 895+216, 170+216); 

rectangle( 151, 432, 151+216, 432+216); 

rectangle( 523, 432, 523+216, 432+216); 

rectangle(833, 605, 833+340, 605+42);


}

//***************************************************************************************

void drawUserEdit(){ 

    readimagefile("USER_EDIT.jpg", 0, 0, 1280, 720); 

}


//***************************************************************************************

void drawDietSuggestion(){ 
    
    readimagefile("DIET_SUGGESTION_1.jpg", 0,0, 1280, 720); 

}


//***************************************************************************************


void drawUserRecords(){ 

    readimagefile("USER_RECORDS.jpg", 0, 0, 1280, 720); 

}


//***************************************************************************************


void drawUserQuit(){ 

    readimagefile("USER_QUIT.jpg", 0, 0, 1280, 720); 

}

//***************************************************************************************
//BELOW THIS ARE THE FUNCTIONS THAT CONTROL THE BUTTON CLICKS
//    			 ||
//    		     ||
//    			 ||
//   			\  /
//    			 \/    
//****************************************************************************************




void handleLandingPageClick(int x, int y) 
{
    if (isClickInBounds(x, y, 972, 597, 1143, 647.5)) 
	{
        currentPage = LOGIN_POPUP;
        cleardevice();
        drawLoginPopup();
    }
	else if (isClickInBounds(x, y, 1004, 666, 1003+108, 668+15)) 
	{
        currentPage = ADMIN_LOG;
        cleardevice();
        drawAdminLogin();
    } 
	else if (isClickInBounds(x, y, 200, 400, 400, 430)) {
        closegraph();
        exit(0);
    }
}


//******************************************************************************************



void handleLoginPopup(int x, int y){ 

	if(isClickInBounds(x, y, 435, 511, 435+398, 511+48)){ 


		cleardevice(); 
		drawLoginForm(); 
		currentPage == LOGIN_USER; 

	}
	else if(isClickInBounds(x, y, 435, 576, 435+398, 576+48)){
	
	
		cleardevice(); 
		drawSignUpPage(); 
			currentPage == SIGN_UP;
	}


}

// Function to handle login page clicks
void handleLoginPageClick(int x, int y) {
	
	
    // Check if the click is within the login button bounds
    if (isClickInBounds(x, y, 232, 523, 523, 561) ){
        cleardevice();
        
        drawUserMenu();
        currentPage = USER_MENU;
      
    }
    else if(isClickInBounds(x, y, 352, 603, 404, 621)){
		cleardevice(); 
    	
		drawSignUpPage();
		currentPage = SIGN_UP; 
    	
	}
	else if(isClickInBounds(x, y, 1038, 480, 1038+169, 480+169)){ 
	
	
	cleardevice(); 
	drawAdminLogin(); 
	currentPage = ADMIN_LOG; 
	
	}
	else if(isClickInBounds(x,y,209, 338, 209+292, 338+45))
	{ 
	
	captureTextInput(240, 340, 480, 380, username);
    
    
	}
	else if (isClickInBounds(x,y, 209, 432, 209+292, 432+45))
	{ 
	
	 capturePasswordInput(240, 434, 480, 470, password);
	 
	}
}


//**********************************************************************************************



// Function to Subscription page clicks
void handleSubscriptionClick(int x, int y) {
	
	
    // Check if the click is within the login button bounds
    if (isClickInBounds(x, y, 221, 642, 560, 683) ){
        cleardevice();
        
        drawGymTimeSelect();
        
        currentPage = GYMTIME_SELECT;
    }
    else if (isClickInBounds(x, y, 720, 642, 1059, 683) ){
        cleardevice();
        
        drawGymTimeSelect();
        currentPage = GYMTIME_SELECT;
      
    }
}


//**********************************************************************************************

/*rectangle(207, 354, 207+292, 354+45); 
    
    rectangle(207, 423, 207+292, 423+45); 
    
    rectangle(207, 491, 207+292, 491+45);
    
    rectangle(208, 560, 207+292, 560+38); */

void handleSignUpPageClick(int x, int y) {

if(isClickInBounds(x, y, 208, 286, 208+292, 286+45)){ 
    
	captureTextInput(208, 286, 500, 331, mem_no); 
	
	}
else if(isClickInBounds(x, y, 207, 354, 207+292, 354+45)){ 
    
	captureTextInput(207, 354, 207+292, 354+45, username); 
	
	}

else if(isClickInBounds(x, y, 207, 423, 207+292, 423+45)){ 
    
	captureTextInput(207, 423, 207+292, 423+45, contacts); 
	
	}

else if(isClickInBounds(x, y, 207, 491, 207+292, 491+45)){ 
    
	capturePasswordInput(207, 491, 207+292, 491+45, password); 
	
	}
}




//***************************************************************************************

void handleGymTimeSelect(int x, int y){ 

if (isClickInBounds(x, y, 355, 269, 548, 462) )
{
        cleardevice();
        
        drawRegistrationThanks();
        
        currentPage = THANK_YOU;
    
	}
    else if(isClickInBounds(x, y, 355+277, 269, 548+277, 462))
	{
	 
    cleardevice(); 
    
    drawRegistrationThanks(); 
    
    currentPage = THANK_YOU; 
	
	}
	
	
	else if(isClickInBounds(x, y, 355+277+277, 269, 548+277+277, 462))
	{
	 
    cleardevice(); 
    
    drawRegistrationThanks(); 
    
    currentPage = THANK_YOU; 
	
	}
	
	
	else if(isClickInBounds(x, y, 355, 269+210, 548, 462+210))
	{
	 
    cleardevice(); 
    
    drawRegistrationThanks(); 
    
    currentPage = THANK_YOU; 
	
	}
	
	else if(isClickInBounds(x, y, 355+277, 269+210, 548+277, 462+210))
	{ 
    
	cleardevice(); 
    
    drawRegistrationThanks(); 
    
    currentPage = THANK_YOU; 
	
	}
	
	else if(isClickInBounds(x, y, 355+277+277, 269+210, 548+277+277, 462+210))
	{ 
    
	cleardevice(); 
    
    drawRegistrationThanks(); 
    
    currentPage = THANK_YOU; 
	
	}

}

//**********************************************************************************************

void handleRegistrationThanks(int x, int y) {
    if (isClickInBounds(x, y, 463, 551, 804, 593)) 
	{
        currentPage = LOGIN_USER;
        cleardevice();
        drawLoginForm();
    }
   
	
}
//**********************************************************************************************

void handleUserMenu( int x, int y){ 

if(isClickInBounds(x, y, 139, 252, 139+216 ,252+216)){ 

cleardevice();
drawUserEdit(); 
currentPage = USER_EDIT;
}
else if(isClickInBounds(x, y, 415, 252, 415+216, 252+216)){
	

	cleardevice(); 
	drawDietSuggestion(); 
	currentPage = DIET_SUGGESTION;
	
}
else if(isClickInBounds(x, y, 692, 252, 692+216, 252+216) ){
	
	cleardevice();
	drawUserRecords();
	currentPage = USER_RECORDS;
	
	
}
else if(isClickInBounds(x,y, 969, 252, 969+216, 252+216)){ 


cleardevice(); 
drawUserQuit();
currentPage = USER_QUIT; 

}



}

//***************************************************************************************
 
void handleAdminLogin( int x, int y){ 
 
  if (isClickInBounds(x, y, 232, 523, 523, 561) ){
        cleardevice();
        
        drawAdminMenu();
        currentPage = ADMIN_MENU;
      
    }
    else if(isClickInBounds(x, y, 352, 603, 404, 621)){
		cleardevice(); 
    	
		drawLoginForm();
		currentPage = LOGIN_USER; 
    	
	}
	
/*	else if(isClickInBounds(x,y,209, 338, 209+292, 338+45))
	{ 
	
	captureTextInput(240, 340, 480, 380, username);
    
    
	}
	else if (isClickInBounds(x,y, 209, 432, 209+292, 432+45))
	{ 
	
	 capturePasswordInput(240, 434, 480, 470, password);
	 
	}*/ 
}


//*****************************************************************************************************

void handleAdminMenu(int x, int y){ 

	
	if(isClickInBounds(x, y, 151, 170, 151+216, 170+216)){ 
	
	cleardevice(); 
	
	//drawAddMember(); 
	
	currentPage == ADD_MEMBER; 
	
	}
	
	else if(isClickInBounds(x, y, 523, 170, 523+216, 170+216)){ 
	
	cleardevice(); 
	
	//drawAdminRecords(); 
	
	currentPage == ADMIN_RECORDS; 
	
	}
	else if(isClickInBounds(x, y, 895, 170, 895+216, 170+216)){ 
	
	cleardevice(); 
	
	//drawDeleteMember(); 
	
	currentPage == DELETE_MEMBER; 
	
	}
	
	else if(isClickInBounds(x,y, 151, 432, 151+216, 432+216)){ 
	
	cleardevice(); 
	
	//drawEditMember(); 
	
	currentPage == EDIT_MEMBER; 
	
	}
	else if(isClickInBounds(x, y, 523, 432, 523+216, 432+216)){ 
	
	cleardevice(); 
	
	//drawSearchRecords(); 
	
	currentPage == ADMIN_SEARCH; 
	
	}
	else if(isClickInBounds(x,y, 833, 605, 833+340, 605+42)){ 
	
	cleardevice(); 
	
	drawLoginForm(); 
	
	currentPage == LOGIN_USER; 
	}

}


//*****************************************************************************************************


void handleUserEdit(int x, int y){ 


}


//*****************************************************************************************************


void handleDietSuggestion(int x, int y){ 


}


//*****************************************************************************************************


void handleUserRecords(int x, int y) { 


}


//*****************************************************************************************************


void handleUserQuit(int x, int y){ 


}




//***************************************************************************************
//BELOW THIS IS THE MAIN FUNCTIONS
//    			 ||
//    		     ||
//    			 ||
//   			\  /
//    			 \/    
//****************************************************************************************



int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Set window size
    initwindow(1280, 720, "Gym Management and Fitness Suggestion System");

	drawLandingPage();
	
	
	
	
   	int x, y;
   	
   	std::string username;
   	
   	
   	
	
		while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);
            
            
           if (currentPage == LANDING) 
		   {
                handleLandingPageClick(x, y);
            } 
            else if (currentPage == LOGIN_POPUP)
			{ 
            
            handleLoginPopup(x, y);
            
			}
			else if (currentPage == LOGIN_USER /*|| currentPage == LOGIN_ADMIN*/) 
			{
                handleLoginPageClick(x, y);
            }
            else if (currentPage == SUBSCRIPTION) 
			{
                handleSubscriptionClick(x, y);
            }
            else if(currentPage == SIGN_UP)
            { 
            handleSignUpPageClick(x,y);
			}
			else if( currentPage == GYMTIME_SELECT){
				
			handleGymTimeSelect(x,y);
			}
			else if( currentPage == THANK_YOU){
				
				handleRegistrationThanks(x,y);
			}
            else if( currentPage == USER_MENU){
            	
            	handleUserMenu(x, y); 
			}
			else if( currentPage == ADMIN_LOG){ 
			
			handleAdminLogin(x, y);
			
			}
			else if(currentPage == ADMIN_MENU){ 
			
			handleAdminMenu(x, y);
			
			}
            else if( currentPage == USER_EDIT){ 
            
            handleUserEdit(x, y);
            
			}
			else if( currentPage == DIET_SUGGESTION){ 
			
			handleDietSuggestion(x, y); 
			
			}
			else if (currentPage == USER_RECORDS){
				
			handleUserRecords(x, y); 
				
			}
			else if (currentPage == USER_QUIT){ 
			
			handleUserQuit(x, y); 
			
			}
            
			}
        }

       
    


    closegraph();
    return 0;
}

