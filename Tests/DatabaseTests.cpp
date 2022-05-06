#include "DatabaseTests.h"

void TestIO(){
    cout << "Testing I/O\n";

    //Test Candidate Writing
    unsigned long testCandidateID = 123456789;
    string testParty = "Test Party";
    string testCandidateName = "Test Name";
    unsigned char testCandidateAge = 32;
    string testCandidateSuburb = "Test Suburb";

    Candidate testCandidate(testCandidateID, testParty, testCandidateName, testCandidateAge, testCandidateSuburb);

    //Read Values from Candidate Table
    Database::instance().WriteToCandidateTable(testCandidate);
    auto resultCandidate = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return true;
    }, testCandidate, true);
    
    //Check if Read and Write Works
    cout << "Candidate: ";
    if(resultCandidate[0] == testCandidate){
        cout << "Passed";
    }else{
        cout << "Failed";
    }

    cout << endl;

    //Test Voter Writing
    unsigned long testVoterID = 123456789;
    string testVoterName = "Test Name";
    unsigned char testVoterAge = 32;
    string testVoterSuburb = "Test Suburb";

    Voter testVoter(testVoterID, testVoterName, testVoterAge, testVoterSuburb);

    Database::instance().WriteToVoterTable(testVoter);

    //Read Values from Voter Table
    auto resultVoter = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return true;
    }, testVoter, true);

    //Check if Read and Write Works
    cout << "Voter: ";
    if(resultVoter[0] == testVoter){
        cout << "Passed";
    }else{
        cout << "Failed";
    }

    cout << endl;
    
    cout << "------------------------------------------------" << endl;

}

void TestQuery(){
    //Define Test Cases
    Candidate candidate1((unsigned long)123456789, "Party 1", "Name 1", 32, "Suburb 1");
    Candidate candidate2((unsigned long)234567891, "Party 2", "Name 2", 16, "Suburb 2");
    Candidate candidate3((unsigned long)345678912, "Party 3", "Name 3", 19, "Suburb 3");
    Voter voter1((unsigned long) 123456789, "Name 1", 18, "Suburb 1");
    Voter voter2((unsigned long) 234567891, "Name 2", 12, "Suburb 2");
    Voter voter3((unsigned long) 345678912, "Name 3", 14, "Suburb 3");

    //Adding Info to Database to Query from and test for Expecting Single Output
    Database::instance().WriteToCandidateTable(candidate1);
    Database::instance().WriteToCandidateTable(candidate2);
    Database::instance().WriteToCandidateTable(candidate3);

    Database::instance().WriteToVoterTable(voter1);
    Database::instance().WriteToVoterTable(voter2);
    Database::instance().WriteToVoterTable(voter3);

    TestQuerySingleOutput();
    TestQuerySingleOutputAllResults();

    Database::instance().WriteToCandidateTable(candidate1);
    Database::instance().WriteToCandidateTable(candidate2);
    Database::instance().WriteToCandidateTable(candidate1);

    Database::instance().WriteToVoterTable(voter1);
    Database::instance().WriteToVoterTable(voter2);
    Database::instance().WriteToVoterTable(voter1);

    TestQueryMultipleOutput();
    TestQueryMultipleOutputAllResults();
}

void TestQuerySingleOutput(){
    
    cout << "Testing Query with Single Instance\n";

    Candidate candidate1((unsigned long)123456789, "Party 1", "Name 1", 32, "Suburb 1");
    auto candidateResults = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate == check;
    }, candidate1, false);

    cout << "Candidate: ";
    if(candidateResults.size() == 1 && candidateResults[0] == candidate1){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

    Voter voter2((unsigned long) 234567891, "Name 2", 12, "Suburb 2");
    auto voterResults = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voter2, false);

    cout << "Voter: ";
    if(voterResults.size() == 1 && voterResults[0] == voter2){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;
}

void TestQuerySingleOutputAllResults(){
    cout << "Testing Query with Single Instance and All Results Option Set to True\n";

    Candidate candidate1((unsigned long)123456789, "Party 1", "Name 1", 32, "Suburb 1");
    auto candidateResults = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate == check;
    }, candidate1, true);

    cout << "Candidate: ";
    if(candidateResults.size() == 1 && candidateResults[0] == candidate1){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

    Voter voter2((unsigned long) 234567891, "Name 2", 12, "Suburb 2");
    auto voterResults = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voter2, true);

    cout << "Voter: ";
    if(voterResults.size() == 1 && voterResults[0] == voter2){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;
}

void TestQueryMultipleOutput(){
    cout << "Testing Query with Multiple Instances\n";

    Candidate candidate1((unsigned long)123456789, "Party 1", "Name 1", 32, "Suburb 1");
    auto candidateResults = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate == check;
    }, candidate1, false);

    cout << "Candidate: ";
    if(candidateResults.size() == 1 && candidateResults[0] == candidate1){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

    Voter voter2((unsigned long) 234567891, "Name 2", 12, "Suburb 2");
    auto voterResults = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voter2, false);

    cout << "Voter: ";
    if(voterResults.size() == 1 && voterResults[0] == voter2){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;
}

void TestQueryMultipleOutputAllResults(){
    cout << "Testing Query with Multiple Instances and All Results Set to True\n";

    Candidate candidate1((unsigned long)123456789, "Party 1", "Name 1", 32, "Suburb 1");
    auto candidateResults = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate == check;
    }, candidate1, true);

    cout << "Candidate: ";
    if(candidateResults.size() == 3 && candidateResults[0] == candidate1 && candidateResults[1] == candidate1 && candidateResults[2] == candidate1){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

    Voter voter2((unsigned long) 234567891, "Name 2", 12, "Suburb 2");
    auto voterResults = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voter2, true);

    cout << "Voter: ";
    if(voterResults.size() == 2 && voterResults[0] == voter2 && voterResults[1] == voter2){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;
}

void TestReplace(){
    cout << "Testing Editing Database\n";

    Candidate candidateToBeReplaced((unsigned long)123568946, "Party To Replace", "To", 22, "Suburb To");
    Candidate candidateToReplace((unsigned long)4569789326, "Replaced Party", "Done", 15, "Suburb Done");
    Database::instance().WriteToCandidateTable(candidateToBeReplaced);

    Database::instance().ReplaceCandidate(candidateToBeReplaced, candidateToReplace);

    auto checkIfReplacedValueIsPresent_candidate = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate == check;
    }, candidateToBeReplaced, true);

    auto checkIfReplacedSuccessfully_candidate = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate == check;
    }, candidateToReplace, true);

    cout << "Candidate: ";
    if(checkIfReplacedValueIsPresent_candidate.empty() && checkIfReplacedSuccessfully_candidate.size()){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;
    
    Voter voterToBeReplaced((unsigned long) 123568946, "Name To Replace", 18, "Suburb To");
    Voter voterToReplace((unsigned long) 4569789326, "Repplaced Name", 19, "Suburb Replaced");
    Database::instance().WriteToVoterTable(voterToBeReplaced);

    Database::instance().ReplaceVoter(voterToBeReplaced, voterToReplace);

    auto checkIfReplacedValueIsPresent_voter = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voterToBeReplaced, true);

    auto checkIfReplacedSuccessfully_voter = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voterToReplace, true);

    cout << "Voter: ";
    if(checkIfReplacedValueIsPresent_voter.empty() && checkIfReplacedSuccessfully_voter.size()){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;
}

void TestCandidateInfo(){
    TestCandidateInfoEmpty();
}

void TestCandidateInfoEmpty();

void TestCandidateInfoSingle();

void TestCandidateInfoMultiple();

void TestVote(){
    cout << "Testing Voting\n";

}