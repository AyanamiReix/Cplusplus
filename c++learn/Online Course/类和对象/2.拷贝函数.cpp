#include <iostream>

using namespace std;

/*
1.构造函数（fun1）与析构函数（fun2）,它们都无返回值
编译器每次都会< 自动调用>，但是为空

构造函数： 类名(){
}
析构函数  ~类名(){
}


2.构造函数的分类及调用
分类
    按照参数分类 无参构造（默认构造）和有参构造Person(int)
    按照类型分类 普通构造/拷贝构造函数


3. 拷贝构造函数调用时机
    1.使用已经存在的对象来初始化新对象
    2.值传递的方式给函数参数传值
    3.值的方式返回局部对象
    注意事项：1.如果调用了有参构造，编译器不在默认提供默认无参构造,但仍然提供拷贝构造
            2.如果提供了拷贝构造函数，那么编译器不再默认提供 无参和有参构造（自己写可以）


4.深拷贝与浅拷贝：如果属性有在堆区开辟的，要用自己提供的拷贝构造函数，防止浅拷贝带来的问题
注意：vc使用浅拷贝（编译器自己提供的拷贝函数没有报错，但是只执行了一次析构函数，且堆区指针地址相同）

*/




class Person{
public:
    
    Person(){
        cout<<"fun1"<<endl;
    }
    Person(int a){
        age=a;
        cout<<"fun1:youcan"<<endl;
    }
    
    //拷贝构造函数：将传入的人身上的所有属性，拷贝到自身身上
    Person(const Person &p){
            cout<<"copy_fun"<<endl;
            age=p.age;
    }
    
    ~Person(){
        
        cout<<"fun2"<<endl;
    }


    int age;
private:
    

};

//调用
void test01(){
    //1.括号法
    //注意事项：调用默认构造函数的时候，不要加()
    //Person p1() 会被编译器认为是一个函数声明
    Person p1;
    Person p2(10);
    Person p3(p2);//拷贝构造函数的调用
    cout<<"p2_age"<<" "<<p2.age<<endl;
    cout<<"p3_age"<<" "<<p3.age<<endl;
    
    //2.显示法
    // Person p1;
    // Person p2=Person(10);
    // Person p3=Person(p2);


    //3.隐式转换法
    Person p4=10;  //==Person p4=Person(10)
    Person p5=p4;  //拷贝构造
}


//深拷贝与浅拷贝

class stu{
public:
   stu(){
    cout<<"wucan_fun"<<endl;
   }//无参构造函数 
   

   stu(int a,int gr){
        cout<<"youcan_fun"<<endl;
        age=a;
        grade=new int(gr);

   }//有参构造

   stu(const stu &stu_copy){
       cout<<"copy_fun"<<endl;
       age=stu_copy.age;
       //浅拷贝实现：grade=stu_copy.grade; 不知道为什么vc没有报错
       grade=new int(*stu_copy.grade);//利用深拷贝解决问题
   }//拷贝构造函数

   ~stu(){
        if(grade!=NULL){
            delete grade;
            grade=NULL;
        }
        cout<<"xigou_fun"<<endl;

 
   }//析构函数

   int age;
   int *grade;

};

void test_copy(){
    stu stu1(10,60);
    cout<<"stu1_age"<<stu1.age<<"stu1_grade"<<*stu1.grade<<endl;
    stu stu2(stu1);
    cout<<"stu2_age"<<stu2.age<<"stu2_grade"<<*stu2.grade<<endl;

}
 

int main(){
    //test01();
    test_copy();
 
    
    return 0;
}


