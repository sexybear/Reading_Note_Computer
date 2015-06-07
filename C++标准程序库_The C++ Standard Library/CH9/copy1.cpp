#include "algostuff.hpp"
using namespace std;

int main()
{
  vector<int> coll1;
  list<int> coll2;

  INSERT_ELEMENTS(coll1,1,9);

  copy(coll1.begin(),coll1.end(),back_inserter(coll2));

  copy(coll2.begin(),coll2.end(),ostream_iterator<int>(cout," "));

  cout << endl;

  copy(coll1.rbegin(),coll2.rend(),coll2.begin());

  copy(coll2.begin(),coll2.end(),ostream_iterator<int>(cout," "));

  cout << endl;
}
