#include <iostream>
#include <string>   //make string class avaliable
#include <cstring> //c-style string library
using namespace std;

/*
    #include <string>:可以合法使用string类
        strlen(arr)
        strcpy(arr1,arr2)  把arr2赋值给arr1
        strcat(arr1,arr2)  把arr2拼接到arr1后面
    #include <string.h> 让字符数组 char arr[size]使用string的操作
        string s1;
        s1.size(); 返回字符串长度 
*/


void test_char(){
    static const int arrsize1=10;
    static const int arrsize2=11;
    char arr1[arrsize1];
    char arr2[arrsize2];
    cin.get(arr1,arrsize1).get();
    cin.getline(arr2,arrsize2);
    cout<<"arr1:"<<arr1<<endl;
    cout<<"arr2:"<<arr2<<endl;

    strcpy(arr2,arr1);
    cout<<"after strcpy arr2 is:"<<arr2<<endl;

    char arr3[arrsize2];
    strcpy(arr3,arr1);
    strcat(arr3,arr2);
    cout<<"arr3 is:"<<arr3<<endl;


}

void test_string_class(){
    string s1="hello ";
    string s2="World";
    cout<<s1.size()<<endl;  //返回字符串长度 类方法
    string s3=s1+s2;
    cout<<"s3=s1+s2="<<s3<<endl;
    s2=s1;
    cout<<"s2=s1="<<s2<<endl;

   



}

int main(){
    //test_char();
    //test_string_class();
    cout<<R"+*("hello,(world)")+*"<<endl;
    return 0;

     
}