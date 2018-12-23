#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int player[1000000];

        // Reset player position.
        for (int k = 0; k < a; k++) {
            player[k] = 1;
        }

        int snake[100];
        int ladder[100];

        // Reset snake & ladder status;
        for (int i = 0; i < 100; i++) {
            snake[i] = -1;
            ladder[i] = -1;
        }

        for (int i = 0; i < b; i++) {
            int head, tail;
            cin >> head >> tail;

            if (head > tail) {
                snake[head - 1] = tail;
            } else {
                ladder[head - 1] = tail;
            }
        }

        int playerIndex = 0;
        bool finished = false;

        for (int j = 0; j < c; j++) {
            int die;
            cin >> die;

            if (finished) {
                continue;
            }

            int pos = player[playerIndex];

            if (pos == 100) {
                finished = true;
                continue;
            }

            pos += die;
            if (pos > 100) {
                pos = 100;
            }

            int iPos = pos - 1;

            if (snake[iPos] != -1) {
                pos = snake[iPos];
            } else if (ladder[iPos] != -1) {
                pos = ladder[iPos];
            }

            // Set current player position.
            player[playerIndex] = pos;

            if (pos == 100) {
                finished = true;
                continue;
            }

            // Next player.
            playerIndex = (playerIndex + 1) % a;
        }

        for (int i = 0; i < a; i++) {
            printf("Position of player %d is %d.\n", i + 1, player[i]);
        }
    }

    return 0;
}
