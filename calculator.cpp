#include <iostream>
#include <string>
#include <sstream>
#include "functions.h"
using std::cin, std::cout, std::endl, std::string, std::istringstream;

int main() {
  // prompt user input
  cout << "Type RPN expression (end with '=')." << endl;
  cout << "> ";

  string next;
  int valnum;

  Stack numStack;

  cin >> next;
  while(next != "="){
    try{
      valnum = stoi(next);
      push(numStack, valnum);
    }
    catch(...){
      int val1 = pop(numStack);
      int val2 = pop(numStack);

      if(next == "+"){
        push(numStack, val1+val2);
      }
      else if(next == "-"){
        push(numStack, val2 - val1);
      }
      else if(next == "*"){
        push(numStack, val1*val2);
      }
      else{
        int total = 1;
        for(int i = 0; i < val1; i++){
          total *= val2;
        }
        push(numStack, total);
      }
    }
    cin >> next;
  }
  cout << "Ans: " << pop(numStack) << endl;

  delete[] numStack.numbers;


  return 0;
}