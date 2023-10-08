#include <iostream>
#include <string>
using namespace std;
/* 虚析构和纯虚析构*/
/*
如果子类开辟了堆区内存，父类不会调用子类的析构函数，所以要用虚析构
like:
class name{
    virtual ~name(){
        cout<<"name_xigou"<<endl;
    }
};

or use 纯虚析构 但需要在类外定义
class name{
    virtual ~name()=0;
}

name::~name(){
    //add some fun or stay NULL..
    cout<<"xigou_name"<<endl;
}


*/

class Animal{
public:
    Animal(){
        cout<<"gouzao_Animal"<<endl;
    }
    virtual void speak()=0;
    virtual ~Animal()=0; //改为虚析构，才会走子类的析构函数
};

Animal::~Animal(){
    cout<<"Animal_xigou"<<endl;
}

class Cat:public Animal{
public:
    Cat(string name){
        cout<<"gouzao_Cat"<<endl;
        this->name=new string(name);
    }
    
    string *name;
    
    ~Cat(){
        if(name!=NULL){
            cout<<"xigou_Cat"<<endl;
            delete name;
            name=NULL;
            
        }
    }
    void speak(){
        cout<<*this->name<<"miao"<<endl;
    }
};

void animal_speak(Animal *animal){ //Animal &animal=cat;(Cat cat)
    animal->speak();


}


void test_speak2(){
    Animal *cat=new Cat("Jerry");
    cat->speak();
    delete cat;
}



/*案例 组装电脑*/
/*
    1.电脑主要组成部件为 CPU (用于计算) ，显卡(用于显示) ，内存条(用于存储)
    2.将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
    3.创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
    4.测试时组装三台不同的电脑进行工作
*/

class CPU{
public:
    virtual void compute()=0;
    virtual ~CPU(){}
};

class Graphics_card{
public:
    virtual void display()=0;
    virtual ~Graphics_card(){}
};

class Memory_Module{
public:
    virtual void storage()=0;
    virtual ~Memory_Module(){}
};

/*cpu、memory_module、garphics_card的类定义一致，
以下不一致，第一个版本是自己写的，第二个版本是按照课程来的
*/

//组装电脑 Version 1
class manufacturer:public CPU,public Graphics_card,public Memory_Module{
public:
    manufacturer(string name){
        this->name=new string(name);

    }
    string *name;

    void compute(){
        cout<<*this->name<<" is computing.."<<endl;
    }

    void display(){
        cout<<*this->name<<" is displaying.."<<endl;
    }

    virtual void storage(){
        cout<<*this->name<<" is storaging.."<<endl;
    }

    ~manufacturer(){
        if(name!=NULL){
            delete name;
            name=NULL;
        }
    }

};

class computer{
public:  
    computer(string cpu,string memory_module,string garphics_card){
        this->cpu=cpu;
        this->memory_module=memory_module;
        this->garphics_card=garphics_card;

    }
    void part_running(){
        manufacturer manufacturer_1(cpu);
        manufacturer_1.compute();
        manufacturer manufacturer_2(memory_module);
        manufacturer_2.storage();
        manufacturer manufacturer_3(garphics_card);
        manufacturer_3.display();
        
    }

private:
     string cpu;
     string memory_module;
     string garphics_card;
    

};

void test_computer(){
    computer computer1("amd","amd","amd");
    computer1.part_running();

}


//组装电脑 Version 2

class IntelCPU:public CPU{
public:
    void compute(){
        cout<<"IntelCPU is computing.."<<endl;
    }
};

class IntelMemory:public Memory_Module{
public:
    void storage(){
        cout<<"IntelMemory is storaging.."<<endl;
    }
};

class IntelGraphics:public Graphics_card{
public:
    void display(){
        cout<<"IntelCPU is displaying.."<<endl;
    }
};


class computer_version2{
public:
    computer_version2(CPU *cpu,Memory_Module *memory_module,Graphics_card *graphics_card){
     this->cpu=cpu;
     this->graph_card=graphics_card;
     this->memory_module=memory_module;
    }

    void running_allParts(){
        cpu->compute();
        memory_module->storage();
        graph_card->display();        

    }

private:
    CPU *cpu;
    Memory_Module *memory_module;
    Graphics_card *graph_card;

};

void test_version2(){

    // wanning：IntelCPU *cpu=new IntelCPU; 错误，应该用父类指针调用，方为多态
    CPU *cpu=new IntelCPU;
    Memory_Module *memory_module=new IntelMemory;
    Graphics_card *graphics_card=new IntelGraphics;
    
    computer_version2 computer(cpu,memory_module,graphics_card);
    computer.running_allParts();
    

}


int main(){
    //test_speak2();
    
    //Version1::
    //test_computer();
    //Version1::
    test_version2();

    return 0;
}