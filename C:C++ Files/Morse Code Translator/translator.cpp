#include <iostream>
using namespace std;

/*The purpose of this program is to take an input string from the user and translate it character by character into morse code */


void traverseString(string str, int length);    //traverses string and allows us to read individual characters inside of the string 
string morseMatch(char arr);    //translates indivudual characters into morse code

int main(){

    while(1){       //while loop allows the program to continue running so that the user can type more than one word
    
    string str;
    cout<< "Input: ";           
    getline(cin, str);  
    int length = str.size();        //calculates length/size of string to be used in the for loop while we traverse the input string 
    traverseString(str, length);    //calls traverse string functions to go character by character through our string 
    
    }

}

void traverseString(string str, int length) {
    //iterates through a string and calls morseMatch function
    for(string::iterator it = str.begin(); it!= str.end(); it++){
        if(isspace(*it)) continue; //protects against spaces, but not against anything else 
        else cout<< morseMatch(*it); 
    }
    cout<<endl; //creates new line after inputs 

}

string morseMatch(char x){
    //matches input character with the correct morse code and returns the right code to be outputted into the terminal 
    switch(x) {
        case '.':
            return "/ ";
        case 'a': 
            return ".- ";
        case 'b': 
            return "-... ";
        case 'c': 
            return "-.-. ";
        case 'd': 
            return "-.. ";
        case 'e': 
            return ". ";
        case 'f': 
            return "..-. ";
        case 'g': 
            return "--. ";
        case 'h': 
            return ".... ";
        case 'i': 
            return ".. ";
        case 'j': 
            return ".--- ";
        case 'k': 
            return "-.- ";
        case 'l': 
            return ".-.. ";
        case 'm': 
            return "-- ";
        case 'n': 
            return "-. ";
        case 'o': 
            return "--- ";
        case 'p': 
            return ".--. ";
        case 'q': 
            return "--.- ";
        case 'r': 
            return ".-. ";
        case 's': 
            return "... ";
        case 't': 
            return "- ";
        case 'u': 
            return "..- ";
        case 'v': 
            return "...- ";
        case 'w': 
            return ".-- ";
        case 'x': 
            return "-..- ";
        case 'y':
            return "-.-- ";
        case 'z': 
            return "--.. ";
        case '1': 
            return ".---- ";
        case '2': 
            return "..--- ";
        case '3': 
            return "...-- ";
        case '4': 
            return "....- ";
        case '5': 
            return "..... ";
        case '6': 
            return "-.... ";
        case '7':
            return "--... ";
        case '8': 
            return "---.. ";
        case '9': 
            return "----. ";
        case '0': 
            return "----- ";

        default: //protects against invalid characters 
            cerr<< "Invalid character"<<x<<' '<<endl;
            exit(0);
       
    }
}
