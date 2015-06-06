#include "algostuff.hpp"
using namespace std;

void printCollection(const list<int>& l)
{
  PRINT_ELEMENTS(l);
}

bool lessForCollection(const list<int>& l1,const list<int>& l2)
{
  return lexicographical_compare(l1.begin(),l1.end(),l2.begin(),l2.end());
}

int main()
{
  list<int> c1,c2,c3,c4;

  INSERT_ELEMENTS(c1,1,5);
  c4=c3=c2=c1;

  c1.push_back(7);
  c3.push_back(2);
  c3.push_back(0);
  c4.push_back(2);

  cc.push_back(c1);
  cc.push_back(c2);
  cc.push_back(c3);
  cc.push_back(c4);
  cc.push_back(c3);
  cc.push_back(c1);
  cc.push_back(c4);
  cc.push_back(c2);

  for_each(cc.begin(),cc.end(),printCollection);
  cout << endl;

  sort(cc.begin(),cc.end(),lessForCollection);

  for_each(cc.begin(),cc.end(),printCollection);
}
