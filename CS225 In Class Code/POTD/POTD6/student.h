// Your code here! :)
#pragma once
#include <string>
using std::string;

namespace potd {
    class Student {
        public:
            Student();
            Student(string name, int grade);
            void set_name(string name);
            void set_grade(int grade);
            string get_name();
            int get_grade();
        private:
            string name_;
            int grade_;
    };
}