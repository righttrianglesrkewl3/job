#include <iostream>
#include <typeinfo>
#include <string>
#include <cstring>

using std::string;
using std::cout;
using std::endl;
// remember: size() and length() functions are just synonyms and they both do exactly the same thing

// using str.size()
int main()
{
  string str = "cessna180";

  cout << "String length = " << str.size() << endl;

  return 0;

}

// using str.length()
// int main()
// {
//   string str = "cessna180";
//
//   cout << "String length = " << str.size() << endl;
//
//   return 0;
//
// }

// example to get length of C-style string (as opposted to String Object)
// int main()
// {
//   char str[] = "C++ programming language";
//
//   // you can also use str.length()
//   // need #include <cstring> "header" to use
//   cout << "String length = " << strlen(str) << endl;
//
//   return 0;
//
// }
