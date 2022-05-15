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

    #ifdef TESTING
    remove(CANDIDATE_DATA_LOCATION);
    remove(VOTER_DATA_LOCATION);
    #endif
}

//Reset File Streams
void Database::ResetCandidateTable(bool beginning){
    m_candidateTable.clear();
    if(beginning)
        m_candidateTable.seekg(0, ios_base::beg);
    else
        m_candidateTable.seekg(0, ios_base::end);
}

//Reset File Streams
void Database::ResetVoterTable(bool beginning){
    m_voterTable.clear();
    if(beginning)
        m_voterTable.seekg(0, ios_base::beg);
    else
        m_voterTable.seekg(0, ios_base::end);
}

//Returns all Values that Satisfy a Query Function
vector<Candidate> Database::CandidateQuery(bool (*query)(Candidate candidate, Candidate check), Candidate check, bool allResults){
    ResetCandidateTable(true);
    string data;
    vector<Candidate> results;
    while (getline(m_candidateTable, data)){
        data += '\n';
        Candidate candidate(data);
        if(query(candidate, check)){
            results.push_back(candidate);
            if(!allResults) break;
        }
    }
    bool op = m_candidateTable.is_open();
    return results;
}

vector<Voter> Database::VoterQuery(bool (*query)(Voter voter, Voter check), Voter check, bool allResults){
    ResetVoterTable(true);
    string data;
    vector<Voter> results;
    while (getline(m_voterTable, data, '\n')){
        data += '\n';
        Voter voter(data);
        if(query(voter, check)){
            results.push_back(voter);
            if(!allResults) break;
        }
    }
    return results;
}

//Writes the Binary Data into the Tables. Also Checks if the status is fine.
void Database::WriteToCandidateTable(Candidate candidate){
    ResetCandidateTable(false);
    if(!m_candidateTableStatus) return;
    m_candidateTable << candidate.ToBinary();
    m_candidateTable << flush;
}

void Database::WriteToVoterTable(Voter voter){
    ResetVoterTable(false);
    if(!m_voterTableStatus) return;
    m_voterTable << voter.ToBinary();
    m_voterTable << flush;
}

void Database::ReplaceCandidate(Candidate candidateToReplace, Candidate newCandidate){
    ResetCandidateTable(true);
    ofstream temp(TEMP_DATA_LOCATION);
    string data;
    while (getline(m_candidateTable, data, '\n')){
        data += '\n';
        Candidate candidate(data);
        if(candidate == candidateToReplace){\
            temp << newCandidate.ToBinary();
        }else
            temp << data;
    }

    temp << flush;

    ///Close File Streams to Rename the files
    m_candidateTable.close();
    temp.close();

    remove(CANDIDATE_DATA_LOCATION);
    rename(TEMP_DATA_LOCATION, CANDIDATE_DATA_LOCATION);

    m_candidateTable.open(CANDIDATE_DATA_LOCATION);
}

void Database::ReplaceVoter(Voter voterToReplace, Voter newVoter){
    ResetVoterTable(true);
    ofstream temp(TEMP_DATA_LOCATION);
    string data;
    while (getline(m_voterTable, data, '\n')){
        data += '\n';
        Voter voter(data);
        if(voter == voterToReplace){\
            temp << newVoter.ToBinary();
        }else
            temp << data;
    }

    temp << flush;

    ///Close File Streams to Rename the files
    m_voterTable.close();
    temp.close();

    remove(VOTER_DATA_LOCATION);
    rename(TEMP_DATA_LOCATION, VOTER_DATA_LOCATION);

    m_voterTable.open(VOTER_DATA_LOCATION);
}

bool Database::Vote(Voter& voter, unsigned long candidateID, string party){
    //Creates Query According the Conditions Given. Query is a lambda Expression.
    Candidate check;
    bool (*query)(Candidate candidate, Candidate check);

    if(candidateID){
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

    //Applying the Voting.
    Candidate candidateToBeReplaced = results[0];
    results[0].Vote();

    Voter voterToBeReplaced = voter;
    voter.Vote();

    //Replacing the data in the database
    ReplaceCandidate(candidateToBeReplaced, results[0]);
    ReplaceVoter(voterToBeReplaced, voter);
    
    return true;
}

vector<Candidate> Database::CandidateVoteInfo(bool most){
    ResetCandidateTable(true);
    vector<Candidate> results;
    bool (*compare)(unsigned long a, unsigned long b);
    unsigned long pass;
    int lines = 0;
    string data;

    if(most){
        pass = 0;
        compare = [](unsigned long a, unsigned long b) -> bool{
            return a > b;
        };
    }else{
        pass = ULONG_MAX;
        compare = [](unsigned long a, unsigned long b) -> bool{
            return a < b;
        };
    }   

    while (getline(m_candidateTable, data, '\n')){
        Candidate candidate(data + '\n');
        lines++;
        if(compare(candidate.Count(), pass)){
            pass = candidate.Count();
            results.clear();
            results.push_back(candidate);

        //Add more Candidates have Tied
        }else if(candidate.Count() == pass){
            results.push_back(candidate);
        }
    }

    //Check If Everyone has Zero Votes.
    if(results[0].Count() == 0 && results.size() == lines) results.clear();


    return results;
}
