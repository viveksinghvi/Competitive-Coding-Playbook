#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

int main(int argc, const char * argv[])
{
  node *n;
  node *t;
  node *h;
  int size;
  int item;
  int i;

  cout << "How many items are in your list?" << endl;
  cin >> size;

  n = new node;
  cout << "Enter the first item: " << endl;
  cin >> item;
  n->data = item;
  t = n;
  h = n;

  for (i = 1; i<size-1; i++){
  n = new node;
  cout << "Enter the next item: " << endl;
  cin >> item;
  n->data = item;
  t->next = n;
  t = t->next;
  }
  n = new node;
  cout << "Enter the last item: " << endl;
  cin >> item;
  n->data = item;
  t->next = n;
  n->next=NULL;

  node *p;
  p=h;

  cout << "The list contains:" << endl;

  while (p!=NULL){
  cout << p->data << " ";
  p = p->next;
  }
  return 0;
}
