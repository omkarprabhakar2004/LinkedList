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

class circularll{
    public:
    node* head;

    circularll(){
        head=NULL;
    }
    
    //O(n)
    void insertathead(int x){
        node* new_node=new node(x);
        if(head==NULL){
            head=new_node;
            new_node->next=head;  //cll
            return;
        }
        node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        //now tail is pointing to the last node
        tail->next=new_node;
        new_node->next=head;
        head=new_node;
    }
    //O(n)
    void insertatend(int x){
        node* new_node=new node(x);
        if(head==NULL){
            head=new_node;
            new_node->next=head;  //cll
            return;
        }
        node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        //now tail is pointing to the last node
        tail->next=new_node;
        new_node->next=head;

    }
    //SAME as SLL
    void insertatpos(int x,int pos){
    if(pos==0){
        insertathead(x);
        return;
    }
    node* new_node=new node(x);
    node* temp=head;
    int current_pos=0;
    while(current_pos!=pos-1){
        temp=temp->next;
        current_pos++;
    }
    //temp at pos-1
    new_node->next=temp->next;
    temp->next=new_node;
    }


    void checkcircular(){
        node* temp=head;
        for(int i=0;i<20;i++){
            cout<<temp->data<<"->";
            temp=temp->next;
        }cout<<endl;
    }
    void print(){
        node* temp=head;
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
};

int main(){
    circularll l1;
    l1.insertathead(10);
    l1.insertathead(11);
    l1.insertatend(9);
    l1.insertatpos(8,1);
    l1.checkcircular();
    l1.print();
    
}