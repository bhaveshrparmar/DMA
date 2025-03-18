#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_at_begginning(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void search_Key(int key)
    {

        bool isfindkey = false;

        if (head == NULL)
        {
            cout << "Linked List is Empty!";
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << temp->data << " Yes, This Key is Exist! " << endl;
                isfindkey = true;
            }
            temp = temp->next;
        }

        if (!isfindkey)
        {
            cout << "No, This Key Not Exist!";
        }
    }

    void deleteNode(int pos)
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty!" << endl;
            return;
        }

        Node *temp = head;

        if (pos == 1)
        {
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 1; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            cout << "Invalid Position!" << endl;
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        cout << endl;
    }

    void reverseNode()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void printFunction()
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty!";
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
        cout << endl;
    }
};

int main()
{

    List ll;

    ll.insert_at_begginning(100);
    ll.insert_at_begginning(200);
    ll.insert_at_begginning(300);
    ll.insert_at_begginning(400);
    ll.insert_at_begginning(500);

    ll.printFunction();
    ll.search_Key(200);

    ll.deleteNode(3);
    ll.printFunction();
    ll.reverseNode();
    ll.printFunction();
}