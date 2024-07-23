// deletion and insertion of linkedlist

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertarraytolist(vector<int> v)
{
    if (v.empty())
        return nullptr;

    Node *head = new Node(v[0]);
    Node *temp = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newnode = new Node(v[i]);
        temp->next = newnode;
        temp = newnode;
    }

    return head;
}

Node *traverse(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}

// delete a head node
Node *deleteHead(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *temp = head;
    head = head->next;
    // delete temp;
    free(temp);
    return head;
}

// delete a node at the end

Node *deleteEnd(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// delete a node at the given position
Node *deleteposition(Node *head, int key)
{
    if (head == NULL)
        return head;

    Node *temp = head;
    int count = 0;
    Node *prev = NULL;
    while (temp != NULL)
    {
        count++;
        if (count == key)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertathead(Node *head, int data)
{
    Node *newnode = new Node(data);
    newnode->next = head;
    head = newnode;
    return head;
}

// insert at any given postion
Node *insertatgivenpositon(Node *head, int val, int pos)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        return newnode;
    }

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == pos)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }

    return head;
}




int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *head = new Node(v[0]);
    // head print
    cout << head->data << endl;

    // convert array to linked list
    Node *head1 = convertarraytolist(v);
    cout << head1->data << endl;

    // delete head node
    head1 = deleteHead(head1);
    cout << head1->data << endl; // ans = 2

    // // delete end node
    // head1 = deleteEnd(head1);
    // traverse(head1); // ans = 2 3 4 5 6 7 8 9

    // delete node at the given position
    head1 = deleteposition(head1, 4);
    traverse(head1); // ans = 2 3 4 6 7 8 9

    // insert at head
    head1 = insertathead(head1, 1);
    traverse(head1); // ans = 1 2 3 4 6 7 8 9

    // insert at a given position
    head1 = insertatgivenpositon(head1, 15, 2);
    traverse(head1);

    return 0;
}
