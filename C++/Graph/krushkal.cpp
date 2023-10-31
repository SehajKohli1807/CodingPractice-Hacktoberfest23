#include <iostream>
#include <algorithm>
using namespace std;

class Edges {
    public:
    int start;
    int destination;
    int weight;
};

bool compare(Edges e1,Edges e2) {
    return e1.weight<e2.weight;
}

int findParent(int current,int* parent) {
    if(parent[current]==current) {
        return current;
    }
    
    return findParent(parent[current],parent);
}
void Krushkal(Edges* input,int n, int e) {
    sort(input,input+e,compare);             //inbuilt sort (starting iterator, ending iterator, function)
    
    Edges*output= new Edges[n-1];
    
    int* parent =new int [n];
    for(int i=0;i<n;i++) {
        parent[i]=i;
    }
    
    int count=0;
    int i=0;
    
    while(count!=n-1) {
        Edges currentEdge=input[i];
        int sourceParent=findParent(currentEdge.start,parent);
        int destinationParent=findParent(currentEdge.destination,parent);
        
        if(sourceParent!=destinationParent) {
            output[count]=currentEdge;         //in output array we will add sequentially
            parent[sourceParent]=destinationParent;
            count++;
        }
        i++;
    }
     //Print 
     cout<<"Output\n";
    for(int i=0;i<n-1;i++) {
        if(output[i].start < output[i].destination) {
            cout<<output[i].start<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        } else {
            cout<<output[i].destination<<" "<<output[i].start<<" "<<output[i].weight<<endl;
        }
    }
    
    
}
int main()
{
    int v,e;
    cout<<"Enter number of vertices and edges\n";
    cin>>v>>e;
    
    int si,di,w;
    Edges* input= new Edges[e];
    for(int i=0;i<e;i++) {
        cin>>si>>di>>w;
        input[i].start=si;
        input[i].destination=di;
        input[i].weight=w;
    }
    Krushkal(input,v,e);
    return 0;
}
