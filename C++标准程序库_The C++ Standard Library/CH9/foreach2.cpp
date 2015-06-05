#include "algostuff.hpp"
using namespace std;

template <class T>
class AddValue
{
private:
  T theValue;

public:
  AddValue(const T& v):theValue(v){}

  void operator() (T& elem) const{
    elem += theValue;
  }
};

int main()
{
  vector<int> coll;
  INSERT_ELEMENTS(coll,1,9);
  for_each(coll.begin(),coll.end(),AddValue<int>(10));
  PRINT_ELEMENTS(coll);

  for_each(coll.begin(),coll.end(),AddValue<int>(*coll.begin()));
  PRINT_ELEMENTS(coll);
}
