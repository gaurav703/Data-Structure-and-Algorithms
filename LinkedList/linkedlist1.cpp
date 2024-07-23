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

// search element in linked list
Node *search(Node *head, int key)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            cout << "Element found" << endl;
            return temp;
        }
        temp = temp->next;
    }
    cout << "Element not found" << endl;
    return nullptr;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = new Node(v[0]);
    // head print
    cout << head->data << endl;

    // convert array to linked list
    Node *head1 = convertarraytolist(v);
    cout << head1->data << endl;

    // traverse linked list
    traverse(head1);

    // search element in linked list
    search(head1, 3);

    return 0;
}
