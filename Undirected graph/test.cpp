#include <iostream>
using namespace std;

void push(int value, int stack[], int size, int top)
{
  if (top == size - 1)
  {
    cout << "Stack overflow" << endl;
    return;
  }
  top++;
  stack[top] = value;
}

int pop(int stack[], int size, int top)
{
  if (top == -1)
  {
    return -1;
  }
  int tmp = stack[top];
  top--;
  return tmp;
}

int main()
{
  int top1 = -1;
  int top2 = -1;

  int stack1[10];
  int stack2[10];
  push(1, stack1, 10, top1);
  push(2, stack1, 10, top1);
  push(3, stack2, 10, top2);
  push(4, stack2, 10, top2);
  cout << pop(stack2, 10, top2);
  cout << pop(stack1, 10, top1);
}