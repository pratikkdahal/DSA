#include<iostream>
#include<cstdlib>
#include<chrono>
#define MAX 300000
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

void insertionSort(int A[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        j=i-1;
        temp=A[i];
        while(j>=0 and temp<A[j]){
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=temp;
    }
}

int main(){
    int i,n,A[MAX];
    std::cout<<"Enter n:";
    std::cin>>n;
    for(i=0;i<n;i++)
    {
        A[i]=rand()%100000;
    }

    display(A,n);
    auto start= std::chrono::steady_clock::now();
    insertionSort(A,n);
    auto end = std::chrono::steady_clock::now();
    display(A,n);
    auto time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
    std::cout<<"Time taken is : "<<time_taken.count()*1e-9<<"s \n"<<std::endl;
    return 0;
}