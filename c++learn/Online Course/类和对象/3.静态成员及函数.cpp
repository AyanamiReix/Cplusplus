#include <iostream>
using namespace std;
#include <string>


//初始化列表
class person{
public:
    //初始化列表方式赋初值
    person(int a,int b,int c):m_a(a),m_b(b),m_c(c) //注意冒号位置
    {
    }
    int m_a,m_b,m_c;
 


};

void test_initialize_list(){
    person p1(10,20,30);
    cout<<p1.m_a<<p1.m_b<<p1.m_c<<endl;
}


/****类对象作为类成员*****/


class Phone{
public:
    Phone(string name):phone_name(name){}

    

    string phone_name;
};

class Stu{

public:   // 隐式转换法 Phone p_name=name
    Stu(string name,string ph_name):s_name(name),p_name(ph_name)
    { 
        cout<<"initialize_Stu"<<endl;
    
    }
    string s_name;
    Phone p_name;
    ~Stu(){ }

};

void test_class(){ 
     Stu s1("aya","iphone");
     cout<<"age "<<s1.s_name<<"phone "<<s1.p_name.phone_name<<endl;
}



/*******************静态成员*********************/
/*
静态成员变量 static type name;
    所有对象共享同一份数据
    编译阶段就分配内存
    类内声明，类外初始化操作

    静态成员变量不属于某个对象，所有对象共享同一份数据
    两种访问方式：
    1.通过对象进行访问 
    People p；
    p.m_A=num;
    2. 通过类名进行访问 People::m_A 私有权限类外访问不到

静态成员函数
    所有对象共享同一个函数
    静态成员函数只能访问静态成员变量
*/


class people{
public:
    //类内声明 
    static int m_A;
    static void fun(){
        cout<<"static_fun"<<endl;
        m_A=200;
        //报错：m_B=100;
    }
    int m_B;


};
int people::m_A=100;//类外初始化

void test_people(){
     people p1;
     cout<<p1.m_A<<endl;
     people p2;
     p2.m_A=200;
     cout<<p2.m_A<<endl;

}

void test_people2(){

}

void test_fun_people(){
    //1.通过对象访问
    people p;
    p.fun();
    //2.通过类名访问
    people::fun();

  }



int main(){
    //test_initialize_list();
    //test_class();
    //test_people();
    test_fun_people();
 
    return 0;
}