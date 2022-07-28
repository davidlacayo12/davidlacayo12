#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename T>
class MyStack{
    private:    
        int TOS;        //index for top of the stack 
        int size;       //size of the stack 
        char* data;     //pointer for dynamic array 
    public: 
        MyStack(int _size){size = _size; TOS = 1; data = new T[size];};
        ~ MyStack(){delete []data;};
        void push(const T &value){
            if(full()){
                return;
            }
            TOS++;
            data[TOS] = value;
        };
        T top(){return data[TOS];};     //return to the top
        void pop(){     //remove the top
            if(empty()){
                cout<<"underflow"<<endl;
            }
            TOS--;
        };     
        bool empty(){
            if(TOS == 1){
                return true;
            }
            else
                return false;
        };
        bool full(){
            if(TOS == size-1){
                return true;
            }
            else
                return false;
        };
};


int main(){
    MyStack<char> s(10);
    s.push('A');
    s.push('B');
    s.push('C');
    while(!s.empty()){
    cout<<s.top()<<endl;
     s.pop();
    }
}