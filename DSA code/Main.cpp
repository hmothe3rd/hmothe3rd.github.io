#include <iostream>
#include "Yeah.h"

int main() {
    FloatList list;

    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);
    std::cout << "Here are the initial values:\n";
    
    list.displayList();
    std::cout << std::endl;
    std::cout << "Now deleting the node in the middle.\n";
    std::cout << "Here are the nodes left.\n";
    
    list.deleteNode(7.9);
    list.displayList();
    std::cout << std::endl;
    std::cout << "Now deleting the last node.\n";
    std::cout << "Here are the nodes left.\n";
    
    list.deleteNode(12.6);
    list.displayList();
    std::cout << std::endl;
    std::cout << "Now deleting the only remaining node.\n";
    std::cout << "Here are the nodes left.\n";
    
    list.deleteNode(2.5);
    list.displayList();

    return 0;
}