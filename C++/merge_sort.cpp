#include <iostream>
using namespace std;

void print(int *a,int n) {
    cout<<"Output: ";
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
}

void merge(int *a,int l, int mid, int r) {
    int size1=mid-l+1;
    int size2=r-mid;
    
    int* arr1=new int [size1];
    int* arr2=new int [size2];
    
    for(int i=0;i<size1;i++) {
        arr1[i]=a[l+i];
    }
    
    for(int j=0;j<size2;j++) {
        arr2[j]=a[mid+1+j];
    }
    
    int i=0,j=0,k=l;
    
    while(i<size1 && j<size2) {
        if(arr1[i]<=arr2[j]) {
            a[k]=arr1[i];
            i++;
        } else {
            a[k]=arr2[j];
            j++;
        }
         k++;
    }
   

while(i<size1) {
    a[k]=arr1[i];
    i++;
    k++;
}

while(j<size2) {
    a[k]=arr2[j];
    j++;
    k++;
}

}

void merge_sort(int *a,int si,int li) {
    if(si<li) {
        int mid=(si+li)/2;
        merge_sort(a,si,mid);
        merge_sort(a,mid+1,li);
        merge(a,si,mid,li);
    }
}

int main()
{
     int n;
    cout<<"Enter the size\n";
    cin>>n;
    
    int *arr=new int[n];
    
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    
    merge_sort(arr,0,n-1);
    print(arr,n);

    return 0;
}