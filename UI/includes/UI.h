#pragma once

#include <iostream>
#include<string>
#include<cstdlib>
#include <cctype>
#include <windows.h>
#include "table.h"
#include "database.h"

using namespace std;

void UI();
Voter Login();
string Menu();
bool ContainsCharacters(string data);
void PrintCandidate(Voter voter);
void Vote();
bool AreYouSure(string prompt);