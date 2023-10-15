#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

class linkedlist
{
public:
    node *head;
    linkedlist()
    {
        head = NULL;
    }

    void insertathead(int x)
    {
        node *new_node = new node(x);
        new_node->next = head;
        head = new_node;
    }

    void insertattail(int x)
    {
        node *new_node = new node(x);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // At tail
        temp->next = new_node;
    }

    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void delalternate(node* &head)
    {
        node* curr_node=head;
        while (curr_node!=NULL && curr_node->next != NULL)
        {
            node *temp = curr_node->next;   //Node to be deleted
            curr_node->next = curr_node->next->next;
            free(temp);
            curr_node = curr_node->next;
        }
    }

int main()
{
    linkedlist ll;
    // ll.insertathead(1);
    ll.insertattail(1);
    ll.insertattail(2);
    ll.insertattail(3);
    ll.insertattail(4);
    ll.insertattail(5);
    ll.insertattail(6);
    delalternate(ll.head);
    ll.print();
}