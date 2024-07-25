#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node *convertarrDLL(vector<int> v)
{
    Node *head = new Node(v[0]);
    Node *temp = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newnode = new Node(v[i]);
        newnode->prev = temp;
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

Node *deleteathead(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *back = head;
    head = head->next;
    head->prev = nullptr;
    back->next = nullptr;
    delete back;

    return head;
}

Node *deleteattail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *back = temp->prev;
    back->next = nullptr;
    temp->prev = nullptr;
    delete temp;

    return head;
}

// delete the kth element
Node *deleteatkthelement(Node *head, int pos)
{
    if (head == NULL)
    {
        return NULL;
    }

    int count = 0;
    Node *temp = head;
    while (temp->next != NULL)
    {
        count++;
        if (count == pos)
        {
            break;
        }
        temp = temp->next;
    }

    Node *back = temp->prev;
    Node *front = temp->next;

    if (back == NULL && front == NULL)
    {
        delete temp;
        return NULL;
    }
    else if (back == NULL)
    {
        head = deleteathead(temp);
        return head;
    }
    else if (front == NULL)
    {
        head = deleteattail(temp);
        return head;
    }

    back->next = front;
    front->prev = back;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;

    return head;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = convertarrDLL(v);
    traverse(head);

    // delete at head
    Node *head1 = deleteathead(head);
    traverse(head1);

    // delete at the tail
    head1 = deleteattail(head1);
    traverse(head1);

    // delete at the kth element
    head1 = deleteatkthelement(head1, 3);
    traverse(head1);

    return 0;
}