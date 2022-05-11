#include "UI.h"


void UI(){

	Voter voter = Login();

	bool running = true;

	//Program Loop
	while(running){
		
		char menuChoice = Menu();

		switch (tolower(menuChoice)) {
		case 'p':
			voteprint();
			break;
		case 'a':
			
			break;
		case 's':
			
			break;
		case 'l':
			
			break;
		case 'q':
			if(AreYouSure("quit")){
				running = false;
			}
			break;
		// if the users have entered the wrong selected, display a message and return to main menu
		default:
			cout << "\n\tUnknown selection, please try again\n\n";
			cin.clear();
			cin.ignore();
			break;
		}
		
	}
}

Voter Login(){
	while (true){
		unsigned long ID;
		char unsigned age;
		cout << "Please Enter Voter ID: ";
		cin >> ID;
		cout << "Please Enter Your Age: ";
		cin >> age;
		
		Voter check(ID, "", 0, "");

		auto results = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
			return voter.VoterID() == check.VoterID();
		}, check, true);

		if(results.empty() || results.size() > 1 || results[0].Age() != age){
			cout << "Invalid Login";
			cin.clear();
			cin.ignore();
		}else{
			return results[0];
		}
	}
}

char Menu(){

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
	return menuchoice;
}

bool IsCandidateID(string data){
	for (int i = 0; i < data.size(); i++){
		if(isalpha(data[i]))
			return false;
	}
	return true;
}

void Vote(Voter voter){
	string input;
	cout << "Enter Candidate ID or the Party YOu wish to Vote for: ";
	getline(cin, input);

	if(IsCandidateID(input)){
		Database::instance().Vote(voter, stoul(input), "");
	}else{	
		Database::instance().Vote(voter, 0, input);
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
bool AreYouSure(string prompt){
	
	while (true){
		char selected;
		cout << "\n\n\t\tAre you sure you want to" << prompt <<"?\n\n" << endl;
		cout << " \t==================================================\n";
		cout << "\tpress 'Y' for" << prompt << "\tpress 'N' to return to menu\n";
		cin >> selected;
		selected = tolower(selected);

		if(selected == 'y'){
			return true;
		}else if(selected == 'n'){
			return false;
		}else{
			cin.clear();
			cin.ignore();
			cout << "Unknown selection, please try again.";
		}
	}
}
