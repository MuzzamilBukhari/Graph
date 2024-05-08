#include <iostream>
using namespace std;
struct Vertex;
struct Edge
{
  Vertex *ver;
  Edge *next;
  bool visited;
};

struct Vertex
{
  int rep;
  Vertex *next;
  Edge *edgeList;
};

void addVertex(int rep, Vertex **head)
{
  Vertex *ptr = (Vertex *)malloc(sizeof(Vertex));
  ptr->rep = rep;
  ptr->next = NULL;
  ptr->edgeList = NULL;
  if (*head == NULL)
  {
    *head = ptr;
    return;
  }
  Vertex *curr = *head;
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  curr->next = ptr;
}

void addEdge(int vertex1, int vertex2, Vertex **head)
{
  // add eddge to vertex 1
  Vertex *ver1 = *head;
  while (ver1 != NULL)
  {
    if (ver1->rep == vertex1)
      break;
  }
  Vertex *ver2 = *head;
  while (ver2 != NULL)
  {
    if (ver2->rep == vertex2)
      break;
  }
}

void printVertices(Vertex *head)
{
  Vertex *curr = head;
  while (curr != NULL)
  {
    cout << curr->rep << " ";
    curr = curr->next;
  }
}

int main()
{
  Vertex *head = NULL;
  int n;
  do
  {
    cout << "Enter 1 to add vertex " << endl
         << "Enter 2 to add an edge " << endl
         << "Enter 3 to Find path " << endl
         << "Enter 4 to find cycle " << endl
         << "Enter 5 to find degree " << endl
         << "Enter  6 to Quit" << endl;
    cin >> n;
    if (n == 1)
    {
      int rep;
      cout << "Enter representation of a vertex : ";
      cin >> rep;
      addVertex(rep, &head);
    }
    else if (n == 2)
    {
      int vertex1;
      cout << "Make edge of which vertex? " << endl;
      cin >> vertex1;
      int vertex2;
      cout << "Make a connection between " << vertex1 << " and?" << endl;
      cin >> vertex2;
      addEdge(vertex1, vertex2, &head);
    }
    else if (n == 3)
    {
    }
    else if (n == 4)
    {
    }
    else if (n == 5)
    {
    }
    else if (n == 6)
    {
      cout << "Quit" << endl;
    }
    else
    {
      cout << "Invalid" << endl;
    }

  } while (n != 6);
  printVertices(head);
}