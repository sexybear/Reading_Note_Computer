#include <iostream>
#include <string>

using namespace std;

int main(int argc,char** argv)
{
  const string delims("\t,.;");
  string line;

  while(getline(cin,line))
  {
    string::size_type begIdx,endIdx;

    begIdx = line.find_first_not_of(delims);

    while(begIdx != string::npos)
    {
      endIdx = line.find_first_of(delims,begIdx);

      if(endIdx == string::npos)
      {
        endIdx = line.length();
      }

      for(int i=endIdx-1;i>=static_cast<int>(begIdx);--i)
      {
        cout << line[i];
      }

      cout << ' ';

      begIdx = line.find_first_not_of(delims,endIdx);
    }
    cout << endl;
  }
}
