#include "stack.h"
#include "iostream"

using namespace std;
int main(){
  Stack<int> andrew;
  andrew.push(1);
  andrew.push(2);
  andrew.push(3);
  
  cout << andrew.top() << endl;
  return 0;
}