#pragma once
#include <iostream>
#include<string>
#include<cstdlib>
#include <windows.h>
void menu();
void select(char menuchoice);
void voteprint();
void cand_record(char cand);
void m_quit();
void q_selector(char selected);
using namespace std;
int main()
{
	menu();
	return 0;
}
void menu()
{
	// asking the user to select an option from the menu
	char menuchoice;
	cout << " =====================================================\n";
	cout << " \t\tMENU\n ";
	cout << "=====================================================\n";
	cout << " Enter P to print the record of (selected) candidate\n";
	cout << " Enter A to add your vote\n";
	cout << " Enter S to display the smallest number of votes\n";
	cout << " Enter L to display the largest number of votes\n";
	cout << " Enter Q to Quit\n";
	cout << " ===================================================== \n";
	cout << "\t\tEnter your choice:\t";
	cin >> menuchoice;
	system("CLS");
	select(menuchoice);
}
void select(char menuchoice) {
	// making sure the selection is valid 
	switch (menuchoice) {

	case 'P': 
	case 'p':
	voteprint();
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
		m_quit();
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
			cout << " Enter A to add your vote\n";
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
	char cand;
	cout << " =====================================================\n";
	cout << " \t\t CANDIDATE lIST\n ";
	cout << " =====================================================\n";
	cout << " Enter 1 to print the record of this guy\n";
	cout << " Enter 2 to print the record of this guy\n";
	cout << " Enter 3 to print the record of this guy\n";
	cout << " ===================================================== \n";
	cout << "\t\tEnter candidate's initial:\t";
	cin >> cand;
	system("CLS");
	cand_record(cand);
}
void cand_record(char cand)
{
	switch (cand){
	case '1':
		cout << "22";
		// babaaabb
		break;
	case '2':
		cout << "223";
		// fhahhss
		break;
	case '3':
		cout << "223";
		// fgihasfa
		break;
	default:
		cout << "\n\tUnknown selection, please try again\n\n";
		char rest;
		cout << "\tPress 0 to go back to the menu\t";
		cin >> rest;
		if (rest == '0') {
			system("CLS");
			cout << " =====================================================\n";
			cout << " \t\t CANDIDATE lIST\n ";
			cout << "=====================================================\n";
			cout << " Enter CH to print the record of this guy\n";
			cout << " Enter FG to print the record of this guy\n";
			cout << " Enter KL to print the record of this guy\n";
			cout << " ===================================================== \n";
			cout << "\t\tEnter candidate's initial:\t";
			cin >> cand;
		}
		else {
			system("cls");
			cout << "\n\t!! You have select the wrong option too many times, press any key to exit !!\n\n";

		}
		break;
	}
}
void m_quit()
{
	char selected;
	cout << "\n\n\t\tAre you sure you want to exit?\n\n" << endl;
	cout << " \t==================================================\n";
	cout << "\tpress Y for exit\tpress N to return to menu\n";
	cin >> selected;
	q_selector(selected);

}
void q_selector(char selected)
{
	switch (selected)
	{
	case 'Y':
	case 'y':

		break;
	case 'N':
	case 'n':
		system("cls");
		menu();
		break;
	default:
		cout << "\n\tUnknown selection, please try again\n\n";
		system("cls");
		m_quit();
		break;
	}
}
