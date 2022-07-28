#include <iostream>



using namespace std;

template <typename T>
class Point{
    private:
        int x,y;
    public:
        Point(int _x=0, int _y=0){x=_x; y=_y;}
        void ShowPosition(){cout<<x<<", "<<y<<endl;}
};

template <typename T>
class Data{
        T data;
    public: 
        Data(T d){
            data = d;
        }
        void ShowData(){
            cout<<data<<endl;
        }
};

template <typename T>
void swap(T &a,T &b){       //swap function for any data type using template and references 
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    Point<int> p1(1,2);
    Point<int> p2(10,11);
    swap(p1, p2);
    p1.ShowPosition(); // Expect (10,11)
    p2.ShowPosition(); // Expect (1,2)
    int a = 0, b = 3;
    swap(a,b);
    cout<<a<<", "<<b<<endl; // Expect (3,0)
}