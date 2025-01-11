#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int comparisonCount = 0; // Global variable to count comparisons

// Merge function
void Merge(vector<int>& A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    // Create arrays L and R
    vector<int> L(n1 + 1), R(n2 + 1); // Add one extra space for sentinel
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }

    // Sentinel values
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        comparisonCount++; // Increment comparison count
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

// Merge-Sort function
void MergeSort(vector<int>& A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid, right);
        Merge(A, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    comparisonCount = 0; // Reset comparison count
    MergeSort(A, 0, n);

    // Output the sorted sequence
    for (int i = 0; i < n; i++) {
        cout << A[i] ;
        if(i!=n-1) cout<< " ";
    }
    cout << "\n";

    // Output the number of comparisons
    cout << comparisonCount << "\n";

    return 0;
}
