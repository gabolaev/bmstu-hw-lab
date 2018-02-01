#include <iostream>
#include <stack>
#include <functional>

template<class T>
class BinaryTree {
private:
    struct Node {

        T value = 0;
        Node *right;
        Node *left;

        Node(T inValue) : value(inValue), right(NULL), left(NULL) {};
    };
public:
    explicit BinaryTree();

    ~BinaryTree();

    void insert(T inputtingValue);

    void printInOrder();

private:

    void inOrderTraversal(std::function<void(Node * node)> f);

    Node *root;
    Node *getFront;

};

template<class T>
BinaryTree<T>::BinaryTree() {}

template<class T>
BinaryTree<T>::~BinaryTree() {

    inOrderTraversal([](Node *node){
        delete node;
    });

}

template<class T>
void BinaryTree<T>::insert(T inputtingValue) {

    Node *currentNode = root;
    if(currentNode == NULL){
        root = new Node(inputtingValue);
        return;
    }

    while (true) {
        if (inputtingValue > currentNode->value) {
            if (currentNode->right == nullptr) {
                currentNode->right = new Node(inputtingValue);
                break;
            } else {
                currentNode = currentNode->right;
            }
        } else {
            if (currentNode->left == nullptr) {
                currentNode->left = new Node(inputtingValue);
                break;
            } else {
                currentNode = currentNode->left;
            }
        }
    }
}

template<class T>
void BinaryTree<T>::inOrderTraversal(std::function<void(Node * node)> f) {

    Node *currentNode = root;

    std::stack<Node *> stack;
    while (true) {
        if (currentNode != nullptr) {
            stack.push(currentNode);
            currentNode = currentNode->left;
        } else if (!stack.empty()) {
            currentNode = stack.top();
            stack.pop();
            f(currentNode);
            currentNode = currentNode->right;
        } else {
            break;
        }

    }

}

template<class T>
void BinaryTree<T>::printInOrder() {
    inOrderTraversal([](Node *node){
       std::cout << node->value << " ";
    });
}

int main() {

    BinaryTree<long> tree;

    short size;
    long inputValue;

    std::cin >> size;
    for(; size > 0; --size){
        std::cin >> inputValue;
        tree.insert(inputValue);
    }

    tree.printInOrder();
    return 0;
}