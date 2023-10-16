#include <iostream>
#include <cstring>
using namespace std;

void test_arr_size(){   //Page 77 程序说明
    /*
    区分字符串长度          strlen()
    字符串大小-及数组大小    sizeof()
    计算字符串长度及大小，注意字符串大小包括末尾的 '\0'
    */
    char arr[]="abcde";
    int size;
    size=sizeof(arr)/sizeof(char);// =sizeof(arr) char bytes=1
    cout<<"the size is:"<<size<<"\n";                   //6
    cout<<"the length of arr is:"<<strlen(arr)<<endl;   //5
    /*
    字符串读取'\0'为end
    */
    arr[2]='\0';
    cout<<arr;      //ab

}



void test_getline_get(){ //Page 80
/*
面向行的输入
    1.getline
        读取整行，cin遇到空格、制表符、换行符确定字符串结束位置
        getline(arr_name,size)
        只显式读取size-1个字符，要留一个'\0'
    2.get
        cin.get(arr,name)
        注意：
            cin.get(arr,arrsize);
            cin.get(arr,arrsize);
            两次调用cin.get(arr,size)会出现问题，因为cin.get(arr,size)不会读取并丢弃换行符，
            所以再次调用会直接遇到换行符而不读取任何字符，因此需要加上cin.get()将换行符读取掉
    ****：可以使用cin.get(arr,arrsize).get() 因为cin.get(arr,size)返回一个cin对象
*/
    int size;
    const int arrsize=20;
    //const int arrsize=3;
    
    char arr[arrsize]{};

    cout<<"<please cin string>"<<endl;
    cin.getline(arr,arrsize);
    cout<<arr<<endl;    

    // cin.get(arr,arrsize);
    // cout<<arr<<endl;
    // cin.get();//读取换行符
    // cin.get(arr,arrsize);
    // cout<<arr<<endl;
    cin.get(arr,arrsize).get();
    cout<<arr<<endl;
    cin.get(arr,arrsize);
    cout<<arr<<endl;


}



int main(){
    //test_arr_size();
    
    test_getline_get();

}