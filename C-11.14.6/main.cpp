#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool is_palindrome (const string& str, int left, int right) {
    while (left < right && !isalpha(str[left])) {
        left++;
    }

    while (left < right && !isalpha(str[right])) {
        right --;
    }

    // Base case (when all letters are checked)
    if (left >= right) {
        return true;
    }

    if(tolower(str[left]) != tolower(str[right])) {
        return false;
    }

    return is_palindrome(str, left + 1, right - 1);
}

int main() {
    // Testing
    string input = "Madam, I'm Adam!";

    if (is_palindrome(input, 0, input.length() - 1)) {
        cout << "\"" << input << "\" is a palindrome.";
    }
    else {
        cout << "\"" << input << "\" is not a palindrome";
    }

    return 0;
}
