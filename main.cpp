#include<conio.h>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<cstring>
#include<cstdlib>

//header files
#include "admin.h";
#include "user.h";
#include "registration_and_login.h";

using namespace std;

/*class alogin
{
	string admin;
	public:
	int adlogin()
	{
		cout<<"\t\tEnter the admin code"<<endl;
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
	cout<<"enter the password"<<endl;
	cin>>pw;
	if(pw=="Reenamaam")
	{
		cout<<"WELCOME!!"<<endl;
		return 1;
	}
	else
    {
		cout<<"entered password is incorrect"<<endl;
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
    	string password;
    	float fee;
    	
	long int contact;    	
    	public:
    void setn(int nn)
    {
    	member_number=nn;
	}
    int get_member_number()
    {	return(member_number);
	}
     string passw()
	 {
	 	return(password);
		}   
     int time_slots()
       {	
			int k;
			cout<<"please select your preferred timings\n press 1 for: morning 6-7\n press 2 for: morning 7-8\npress 3 for:morning 8-9\n";
			cout<<" press 4 for: evening 4-5\npress 5 for:evening 5-6\npress 6 for:evening 6-7\n";
			cin>>k;
			switch(k)
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
    	{	int k;
    		cout<<endl<<"Please Enter The member Number: ";
    		cin>>member_number;
    		cout<<endl<<"Please set The password:";
    		cin>>password;
    		cout<<endl<<"Please Enter The Name of The member: ";
    		
            fflush(stdin);
    		cin.getline(mem_name ,50);
    		cout<<endl<<"Please Enter The contact number: ";
    		cin>>contact;
    		cout<<"\n\n1.gold class\n 2.silver class\n";
		cout<<"\nenter the choice\n";
		cin>>k;
		switch (k)
		{
			case 1:{
                strcpy(classs,"gold");
				fee=2500;
				cout<<"your monthly fee would be: "<<fee<<endl;
				trainee_allotment(classs);
				}
				break;
			case 2:{
                strcpy(classs,"silver");
				fee=2000;
				cout<<"your monthly fee would be: "<<fee<<endl;
				trainee_allotment(classs);
				}
				break;
		}
		time_slots();
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
    //void virtual display_record(int num)=0;
	//void virtual delete_member(int num)=0;
    //void virtual edit_member(int num)=0;
    
};
class gymmember: public user
{	int n;
	public:
	void save_member()
    {
    	fp.open("hamro.bin",ios::out|ios::app);
    	m1.create_mem();
    	fp.write((char*)&m1,sizeof(m1));
    	fp.close();
    	cout<<endl<<endl<<"the member has been succesfully added...";
    	fflush(stdin);
    }
     void display_record()
    {	int num;
    	num=m1.get_member_number();
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
    	if(found == true)
    	cout<<"\n\nNo record found";
    	getchar();
    }

    void delete_member(int num = 0)
    {
    	
    	system("cls");
        if(num == 0 )
        {
        num=m1.get_member_number();
        
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

        getchar(); // to clear the buffer space   
        }
    }

     void edit_member()
    {
    	int num;
    	char ch = 'T'; // intilized
    	system("cls");
    	cout<<endl;
    	num=m1.get_member_number();
    	fp.open("hamro.bin",ios::in|ios::out);
    	while(fp.read((char*)&m1,sizeof(m1)) && ch == 'T')
    	{
    		if(m1.getmem()==num) // entre only if user's i/p no. and password matches
    		{
    			m1.show_mem();
    			cout<<"\nPlease Enter The New details of the member: "<<endl;
    			m1.create_mem();
    			int pos=1*sizeof(m1);
    			fp.seekp(pos,ios::cur);
    			fp.write((char*)&m1,sizeof(m1));
    			cout<<endl<<endl<<"\t Record Successfully Updated...";
                ch = 'f';	// record found
               delete_member(num);
    		}
            
    	}
        fp.close();
        if(ch == 'T')
            cout<<"incorrect member number or incorrect password\n";// 

    	getchar();
    }
/*    void display_record(int num)
    {
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
    	if(found == true)
    	cout<<"\n\nNo record found";
    	getchar();
    }

    void delete_member(int num)
    {
    	
    	system("cls");
        
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

        getchar(); // to clear the buffer space   
        
    }

     void edit_member(int num)
    {
    	char ch = 'T'; // intilized
    	system("cls");
    	fp.open("hamro.bin",ios::in|ios::out);
    	while(fp.read((char*)&m1,sizeof(m1)) && ch == 'T')
    	{
    		if(m1.getmem()==num) // entre only if user's i/p no. and password matches
    		{
    			m1.show_mem();
   			cout<<"\nPlease Enter The New details of the member: "<<endl;
    			m1.create_mem();
    			int pos=1*sizeof(m1);
    			fp.seekp(pos,ios::cur);
    			fp.write((char*)&m1,sizeof(m1));
    			cout<<endl<<endl<<"\t Record Successfully Updated...";
                ch = 'f';	// record found
               delete_member(num);
    		}
            
    	}
        fp.close();
        if(ch == 'T')
            cout<<"record not found\n";// 

    	getchar();
    } */
}s1;
class admin: public user
{	int n;
	public:
	void save_member()
    {
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
    	cout<<endl<<"\t\tRECORDS...";
    	fp.open("hamro.bin",ios::in);
    	while(fp.read((char*)&m1,sizeof(m1)))
    	{
    		m1.show_mem();
    	fflush(stdin);
    	}
    	fp.close();
    	
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
    	if(found == true)
    	cout<<"\n\nNo record found";
    	getchar();
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

        getchar(); // to clear the buffer space   
        }
    }

     void edit_member()
    {
    	int num;
    	bool found=false;
    	char ch = 'T'; // intilized
    	system("cls");
    	cout<<endl<<endl<<"\tPlease Enter The member number: ";
    	cin>>num;
    	fp.open("hamro.bin",ios::in|ios::out);
    	while(fp.read((char*)&m1,sizeof(m1)) && ch == 'T'&&found!=true)
    	{
    		if(m1.getmem()==num) // entre only if user's i/p no. and password matches
    		{
    			m1.show_mem();
    			cout<<"\nPlease Enter The New details of the member: "<<endl;
    			m1.create_mem();
    			int pos=1*sizeof(m1);
    			fp.seekp(pos,ios::cur);
    			fp.write((char*)&m1,sizeof(m1));
    			cout<<endl<<endl<<"\t Record Successfully Updated...";
                ch = 'f';	// record found
                found=true;
    		}
            
    	}
        fp.close();
        if(found)
        {
        	delete_member(num);
		}
        if(ch == 'T')
            cout<<"incorrect member number or incorrect password\n";// 

    	getchar();
    }
/*  void display_record(int num)
    {
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
    	if(found == true)
    	cout<<"\n\nNo record found";
    	getchar();
    }

    void delete_member(int num)
  {
    	
    	system("cls");
        
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

        getchar(); // to clear the buffer space   
        
    }

     void edit_member(int num)
    {
    	char ch = 'T'; // intilized
    	system("cls");
    	fp.open("hamro.bin",ios::in|ios::out);
    	while(fp.read((char*)&m1,sizeof(m1)) && ch == 'T')
    	{
    		if(m1.getmem()==num) // entre only if user's i/p no. and password matches
    		{
    			m1.show_mem();
    			cout<<"\nPlease Enter The New details of the member: "<<endl;
    			m1.create_mem();
    			int pos=1*sizeof(m1);
    			fp.seekp(pos,ios::cur);
    			fp.write((char*)&m1,sizeof(m1));
    			cout<<endl<<endl<<"\t Record Successfully Updated...";
                ch = 'f';	// record found
               delete_member(num);
    		}
            
    	}
        fp.close();
        if(ch == 'T')
            cout<<"record not found\n";// 

    	getchar();
    } */
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
    				break;
    				
    		case 3:
    				int num;
   				system("cls"); 
    				s2.display_record();
    				break;
    				
    		case 4: s2.edit_member();
    			break;
    		
    		case 5: s2.delete_member();
    		        break;
   				
    		case 6:return;    		
    		default:cout<<"invalid option please try again";
    		}
    	}
    }

    
void user_record(int num)
{	
	while(true)
	{
	int m;
	cout<<"1.quit gym\n2.edit your profile\n3.fitness recommendations\n4.display record\n5.logout\n";
	cout<<endl<<"enter your choice"<<endl;
	cin>>m;
	switch(m)
	{
    		case 1:s1.delete_member();
    		        break;
    		case 2:s1.edit_member();
    		       break;
    		case 3:fnd f;
    				system("cls");
					f.fitness();
    				break;
    		case 4: int num;
   				system("cls"); 
    				s1.display_record();
    				break;
    		case 5:goto b;
	}
	b:
		break;
}
}
class memlogin
{
	public:
	void log()
	{	char ch='T';
		int num;
		string p;
		system("cls");
    	cout<<endl<<endl<<"\tPlease Enter The member number: ";
    	cin>>num;
    	cout<<endl<<"Please enter the password:";
    	cin>>p;
		fp.open("hamro.bin",ios::in|ios::out);
    	while(fp.read((char*)&m1,sizeof(m1)) && ch == 'T')
    	{
    		if(m1.getmem()==num&&m1.passw()==p) // entre only if user's i/p no. and password matches
    		{	m1.setn(num);
    			user_record(num);
    			ch='F';
    		}
            
    	}
        fp.close();
		if(ch=='T')
		{cout<<"invalid member number or password";
		}
	}
};
int main()
{		
		int i,k,z;
		a:
		cout<<"\t\t********************** Gym & Fitness Management System **********************\n"<<endl;
        cout<<"\n\t\t\t-----------------------  WELCOME  -----------------------\n";
		cout<<endl<<"\tSELECT MODE"<<endl<<"\t1.User"<<endl<<"\t2.Admin"<<endl<<"\t3.Exit\n";
		cin>>i;
			if(i==1)
            {
                cout<<endl<<"You're in user mode"<<endl;
                b:
                cout<<endl<<"1.register\n2.login\n";
                cin>>z;
                if(z==1)
				{
				s2.save_member();
				goto b;
			}
				if(z==2)
				{
					memlogin l;
					l.log();
					goto a;
			}
			}
			if(i==2)
            {
                cout<<endl<<"You're in admin mode"<<endl;	
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
						
					}
					}
			if(i==3)
			{
				exit(1);
			}
		return 0;
}

