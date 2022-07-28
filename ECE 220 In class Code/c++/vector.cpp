#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<int> a;      //default constructor (Size = 0)
    vector<int> b(4, 3);    //parametrized construction (size, initial values )
    cout<<"size of a: "<< a.size()<<endl;
    for(int i=0; i < a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;

    cout<<"size of b: "<< b.size()<<endl;
    for(int i=0; i < b.size(); i++)
        cout<<b[i]<<" ";
    cout<<endl;
    for(int i=0; i < 2; i++)
        a.push_back(i);
    cout<<"size of a: "<< a.size()<<endl;
    for(int i=0; i < a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;


}

/*  //Iterator Example-> works for both vectors and lists 

    list<int> data;     //declare container
    list<int>::iterator it; //declare iterator
    for(it = data.begin(); it!= data.end(); it++){
        cout<<*it<<endl;        //looks like pointer, but is actually not a pointer 
    }
*/