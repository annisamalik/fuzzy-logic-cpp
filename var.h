#ifndef VAR_H_INCLUDED
#define VAR_H_INCLUDED
#include <iostream>
#include <iomanip>


using namespace std;

void trapesiumTT(int x, float &nilai1, string &sifat1, float &nilai2, string &sifat2);
void trapesiumWW(int x, float &nilai1, string &sifat1, float &nilai2, string &sifat2);
string fuzzyRule(string tt, string w);
float fuzzyRuleAnd(float itt, float iw);
float fuzzyRuleOr(float rendah[]);


#endif // VAR_H_INCLUDED
