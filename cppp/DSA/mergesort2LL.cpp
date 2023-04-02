#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        this->data = val;
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
node *mergsort(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *dummy = new node(-1);
    node *p3 = dummy;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}
node *recurtive(node *&head1,node *&head2){
    node *result;
    while(head1==NULL){
        return head2;

    }
    while(head2==NULL){
        return head1;

    }
    if(head1->data<head2->data){
        result=head1;
        result->next=recurtive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=recurtive(head1,head2->next);
    }
    return result;
}
void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    int arr[100] = {5, 3, 2, 9};
    int arr1[100] = {8, 7, 10};
    for (int i = 0; i < 4; i++)
    {
        create(arr[i], head1);
    }
    for (int i = 0; i < 3; i++)
    {
        create(arr1[i], head2);
    }

    display(head1);

    display(head2);
    node *head3 = recurtive(head1, head2);
    display(head3);
}