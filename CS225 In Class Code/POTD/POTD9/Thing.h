#pragma once

#include <string>

namespace potd {
  class Thing {
  public:
    Thing(int size);
    Thing(const Thing & t);
    Thing & operator=(const Thing & t);
    ~Thing();

    int set_property(std::string name,std::string value);
    std::string get_property(std::string name);

  private:

    void _copy(const Thing & t);
    void _destroy();

    std::string *properties_;
    std::string *values_;
    int props_ct_;
    int props_max_;
  };
}
