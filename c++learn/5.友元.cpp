#include <iostream>
using namespace std;
#include <string>

/*
    友元
    1.全局函数做友元
    2.类做友元
    3.成员函数做友元

*/
//全局函数做友元
class house{
    //friend + 全局函数 ->全局函数可以访问 private 内容
    friend void goodGay(house *house1);


public:
    string m_sittingRome;
    house(){
        m_sittingRome="sitRoom";
        m_bedroom="bedRoom";
    }


private:
    string m_bedroom;


};

void goodGay(house *house1){
    cout<<"visit  "<<house1->m_sittingRome<<endl;
    cout<<"visit  "<<house1->m_bedroom<<endl;

}


//类做友元
class Building{
   friend class GoodGay;
public:
    Building();
    string sittingRoom;
  

private:
    string bedRoom;

};

class GoodGay{
public:
    Building *build;
    GoodGay();
    void visit();
};

//类外写成员函数
Building::Building(){
     bedRoom="5StarBedRoom";
     sittingRoom="3starSitRoom";

}

GoodGay::GoodGay(){
        //创建建筑物对象
        build=new Building;
}

void GoodGay::visit(){
    cout<<"Gay is visiting..."<<build->sittingRoom<<endl;
    cout<<"Gay is visiting..."<<build->bedRoom<<endl;

}



//成员函数做友元
class Jie;
class myhouse;

class Jie{
public:
    Jie();
    myhouse *aya_house;
    void day_visit();
    void mid_night_visit();


};

class myhouse{

    friend void Jie::mid_night_visit();
public:  
    myhouse();
    string sex_name1;
private:
    void sex_with_aya();
    string  sex_name;
};


myhouse::myhouse(){
    sex_name="aya";
    sex_name1="babby";
}

Jie::Jie(){
    aya_house=new myhouse;
}

void Jie::day_visit(){
    cout<<"sex with..."<<aya_house->sex_name1<<endl;
}
void Jie::mid_night_visit(){

    cout<<"sex_with..."<<aya_house->sex_name<<endl;
}




void test(){
//  house house1;
//  goodGay(&house1);
    // GoodGay GAY1;
    // GAY1.visit();
    Jie jieLUO;
    jieLUO.mid_night_visit();
    jieLUO.day_visit();


}


int main(){
    test();

    return 0;
}