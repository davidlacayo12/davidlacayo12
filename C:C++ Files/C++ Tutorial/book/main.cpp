#include <iostream>     //C++ Library
#include <cmath>        //math library 
#include <iomanip>      //Allows for number manipulation in C++, i.e. suffixes during type declaration 
#include <ios>
#include <iomanip>

using namespace std;    //allows us to not put std:: in front of every cout or cin
void sayHi(string name, int age);
double add(double one, double two);
double subtract(double one, double two);
double exp(double base, double power);

class Book {
    public: 
        string title;
        string author;
        int pages;

        Book(){
            title = "no title";
            author = "no author";
            pages = 0;
        }

        Book(string aTitle, string aAuthor, int aPages){
            title = aTitle;
            author = aAuthor;
            pages = aPages;
        }
};

class Student {
    public:
        string name;
        string major;
        double gpa;
        
        Student(string aName, string aMajor, double aGPA){
            name = aName;
            major = aMajor;
            gpa = aGPA;
        }

        bool hasHonors(){
            if(gpa >= 3.5)
                return true;
            return false;
        }

};

class Movie{
    private:
        string rating;
    public:
        string title;
        string director;

        Movie(string aTitle, string aDirector, string aRating){
            title = aTitle;
            director = aDirector;
            setRating(aRating);
        }

        void setRating(string aRating){
            if(aRating == "G" || aRating == "PG" || aRating == "PG-13" || aRating == "R" || aRating == "NR")
                rating = aRating;
            else    
                rating = "NR";
        }

        string getRating(){
            return rating;
        }
};

class Chef {
    public: 
        void makeChicken(){
            cout << "The chef makes chicken" <<endl;
        }
        void makeSalad(){
            cout << "The chef makes salad" <<endl;
        }
        void makeSpecialDish(){
            cout << "The chef makes bbq ribs" <<endl;
        }

};

class ItalianChef : public Chef{        //italian chef inherits atributes of chef class 
    public: 
        void makePasta(){
            cout << "The chef makes pasta" <<endl;
        }
        void makeSpecialDish(){
            cout << "The chef makes chicken parm" <<endl;
        }
};



int main()
{


   // Movie avengers("The Avengers", "Joss Whedon", "PG-13");

    //cout << avengers.title << endl;

  // Student student1("Jim", "Business", 2.4);
   //Student student2("Pam","Art",3.6);


   //cout << student1.hasHonors() << endl;
   //cout << student2.hasHonors() << endl;
   
   // Book book1("Harry Potter", "JK Rowling", 500);
    //Book book2("Legend", "Marie Lu", 300);

  
    
    //cout << book1.title << endl;
    //cout << book2.title << endl;


    //2D Array with Nested For Loop to print out each element in array
    /*
    int numberGrid[3][2] = {
        {1,2},
        {3,4},
        {5,6}        
    };
 
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 2; j++){
            cout << numberGrid[i][j];
        }
        cout << endl;
    }
    */

   //Pointers
    /*
    int age = 19;
    int *age_pointer = &age;
    double gpa = 2.7;
    string name = "David";
    
    cout << "Age: " << age<<endl;
    cout<< "Age memory: "<< age_pointer<<endl;
    cout<< &age<<endl;          //same  output as previous line
    cout<<*age_pointer<<endl;   //dereferencing age_pointer 

    */

    return 0;
}












/*double add(double one, double two){
    return (one+two);
}
double subtract(double one, double two){
    return (one-two);
}
double exp(double base, double power){
    double result = 1;
    if(power > 0){
        for(int i = 0; i < power; i++){
            result = result*base;
        }
        return result;
    }
    else if(power == 0){
        return result;
    }
    else
        return -1;
}
*/
