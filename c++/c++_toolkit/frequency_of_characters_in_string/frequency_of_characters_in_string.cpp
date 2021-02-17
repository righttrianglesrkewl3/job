#include <iostream>
#include <string>
#include <stdio.h>
#include <sqlite3.h>
using std::string;
using std::cout;
using std::endl;
using std::cin;


int main()
{
  string str1 = "Some string";
  int count = 0;
  char checkCharacter = 'a';

  for (int i = 0; i < static_cast<int>(str1.size()); i++)
  {
    if (str1[i] == checkCharacter)
    {
      count ++;
    }
  }

  cout << "Number of " << checkCharacter << " = " << count << endl;

  return 0;
}
