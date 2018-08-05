#include <iostream>
#include <string>

using namespace std;

int main() {
    char inputHour[2];
    char inputMinute[2];

    while (true) {
        string input;

        cin >> input;

        //printf("%s\n", input.c_str());

        if (input == "0:00") {
            break;
        }

        int hour;
        int minute;

        if (input[1] == ':') {
            hour = input[0] - '0';
            minute = ((input[2] - '0') * 10) + (input[3] - '0');
        } else {
            hour = ((input[0] - '0') * 10) + (input[1] - '0');
            minute = ((input[3] - '0') * 10) + (input[4] - '0');
        }

        //printf("hour: %d, minute: %d\n", hour, minute);

        double degHour = (double(hour) * 30) + (double(minute) / 60 * 30);
        double degMinute = double(minute) * 6;

        double deg = abs(degHour - degMinute);

        if (deg > 180) {
            deg = 360 - deg;
        }

        printf("%.3f\n", deg);
    }

    return 0;
}
