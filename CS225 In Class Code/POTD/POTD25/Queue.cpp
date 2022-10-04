#include "Queue.h"

Queue::Queue() {
  length = 0;
  capacity = 2;
  front = 0;
  data = new int[capacity];
}

Queue::Queue(const Queue& other) {
  _copy(other);
}

Queue::~Queue() {
  _clear();
}

void Queue::_copy(const Queue& other) {
  length = other.length;
  capacity = other.capacity;
  front = other.front;

  data = new int[capacity];
  for(unsigned i =0; i < capacity; i++) {
    data[i] = other.data[i];
  }
}

void Queue::_clear() {
  if(data !=nullptr) {
    delete[] data;
  }
}

Queue& Queue::operator=(const Queue& other) {
  if (this != &other) {
    _clear();
    _copy(other);
  }

  return *this;
}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
  return length;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  if(length == 0) {
    return true;
  }
  return false;
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
  if(length >= capacity) {
    unsigned new_capacity = capacity * 2;
    int* new_data = new int[new_capacity];
    for(unsigned i =0; i < new_capacity; i++) {
      new_data[i] = data[i];
    }
    _clear();
    capacity = new_capacity;
    data = new_data;
    front = 0;
  }
  int position = (front + length) % capacity;
  data[position] = value;
  length++;
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
  length--;
  return data[front++];
}
