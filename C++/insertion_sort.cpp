#include <iostream>
using namespace std;

void print(int *arr,int n) {
    cout<<"Output: ";
for(int i=0;i<n;i++) {
    cout<<arr[i]<<" ";
}    
cout<<endl;
}

void insertion(int *arr, int n) {
    int key,j;
    for(int i=1;i<n;i++) {
         key=arr[i];
         j=i-1;
         while(arr[j]>key && j>=0) {
             arr[j+1]=arr[j];
             j--;
         }
         arr[j+1]=key;
    }
}

int main()
{
    int size;
    cout<<"Enter Size of array\n";
    cin>>size;
    
    int*arr=new int[size];
    
    cout<<"Enter Elements\n";
    for(int i=0;i<size;i++) {
        cin>>arr[i];
    } 
    
    cout<<endl;
    print(arr,size);
    insertion(arr,size);
    cout<<endl;
    cout<<"After Sorting:\n";
    print(arr,size);
    
    return 0;
}
