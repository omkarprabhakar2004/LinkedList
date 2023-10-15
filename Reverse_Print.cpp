#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int x){
        this->data=x;
        this->next=NULL;
    }
};

class linkedlist{
    public:
    node* head;
    linkedlist(){
        head=NULL;
    }

    void print(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void insertattail(int x){
        node* new_node=new node(x);
        if(head==NULL){
            head=new_node;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
};

void reverseprint(node* &head){
    if(head==NULL){
        return;
    }
    reverseprint(head->next);
    cout<<head->data<<" ";

}
int main(){
    linkedlist ll;
    ll.insertattail(1);
    ll.insertattail(2);
    ll.insertattail(3);
    ll.print();
    reverseprint(ll.head);
}