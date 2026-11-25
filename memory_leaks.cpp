#include <iostream>
using namespace std;

// Activity 3A: Allocates memory on the heap without freeing it
void createLeak() {
    int* ptr = new int(42);
    cout << "Inside createLeak. Value: " << *ptr << endl;
    cout << "Memory allocated at address: " << ptr << endl;
    // Missing delete ptr; causes a memory leak when ptr goes out of scope
}

// Step 3 Fix: Properly frees memory and resets pointer to nullptr
void fixLeak() {
    int* ptr = new int(42);
    cout << "Inside fixLeak. Value: " << *ptr << endl;
    cout << "Memory allocated at address: " << ptr << endl;

    delete ptr;      // Frees memory back to the OS
    ptr = nullptr;   // Prevents dangling pointer

    cout << "Memory has been successfully freed." << endl;
}

int main() {
    cout << "--- Demonstrating Memory Leak ---" << endl;
    createLeak();
    cout << "Function finished. Heap memory leaked.\n" << endl;

    cout << "--- Testing the Fix ---" << endl;
    fixLeak();

    return 0;
}

