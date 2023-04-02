#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int dak)
    {
        this->data = dak;
        next = NULL;
    }
};
void create(int data, node *&head)
{
    node *newn = new node(data);
    if (head == NULL)
    {
        head = newn;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newn;
}
void insertfirst(int val, node *&head)
{
    node *newn = new node(val);
    if (head == NULL)
    {
        head = newn;
    }
    newn->next = head;
    head = newn;
}
node *reverselist(node *&head)
{
    node *current = head;
    node *prev = NULL;
    node *nextn;
    while (current != NULL)
    {
        nextn = current->next;
        current->next = prev;

        prev = current;
        current = nextn;
    }
    return prev;
}
void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
node *recuresivemethod(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = recuresivemethod(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
int main()
{
    int n;
    node *head = NULL;
    cout << "enter no.of nodes\t";
    cin >> n;
    int val;
    for (int i = 1; i <= n; i++)
    {
        cout << "enter the data to insert\t";
        cin >> val;
        create(val, head);
    }
    display(head);
    cout << "\n";
    // insering at first
    insertfirst(7, head);
    display(head);
    cout << "\n";
    /*
      //using normal method reversing the list
          node *newhead= reverselist(head);
          display(newhead);
    */
    cout << "\n";
    // reversing list using recursive function
    node *newhead1 = recuresivemethod(head);
    display(newhead1);
}