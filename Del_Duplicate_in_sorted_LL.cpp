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
    void print(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

void deleteduplicate(node* &head){
    node* curr_node=head;
    while(curr_node!=NULL){
        while( (curr_node->next!=NULL) && (curr_node->data==curr_node->next->data)){
            node* temp=curr_node->next;  //node to be deleted
            curr_node->next=curr_node->next->next;
            free(temp);
        }
        //this loop ends when current node and next node values are different
        //or ll ends
        curr_node=curr_node->next;
    }
}

int main(){
    linkedlist ll;
    ll.insertattail(1);
    ll.insertattail(1);
    ll.insertattail(2);
    ll.insertattail(2);
    ll.insertattail(2);
    ll.insertattail(3);
    ll.insertattail(3);
    ll.insertattail(3);
    ll.insertattail(3);
    deleteduplicate(ll.head);
    ll.print();
}
