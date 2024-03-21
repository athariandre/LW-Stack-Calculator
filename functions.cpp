#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) {
  // TODO: implement push function for stack

  if(stack.count < stack.capacity){
    stack.numbers[stack.count] = number;
    stack.count++;
  }
  else{
    int* newNums = new int[stack.capacity*2];
    for(int i = 0; i < stack.capacity; i++){
      newNums[i] = stack.numbers[i];
    }
    newNums[stack.count] = number;

    delete[] stack.numbers;

    stack.numbers = newNums;

    stack.count++;
    stack.capacity *= 2;
  }


  INFO_STRUCT(stack);
  INFO(number);
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  
  if(stack.count == 0){
    return(INT32_MAX);
  }

  int popped = stack.numbers[stack.count-1];
  stack.count--;


  INFO_STRUCT(stack);

  return(popped);
  
}

/**
 * ----- REQUIRED -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  // TODO: implement peek function for stack

  if(stack.count == 0){
    return INT32_MAX;
  }


  INFO_STRUCT(stack);
  return stack.numbers[stack.count-1];
}
