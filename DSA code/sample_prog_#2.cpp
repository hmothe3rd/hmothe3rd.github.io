#include <iostream> 

void message(int times); 
  
int main() 
{ 
    message(5);     
} 
  
void message (int times) 
{ 
    std::cout << "Message called with " << times << " in times.\n"; 
     
    if (times > 0) 
    { 
        std::cout << "This is a recursive function.\n"; 
        message(times - 1); 
    } 
    std::cout << "Messsage returning with " << times; 
    std::cout << " in times.\n"; 
}