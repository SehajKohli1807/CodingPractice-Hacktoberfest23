#include <iostream>
using namespace std;

void bubble(int*a,int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1-i;j++) {
            if(a[j]>a[j+1]) {
                a[j]^=a[j+1]^=a[j]^=a[j+1];
            }
        }
    }
}


int main()
{ 
    int size;
    cout<<"Enter size\n";
    cin>>size;
    
    int*arr=new int [size];
    
    cout<<"Enter Elements\n";
    for(int i=0;i<size;i++) {
        cin>>arr[i];
    }
    
    bubble(arr,size);
    
    cout<<endl;
    cout<<"Output after sorting: ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}
