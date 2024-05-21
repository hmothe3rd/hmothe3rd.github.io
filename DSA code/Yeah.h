#include <iostream>

class FloatList {
private:
    struct ListNode {
        float value;
        ListNode* next;
    };
    ListNode* head;

public:
    FloatList() { head = nullptr; }
    ~FloatList(); 
    void appendNode(float num);
    void insertNode(float num);
    void deleteNode(float num);
    void displayList();
};

FloatList::~FloatList() {
    ListNode* nodePtr = head;
    ListNode* nextNode;
    while (nodePtr != nullptr) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
    std::cout << "Linked List has been destroyed!" << std::endl;
}

void FloatList::appendNode(float num) {
    ListNode* newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } 
    
    else {
        ListNode* nodePtr = head;
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
    std::cout << "Input has been APPENDED!" << std::endl;
}

void FloatList::displayList() {
    ListNode* nodePtr;
    
    if (head == nullptr)
        std::cout << "The List is empty!" << std::endl;
    
    else {
        nodePtr = head;
        while (nodePtr) {
            std::cout << nodePtr->value << std::endl;
            nodePtr = nodePtr->next;
        }
    }
}

void FloatList::insertNode(float num) {
    ListNode *newNode, *nodePtr, *previousNode;
    newNode = new ListNode;
    newNode->value = num;

    if (!head) {
        head = newNode;
        newNode->next = nullptr;
    } 
    
    else { 
        nodePtr = head;
        previousNode = nullptr;
        
        while (nodePtr != nullptr && nodePtr->value < num) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if (previousNode == nullptr) {
            head = newNode;
            newNode->next = nodePtr;
        } 
    
        else {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
    std::cout << "Input has been INSERTED!" << std::endl;
}

void FloatList::deleteNode(float num) {
    ListNode *nodePtr, *previousNode;
    int found = 0;

    if (!head) {
        std::cout << "The list is empty!" << std::endl;
        return;
    }

    if (head->value == num) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        found = 1;
    } 
    
    else {
        nodePtr = head;
        previousNode = nullptr;

        while (nodePtr != nullptr && nodePtr->value != num) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr != nullptr) {
            previousNode->next = nodePtr->next;
            delete nodePtr;
            std::cout << "Input has been DELETED!" << std::endl;
            found = 1;
        }
    }
    
    if (found == 0)
        std::cout << "Input not in the list!" << std::endl;
}
