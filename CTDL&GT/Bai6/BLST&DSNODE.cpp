// #ifndef DICTIONARY_MANAGER_cpp
// #define DICTIONARY_MANAGER_cpp
// #include <bits/stdc++.h>
// #include "BTREE.cpp"

// using namespace std;

// class DictionaryManager {
//     private:
//         BTree<string,string> dictionaryTree;

//     public:
//         DictionaryManager();
//         ~DictionaryManager();

//         void readFromFile(const string& filename);
//         void writeToFile(const string& filename);

//         void addWord(const string& word, const string& meaning);
//         void removeWord(const string& word);
//         void updateMeaning(const string& word, const string& newMeaning);
//         string searchWord(const string& word) const;
// };

// DictionaryManager::DictionaryManager() {}

// DictionaryManager::~DictionaryManager() {}

// void DictionaryManager::readFromFile(const string& filename) {
//     ifstream inFile(filename);
//     if (!inFile.is_open()) {
//         cerr << "Error opening file: " << filename << endl;
//         return;
//     }

//     string word, meaning;
//     while (inFile >> word >> meaning) {
//         dictionaryTree.insert(word, meaning);
//     }

//     inFile.close();
// }

// void DictionaryManager::writeToFile(const string& filename) {
//     ofstream outFile(filename);
//     if (!outFile.is_open()) {
//         cerr << "Error opening file: " << filename << endl;
//         return;
//     }

//     dictionaryTree.inOrderTraversal([&outFile](BNode<string,string>* node) {
//         outFile << node->getKey() << " " << node->getElem() << std::endl;
//     });

//     outFile.close();
// }

// void DictionaryManager::addWord(const string& word, const string& meaning) {
//     dictionaryTree.insert(word, meaning);
// }

// void DictionaryManager::removeWord(const string& word) {
//     dictionaryTree.remove(word);
// }

// void DictionaryManager::updateMeaning(const string& word, const string& newMeaning) {
//     BNode<string, string>* node = dictionaryTree.search(word);
//     if (node != nullptr) {
//         node->setElem(newMeaning);
//     } else {
//         std::cout << "Word not found" << std::endl;
//     }
// }

// string DictionaryManager::searchWord(const string& word) const {
//     BNode<string,string>* node = dictionaryTree.search(word);
//     if (node != nullptr) {
//         return node->getElem();
//     } else {
//         return "Word not found";
//     }
// }
// #endif