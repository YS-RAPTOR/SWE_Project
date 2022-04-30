#pragma once
#define STRINGBITS 8
#include <string>
#include <bitset>

using namespace std;

class Candidate{
private:
    unsigned long m_candidateID;
    string m_party;
    string m_name;
    unsigned char m_age;
    string m_suburb;
    unsigned long m_count;
public:
    Candidate(unsigned long candidateID, string party,  string name, unsigned char age, string suburb);
    Candidate(string binary);
    string ToBinary();

    //Operators
    bool operator==(const Candidate& other);
};

class Voter{
private:
    unsigned long m_voterID;
    string m_name;
    unsigned char m_age;
    string m_suburb;
    bool m_status;
public:
    Voter(unsigned long voterID, string name, unsigned char age, string suburb);
    Voter(string binary);
    string ToBinary();

    //Operators
    bool operator==(const Voter& other);
};

//Helper Functions
string StringToBinary(string str);
string BinaryToString(string bin);
unsigned char BinaryToULong(string bin);
unsigned long BinaryToUChar(string bin);

