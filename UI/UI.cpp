#include "UI.h"


void UI(){
	//Login Function to get Voter Information
	Voter voter = Login();

	//Check if Quitting from Login Screen
	if(voter == Voter(0, "", 0, ""))
		return;

	bool running = true;
	//Program Loop
	while(running){
		char menuChoice;
		string Input = Menu();
		vector<Candidate> candidatesResults;

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
			//Print Info About Candidate
			PrintCandidate(voter);
			break;
		case 'a':
			//Check if Voter has already voted
			system("CLS");
			if(!voter.Status()){
				Vote(voter);
			}else{
				cout << "You Have Already Cast Your Ballot!" << endl;
				system("pause");
			}
			break;
		case 's':
			//Print Info About Candidate with Least Votes
			system("CLS");
			candidatesResults = Database::instance().CandidateVoteInfo(false);
			//Check if No Votes Have been recorded
			if (candidatesResults.empty()){
				cout << "There are no Recorded Votes" << endl;
			}
			//Check if Only One Person has the Least Votes
			else if (candidatesResults.size()==1){
				cout << "The Candidate with the Least Votes is: " << endl;
				cout << endl;
				candidatesResults[0].PrintInfo();
			}
			//Check if More Than One Person has the Least Votes
			else {
				cout << "The Candidates with the Least Votes are: " << endl; 
				for (size_t i = 0; i < candidatesResults.size(); i++){
					cout << endl;
					candidatesResults[i].PrintInfo();
				}
			}
			system("pause");
			break;
		case 'l':
			//Print Info About Candidate with Most Votes
			system("CLS");
			candidatesResults = Database::instance().CandidateVoteInfo(true);
			//Check if No Votes Have been recorded
			if (candidatesResults.empty()){
				cout << "There are no Recorded Votes" << endl;
			}
			//Check if Only One Person has the Most Votes
			else if (candidatesResults.size()==1){
				cout << "The Candidate with the Most Votes is: " << endl;
				cout << endl;
				candidatesResults[0].PrintInfo();
			}
			//Check if More Than One Person has the Most Votes
			else {
				cout << "The Candidates with the Most Votes are: " << endl; 
				for (size_t i = 0; i < candidatesResults.size(); i++){
					cout << endl;
					candidatesResults[i].PrintInfo();
				}
			}
			system("pause");
			break;
		case 'q':
			//Check if the User is 100% Sure the User Wants to Quit
			if(AreYouSure("Quit", "")){
				running = false;
			}
			break;
		//If the Users have Entered the Wrong Selected, Display a Message and Return to Main Menu
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
		cout << "Enter Q to Quit." << endl;
		cout << "Please Enter Voter ID: ";
		getline(cin, data);

		//Check if Quitting
		if(data == "Q" || data == "q")
			return Voter(0, "",0, "");
		
		//If You can Convert Input To ID Convert It, Otherwise Continue
		else if(DoesntContainCharacters(data))
			ID = stoul(data);
		else{
			cout << "Invalid Input, Please Try Again!" << endl;
			system("pause");
			continue;
		}
		

		cout << "Please Enter Your Age: ";
		getline(cin, data);
		
		//Check if Quiting
		if(data == "Q" || data == "q")
			return Voter(0, "",0, "");
		
		//If You can Convert Input To Age Convert It, Otherwise Continue
		if(DoesntContainCharacters(data))
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

	//Menu is Displayed 
	//Asking the User to Select an Option From the Menu
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


void Vote(Voter& voter){
	string input;
	cout << "Enter Candidate ID or the Party You Wish to Vote for: ";
	getline(cin, input);

	//Check if User Entered Candidate ID or Party Name
	if(DoesntContainCharacters(input)){
		//Query Database
		Candidate check(stoul(input), "", "", 0, "");
		auto resultCandidate = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool {
				return candidate.CandidateID() == check.CandidateID();
			}, check, true);

		//Check if Candidate is Valid
		if (resultCandidate.empty() || resultCandidate.size() > 1){
			cout << "Invalid Candidate ID!" << endl;
			system("pause");
		}else{
			//If Valid Make Sure the Person Wants to Vote for this Candidate.
			if(AreYouSure("Vote For This Candidate", "\n" + resultCandidate[0].ToString())){
				//Vote for Candidate
				Database::instance().Vote(voter, stoul(input), "");
			}
		}
	}else{	
		//Query Database
		Candidate check(0, input, "", 0, voter.Suburb());
		auto resultCandidate = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool {
			return StrToLower(candidate.Party()) == StrToLower(check.Party()) && check.Suburb() == candidate.Suburb();
			}, check, true);

		//Check if Candidate is Valid
		if (resultCandidate.empty() || resultCandidate.size() > 1){
			cout << "Invalid Party Name!" << endl;
			system("pause");
		}else{
			//If Valid Make Sure the Person Wants to Vote for this Candidate.
			if(AreYouSure("Vote For This Candidate", "\n" + resultCandidate[0].ToString())){
				//Vote for Candidate
				cout << Database::instance().Vote(voter, 0, input);
			}
		}
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
	if (DoesntContainCharacters(input)) {
		//Query Database
		Candidate check(stoul(input), "", "", 0, "");
		auto resultCandidate = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool {
				return candidate.CandidateID() == check.CandidateID();
			}, check, true);

		//Check if Candidate is Valid
		if (resultCandidate.empty() || resultCandidate.size() > 1)
			cout << "Invalid Candidate ID!" << endl;
		else
			//Print Info about Candidate
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
			//Print Info about Candidate
			resultCandidate[0].PrintInfo();
	}
	system("pause");
	system("CLS");
}

bool AreYouSure(string prompt, string extra){
	while (true){
		system("CLS");
		string data = "";
		char selected;

		//Print Options
		cout << "Are You Sure You Want to " << prompt << "?" << extra << endl;
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

//Convert String to LowerCase
string StrToLower(string str){
	string lower;
	for (int i = 0; i < str.size(); i++){
		lower += tolower(str[i]);
	}

	return lower;
}

//Check if String Contains Characters
bool DoesntContainCharacters(string data){
	//To Prevent Errors When Working with Empty Strings
	if(data.empty())
		return false;

	for (int i = 0; i < data.size(); i++){
		if(isalpha(data[i]))
			return false;
	}
	return true;
}
