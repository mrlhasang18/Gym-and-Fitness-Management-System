#ifndef HANDLECLICKS
#define HANDLECLICKS
#include <graphics.h>
#include "CAPTUREINPUTS.h"
#include "DRAWPAGES.h"


std::string username, u_pass, u_contact, u_num, log_num, log_pass, DAYcount, W8, Admin_str, Pw_str, Mem_Del, Admin_E, dis_num;
int time_slut, Subs_click; 


// Function to check if click is within the button bounds
bool isClickInBounds(int x, int y, int left, int top, int right, int bottom) {
    return (x >= left && x <= right && y >= top && y <= bottom);
}



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
        
        
        Subs_click = 2; 
        drawGymTimeSelect();
        handleGymTimeSelect(x, y);
        break; 
        
    }
    else if (isClickInBounds(x, y, 720, 642, 1059, 683) ){
        cleardevice();
        
        Subs_click = 1; 
        
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
				        //currentPage = LOGIN_USER;
				        //cleardevice();
				        //drawLoginForm();
						return 10; 
				    }
				     if (isClickInBounds(x, y, 1004, 666, 1003+108, 668+15)) 
					{
				        //currentPage = ADMIN_LOG;
				        //cleardevice();
				        return 20;
				    } 
					if (isClickInBounds(x, y, 200, 400, 400, 430)) {
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
		//currentPage == LOGIN_USER; 
		return 2;

	}
	else if(isClickInBounds(x, y, 435, 576, 435+398, 576+48)){
	
	
		cleardevice(); 
		//drawSignUpPage(); 
			//currentPage == SIGN_UP;
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
            
	
    if(isClickInBounds(x,y,209, 338, 209+292, 338+45))
	{ 
	
	captureMemberNumber(209, 338, 209+292, 338+45, log_num);
    
    
	}
	else if (isClickInBounds(x,y, 209, 432, 209+292, 432+45))
	{ 
	
	 capturePasswordInput(209, 432, 209+292, 432+45, log_pass);
	 
	}
	else if(isClickInBounds(x,y, 208, 527, 208+293, 527+38))
	 {
	 	
	 	break;
	 }
}
};

}


//**********************************************************************************************



//**********************************************************************************************


//**********************************************************************************************

int handleUserMenu( int x, int y){ 

	while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);

if(isClickInBounds(x, y, 139, 252, 139+216 ,252+216)){ 

//cleardevice();
//drawUserEdit(); 
//currentPage = USER_EDIT;
return 2; 
}
else if(isClickInBounds(x, y, 415, 252, 415+216, 252+216)){
	

	//cleardevice(); 
    //drawDietSuggestion(); 
	//currentPage = DIET_SUGGESTION;
	return 3; 
	
}
else if(isClickInBounds(x, y, 692, 252, 692+216, 252+216) ){
	
	//cleardevice();
	//drawUserRecords();
	//currentPage = USER_RECORDS;
	return 4; 
	
	
}
else if(isClickInBounds(x,y, 969, 252, 969+216, 252+216)){ 


//cleardevice(); 
//drawUserQuit();
//currentPage = USER_QUIT; 
return 1; 
}
else if(isClickInBounds(x,y, 867, 626, 867+340, 626+43)){ 

return 5; 
}
}
}
}

//***************************************************************************************
 
int handleAdminLogin( int x, int y){ 

while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);


 
  if (isClickInBounds(x, y, 209, 338, 209+292, 338+45) ){
        
        
        captureAdminName(209, 338, 209+292, 338+45, Admin_str);
        
        // drawAdminMenu();
        //currentPage = ADMIN_MENU;
      
    }
    else if(isClickInBounds(x, y, 209, 432, 209+292, 432+45)){
		
    	captureAdminPassword( 209, 432, 209+292, 432+45, Pw_str);
    	
		//drawLoginForm();
		//currentPage = LOGIN_USER; 
    	
	}
	else if(isClickInBounds(x,y, 208, 526, 208+293,526+38)){
		
	break;
	}
} 
}

}


//*****************************************************************************************************

int handleAdminMenu(int x, int y){ 

while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);

	
	if(isClickInBounds(x, y, 151, 170, 151+216, 170+216)){ 
	
	return 1; 
	
	//drawAddMember(); 
	
	//currentPage == ADD_MEMBER; 
	
	}
	
	else if(isClickInBounds(x, y, 523, 170, 523+216, 170+216)){ 
	
	return 2;  
	
	//drawAdminRecords(); 
	
	//currentPage == ADMIN_RECORDS; 
	
	}
	else if(isClickInBounds(x, y, 895, 170, 895+216, 170+216)){ 
	
	return 5; 
	
	//drawDeleteMember(); 
	
	//currentPage == DELETE_MEMBER; 
	
	}
	
	else if(isClickInBounds(x,y, 151, 432, 151+216, 432+216)){ 
	
	return 4; 
	
	//drawEditMember(); 
	
//currentPage == EDIT_MEMBER; 
	
	}
	else if(isClickInBounds(x, y, 523, 432, 523+216, 432+216)){ 
	
	return 3; 
	
	//drawSearchRecords(); 
	
	//currentPage == ADMIN_SEARCH; 
	
	}
	else if(isClickInBounds(x,y, 833, 605, 833+340, 605+42)){ 
	
	return 6; 
	
	//drawLoginForm(); 
	
	//currentPage == LOGIN_USER; 
	}
} 
}
}
//*****************************************************************************************************

int handleMemberDeleteNum(int x, int y){

while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);

	
	if(isClickInBounds(x, y, 487, 499, 487+304, 499+64)){ 
	
	captureDeleteMemberNum(487, 499, 487+304, 499+64, Mem_Del);
	
}
else if(isClickInBounds(x,y, 523, 588, 523+233, 588+44)){ 
	
	break;
} 

} 
} 
} 



//*****************************************************************************************************

int handleAdminEdit(int x, int y){ 

while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);

	
	if(isClickInBounds(x, y, 487, 499, 487+304, 499+64)){ 
	
	captureAdminEdit(487, 499, 487+304, 499+64, Admin_E);
	
}
else if(isClickInBounds(x,y, 523, 588, 523+233, 588+44)){ 
	
	break;
} 

} 
} 
} 

//******************************************************************************************************


int handleAdminSearch(int x, int y){ 

while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);

	
	if(isClickInBounds(x, y, 487, 499, 487+304, 499+64)){ 
	
	captureAdminSearch(487, 499, 487+304, 499+64, dis_num);
	
}
else if(isClickInBounds(x,y, 523, 588, 523+233, 588+44)){ 
	
	break;
} 

} 
} 
} 
//******************************************************************************************************
void handleUserEdit(int x, int y){ 


}


//*****************************************************************************************************


void handleDietSuggestion(int x, int y){ 

	while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);
            
            

if(isClickInBounds(x, y, 633, 292, 633+165, 292+53)){ 

captureDayCountInput(636, 294, 633+165, 292+51, DAYcount);
	
//cleardevice(); 
	
	}
	
	else if(isClickInBounds(x, y, 622, 378, 622+188, 378+53)){ 
	
captureWeightInput(622, 378, 622+188, 378+53, W8);

	
	}
 else if(isClickInBounds(x,y, 497, 555, 497+302, 555+42)){ 
 
 break; 
 }

}
}
}

//*****************************************************************************************************

int handleDietSuggestion2(int x, int y)
{ 

	while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);
            
            

if(isClickInBounds(x, y, 131, 323, 131+278, 323+278)){ 
return 1; 	
}
	
else if(isClickInBounds(x, y, 501, 323, 501+278, 323+278)){ 
return 2;
}
 
else if(isClickInBounds(x,y, 870, 323, 870+278, 323+278)){ 

return 3; 

}

}
}


}

//*****************************************************************************************************


int handleUserRecords(int x, int y) { 

while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);
            
            
if(isClickInBounds(x, y, 928, 551, 928+209, 551+52)){ 


return 1; 
	
	}

}
};
}


//*****************************************************************************************************

void handleEntireScreenClick(int x, int y){ 

while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            getmouseclick(WM_LBUTTONDOWN, x, y);
            
            
if(isClickInBounds(x, y, 0, 0, 1280, 720)){ 


break; 
	
	}

}
};


}
void handleUserQuit(int x, int y){ 


}




#endif
