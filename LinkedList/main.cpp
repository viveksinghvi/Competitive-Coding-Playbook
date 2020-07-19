#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

// Node class
class Node {
    public:
    int data;
    Node* next;
    Node(int i) {
        data=i;
        next=NULL;
    };
};
class List {
    public:
    Node *head;
    List(){
        head=NULL;
    }
    void print(){
    Node *temp = head;
    if ( temp == NULL ) {
    cout << "EMPTY" << endl;
    return;
    }
    while (temp!=NULL){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout << "NULL" << endl;
    }
    void append(int data){
        Node* a=new Node(data);
        if (head==NULL){
            head=a;
        }
        else{
            Node* temp=head;
            while (temp->next!=NULL){
                temp=temp->next;
            }
        temp->next=a;
        }
    }
    void Delete(int data);
};

int main(){
    List a=List();
    a.append(1);
    a.append(2);
    a.print();
}
