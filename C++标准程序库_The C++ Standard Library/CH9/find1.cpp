#include "algostuff.hpp"

using namespace std;

int main()
{
  list<int> coll;

  INSERT_ELEMENTS(coll,1,9);
  INSERT_ELEMENTS(coll,1,9);

  PRINT_ELEMENTS(coll,"coll: ");

  list<int>::iterator pos1;
  pos1 = find(coll.begin(),coll.end(),4);

  list<int>::iterator pos2;
  if(pos1 != coll.end())
  {
    pos2 = find(++pos,coll.end(),4);
  }

  if(pos1 != coll.end() && pos2 != coll.end())
  {
    copy(--pos1,++pos2,ostream_iterator<int>(cout," "));
    cout << endl;
  }
}
