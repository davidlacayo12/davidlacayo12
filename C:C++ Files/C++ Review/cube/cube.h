#pragma once        //header/inclusion guard --> only use/read this file ONCE. It allows us to make sure that we do not end up with a cycle 

namespace cs225 {    
    class Cube {
        public:     //interface for everyone
            Cube();
            Cube(double length);     //default constructor -->custom constructor -->adding in your own constructor gets rid of the default one 
            Cube(const Cube & other);   //copy constructor

            double getVolume() const;   //if using const, must change in .h file
            double getSurfaceArea();
            void setLength(double length);

        private:        //private interface (not for everyone)
            double length_;     //<-- private is really TO CLASS 

    };
}
    