#include "database.h"

int main(){
    if(!filesystem::is_directory(DATA_LOCATION)){
        //Write Candidates
        Database::instance().WriteToCandidateTable(Candidate((unsigned long) 103489594, "Labour Party", "Tom Brady", 23, "Epping"));
        Database::instance().WriteToCandidateTable(Candidate((unsigned long) 104953464, "Greens Party", "Smith", 48, "Thomastown"));
        Database::instance().WriteToCandidateTable(Candidate((unsigned long) 105334243, "Liberal Party", "David Duncan", 68, "Lalor"));
        Database::instance().WriteToCandidateTable(Candidate((unsigned long) 103253434, "Labour Party", "Jack", 24, "Lalor"));
        Database::instance().WriteToCandidateTable(Candidate((unsigned long) 104543432, "United Australia Party", "Bob", 39, "Greensborough"));
        Database::instance().WriteToCandidateTable(Candidate((unsigned long) 104354832, "One Nation Party", "Emanuel Eliza", 70, "Hawthorn"));
        Database::instance().WriteToCandidateTable(Candidate((unsigned long) 103493256, "Labour Party", "Sam White", 43, "Carlton"));
        Database::instance().WriteToCandidateTable(Candidate((unsigned long) 108458335, "Liberal Party", "William Cook", 23, "Richmond"));
        Database::instance().WriteToCandidateTable(Candidate((unsigned long) 103438534, "Centre Alliance Party", "Prajesh", 56, "Southbank"));
        Database::instance().WriteToCandidateTable(Candidate((unsigned long) 106343424, "Liberal Party", "Wosniak", 28, "Bundoora"));
        
        //Write Voters
        Database::instance().WriteToVoterTable(Voter((unsigned long) 103244354, "Isaac Hayes", 25, "Epping"));
        Database::instance().WriteToVoterTable(Voter((unsigned long) 102354345, "Dylan", 32, "Thomastown"));
        Database::instance().WriteToVoterTable(Voter((unsigned long) 103453643, "Steven", 53, "Lalor"));
        Database::instance().WriteToVoterTable(Voter((unsigned long) 103234235, "Michael Till", 60, "Lalor"));
        Database::instance().WriteToVoterTable(Voter((unsigned long) 103453563, "Kelly", 28, "Greensborough"));
        Database::instance().WriteToVoterTable(Voter((unsigned long) 106543544, "Jay", 27, "Hawthorn"));
        Database::instance().WriteToVoterTable(Voter((unsigned long) 103434643, "Campbell", 36, "Carlton"));
        Database::instance().WriteToVoterTable(Voter((unsigned long) 109785634, "Rob", 40, "Richmond"));
        Database::instance().WriteToVoterTable(Voter((unsigned long) 104675445, "Tina Tina", 18, "Southbank"));
        Database::instance().WriteToVoterTable(Voter((unsigned long) 107345273, "Samantha", 24, "Bundoora"));
    }
}