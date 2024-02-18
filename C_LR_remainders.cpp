#include <iostream>
#include <vector>
#include <string>
#define int long long
using namespace std;

struct Node {
    int product;
};

void buildTree(vector<Node>& tree, const vector<int>& arr, int start, int end, int treeNode, int k) {
    if (start == end) {
        tree[treeNode].product = arr[start] % k; 
        return;
    }

    int mid = (start + end) / 2;
    buildTree(tree, arr, start, mid, 2 * treeNode, k);
    buildTree(tree, arr, mid + 1, end, 2 * treeNode + 1, k);
    tree[treeNode].product = (tree[2 * treeNode].product * tree[2 * treeNode + 1].product) % k; 
}

void updateTree(vector<Node>& tree, const vector<int>& arr, int start, int end, int treeNode, int idx, int k) {
    if (start == end) {
        tree[treeNode].product = arr[start] % k; 
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid) {
        updateTree(tree, arr, start, mid, 2 * treeNode, idx, k);
    } else {
        updateTree(tree, arr, mid + 1, end, 2 * treeNode + 1, idx, k);
    }
    tree[treeNode].product = (tree[2 * treeNode].product * tree[2 * treeNode + 1].product) % k;
}

int query(vector<Node>& tree, int start, int end, int treeNode, int left, int right, int k) {
    if (start > right || end < left) {
        return 1;
    }
    if (start >= left && end <= right) {
        return tree[treeNode].product;
    }
    int mid = (start + end) / 2;
    long long ans1 = query(tree, start, mid, 2 * treeNode, left, right, k);
    long long ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right, k);
    return (ans1 * ans2) % k;
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    string s;
    cin >> s;
    vector<Node> tree(4 * n);
    buildTree(tree, v, 0, n - 1, 1, k);

    int l = 0, r = n - 1;
    for (char c : s) {
        cout << query(tree, 0, n - 1, 1, l, r, k) << " ";
        if (c == 'L') {
            //updateTree(tree, v, 0, n - 1, 1, l, k);
            l++;
        } else {
           //updateTree(tree, v, 0, n - 1, 1, r, k);
            r--;
        }
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
