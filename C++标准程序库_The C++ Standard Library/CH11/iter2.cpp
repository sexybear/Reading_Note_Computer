#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool nocase_compare(char c1,char c2)
{
  return toupper(c1) == toupper(c2);
}

int main()
{
  string s1("this is a string");
  string s2("STRING");

  if(s1.size() == s2.size() && equal(s1.begin(),s1.end(),s2.begin(),nocase_compare))
  {
    cout << "the stirngs are equal"<< endl;
  }
  else
  {
    cout << "the strings are not equal"<< endl;
  }

  stirng::iterator pos;
  pos = search(s1.begin(),s1.end(),s2.begin(),s2.end(),nocase_compare);

  if(pos == s1.end())
  {
    cout <<"s2 is not a substring of s1"<< endl;
  }
  else{
    cout << "*" <<s2<<"\"is a substring of\""<<s1<<"\"(at index"<<pos-s1.begin()<<")"<<endl;
  }
}
