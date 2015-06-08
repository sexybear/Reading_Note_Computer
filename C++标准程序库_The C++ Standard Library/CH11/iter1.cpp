#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
  string s("the zip code of hodelage in germany is 38108");

  cout << "orginal: "<<s<< endl;

  transform(s.begin(),s.end(),s.begin(),tolower);
  cout << "lowered: "<<s << endl;

  transform(s.begin(),s.end(),s.begin(),toupper);
  cout << "uppered: "<<s <<endl;
}
