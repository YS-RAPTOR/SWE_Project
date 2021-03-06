#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <cstdio>
#include <string>

#include "table.h"

#define DATA_LOCATION "Data"
#define CANDIDATE_DATA_LOCATION "Data/Candidate.txt"
#define VOTER_DATA_LOCATION "Data/Voter.txt"
#define TEMP_DATA_LOCATION "Data/.temp.txt"
// #define TESTING

using namespace std;

//Singleton Class
class Database{
private:
    //Reset file Streams
    void ResetCandidateTable(bool beginning);
    void ResetVoterTable(bool beginning);

    //File Stream for Text Files
    fstream m_voterTable;
    fstream m_candidateTable;

    //Constructors and Destructors
    Database();
    ~Database();

public:
    //Returns static instance
    static Database& instance(){
        static Database instance;
        return instance;
    }

    //Deleting assignment opperator and default constructor
    Database(Database const&) = delete;
    void operator=(Database const&) = delete;

    //Query Tables
    vector<Candidate> CandidateQuery(bool (*query)(Candidate candidate, Candidate check) , Candidate check, bool allResults);
    vector<Voter> VoterQuery(bool (*query)(Voter voter, Voter check), Voter check, bool allResults);

    //Write Information to the Text File. Used for testing
    void WriteToCandidateTable(Candidate candidate);
    void WriteToVoterTable(Voter voter);

    //Edit Information in the Database
    void ReplaceCandidate(Candidate candidateToReplace, Candidate newCandidate);
    void ReplaceVoter(Voter voterToReplace, Voter newVoter);

    //Special Functions for Voting and FInding Candidate with Most or Least amount of Votes.
    bool Vote(Voter& voter, unsigned long candidateID, string party);
    vector<Candidate> CandidateVoteInfo(bool most);
};
