// your code here
#pragma once
#include "Foo.h"
#include <string>
using std::string;

namespace potd {
    class Bar{
        public:
            Bar(string s);
            Bar(Bar & b);
            ~Bar();
            Bar& operator=(const Bar &obj);
            string get_name();
        private:
            Foo * f_;

};
}
