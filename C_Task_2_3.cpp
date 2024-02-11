#include <iostream>
#include <vector>
using namespace std;

const int N = 1e7;
vector<bool> is_prime(N, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int n;
        cin >> n;
        int k = 0;
        for (int p = 2; p <= n / 2; p++) {
            if (is_prime[p] && is_prime[n - p]) {
                k++;
            }
        }
        cout << "Case " << i << ": " << k << endl;
    }

    return 0;
}
