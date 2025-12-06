#include <iostream>
#include <string>

using namespace std;

int count_letter(string phrase, char letter) {
    int count = 0;
    for (char c : phrase) {
        if (c == letter) {
            count++;
        }
    }
    return count;
}

int main() {
    string phrase;
    char letter;
    cout << "Enter a phrase: ";
    getline(cin, phrase);
    cout << "Enter a letter: ";
    cin >> letter;
    int count = count_letter(phrase, letter);
    cout << "The letter \"" << letter << "\" occurs " << count << " time(s) in the phrase." << endl;
    return 0;
}
