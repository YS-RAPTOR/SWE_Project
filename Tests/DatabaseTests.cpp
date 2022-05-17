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

    //Adding More Info to Database to Query from and test for Expecting Multiple Outputs
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
    //Query Candidate Table
    Candidate candidate1((unsigned long)123456789, "Party 1", "Name 1", 32, "Suburb 1");
    auto candidateResults = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate == check;
    }, candidate1, false);

    //Check if Results are Expected
    cout << "Candidate: ";
    if(candidateResults.size() == 1 && candidateResults[0] == candidate1){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

    //Query Voter Table
    Voter voter2((unsigned long) 234567891, "Name 2", 12, "Suburb 2");
    auto voterResults = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voter2, false);

    //Check if Results are Expected
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

    //Query Candidate Table
    Candidate candidate1((unsigned long)123456789, "Party 1", "Name 1", 32, "Suburb 1");
    auto candidateResults = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate == check;
    }, candidate1, true);

    //Check if Results are Expected
    cout << "Candidate: ";
    if(candidateResults.size() == 1 && candidateResults[0] == candidate1){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

    //Query Voter Table
    Voter voter2((unsigned long) 234567891, "Name 2", 12, "Suburb 2");
    auto voterResults = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voter2, true);

    //Check if Results are Expected
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

    //Query Candidate Table
    Candidate candidate1((unsigned long)123456789, "Party 1", "Name 1", 32, "Suburb 1");
    auto candidateResults = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate == check;
    }, candidate1, false);

    //Check if Results are Expected
    cout << "Candidate: ";
    if(candidateResults.size() == 1 && candidateResults[0] == candidate1){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

    //Query Voter Table
    Voter voter2((unsigned long) 234567891, "Name 2", 12, "Suburb 2");
    auto voterResults = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voter2, false);

    //Check if Results are Expected
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

    //Query Candidate Table
    Candidate candidate1((unsigned long)123456789, "Party 1", "Name 1", 32, "Suburb 1");
    auto candidateResults = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate == check;
    }, candidate1, true);

    //Check if Results are Expected
    cout << "Candidate: ";
    if(candidateResults.size() == 3 && candidateResults[0] == candidate1 && candidateResults[1] == candidate1 && candidateResults[2] == candidate1){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

    //Query Voter Table
    Voter voter2((unsigned long) 234567891, "Name 2", 12, "Suburb 2");
    auto voterResults = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voter2, true);

    //Check if Results are Expected
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

    //Make the Candidates for Testing
    Candidate candidateToBeReplaced((unsigned long)123568946, "Party To Replace", "To", 22, "Suburb To");
    Candidate candidateToReplace((unsigned long)4569789326, "Replaced Party", "Done", 15, "Suburb Done");
    //Write Candidate to the Table
    Database::instance().WriteToCandidateTable(candidateToBeReplaced);

    //Replace Candidate Within Table
    Database::instance().ReplaceCandidate(candidateToBeReplaced, candidateToReplace);

    //Check if the Candidate Written to the Table is Still There
    auto checkIfReplacedValueIsPresent_candidate = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate.CandidateID() == check.CandidateID();
    }, candidateToBeReplaced, true);

    //Check if the Candidate Replaced to the Table is Present
    auto checkIfReplacedSuccessfully_candidate = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate == check;
    }, candidateToReplace, true);

    //Check if the Result is Expected
    cout << "Candidate: ";
    if(checkIfReplacedValueIsPresent_candidate.empty() && checkIfReplacedSuccessfully_candidate.size()){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;
    
    //Make the Voters for Testing
    Voter voterToBeReplaced((unsigned long) 123568946, "Name To Replace", 18, "Suburb To");
    Voter voterToReplace((unsigned long) 4569789326, "Repplaced Name", 19, "Suburb Replaced");
    //Write Voter to the Table
    Database::instance().WriteToVoterTable(voterToBeReplaced);

    //Replace Voter Within Table
    Database::instance().ReplaceVoter(voterToBeReplaced, voterToReplace);

    //Check if the Voter Written to the Table is Still There
    auto checkIfReplacedValueIsPresent_voter = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voterToBeReplaced, true);

    //Check if the Voter Replaced to the Table is Present
    auto checkIfReplacedSuccessfully_voter = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter == check;
    }, voterToReplace, true);

    //Check if the Result is Expected
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
    //Make the Candidates for Testing
    Candidate votes_20_1((unsigned long)24680, "20 Party 1", "Twenties 1", 201, "Twentieth Street 1");
    Candidate votes_20_2((unsigned long)13579, "20 Party 2", "Twenties 2", 202, "Twentieth Street 2");

    //Vote for both Candidates 20 times
    for (int i = 0; i < 20; i++){
        votes_20_1.Vote();
        votes_20_2.Vote();
    }
    //Check when there are no votes
    TestCandidateInfoEmpty();
    //Write a Person with Multiple Votes to test for Single Candidate Case.
    Database::instance().WriteToCandidateTable(votes_20_1);
    TestCandidateInfoSingle();
    //Write Another Person with Multiple Votes to test for Multiple Candidates Case.
    Database::instance().WriteToCandidateTable(votes_20_2);
    TestCandidateInfoMultiple();
}

void TestCandidateInfoEmpty(){
    //Check if No Results Show Up
    cout << "Testing Candidate Info When Empty\n";
    //Most Votes
    auto resultsTrue = Database::instance().CandidateVoteInfo(true);
    //Least Votes
    auto resultsFalse = Database::instance().CandidateVoteInfo(false);
    
    if(resultsTrue.empty()){
        cout << "Most: Passed";
    }else
        cout << "Most: Failed";

    cout << endl;
    
    if(resultsFalse.empty()){
        cout << "Least: Passed";
    }else
        cout << "Least: Failed";

    cout << endl;

    cout << "------------------------------------------------" << endl;
}

void TestCandidateInfoSingle(){
    cout << "Testing Candidate Info When Single Candidate with Most Votes\n";
    //Most Votes
    auto resultsTrue = Database::instance().CandidateVoteInfo(true);
    //Least Votes
    auto resultsFalse = Database::instance().CandidateVoteInfo(false);
    
    //Test if The Result Shows One Person with the Most Votes
    if(resultsTrue.size() == 1){
        cout << "Most: Passed";
    }else
        cout << "Most: Failed";

    cout << endl;
    
    //Test if The Result Shows Multiple People with the Least Votes
    if(resultsFalse.size() > 1 && resultsFalse[0].Count() == 0){
        cout << "Least: Passed";
    }else
        cout << "Least: Failed";

    cout << endl;
    cout << "------------------------------------------------" << endl;
}

void TestCandidateInfoMultiple(){
    cout << "Testing Candidate Info When Many Candidates with Most V0tes\n";
    //Most Votes
    auto resultsTrue = Database::instance().CandidateVoteInfo(true);
    //Least Votes
    auto resultsFalse = Database::instance().CandidateVoteInfo(false);
    
    //Test if The Result Shows Two People with the Most Votes
    if(resultsTrue.size() == 2){
        cout << "Most: Passed";
    }else
        cout << "Most: Failed";

    cout << endl;
    
    //Test if The Result Shows Multiple People with the Least Votes
    if(resultsFalse.size() > 1 && resultsFalse[0].Count() == 0){
        cout << "Least: Passed";
    }else
        cout << "Least: Failed";

    cout << endl;
    
    cout << "------------------------------------------------" << endl;
}

void TestVote_Database(){
    cout << "Testing Voting\n";
    //Make The Candidate that gets Voted on And the Person Who Votes
    Candidate testVoteReceiver((unsigned long)420696969, "Labour 1", "Noah", 20, "Tilted Towers");
    Voter testVoteVoter((unsigned long)616815165651, "Noah", 19, "Tilted Towers" );

    Database::instance().WriteToCandidateTable(testVoteReceiver);
    Database::instance().WriteToVoterTable(testVoteVoter);

    //Test Both Methods of Voting
    Database::instance().Vote(testVoteVoter, 420696969, "");
    Database::instance().Vote(testVoteVoter, 0, "Labour 1");

    //Check if the Vote was COunted
    auto candidateCheck = Database::instance().CandidateQuery([](Candidate candidate, Candidate check)->bool{
        return candidate.CandidateID() == check.CandidateID();
    }, testVoteReceiver, true);

    //Check if the Voter Status Got Updated
    auto voteCheck = Database::instance().VoterQuery([](Voter voter, Voter check)->bool{
        return voter.VoterID() == check.VoterID();
    }, testVoteVoter, true);

    //Check if the Result is Expected
    cout << "Vote: ";
    if(candidateCheck.size() == 1 && candidateCheck[0].Count() == 2 && voteCheck.size() == 1 && voteCheck[0].Status()){
        cout << "Passed";
    }else
        cout << "Failed";

    cout << endl;
    cout << "------------------------------------------------" << endl;

}