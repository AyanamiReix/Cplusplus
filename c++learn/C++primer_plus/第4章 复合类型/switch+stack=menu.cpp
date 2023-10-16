#include <iostream>
#include "stack.h"
using namespace std;

stack::stack(){
    //inialize
    
    cout<<"initializing a stack.."<<endl;
    base=new int[stacksize];
    top=base;
    

}

stack::~stack(){
    cout<<"destroying a stack.."<<endl;
    if(base!=NULL){
        delete base;
        base=NULL;
    }

}


stack::stack(const stack &s){
    this->top=new int(*s.top);
    this->base=new int(*s.base);

}

int stack::isfull()const{
    
    return (top-base==stacksize?1:0);
}

int stack::isempty()const{

    return (top==base?1:0);
}

void stack::push_in(int element){
    if(~isfull())
       { 
        *top=element;
        top++;
       }
    else{
        cout<<"the stack is full"<<endl;
        return;
    }
}
void stack::push_out(int &element){
    if(!isempty())
       {element=*(top-1);
        top--;}
    else{
        cout<<"the stack is empty"<<endl;
        return;

    }

}

void stack::show_top_ele()const{
    cout<<*(top-1)<<endl;
}


void stack::push_in2(){
    int ele;
    cout<<"please cin a num to push in"<<endl;
    cin>>ele;

    if(~isfull())
       { 
        *top=ele;
        top++;
       }
    else{
        cout<<"the stack is full"<<endl;
        return;
    }
}
void stack::push_out2(){
    if(!isempty())
       {
        top--;}
    else{
        cout<<"the stack is empty"<<endl;
        return;

    }

}







 ostream& operator<<( ostream &os,const stack &s){
    for(int i=s.top-s.base-1;i>=0;i--){
       
       os<<"|"<<*(s.top-1-i)<<"|"<<endl; 
       
    }
    return os;

}
/*-------------------以上为类方法的定义-------------------------------*/





void test_stack(){
    stack s1;
    s1.push_in(2);
    s1.show_top_ele();
    int pushout_ele;
    s1.push_out(pushout_ele);
    cout<<pushout_ele<<endl;
    s1.push_out(pushout_ele);
    

}

void test_cout_stack(){
    stack s1;
    s1.push_in(2);
    s1.push_in(3);
    s1.push_in(3);
    s1.push_in(4);
    s1.push_in(5);
    cout<<s1;


}
/*-------------------以上为栈的测试-------------------------------*/



void show_menu(){
    
    cout<<"***********"<<"0.exit"               <<"***********"<<endl;
    cout<<"***********"<<"1.push in a letter"   <<"***********"<<endl<<'\t';
    cout<<"***********"<<"2.push out a letter"  <<"***********"<<endl<<'\t';
    cout<<"***********"<<"3.check the stack"    <<"***********"<<endl<<'\t';
    cout<<"enter a choice"<<endl;

}

int main(){
    //test_stack(); //测试
    //test_cout_stack();
    show_menu();
    int choice;
    cin>>choice;
    stack s;
    while(choice!=0){
        switch(choice)
        {
        
        case 1:
            s.push_in2();
            
            break;
        case 2:
            s.push_out2();
            break;
        case 3:
            cout<<s;
            break;
        default:
            break;
        }
        show_menu();
        cin>>choice;

    }
    return 0;


}