// Copyright 2021 mkhorosh
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<typename T>  // T-data type
class MyStack {
 private:
  T *stack;
  int top;  // top position index
  int size;  // size of stack

 public:
  explicit MyStack(int size) {
    this->stack = new T[size];
    this->top = -1;  // empty stack
    this->size = size;
  }  // size param constructor
  MyStack(const MyStack &another) {
    this->size = another.size;
    this->top = another.top;
    this->stack = new T[another.size];
    for (int i = 0; i < this->size; i++) {
      this->stack[i] = another.stack[i];
    }
  }  // copy constructor
  ~MyStack() {
    delete[] this->stack;
  }  // destructor
  T get() const {
    if (this->top != -1) {
      return this->stack[this->top];
    } else {
      throw "out of range";
    }
  }  // return top element
  T pop() {
    if (this->top != -1) {
      T top = this->stack[(this->top)];
      this->stack[(this->top)--] = {};
      return top;
    } else {
      throw "out of range";
    }
  }  // delete top element
  void push(T elem) {
    if (this->top != this->size - 1) {
      this->stack[++(this->top)] = elem;
    } else {
      throw "out of range";
    }
  }  // add new element to the top
  bool isFull() const {
    return (this->top == this->size - 1);
  }
  bool isEmpty() const {
    return (this->top == -1);
  }
};

#endif  // INCLUDE_MYSTACK_H_
