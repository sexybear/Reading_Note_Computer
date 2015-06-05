#include "algostuff.hpp"
using namespace std;

void print(int elem)
{
  cout << elem << " ";
}

int main()
{
  vector <int> coll;
  INSERT_ELEMENTS(coll,1,9);

  for_each(coll.begin(),coll.end(),print);

  coll << endl;
}
