#include <iostream>
using namespace std;
struct Vertex;
struct Edge
{
  Vertex *verAdd;
  Edge *next;
};

struct Vertex
{
  int rep;
  Vertex *next;
  Edge *edgeHead;
  bool visited;
};

int top = -1;
void push(Vertex *value, Vertex *stack[], int size)
{
  if (top == size - 1)
  {
    cout << "Stack overflow" << endl;
    return;
  }
  top++;
  stack[top] = value;
}

Vertex *pop(Vertex *stack[], int size)
{
  if (top == -1)
  {
    return NULL;
  }
  Vertex *tmp = stack[top];
  top--;
  return tmp;
}

void addVertex(int rep, Vertex **head)
{
  Vertex *ptr = (Vertex *)malloc(sizeof(Vertex));
  ptr->rep = rep;
  ptr->next = NULL;
  ptr->edgeHead = NULL;
  ptr->visited = false;
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
  Vertex *ver1Node = *head;
  while (ver1Node != NULL)
  {
    if (ver1Node->rep == vertex1)
      break;
    ver1Node = ver1Node->next;
  }
  Vertex *ver2Node = *head;
  while (ver2Node != NULL)
  {
    if (ver2Node->rep == vertex2)
      break;
    ver2Node = ver2Node->next;
  }

  Edge *ver1ptr = (Edge *)malloc(sizeof(Edge));
  ver1ptr->verAdd = ver2Node;
  ver1ptr->next = NULL;
  if (ver1Node->edgeHead == NULL)
  {
    ver1Node->edgeHead = ver1ptr;
  }
  else
  {
    Edge *currEdge = ver1Node->edgeHead;
    while (currEdge->next != NULL)
    {
      currEdge = currEdge->next;
    }
    currEdge->next = ver1ptr;
  }
}

void printEdgesInVertex(Vertex *head, int vertex)
{
  Vertex *ver1Node = head;
  while (ver1Node != NULL)
  {
    if (ver1Node->rep == vertex)
      break;
    ver1Node = ver1Node->next;
  }
  if (ver1Node->edgeHead == NULL)
  {
    cout << "0 edges" << endl;
    return;
  }
  Edge *curr = ver1Node->edgeHead;
  while (curr != NULL)
  {
    cout << "Edge is " << curr->verAdd->rep << endl;
    curr = curr->next;
  }
}
void findPath(int src, int dest, Vertex *head)
{
  Vertex *stack[10];
  // find src node
  Vertex *srcNode = head;
  while (srcNode != NULL)
  {
    if (srcNode->rep == src)
    {
      break;
    }
    srcNode = srcNode->next;
  }
  // find dest node
  Vertex *destNode = head;
  while (destNode != NULL)
  {
    if (destNode->rep == dest)
    {
      break;
    }
    destNode = destNode->next;
  }
  if (destNode == NULL)
  {
    cout << "Connection not Exist ";
    return;
  }

  Vertex *currVertex = srcNode;
  do
  {
    Edge *currEdge = currVertex->edgeHead;
    while (currEdge != NULL && currEdge->verAdd->visited)
    {
      currEdge = currEdge->next;
    }
    currVertex->visited = true;
    if (currEdge == NULL)
    {
      currVertex = pop(stack, 10);
    }
    else
    {
      push(currVertex, stack, 10);
      currVertex = currEdge->verAdd;
    }
  } while (currVertex != destNode);
  cout << currVertex->rep;
  while (top != -1)
  {
    Vertex *tmp = pop(stack, 10);
    cout << " <- " << tmp->rep;
  }
  cout << endl;
  currVertex = head;
  while (currVertex != NULL)
  {
    currVertex->visited = false;
    currVertex = currVertex->next;
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

int findDegree(int vertex, Vertex *head)
{
  if (head == NULL)
  {
    cout << "Vertices not exist " << endl;
    return -1;
  }
  int count = 0;
  Vertex *currVertex = head;
  while (currVertex != NULL)
  {
    if (currVertex->rep == vertex)
    {
      break;
    }
    currVertex = currVertex->next;
  }
  if (currVertex == NULL)
  {
    cout << "this representation vertex not found in the graph" << endl;
    return -1;
  }
  Edge *currEdge = currVertex->edgeHead;
  while (currEdge != NULL)
  {
    count++;
    currEdge = currEdge->next;
  }
  return count;
}
int main()
{
  Vertex *head = NULL;
  // addVertex(1, &head);
  // addVertex(2, &head);
  // addVertex(3, &head);
  // addVertex(4, &head);
  // addVertex(5, &head);
  // addEdge(2, 1, &head);
  // addEdge(2, 4, &head);
  // addEdge(3, 1, &head);
  // addEdge(3, 5, &head);
  int n;
  do
  {
    cout << "Enter 1 to add vertex " << endl
         << "Enter 2 to add an edge " << endl
         << "Enter 3 to Find path " << endl
         << "Enter 4 to find cycle " << endl
         << "Enter 5 to find degree " << endl
         << "Enter 6 to print vertices " << endl
         << "Enter 7 to print edges in vertices" << endl
         << "Enter  8 to Quit" << endl;
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
      int direction;
      cout << "Make incoming connection or outgoing? enter 1 for incoming and 2 for outgoing : ";
      cin >> direction;
      if (direction == 1)
      {
        cout << vertex1 << " is adjacent from ? ";
        cin >> vertex2;
        addEdge(vertex2, vertex1, &head);
      }
      else if (direction == 2)
      {
        cout << vertex1 << " is adjacent to ? ";
        cin >> vertex2;
        addEdge(vertex1, vertex2, &head);
      }
      else
      {
        cout << "invalid value";
      }
    }
    else if (n == 3)
    {
      int src;
      cout << "Enter source representation : ";
      cin >> src;
      int dest;
      cout << "Enter Destination representation : ";
      cin >> dest;
      findPath(src, dest, head);
    }
    else if (n == 4)
    {
    }
    else if (n == 5)
    {
      int vertex;
      cout << "for which vertex you want to find degree : ";
      cin >> vertex;
      int degree = findDegree(vertex, head);
      cout << "Degree of vertex " << vertex << " is " << degree << endl;
    }
    else if (n == 6)
    {
      printVertices(head);
    }
    else if (n == 7)
    {
      int vertex;
      cout << "Enter vertex" << endl;
      cin >> vertex;
      printEdgesInVertex(head, vertex);
    }
    else if (n == 8)
    {
      cout << "Quit" << endl;
    }
    else
    {
      cout << "Invalid" << endl;
    }

  } while (n != 8);
}