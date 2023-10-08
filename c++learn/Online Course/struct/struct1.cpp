#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct goods{

    int price;
    union
    {
      char id_letter[20];
      long  id_number;
    };

}good1,good2;


struct stu{
char name[20];
int gender;
};


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






enum color{red,blue,pink};
char* getarr(void);

int main(){
    //  int* p=new int[10];
    //  for(int i=0;i<10;i++)
    //  {
    //     *(p+i)=i;
    //     cout<<p[i]<<" ";
    //  }

    //  delete []p;
    // char flowers[10]="rose";
    // cout<<flowers<<"s are red\n"<<endl;
    // char *f=new char[strlen(flowers)+1];
    // strcpy(f,flowers);
    // cout<<f<<endl;
    // cout<<"new address"<<(int*)f<<endl;
    // cout<<"old address"<<(int *)flowers<<endl;
   
    // char *name=NULL;
    // name=getarr();
    // cout<<name<<"at"<<(int*)name<<endl;
    // delete []name;
    // name=getarr();
    // cout<<name<<"at"<<(int*)name<<endl;
    // delete []name;
 
      stu* stulist=new stu[2];
      stulist->gender=1;
      (stulist+1)->gender=2;
      
      cout<<stulist[0].gender<<endl;
      cout<<(stulist[1].gender==1?"male":"female")<<endl;
      //测试auto
      auto ppb=stulist;
      std::cout<<ppb->gender<<endl;
      delete []stulist;



    return 0;
} 

char *getarr(){
      char name[90];
      cin>>name;
      char *temp=new char[strlen(name)+1];
      strcpy(temp,name);
      return temp;
}