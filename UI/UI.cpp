#include <iostream>
#include<string>
#include<cstdlib>
#include <windows.h>

void select(char menuchoice);
void voteprint();
using namespace std;
int main()
{
	char menuchoice;
	cout << " =====================================================\n";
	cout << " \t\tMENU\n ";
	cout << "=====================================================\n";
	cout << " Enter P to print the record of (selected) candidate\n";
	cout << " Enter A to edit the votes\n";
	cout << " Enter S to display the smallest number of votes\n";
	cout << " Enter L to display the largest number of votes\n";
	cout << " Enter Q to Quit\n";
	cout << " ===================================================== \n";
	cout << "\t\tEnter your choice:\t";
	cin >> menuchoice;
	system("CLS");
	select(menuchoice);
	return 0;
}
void select(char menuchoice) {

	switch (menuchoice) {

	case 'P': 
	case 'p':
		cout << "1";
		void print();
		break;
	case 'A': 
	case 'a':
		cout << "2";
		break;
	case 'S': 
	case 's':
		cout << "3";
		break;
	case 'L': 
	case 'l':
		cout << "4";
		break;
	case 'Q': 
	case 'q':
		cout << "5";
		break;
	default:
		cout << "\n\tUnknown selection, please try again\n\n";
		char reset;
		cout << "\tPress 0 to go back to the menu\t";
		cin >> reset;
		if (reset == '0') {
			system("CLS");
			cout << " =====================================================\n";
			cout << " \t\tMENU\n ";
			cout << "=====================================================\n";
			cout << " Enter P to print the record of (selected) candidate\n";
			cout << " Enter A to edit the votes\n";
			cout << " Enter S to display the smallest number of votes\n";
			cout << " Enter L to display the largest number of votes\n";
			cout << " Enter Q to Quit\n";
			cout << " ===================================================== \n";
			cout << "\t\tEnter your choice\t";
			cin >> menuchoice;
		}
		else {
			system("cls");
			cout << "\n\t!! You have select the wrong option too many times, press any key to exit !!\n\n";
	
		}
		break;
	}
}

void voteprint()
{

}
