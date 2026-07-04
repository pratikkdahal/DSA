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
void merge(int A[],int l,int m,int r){
    int B[r];
    int i=l;
    int j=m;
    int k=l;
    while(i<m && j<=r){
        if(A[i]<=A[j]){
            B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }
    for(; i<m ; i++,k++){
        B[k]=A[i];
    }
    for(; j<=r ;j++,k++){
        B[k]=A[j];
    }
    for(k=l;k<=r;k++){
        A[k]=B[k];
    }

}
void mergeSort(int A[],int l,int r)
{
    
    if (l<r){
        int m;
        m=(l+r)/2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,r);
        merge(A,l,m+1,r);
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

    display(A,n);
    auto start= chrono::steady_clock::now();
    mergeSort(A,l,r);
    auto end = chrono::steady_clock::now();
    display(A,n);
    auto time_taken = chrono::duration_cast<chrono::nanoseconds>(end-start);
    cout<<"Time taken is : "<<time_taken.count()*1e-9<<"s \n"<<endl;
    return 0;
}