#include "TableTests.h"

void TestOperatorEqual(){
    cout << "Testing Equal Operator\n";
    
    //Test Candidate Equal Operator
    unsigned long testCandidateID = 123456789;
    string testParty = "Test Party";
    string testCandidateName = "Test Name";
    unsigned char testCandidateAge = 32;
    string testCandidateSuburb = "Test Suburb";

    Candidate testCandidate(testCandidateID, testParty, testCandidateName, testCandidateAge, testCandidateSuburb);
    Candidate newCandidate(testCandidateID, testParty, testCandidateName, testCandidateAge, testCandidateSuburb);

    cout << "Candidate: ";
    if(newCandidate == testCandidate){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

    //Test Voter Equal Operator
    unsigned long testVoterID = 123456789;
    string testVoterName = "Test Name";
    unsigned char testVoterAge = 32;
    string testVoterSuburb = "Test Suburb";

    Voter testVoter(testVoterID, testVoterName, testVoterAge, testVoterSuburb);
    Voter newVoter(testVoterID, testVoterName, testVoterAge, testVoterSuburb);

    cout << "Voter: ";
    if(newVoter == testVoter){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;
}

void TestBinaryConversion(){
    cout << "Testing Binary Conversion\n";
    
    //Test Candidate Binary Conversion
    unsigned long testCandidateID = 123456789;
    string testParty = "Test Party";
    string testCandidateName = "Test Name";
    unsigned char testCandidateAge = 32;
    string testCandidateSuburb = "Test Suburb";

    Candidate testCandidate(testCandidateID, testParty, testCandidateName, testCandidateAge, testCandidateSuburb);
    Candidate newCandidate(testCandidate.ToBinary());
    
    cout << "Candidate: ";
    if(newCandidate == testCandidate){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

    //Test Voter Binary Conversion
    unsigned long testVoterID = 123456789;
    string testVoterName = "Test Name";
    unsigned char testVoterAge = 32;
    string testVoterSuburb = "Test Suburb";

    Voter testVoter(testVoterID, testVoterName, testVoterAge, testVoterSuburb);
    Voter newVoter(testVoter.ToBinary());

    cout << "Voter: ";
    if(newVoter == testVoter){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;
}

void TestVote_Class(){
    cout << "Testing Voting\n";
    
    //Test Candidate Voting Function
    unsigned long testCandidateID = 123456789;
    string testParty = "Test Party";
    string testCandidateName = "Test Name";
    unsigned char testCandidateAge = 32;
    string testCandidateSuburb = "Test Suburb";

    Candidate testCandidate(testCandidateID, testParty, testCandidateName, testCandidateAge, testCandidateSuburb);
    testCandidate.Vote();

    cout << "Candidate: ";
    if(1 == testCandidate.Count()){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

    //Test Voter Voting Function
    unsigned long testVoterID = 123456789;
    string testVoterName = "Test Name";
    unsigned char testVoterAge = 32;
    string testVoterSuburb = "Test Suburb";

    Voter testVoter(testVoterID, testVoterName, testVoterAge, testVoterSuburb);
    testVoter.Vote();

    cout << "Voter: ";
    if(testVoter.Status()){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;
}