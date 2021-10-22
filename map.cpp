
/*
links:
    https://www.geeksforgeeks.org/map-vs-unordered_map-c/

    
                  | map             | unordered_map
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  

search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search
                      
Deletion time   | log(n) + Rebalance  | Same as search
*/

#include <map>
#include <iostream>

using namespace std;


int main() {
    map<char, int> mp;
    string str = "jskldjasjioquroihdklfhslkfjsljajdasjopau";

    for (auto a: str) mp[a]++;

    cout << "mp size " << mp.size() << endl;

    for (auto [a, count]: mp) cout << a << " -> " << count << endl;

    return 0;
}