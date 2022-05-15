#include "UI.h"
#include "database.h"


int main(){
    // Database::instance().WriteToCandidateTable(Candidate((unsigned long)102838834, "Labour Party 1", "Yashan", 25, "Hawthorn East"));
    // Database::instance().WriteToCandidateTable(Candidate((unsigned long)102838835, "Labour Party 2", "Mallika", 22, "Hawthorn"));
    // Database::instance().WriteToCandidateTable(Candidate((unsigned long)102838832, "Labour Party 3", "Suma", 22, "Glenferrie"));

    // Database::instance().WriteToVoterTable(Voter((unsigned long)102838834, "Yashan", 25, "Hawthorn East"));
    // Database::instance().WriteToVoterTable(Voter((unsigned long)102838835, "Mallika", 22, "Hawthorn"));
    // Database::instance().WriteToVoterTable(Voter((unsigned long)102838832, "Suma", 22, "Glenferrie"));
    UI();
    return 0;
}
