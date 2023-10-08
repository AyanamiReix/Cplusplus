#include <iostream>
#include <string>
using namespace std;

class father{
public: 
    father(){
        age=40;
    }
    void fun(){
        cout<<"father::fun"<<endl;
    }
    void fun(int a){
        cout<<"father::fun_int a"<<endl;
    }
    int age;

protected:
    int password;

private:
    string lover;

};

class son:public father{
public:
    son(){
        age=20;
    }
    int age;
    void fun(){
        cout<<"son::fun"<<endl;
    }
};

class grandson:public son{
public:
    void fun(){
        age=10;
    }

};

//同名成员属性处理 property
void test_member_element(){
    son s;
    cout<<"son_age "<<s.age<<endl;
    cout<<"father_age"<<s.father::age<<endl;
}

//同名成员函数
void test_member_fun(){
    son s;
    s.fun();
    s.father::fun(10);
    s.father::fun();
}


/*********继承同名静态成员处理方式********/
 
class base{
public:
    static int m_A;

 };
//类内定义，类外赋初值
int base::m_A=100;


class first:public base{
public:
    int static m_A;
 };

 int first::m_A=200;

void test_static_property(){

    first f1;
    //通过对象访问
    cout<<f1.m_A  <<endl;
    cout<<first::m_A  <<endl;
    
    //通过类名访问
    cout<<first::base::m_A<<endl;
    cout<<f1.base::m_A<<endl;

}

void test_static_fun(){


}



/*
多继承grammer: class son:type father 1,type father 2...{}

菱形继承：虚继承 数据只有一份:virtual  关键字
vbptr: virtual base pointer 指针
*/

class grandfather{//虚基类
public:
    int age;

};

//加入virtual关键字 
class father:virtual public grandfather{};

class son:virtual public grandfather{};

class son_son:public son,public father{};

void test_mutiple(){
    son_son s1;
    s1.son::age=18;
    s1.father::age=29;
    cout<<"father_age->"<<s1.father::age<<endl;
    cout<<"son_age->"<<s1.son::age<<endl;  
    cout<<s1.age<<endl;  

}


int main(){
    //test_member_element();
    //test_member_fun();
    //test_static_property();
    test_static_fun();

    return 0;
}