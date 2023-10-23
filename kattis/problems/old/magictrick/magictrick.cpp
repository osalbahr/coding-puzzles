#include <iostream>
#include <set>

using namespace std;

int main()
{
    string str;
    cin >> str;
    set<char> dups;
    for (char ch : str)
        dups.insert(ch);
    cout << (dups.size() == str.size()) << endl;
}
