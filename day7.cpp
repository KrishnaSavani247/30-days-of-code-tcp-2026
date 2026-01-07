#include <iostream>
using namespace std;

// Function to encrypt a number
int encrypt(int x) {
    int maxDigit = 0;
    int digits = 0;
    int temp = x;

    // Finding largest digit and count digits
    while(temp > 0) {
        int digit = temp % 10;
        if (digit > maxDigit)
            maxDigit = digit;
        temp = temp / 10;
        digits++;
    }

    // Build encrypted number
    int encrypted = 0;
    for(int i = 0; i < digits; i++) {
        encrypted = encrypted * 10 + maxDigit;
    }

    return encrypted;
}

int main() {
    int nums[] = {10, 21, 31};
    int n = 3;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += encrypt(nums[i]);
    }

    cout << sum;
    return 0;
}
