#pragma once

#include <iostream>
#include<string>
#include<cstdlib>
#include <cctype>
#include <windows.h>
#include "table.h"
#include "database.h"

using namespace std;

Voter Login();
void UI();
char Menu();
bool AreYouSure();
bool IsCandidateID(string data);

void voteprint();
void cand_record(char cand);

