#include <iostream>
using namespace std;

class AbstractEmployee { 
    virtual void AskForPromotion()= 0;
};

class Employee:AbstractEmployee {
private:
    string name;
    string company;
    int age;
public: 
    void setName(string name_){
        name = name_;
    }
    string getName(){
        return name;
    }
    void setCompany(string company_){
        company = company_;
    }
    string getCompany(){
        return company;
    }
    void setAge(int age_){
        age = age_;
    }
    int getAge(){
        return age;
    }

    Employee(string name_, string company_, int age_){
        name = name_;
        company = company_;
        age = age_;
    }

    void IntroduceYourself(string name, string company, int age){
        cout<<"Name- " <<name<<endl;
        cout<<"Company- " <<company<<endl;
        cout<<"Age- " <<age<<endl;

    }  
    void AskForPromotion(){
        if(age>30)
            cout<<name<<" got promoted!"<<endl;
        else    
            cout<<name<<" did not get promoted."<<endl;
    }
};

class Developer:Employee {
public:
    string FavProgrammingLanguage;
    Developer(string name_, string company_, int age_, string FavProgrammingLanguage_):Employee(name_, company_, age_){
        FavProgrammingLanguage = FavProgrammingLanguage_;
    }
    void FixBug() {
        cout<< getName()<<" fixed bug using "<<FavProgrammingLanguage<<endl;
    }

};

int main(){

    Employee employee1 = Employee("David","Amazon", 19);
    Employee employee2 = Employee("Adam", "National Geographic", 17);
    Developer d = Developer("Sara", "Youtube", 14, "C++");
    d.FixBug();
}