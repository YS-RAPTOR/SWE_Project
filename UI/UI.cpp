#include <iostream>
#include<string>
void select(char menuchoice);
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
	cout << "\t\tEnter your choice\t";
	cin >> menuchoice;
	system("CLS");
	select(menuchoice);
	return 0;
}
void select(char menuchoice) {


	if (menuchoice == 'P' || menuchoice == 'p') {
		cout << "1";
	}
	else if (menuchoice == 'A' || menuchoice == 'a') {
		cout << "2";
	}
	else if (menuchoice == 'S' || menuchoice == 's') {
		cout << "3";
	}
	else if (menuchoice == 'L' || menuchoice == 'l') {
		cout << "4";
	}
	else if (menuchoice == 'Q' || menuchoice == 'q') {
		cout << "5";
	}
	else {
		cout << "\n\tUnknown selection, please try again\n\n";
		int reset;
		cout << "\tPress 0 to go back to the menu\t";
		cin >> reset;
		if (reset == 0) {
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
			cout << " Unknown selection, please try again ";
			cout << "Press 0 to go back to the menu\t";
			cin >> reset;
		}
	}
}
