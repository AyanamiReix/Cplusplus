#include <iostream>
using namespace std;


int main(){
    int rats;
    int &ra=rats;
    int *p=&rats;
    cout<<"pointer address"<<p<<endl<<"\t";
    cout<<"reference address"<<&ra<<endl<<"\t";
    cout<<"element address"<<&rats<<endl<<"\t";
     

    return 0;
}