#include "Memory.h"
#include <iostream>
#include <iomanip>
#include "Node.h"
#include <vector>
#include <utility>

using namespace std;

/**
Frees the given memory address. Returns if the free was successful or not
Be sure to merge adjacent free blocks when possible
*/
bool Memory::free(unsigned address) {
    Node* current = head;
    while (current != NULL) {
        if (current->address == address) {
            // Your code there
            current->inUse = false;

            // See if we can merge
            Node* prev = current->previous;
            Node* next = current->next;
            if (prev != NULL && !prev->inUse) {
                // Your code there
                prev->next = next;
                next->previous = prev;
                free(prev->address);

            }

            if (next != NULL && !next->inUse) {
                // Your code there
                current->next = next->next;
                next->previous = current->previous;
                free(next->address);
            }
            return true;
        }
        current = current->next;
    }

    return false;
}


/**
Reorganizes memory structure so that all of the allocated memory is grouped at the bottom (0x0000) and there is one large
chunk of free memory above.

Note: We do not care about the order of the allocated memory chunks
*/
void Memory::defragment() {
    Node* current = head;
    while (current != NULL) {

        if (current->inUse) {
            // Do nothing
        } else {
            // TODO: Find the next chunk of allocated memory and shift it down to current's address
            // We recommend using the helper function `findNextAllocatedMemoryChunk` and `getSize`
            // Your code here
            
            Node * memory_next = findNextAllocatedMemoryChunk(current);

            if(memory_next != NULL) {
                size_t size = getSize(memory_next);
                current->inUse = true;
                current->next->address = current->address + size;
                unsigned temp = memory_next->address;
                memory_next->address = current->next->address;
                memory_next->inUse = false;
                memory_next->previous = current;
                free(temp);
            }
        }
        current = current->next;
    }
}
