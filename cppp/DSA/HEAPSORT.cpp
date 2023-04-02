#include "bits/stdc++.h"
using namespace std;
int heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[largest] < arr[l])
    {
        largest = l;
    }
    if (r < n && arr[largest] < arr[r])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, i, largest);
    }
}
int heapsort(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    int arr[] = {30, 34, 56, 24, 54, 31};
    int n = 6;
    heapsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}