#include "TableTests.h"
#include "DatabaseTests.h"

int main(){
    cout << "------------------------------------------------" << endl;
    TestOperatorEqual();
    TestBinaryConversion();
    TestVote();

    TestIO();
    TestQuery();
    TestReplace();
    TestVote();
    TestCandidateInfo();
    return 0;
}
