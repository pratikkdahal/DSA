#include <iostream>
#include <cstdlib>
#include <chrono>

#define MAX 300000
using namespace std;

// to prevent stack overflow
int bin[10][MAX];

void display(int A[], int n)
{
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int getMax(int A[], int n)
{
    int max = A[0];

    for(int i = 1; i < n; i++)
    {
        if(A[i] > max)
            max = A[i];
    }

    return max;
}

void radixSort(int A[], int n)
{
    int max = getMax(A, n);

    // Units, Tens, Hundreds, ...
    for(int exp = 1; max / exp > 0; exp *= 10)
    {
        int count[10] = {0};

        // Put elements into bins
        for(int i = 0; i < n; i++)
        {
            int digit = (A[i] / exp) % 10;
            bin[digit][count[digit]] = A[i];
            count[digit]++;
        }

        // Collect elements back
        int k = 0;

        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < count[i]; j++)
            {
                A[k++] = bin[i][j];
            }
        }
    }
}

int main()
{
    int n;
    int A[MAX];

    cout << "Enter n: ";
    cin >> n;

    for(int i = 0; i < n; i++)
        A[i] = rand() % 100000;

    // display(A, n);

    auto start = chrono::high_resolution_clock::now();

    radixSort(A, n);

    auto end = chrono::high_resolution_clock::now();

    // display(A, n);

    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "Time taken = " << duration.count() * 1e-9 << " seconds" << endl;

    return 0;
}