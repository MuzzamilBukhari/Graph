#include <iostream>
using namespace std;
int main()
{
  int vertices = 5;
  int arr[5][5];
  // for (int i = 0; i < 5; i++)
  // {
  //   arr[i] = false;
  // }
  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
      arr[i][j] = 0;
    }
  }
  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
      cout << arr[i][j] << " ";
    }
  }
  // for (int i = 0; i < 5; i++)
  // {
  //   cout << arr[i][j];
  // }
}