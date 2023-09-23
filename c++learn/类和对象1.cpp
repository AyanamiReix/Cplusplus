#include <iostream>
#include <string>
using namespace std;
const double PI=3.1415926;

class Circle
{
//访问权限：public、private、protected
public:
   //属性
   int r;//半径

   //行为
   double calculate_l(){
     return 2*PI*r;
   }

};//注意这边有;

/*
int main(){
    //通过圆类创建具体对象
    Circle c1;
    //给圆对象 属性赋值
    c1.r=10;
    cout<<"the length is"<<c1.calculate_l()<<endl;
    return 0;
}
*/

/*
访问权限：
public:    成员类内可以访问，类外可以访问
protected: 成员类内可以访问 类外不可以访问 
private:   成员类内可以访问 类外不可以访问
protected、private区别：继承

struct 和 类的区别主要在于默认权限不同，前者为public,后者为private
*/

class person{
public:
    

protected:


private:
   string password;

};



//判断点和⚪的位置关系


class Pos{
public:
    void set_pos(const double x,const double y){
              x_pos=x;
              y_pos=y;

    }//设置坐标
    double get_x(){
        return x_pos;
    }
    double get_y(){
        return y_pos;
    }
private:
    double x_pos;
    double y_pos;

};

class circle_dot{
public:
    void set_circle(double x,double y,double r){     
           pos.set_pos(x,y);
           r_m=r;
    }   

    void pos_circle_dot(Pos dot){
         double distance;
         
         distance=(dot.get_x()-pos.get_x())*(dot.get_x()-pos.get_x())+(dot.get_y()-pos.get_y())*(dot.get_y()-pos.get_y());
        if(distance==r_m*r_m){
            cout<<"on the circle"<<endl;
            return;
        }
        else if(distance<r_m*r_m){
            cout<<"inside"<<endl;
            return;
        }
        cout<<"outside"<<endl;

 
    }


private:
     Pos pos;
     double r_m;


};//构建⚪类

int main(){
    cout<<"please enter x-y-r"<<endl;
    double x,y,r;
    cin>>x>>y>>r;
    circle_dot c1;
    Pos dot1;
    c1.set_circle(x,y,r);
    cout<<"please enter x-y to set a dot"<<endl;
    cin>>x>>y;
    dot1.set_pos(x,y);
    c1.pos_circle_dot(dot1);

    return 0;
}