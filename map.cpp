
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