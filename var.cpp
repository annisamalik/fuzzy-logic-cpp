#include "var.h"

void trapesiumTT(int x, float &nilai1, string &sifat1, float &nilai2, string &sifat2){
    if (x<=30 || x>=90 || (x>=50 && x<=70)){
        nilai1 = 1;
        if (x<=30)
            sifat1 = "rendah";
        else if (x>=50 && x<=70)
            sifat1 = "sedang";
        else if (x>=90)
            sifat1 = "tinggi";
        nilai2 = -99;
        sifat2 = "t";
    } else if (x>30 && x<50){
            sifat1= "rendah";
            nilai1= (-1*(x-50))/(float)(50-30);
            sifat2= "sedang";
            nilai2= (x-30)/(float)(50-30);
    } else if (x>70 && x<90){
            sifat1= "sedang";
            nilai1= (-1*(x-90))/(float)(90-70);
            sifat2= "tinggi";
            nilai2= (x-70)/(float)(90-70);
    }
}

void trapesiumWW(int x, float &nilai1, string &sifat1, float &nilai2, string &sifat2){
    if (x<=25 || x>=80 || (x>=35 && x<=70)){
        nilai1 = 1;
        if (x<=25)
            sifat1 = "rendah";
        else if (x>=35 && x<=70)
            sifat1 = "sedang";
        else if (x>=80)
            sifat1 = "tinggi";
        nilai2 = -99;
        sifat2 = "t";
    } else if (x>25 && x<35){
            sifat1= "rendah";
            nilai1= (-1*(x-35))/(float)(35-25);
            sifat2= "sedang";
            nilai2= (x-25)/(float)(35-25);
    } else if (x>70 && x<80){
            sifat1= "sedang";
            nilai1= (-1*(x-80))/(float)(80-70);
            sifat2= "tinggi";
            nilai2= (x-70)/(float)(80-70);
    }
}

string fuzzyRule(string tt, string w){
    if (tt=="t" || w=="t")
        return "t";
    else if (tt=="rendah"){
        if (w=="rendah")
            return "tidak";
        else if (w=="sedang")
            return "tidak";
        else if (w=="tinggi")
            return "ya";
    } else if (tt=="sedang"){
        if (w=="rendah")
            return "tidak";
        else if (w=="sedang")
            return "ya";
        else if (w=="tinggi")
            return "ya";
    } else if (tt=="tinggi"){
        if (w=="rendah")
            return "ya";
        else if (w=="sedang")
            return "ya";
        else if (w=="tinggi")
            return "ya";
    } else
        return "t";
}

float fuzzyRuleAnd(float itt, float iw){
    if (itt<iw)
        return itt;
    else
        return iw;

}

float fuzzyRuleOr(float rendah[]){
    int i = 0;
    float Nmax = rendah[i];
    while (rendah[i]!=NULL){
        if (rendah[i]>Nmax)
            Nmax = rendah[i];
        i++;
    }
    return Nmax;
}



