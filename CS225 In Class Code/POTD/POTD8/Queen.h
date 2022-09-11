#pragma once
#include "Piece.h"
#include <string>
using std::string;

class Queen : public Piece {
    public: 
        std::string getType();
};
