#include<iostream>
#include<cstdlib>
#include<chrono>
#define MAX 300000
using namespace std;

void display(int A[],int n){
    int i;
    for(i=0;i<n;i++){
        std::cout<<A[i]<<" ";
    }
    std::cout<<"\n";
}
int partition(int A[],int l, int r){
    int pivot = A[l];
    int x=l;
    int y = r;
    while(x<y){
        while(A[x]<=pivot && x<=r){
            x++;
        }
        while(A[y]>pivot){
            y--;
        }
        if (x<y){
            swap(A[x],A[y]);
        }
    }
    swap(A[l],A[y]);
    return y;
}
void quickSort(int A[],int l,int r)
{
    
    if (l<r){

        int p=partition(A,l,r);
        quickSort(A,l,p-1);
        quickSort(A,p+1,r);
    }
}

int main(){
    int i,n,A[MAX];
    int l=0;
    std::cout<<"Enter n:";
    std::cin>>n;
    int r=n-1;

    for(i=0;i<n;i++)
    {
        A[i]=rand()%100000;
    }

    //display(A,n);
    auto start= chrono::steady_clock::now();
    quickSort(A,l,r);
    auto end = chrono::steady_clock::now();
    //display(A,n);
    auto time_taken = chrono::duration_cast<chrono::nanoseconds>(end-start);
    cout<<"Time taken is : "<<time_taken.count()*1e-9<<"s \n"<<endl;
    return 0;
}