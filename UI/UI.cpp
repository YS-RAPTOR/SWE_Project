#pragma once
#include <iostream>
#include<string>
#include<cstdlib>
#include <cctype>
#include <windows.h>
void menu();
void select(char menuchoice);
void voteprint();
void cand_record(char cand);
void m_quit();
void q_selector(char selected);
void select(char menuchoice);
using namespace std;


int main()
{
	menu();
	return 0;
}
void menu()
{
	// menu is displayed 
	//asking the user to select an option from the menu
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
	// making sure the selection is valid and defining what to do with the selected option
	switch (tolower(menuchoice)) {

	case 'p':
		voteprint();
		break;
	case 'a':
		cout << "2";
		break;
	case 's':
		cout << "3";
		break;
	case 'l':
		cout << "4";
		break;
	case 'q':
		m_quit();
		break;
		// if the users have entered the wrong selected, display a message and return to main menu
	default:
		// infinite while loop
		while (true) {
			cout << "\n\tUnknown selection, please try again\n\n";
			menu();
		}
		break;
	}
}

void voteprint()
// if the user selected P they will be directed to this menu fo further selection
// they are given the option to choose between candidate's ID or party name to select the candidate
// once they have made a selection, they then will be redirected again
{
	char cand;
	cout << "  =====================================================\n";
	cout << " \t\t CANDIDATE\n ";
	cout << " =====================================================\n";
	cout << "  Enter 1 if you know the Candidate's ID \n";
	cout << "  Enter 2 if you know the Party name\n";
	cout << "  ===================================================== \n";
	cout << "\t\t:\t";
	cin >> cand;
	system("CLS");
	cand_record(cand);
}
void cand_record(char cand)
{
	if (cand == '1') {
		string CandID;
		cout << " =====================================================\n";
		cout << " Enter the Candidate's ID:\t";
		cin >> CandID;
	}

	else if (cand == '2') {
		string Party_Name;
		cout << " =====================================================\n";
		cout << " Enter the Party name:\t";
		cin >> Party_Name;
	}
	else{
		while (true) {
			cout << "\n\tUnknown selection, please try again\n\n";
			voteprint();
		}
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
	switch (tolower(selected))
	{
	case 'y':
		system("exit");

		break;
	case 'n':
		system("cls");
		menu();
		break;
	default:
		while (true) {
		system("cls");
		cout << "\n\tUnknown selection, please try again\n\n";
			m_quit();
		}
		break;
	}
}
