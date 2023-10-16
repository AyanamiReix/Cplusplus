#ifndef STACK_H_
using namespace std;

class stack{
    friend void test_stack();
    friend ostream& operator<<(ostream &os,const stack &s);
    int *top,*base;
    static const int stacksize=3;

public:
    stack();
    ~stack();
    stack(const stack &s);//注意深浅拷贝
    void push_in(int);
    void push_out(int&);
    void push_in2();
    void push_out2();
    int isempty()const;
    int isfull()const;
    void show_top_ele()const;
    

};



#endif
