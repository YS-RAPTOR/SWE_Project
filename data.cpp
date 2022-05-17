#include "database.h"

int main(){
    if(!filesystem::is_directory(DATA_LOCATION)){
        //Write Candidates
        Database::instance().WriteToCandidateTable(Candidate());
        Database::instance().WriteToCandidateTable(Candidate());
        Database::instance().WriteToCandidateTable(Candidate());
        Database::instance().WriteToCandidateTable(Candidate());
        Database::instance().WriteToCandidateTable(Candidate());
        Database::instance().WriteToCandidateTable(Candidate());
        Database::instance().WriteToCandidateTable(Candidate());
        Database::instance().WriteToCandidateTable(Candidate());
        Database::instance().WriteToCandidateTable(Candidate());
        Database::instance().WriteToCandidateTable(Candidate());

        //Write Voters
        Database::instance().WriteToVoterTable(Voter());
        Database::instance().WriteToVoterTable(Voter());
        Database::instance().WriteToVoterTable(Voter());
        Database::instance().WriteToVoterTable(Voter());
        Database::instance().WriteToVoterTable(Voter());
        Database::instance().WriteToVoterTable(Voter());
        Database::instance().WriteToVoterTable(Voter());
        Database::instance().WriteToVoterTable(Voter());
        Database::instance().WriteToVoterTable(Voter());
        Database::instance().WriteToVoterTable(Voter());
    }
}