#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    // constructor
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class stack
{
    node *top;
    int capacity; // Maximum capacity of the stack
    int size;     // Current number of elements in the stack

public:
    stack(int cap)
    {
        top = NULL;
        capacity = cap;
        size = 0;
    };
    void display();
    void push(int n);
    int pop();
    int isEmpty();
    int isFull();
};

void stack::display()
{
    cout<<"\nSTACK"<<endl;
    if (top == NULL)
    {
        cout << "Stack is empty." << endl;
        return;
    }
    node *current = top;
    while (current != NULL)
    {
        cout << current->data <<endl;
        current = current->next;
    }
    
}

void stack::push(int n)
{
    if (isFull())
    {
        cout << "Stack is full. Cannot push." << endl;
        return;
    }

    node *new_node = new node(n);
    new_node->next = top;
    top = new_node;
    size++;
}

int stack::pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty. Cannot pop." << endl;
        return -1;
    }
    int n = top->data;
    node *temp = top;
    top = top->next;
    delete temp;
    size--; // Decrement the size after popping an element
    return n;
}

int stack::isEmpty()
{
    return top == NULL;
}

int stack::isFull()
{
    return size == capacity; // Check if the current size equals the capacity
}

int main()
{
    int capacity;
    cout << "Enter the capacity of the Stack: ";
    cin >> capacity;

    stack s(capacity); // Create a stack with the specified capacity
    int choice;
start:
    do
    {
        cout << "\n********************************************** STACK **********************************************" << endl;
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. Display\n";
        cout << "4. IsEmpty\n";
        cout << "5. IsFull\n";
        cout << "6. Exit\n";
        cout<<"Enter Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int n;
            cout << "Enter element to push in Stack: ";
            cin >> n;
            s.push(n);
        }
        else if (choice == 2)
        {
            int poppedValue = s.pop();
            cout << "Popped: " << poppedValue << endl;
        }

        else if (choice == 3)
        {
            s.display();
        }

        else if (choice == 4)
        {
            int a = s.isEmpty();
            cout << a << endl;
        }

        else if (choice == 5)
        {
            int a = s.isFull();
            cout << a << endl;
        }

        else if (choice == 6)
        {
            cout << "End" << endl;
            goto end;
        }
        else
        {
            cout << "Invalid Option" << endl;
            goto start;
        }
    } while (choice != 6);

end:
    return 0;
}