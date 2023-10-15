#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int x) // constructor
    {
        data = x;
        next = NULL;
    }
};

class queue
{
    node *front, *rear;
    int capacity; // Maximum capacity of the queue
    int size;     // Current number of elements in the queue

public:
    // constructor
    queue(int cap)
    { 
        front = rear = NULL;
        capacity = cap;
        size = 0;
    };
    void display();
    void enqueued(int n);
    int dequeued();
    int isEmpty();
    int isFull();
};

int queue::isEmpty()
{
    return (front == NULL);
}

int queue::isFull()
{
    return (size == capacity);
}

void queue::enqueued(int n)
{
    if (isFull())
    {
        cout << "Queue is full, cannot enqueue." << endl;
        return;
    }

    node *newnode = new node(n);
    if (isEmpty())
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    size++; // Increment the size after enqueueing a new element
}

int queue::dequeued()
{
    if (isEmpty())
    {
        cout << "Queue is empty, cannot dequeue." << endl;
        return -1;
    }
    int n = front->data;
    node *temp = front;
    front = front->next;
    delete temp;
    size--; // Decrement the size after dequeuing an element
    if (front == NULL)
        rear = NULL;
    return n;
}

void queue::display()
{
    if (front == NULL)
    {
        cout << "Queue is empty." << endl;
        return;
    }
    node *current = front; // Use a separate pointer for traversal
    while (current != NULL)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    queue q(capacity); // Create a queue with the specified capacity
    int choice;
start:
    do
    {
        cout << "\n********************************************** QUEUE **********************************************" << endl;
        cout << "1. Enqueued\n";
        cout << "2. Dequeued\n";
        cout << "3. Display\n";
        cout << "4. IsEmpty\n";
        cout << "5. IsFull\n";
        cout << "6. Exit\n";
        cin >> choice;
        if (choice == 1)
        {
            int n;
            cout << "Enter element to insert in Queue: ";
            cin >> n;
            q.enqueued(n);
        }
        else if (choice == 2)
        {
            int dequeuedValue = q.dequeued();
            cout << "Dequeued: " << dequeuedValue << endl;
        }

        else if (choice == 3)
        {
            q.display();
        }

        else if (choice == 4)
        {
            int a = q.isEmpty();
            cout << a << endl;
        }

        else if (choice == 5)
        {
            int a = q.isFull();
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
