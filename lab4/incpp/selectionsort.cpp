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

void selectionSort(int A[],int n)
{
    int i,j,POS,least;
    for(i=0;i<n-1;i++)
    {
        least = A[i];
        POS = i;
        for(j=i+1;j<n;j++)
        {
            if (A[j]<least){
                least= A[j];
                POS=j;
            }
        }
        if( i!= POS){
            swapp(&A[i],&A[POS]);
        }
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
    selectionSort(A,n);
    auto end = std::chrono::steady_clock::now();
    display(A,n);
    auto time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
    std::cout<<"Time taken is : "<<time_taken.count()*1e-9<<"s \n"<<std::endl;
    return 0;
}