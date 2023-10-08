#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
操作文件的三大类:
    1.ofstream: 写操作
    2.ifstream: 读操作
    3.fstream : 读写操作


5.1.1写文件
写文件步骤如下:
    1.包含头文件
    #include <fstream>
    2.创建流对象
    ofstream ofs;
    3.打开文件
    ofs.open("文件路径",打开方式);
    4.写数据
    ofs <<"写入的数据";
    5.关闭文件
    ofs.close():


*/

void test_ostream(){

    ofstream ofs;
    ofs.open("text111.txt",ios::out);

    ofs<<"name is aya"<<endl;
    ofs<<"lover is Jie"<<endl;

    ofs.close();


}


void test_ifstream(){
    ifstream ifs;
    ifs.open("text111.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<<"failure open"<<endl;
        return;
    }

    //读数据
    //version 1:
    // char buf[1024]={0};
    // while(ifs>>buf){
    //     cout<<buf<<endl;
    // }
    
    //version 2:
    // char buf1[1024]={0};
    // while(ifs.getline(buf1,sizeof(buf1)))
    // {
    //     cout<<buf1<<endl;
    // }


    //version 3:
    // string buf;
    // while(getline(ifs,buf))
    // {
    //     cout<<buf<<endl;
    // }
    // ifs.close();


    //version 3:
    char c;
    while((c==ifs.get())!=EOF){  //EOF end of file
        cout<<c;
    }

}

int main(){
    //test();
    test_ifstream();

    return 0;
}