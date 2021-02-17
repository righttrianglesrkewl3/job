// #include <iostream>
// #include <string>
// #include <stdio.h>
// #include <sqlite3.h>
// using std::string;
// using std::cout;
// using std::endl;
// using std::cin;


// int main()
// {
//   string str1 = "Some string";
//   int count = 0;
//   char checkCharacter = 'a';
//
//   for (int i = 0; i < static_cast<int>(str1.size()); i++)
//   {
//     if (str1[i] == checkCharacter)
//     {
//       count ++;
//     }
//   }
//
//   cout << "There are " << count << " " << checkCharacter << "'s in the string: " << str1 << endl;
//
//   return 0;
// }
#include <sqlite_orm/sqlite_orm.h>

#include <string>
#include <iostream>
#include <cassert>

using namespace sqlite_orm;

using std::cout;
using std::endl;

struct RapArtist {
    int id;
    std::string name;
};

int main(int, char **) {

    auto storage = make_storage(":memory:",
                                make_table("rap_artists",
                                           make_column("id", &RapArtist::id, primary_key()),
                                           make_column("name", &RapArtist::name)));
    cout << "in memory db opened" << endl;
    storage.sync_schema();

    assert(!storage.count<RapArtist>());

    storage.insert(RapArtist{-1, "The Weeknd"});

    storage.transaction([&] {
        storage.insert(RapArtist{-1, "Drake"});
        return true;
    });

    cout << "rap artists count = " << storage.count<RapArtist>() << endl;

    //  transaction also work in memory..
    storage.transaction([&] {
        storage.insert(RapArtist{-1, "Kanye West"});
        return false;
    });

    cout << "rap artists count = " << storage.count<RapArtist>() << " (no Kanye)" << endl;

    return 0;
}
