
#include "var.h"

using namespace std;

int main()
{

    int TesTulis[] = {55, 98, 31, 30, 88, 19, 63, 69, 46, 15, 22, 39, 92, 71, 38, 20, 38, 83, 37, 73, 19, 48, 92, 18, 77, 11, 57, 26};
    int Wawan[] = {21, 95, 82, 20, 47, 92, 56, 41, 87, 28, 48, 63, 19, 75, 26, 37, 79, 22, 50, 31, 40, 16, 8, 36, 28, 81, 49, 90};
    cout<<"Data Tes Tulis"<<endl;
    int n = sizeof(TesTulis)/sizeof(TesTulis[0]);
    for (int i = 0; i<n; i++) {
        cout<<TesTulis[i]<<", ";
    }
    cout<<endl;
    cout<<"Data Wawancara"<<endl;
    for (int i = 0; i<n; i++) {
        cout<<Wawan[i]<<", ";
    }
    cout<<endl<<endl;

    for (int q = 0; q<n; q++) {
        cout<<"-----------------------------------------DATA "<<q<<"------------------------------------------------"<<endl;
        cout<<">>Fuzzyfication<<"<<endl;
        string s1a, s2a, s1b, s2b;
        float n1a, n2a, n1b, n2b;
        trapesiumTT(TesTulis[q], n1a, s1a, n2a, s2a);
        trapesiumWW(Wawan[q], n1b, s1b, n2b, s2b);

        cout<<"Tes Tulis "<<s1a<<" "<<n1a<<" ";
        if (s2a!="t")
            cout<<s2a<<" "<<n2a;
        cout<<endl<<"Wawancara "<<s1b<<" "<<n1b<<" ";
        if (s2b!="t")
            cout<<s2b<<" "<<n2b;
        float YAi[4], TIDAKi[4];
        float angka1 = fuzzyRuleAnd(n1a, n1b);
        float angka2 = fuzzyRuleAnd(n1a, n2b);
        float angka3 = fuzzyRuleAnd(n2a, n1b);
        float angka4 = fuzzyRuleAnd(n2a, n2b);


        int i = -1; int j = -1; string temp, YA[4], TIDAK[4];
        temp = fuzzyRule(s1a, s1b);
        if (temp=="ya"){
            i++; YA[i] =  temp;
            YAi[i] = angka1;
        } else if (temp=="tidak"){
            j++; TIDAK[j] = temp;
            TIDAKi[j]= angka1;
        }

        temp = fuzzyRule(s1a, s2b);
        if (temp=="ya"){
            i++; YA[i] =  temp;
            YAi[i]= angka2;
        } else if (temp=="tidak"){
            j++; TIDAK[j] = temp;
            TIDAKi[j]= angka2;
        }
        temp = fuzzyRule(s2a, s1b);
        if (temp=="ya"){
            i++; //YA[i] =  temp;
            YAi[i] = angka3;
        } else if (temp=="tidak"){
            j++; //TIDAK[j] = temp;
            TIDAKi[j]= angka3;}
        temp = fuzzyRule(s2a, s2b);
        if (temp=="ya"){
            i++; //YA[i] =  temp;
            YAi[i] = angka4;
        } else if (temp=="tidak"){
            j++; //TIDAK[j] = temp;
            TIDAKi[j]= angka4;
        }

        float yap, nop;
        yap = 0.0; nop = 0.0;
        cout<<endl<<endl<<">>Inference<<"<<endl<<"NK"<<endl;
        if (i!=-1){
            cout<<"Ya ";
            yap = fuzzyRuleOr(YAi);
            cout<<yap<<endl;
        }
        if (j!=-1){
            cout<<"Tidak ";
            nop = fuzzyRuleOr(TIDAKi)/(float)(1.0);
            cout<<setprecision(2)<<nop<<endl;
        }

        float hasil;
        cout<<endl<<">>Defuzzyfications<<"<<endl;
        cout<<"Sugeno"<<endl;
        hasil = ((nop*50)+(yap*80))/(yap+nop);
        if (hasil>=80) {
            cout<<"Diterima "<<hasil<<endl;
        } else
            cout<<"Ditolak "<<hasil<<endl;

        cout<<endl<<"Mamdani"<<endl;
        hasil = (((10+20+30+40+50+60)*nop) + ((70+80+90+100)*yap)) / ((6*nop)+(4*yap));
        if (hasil>=65) {
            cout<<"Diterima "<<hasil<<endl;
        } else
            cout<<"Ditolak "<<hasil<<endl<<endl<<endl;
    }






    return 0;
}
