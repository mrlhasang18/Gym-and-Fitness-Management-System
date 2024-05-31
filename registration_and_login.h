using namespace std;
class alogin
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
