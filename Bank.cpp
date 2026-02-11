#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
// Account structure holding user data
// name, cnic, account number, password and current balance
struct acc{
	string cnic;
	string accNumber;
	string password;
	string name;
	double balance;
};
//global variables
double temp_amount;
string temp_acc;
string temp_pass;


string display_main_menu(){
	string c;
	cout<<"--------------------------"<<endl;
	cout<<"******Main Menu******\n";
	cout<<"--------------------------"<<endl;
	cout<<"Select an option from the menu. Signup if you don’t have an account. Login if you already created one.\n1)Signup\n2)Login\n3)Admin Login\n4)Exist\nEnter your Choice:";
	cin>>c;
	return c;
}
bool check(string cnic,int l){
	
	if(cnic.length()!=l)
		return true;
	for(int i=0; i<13; i++){
		if(!isdigit(cnic[i]))
			return true;
	}
	return false;
}
bool check(string accNo){
	
	if(accNo.length()!=8)
		return true;
	for(int i=0; i<8; i++){
		if(!isdigit(accNo[i]))
			return true;
	}
	return false;
}
bool check_pass(string pass){
	if(pass.length()!=6)
		return true;
	for(int i=0; i<6; i++){
		if(!isdigit(pass[i]))
			return true;
	}
	return false;
}
void signup(acc u1[],int t){
	cout<<"Enter your full name (up to 50 characters, alphabets only recommended):";
	cin.ignore();
	getline(cin,u1[t].name);
	cout<<"Enter your CNIC without dashes (13 digits). Example: 3520123456789. No letters or special characters allowed :";
	cin>>u1[t].cnic;
	while(check(u1[t].cnic,13)){
		cout<<"Invalid CNIC! It must contain exactly 13 digits. Try again.\n";
		cin>>u1[t].cnic;
		}
	cout<<"Create your 8-digit account number (numbers only). Example: 12345678 :";
	cin>>u1[t].accNumber;
	while(check(u1[t].accNumber)){
		cout<<"Account number must be exactly 8 digits and should be only digits. Try again:";
		cin>>u1[t].accNumber;
		}
	cout<<"Create a 6-digit password (numbers only). No letters or symbols. Example: 102938.:";
	cin>>u1[t].password;
	while(check_pass(u1[t].password)){
		cout<<"Password must be exactly 6 digits. Try again:";
		cin>>u1[t].password;
		}
	cout<<"Enter the initial amount to deposit (cannot be negative or zero):";
	cin>>u1[t].balance;
	while(u1[t].balance<=0){
		cout<<"Amount cannot be negative or zero. Enter a valid amount :"<<endl;
		cin>>u1[t].balance;
		}
	cout<<"Your account has been created successfully!\n";	
}


void save_data(acc u1[],int t){
	ofstream out("data.txt");
	for(int i= 0; i<t; i++){
		out<<u1[i].name<<"\n";
		out<<u1[i].cnic<<"\n";
		out<<u1[i].accNumber<<"\n";
		out<<u1[i].password<<"\n";
		out<<u1[i].balance<<"\n";
	}
	out.close();
}
int load_data(acc u1[]){
	ifstream in("data.txt");
	int count=0;
	if(!in)
		return 0;
	while(count<100){
		getline(in,u1[count].name);
		in>>u1[count].cnic;
		in>>u1[count].accNumber;
		in>>u1[count].password;
		in>>u1[count].balance;
		in.ignore();
		if(in.fail())
           break;
        count++;
		}
	in.close();
	return count;
}
void displayAccounts(acc u1[],int t){
	if(t>0)
		for(int i=0; i<t; i++){
		cout<<endl<<"*****User "<<u1[i].name<<"*****"<<endl<<endl;
		cout<<"Name: "<<u1[i].name<<endl<<"CNIC: "<<u1[i].cnic<<endl<<"Acccount No: "<<u1[i].accNumber<<endl<<"Balance= "<<u1[i].balance<<endl;
	}
	else
		cout<<"No accounts exist!\n";
}
void search_by_cnic(acc u1[],int t){
	string temp_cnic;
	bool found=false;
	cout<<"Enter a valid cnic to search data:";
	cin>>temp_cnic;
	for(int i=0; i<t; i++){
		if(temp_cnic==u1[i].cnic){
			cout<<"Name: "<<u1[i].name<<endl;
			cout<<"CNIC: "<<u1[i].cnic<<endl;
			cout<<"Acccount No:"<<u1[i].accNumber<<endl;
			cout<<"Balance= "<<u1[i].balance<<endl<<endl;
			found=true;
		}
	}
	if(!found)
		cout<<"No account found!\n";
}
void search_by_accNo(acc u1[],int t){
	bool found=false;
	cout<<"Enter a valid account no to search data:";
	cin>>temp_acc;
	for(int i=0; i<t; i++){
		if(temp_acc==u1[i].accNumber){
			cout<<"Name: "<<u1[i].name<<endl;
			cout<<"CNIC: "<<u1[i].cnic<<endl;
			cout<<"Acccount No:"<<u1[i].accNumber<<endl;
			cout<<"Balance= "<<u1[i].balance<<endl<<endl;
			found=true;
		}
	}
	if(!found)
		cout<<"No account found!\n";
}


int login(acc u1[],int t){
//dynamic memory allocation
	char *pas=new char[7];
	char *acNo=new char[9];
	string acNo_str;
	string pass_str;
	int userIndex;
	if(t==0){
		cout<<"No account exists,signup first."<<endl;
		}
	else{
	// User enters account number and password
	// Searches account array to verify credentials
	// Opens user menu on success
	cout<<"Enter your 8-digit account number to login: ";
	cin>>acNo;
	acNo_str=acNo;
	bool found=true;
	do{
		for(int i=0; i<t; i++){
			if(acNo_str==u1[i].accNumber){
				found=false;
				userIndex=i;
				break;
				}
			}
		if(found){
			cout<<"No account found with this number. Re-enter a valid account number.:";
			cin>>acNo;
			acNo_str=acNo;
			}
		}while(found);
	cout<<"Enter your 6-digit password:";
	cin>>pas;
	pass_str=pas;
	while(pass_str!=u1[userIndex].password){
		cout<<"Incorrect password. Try again: ";
		cin>>pas;
		pass_str=pas;
		}
	cout<<"Login successful! Welcom "<<u1[userIndex].name<<endl;
	delete []pas;
	delete[]acNo;
	return userIndex;
	}
}
int display_login_menu(){
	
	int ch;
	cout<<"------------------------------"<<endl;
	cout<<"Welcome to User Menu!"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"1)Check balance\n2)Deposit Money\n3)Withdraw Money\n4)Transfer Money\n5)Edit details\n6)Transaction History\n7)Delete Account\n8)Logout\n";
	cout<<"Enter choice:";
	cin>>ch;
	return ch;
}
void change_password(acc *user){
	cout<<"Enter your current password :";
	cin>>temp_pass;
	while(temp_pass!=user->password){
		  cout<<"Invalid password!\nEnter correct password:";
		  cin>>temp_pass;
		}
	cout<<"Enter your new 6-digit password: ";
	cin>>user->password;
	while(check_pass(user->password)){
		 cout<<"Password must be exactly 6 digits. Enter again.";
		 cin>>user->password;
		}
	cout<<"Password changed successfully!\nYour new password is :"<<user->password<<endl;
}
bool delete_account(acc u1[],int userIndex,int &t,int h_count[],double tran_history[][50]){
	char choice;
	cout<<"Enter password to delete your account:";
	cin>>temp_pass;
	if(temp_pass!=u1[userIndex].password){
		cout<<"Invalid password, Account deletion aborted!\n";
		return false;
	}
	cout<<"Are you sure you want to delete your account permanently?";
	cin>>choice;
	if(choice!='Y' && choice!='y'){
		cout<<"Account deletion aborted!\n";
		return false;
	}
	for(int i=userIndex; i<t-1; i++ ){
		u1[i]=u1[i+1];
		h_count[i]=h_count[i+1];
		for(int j=0; j<50; j++){
			tran_history[i][j]=tran_history[i+1][j];
		}
	}	
	t--;
	save_data(u1,t);
	return true;
}
void show_transactions(double tran_history[][50],int h_count[],int userIndex){
	cout<<"Transaction History!"<<endl;
	if(h_count[userIndex]==0)
	cout<<"No transactions recorded yet !\n";
	else{
		for(int x=0; x<h_count[userIndex]; x++){
		cout<<x+1<<") ";
		if(tran_history[userIndex][x]<0)
			cout<<"Withdrawal / Sent :"<<tran_history[userIndex][x]<<endl;
		else
			cout<<"Deposit / Recieved :"<<tran_history[userIndex][x]<<endl;
			}
		}
}
int transfer_amount(acc u1[],int userIndex, int t){
	cout<<"Enter the 8-digit account number to transfer money to:";
	cin>>temp_acc;
	bool found=true;
	int j=0;
	do{
		for(int i=0; i<t; i++){
			if(temp_acc==u1[i].accNumber){
				found=false;
				j=i;
				break;
				}
			}
		if(found){
			cout<<"No matching account found. Re-enter a valid account number.:";
			cin>>temp_acc;
			}
	}while(found);
	cout<<"Enter transfer amount (must be positive and >= your balance) :";
	cin>>temp_amount;
	while(temp_amount<=0 || temp_amount>u1[userIndex].balance){
		cout<<"Invalid amount! Try again : ";
		cin>>temp_amount;
		}
	cout<<"Enter password to confirm transfer:";
	cin>>temp_pass;
	while(temp_pass!=u1[userIndex].password){
		cout<<"Invalid password! Try again :";
		cin>>temp_pass;
		}
	u1[userIndex].balance-=temp_amount;
	u1[j].balance+=temp_amount;
	cout<<"Money transferred successfully!\n";
		return j;
}


void check_balance(acc u1[],int userIndex){
	cout<<"Your current account balance is: Rs. "<<u1[userIndex].balance<<endl;
}
void deposit_money(acc u1[],int userIndex){
	cout<<"Enter the amount you want to deposit (cannot be negative or zero):";
	cin>>temp_amount;
	while(temp_amount<=0){
		cout<<"Amount cannot be negative or zero. Enter again :";
		cin>>temp_amount;
		}
	cout<<"Enter your password to confirm deposit: ";
	cin>>temp_pass;
	while(temp_pass!=u1[userIndex].password){
		cout<<"Invalid password! Try again: ";
		cin>>temp_pass;
		}
	u1[userIndex].balance+=temp_amount;
	cout<<"Deposit successful! Amount added to your account\n";

}
void withdraw_money(acc u1[],int userIndex){
	cout<<"Enter the amount to withdraw (must be less than or equal to your balance and can't be negative and zero'):";
	cin>>temp_amount;
	while(temp_amount>u1[userIndex].balance || temp_amount<=0){
		cout<<"Invalid amount! It must be positive and not exceed your balance. Try again : ";
		cin>>temp_amount;
		}
	cout<<"Enter your password to confirm withdrawal:";
	cin>>temp_pass;
	while(temp_pass!=u1[userIndex].password){
		cout<<"Invalid password! Try again: ";
		cin>>temp_pass;
		}
	u1[userIndex].balance-=temp_amount;
	cout<<"Withdrawal successful!\n";
						
}
void change_name(acc u1[],int userIndex){
	string name;
	string pass;
	cout<<"Enter your new name:";
	getline(cin,name);
	cout<<"Enter password to save your new name:";
	cin>>pass;
	while(pass!=u1[userIndex].password){
		cout<<"Invalid password! try again:";
		cin>>pass;
	}
	u1[userIndex].name=name;
	cout<<"Name changed successfully!\n";
}
void change_cnic(acc u1[],int userIndex){
	string cnic;
	string pass;
	cout<<"Enter your new cnic:";
	cin>>cnic;
	while(check(cnic,13)){
		cout<<"Invalid cnic! try again:";
		cin>>cnic;
	}
	cout<<"Enter password to save your new cnic:";
	cin>>pass;
	while(pass!=u1[userIndex].password){
		cout<<"Invalid password! try again:";
		cin>>pass;
	}
	u1[userIndex].cnic=cnic;
	cout<<"CNIC changed successfuly!\n";
}
int main(){
	const char admin_password[]={"9898"};
	acc u1[100];
	int t=load_data(u1);
	double tran_history[100][50];
	int h_count[100]={0};
	int userIndex;
	cout<<"---------------------------------------\n";
	cout<<"========Bank Management System========\n";
	cout<<"---------------------------------------\n";
	do{
		string ch=display_main_menu();
		if(ch=="1"){
			signup(u1,t); 
			tran_history[t][h_count[t]++]=u1[t].balance; 
			t++;		
			save_data(u1,t);	
			}
		else if(ch=="2"){
			userIndex=login(u1,t); 
			do{
				int lm=display_login_menu(); 
				switch(lm){
					case 1:
						check_balance(u1,userIndex);	
						break;
					case 2:
						deposit_money(u1,userIndex);   
						tran_history[userIndex][h_count[userIndex]++] =+temp_amount; 
						save_data(u1,t);  
						break;
					case 3:
					 	withdraw_money(u1,userIndex); 
						tran_history[userIndex][h_count[userIndex]++] =-temp_amount; 
						save_data(u1,t); 
						break;
					case 4:
					  	{
						int j=transfer_amount(u1,userIndex,t);  
						tran_history[userIndex][h_count[userIndex]++] =-temp_amount;
						tran_history[j][h_count[j]++] =+temp_amount;
						save_data(u1,t);  
						break;
						}
				case 5:
						int choice;
						do{
						cout<<"====Edit user details====\n";
						cout<<"1)Edit Name.\n2)Edit CNIC.\n3)Edit Password.\n4)Go Back.\nSelect your choice:";
						cin>>choice;
						cin.ignore();
						switch(choice){
							case 1:
								change_name(u1,userIndex);
								save_data(u1,t);
								break;
							case 2:
								change_cnic(u1,userIndex);
								save_data(u1,t);
								break;
							case 3:
								change_password(&u1[userIndex]);
								save_data(u1,t);
								break;
							case 4:
								break;
							default:
								cout<<"Invalid selection!\n";
								break;
							}
						if(choice==4)
							break;
						}while(true);
					
						break;
				case 6:
						// Displays all stored transactions for the logged-in user
						show_transactions(tran_history,h_count,userIndex);
						break;
				case 7:
					{
					bool close=delete_account(u1,userIndex,t,h_count,tran_history);
					if(close)
						goto end;
					break;
					}
				case  8:
						goto end;
			
			}
		}while(true);
		end: ;
		cout<<"You have been logged out successfully!\n";
		
	}
	else if(ch=="3"){
				
				// Admin can see accounts after entering admin password
				char temp_admin[5];
				int choice;
				cout<<"Enter 4-digit admin password to login:";
				cin>>temp_admin;
				//password verification
				while(strcmp(temp_admin,admin_password)!=0){
					cout<<"Incorrect admin password. Try again: ";
					cin>>temp_admin;
				}
				cout<<"Login Successful!\n";
				do{
				cout<<"\n=====Admin Menu=====\n";
				cout<<"1)Diplay all accounts.\n2)Search by CNIC.\n3)Search by Account No.\n4)Logout.\n";
				cin>>choice;
				if(choice==1)
					displayAccounts(u1,t);
				else if(choice==2)
					search_by_cnic(u1,t);
				else if(choice==3)
					search_by_accNo(u1,t);
				else if(choice==4)
						break;
				else
					cout<<"Invalid Selection!\n";
				}while(true);
				cout<<"Logout successfuly!\n";
	}
	else if(ch=="4")
		break;
	else
		cout<<"Invalid selections!";
	
	}while(true);
	
}
