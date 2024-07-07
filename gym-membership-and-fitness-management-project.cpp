#include<fstream>
#include<iomanip>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<graphics.h>
#include<string.h>

using namespace std;

void handleRegistrationThanks(int x, int y);
void drawGymTimeSelect(); 



enum Page { LANDING, LOGIN_USER, ADMIN_LOG, SIGN_UP , SUBSCRIPTION, GYMTIME_SELECT, THANK_YOU, 
			USER_MENU, USER_EDIT, DIET_SUGGESTION, USER_RECORDS, USER_QUIT, 
			ADMIN_MENU, ADD_MEMBER, DELETE_MEMBER, ADMIN_RECORDS, ADMIN_SEARCH, EDIT_MEMBER};

Page currentPage = LANDING;

std::string username, u_pass, u_contact, u_num;
int time_slut, Subs_click; 

//***************************************************************************

// Function to check if click is within the button bounds
bool isClickInBounds(int x, int y, int left, int top, int right, int bottom) {
    return (x >= left && x <= right && y >= top && y <= bottom);
}

//***************************************************************************

void captureMemberNumber(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box

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

//****************************************************************************

void captureContactInput(int left, int top, int right, int bottom, std::string &inputText) {
    char ch;
    int x = left + 5;  // Starting x position for text inside the input box
    int y = top + 10;  // Starting y position for text inside the input box

    while (true) {
        // Draw the input box
        rectangle(left, top, right, bottom);

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
void drawLoginPopup(){ 

	readimagefile("Login_Popup.jpg", 0, 0,1280, 720); 

	setcolor(RED);

	rectangle(435, 511, 435+398, 511+48);
	rectangle(435, 576, 435+398, 576+48); 
} 

//***************************************************************************

void drawLandingPage() {
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 0, getmaxx(), getmaxy());

    setcolor(WHITE);
    
    readimagefile("Landing_Page.jpg", 0, 0, 1280, 720);
    
    
    
    

   /* settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    rectangle(150, 200, 450, 250);
    outtextxy(200, 210, "Login as User"); 

    rectangle(150, 300, 450, 350);
    outtextxy(200, 310, "Login as Admin");

    rectangle(200, 400, 400, 430);
    outtextxy(230, 410, "Exit from the app"); */
    
    // "JOIN US" BUtton == rectangle(972, 597, 1143, 647.5);
    
}

//****************************************************************************

void drawLoginForm() {
	
    readimagefile("User_Login.jpg", 00, 00, 1280, 720);
    
    
    
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


void handleRegistrationThanks(int x, int y) {
	while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);
    if (isClickInBounds(x, y, 463, 551, 804, 593)) 
	{
         cleardevice();
        break;
  
    }
}}
   	
}
//**********************************************************************************************
int handleGymTimeSelect(int x, int y){ 

while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);

if (isClickInBounds(x, y, 355, 269, 548, 462) )
{
        cleardevice();
        
        time_slut = 1;
        
        drawRegistrationThanks();
        handleRegistrationThanks(x, y);
        break; 

    
	}
    else if(isClickInBounds(x, y, 355+277, 269, 548+277, 462))
	{
	 
    cleardevice(); 
    
    time_slut = 2; 
    
    drawRegistrationThanks(); 
    handleRegistrationThanks(x, y);
    break;
  
	
	}
	
	
	else if(isClickInBounds(x, y, 355+277+277, 269, 548+277+277, 462))
	{
	 time_slut = 3; 
    cleardevice(); 
    
    drawRegistrationThanks(); 
    handleRegistrationThanks(x, y);
    break;
   
	
	}
	
	
	else if(isClickInBounds(x, y, 355, 269+210, 548, 462+210))
	{
	 
	 time_slut = 4; 
    cleardevice(); 
    
    drawRegistrationThanks(); 
    handleRegistrationThanks(x, y);
    break;
    
	
	}
	
	else if(isClickInBounds(x, y, 355+277, 269+210, 548+277, 462+210))
	{ 
    time_slut = 5; 
	cleardevice(); 
    
    drawRegistrationThanks(); 
    handleRegistrationThanks(x, y);
    break;
  
	
	}
	
	else if(isClickInBounds(x, y, 355+277+277, 269+210, 548+277+277, 462+210))
	{ 
    time_slut = 6; 
	cleardevice(); 
    
    drawRegistrationThanks(); 
    
    handleRegistrationThanks(x, y);
    break; 
    
	
	}
}}
return 0; 
}



// Function to Subscription page clicks
int handleSubscriptionClick(int x, int y) {

while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);	
	
    // Check if the click is within the login button bounds
    if (isClickInBounds(x, y, 221, 642, 560, 683) ){
        cleardevice();
        
        
        Subs_click = 1; 
        drawGymTimeSelect();
        handleGymTimeSelect(x, y);
        break; 
        
    }
    else if (isClickInBounds(x, y, 720, 642, 1059, 683) ){
        cleardevice();
        
        Subs_click = 2; 
        
        drawGymTimeSelect();
        handleGymTimeSelect(x, y); 
        break; 
      
    }
}
}
return 0; 
}


//**********************************************************************************************

int handleSignUpPageClick(int x, int y) {
	
	
	int Subs;
	
	while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);	

if(isClickInBounds(x, y, 208, 286, 208+292, 286+45)){ 
    
	captureMemberNumber(208, 286, 500, 331, u_num); 
	
	}
else if(isClickInBounds(x, y, 207, 354, 207+292, 354+45)){ 
    
	captureTextInput(207, 354, 207+292, 354+45, username); 
	
	}

else if(isClickInBounds(x, y, 207, 423, 207+292, 423+45)){ 
    
	captureContactInput(207, 423, 207+292, 423+45, u_contact); 
	
	}

else if(isClickInBounds(x, y, 207, 491, 207+292, 491+45)){ 
    
	capturePasswordInput(207, 491, 207+292, 491+45, u_pass); 
	
	}
	else if(isClickInBounds(x, y, 208, 560, 207+292, 560+38)){ 
	
	cleardevice();
	drawSubscriptionPlan(); 
	handleSubscriptionClick(x, y); 
	break; 
	
	}

}
}
return 0; 

}


//***************************************************************************************




int handleLandingPageClick(int x, int y) 
{
	
		while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);
            
    if (isClickInBounds(x, y, 972, 597, 1143, 647.5)) 
	{
        currentPage = LOGIN_USER;
        //cleardevice();
        //drawLoginForm();
		return 1; 
    }
    else if (isClickInBounds(x, y, 1004, 666, 1003+108, 668+15)) 
	{
        currentPage = ADMIN_LOG;
        //cleardevice();
        return 2;
    } 
	else if (isClickInBounds(x, y, 200, 400, 400, 430)) {
        closegraph();
        exit(0);
    }
    
	
}
};
}






//******************************************************************************************



int handleLoginPopup(int x, int y){ 

while(TRUE)
{ 
if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);


	if(isClickInBounds(x, y, 435, 511, 435+398, 511+48)){ 


		cleardevice(); 
		//drawLoginForm(); 
		currentPage == LOGIN_USER; 
		return 2;

	}
	else if(isClickInBounds(x, y, 435, 576, 435+398, 576+48)){
	
	
		cleardevice(); 
		//drawSignUpPage(); 
			currentPage == SIGN_UP;
			return 1;
	}
}
};

}

//******************************************************************************************

// Function to handle login page clicks
int handleLoginPageClick(int x, int y) {
	
	while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);
            
    // Check if the click is within the login button bounds
    if (isClickInBounds(x, y, 232, 523, 523, 561) ){
        //cleardevice();
        return 1;
        //drawUserMenu();
        //currentPage = USER_MENU;
      
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
	
	 capturePasswordInput(240, 434, 480, 470, u_pass);
	 
	}
}
};
exit(0);
}


//**********************************************************************************************



//**********************************************************************************************


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








void user_record();
void fnmanage();


class alogin
{
	string admin;
	public:
	int adlogin()
	{
		cout<<"\n\t\tEnter the admin code: ";
		
		cin>>admin;
		if(admin=="admin")
		{	
			 int p=getadpassword();
			 if (p==1)
			 {
			 	cout<<"login succesful"<<endl;
			 	return(1);  
			 }
			 else{
			 	cout<<"login failed"<<endl;
			return(0);
			 }
		}
		else{
			cout<<"user name not found"<<endl;
			adlogin();
		}
	}
	int getadpassword();
};	
int alogin::getadpassword()
{
	string pw;
	cout<<"\t\tEnter the password: ";
	cin>>pw;
	if(pw=="hello")
	{
		cout<<"WELCOME!!"<<endl;
		return 1;
	}
	else
    {
		cout<<"\t\tEntered password is incorrect"<<endl;
		getadpassword();
	}
}
void allotment_gold(int gc)
{
    if(gc!=0)
    {
        cout<<gc;
        cout<<" trainer alloted\n";
    }
     else
     {
         cout<<"no trainer available\n";
     }
}
void allotment_silver( int sc)
{
    if(sc!=0)
    {
        cout<<sc;
        cout<<" trainer alloted\n";
    }
     else
     {
         cout<<"\nno trainer available\n";
        
     }
}
void trainee_allotment(char* c)
{	
    char class_type[10];
    int i, gold_class = 5, silver_class = 3;
    strcpy(class_type,c);
           		if((gold_class!=0) || (silver_class)!=0)
                    {
                        if(strcmp(class_type,"gold")==0)
                        {
                           
                            allotment_gold(gold_class);
                        }
                        else if(strcmp(class_type,"silver")==0)
                        {
                           
                            allotment_silver( silver_class);
                        }
                    }
                    else
                    {
                        cout<<"no traianer availbale\n";
                        
                    }
}
class member
    {
    	int member_number, weight; 
    	char mem_name[50], classs[50],timings[50];
    	char password[50];
    	float fee;
    	char contact[11];    	
    	public:
    int get_member_number()
    {	return(member_number);
	}
     string passw()
	 {
	 	return(password);
		}   
     int time_slots()
       {	
			//int k;
			//cout<<"\nPlease select your preferred timings\npress 1 for: morning 6-7\npress 2 for: morning 7-8\npress 3 for:morning 8-9\n";
			//cout<<"press 4 for: evening 4-5\npress 5 for:evening 5-6\npress 6 for:evening 6-7\n";
			//cin>>k;
			switch(time_slut)
			{
				case 1:strcpy(timings,"6AM-7AM");break;
				case 2:strcpy(timings,"7AM-8AM");break;
				case 3:strcpy(timings,"8AM-9AM");break;
				case 4:strcpy(timings,"4PM-5PM");break;
				case 5:strcpy(timings,"5PM-6PM");break;
				case 6:strcpy(timings,"6PM-7PM");break;
			}
		}	
    	void create_mem()
    	{	int k,i=0, m;
    		
    		//fflush(stdin);
    		//cout<<endl<<"Please Enter The member Number: ";
    		
    		cleardevice(); 
    		drawSignUpPage();
    	
			int click_x = 0; // Replace with actual x coordinate
    		int click_y = 0; // Replace with actual y coordinate
    	
		    k = handleSignUpPageClick(click_x, click_y);
    	
    			 
			strncpy(mem_name, username.c_str(), sizeof(mem_name) - 1);
    		mem_name[sizeof(mem_name) - 1] = '\0';  // Ensure null termination
    		
    		
    		//cin.getline(mem_name,50); ------------------------------------------------------{this cuts the first letter, so comment}
    		
    		//cout<<endl<<"Please set The password:";
    		strncpy(password, u_pass.c_str(), sizeof(password) - 1);
    		password[sizeof(password) - 1] = '\0';  // Ensure null termination
			
    		//cout<<endl<<"Please Enter The contact number: ";
    		//cin>>contact;
    		strncpy(contact, u_contact.c_str(), sizeof(contact) - 1);
    		contact[sizeof(contact) - 1] = '\0';  // Ensure null termination
    		
    		cleardevice(); 
    		drawUserMenu();
    	/*	x:
    		while(strlen(contact)!=10)
    		{
    			cout<<"Invalid contact number";
    			cout<<endl<<"Please Enter The contact number: ";
    			cin>>contact;
			}
			while(i<=9)
			{
				if(contact[i]<48 || contact[i]>57 )
				{
					cout<<"Invalid contact number";
    				cout<<endl<<"Please Enter The contact number: ";
    				cin>>contact;
    				goto x;
				}
				i++;
			}*/
    	 
		
		switch (Subs_click)
		{
			case 1:{
                strcpy(classs,"gold");
				fee=2500;
				//cout<<"your monthly fee would be: "<<fee<<endl;
				trainee_allotment(classs);
				}
				break;
			case 2:{
                strcpy(classs,"silver");
				fee=2000;
				//cout<<"your monthly fee would be: "<<fee<<endl;
				trainee_allotment(classs);
				}
				break;
		}
		time_slots();
		cleardevice(); 
		drawUserMenu(); 
		
    	}
    	void show_mem()
    	{
    		cout<<endl<<"member code: "<<member_number;
    		cout<<endl<<"Name: "<<mem_name;
    		cout<<endl<<"category: "<<classs;
    		cout<<endl<<"fee: "<<fee;
    		cout<<endl<<"contact: "<<contact;
    		cout<<endl<<"timings: "<<timings<<endl;
    	}
    	int getmem()
    	{
    		return member_number;
    	}
    }; 
    fstream fp;
    member m1;
class user
{
	public:
	void virtual save_member()=0;
    void virtual display_record()=0;
    void virtual delete_member(int num = 0)=0;
    void virtual edit_member()=0;
    
};
class gymmember: public user
{	int n;
	public:
//	void setn(int aa)
//	{
//		n=aa;
//	}
	void save_member()
    {
    	system("cls");
    	fp.open("hamro.bin",ios::out|ios::app);
    	m1.create_mem();
    	fp.write((char*)&m1,sizeof(m1));
    	fp.close();
    	cout<<endl<<endl<<"the member has been succesfully added...";
    	fflush(stdin);
    }
	void log()
	{	char ch='T';
		int num;
		char p[50];
		system("cls");
    	cout<<endl<<endl<<"Please Enter The member number: ";
    	cin>>num;
    	cout<<endl<<"Please enter the password:";
    	cin>>p;
		fp.open("hamro.bin",ios::in|ios::out);
    	while(fp.read((char*)&m1,sizeof(m1)) && ch == 'T')
    	{
    		if(m1.getmem()==num&&m1.passw()==p) // entre only if user's i/p no. and password matches
    		{	n=num;
    		fp.close();
   			user_record();
    			ch='F';
    		}
            
    	}
		if(ch=='T')
		{cout<<"invalid member number or password";
	    fp.close();

		}
	}
	void display_record()
    {	int num;
    	num=n;
    	bool found=false;
    	fp.open("hamro.bin",ios::in);
    	while(fp.read((char*)&m1,sizeof(m1)))
    	{
    		if(m1.getmem()==num)
    		{
    			system("cls");
    			m1.show_mem();
    			found=true;
    		}
    	}
    	fp.close();
    	if(found == false)
    	cout<<"\n\nNo record found";
    	
    	cout<<"press any key to continue\n";
    	getch();
    }

    void delete_member(int num = 0)
    {
    	
    	system("cls");
        num=n;
         fp.open("hamro.bin",ios::in|ios::out);
        
    	fstream fp2;
    	fp2.open("timro.bin",ios::out|ios::binary);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&m1,sizeof(m1)))
    	{
    		if(m1.getmem()!=num)
    		{
    			fp2.write((char*)&m1,sizeof(m1));
                
    		}
            
    	}
    	fp2.close();
    	fp.close();
    	remove("hamro.bin");
    	rename("timro.bin","hamro.bin");

        cout<<"press any key to continue\n";
    	getch();
        
    }
   void edit_member()
    {
    	int num;
    	char ch = 'T'; // intilized
    	system("cls");
    	num=n;
    	fp.open("hamro.bin", ios::app | ios::in | ios::binary);
        fp.seekg(0,ios::beg);
    	while(fp.read((char*)&m1,sizeof(m1)) && ch == 'T')
    	{
    		if(m1.getmem()==num) // entre only if user's i/p no. matches
    		{
    			m1.show_mem();
    			cout<<"\nPlease Enter The New details of the member: "<<endl;
    			m1.create_mem();
    			int pos=1*sizeof(m1);
    			fp.seekp(pos,ios::cur);
    			fp.write((char*)&m1,sizeof(m1));
    			cout<<endl<<endl<<"\t Record Successfully Updated...";
                ch = 'f';	// record found
               fp.close();
               delete_member(num);
               n=m1.get_member_number();

    		}
            else{
                continue; 
            }
    	}
        //fp.close();
        if(ch == 'T')
            cout<<"record not found\n";// 

    	fflush(stdin);
    }
    
}s1;
class admin: public user
{	int n;
	public:
	void save_member()
    {
    	system("cls");
    	fp.open("hamro.bin",ios::out|ios::app);
    	m1.create_mem();
    	fp.write((char*)&m1,sizeof(m1));
    	fp.close();
    	cout<<endl<<endl<<"the member has been succesfully added...";
    	fflush(stdin);
    }
    void show_all()
    {
    	system("cls");
    	bool found=false;
    	cout<<endl<<"\t\tRECORDS...";
    	fp.open("hamro.bin",ios::in);
    	while(fp.read((char*)&m1,sizeof(m1)))
    	{
    		m1.show_mem();
    	fflush(stdin);
    	found=true;
    	}
    	fp.close();
    	if(found == false)
    	cout<<"\n\nNo record found";
    	cout<<"\npress any key to continue";
    	getch();
    }
     void display_record()
    {	int num;
    cout<<"enter the member number to be displayed";
    cin>>num;
    	bool found=false;
    	fp.open("hamro.bin",ios::in);
    	while(fp.read((char*)&m1,sizeof(m1)))
    	{
    		if(m1.getmem()==num)
    		{
    			system("cls");
    			m1.show_mem();
    			found=true;
    		}
    	}
    	fp.close();
    	if(found == false)
    	cout<<"\n\nNo record found";
    	
    	cout<<"press any key to continue\n";
    	getch();
    	
    }

    void delete_member(int num = 0)
    {
    	
    	system("cls");
        if(num == 0 )
        {
            cout<<endl<<endl<<"Please Enter The member number: ";
    	cin>>num;
        
    	fp.open("hamro.bin",ios::in|ios::out);
        
    	fstream fp2;
    	fp2.open("timro.bin",ios::out|ios::binary);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&m1,sizeof(m1)))
    	{
    		if(m1.getmem()!=num)
    		{
    			fp2.write((char*)&m1,sizeof(m1));
                
    		}
            
    	}
    	fp2.close();
    	fp.close();
    	remove("hamro.bin");
    	rename("timro.bin","hamro.bin");
    	cout<<endl<<endl<<"\tRecord Deleted..."; 
    	getchar();
        }
        else
        {
          fp.open("hamro.bin",ios::in|ios::out);
        
    	fstream fp2;
    	fp2.open("timro.bin",ios::out|ios::binary);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&m1,sizeof(m1)))
    	{
    		if(m1.getmem()!=num)
    		{
    			fp2.write((char*)&m1,sizeof(m1));
                
    		}
            
    	}
    	fp2.close();
    	fp.close();
    	remove("hamro.bin");
    	rename("timro.bin","hamro.bin");

        cout<<"press any key to continue\n";
    	getch();
        }
    }
   void edit_member()
    {
    	int num;
    	char ch = 'T'; // intilized
    	system("cls");
    	cout<<endl<<endl<<"\tPlease Enter The member number: ";
    	cin>>num;
    	fp.open("hamro.bin", ios::app | ios::in | ios::binary);
        fp.seekg(0,ios::beg);
    	while(fp.read((char*)&m1,sizeof(m1)) && ch == 'T')
    	{
    		if(m1.getmem()==num) // entre only if user's i/p no. matches
    		{
    			m1.show_mem();
    			cout<<"\nPlease Enter The New details of the member: "<<endl;
    			m1.create_mem();
    			int pos=1*sizeof(m1);
    			fp.seekp(pos,ios::cur);
    			fp.write((char*)&m1,sizeof(m1));
    			cout<<endl<<endl<<"\t Record Successfully Updated...";
                ch = 'f';	// record found
               fp.close();
               delete_member(num);

    		}
            else{
                continue; 
            }
    	}
        //fp.close();
        if(ch == 'T')
            cout<<"record not found\n";// 

    	fflush(stdin);
    }


}s2;
class fnd
{
	public:
		void diet1(float W) {
        int t = (W * 22);
        float protein = W * 1.8;
        float carb = 0.45 * t;
        float fat = 0.25 * t;

        cout << "Calorie Intake for Fat Loss (C_fat_loss) = " << t << " cal\n";
        cout << "Protein Intake for Fat Loss (P_fat_loss) = " << protein << " g\n";
        cout << "Carbohydrates for Fat Loss (CHO_fat_loss) = " << carb << " g\n";
        cout << "Fats for Fat Loss (F_fat_loss) = " << fat << " g\n";

        cout << "\nSuggested food items:\n";
        cout << " Proteins: Chicken breast, turkey, lean beef, tofu, fish (salmon, tuna), Greek yogurt, cottage cheese.\n";
        cout << " Carbohydrates: Brown rice, quinoa, sweet potatoes, whole-grain pasta, oats, beans, legumes, and leafy greens.\n";
        cout << " Fats: Avocado, nuts (almonds, walnuts), seeds (chia, flax), olive oil, fatty fish (salmon, mackerel).\n\n";
    }
    
void fitness1(int count, float W) 
{
        cout << "WORKOUT AND DIET PLAN FOR WEIGHT LOSS!!!! \n\n\n";

        cout << "Day " << count << " Workout Plan:\n\n";

        if (count == 1 || count == 8 || count == 15 || count == 22 || count == 29) {
            cout << "Day: " << count << " Upper Body\n\n";

            cout << "#. INSTRUCTION: \n";
            cout << "Pick a weight that leads you to failure at end of 15 rep\n";
            cout << "Do each exercise of 3 sets of 15 reps\n";
            cout << "Take rest of (20 - 30) sec after each set\n\n\n";

            cout << "#. Workout:\n";
            cout << "1. DB Bench Press\n";
            cout << "2. DB Row\n";
            cout << "3. DB Shoulder Press\n";
            cout << "4. Reverse Crunch\n";
        }

        if(count == 2|| count == 9 || count == 16 || count == 23 || count == 30)
        {
        cout<<"Day: "<<count<<" Lower Body\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Pick a weight that leads you to failure at end of 15 rep\n";
        cout<<"Do each exercise of 3 set of 15 reps\n";
        cout<<"Take rest of (20 - 30)sec after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Goblet Squat\n";
        cout<<"2. DB Romanian Deadlift\n";
        cout<<"3. DB Calf Raises\n";
        cout<<"4. Weighted Crunch\n";     
        
        }
        if(count == 3|| count == 10 || count == 17 || count == 24)
        {
        cout<<"Day: "<<count<<" Full Body\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Pick a weight that leads you to failure at end of 15 rep\n";
        cout<<"Do each exercise of 3 set of 15 reps\n";
        cout<<"Take rest of (20 - 30)sec after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Reverse Lunges\n";
        cout<<"2. Push Up\n";
        cout<<"3. DB Facepull \n";
        cout<<"4. Plank: 30sec hold \n";     
       
        }

        if(count == 4|| count == 11 || count == 18 || count == 25)
        {
        cout<<"Day: "<<count<<" Rest\n\n";
        cout<<"Rest: where strength finds its quiet power.\n";
        }

        if(count == 5|| count == 12|| count == 19 || count == 26 )
        {
        
        cout<<"Day: "<<count<<" Upper Body\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Pick a weight that leads you to failure at end of 15 rep\n";
        cout<<"Do each exercise of 3 set of 15 reps\n";
        cout<<"Take rest of (20 - 30)sec after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. DB Bench Press\n";
        cout<<"2. DB Row\n";
        cout<<"3. DB Shoulder Press\n";
        cout<<"4. Reverse Crunch\n"; 
        
        }
        
        if(count == 6|| count == 13 || count == 20 || count == 27 )
        {
        
        cout<<"Day: "<<count<<" Lower Body\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Pick a weight that leads you to failure at end of 15 rep\n";
        cout<<"Do each exercise of 3 set of 15 reps\n";
        cout<<"Take rest of (20 - 30)sec after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Goblet Squat\n";
        cout<<"2. DB Romanian Deadlift\n";
        cout<<"3. DB Calf Raises\n";
        cout<<"4. Weighted Crunch\n";
        }
        
        if(count == 7|| count == 14 || count == 21 || count == 28 )
        {
         cout<<"Day: "<<count<<" Rest\n\n";
        cout<<"Rest: where strength finds its quiet power.\n";
        }

        cout << "\n\n\nDay " << count << " Diet Plan:\n\n";

        diet1(W);
    }


void diet2(float W)
{
	int t=(W * 45);
	float protein= (W * 2.2);
	float carb= 0.45 * t;
	float fat=0.25 * t;

	cout<<"Diet Plan:\n";
	cout<<"Calorie Intake for Muscle Building (C_muscle_building) ="<<t <<"cal\n";
	cout<<"Protein Intake for Muscle Building (P_muscle_building) ="<< protein ;
	cout<<"\nCarbohydrates for Muscle Building (CHO_muscle_building) ="<< carb;
	cout<<"\nFats for Muscle Building (F_muscle_building) =" <<fat;

	cout<<"\nSuggested food items:\n";
	cout<<"Proteins: Lean meats (chicken, turkey, beef), eggs, dairy products (Greek yogurt, milk), fish, tofu, tempeh.";
	cout<<"\nCarbohydrates: Whole-grain bread, brown rice, quinoa, sweet potatoes, oats, fruits (bananas, berries), and vegetables (broccoli, spinach).";
	cout<<"\nFats: Avocado, nuts (almonds, cashews), seeds (flax, chia), olive oil, fatty fish (salmon, mackerel).\n\n";
		
}

void fitness2(int count, float W) 
{
	cout<<"WORKOUT PLAN FOR MUSCLE BUILDING!!!! \n\n\n";
        if(count == 1 || count == 8 || count == 15 || count == 22 || count == 29)
        {
        cout<<"Day: "<<count<<" Back and Biceps\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Deadlifts: 4 sets of 6-8 reps\n";
        cout<<"2. Pull-Ups: 3 sets of 8-10 reps\n";
        cout<<"3. Pull-Ups: 3 sets of 8-10 reps\n";
        cout<<"4. Barbell Bicep Curls: 3 sets of 10-12 reps\n"; 
        }

        if(count == 2|| count == 9 || count == 16 || count == 23 || count == 30)
        {
        cout<<"Day: "<<count<<" Chest and Shoulders\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Bench Press: 4 sets of 6-8 reps\n";
        cout<<"2. Dumbbell Shoulder Press: 3 sets of 8-10 reps\n";
        cout<<"3. Incline Dumbbell Press: 3 sets of 8-10 reps\n";
        cout<<"4. Lateral Raises: 3 sets of 10-12 reps\n";     
        
        }
        if(count == 3|| count == 10 || count == 17 || count == 24)
        {
        cout<<"Day: "<<count<<" Legs, Abs, and Triceps\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Squats: 4 sets of 6-8 reps\n";
        cout<<"2. Leg Press: 3 sets of 8-10 reps\n";
        cout<<"3. Romanian Deadlifts: 3 sets of 8-10 reps \n";
        cout<<"4. Hanging Leg Raises: 3 sets of 10-12 reps \n";  
		cout<<"5. Tricep Dips: 3 sets of 10-12 reps \n" ; 
       
        }

        if(count == 4|| count == 11 || count == 18 || count == 25)
        {
        cout<<"Day: "<<count<<" Back and Biceps\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Pull-Ups: 4 sets of 6-8 reps\n";
        cout<<"2. Barbell Rows: 3 sets of 8-10 reps\n";
        cout<<"3. Lat Pulldowns: 3 sets of 8-10 reps \n";
        cout<<"4. Hammer Curls: 3 sets of 10-12 reps\n";  
       
        }

        if(count == 5|| count == 12|| count == 19 || count == 26 )
        {
        
        cout<<"Day: "<<count<<" Chest and Shoulders\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Incline Bench Press: 4 sets of 6-8 reps\n";
        cout<<"2. Seated Dumbbell Shoulder Press: 3 sets of 8-10 reps\n";
        cout<<"3.Cable Flyes: 3 sets of 8-10 reps \n";
        cout<<"4. Front Raises: 3 sets of 10-12 reps \n";  
        
        }
        
        if(count == 6|| count == 13 || count == 20 || count == 27 )
        {
        
        cout<<"Day: "<<count<<" Legs, Abs, and Triceps\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Front Squats: 4 sets of 6-8 reps\n";
        cout<<"2. Lunges: 3 sets of 8-10 reps (each leg)\n";
        cout<<"3. Leg Curls: 3 sets of 8-10 reps \n";
        cout<<"4. Planks: 3 sets (hold for 30-60 seconds) \n";  
		cout<<"5. Skull Crushers: 3 sets of 10-12 reps \n";   
        }
        
        if(count == 7|| count == 14 || count == 21 || count == 28 )
        {
         cout<<"Day: "<<count<<" Rest\n\n";
        cout<<"Use this day for rest and recovery to prepare for the next cycle.\n";
        }
        
        cout << "\n\n\nDay " << count << " Diet Plan:\n\n";

        diet2(W);
}

void diet3(float W)
{
	int t=(W * 33);
	float protein= (W * 1.5);
	float carb=(0.5 * t);
	float fat=(0.25 * t);

	cout<<"Diet Plan:\n";
	cout<<"Calorie Intake for General Fitness (C_maintain) ="<< t<<"cal";
	cout<<"\nProtein Intake for General Fitness (P_ maintain) ="<< protein;
	cout<<"\nCarbohydrates for General Fitness (CHO_ maintain) ="<< carb;
	cout<<"\nFats for General Fitness (F_ maintain) ="<<fat ;
	
	cout<<"\nSuggested food items:\n";
	cout<<"Proteins: Lean meats (chicken, turkey), eggs, low-fat dairy products, tofu, legumes (lentils, chickpeas).";
	cout<<"\nCarbohydrates: Whole-grain bread, whole-grain pasta, brown rice, fruits (apples, pears), and vegetables (carrots, green beans).";
	cout<<"\nFats: Olive oil, nuts (almonds, peanuts), seeds (pumpkin, sunflower), avocados.\n\n";
	
}

void fitness3(int count, float W) 
{
       cout<<"WORKOUT PLAN FOR MAINTAINING FITNESS!!!! \n\n\n";
        if(count == 1 || count == 8 || count == 15 || count == 22 || count == 29)
        {
        cout<<"Day: "<<count<<" Full-Body Strength\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"1. Squats: 3 sets of 8-10 reps\n";
        cout<<"2. Push-Ups: 3 sets of 10-12 reps\n";
        cout<<"3. Bent Over Rows: 3 sets of 8-10 reps\n";
        cout<<"4. Planks: 3 sets (hold for 30-60 seconds)\n"; 
        }

        if(count == 2|| count == 9 || count == 16 || count == 23 || count == 30)
        {
        cout<<"Day: "<<count<<"Cardio and Core\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"1. Cardio: 20-30 minutes of moderate-intensity aerobic exercise (running, cycling, or using an elliptical).\n";
        cout<<"2. Planks: (3 sets, hold for 30-60 seconds)\n";
        cout<<"3. Russian Twists: (3 sets of 12-15 reps)\n";
        cout<<"4. Leg Raises: (3 sets of 12-15 reps)\n";     
        
        }
        if(count == 3|| count == 10 || count == 17 || count == 24)
        {
        cout<<"Day: "<<count<<" Active Recovery\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"1. Light to moderate-intensity activity like walking, swimming, or yoga\n";
        cout<<"2. Stretching and mobility exercises\n";
        }

        if(count == 4|| count == 11 || count == 18 || count == 25)
        {
        cout<<"Day: "<<count<<" Cardio Intervals\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"Cardio: 30-40 minutes of interval training (alternating between high-intensity and low-intensity periods). Choose your preferred cardio activity (running, cycling, or swimming).\n";
        }

        if(count == 5|| count == 12|| count == 19 || count == 26 )
        {
        
        cout<<"Day: "<<count<<" Full-Body Strength\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"1. Deadlifts: 3 sets of 6-8 reps\n";
        cout<<"2. Bench Press: 3 sets of 8-10 reps\n";
        cout<<"3. Pull-Ups: 3 sets of 6-8 reps \n";
        cout<<"4. Dumbbell Shoulder Press: 3 sets of 8-10 reps \n";  
        }
        
        if(count == 6|| count == 13 || count == 20 || count == 27 )
        {
        
        cout<<"Day: "<<count<<" Cardio and Core\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"1. Cardio: 20-30 minutes of steady-state cardio.\n";
        cout<<"2. Planks: (3 sets, hold for 30-60 seconds)\n";
        cout<<"3. Russian Twists: (3 sets of 12-15 reps) \n";
        cout<<"4. Leg Raises: (3 sets of 12-15 reps) \n";  
        }
        
        if(count == 7|| count == 14 || count == 21 || count == 28 )
        {
         cout<<"Day: "<<count<<" Rest\n\n";
        cout<<"Use this day for complete rest and recovery to allow your body to recuperate.\n";
        }
        
        cout << "\n\n\nDay " << count << " Diet Plan:\n\n";

        diet3(W);
}

void fitness()
{
	cout<<"displaying fitness tips..."<<endl;
	int day_count,c;
    float weight;

    cout << "Enter the day count: ";
    cin >> day_count;

    cout << "Enter your weight (in kg): ";
    cin >> weight;
    
    cout<<"\nChoices:";
    cout<<"\n1.weightloss\n2.muscle building\n3.maintain\n";
    cin>>c;
    switch(c)
    {case 1:
    	fitness1(day_count, weight);
    	break;
    case 2:
    	fitness2(day_count, weight);
    	break;
    case 3:
    	fitness3(day_count, weight);
    	break;
	}
	
}
};
     void fnmanage()
    {
		while(true)
    	{
    	system("cls");
    	int option;
    	cout<<"\t***********************************************";
    	cout<<"\n\tPress 1 to CREATE MEMBER";
    	cout<<"\n\tPress 2 to DISPLAY ALL RECORDS";
    	cout<<"\n\tPress 3 to SEARCH FOR A PARTICULAR RECORD ";
    	cout<<"\n\tPress 4 to EDIT MEMBER DETAILS";
    	cout<<"\n\tPress 5 to DELETE MEMBER";
    	cout<<"\n\tPress 6 to LOGOUT";
    	cout<<"\n\t**********************************************";
    	cout<<"\n\n\tOption: ";
    	cin>>option;
    	switch(option)
    	{
    		case 1: system("cls");
    				s2.save_member();
    				break;
    				
    		case 2: s2.show_all();
    				system("cls"); 
    				break;
    				
    		case 3:
    				int num;
   				system("cls"); 
    				s2.display_record();
    				system("cls");
    				break;
    				
    		case 4: s2.edit_member();
    				system("cls");
    			break;
    		
    		case 5: s2.delete_member();
    				system("cls");
    		        break;
   				
    		case 6:return;    		
    		default:cout<<"invalid option please try again";
    		}
    	}
    }

    
void user_record()
{	
	while(true)
	{
	int m;
	cout<<"\n*******************************\n";
	cout<<"1.Quit gym\n2.Edit your profile\n3.Fitness recommendations\n4.Display record\n5.Logout\n";
	cout<<"\n*******************************\n";
	cout<<endl<<"Enter your choice"<<endl;
	cin>>m;
	switch(m)
	{
    		case 1:s1.delete_member();
    				system("cls"); 
    		        break;
    		case 2:s1.edit_member();
    				system("cls"); 
    		       break;
    		case 3:fnd f;
    				system("cls");
					f.fitness();
					cout<<"Press any key to continue...";
					getch();
					system("cls"); 
    				break;
    		case 4: int num;
   				system("cls"); 
    				s1.display_record();
    				system("cls"); 
    				break;
    		case 5:return;
	}
}
}

int main()
{		

int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Set window size
    initwindow(1280, 720, "Gym Management and Fitness Suggestion System");
	int x, y, i,k,z;
	
		
	
		
		a:
		
		drawLandingPage();
		i = handleLandingPageClick(x ,y);

			if(i==1)
            {
            
				cleardevice(); 
				
				drawLoginPopup();
				
				
				z = handleLoginPopup(x, y);
				
			}
			
			
                //cout<<endl<<"\n\t\tYou're in user mode"<<endl;
                //cout<<"\t\t*******************";
                
                
                b:
                //cout<<endl<<"\n\t\t1.register\n\t\t2.login\n\n\t\t";
                
                if(z==1)
				{
				s1.save_member();
				goto a;
			}
				if(z==2)
				{
					s1.log();
					goto a;
			}
			
			if(i==2)
            {
            	system("cls"); 
                cout<<endl<<"\t\tYou're in admin mode"<<endl;	
                cout<<"\t\t********************";
					alogin ad;
					k=ad.adlogin();
					if(k==1)
					{
						fnmanage();
						goto a;
					}
					else
					{
						cout<<"you cannot access manageral details!";
						cout<<"\t\tpress any key to continue";
						getch();
					}
					}
			if(i==3)
			{
				exit(1);
			}
		

			getch();
			closegraph(); 
		return 0;

}



