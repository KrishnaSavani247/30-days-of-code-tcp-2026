#include <iostream>
using namespace std;

class Solution {
public:
    int setBits(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1; // check LSB
            n >>= 1;        // right shift
        }
        return count;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution obj;
    cout << "Number of set bits: " << obj.setBits(n) << endl;

    return 0;
}
