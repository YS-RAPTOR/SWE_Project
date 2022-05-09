#include "TableTests.h"
#include "DatabaseTests.h"

int main(){
    cout << "------------------------------------------------" << endl;
    TestOperatorEqual();
    TestBinaryConversion();
    TestVote_Class();

    TestIO();
    TestQuery();
    TestReplace();
    TestCandidateInfo();
    TestVote_Database();
    
    return 0;
}
