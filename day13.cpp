#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = 0;

            for (int p : piles) {
                hours += (p + mid - 1) / mid;  // ceiling division
            }

            if (hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);
    cout << "Enter piles: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    int h;
    cout << "Enter hours: ";
    cin >> h;

    Solution obj;
    int result = obj.minEatingSpeed(piles, h);

    cout << "Minimum eating speed: " << result << endl;

    return 0;
}
