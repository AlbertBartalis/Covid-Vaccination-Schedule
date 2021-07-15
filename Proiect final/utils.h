#pragma once
#include <string>
#include <string.h>

using namespace std;

int calculatePriority(int age, int sanitaryConditions);
string formatDisplay(int id, string name, int age, int cond, string city, int priority);
void printMenu();
int getCommand();
int getDoses();
