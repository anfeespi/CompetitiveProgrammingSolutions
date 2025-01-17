#include<bits/stdc++.h>

using namespace std;

long long merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    long long inv_count = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inv_count += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    return inv_count;
}

long long merge_sort(vector<int>& arr, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += merge_sort(arr, left, mid);
        inv_count += merge_sort(arr, mid + 1, right);

        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}

int main() {
    int n;
    while (cin>>n && n != 0) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin>>arr[i];

        long long result = merge_sort(arr, 0, n - 1);
        cout << result << "\n";
    }
}
