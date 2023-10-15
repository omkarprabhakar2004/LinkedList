#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int x)
    {
        this->data = x;
        this->prev = NULL; //**
        this->next = NULL;
    }
};

class doublyll
{
public:
    node *head, *tail; //**
    doublyll()
    {
        head = NULL;
        tail = NULL; //**
    }

    void create()
    {
        int num;
        cout << "Enter the number of nodes you want to create: ";
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            int x;
            cout << "Enter value for node " << i + 1 << ": ";
            cin >> x;

            node *new_node = new node(x);
            node *temp;
            if (head == NULL)
            {
                head = temp = new_node;
            }
            else
            {
                temp->next = new_node;
                new_node->prev = temp; //**
                temp = new_node;
                tail = new_node; //**
            }
        }
    }
    // O(1)
    void insertathead(int x)
    {
        node *new_node = new node(x);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    // O(1)
    void insertattail(int x)
    {
        node *new_node = new node(x);
        if (tail == NULL)
        {
            tail = new_node;
            head = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    // Time Complexity= Bestcase: O(pos)  Worstcase: 0(n)
    void insertatpos(int x, int pos)
    {
        if (pos == 0)
        {
            insertathead(x);
            return;
        }
        node *new_node = new node(x);
        node *temp = head;
        int current_pos = 0;
        while (current_pos != pos - 1)
        {
            temp = temp->next;
            current_pos++;
        }
        // temp at pos-1
        new_node->next = temp->next;
        temp->next = new_node;

        new_node->prev = temp;           //**
        new_node->next->prev = new_node; //**
    }

    void insertatdata(int x, int olddata)
    {
        node *new_node = new node(x);
        node *temp = head;
        while (temp->data != olddata)
        {
            temp = temp->next;
        }
        // temp at pos
        new_node->next = temp->next;
        temp->next = new_node;

        new_node->prev = temp;       //**
        temp->next->prev = new_node; //**
    }

    // SAME as SLL
    void updateathead(int x)
    {
        if (head == NULL)
        {
            insertathead(x);
            return;
        }
        head->data = x;
    }

    void updateattail(int x)
    {
        if (head == NULL)
        {
            insertathead(x);
            return;
        }
        tail->data = x;
    }

    // SAME as SLL
    void updateatpos(int x, int pos)
    {
        if (pos == 0)
        {
            updateathead(x);
            return;
        }
        node *temp = head;
        int current_pos = 0;
        while (current_pos != pos)
        {
            temp = temp->next;
            current_pos++;
        }
        // temp at pos
        temp->data = x;
    }

    // SAME as SLL
    void updateatdata(int x, int olddata)
    {
        node *temp = head;
        while (temp->data != olddata)
        {
            temp = temp->next;
        }
        // temp at pos
        temp->data = x;
    }

    void deleteathead()
    {
        node *temp = head;
        head = head->next;
        head->next->prev = head; //**
        free(temp);
    }

    // SAME as SLL
    void deleteattail()
    {
        node *second_last = head;
        while (second_last->next->next != NULL)
        {
            second_last = second_last->next;
        }
        // At second last
        node *temp = second_last->next;
        second_last->next = NULL;
        free(temp);
    }

    void deleteatpos(int pos)
    {
        if (pos == 0)
        {
            deleteathead();
            return;
        }
        node *temp = head;
        int current_pos = 0;
        while (current_pos != pos - 1)
        {
            temp = temp->next;
            current_pos++;
        }
        // temp at pos-1
        node *temp2 = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp; //**
        free(temp2);
    }

    void deleteatdata(int x)
    {
        node *temp = head;
        while (temp->next->data != x)
        {
            temp = temp->next;
        }
        // temp at pos-1
        node *temp2 = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp; //**
        free(temp2);
    }

    // SAME AS SLL
    void searchdata(int x)
    {
        node *temp = head;
        int position = 0;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                cout << "Value " << x << " found at position " << position << " in the list." << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Value " << x << " not found in the list." << endl;
    }

    void concatenate(doublyll &d2)
    {
        if (head == NULL)
        {
            head = d2.head;
        }
        else
        {
            node *temp=head;
            while (temp->next != NULL)
            { 
                temp = temp->next;
            }
            temp->next = d2.head;
            d2.head->prev = temp; //**
        }
    }

    // SAME AS SLL
    void sort()
    {
        if (head == NULL)
        {
            cout << "List is empty. Nothing to sort." << endl;
            return;
        }
        node *current, *index;
        int tempValue;

        for (current = head; current != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data > index->data)
                {
                    tempValue = current->data;
                    current->data = index->data;
                    index->data = tempValue;
                }
            }
        }
    }

    // SAME as SLL
    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    doublyll d1, d2;
    int choice;
start:
    do
    {
        cout << "\n*************************************************************** DOUBLY LINKED LIST ***************************************************************" << endl;
        cout << "0.   Create" << endl;
        cout << "1.   Insert at head" << endl;
        cout << "2.   Insert at tail" << endl;
        cout << "3.   Insert at Position" << endl;
        cout << "4.   Insert at data" << endl;

        cout << "5.   Update at head" << endl;
        cout << "6.   Update at tail" << endl;
        cout << "7.   Update at Position" << endl;
        cout << "8.   Update at data" << endl;

        cout << "9.   Delete at head" << endl;
        cout << "10.  Delete at tail" << endl;
        cout << "11.  Delete at Position" << endl;
        cout << "12.  Delete at data" << endl;

        cout << "13.  Search data" << endl;
        // cout << "14. Reverse" << endl;

        cout << "15.  Create list2" << endl;
        cout << "16.  Concatenate" << endl;
        cout << "17.  Sort" << endl;

        cout << "99.  Print" << endl;
        cout << "100. Exit\n"
             << endl;
        cin >> choice;
        if (choice == 0)
        {
            d1.create();
        }
        else if (choice == 1)
        {
            int x;
            cout << "Enter Value which u want to insert" << endl;
            cin >> x;
            d1.insertathead(x);
        }
        else if (choice == 2)
        {
            int x;
            cout << "Enter Value which u want to insert" << endl;
            cin >> x;
            d1.insertattail(x);
        }
        else if (choice == 3)
        {
            int x, y;
            cout << "Enter Value which u want to insert" << endl;
            cin >> x;
            cout << "Enter Position where u want to insert" << endl;
            cin >> y;
            d1.insertatpos(x, y);
        }
        else if (choice == 4)
        {
            int x, y;
            cout << "Enter Value which u want to insert" << endl;
            cin >> x;
            cout << "Enter Data where u want to insert" << endl;
            cin >> y;
            d1.insertatdata(x, y);
        }

        else if (choice == 5)
        {
            int x;
            cout << "Enter Value which u want to update" << endl;
            cin >> x;
            d1.updateathead(x);
        }
        else if (choice == 6)
        {
            int x;
            cout << "Enter Value which u want to update" << endl;
            cin >> x;
            d1.updateattail(x);
        }
        else if (choice == 7)
        {
            int x, y;
            cout << "Enter Value which u want to update" << endl;
            cin >> x;
            cout << "Enter Position where u want to update" << endl;
            cin >> y;
            d1.updateatpos(x, y);
        }
        else if (choice == 8)
        {
            int x, y;
            cout << "Enter Value which u want to update" << endl;
            cin >> x;
            cout << "Enter Data where u want to update" << endl;
            cin >> y;
            d1.updateatdata(x, y);
        }

        else if (choice == 9)
        {
            d1.deleteathead();
            cout << "Deleted\n";
        }
        else if (choice == 10)
        {
            d1.deleteattail();
            cout << "Deleted\n";
        }
        else if (choice == 11)
        {
            int x;
            cout << "Enter Position on which u want to delete" << endl;
            cin >> x;
            d1.deleteatpos(x);
        }
        else if (choice == 12)
        {
            int x;
            cout << "Enter Data which u want to delete" << endl;
            cin >> x;
            d1.deleteatdata(x);
        }

        else if (choice == 13)
        {
            int x;
            cout << "Enter Data to search" << endl;
            cin >> x;
            d1.searchdata(x);
        }

        // NO NEED IN DLL
        //  else if (choice == 14)
        //  {
        //      d1.reverse();
        //  }

        else if (choice == 15)
        {
            d2.create();
            d2.print();
        }
        else if (choice == 16)
        {
            d1.concatenate(d2);
        }
        else if (choice == 17)
        {
            d1.sort();
        }

        else if (choice == 99)
        {
            d1.print();
            cout << endl;
        }
        else if (choice == 100)
        {
            cout << "Exiting" << endl;
            goto end;
        }
        else
        {
            cout << "Invalid Option" << endl;
            goto start;
        }
    } while (choice != 100);
end:
    return 0;
}