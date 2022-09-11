#include <string>
#include "Pet.h"

using namespace std;

// Put your constructor code here!
Pet::Pet() {
  name_ = "Rover";
  birth_year_ = 2018;
  type_ = "dog";
  owner_name_ = "Wade";
}
Pet::Pet(string name, int birth_year, string type, string owner_name) {
    name_ = name;
    birth_year_ = birth_year;
    type_ = type;
    owner_name_ = owner_name;
  }

void Pet::setName(string newName) {
  name_ = newName;
}

void Pet::setBY(int newBY) {
  birth_year_ = newBY;
}

void Pet::setType(string newType) {
  type_ = newType;
}

void Pet::setOwnerName(string newName) {
  owner_name_ = newName;
}

string Pet::getName() {
  return name_;
}

int Pet::getBY() {
  return birth_year_;
}

string Pet::getType() {
  return type_;
}

string Pet::getOwnerName() {
  return owner_name_;
}
