#include <bits/stdc++.h>
#include "DictionaryManager.cpp"

using namespace std;

int main() {
    DictionaryManager<string, string> myDictionary;
    myDictionary.addWord("Hard", "Kho");
    myDictionary.addWord("Easy", "De");
    myDictionary.addWord("English", "Tieng Anh");

    cout << "Initial dictionary:" << endl;
    myDictionary.writeToFile("initial_dictionary.txt");
    myDictionary.readFromFile("initial_dictionary.txt");
    myDictionary.writeToFile("result_dictionary.txt");

    return 0;
}
