#include <iostream>
using namespace std;

long long gcd(long long x, long long y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

long long lcm(long long x, long long y) {
    return (x / gcd(x, y)) * y;
}

int nthUglyNumber(int n, int a, int b, int c) {
    long long ab = lcm(a, b);
    long long ac = lcm(a, c);
    long long bc = lcm(b, c);
    long long abc = lcm(ab, c);

    long long low = 1, high = 2000000000LL;

    while (low < high) {
        long long mid = low + (high - low) / 2;

        long long count =
            mid / a + mid / b + mid / c
            - mid / ab - mid / ac - mid / bc
            + mid / abc;

        if (count < n)
            low = mid + 1;
        else
            high = mid;
    }
    return (int)low;
}

int main() {
    int n, a, b, c;

    cout << "Enter n, a, b, c: ";
    cin >> n >> a >> b >> c;

    cout << "Nth Ugly Number: " << nthUglyNumber(n, a, b, c) << endl;

    return 0;
}
