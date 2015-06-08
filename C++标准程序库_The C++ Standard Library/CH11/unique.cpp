#include <iostream>
#include <string>
#include <algorithm>
#include <locale>

using namespace std;

class bothWhiteSpaces
{
private:
    const locale& loc;

  public:
    bothWhiteSpaces(const locale& l):loc(1){}
    bool operator()(char elem1,char elem2)
    {
      return isspace(elem1,loc)&&isspace(elem2,loc);
    }
};

int main()
{
  string contents;

  cin.unsetf(ios::skipws);

  unique_copy(istream_iterator<char>(cin),istream_iterator<char>(),back_inserter(contents),bothWhiteSpaces(cin.getloc()));

  cout << contents;
}
