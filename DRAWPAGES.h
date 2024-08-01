#ifndef DRAWPAGES
#define DRAWPAGES
#include <graphics.h>
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


void drawinvalidcred(){ 

readimagefile("invalidcred.jpg", 265, 115, 265+750, 115+490); 



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

void drawDietSuggestion2(){ 
    
    readimagefile("DIET_SUGGESTION_2.jpg", 0,0, 1280, 720); 

}


//***************************************************************************************


void drawUserRecords(){ 

    readimagefile("USER_RECORDS.jpg", 0, 0, 1280, 720); 

}


//***************************************************************************************


void drawUserQuit(){ 

    readimagefile("USER_QUIT.jpg", 0, 0, 1280, 720); 

}


void drawNoUser(){ 

readimagefile("NoUser.jpg",0,0,1280,720); 

}

void drawUserDeleteComplete(){ 

readimagefile("User_Delete.jpg",0,0,1280,720); 

}

void drawDeleteMemberNum(){ 

readimagefile("DeleteMemberNum.jpg", 0,0, 1280, 720);

}

void drawAdminEdit(){ 

readimagefile("Admin_Edit.jpg", 0,0,1280,720); 


}

void drawAdminSearch(){ 

readimagefile("Admin_Search.jpg", 0,0,1280,720); 
 
}

void drawConnectivityTrue(){ 

readimagefile("ConnectivityTrue.jpg", 42, 648, 92, 698);

}

void drawConnectivityFalse(){ 

readimagefile("ConnectivityFalse.jpg", 42, 648, 92, 698);

}

void drawFitness1(){ 

readimagefile("Fitness1.jpg", 0, 0, 1280, 720); 

}

#endif
