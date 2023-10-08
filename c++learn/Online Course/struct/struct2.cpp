#include <iostream>
#include "sawp.h"
using namespace std;
#define day 7
#include <string>


//泡泡排序
void myfun(int arr[],int sz) 
{
   
    int flag=1;
    for (int i=0;i<sz-1;i++) //冒泡排序趟数 sz-1次 
    { 
        for(int j=0;j<sz-i-1;j++) //每一次泡泡排序比较次数 sz-1，sz-2，sz-3
        {
            if(arr[j]>arr[j+1])
            {
                int temp=0;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=0;
            }

        }
        if(flag==1)
        {
            break;
        }

    }


}


//创建学生数据类型： 
struct Stu
{
    string name;
    int age;
    
}stu;

struct teacher{
    int id;
    int age;
    struct Stu arr[5];

};


void printStu(Stu s1)
{
   cout<<s1.age<<s1.name<<endl; 
}

void printpointStu(Stu *s1)
{
   cout<<s1->age<<s1->name<<endl; 
}

struct hero{
string name;
int age;

};

void printInfo(hero arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<"name is"<<arr[i].name<<" "<<arr[i].age<<endl;
    }
}

void bubbleSort(hero arr[],int len)
{
    for(int i=0;i<len-1;i++)
    {int flag=1;
        for (int j=0;j<len-i-1;j++)
        {
            if(arr[j].age<arr[j+1].age)
            {
                int temp=0;
                temp=arr[j].age;
                arr[j].age=arr[j+1].age;
                arr[j+1].age=temp;
                flag=0;
            }
        }
        if (flag==1)
        {
            break;
        }
        
    }


}





int main(){


//1.结构体指针
/*
1.创建学生的结构体变量
2.通过指针指向结构体变量 struct *x=&x;
3.通过指针访问结构体变量中的数据 x->...
*/
//2.结构体嵌套
/*
teacher t1;
teacher *t=&t1;
t->stu.age=18;

*/
//3.结构体作函数参数  //地址传递外侧数据跟着改变
/*
1.将学生传入到一个参数中，打印学生身上所有信息
1.1值传递
Stu s1;
s1.age=18;
s1.name="Aya";
printStu(s1)
**1.2地址传递
main(){Stu s1;
s1.age=18;
s1.name="Aya";
printpointStu(&s1);
return 0;  

void printpointStu(Stu *s1)
{
   cout<<s1->age<<s1->name<<endl; 
}
}


*/
hero arr[]={
    {"diaochan",18},
    {"haha",20},
    {"zhaoyun",100}

};
int len=sizeof(arr)/sizeof(arr[0]);

bubbleSort(arr,len);
printInfo(arr,len);




}







/*
    //const修饰指针
    /*
    1.const int*p=&a;  常量指针
    特点：指针的指向可以修改，但是指针指向的值不可以修改
    
    2.int *const p=&a;   指针常量
    特点：指针的指向不可以改，指针指向的值可以改；
    *p=20 对
    p=&b；错

    3.const int * const p=&a;

    */

/*创建结构体
1、struct Student s1；
2、struct Studnet s2={.....}
3、在定义结构体时顺便创建结构体变量

//结构体数组：
struct Studnet arr[]={
     {},
     {},
     {},
     ...

};
struct Student arr[2]={
{"aya",18},
{"jami",20}
};
cout<<arr[0].age<<arr[0].name<<endl;
cout<<arr[1].age<<arr[1].name<<endl;
for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
{
   cout<<arr[i].age<<arr[i].name<<endl;

}
*/




