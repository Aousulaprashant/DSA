#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int dak)
    {
        this->data = dak;
        next = NULL;
        prev = NULL;
    }
};
void inserthead(int val, node *&head)
{
    node *newn = new node(val);
    newn->next = head;
    if(head!=NULL){
        head->prev = newn;
    }
    
    head = newn;
}
void create(int data, node *&head)
{

    if (head == NULL)
    {
        inserthead(data, head);
        return;
    }
    node *newn = new node(data);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newn;
    newn->prev = temp;
}
void deletef(int pos,node * &head){
    int count=1;
    node *temp=head;
    while(temp->next!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    delete temp;

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
    
    inserthead(35,head);
    display(head);
    cout << "\n";
    deletef(2,head);
     display(head);
   
    cout << "\n";
}