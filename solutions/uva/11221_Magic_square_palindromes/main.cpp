#include <iostream>
#include <string>
#include <ctype.h>
#include <math.h>

using namespace std;

string preProcess(string raw) {
    string input = "";

    for (int j = 0; j < raw.size(); j++) {
        if (isalpha(raw[j])){
            input += raw[j];
        }
    }

    return input;
}

int getMagicPalindromeCount(string text) {
    int count = 0;
    int lastIndex = text.size() - 1;
    int end = text.size() / 2;
    bool isPalindrome = true;

    // Check palindromes.
    for (int i = 0; i < end; i++) {
        if (text[i] != text[lastIndex - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (!isPalindrome) {
        return 0;
    }

    double pCount = sqrt(double(text.size()));

    // Check whole number, decimal means it cannot be squared.
    if (floor(pCount) != pCount) {
        return 0;
    }

    int sCount = int(pCount);
    int breakEven = sCount;
    int len = text.size() - 1;

    for (int i = 0; i < sCount; i++) {
        int j = breakEven;

        for (int k = 0; k < breakEven; k++) {
            int head = (k + (i * breakEven));
            int tail = (len - k - (i * breakEven));

            //printf("Checking %c <> %c : index %d <> %d\n", text[head], text[tail], head, tail);

            if (text[head] != text[tail]) {
                return 0;
            }
        }
    }

    for (int i = 0; i < sCount; i++) {
        int j = breakEven;

        for (int k = 0; k < breakEven; k++) {
            int head = (i + (k * breakEven));
            int tail = (len - i - (k * breakEven));

            //printf("Checking %c <> %c : index %d <> %d\n", text[head], text[tail], head, tail);
            if (text[head] != text[tail]) {
                return 0;
            }
        }
    }

    return sCount;
}

int main() {
    int tCase;
    string rawInput;

    cin >> tCase;
    cin.ignore();

    for (int i = 0; i < tCase; i++) {
        getline(cin, rawInput);

        string input = preProcess(rawInput);

        //printf("input: %s\n", input.c_str());

        int count = getMagicPalindromeCount(input);

        printf("Case #%d:\n", i+1);

        if (count > 0) {
            printf("%d\n", count);
        } else {
            printf("No magic :(\n");
        }
    }

    return 0;
}
