#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  const string hello("hello how are you");
  string s(hello.begin(),hello.end());

  stirng::iterator pos;

  for(pos = s.begin();pos!=s.end();++pos)
  {
    cout << *pos;
  }

  cout << endl;

  reverse(s.begin(),s.end());
  cout << "recerse: "<<s<<endl;

  sort(s.begin(),s.end());

  cout << "ordered: "<< s << endl;

  s.erase(unique(s.begin(),s.end()),s.end());

  cout << "no duplicates: "<<s << endl;
}
