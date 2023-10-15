#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
class tree
{
public:
    node *root=NULL;
    void create(node *&root);
};
class stack
{
    node *item[MAX];

public:
    int top;
    stack()
    {
        top = -1;
    }
    void push(node *p)
    {
        if (top < MAX)
        {
            item[++top] = p;
        }
    }
    node *pop()
    {
        if (top >= 0)
        {
            return item[top--];
        }
        return NULL;
    }
    int isfull()
    {
        return top == 10;
    }
    bool isempty()
    {
        return top == -1;
    }
};
node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder_Recursive(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder_Recursive(root->left);
    cout << root->data << " ";
    inorder_Recursive(root->right);
}

void preorder_Recursive(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder_Recursive(root->left);
    preorder_Recursive(root->right);
}

void postorder_Recursive(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postorder_Recursive(root->left);
    postorder_Recursive(root->right);
    cout << root->data << " ";
}

void iterativeInorder(node *root)
{
    stack s1;
    node *temp = root;

    while (true)
    {
        while (temp != NULL)
        {
            s1.push(temp);
            temp = temp->left;
        }
        temp = s1.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}
void iterativePreorder(node *root)
{
    if (!root)
        return;

    stack s;
    s.push(root);

    while (!s.isempty())
    {
        node *node = s.pop();
        cout << node->data << " ";

        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
}

void iterativePostorder(node *root)
{
    if (!root)
        return;

    stack s1, s2;
    s1.push(root);

    while (!s1.isempty())
    {
        node *node = s1.pop();
        s2.push(node);

        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    while (!s2.isempty())
    {
        node *node = s2.pop();
        cout << node->data << " ";
    }
}

int countNodes(node *root)
{
    static int count = 0;
    if (root != NULL)
    {
        count++;
        countNodes(root->left);
        countNodes(root->right);
    }
    return count;
    /*if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);*/
}

int countLeafNodes(node *root)
{
    static int countleaf = 0;
    if (root == NULL)
        return countleaf;
    if (root->left == NULL && root->right == NULL)
        return ++countleaf;
    countLeafNodes(root->left);
    countLeafNodes(root->right);
    /*if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);*/
}
node *copy(node *root1, node *&root2)
{
    if (root1 != NULL)
    {
        root2 = new node(root1->data);
        root2->left = copy(root1->left, root2->left);
        root2->right = copy(root1->right, root2->right);
        return root2;
    }
    else
    {
        return NULL;
    }
}

node *mirror(node *root1, node *&root2)
{
    if (root1 != NULL)
    {
        root2 = new node(root1->data);
        root2->left = mirror(root1->right, root2->left);
        root2->right = mirror(root1->left, root2->right);
        return root2;
    }
    else
    {
        return NULL;
    }
}
node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    char ans;
    cout << "Insert " << data << " to the left or right of " << root->data << " (l/r): ";
    cin >> ans;

    if (ans == 'l')
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}
void tree::create(node *&root)
{
    node *temp, *newnode;
    char ans, choice;
    int c=0;
    do
    {
        cout << "Enter the element to be attached: ";
        cin>>c;
        newnode = new node(c); // call constructor of node class
        if (root == NULL)
            root = newnode;
        else
        {
            temp = root;
            while (1)
            {
                cout <<"Left or right(l / r) of " << temp->data<<":";
                cin >> ans;
                if (ans == 'l')
                    if (temp->left == NULL)
                    {
                        temp->left = newnode;
                        break;
                    }
                    else
                        temp = temp->left;
                else if (temp->right == NULL)
                {
                    temp->right = newnode;
                    break;
                }
                else
                    temp = temp->right;
            }
        }
        cout <<"Any more nodes (y/n):";
        cin >> choice;
    } while ((choice == 'y') ||(choice =='Y'));
    cout << "Tree created \n";
    levelOrderTraversal(root);
    cout << endl;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main()
{
    node *root = NULL;
    int choice;
    tree t;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Create Tree(Build Tree)\n";
        cout << "2. Inorder Traversal (Recursive)\n";
        cout << "3. Preorder Traversal (Recursive)\n";
        cout << "4. Postorder Traversal (Recursive)\n";
        // cout << "5. Inorder Traversal (Iterative)\n";
        // cout << "6. Preorder Traversal (Iterative)\n";
        // cout << "7. Postorder Traversal (Iterative)\n";
        // cout << "8. Level Order Traversal(Display)\n";
        // cout << "9. Total Nodes\n";
        // cout << "10. Total Leaf Nodes\n";
        // cout << "11. Create Mirror Tree\n";
        // cout << "12. Create Copy of Tree\n";
        // cout << "13. Insert a node\n";
        // cout << "14. Create tree using create function\n";
        cout << "15. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            root = buildTree(root);
            break;
        case 2:
            cout << "Inorder Traversal (Recursive): ";
            inorder_Recursive(root);
            cout << endl;
            break;
        case 3:
            cout << "Preorder Traversal (Recursive): ";
            preorder_Recursive(root);
            cout << endl;
            break;
        case 4:
            cout << "Postorder Traversal (Recursive): ";
            postorder_Recursive(root);
            cout << endl;
            break;
        case 5:
            cout << "Inorder Traversal (Iterative): ";
            iterativeInorder(root);
            cout << endl;
            break;
        case 6:
            cout << "Preorder Traversal (Iterative): ";
            iterativePreorder(root);
            cout << endl;
            break;
        case 7:
            cout << "Postorder Traversal (Iterative): ";
            iterativePostorder(root);
            cout << endl;
            break;
        case 8:
            cout << "Level Order Traversal: \n";
            levelOrderTraversal(root);
            cout << endl;
            break;
        case 9:
            cout << "Total Nodes in the Tree: " << countNodes(root) << endl;
            break;
        case 10:
            cout << "Total Leaf Nodes in the Tree: " << countLeafNodes(root) << endl;
            break;
        case 11:
            node *mirrorRoot;
            mirror(root, mirrorRoot);
            cout << "Mirror Tree created.\n";
            levelOrderTraversal(mirrorRoot);
            break;
        case 12:
            node *copyRoot;
            copy(root, copyRoot);
            cout << "Copy of the Tree created.\n";
            levelOrderTraversal(copyRoot);
            break;
        case 13:
            int data;
            cout << "Enter the data to insert: ";
            cin >> data;
            root = insert(root, data);
            break;
        case 14:
            t.create(root);
            break;
        case 15:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 16);
    return 0;
}
// Delete function REMAINING!