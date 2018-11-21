#include<string.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
#include<E:\Work\University\CP\Project\Txt files\Menu.txt>
#include<E:\Work\University\CP\Project\Txt files\Class Student.txt>
#include<E:\Work\University\CP\Project\Txt files\Check_Student_Info.txt>
#include<E:\Work\University\CP\Project\Txt files\Results.txt>
#include<E:\Work\University\CP\Project\Txt files\Teachers.txt>
#include<E:\Work\University\CP\Project\Txt files\Login.txt>
int main()
{
	char key,admins[20];
	int pass;
	//Classes objects ki decleration
	Menu m;
	Check_Student_Info CSI;
	Results R;
	Teachers T;
	//New_Employment NE;
	while(key!='E') //loop ruke ga jab E(exit) enter hoga
	{
		system ("color 74");
		system("CLS");
		m.Main_Menu(); //Calling Funtion of "Main_Menu" from Class "Menu"
		key=getch();
		key=CSI.Upper_Case(key);
		//New student ki addmission ka fuction call hoga "N" key sy
		if(key=='N')
		{
			CSI.New_Admission();
		}
		//Result Entry ka function call ho ga "R" key sa
		if(key=='R'){
			Login();
			R.Enter_Result();
		}
		//Check Detail ka function call ho ga "C" key sa
		if(key=='C'){
			CSI.Check_Info();
			key=getch();
			key=CSI.Upper_Case(key);
			if(key=='S'){
				CSI.Student_Info();
				key=getch();
				key=CSI.Upper_Case(key);
				if(key=='G'){
					system ("color 74");
					system("CLS");
					system ("color 74");
					CSI.General_Information();
				}
				if(key=='R'){
					R.display_Result();
				}
			}
			if(key=='T' || key=='D'){
				system ("color 74");
				system("CLS");
				system ("color 74");
				cout<<"\n\n\n\n\n\n";
				cout<<"\t\t\t\tEnter Admintator ID"<<endl<<"\t\t\t\t";
				cin>>admins;
				if(strcmp(admins,"Waris")==0){
					cout<<"\t\t\t\tEnter Password"<<endl<<"\t\t\t\t";
					cin>>pass;
					if(pass==21542){
						T.display_Employment(key);
					}
					else{
						cout<<"\t\t\t\tPassword Is Worng"<<endl;
						getch();
					}
				}
				else{
					cout<<"\t\t\t\tAdminstator ID Wrong"<<endl;
					getch();
				}
			}
		}
		if(key=='L'){
			system ("color 74");
			system("CLS");
			system ("color 74");
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\tEnter Admintator ID"<<endl<<"\t\t\t\t";
			cin>>admins;
			if(strcmp(admins,"Waris")==0){
				cout<<"\t\t\t\tEnter Password"<<endl<<"\t\t\t\t";
				cin>>pass;
				if(pass==21542){
					T.Employment();
					key=getch();
					key=CSI.Upper_Case(key);
					T.Teacher(key);
				}
				else{
					cout<<"\t\t\t\tPassword Is Worng"<<endl;
					getch();
				}
			}
			else{
				cout<<"\t\t\t\tAdminstator ID Wrong"<<endl;
				getch();
			}
		}
		
	}
}
