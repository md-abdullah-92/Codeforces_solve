#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool can_beat(const pair<char, char>& trump_card, const pair<char, char>& first_card, const pair<char, char>& second_card) {
    // If the second card has the same suit as the first card and a higher rank, it can beat the first card
    if (second_card.second == first_card.second && second_card.first > first_card.first)
        return true;
    
    // If the second card is a trump card and the first card is not, it can beat the first card
    if (second_card.second == trump_card.second && first_card.second != trump_card.second)
        return true;
    
    return false;
}

void solve() {
    int n;
    cin >> n;
    char trump_suit;
    cin >> trump_suit;
    vector<pair<char, char>> cards(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> cards[i].first >> cards[i].second;
    }

    vector<bool> used(2 * n, false);
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            if (!used[j] && can_beat(make_pair('0', trump_suit), cards[i], cards[j])) {
                cout << cards[i].first << cards[i].second << " " << cards[j].first << cards[j].second << endl;
                used[j] = true;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
