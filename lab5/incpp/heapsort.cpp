#include<iostream>
#include<cstdlib>
#include<chrono>
#include<cmath>
#define MAX 500000
using namespace std;

void swapp(int *p,int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;                                                                                                                                                                                   
}

void display(int A[],int n){
    int i;
    for(i=0;i<n;i++){
        std::cout<<A[i]<<" ";
    }
    std::cout<<"\n";
}

void max_heapify(int A[],int i, int n){
    int L=2*i;
    int R=2*i+1;
    int largest = i;
    if(L<=n && A[L]>A[largest]){
        largest = L;
    }
    if(R<=n && A[R]>A[largest]){
        largest = R;
    }
    if(i!=largest){
        swapp(&A[i],&A[largest]);
        max_heapify(A,largest,n);
    }
}

void build_max_heap(int A[],int n){
    int i;
    for(i=floor(n/2);i>=1;i--){
        max_heapify(A,i,n);
    }
}

void heap_sort(int A[],int n){
    build_max_heap(A,n);
    int i;
    for(i=n;i>=2;i--){
        swapp(&A[1],&A[i]);
        max_heapify(A,1,i-1);
    }
}

int main()
{
    int n;
    int A[MAX+1];

    cout<<"Enter n: ";
    cin>>n;

    for(int i=1;i<=n;i++)
        A[i]=rand()%100000;

    // display(A,n);

    auto start=chrono::steady_clock::now();

    heap_sort(A,n);

    auto end=chrono::steady_clock::now();

    // display(A,n);

    auto time_taken=chrono::duration_cast<chrono::nanoseconds>(end-start);

    cout<<"Time taken = "<<time_taken.count()*1e-9<<" s"<<endl;
}