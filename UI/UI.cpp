#include "UI.h"


void UI(){
	Voter voter = Login();
	bool running = true;
	//Program Loop
	while(running){
		char menuChoice;
		string Input = Menu();
		
		//Check if Input is Valid
		if(Input.length() == 1){
			menuChoice = tolower(Input[0]);
		}else{
			cout << "Unknown Selection, Please Try Again!" << endl;
			system("pause");
			continue;
		}

		//Logic To Check if Input is Expected
		switch (tolower(menuChoice)) {
		case 'p':
			PrintCandidate(voter);
			break;
		case 'a':
			
			break;
		case 's':
			
			break;
		case 'l':
			
			break;
		case 'q':
			if(AreYouSure("Quit")){
				running = false;
			}
			break;
		// if the users have entered the wrong selected, display a message and return to main menu
		default:
			cout << "Unknown Selection, Please Try Again!" << endl;
			system("pause");
			break;
		}
		
	}
}

Voter Login(){
	while (true){
		system("CLS");
		string data;

		unsigned long ID = 0; 
		char unsigned age = 0;
		//TODO Quit Here
		cout << "Please Enter Voter ID: ";
		getline(cin, data);

		//If You can Convert Input To ID Convert It Otherwise Continue
		if(ContainsCharacters(data))
			ID = stoul(data);
		else{
			cout << "Invalid Input, Please Try Again!" << endl;
			system("pause");
			continue;
		}
		

		cout << "Please Enter Your Age: ";
		getline(cin, data);
		//If You can Convert Input To Age Convert It Otherwise Continue
		if(ContainsCharacters(data))
			age = (unsigned char)stoi(data);
		else{
			cout << "Invalid Input, Please Try Again!" << endl;
			system("pause");
			continue;
		}

		Voter check(ID, "", 0, "");

		//Checks If Voter Exists in Database
		auto results = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
			return voter.VoterID() == check.VoterID();
		}, check, true);

		//Checks if the Voter Credentials Given Is Valid
		if(results.empty() || results.size() > 1 || results[0].Age() != age){
			cout << "Invalid Login, Please Try Again!" << endl;
			system("pause");
			continue;
		}else{
			system("CLS");
			return results[0];
		}
	}
}

string Menu(){

	//menu is displayed 
	//asking the user to select an option from the menu
	system("CLS");
	string Input;
	cout << "=====================================================\n";
	cout << "MENU\n";
	cout << "=====================================================\n";
	cout << "Enter P to Print Information About A Specific Candidate\n";
	cout << "Enter A to Vote For a Specific Candidate\n";
	cout << "Enter S to Display the Candidate with The Least Votes\n";
	cout << "Enter L to Display the Candidate with The Most Votes\n";
	cout << "Enter Q to Quit\n";
	cout << "===================================================== \n";
	cout << "Enter your choice: ";
	getline(cin, Input);
	return Input;
}

void Vote(Voter voter){
	string input;
	cout << "Enter Candidate ID or the Party You Wish to Vote for: ";
	getline(cin, input);

	if(ContainsCharacters(input)){
		Database::instance().Vote(voter, stoul(input), "");
	}else{	
		Database::instance().Vote(voter, 0, input);
	}


}

// if the user selected P they will be directed to this menu fo further selection
// they are given the option to choose between candidate's ID or party name to select the candidate
// once they have made a selection, they then will be redirected again
void PrintCandidate(Voter voter){	
	//Get User Input
	system("CLS");
	string input;
	cout << "Enter Candidate's ID or the Party name: ";
	getline(cin, input);

	//Check If User Entered Candidate ID or Party Name
	if (ContainsCharacters(input)) {
		//Query Database
		Candidate check(stoul(input), "", "", 0, "");
		auto resultCandidate = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool {
				return candidate.CandidateID() == check.CandidateID();
			}, check, true);

		//Check if Candidate is Valid
		if (resultCandidate.empty() || resultCandidate.size() > 1)
			cout << "Invalid Candidate ID!" << endl;
		else
			resultCandidate[0].PrintInfo();
	}
	else {
		//Query Database
		Candidate check(0, input, "", 0, voter.Suburb());
		auto resultCandidate = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool {
			return StrToLower(candidate.Party()) == StrToLower(check.Party()) && check.Suburb() == candidate.Suburb();
			}, check, true);

		//Check if Candidate is Valid
		if (resultCandidate.empty() || resultCandidate.size() > 1)
			cout << "Invalid Party Name!" << endl;
		else
			resultCandidate[0].PrintInfo();
	}
	cout << endl;
	system("pause");
	system("CLS");
}

bool AreYouSure(string prompt){
	while (true){
		system("CLS");
		string data = "";
		char selected;

		//Print Options
		cout << "Are You Sure You Want to " << prompt <<"?" << endl;
		cout << "==================================================\n";
		cout << "Press 'Y' To " << prompt << "\nOr\nPress 'N' to Return to the Menu" << endl;

		//Get User Input
		getline(cin, data);
		
		//Check If Data can be casted into a character
		if(data.length() == 1){
			selected = tolower(data[0]);
		}else{
			cout << "Unknown Selection, Please Try Again!" << endl;
			system("pause");
			continue;
		}

		//Check if Selection is Valid
		if(selected == 'y'){
			return true;
		}else if(selected == 'n'){
			return false;
		}else{
			cout << "Unknown Selection, Please Try Again!" << endl;
			system("pause");
			continue;
		}
	}
}

string StrToLower(string str){
	string lower;
	for (int i = 0; i < str.size(); i++){
		lower += tolower(str[i]);
	}

	return lower;
}

bool ContainsCharacters(string data){
	for (int i = 0; i < data.size(); i++){
		if(isalpha(data[i]))
			return false;
	}
	return true;
}