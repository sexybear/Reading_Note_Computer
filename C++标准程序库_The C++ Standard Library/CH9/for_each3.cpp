#include "algostuff.hpp"
using namespace std;

class MeanValue
{
private:
  long num;
  long sum;

public:
  MeanValue():num(0),sum(0){}
  void operatror() (int elem)
  {
    num++;
    sum += elem;
  }
  operator double()
  {
    return static_cast<double>(sum)/static_cast<double>(num);
  }
};

int main()
{
  vector<int> coll;
  INSERT_ELEMENTS(coll,1,8);

  double mv = for_each(coll.begin(),coll.end(),MeanValue());
  cout << "mean value: "<<mv<<endl;
}
