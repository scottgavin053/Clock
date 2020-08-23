#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
using namespace std;

int userChoice;
int counter = 0;

void displayTime(int addTime) {
    int i = true;
    string tZone;
    int currS, currM, currH;                //current seconds, hours, minutes
    if (currH >= 12) {
        tZone = "PM";
    } else {
        tZone = "AM";
    }
    while (i) {
        time_t total_seconds = time(0);
        total_seconds += addTime;
        struct tm *ct = localtime(&total_seconds);
        currS = ct->tm_sec;
        currM = ct->tm_min;
        currH = ct->tm_hour;
        cout << (currH < 10 ? "0" : "") << currH << ":" << (currM < 10 ? "0" : "") << currM << ":"      //24 hour format
             << (currS < 10 ? "0" : "") << currS << endl;
        if (currH > 12) {
            currH %= 12;
        }
        cout << (currH < 10 ? "0" : "") << currH << ":" << (currM < 10 ? "0" : "") << currM << ":"      //12 hour format
             << (currS < 10 ? "0" : "") << currS << tZone << endl;
        Sleep(1000);
        system("CLS");      //delay of one second followed by clear screen before looping again
        counter += 1;
        if (counter > 20){           //time is displayed 20 seconds at a time
            break;
        }
    }
}

int displayMenu() {
    cout << "1 * - Add One Hour" << endl;
    cout << "2 * - Add One Minute" << endl;
    cout << "3 * - Add One Second" << endl;
    cout << "4 * - Exit Program" << endl;
}

int main() {
    int addTime = 0;
    bool i = true;
    while (i) {                             //loops through display time and menu until exit is selected
        displayTime(addTime);
        displayMenu();
        cin >> userChoice;
        if (userChoice == 4) {
            cout << "Goodbye!";
            return 0;
        } else if (userChoice == 1) {       //alters time based on user selection
            addTime += 3600;
        } else if (userChoice == 2) {
            addTime += 60;
        } else {
            addTime += 1;
        }
        counter = 0;
    }
}
