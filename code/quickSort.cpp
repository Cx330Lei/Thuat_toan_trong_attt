#include <iostream>
using namespace std; 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // phan tu chot la phan tu cuoi cua mang
    int i = low ; 
    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        { 
            swap(&arr[i], &arr[j]);
            i++;
        } 
    } 
    swap(&arr[i], &arr[high]); 
    return i; 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
  
// Driver Code
int main() 
{ 
    int n,m;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	cin>>m;
    	arr[i] = m;
	}
    quickSort(arr, 0, n - 1); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
} 
int tinh(int n)
{
    if (n == 1)
        return 1;
    return (1/n)+tinh(n-1);
}






