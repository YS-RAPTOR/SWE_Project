#pragma once
#define STRINGBITS 8
#include <string>
#include <bitset>

using namespace std;

//Candidate Class
class Candidate{
private:
    //Fields a Candidate can have
    unsigned long m_candidateID;
    string m_party;
    string m_name;
    unsigned char m_age;
    string m_suburb;
    unsigned long m_count;
    
public:
    //Constructors
    Candidate(unsigned long candidateID, string party,  string name, unsigned char age, string suburb);
    Candidate(string binary);
    Candidate(){}

    //Convert Candidate to Binary
    string ToBinary();

    //Print Information about the Candidate
    void PrintInfo();

    //Operators
    bool operator==(const Candidate& other);
    
    //Getters
    unsigned long CandidateID(){
        return m_candidateID;
    }
    string Party(){
        return m_party;
    }
    string Name(){
        return m_name;
    }
    unsigned char Age(){
        return m_age;
    }
    string Suburb(){
        return m_suburb;
    }
    unsigned long Count(){
        return m_count;
    }
};

//Voter Class
class Voter{
private:
    //Fields a Voter can have
    unsigned long m_voterID;
    string m_name;
    unsigned char m_age;
    string m_suburb;
    bool m_status;

public:
    //Constructors
    Voter(unsigned long voterID, string name, unsigned char age, string suburb);
    Voter(string binary);
    Voter(){}

    //Convert Voter to Binary
    string ToBinary();

    //Print Information about the Voter
    void PrintInfo();

    //Operators
    bool operator==(const Voter& other);

    //Getters
    unsigned long VoterID(){
        return m_voterID;
    }
    string Name(){
        return m_name;
    }
    unsigned char Age(){
        return m_age;
    }
    string Suburb(){
        return m_suburb;
    }
    bool Status(){
        return m_status;
    }
};

//Helper Functions
string StringToBinary(string str);
string BinaryToString(string bin);
unsigned long BinaryToULong(string bin);
unsigned char BinaryToUChar(string bin);

