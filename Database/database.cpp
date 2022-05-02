#include "database.h"

Database::Database(){
    //Make Data Folder if it Doesn't Exist
    if(!filesystem::is_directory(DATA_LOCATION)){
        filesystem::create_directory(DATA_LOCATION);
    }

    //Make Tables if they don't Exist
    m_candidateTable.open(CANDIDATE_DATA_LOCATION, ios_base::app | ios_base::in);
    m_voterTable.open(VOTER_DATA_LOCATION, ios_base::app | ios_base::in);

    m_candidateTableStatus = m_candidateTable.is_open();
    m_voterTableStatus = m_voterTable.is_open();
}

Database::~Database(){
    //Close File Streams
    m_candidateTable.close();
    m_voterTable.close();
}

//Returns all Values that Satisfy a Query Function
vector<Candidate> Database::CandidateQuery(bool (*query)(Candidate candidate, Candidate check), Candidate check, bool allResults){
    string data;
    vector<Candidate> results;
    while (getline(m_candidateTable, data, '\n')){
        Candidate candidate(data);
        if(query(candidate, check)){
            results.push_back(candidate);
            if(!allResults) break;
        }
    }
    return results;
}

vector<Voter> Database::VoterQuery(bool (*query)(Voter voter) , bool allResults){
    string data;
    vector<Voter> results;
    while (getline(m_voterTable, data, '\n')){
        Voter voter(data);
        if(query(voter)){
            results.push_back(voter);
            if(!allResults) break;
        }
    }
    return results;
}

//Writes the Binary Data into the Tables. Also Checks if the status is fine.
void Database::WriteToCandidateTable(Candidate candidate){
    if(!m_candidateTableStatus) return;
    m_candidateTable << candidate.ToBinary();
}

void Database::WriteToVoterTable(Voter voter){
    if(!m_voterTableStatus) return;
    m_voterTable << voter.ToBinary();
}

bool Database::Vote(Voter voter, unsigned long candidateID, string party){
    //Creates Query According the Conditions Given. Query is a lambda Expression.
    Candidate check;
    bool (*query)(Candidate candidate, Candidate check);

    if(!candidateID){
        check = Candidate(candidateID, "", "", 0, voter.Suburb());
        query = [](Candidate candidate, Candidate check) -> bool{
            if(candidate.CandidateID() == check.CandidateID() && candidate.Suburb() == check.Suburb()){
                return true;
            }else return false;
        };
    }else if(!party.empty()){
        check = Candidate(0, party, "", 0, voter.Suburb());
        query = [](Candidate candidate, Candidate check) -> bool{
            if(candidate.Party() == check.Party() && candidate.Suburb() == check.Suburb()){
                return true;
            }else return false;
        };
    }else{
        return false;
    }

    //Query Info
    vector<Candidate> results = CandidateQuery(query, check, true);

    //Check if the Query Returned a Candidate and Check if There are Multiple Candidates with the Same Query.
    if(results.empty()){
        return false;
    }else if(results.size() > 1){
        return false;
    }

    //TODO Delete Candidate

    //TODO Delete Voter

    //TODO Write Candidate with 1 more vote

    //TODO Write Voter with status True

    return true;
}

vector<Candidate> CandidateVoteInfo(bool most){
    vector<Candidate> can;
    return can;
}

