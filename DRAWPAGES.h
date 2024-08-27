#ifndef DRAWPAGES
#define DRAWPAGES
#include <graphics.h>
void drawLoginPopup(){ 

	readimagefile("Images/Login_Popup.jpg", 0, 0,1280, 720); 

	setcolor(RED);

//	rectangle(435, 511, 435+398, 511+48);
//	rectangle(435, 576, 435+398, 576+48); 
} 

//***************************************************************************

void drawLandingPage() {
    
    
    readimagefile("Images/Landing_Page.jpg", 0, 0, 1280, 720);
    

}

//****************************************************************************

void drawLoginForm() {
	
    readimagefile("Images/User_Login.jpg", 00, 00, 1280, 720);
    
   	
}
//***************************************************************************************


void drawinvalidcred(){ 

readimagefile("Images/invalidcred.jpg", 0,0,1280,720); 



}

//***************************************************************************************


void drawSubscriptionPlan(){ 

readimagefile("Images/Subscription_Plan.jpg", 00, 00, 1280, 720);
//(221, 642, 560, 683);

//rectangle(720, 642, 1059, 683);


//Silver tier SIGNUP 221, 642, 560, 683
//GOLD tier SIGNUP 720, 642, 1059, 683


}


//***************************************************************************************

// Function to draw the login form
void drawSignUpPage() 
{
	
    readimagefile("Images/SIGN_UP.jpg", 0, 0, 1280, 720);
    
   /* rectangle(208, 286, 208+292, 286+45); 
    
    rectangle(207, 354, 207+292, 354+45); 
    
    rectangle(207, 423, 207+292, 423+45); 
    
    rectangle(207, 491, 207+292, 491+45);
    
    rectangle(208, 560, 207+292, 560+38); 
    */
}



//***************************************************************************************

void drawGymTimeSelect()
{ 

readimagefile("Images/Time_Select.jpg", 0,0, 1280, 720); 
/*
rectangle(355, 269, 548, 462);
rectangle(355+277, 269, 548+277, 462);
rectangle(355+277+277, 269, 548+277+277, 462); 

rectangle(355, 269+210, 548, 462+210);
rectangle(355+277, 269+210, 548+277, 462+210);
rectangle(355+277+277, 269+210, 548+277+277, 462+210); 
*/
}


//***************************************************************************************


void drawRegistrationThanks(){ 

readimagefile("Images/ThankYou.jpg", 0, 0, 1280, 720); 

}

//***************************************************************************************


void drawUserMenu(){ 

readimagefile("Images/UserMenu.jpg", 0, 0, 1280, 720); 

}


//***************************************************************************************


void drawAdminLogin(){ 

readimagefile("Images/ADMIN_LOG.jpg", 0, 0 , 1280, 720); 

/*
rectangle( 209, 338, 209+292, 338+45);

rectangle( 209, 432, 209+292, 432+45); 
*/

}

//***************************************************************************************

void drawAdminMenu(){ 

readimagefile("Images/ADMIN_MENU.jpg",0,0,1280,720); 

/*rectangle( 151, 170, 151+216, 170+216); 

rectangle( 523, 170, 523+216, 170+216); 

rectangle( 895, 170, 895+216, 170+216); 

rectangle( 151, 432, 151+216, 432+216); 

rectangle( 523, 432, 523+216, 432+216); 

rectangle(833, 605, 833+340, 605+42);

*/
}

//***************************************************************************************

void drawUserEdit(){ 

    readimagefile("Images/USER_EDIT.jpg", 0, 0, 1280, 720); 

}


//***************************************************************************************

void drawDietSuggestion1(){ 
    
    readimagefile("Images/DIET_SUGGESTION_1.jpg", 0,0, 1280, 720); 

}

//***************************************************************************************

void drawDietSuggestion2(){ 
    
    readimagefile("Images/DIET_SUGGESTION_2.jpg", 0,0, 1280, 720); 

}

//***************************************************************************************

void drawDietSuggestion3(){ 
    
    readimagefile("Images/DIET_SUGGESTION_3.jpg", 0,0, 1280, 720); 

}

//***************************************************************************************


void drawUserRecords(){ 

    readimagefile("Images/USER_RECORDS.jpg", 0, 0, 1280, 720); 

}


//***************************************************************************************


void drawUserQuit(){ 

    readimagefile("Images/USER_QUIT.jpg", 0, 0, 1280, 720); 

}


void drawNoUser(){ 

readimagefile("Images/NoUser.jpg",0,0,1280,720); 

}

void drawUserDeleteComplete(){ 

readimagefile("Images/User_Delete.jpg",0,0,1280,720); 

}

void drawDeleteMemberNum(){ 

readimagefile("Images/DeleteMemberNum.jpg", 0,0, 1280, 720);

}

void drawAdminEdit(){ 

readimagefile("Images/Admin_Edit.jpg", 0,0,1280,720); 


}

void drawAdminSearch(){ 

readimagefile("Images/Admin_Search.jpg", 0,0,1280,720); 
 
}

void drawConnectivityTrue(){ 

readimagefile("ConnectivityTrue.jpg", 42, 648, 92, 698);

}

void drawConnectivityFalse(){ 

readimagefile("ConnectivityFalse.jpg", 42, 648, 92, 698);

}

void drawFitnessPage(){ 

readimagefile("Images/Fitness_Page.jpg", 0, 0, 1280, 720); 



}

void drawFitnessPage2(){ 

cleardevice();

readimagefile("Images/Fitness_Page2.jpg", 0, 0, 1280, 720); 
}


void drawAdminInvalid()
{ 

cleardevice(); 

readimagefile("Images/Admin_Invalid.jpg",0,0,1280,720);

}

void drawNoRecords(){ 

cleardevice(); 

readimagefile("Images/NoUser.jpg", 0,0,1280,720);

}
#endif
