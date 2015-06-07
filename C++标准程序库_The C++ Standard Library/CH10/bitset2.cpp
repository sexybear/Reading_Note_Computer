#include <bitset>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
  cout << "267 as binary short: "<< bitset<numeric_limits<unsigned short>::digits>(267)<<endl;

  cout << "267 as binary long:" << bitset<numeric_limits<unsigned long>::digits>(267)<<endl;

  cout << "10.000.000 with 24 bits:"<<bitset<24>(1e7)<<endl;

  cout << "\"1000101011\"as number:"<<bitset<100>(string("1000101011")).to_ulong()<< endl;
}
