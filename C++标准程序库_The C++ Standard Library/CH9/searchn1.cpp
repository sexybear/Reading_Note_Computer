#include "algostuff.hpp"
using namespace std;

int main()
{
  deque<int> coll;

  INSERT_ELEMENTS(coll,1,9);
  PRINT_ELEMENTS(coll);

  deque<int>::iterator pos;
  pos = search_n(coll.begin(),coll.end(),4,3);

  if(pos != coll.end())
  {
    cout << "four consecutive elements with value 3"<< "start with "<<distance(col.begin(),pos)+1<<".element"<<endl;
  }
  else
  {
    cout << "no four consecutive elements with value 3 found"<<endl;
  }

  pos = search_n(coll.begin(),coll.end(),4,3,greater<int>());

  if(pos != coll.end())
  {
    cout <<"four comsecutive elements with value > 3"<< "start with "<< distance(coll.begin(),pos)+1<<".element"<<endl;
  }
  else
  {
    cout << "no four consecutive elements with value > 3 found"<< endl;
  }
}
