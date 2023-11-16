#include <bits/stdc++.h>
#include "BLSTREE.cpp"

#ifndef ___DictionaryManager___cpp___
#define ___DictionaryManager___cpp___

using namespace std;

template <class Keys, class T>
class DictionaryManager {
    private:
        BinarySearchTree<Keys, T> dictionaryTree;

    public:
        void writeNodeToFile(typename BinarySearchTree<Keys, T>::Node* node, ofstream& outFile) {
            outFile << node->key << " " << node->data << endl;
        }
        void readFromFile(const string& filename) {
            ifstream inFile(filename);
            if (!inFile.is_open()) {
                cerr << "Error opening file: " << filename << endl;
                return;
            }

            Keys word;
            T meaning;
            while (inFile >> word >> meaning) {
                dictionaryTree.insert(word, meaning);
            }

            inFile.close();
        }

        void writeToFile(const string& filename) {
            ofstream outFile(filename);
            if (!outFile.is_open()) {
                cerr << "Error opening file: " << filename << std::endl;
                return;
            }
            dictionaryTree.inOrderTraversal(&BinarySearchTree<Keys, T>::writeNodeToFile, outFile);

            outFile.close();
        }

        void addWord(const Keys& word, const T& meaning) {
            dictionaryTree.insert(word, meaning);
        }

        void removeWord(const Keys& word) {
            dictionaryTree.remove(word);
        }

        void updateMeaning(const Keys& word, const T& newMeaning) {
            typename BinarySearchTree<Keys, T>::Node* node = dictionaryTree.search(word);
            if (node != nullptr) {
                node->data = newMeaning;
            } else {
                std::cout << "Word not found" << std::endl;
            }
        }

        T searchWord(const Keys& word) const {
            typename BinarySearchTree<Keys, T>::Node* node = dictionaryTree.search(word);
            if (node != nullptr) {
                return node->data;
            } else {
                return "Word not found";
            }
        }
};
#endif





