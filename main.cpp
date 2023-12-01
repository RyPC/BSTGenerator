#include <iostream>
#include <set>
#include <random>


struct Node {
    char value;
    Node* left = nullptr;
    Node* right = nullptr;
};

char getRandomLetter() {
    // Set up a random device and a random engine
    std::random_device rd;
    std::mt19937 gen(rd());

    // Generate a random number corresponding to the ASCII values of 'A' to 'Z'
    std::uniform_int_distribution<> distribution('A', 'Z');

    // Return the randomly generated letter
    return static_cast<char>(distribution(gen));
}

int getRandomNumber() {
    // Set up a random device and a random engine
    std::random_device rd;
    std::mt19937 gen(rd());

    // Generate a random number between 1 and 4
    std::uniform_int_distribution<> distribution(1, 10);

    // Return the randomly generated number
    return distribution(gen);
}

void preorder(Node* head) {
    if (head == nullptr) {
        return;
    }
    
    std::cout << head->value;
    preorder(head->left);
    preorder(head->right);
}
void inorder(Node* head) {
    if (head == nullptr) {
        return;
    }
    
    inorder(head->left);
    std::cout << head->value;
    inorder(head->right);
}
void postorder(Node* head) {
    if (head == nullptr) {
        return;
    }
    
    postorder(head->left);
    postorder(head->right);
    std::cout << head->value;
}



void insertIntoTree(Node* head, std::set<char>& letters, int& i, int thresh) {
    if (i >= thresh) {
        return;
    }
    
    if (!head->left) {
        if (getRandomNumber() == 1) {
            char c = getRandomLetter();
            if (!letters.count(c)) {
                letters.insert(c);
                head->left = new Node{};
                head->left->value = c;
                ++i;
            }
        }
    }
    if (!head->right) {
        if (getRandomNumber() == 1) {
            char c = getRandomLetter();
            if (!letters.count(c)) {
                letters.insert(c);
                head->right = new Node{};
                head->right->value = c;
                ++i;
            }
        }
    }
    
    if (head->left && head->right) {
        insertIntoTree(head->left, letters, i, thresh);
        insertIntoTree(head->right, letters, i, thresh);
        return;
    }
}

int main() {
    std::set<char> letters;
    Node* head = new Node();
    
    // insert first char at head
    char c = getRandomLetter();
    head->value = c;
    letters.insert(c);
    
    int i = 0;
    int thresh = 10;
    while (i < thresh) {
        insertIntoTree(head, letters, i, thresh);
    }
    
    std::cout << std::endl << "Preorder:\t";
    preorder(head);
        
    std::cout << std::endl << "Inorder:\t";
    inorder(head);
    
    std::cout << std::endl << "Postorder:\t";
    postorder(head);

    return 0;
}
