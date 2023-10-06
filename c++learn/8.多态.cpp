#include <iostream>
using namespace std;
/***********多态***********/

class Animal{
public:
    virtual void speak(){

        cout<<"speak_animal"<<endl;
    }
};

class cat:public Animal{
public:
    void speak(){
        cout<<"miao~"<<endl;
    }
};

void dospeak(Animal &animal){
    animal.speak();

}

void test_01(){
    cat cat;
    dospeak(cat);

}


//多态好处
class calculate{
public:
    int m1;
    int m2;
    virtual int calculate_1(){
        return 0;
    }

};

class calculate_plus:public calculate
{
    int calculate_1(){
        return m1+m2;
    }
};

class calculate_multiple:public calculate
{
    int calculate_1(){
        return m1*m2;
    }
};

void test_caculate(){
    calculate* ca1=new calculate_multiple;
    ca1->m1=10;
    ca1->m2=20;
    cout<<ca1->calculate_1()<<endl;
    
}


/*纯虚函数和抽象类*/
/*
    纯虚函数：virtual [return_type] fun_name=0;
    只要有个纯虚函数，这个类成为抽象类
    特点：
    1.无法实例化对象
    2.抽象类的子类，必须要重写父类的纯虚函数，否则也属于抽象类
Wrong like：

Base{
public:
    virtual void fun()=0;
};

than go:
void test(){
    Base base1; //wrong

}
*/

class Base{
public:
    virtual void fun()=0;//虚函数内代码实现无意义
};

class son:public Base{

public:
    virtual void fun(){//子类必须重写父类的纯虚函数，不然报错
        cout<<"void fun"<<endl;

    }  
};

void test_virtual_fun(){
    Base *base=new son;
    base->fun();

}


/*案例 制作饮品*/
/*
煮水-冲泡-倒入杯中-加入辅料
*/

class make_drinks{
public:
    virtual void make_hotwater()=0;
    virtual void pourIn_water()=0;
    virtual void pourInto_cup()=0;
    virtual void addSome()=0;

    void fun_make_drinks(){
        make_hotwater();
        pourIn_water();
        pourInto_cup();
        addSome();

    }
};


class make_tea:public make_drinks{
public:
     void make_hotwater(){
        cout<<"fire the water to 100 C"<<endl;
    }
     void pourIn_water(){
        cout<<"pout in tear"<<endl;

    }
     void pourInto_cup(){
        cout<<"pour into a cup"<<endl;

    }
     void addSome(){
        cout<<"pour into milk"<<endl;
    }

};

void test_make_drinks(){
    make_drinks *tea=new make_tea;
    tea->fun_make_drinks();

}



int main(){
    //test_caculate();
    //test_virtual_fun();
    test_make_drinks();
   
    
    return 0;
}