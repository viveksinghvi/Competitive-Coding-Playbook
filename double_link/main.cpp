#include <iostream>

using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
};
class doub_list{
    public:
        node *h;
        node *t;
        doub_list(){
            h=NULL;
            t=NULL;
        }
        void add_f(int i){
            node *n=new (struct node);
            n->data=i;
            n->next=NULL;
            n->prev=NULL;
            if (h==NULL){
                h=n;
                t=n;
            }
            else{
                h->prev=n;
                n->next=h;
                h=n;
            }
        }
        void add_l(int i){
            node *n=new (struct node);
            n->data=i;
            n->next=NULL;
            n->prev=NULL;
            if (h==NULL){
                h=n;
                t=n;
            }
            else{
                t->next=n;
                n->prev=t;
                t=n;
            }
        }
        void view(){
            node *temp;
            temp=h;
            while(temp!=NULL){
                cout <<temp->data<<'\n';
                temp=temp->next;
            }
        }
};
int main()
{
    doub_list a;
    a.add_f(3);
    a.add_f(1);
    a.add_f(4);
    a.add_l(7);
    a.view();
    return 0;
}
