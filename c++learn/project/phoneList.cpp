#include <iostream>
using namespace std;
#include <string>
#define MAX 1000
#include <cstring>


//联系人 和通讯录的结构体
struct person{
    string name;
    string number;

};

struct addressBook{
    int size;
    struct person members[MAX];
};

//展示主菜单

void showMenu(){
    cout<<"1.add"<<endl;
    cout<<"2.delete"<<endl;
    cout<<"3.Search"<<endl;
    cout<<"4.show_Info"<<endl;
    cout<<"0.Exit"<<endl;

}


int emptyAddressBook(addressBook *ab)
{
   if(ab->size==0)
   {
    return 0;
   }
   return 1;
}


void addPerson(addressBook *ab)
{  
   if(ab->size==MAX) return;
   cout<<"please enter the name"<<endl;
   cin>>ab->members[ab->size].name;
   cout<<"please enter his/her numbers"<<endl;
   cin>>ab->members[ab->size].number;
   ab->size++;

}

int searchPerson_delete(addressBook *ab,int *pa)
{    cout<<"who do you wanna fine"<<endl;
     string name;
     cin>>name;
     for(int i=0;i<ab->size;i++)
     {
         if(name==ab->members[i].name)
         {
            cout<<"already found"<<endl;
            cout<<"name is"<<ab->members[i].name<<" "<<"number is"<<ab->members[i].number<<endl;
            *pa=i;
            return 1;

         }  
     }
     cout<<"None exist such guy"<<endl;
     return 0;
}

void show_Info(addressBook ab)
{   
    cout<<"Now the phone list is"<<endl;
    for(int i=0;i<ab.size;i++)
    {
        cout<<"name is"<<ab.members[i].name<<"  "
        <<"number is"<<ab.members[i].number<<endl;

    }

}

int searchPerson(addressBook *ab)
{    cout<<"who do you wanna fine"<<endl;
     string name;
     cin>>name;
     for(int i=0;i<ab->size;i++)
     {
         if(name==ab->members[i].name)
         {
            cout<<"already found"<<endl;
            cout<<"name is"<<ab->members[i].name<<" "<<"number is"<<ab->members[i].number<<endl;
            return 1;

         }  
     }
     cout<<"None exist such guy"<<endl;
     return 0;
}




void deletePerson(addressBook *ab)
{   /*先查询此人是否存在，如果不存在，输出不存在
       如果存在，查询此人的index，
           */ 
    if(ab->size==0) 
    {   cout<<"Empty phonelist";
        return;
    }
    int index=0;
    
    if(searchPerson_delete(ab,&index))
    {   cout<<"deleting..."<<endl;
           for(int i=index;i<ab->size;i++)
              {ab->members[i]=ab->members[i+1];}
        ab->size--;
        cout<<"already deleted";
    }
    else
      cout<<"not found"<<endl;
    return;


}

void clearAllPerson(addressBook *ab)
{
    delete ab;

}


int main(){
    //1.构建主菜单
     //addressBook *ab
     showMenu();
     addressBook AddressList;
     AddressList.size=0;
    
    
    //2.选择需要进行的工作：
     while(true){
        int flag=0;
     cout<<"what do you wanna do"<<endl;
     cin>>flag;
     switch (flag)
     {
     case 1:addPerson(&AddressList);//添加联系人
        break;
     case 2://删除联系人
        deletePerson(&AddressList);
        break;
     case 3://查询联系人
     {
     searchPerson(&AddressList);
    break;}
     case 4://展示当前联系人
     show_Info(AddressList);
     break;
     case 0://退出
     cout<<"welcome next use,bye";
     system("pause");
     return 0;
     default:
     return 0;
     system("pause");
     return 0;   
     }

     }
}







