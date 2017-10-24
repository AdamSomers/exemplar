#include "hashmap.h"

#include "defs.h"

#include <iostream>

using namespace std;

namespace exemplar
{
    void hashmap_example()
    {
        DBG("\n- Start hashmap_example -\n");
        exemplar::HashMap<int, string> map;
        map.set(0, "adam");
        map.set(1, "jennah");
        map.set(2, "ada");
        map.set(100, "monkey");
        cout << map.get(0) << endl;
        cout << map.get(1) << endl;
        cout << map.get(2) << endl;
        cout << map.get(100) << endl;
    
        exemplar::HashMap<string, string> map2;
        map2.set("adam", "daddy");
        map2.set("jennah", "mommy");
        map2.set("ada", "baby");
        map2.set("ripley", "doggie");

        cout << map2.get("adam") << endl;
        cout << map2.get("jennah") << endl;
        cout << map2.get("ada") << endl;
        cout << map2.get("ripley") << endl;
        DBG("- End hashmap_example -\n");
    }
}
