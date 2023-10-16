#include <iostream>
using namespace std;

/*
    1.typename *p=new typename [size]:直接使用p[index]来调用数组元素即可
    2.
        arr[index]=*(arr+index)
        arr=&arr[0]
        
        arr=arr+1 --not allowed 
        typename_arr *p=arr;
        p=p+1     --allowed
    3.
    cout<<arr; --首元素地址
    cout<<&arr;--整个元素地址 虽然这两个地址相同 但是大小不同
    e.g--short:2 bytes 
    short arr[5];
    sizeof(arr)--10 bytes;
    &arr+1     --move 10 bytes

*/


void test_arr_pointer(){
    float *p_arr=new float[3];
    p_arr[0]=0.3;
    p_arr[1]=0.2;
    p_arr[2]=0.5;
    for(int i=0;i<3;i++){
        cout<<"p_"<<i<<"="<<p_arr[i]<<endl;
    }
    p_arr+=1;
      for(int i=0;i<2;i++){
        cout<<"p_"<<i<<"="<<p_arr[i]<<endl;
    }
    
    delete []p_arr;



}



void test_arr(){
    short arr[5]={};
    cout<<sizeof(arr)<<endl;
    cout<<"arr address:"<<arr<<'\t'<<endl<<'\t';
    cout<<"&arr address:"<<&arr<<'\t'<<endl<<'\t';
    cout<<"arr+1:"<<arr+1<<'\t'<<endl<<'\t';
    cout<<"&arr+1:"<<&arr+1<<'\t'<<endl<<'\t';

}


int main(){
    
    //test_arr_pointer();
    test_arr();
    return 0;

}