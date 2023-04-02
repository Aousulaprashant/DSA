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
void display(node *&head)
{
    node *temp = head;
    while (temp->next!= NULL)
    {
        cout << "[" << temp->data << "]"<< " -> ";
        temp = temp->next;
    }
    cout << "[NULL]";
}
node *makecyc(node *&head, int pos)
{
    node *startnode;
    node *temp = head;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}
bool detect(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
node *correct(node *head){
    node *slow = head;
    node *fast = head;
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast=head;
    while(fast->next!=slow->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;

}
int main()
{
    int n;
    node *head = NULL;
    cout << "enter no.of nodes:\t";
    cin >> n;
    int val;
    for (int i = 1; i <= n; i++)
    {
        cout << "enter the data to insert:\t";
        cin >> val;
        create(val, head);
    }
     display(head);
    cout << "\n";
    makecyc(head, 3);
    cout << "\n";
   // display(head);

    cout << detect(head);
    cout << "\n";
    correct(head);
    cout << detect(head);    
    cout << "\n";
    
    display(head);
}