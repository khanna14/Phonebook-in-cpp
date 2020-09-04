#include <bits/stdc++.h>
using namespace std;

void add();	
void display();
void edit();
void find();
void del();
/*string convertToString(char* a, int size) 
{ 
    string s = a; 
    return s; 
} */
void menu(){
		system("cls");
cout<<"\t\t**********WELCOME TO PHONEBOOK*************";

cout<<"\n\n\t\t\t  MENU\t\t\n\n";
cout<<"\t1.Add New   \t2.List   \t3.Exit  \n\t4.Modify \t5.Search\t6.Delete\n\nEnter your choice!!-";

int a;
cin>>a;

	switch(a){
		case 1: add();
		case 2: display();
		case 3: break;
		case 4: edit();
		case 5: find();
		case 6:	del();
		default:
                system("cls");
                cout<<("\nEnter 1 to 6 only");
                cout<<("\n Enter any key");
	}
}

void add(){
	ofstream f;
	f.open("phone.txt",ios::app | ios::out);
	string nam;
	string phn;
	cout<<"\nEnter Name: ";
	cin.sync();
	getline(cin,nam);
	cout<<"\nEnter the Phones No: ";
	cin>>phn;
	
	while(phn.size()!=10){
	cout<<"\n!!Enter a valid phone no!!";
	cout<<"\nEnter Phone no:";
	cin>>phn;
	}
	string a=nam;
	a=a+" "+phn;
	f<<a<<endl;
	cout<<"\nContact Added :) \n";
	f.close();
	system("pause");
	system("cls");
    menu();
}

void display(){
	ifstream f;
	string line;
	
	f.open("phone.txt",ios::in);		
	if(!f){
		cout<<"File is Empty, Nothing to Diplay\n\n";
	}
	else{
	while (f){
		getline(f,line);
		cout<<line<<endl;
	}			
	}
	f.close();
	system("pause");
	system("cls");
    menu();
	
}

void edit(){
	char k[100];
	cout<<"Enter the name to be edited : "<<endl;
	cin>>k;
	ifstream f;
	f.open("phone.txt");	
	string line;
	f.seekg(0,ios::beg);	
	if(f){
		cout<<"Your Phone Book is Empty!!\n\n";
		system("pause");
		system("cls");
	    menu();
	}
	else {
		
	}
}

void find(){
	ifstream f;
	f.open("phone.txt");	
	string line;
	f.seekg(0,ios::beg);	
	if(!f){
		cout<<"Your Phone Book is Empty!!\n\n";
		system("pause");
		system("cls");
	    menu();
	}
	else {	
		string k;
		system("pause");
		system("cls");
		cout<<"\t\t\t\tSearch by: \n";
		cout<<"\t\t1. Name            2. Phone Number \n Enter Your Choice: ";
		int n;
		cin>>n;
		switch(n){
		case(1):
		{
			int no=1;
			cin.sync();
			getline(cin,k);
			int n=k.size();
			while(f){
				getline(f,line);
				string temp="";
				for(int i=0;i<n;i++){
					temp+=line[i];
				}
				if(temp==k){
					cout<<"Contact "<<no<<" : "<<line<<endl;
					no++;
				}
					
			}
			if(no==1)	{
				cout<<"Not Found\n";
			}
			
			f.close();		
			system("pause");
			system("cls");
		    menu();
			break;
		}
		case(2):
		{	
			int no=1;
			cin.sync();
			getline(cin,k);
			while(f){
				getline(f,line);
				string temp="";
				for(int i=9;i>=0;i--){
					temp+=line[line.size()-i+1];
				}
				if(temp==k){
					cout<<"Contact "<<no<<" : "<<line<<endl;
					no++;
				}	
			}
			
			if(no==1)	{
				cout<<"Not Found\n";
			}
			f.close();		
			system("pause");
			system("cls");
		    menu();
			break;
		}
		default:
			if(n!=1 || n!=2){
				cout<<"Enter a valid Choice"<<endl;
			}
		}		
	}
}


void del(){
	ifstream f;
	f.open("phone.txt");	
	string line;
	f.seekg(0,ios::beg);	
	if(f){
		cout<<"Your Phone Book is Empty!!\n\n";
		system("pause");
		system("cls");
	    menu();
	}
	else {
		ofstream x;
		x.open("temp.txt",ios::out);
		string k;
		cout<<"Enter the name to be Deleted : "<<endl;
		cin.sync();
		getline(cin,k);
		int n=k.size();
		while(f){
			getline(f,line);
			string temp="";
			for(int i=0;i<n;i++){
				temp+=line[i];
			}
			if(temp!=k){
				x<<line;
			}
			else{
				cout<<"Contact has been deleted\n\n";
			}	
		}
		remove("phone.tx");
		rename("temp.txt","phone.txt");
	}
}


	
int main(){
	ofstream f;
	f.open("phone.txt", ios::app);
	system("color 5f");
	menu();
}
