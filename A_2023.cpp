#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define int long long
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int N = 4e6 + 10;

int cnt;
int arrayA[N];
int arrayB[N];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n, k, z;
        cin >> n >> k;

        vector<int> numbers(n);
        map<int, int> frequencyMap;

        int product = 1;
        for (int i = 0; i < n; i++) {
            cin >> z;
            product *= z;
        }

        if (2023 % product != 0) {
            NO;
        } else {
            YES;
            cout << 2023 / product << " ";
            for (int i = 1; i < k; i++) {
                cout << 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
