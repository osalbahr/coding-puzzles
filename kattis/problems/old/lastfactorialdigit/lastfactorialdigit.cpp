#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int result = 1;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            result *= i;
        cout << result % 10 << endl;
    }
}
