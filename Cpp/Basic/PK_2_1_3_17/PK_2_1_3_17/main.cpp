#include <iostream>
#include <fstream>
#include <string>
using  namespace std;

struct Phrase {
    string word;
    bool marker = false;
};

int main() {
    ifstream in ("input.txt");
    ofstream out ("output.txt");

    unsigned int number;
    int amountOfValues = 1;
    in >> number;

    Phrase* phraseArray = new Phrase();
    int index = 0;

    while (!in.eof()) {
        in >> phraseArray[index].word;
        index++;
    }

    for (int i = 0; i < index - 1; i ++) {
        phraseArray[i].marker = true;
        for (int j = i + 1; j < index; j++) {
            if (phraseArray[i].word == phraseArray[j].word && phraseArray[j].marker != true) {
                amountOfValues++;
                phraseArray[j].marker = true;
            }
        }
        if (amountOfValues > number) {
            out << "Word: " <<phraseArray[i].word << " met in phrase " << amountOfValues << " times" << endl;
            amountOfValues = 1;
        }
    }
    out << endl;

    return 0;
}