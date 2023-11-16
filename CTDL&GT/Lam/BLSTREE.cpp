#include <bits/stdc++.h>

#ifndef ___BLSTREE___cpp___
#define ___BLSTREE___cpp___

using namespace std;

template <class Keys, class T>
class BinarySearchTree {
private:
    struct Node {
        Keys key;
        T data;
        Node* left;
        Node* right;

        Node(Keys _key, T _data) : key(_key), data(_data), left(nullptr), right(nullptr) {}
    };

    Node* root;
    long long _size;

    Node* insert(Node* node, Keys key, T data) {
        if (node == nullptr) {
            _size++;
            return new Node(key, data);
        }

        if (key < node->key)
            node->left = insert(node->left, key, data);
        else if (key > node->key)
            node->right = insert(node->right, key, data);

        return node;
    }

    Node* findMin(Node* node) {
        if (node == nullptr)
            return nullptr;
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* remove(Node* node, Keys key) {
        if (node == nullptr)
            return nullptr;

        if (key < node->key)
            node->left = remove(node->left, key);
        else if (key > node->key)
            node->right = remove(node->right, key);
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                _size--;
                return nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                _size--;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                _size--;
                return temp;
            } else {
                Node* minRight = findMin(node->right);
                node->key = minRight->key;
                node->data = minRight->data;
                node->right = remove(node->right, minRight->key);
            }
        }

        return node;
    }

    Node* search(Node* node, Keys key) {
        if (node == nullptr || node->key == key)
            return node;

        if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->key << " - " << node->data << endl;
            inOrder(node->right);
        }
    }

    void deleteRoot(Node* node) {
        if (node != nullptr) {
            deleteRoot(node->left);
            deleteRoot(node->right);
            delete node;
        }
    }
    template <typename Func>
    void inOrderTraversal(Node* node, Func visit) {
        if (node != nullptr) {
            inOrderTraversal(node->left, visit);
            visit(node);
            inOrderTraversal(node->right, visit);
        }
    }
    void writeNodeToFile(Node* node, ofstream& outFile) {
        if (node != nullptr) {
            writeNodeToFile(node->left, outFile);
            outFile << node->key << " " << node->data << endl;
            writeNodeToFile(node->right, outFile);
        }
    }


public:
    BinarySearchTree() : root(nullptr), _size(0) {}

    void insert(Keys key, T data) {
        root = insert(root, key, data);
    }

    void remove(Keys key) {
        root = remove(root, key);
    }

    void update(Keys key, T newData) {
        Node* node = search(root, key);
        if (node != nullptr)
            node->data = newData;
    }

    bool search(Keys key) {
        return search(root, key) != nullptr;
    }

    void inOrder() {
        inOrder(root);
    }

    void clear() {
        deleteRoot(root);
        root = nullptr;
        _size = 0;
    }

    bool empty() {
        return _size == 0;
    }

    long long size() {
        return _size;
    }

    ~BinarySearchTree() {
        deleteRoot(root);
    }
    void writeToFile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        // Start the traversal from the root
        writeNodeToFile(root, outFile);

        outFile.close();
    }


};
#endif
