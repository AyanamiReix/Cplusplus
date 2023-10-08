#include <iostream>
using namespace std;

/*
this-指针
    1.解决名称冲突
    2.返回对象本身用*this
*/


class person{
public:    
    person(int age){
     this->age=age;
    }
    int age;
    person &add_age(const person &p ){
        this->age=this->age+p.age;
        return *this;
        //这边返回值要加取地址，要不然就是开辟一个临时变量，赋值给临时变量了
    } 

};

void test(){
    person p1(18);
    cout<<p1.age<<endl;
    person p2=p1;
    p1.add_age(p2).add_age(p2);
    cout<<"new_age"<<p1.age<<endl;
}


/*
空指针调用成员函数
*/

class person2{
public:
    void showPersonAge(){

        //cout<<"age="<<m_age<<endl;
        //actually cout<<this-m_age<<endl;
        //but here this=p=NULL,so the figure is nothing
        //so we would use like this:
        if(this==NULL){
           return;
        }
    }
    int m_age;



};


void test_01(){
    person2 *p=NULL;
    p->showPersonAge();

}


/*const 修饰成员函数
常函数


常对象



*/

class person3{
public:
    person3(){

    }
    //this 指针的本质是指针常量，指向不可以改
    //person3* const this;
    //成员函数后面加const。本质修饰的是this指针，让指针指向的值也不可修改
    //变为 const person3 * const this
    void showPerson()const //注意const的位置
    {
      //m_A=100; 
      //this=NULL;
      //this->m_A=100;
      this->m_B=100;
    }
    void fun2(){

    }

    int m_A;
    mutable int m_B;//特殊变量，即使是在常函数中，也可以修改这个值，加关键字mutable

};

void test_011(){
    
    const person3 p;
    p.m_B=200;
    cout<<p.m_B<<endl;
    //p2.m_A=100;
    //常对象只能调用常函数 fun2()不是常函数 无const
    //p.fun2();
    
    
}





int main(){
    test_011();
    return 0;

}