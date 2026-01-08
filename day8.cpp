#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;

    //store all numbers in a set
    for(int num : nums) {
        s.insert(num);
    }

    int longest = 0;

    //find longest consecutive sequence
    for(int num : s) {

        // only start counting if num is the beginning
        if(s.find(num - 1) == s.end()) {
            int current = num;
            int count = 1;

            while(s.find(current + 1) != s.end()) {
                current++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Longest Consecutive Sequence Length = "
         << longestConsecutive(nums) << endl;

    return 0;
}
