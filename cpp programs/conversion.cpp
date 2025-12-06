#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string toPhoneNumber(string input);
char toDigit(char letter);

int main() {
    string input;
    cout << "Enter a telephone number expressed in letters: ";
    getline(cin, input);

    string phoneNumber = toPhoneNumber(input);
    cout << "The corresponding telephone number in digits is: " << phoneNumber << endl;

    return 0;
}

string toPhoneNumber(string input) {
    string phoneNumber = "";
    int count = 0;
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (isalpha(c)) {
            char digit = toDigit(c);
            if (digit != ' ') {
                phoneNumber += digit;
                count++;
            }
        }
        if (count == 3) {
            phoneNumber += '-';
        }
        if (count == 7) {
            break;
        }
    }
    return phoneNumber;
}

char toDigit(char letter) {
    char digit = ' ';
    switch (toupper(letter)) {
        case 'A': case 'B': case 'C':
            digit = '2'; break;
        case 'D': case 'E': case 'F':
            digit = '3'; break;
        case 'G': case 'H': case 'I':
            digit = '4'; break;
        case 'J': case 'K': case 'L':
            digit = '5'; break;
        case 'M': case 'N': case 'O':
            digit = '6'; break;
        case 'P': case 'Q': case 'R': case 'S':
            digit = '7'; break;
        case 'T': case 'U': case 'V':
            digit = '8'; break;
        case 'W': case 'X': case 'Y': case 'Z':
            digit = '9'; break;
    }
    return digit;
}
