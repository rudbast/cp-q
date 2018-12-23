#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        int t;
        cin >> t;

        if (t == -1) {
            break;
        }

        const int maxAttempt = 7;

        string word;
        string attempt;

        cin >> word;
        cin >> attempt;

        int alpha[26];
        int alphaAttempt[26];

        const int stateNone = -1;
        const int stateExist = 0;
        const int stateFound = 1;
        const int stateAttempt = 2;

        for (int i = 0; i < 26; i++) {
            alpha[i] = stateNone;
            alphaAttempt[i] = stateNone;
        }

        for (int i = 0; i < word.length(); i++) {
            alpha[int(word[i] - 'a')] = stateExist;
        }

        int wordCount = 0;

        for (int i = 0; i < 26; i++) {
            if (alpha[i] == stateExist) {
                wordCount++;
            }
        }

        int c = 0;
        int wordFound = 0;

        bool fail = false;
        bool success = false;

        for (int i = 0; i < attempt.length(); i++) {
            int index = int(attempt[i] - 'a');

            // Skip previous same character attempt.
            if (alphaAttempt[index] == stateAttempt) {
                continue;
            }

            alphaAttempt[index] = stateAttempt;

            switch (alpha[index]) {
                case stateNone:
                    c++;
                    break;

                case stateExist:
                    wordFound++;
                    alpha[index] = stateFound;
                    break;
            }

            if (wordFound == wordCount) {
                success = true;
                break;
            }

            if (c >= maxAttempt) {
                fail = true;
                break;
            }
        }

        printf("Round %d\n", t);

        if (success) {
            printf("You win.\n");
        } else if (fail) {
            printf("You lose.\n");
        } else {
            printf("You chickened out.\n");
        }
    }

    return 0;
}
