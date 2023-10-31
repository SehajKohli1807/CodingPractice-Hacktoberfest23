#include <iostream>
using namespace std;

void print(int *a,int n) {
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
}

void swap(int *xp,int *yp) {
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}

int partition(int*a,int l,int r) {
    int pivot=a[r];
     int i=l-1;
    for(int j=l;j<r;j++) {
        if(a[j]<pivot) {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return (i+1);
}

void quick_sort(int *a,int l, int r) {
    if(l<r) {
        int p=partition(a,l,r);
        quick_sort(a,l,p-1);
        quick_sort(a,p+1,r);
    }
}

int main()
{
    int size;
    cout<<"Enter Size\n";
    cin>>size;
    
    int *arr= new int[size];
    
    cout<<"Enter elements\n";
    for(int i=0;i<size;i++) {
        cin>>arr[i];
    }
    
    quick_sort(arr,0,size-1);
    print(arr,size);

    return 0;
}