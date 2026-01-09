#include <iostream>
using namespace std;

string largestOddNumber(string num) {
    for (int i = num.length() - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2 == 1) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main() {
    string num;

    cout << "Enter a number: ";
    cin >> num;   // you can enter ANY large number here

    string result = largestOddNumber(num);

    if (result == "")
        cout << "No odd substring exists";
    else
        cout << "Largest odd substring: " << result;

    return 0;
}
