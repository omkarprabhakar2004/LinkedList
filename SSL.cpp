#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
 
    //constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};


//Time Complexity=O(1)
void insertathead(node* &head,int x){    //& or reference is used bcoz it make changes in original ll
    node* new_node=new node(x);          //creating newnode
    new_node->next=head;                 //Pointing newnode to first node
    head=new_node;                       //pointing head to newnode
}

//Time Complexity=O(n)
//Time Complexity=O(1) if tail pointer is given
void insertattail(node* &head,int x){
    node* new_node=new node(x);
    node* temp=head;
    //Traversing
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //temp has reached last node
    temp->next=new_node;
}

//Time Complexity= Bestcase: O(pos)  Worstcase: 0(n)
void insertatpos(node* &head,int x,int pos){
    if(pos==0){
        insertathead(head,x);
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

void insertatdata(node* &head,int x, int olddata){
    node* new_node=new node(x);
    node* temp=head;
    while(temp->data!=olddata){
        temp=temp->next;
    }
    //temp at pos
    new_node->next=temp->next;
    temp->next=new_node;
}




//Time Complexity=O(1)
void updateathead(node* &head,int x){
    if(head==NULL){
        insertathead(head,x);
        return;
    }
    head->data=x;
}

//Time Complexity=O(n)
void updateattail(node* &head,int x){
    if(head==NULL){
        insertathead(head,x);
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //Temp at tail
    temp->data=x;
}

//Time Complexity= Bestcase: O(pos)  Worstcase: 0(n)
void updateatpos(node* &head,int x,int pos){
    if(pos==0){
        updateathead(head,x);
        return;
    }
    node* temp=head;
    int current_pos=0;
    while(current_pos!=pos){
        temp=temp->next;
        current_pos++;
    }
    //temp at pos
    temp->data=x;
}

void updateatdata(node* &head,int x,int olddata){
    node* temp=head;
    while(temp->data!=olddata){
        temp=temp->next;
    }
    //temp at pos
    temp->data=x;
}




//Time Complexity=O(1)
void deleteathead(node* &head){
    node* temp=head;  //node to be deleted
    head=head->next;  //declaring new head
    delete(temp);
}

//Time Complexity=O(n)
void deleteattail(node* &head){
    node* second_last=head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }
    //At second_last 
    node* temp=second_last->next;
    second_last->next=NULL;
    free(temp);
}

//Time Complexity= Bestcase: O(pos)  Worstcase: 0(n)
void deleteatpos(node* &head,int pos){
    if(pos==0){
        deleteathead(head);
        return;
    }
    node* temp=head;
    int current_pos=0;
    while(current_pos!=pos-1){
        temp=temp->next;
        current_pos++;
    }
    //temp at pos-1
    node* temp2=temp->next;  //Storing address of node which has to be deleted
    temp->next=temp->next->next;    
    free(temp2);
}

void deleteatdata(node* &head,int olddata){
    node* temp=head;
    while(temp->next->data!=olddata){
        temp=temp->next;

    }
    //temp at pos-1
    node* temp2=temp->next;  //Storing address of node which has to be deleted
    temp->next=temp->next->next;    
    free(temp2);
}




void print(node* head){         //& is not used as we are only printing the ll, not changing it
    node* temp=head;            //creating a temp(copy of head) so that head pointer does not get change
    while(temp!=NULL){          //as last node's next have NULL
        cout<<temp->data<<"-> ";  //printing data of each node
        temp=temp->next;        //pointing temp to next node
    }
    cout<<"NULL"<<endl;
}

int main(){
    // node* newnode= new node(5);
    // cout<<newnode->data<<endl;
    // cout<<newnode->next<<endl;

    node* head=NULL;  //creating head

    insertathead(head,6);
    insertathead(head,5);
    insertathead(head,4);
 
    // insertattail(head,8);
    // insertattail(head,7);

    // insertatpos(head,36,2);
    insertatdata(head,66,6);
    
    // updateathead(head,44);
    // updateattail(head,77);
    // updateatpos(head,70,0);
    // updateatdata(head,7,70);

    // deleteatpos(head,1);
    // deleteathead(head);
    // deleteattail(head);
    deleteatdata(head,66);

    

    print(head);

    return 0;
}