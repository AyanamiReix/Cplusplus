#include <iostream>
#include <cstring>
#include <string>
using namespace std;
void qi_say()
{
     cout<<"you are a pig"<<endl;

}

void jie_say()
{
    cout<<"you are a dog"<<endl;
     
    }

void fox_say(void (*pf)())
{
     (*pf)();

}

double calculate(double);
double square(double r,double(*pf)(double));

int main(){
    fox_say(qi_say);
    double r=3.44;
    square(r,calculate);


    return 0;
}
double calculate(double r){


    return r*r;
}

double square(double r,double(*pf)(double)){
     
      cout<<pf(r)<<endl; 
     
}