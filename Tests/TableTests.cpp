#include "TableTests.h"

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
    cout << "Voter: ";

    unsigned long testVoterID = 123456789;
    string testVoterName = "Test Name";
    unsigned char testVoterAge = 32;
    string testVoterSuburb = "Test Suburb";
    bool testVoterStatus = "Test Status";

    Voter testVoter(testVoterID, testVoterName, testVoterAge, testVoterSuburb);
    Voter newVoter(testVoter.ToBinary());

    if(newVoter == testVoter){
        cout << "Passed";
    }else{
        cout << "Failed";
    }
    cout << endl;

}


