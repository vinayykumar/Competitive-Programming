#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end(), greater<int>());

        int max_wt = 0;
        int curr_sum = 0;
        int min_wt = arr[0];

        for (int i = 0; i < n; i++) {
            curr_sum += arr[i];
            min_wt = min(min_wt, arr[i]);

            int l = min_wt, r = curr_sum;
            int mid = 0;

            while (l <= r) {
                mid = l + (r - l) / 2;
                if (float(mid) / (i + 1) >= min_wt) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            max_wt = max(max_wt, mid);
        }

        cout << max_wt << endl;
    }

    return 0;
}
