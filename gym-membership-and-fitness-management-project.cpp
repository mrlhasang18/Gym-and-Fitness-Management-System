#include<fstream>
#include<iomanip>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<graphics.h>
#include<string>
#include "CAPTUREINPUTS.h"
#include "DRAWPAGES.h"
#include "HANDLECLICKS.h"
#include "sqlite_connectivity.h"
#include "diet_database.h"

using namespace std;

void handleRegistrationThanks(int x, int y);
void drawGymTimeSelect(); 



enum Page { LANDING, LOGIN_USER, ADMIN_LOG, SIGN_UP , SUBSCRIPTION, GYMTIME_SELECT, THANK_YOU, 
			USER_MENU, USER_EDIT, DIET_SUGGESTION, USER_RECORDS, USER_QUIT, 
			ADMIN_MENU, ADD_MEMBER, DELETE_MEMBER, ADMIN_RECORDS, ADMIN_SEARCH, EDIT_MEMBER};

Page currentPage = LANDING;

//std::string username, u_pass, u_contact, u_num;
//int time_slut, Subs_click; 

//***************************************************************************


//***************************************************************************************
//BELOW THIS ARE THE FUNCTIONS THAT CONTROL THE BUTTON CLICKS
//    			 ||
//    		     ||
//    			 ||
//   			\  /
//    			 \/    
//****************************************************************************************







void user_record();
void fnmanage();


class alogin
{

	
	char admin[10]; 
	char pw[10];
	char a[10], p[10]; 
	

	public:	
	alogin(){ 
	
	strcpy(a, "admin"); 
	strcpy(p, "hello");
	
	}


	int adlogin()
	{
		int click_x, click_y; 
		
		click_x = 0; 
		click_y = 0; 
		
		cleardevice(); 
		drawAdminLogin(); 
		
		handleAdminLogin(click_x, click_y); 
		
		strncpy(admin, Admin_str.c_str(), sizeof(admin) - 1);
    	admin[sizeof(admin) - 1] = '\0';
    	
    	
    	
    	strncpy(pw, Pw_str.c_str(), sizeof(pw) - 1);
    	pw[sizeof(pw) - 1] = '\0';
    	
    	
    	
		//strcpy(admin, Admin_str); 
		//strcpy(pw, Pw_str);
		 
	
		
		if (strcmp(admin, a) == 0 && strcmp(pw, p) == 0) {
			
			return 1; 
			 
		}
		else{ 
		return 0;
		}
}
/*		if(admin=="admin")
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
	int getadpassword();*/
};	
/*int alogin::getadpassword()
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
*/
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
    	char alt_num[50];
    		
    		//fflush(stdin);
    		//cout<<endl<<"Please Enter The member Number: ";
    		
    		cleardevice(); 
    		drawSignUpPage();
    	
			int click_x = 0; // Replace with actual x coordinate
    		int click_y = 0; // Replace with actual y coordinate
    	
		    k = handleSignUpPageClick(click_x, click_y);
		    
		    strncpy(alt_num, u_num.c_str(), sizeof(alt_num) - 1);
    		alt_num[sizeof(alt_num) - 1] = '\0';  // Ensure null termination
    		
    		member_number = stringToInt(alt_num);
    		
    		cout<<member_number; 
    		
    	
    			 
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
    		
    		//cleardevice(); 
    		//drawUserMenu();
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
    		int click_x, click_y, clx;
    		click_x = 0; 
    		click_y = 0;
    		
    	do{
			
    		cleardevice();
    		drawUserRecords(); 
    		
    		
    		setbkcolor(WHITE); 
    		setcolor(BLACK);
    		
    		settextstyle(8, HORIZ_DIR, 2);
    		
    		
    		string member_number_str = to_string(member_number);
    		string fee_str = to_string(fee);
    		
    		outtextxy(640+5, 330+15, (char *)member_number_str.c_str());
   			outtextxy(640+5, 220+15, (char *)std::string(mem_name).c_str());
    		outtextxy(640+5, 441+15, (char *)std::string(classs).c_str());
    		
    		outtextxy(908+5, 330+15, (char *)std::string(contact).c_str());
    		outtextxy(908+5, 441+15, (char *)std::string(timings).c_str());
    		outtextxy(640+5, 552+15, (char *)fee_str.c_str());
    		
    		
    		
    		clx = handleUserRecords(click_x, click_y);
    		
    }while(clx != 1); 
    exit; 
    		
    	/*	cout<<endl<<"member code: "<<member_number;
    		cout<<endl<<"Name: "<<mem_name;
    		cout<<endl<<"category: "<<classs;
    		cout<<endl<<"fee: "<<fee;
    		cout<<endl<<"contact: "<<contact;
    		cout<<endl<<"timings: "<<timings<<endl;*/
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
		char memberNumber[3];
		
		int click_x = 0; // Replace with actual x coordinate
    	int click_y = 0; // Replace with actual y coordinate
		
		system("cls");
    	cleardevice();
		drawLoginForm(); 
		handleLoginPageClick(click_x, click_y);
		
		
		strncpy(memberNumber, log_num.c_str(), sizeof(memberNumber) - 1);
    	memberNumber[sizeof(memberNumber) - 1] = '\0';
		
		num = stringToInt(memberNumber);
		
		strncpy(p, log_pass.c_str(), sizeof(p) - 1);
    	p[sizeof(p) - 1] = '\0';
    	
    	 
    	//cin>>num;
    	//cout<<endl<<"Please enter the password:";
    	//cin>>p;
    	
    	
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
		{
			
		drawinvalidcred(); 
		
		delay(5000);
	    fp.close();
		}
	return;
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
    	{		
    	cleardevice(); 
    	drawNoUser(); 
    	getch();
    }
    	
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
    	cleardevice(); 
        drawUserDeleteComplete(); 
        delay(2000);
        
    	fp2.close();
    	fp.close();
    	remove("hamro.bin");
    	rename("timro.bin","hamro.bin");
		exit;      
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
    	//cout<<endl<<endl<<"the member has been succesfully added...";
    	fflush(stdin);
    }
    void show_all()
    {
    	system("cls");
    	bool found=false;
    	//cout<<endl<<"\t\tRECORDS...";
    	fp.open("hamro.bin",ios::in);
    	while(fp.read((char*)&m1,sizeof(m1)))
    	{
    	m1.show_mem();
    	fflush(stdin);
    	found=true;
    	}
    	fp.close();
    	if(found == false)
    	{
		cout<<"\n\nNo record found";
		} 
		
    	//cout<<"\npress any key to continue";
    	getch();
    }
     void display_record()
    {	
	
	int num;
    int click_x, click_y; 
    
    char Dis_Num[10];
    click_x = 0; 
    click_y = 0; 
    
    
    cleardevice(); 
    drawAdminSearch(); 
    handleAdminSearch(click_x, click_y); 
    
    strncpy(Dis_Num, dis_num.c_str(), sizeof(Dis_Num) - 1);
    Dis_Num[sizeof(Dis_Num) - 1] = '\0';
		
	num = stringToInt(Dis_Num);
    
    
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
    	
    	//cout<<"press any key to continue\n";
    	//getch();
    	
    }

    void delete_member(int num = 0)
    {
    	
    	int click_x, click_y;
    	char Member_Del[10];
    	click_x = 0;
    	click_y = 0;
    	
    	system("cls");
        if(num == 0 )
        {
        	
        	cleardevice(); 
        	drawDeleteMemberNum(); 
        	
        num = handleMemberDeleteNum(click_x, click_y);
        
        strncpy(Member_Del, Mem_Del.c_str(), sizeof(Member_Del) - 1);
    	Member_Del[sizeof(Member_Del) - 1] = '\0';
        
        
        num = stringToInt(Member_Del);
        
        
        //cout<<endl<<endl<<"Please Enter The member number: ";
    	//cin>>num;
        
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
    	
    	drawUserDeleteComplete(); 
    	delay(1000);
    	
    	//cout<<endl<<endl<<"\tRecord Deleted..."; 
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

        //cout<<"press any key to continue\n";
    	getch();
        }
    }
   void edit_member()
    {
    	int num;
    	char ch = 'T'; // intilized
    	char Member_Edit[10];
    	int click_x, click_y; 
    	
    	click_x = 0; 
    	click_y = 0;
    			
		cleardevice(); 
		
        drawAdminEdit(); 
        	
        num = handleAdminEdit(click_x, click_y);
        
        strncpy(Member_Edit, Admin_E.c_str(), sizeof(Member_Edit) - 1);
    	Member_Edit[sizeof(Member_Edit) - 1] = '\0';
        
        
        num = stringToInt(Member_Edit);
        
	
    	
    	
    	fp.open("hamro.bin", ios::app | ios::in | ios::binary);
        fp.seekg(0,ios::beg);
    	while(fp.read((char*)&m1,sizeof(m1)) && ch == 'T')
    	{
    		if(m1.getmem()==num) // entre only if user's i/p no. matches
    		{
    			m1.show_mem();
    			//cout<<"\nPlease Enter The New details of the member: "<<endl;
    			m1.create_mem();
    			int pos=1*sizeof(m1);
    			fp.seekp(pos,ios::cur);
    			fp.write((char*)&m1,sizeof(m1));
    			//cout<<endl<<endl<<"\t Record Successfully Updated...";
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
        
        const char *db_name = "test_database.db;";
        
        access_diet1_data(db_name);
    	
    	
        string CAL_str = to_string(t);
        string P_str = to_string(protein);
        string C_str = to_string(carb);
        string F_str = to_string(fat);
        
        setcolor(BLACK);
        
        
        outtextxy(445, 600, (char *)CAL_str.c_str());
        outtextxy(445, 652, (char *)P_str.c_str());
        outtextxy(858, 600, (char *)C_str.c_str());
        outtextxy(858, 652, (char *)F_str.c_str());
        
        

       // cout << "Calorie Intake for Fat Loss (C_fat_loss) = " << t << " cal\n";
       // cout << "Protein Intake for Fat Loss (P_fat_loss) = " << protein << " g\n";
       // cout << "Carbohydrates for Fat Loss (CHO_fat_loss) = " << carb << " g\n";
       // cout << "Fats for Fat Loss (F_fat_loss) = " << fat << " g\n"; 

       // cout << "\nSuggested food items:\n";
       // cout << " Proteins: Chicken breast, turkey, lean beef, tofu, fish (salmon, tuna), Greek yogurt, cottage cheese.\n";
       // cout << " Carbohydrates: Brown rice, quinoa, sweet potatoes, whole-grain pasta, oats, beans, legumes, and leafy greens.\n";
       // cout << " Fats: Avocado, nuts (almonds, walnuts), seeds (chia, flax), olive oil, fatty fish (salmon, mackerel).\n\n";
       int click_x, click_y; 
       
       click_x = 0; click_y = 0;
       
       handleEntireScreenClick(click_x, click_y);
       
    }
    
void fitness1(int count, float W) 
{
        //cout << "WORKOUT AND DIET PLAN FOR WEIGHT LOSS!!!! \n\n\n";
        const char *db_name = "test_database.db;";
        
        cleardevice(); 
        drawFitness1();
        

        //cout << "Day " << count << " Workout Plan:\n\n";

        if (count == 1 || count == 8 || count == 15 || count == 22 || count == 29) {
        	
        	access_Fitness1_data(db_name, 1);
        	
        	
            /*cout << "Day: " << count << " Upper Body\n\n";

            cout << "#. INSTRUCTION: \n";
            cout << "Pick a weight that leads you to failure at end of 15 rep\n";
            cout << "Do each exercise of 3 sets of 15 reps\n";
            cout << "Take rest of (20 - 30) sec after each set\n\n\n";

            cout << "#. Workout:\n";
            cout << "1. DB Bench Press\n";
            cout << "2. DB Row\n";
            cout << "3. DB Shoulder Press\n";
            cout << "4. Reverse Crunch\n";*/
        }

        if(count == 2|| count == 9 || count == 16 || count == 23 || count == 30)
        {
        	
        access_Fitness1_data(db_name, 2);	
        /*cout<<"Day: "<<count<<" Lower Body\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Pick a weight that leads you to failure at end of 15 rep\n";
        cout<<"Do each exercise of 3 set of 15 reps\n";
        cout<<"Take rest of (20 - 30)sec after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Goblet Squat\n";
        cout<<"2. DB Romanian Deadlift\n";
        cout<<"3. DB Calf Raises\n";
        cout<<"4. Weighted Crunch\n";     */
        
        }
        if(count == 3|| count == 10 || count == 17 || count == 24)
        {
        	
        access_Fitness1_data(db_name, 3);
        /*cout<<"Day: "<<count<<" Full Body\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Pick a weight that leads you to failure at end of 15 rep\n";
        cout<<"Do each exercise of 3 set of 15 reps\n";
        cout<<"Take rest of (20 - 30)sec after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Reverse Lunges\n";
        cout<<"2. Push Up\n";
        cout<<"3. DB Facepull \n";
        cout<<"4. Plank: 30sec hold \n";  */   
       
        }

        if(count == 4|| count == 11 || count == 18 || count == 25)
        {
        cout<<"Day: "<<count<<" Rest\n\n";
        cout<<"Rest: where strength finds its quiet power.\n";
        }

        if(count == 5|| count == 12|| count == 19 || count == 26 )
        {
        access_Fitness1_data(db_name, 4);
        /*cout<<"Day: "<<count<<" Upper Body\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Pick a weight that leads you to failure at end of 15 rep\n";
        cout<<"Do each exercise of 3 set of 15 reps\n";
        cout<<"Take rest of (20 - 30)sec after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. DB Bench Press\n";
        cout<<"2. DB Row\n";
        cout<<"3. DB Shoulder Press\n";
        cout<<"4. Reverse Crunch\n"; */
        
        }
        
        if(count == 6|| count == 13 || count == 20 || count == 27 )
        {
        access_Fitness1_data(db_name, 5);
        /*cout<<"Day: "<<count<<" Lower Body\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Pick a weight that leads you to failure at end of 15 rep\n";
        cout<<"Do each exercise of 3 set of 15 reps\n";
        cout<<"Take rest of (20 - 30)sec after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Goblet Squat\n";
        cout<<"2. DB Romanian Deadlift\n";
        cout<<"3. DB Calf Raises\n";
        cout<<"4. Weighted Crunch\n";*/
        }
        
        if(count == 7|| count == 14 || count == 21 || count == 28 )
        {
        cout<<"Day: "<<count<<" Rest\n\n";
        cout<<"Rest: where strength finds its quiet power.\n";
        }

        //cout << "\n\n\nDay " << count << " Diet Plan:\n\n";

        diet1(W);
    }


void diet2(float W)
{
	int t=(W * 45);
	float protein= (W * 2.2);
	float carb= 0.45 * t;
	float fat=0.25 * t;
	
	const char *db_name = "test_database.db;";
        
    access_diet2_data(db_name);
	
	string CAL_str = to_string(t);
        string P_str = to_string(protein);
        string C_str = to_string(carb);
        string F_str = to_string(fat);
        
        setcolor(BLACK);
        
        
        outtextxy(445, 600, (char *)CAL_str.c_str());
        outtextxy(445, 652, (char *)P_str.c_str());
        outtextxy(858, 600, (char *)C_str.c_str());
        outtextxy(858, 652, (char *)F_str.c_str());
        
        
        
        int click_x, click_y; 
       
       click_x = 0; click_y = 0;
       
       handleEntireScreenClick(click_x, click_y);
        
        

/*	cout<<"Diet Plan:\n";
	cout<<"Calorie Intake for Muscle Building (C_muscle_building) ="<<t <<"cal\n";
	cout<<"Protein Intake for Muscle Building (P_muscle_building) ="<< protein ;
	cout<<"\nCarbohydrates for Muscle Building (CHO_muscle_building) ="<< carb;
	cout<<"\nFats for Muscle Building (F_muscle_building) =" <<fat;

	cout<<"\nSuggested food items:\n";
	cout<<"Proteins: Lean meats (chicken, turkey, beef), eggs, dairy products (Greek yogurt, milk), fish, tofu, tempeh.";
	cout<<"\nCarbohydrates: Whole-grain bread, brown rice, quinoa, sweet potatoes, oats, fruits (bananas, berries), and vegetables (broccoli, spinach).";
	cout<<"\nFats: Avocado, nuts (almonds, cashews), seeds (flax, chia), olive oil, fatty fish (salmon, mackerel).\n\n";*/
		
}

void fitness2(int count, float W) 
{
	const char *db_name = "test_database.db;";
	
	cleardevice(); 
    drawFitness1();
    
    
	//cout<<"WORKOUT PLAN FOR MUSCLE BUILDING!!!! \n\n\n";
        if(count == 1 || count == 8 || count == 15 || count == 22 || count == 29)
        {
        	
        access_Fitness2_data(db_name, 1);
        /*cout<<"Day: "<<count<<" Back and Biceps\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";
        cout<<"#. Workout:\n";++
        cout<<"1. Deadlifts: 4 sets of 6-8 reps\n";
        cout<<"2. Pull-Ups: 3 sets of 8-10 reps\n";
        cout<<"3. Pull-Ups: 3 sets of 8-10 reps\n";
        cout<<"4. Barbell Bicep Curls: 3 sets of 10-12 reps\n"; */
        }

        if(count == 2|| count == 9 || count == 16 || count == 23 || count == 30)
        {
        	
        access_Fitness2_data(db_name, 2);
        /*cout<<"Day: "<<count<<" Chest and Shoulders\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Bench Press: 4 sets of 6-8 reps\n";
        cout<<"2. Dumbbell Shoulder Press: 3 sets of 8-10 reps\n";
        cout<<"3. Incline Dumbbell Press: 3 sets of 8-10 reps\n";
        cout<<"4. Lateral Raises: 3 sets of 10-12 reps\n";    */ 
        
        }
        if(count == 3|| count == 10 || count == 17 || count == 24)
        {
        	
        access_Fitness2_data(db_name, 3);
        /*cout<<"Day: "<<count<<" Legs, Abs, and Triceps\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Squats: 4 sets of 6-8 reps\n";
        cout<<"2. Leg Press: 3 sets of 8-10 reps\n";
        cout<<"3. Romanian Deadlifts: 3 sets of 8-10 reps \n";
        cout<<"4. Hanging Leg Raises: 3 sets of 10-12 reps \n";  
		cout<<"5. Tricep Dips: 3 sets of 10-12 reps \n" ; */
       
        }

        if(count == 4|| count == 11 || count == 18 || count == 25)
        {
        	
        access_Fitness2_data(db_name, 4);
        /*cout<<"Day: "<<count<<" Back and Biceps\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Pull-Ups: 4 sets of 6-8 reps\n";
        cout<<"2. Barbell Rows: 3 sets of 8-10 reps\n";
        cout<<"3. Lat Pulldowns: 3 sets of 8-10 reps \n";
        cout<<"4. Hammer Curls: 3 sets of 10-12 reps\n";  */
       
        }

        if(count == 5|| count == 12|| count == 19 || count == 26 )
        {
        
        access_Fitness2_data(db_name, 5);
        /*cout<<"Day: "<<count<<" Chest and Shoulders\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Incline Bench Press: 4 sets of 6-8 reps\n";
        cout<<"2. Seated Dumbbell Shoulder Press: 3 sets of 8-10 reps\n";
        cout<<"3.Cable Flyes: 3 sets of 8-10 reps \n";
        cout<<"4. Front Raises: 3 sets of 10-12 reps \n";  */
        
        }
        
        if(count == 6|| count == 13 || count == 20 || count == 27 )
        {
        access_Fitness2_data(db_name, 6);
        /*cout<<"Day: "<<count<<" Legs, Abs, and Triceps\n\n";
        
        cout<<"#. INSTRUCTION: \n";
        cout<<"Take rest of full 3 min after each set\n\n\n";

        cout<<"#. Workout:\n";
        cout<<"1. Front Squats: 4 sets of 6-8 reps\n";
        cout<<"2. Lunges: 3 sets of 8-10 reps (each leg)\n";
        cout<<"3. Leg Curls: 3 sets of 8-10 reps \n";
        cout<<"4. Planks: 3 sets (hold for 30-60 seconds) \n";  
		cout<<"5. Skull Crushers: 3 sets of 10-12 reps \n"; */  
        }
        
        if(count == 7|| count == 14 || count == 21 || count == 28 )
        {
         cout<<"Day: "<<count<<" Rest\n\n";
        cout<<"Use this day for rest and recovery to prepare for the next cycle.\n";
        }
        
        //cout << "\n\n\nDay " << count << " Diet Plan:\n\n";

        diet2(W);
}

void diet3(float W)
{
	int t=(W * 33);
	float protein= (W * 1.5);
	float carb=(0.5 * t);
	float fat=(0.25 * t);
	
	const char *db_name = "test_database.db;";
        
    access_diet3_data(db_name);
	
	string CAL_str = to_string(t);
        string P_str = to_string(protein);
        string C_str = to_string(carb);
        string F_str = to_string(fat);
        
        
        
        setcolor(BLACK);
        
        
         outtextxy(445, 600, (char *)CAL_str.c_str());
        outtextxy(445, 652, (char *)P_str.c_str());
        outtextxy(858, 600, (char *)C_str.c_str());
        outtextxy(858, 652, (char *)F_str.c_str());
        

	/*cout<<"Diet Plan:\n";
	cout<<"Calorie Intake for General Fitness (C_maintain) ="<< t<<"cal";
	cout<<"\nProtein Intake for General Fitness (P_ maintain) ="<< protein;
	cout<<"\nCarbohydrates for General Fitness (CHO_ maintain) ="<< carb;
	cout<<"\nFats for General Fitness (F_ maintain) ="<<fat ;
	
	cout<<"\nSuggested food items:\n";
	cout<<"\nProteins: Lean meats (chicken, turkey), eggs, low-fat dairy products, tofu, legumes (lentils, chickpeas).";
	cout<<"\nCarbohydrates: Whole-grain bread, whole-grain pasta, brown rice, fruits (apples, pears), and vegetables (carrots, green beans).";
	cout<<"\nFats: Olive oil, nuts (almonds, peanuts), seeds (pumpkin, sunflower), avocados.\n\n";*/
	int click_x, click_y; 
       
    click_x = 0; click_y = 0;
       
    handleEntireScreenClick(click_x, click_y);
    
}

void fitness3(int count, float W) 
{
	const char *db_name = "test_database.db;";
	
	
	cleardevice(); 
    drawFitness1();
    
    
       //cout<<"WORKOUT PLAN FOR MAINTAINING FITNESS!!!! \n\n\n";
        if(count == 1 || count == 8 || count == 15 || count == 22 || count == 29)
        {
        	
        access_Fitness3_data(db_name, 1);
        /*cout<<"Day: "<<count<<" Full-Body Strength\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"1. Squats: 3 sets of 8-10 reps\n";
        cout<<"2. Push-Ups: 3 sets of 10-12 reps\n";
        cout<<"3. Bent Over Rows: 3 sets of 8-10 reps\n";
        cout<<"4. Planks: 3 sets (hold for 30-60 seconds)\n"; */
        }

        if(count == 2|| count == 9 || count == 16 || count == 23 || count == 30)
        {
        
		access_Fitness3_data(db_name, 2);
        /*cout<<"Day: "<<count<<"Cardio and Core\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"1. Cardio: 20-30 minutes of moderate-intensity aerobic exercise (running, cycling, or using an elliptical).\n";
        cout<<"2. Planks: (3 sets, hold for 30-60 seconds)\n";
        cout<<"3. Russian Twists: (3 sets of 12-15 reps)\n";
        cout<<"4. Leg Raises: (3 sets of 12-15 reps)\n";   */  
        
        }
        if(count == 3|| count == 10 || count == 17 || count == 24)
        {
        	
        access_Fitness3_data(db_name, 3);
        /*cout<<"Day: "<<count<<" Active Recovery\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"1. Light to moderate-intensity activity like walking, swimming, or yoga\n";
        cout<<"2. Stretching and mobility exercises\n";*/
        }

        if(count == 4|| count == 11 || count == 18 || count == 25)
        {
        
        access_Fitness3_data(db_name, 4);
        /*cout<<"Day: "<<count<<" Cardio Intervals\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"Cardio: 30-40 minutes of interval training (alternating between high-intensity and low-intensity periods). Choose your preferred cardio activity (running, cycling, or swimming).\n";
        */
        }

        if(count == 5|| count == 12|| count == 19 || count == 26 )
        {
        access_Fitness3_data(db_name, 5);
        /*cout<<"Day: "<<count<<" Full-Body Strength\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"1. Deadlifts: 3 sets of 6-8 reps\n";
        cout<<"2. Bench Press: 3 sets of 8-10 reps\n";
        cout<<"3. Pull-Ups: 3 sets of 6-8 reps \n";
        cout<<"4. Dumbbell Shoulder Press: 3 sets of 8-10 reps \n";  */
        }
        
        if(count == 6|| count == 13 || count == 20 || count == 27 )
        {
        access_Fitness3_data(db_name, 6);
        /*cout<<"Day: "<<count<<" Cardio and Core\n\n";
        
        cout<<"#. Workout:\n";
        cout<<"1. Cardio: 20-30 minutes of steady-state cardio.\n";
        cout<<"2. Planks: (3 sets, hold for 30-60 seconds)\n";
        cout<<"3. Russian Twists: (3 sets of 12-15 reps) \n";
        cout<<"4. Leg Raises: (3 sets of 12-15 reps) \n";  */
        }
        
        if(count == 7|| count == 14 || count == 21 || count == 28 )
        {
         cout<<"Day: "<<count<<" Rest\n\n";
        cout<<"Use this day for complete rest and recovery to allow your body to recuperate.\n";
        }
        
        //cout << "\n\n\nDay " << count << " Diet Plan:\n\n";

        diet3(W);
}

void fitness()
{
	int click_x; 
	int click_y; 
	click_x = 0; 
	click_y = 0; 
	char DAY_count[3];
	int day_count;
	int c;
	char W88[5];
    float weight;
    
    
	cleardevice(); 
	drawDietSuggestion();
	
	handleDietSuggestion(click_x, click_y); 
	
	strncpy(DAY_count, DAYcount.c_str(), sizeof(DAY_count) - 1);
    DAY_count[sizeof(DAY_count) - 1] = '\0';
	
	day_count = stringToInt(DAY_count);
	
	strncpy(W88, W8.c_str(), sizeof(W88) - 1);
    W88[sizeof(W88) - 1] = '\0';
	
	weight = stringToInt(W88);
	
	//cout<<"displaying fitness tips..."<<endl;
	

    //cout << "Enter the day count: ";
    //cin >> day_count;

    //cout << "Enter your weight (in kg): ";
    //cin >> weight;
    
    
    
    cleardevice(); 
    
    drawDietSuggestion2(); 
    
    c = handleDietSuggestion2(click_x, click_y); 
    
    
    
    
    
    
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
    	int click_x, click_y;
    	click_x = 0; 
    	click_y = 0; 
    	
		while(true)
    	{
    	system("cls");
    	int option;
    	/*cout<<"\t***********************************************";
    	cout<<"\n\tPress 1 to CREATE MEMBER";
    	cout<<"\n\tPress 2 to DISPLAY ALL RECORDS";
    	cout<<"\n\tPress 3 to SEARCH FOR A PARTICULAR RECORD ";
    	cout<<"\n\tPress 4 to EDIT MEMBER DETAILS";
    	cout<<"\n\tPress 5 to DELETE MEMBER";
    	cout<<"\n\tPress 6 to LOGOUT";
    	cout<<"\n\t**********************************************";
    	cout<<"\n\n\tOption: ";*/
    	drawAdminMenu(); 
    	option = handleAdminMenu(click_x, click_y); 
    	
    
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
    		
    		}
    	}
    }

    
void user_record()
{	
	while(true)
	{
	int m;
	int click_x = 0;
	int click_y = 0;
	//cleardevice(); 
	
	drawUserMenu();
	
	m = handleUserMenu(click_x,click_y); 
	
	//cleardevice();
	//getch(); 
	
	
//	cout<<"\n*******************************\n";
//	cout<<"1.Quit gym\n2.Edit your profile\n3.Fitness recommendations\n4.Display record\n5.Logout\n";
	//cout<<"\n*******************************\n";
	//cout<<endl<<"Enter your choice"<<endl;
	//cin>>m;
	
	switch(m)
	{
    		case 1:s1.delete_member();
    				system("cls"); 
    		        return;
    		case 2:s1.edit_member();
    				system("cls"); 
    		       break;
    		case 3: fnd f;
    				//system("cls");
					f.fitness();
					//cout<<"Press any key to continue...";
					//getch();
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

/*int main()
{		

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Set window size 
    initwindow(1280, 720, "Gym Management and Fitness Suggestion System");
	int x, y, i,k,z;
	
		
	const char* db_path = "test_database.db";
		
		a:
		
	
			
    
		
	drawLandingPage();
	check_sqlite_connectivity(db_path);
		
		i = handleLandingPageClick(x ,y);

			if(i==10)
            {
				cleardevice(); 
				drawLoginPopup();
				//circle(100,250,250);
				z = handleLoginPopup(x, y);	
			}
                //cout<<endl<<"\n\t\tYou're in user mode"<<endl;
                //cout<<"\t\t*******************";
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
			
			if(i==20)
            {
            	system("cls"); 
               // cout<<endl<<"\t\tYou're in admin mode"<<endl;	
               //cout<<"\t\t*****************admin***";
               getch();
					alogin ad;
					k=ad.adlogin();
					if(k==1)
					{
						fnmanage();
						exit;
					}
					else
					{
						
						cout<<"you cannot access manageral details!";
						cout<<"\t\tpress any key to continue";
						getch();
					}
					goto a; 
					}
			if(i==3)
			{
				exit(1);
			}
		

			getch();
			closegraph(); 
		return 0;

}

*/

int main() {		
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Set window size 
    initwindow(1280, 720, "Gym Management and Fitness Suggestion System");
	int x, y, i, k, z;

	const char* db_path = "test_database.db";

	while (true) {  // Loop continuously until the user chooses to exit
		cleardevice();  // Clear the screen for a fresh display

		drawLandingPage();
		check_sqlite_connectivity(db_path);
		i = handleLandingPageClick(x, y);

		if (i == 10) {  // User mode
			cleardevice();
			drawLoginPopup();
			z = handleLoginPopup(x, y);

			if (z == 1) {
				s1.save_member();
			} else if (z == 2) {
				s1.log();
				exit;
			} else {
				cout << "\nInvalid option\n";
			}

		} else if (i == 20) {  // Admin mode
			cleardevice();
			alogin ad;
			k = ad.adlogin();
			if (k == 1) {
				fnmanage();
			} else {
				cout << "You cannot access managerial details!";
				cout << "\t\tPress any key to continue";
				getch();
			}

		} else if (i == 3) {  // Exit
			closegraph();
			exit(0);  // Exit the program
		} else {
			cout << "\nInvalid input, please try again.\n";
		}
	}

	closegraph(); 
	return 0;
}


