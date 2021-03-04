#include <iostream>
#include <string>
using std::string;
using std::endl;
using std::cout;
using std::cin;

int main()
{
  string str1 = "123";
  int num;

  // using stoi() to store the value of str1 to x
  num = std::stoi(str1);

  cout << num << endl;
  
  return 0;
}
