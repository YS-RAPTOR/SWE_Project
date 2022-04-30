#include "table.h"
#include <iostream>

using namespace std;
/*Candidate Class*/

//Default Constructor
Candidate::Candidate(unsigned long candidateID, string party,  string name, unsigned char age, string suburb)
    : m_candidateID(candidateID), m_party(party), m_name(name), m_age(age), m_suburb(suburb), m_count(0)
{}

//Convert Binary to Candidate
Candidate::Candidate(string binary){
    string temp;
    int field;
    
    for (size_t i = 0; i < binary.length(); i++){
        if(binary[i] == '|' || binary[i] == '\n'){
            switch (field){
            case 0:
                m_candidateID = BinaryToULong(temp);
                cout << m_candidateID;
                break;
            case 1:
                m_party = BinaryToString(temp);
                break;
            case 2:
                m_name = BinaryToString(temp);
                break;
            case 3:
                m_age = BinaryToUChar(temp);
                break;
            case 4:
                m_suburb = BinaryToString(temp);
                break;
            case 5:
                m_count = BinaryToULong(temp);
                break;
            }
            field++;
            temp = "";
        }else{
            temp += binary[i];
        }
    }
}

//Convert Candidate To Binary
string Candidate::ToBinary(){
    //Convert numbers to binary
    bitset<32> candidateID_B(m_candidateID);
    bitset<8> age_B(m_age);
    bitset<32> count_B(m_count);
    
    //Convert Strings to Binary
    string party_B = StringToBinary(m_party);
    string name_B = StringToBinary(m_name);
    string suburb_B = StringToBinary(m_suburb);

    return candidateID_B.to_string() + "|" + party_B + "|" + name_B + "|" + age_B.to_string() + "|" + m_suburb + "|" + count_B.to_string() + '\n';
}

//==Operator
bool Candidate::operator==(const Candidate& other) {
    if(
        this->m_candidateID == other.m_candidateID && 
        this->m_party == other.m_party && 
        this->m_name == other.m_name && 
        this->m_age == other.m_age && 
        this->m_suburb == other.m_suburb && 
        this->m_count == other.m_count
    ){
        return true;
    }else return false;
    
}

/*Voter Class*/

//Default Constructor
Voter::Voter(unsigned long voterID, string name, unsigned char age, string suburb)
    : m_voterID(voterID), m_name(name), m_age(age), m_suburb(suburb), m_status(0)
{}

//Convert Binary to Voter
Voter::Voter(string binary){
    string temp;
    int field;
    
    for (size_t i = 0; i < binary.length(); i++){
        if(binary[i] == '|' || binary[i] == '\n'){
            switch (field){
            case 0:
                m_voterID = BinaryToULong(temp);
                break;
            case 1:
                m_name = BinaryToString(temp);
                break;
            case 2:
                m_age = BinaryToULong(temp);
            case 3:
                m_status = true ? (temp == "1") : false;
            case 4:
                m_suburb = BinaryToString(temp);
            }
            field++;
            temp = "";
        }else{
            temp += binary[i];
        }
    }
    
}

//Convert Voter to Binary
string Voter::ToBinary(){
    //convert numbers to binary
    bitset<32> voterID_B(m_voterID);
    bitset<8> age_B(m_age);
    
    //convert strings to binary
    string name_B = StringToBinary(m_name);
    string suburb_B = StringToBinary(m_name);
    
    //convert boolean to binary
    char status_B = '1' ? m_status : '0';

    return voterID_B.to_string() + "|" + name_B + "|" + suburb_B + "|" + age_B.to_string() + "|" + status_B + '\n';
    
}

//==Operator
bool Voter::operator==(const Voter& other){
    if(
        this->m_voterID == other.m_voterID && 
        this->m_name == other.m_name && 
        this->m_age == other.m_age && 
        this->m_suburb == other.m_suburb
    ){
        return true;
    }else return false;
}


/*Helper Functions*/

string StringToBinary(string str){
    string binary = "";
    for(int i = 0; i < str.length(); ++i){
        bitset<STRINGBITS> bits(str[i]);
        binary += bits.to_string();
    }
    return binary;
}

string BinaryToString(string bin){
    string str;
    for (size_t i = 0; i < bin.length(); i += STRINGBITS){
        bitset<STRINGBITS> temp(bin.substr(i, STRINGBITS));
        str += (unsigned char)temp.to_ulong();
    }
    return str;
}

unsigned char BinaryToULong(string bin){
    return bitset<32>(bin).to_ulong();
}

unsigned long BinaryToUChar(string bin){
    return (unsigned char)bitset<8>(bin).to_ulong();
}

