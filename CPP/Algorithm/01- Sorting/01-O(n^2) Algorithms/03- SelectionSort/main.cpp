#include <iostream>
#include <assert.h>
#include <fstream>
using namespace std;

/************* Selection Sort *******************/
/* Algorithm: Compare each element with the     */
/* whole array and swap when finding smaller    */
/* Complexity ==> O(n^2)                        */
/************************************************/

long long selectionSort(int arr[], int length)
{
    long long steps = 1;
    assert(arr != nullptr);
    steps += 2; /* assert + next compare */
    if (length < 2)
    {
        return steps;
    }
    steps += 2; /* init + compare */
    for (int i = 0; i < length - 1; i++)
    {
        steps += 2; /* init + compare */
        for (int j = i + 1; j < length; j++)
        {
            steps += 2; /* increment + compare */

            steps++; /* next compare */
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                steps += 3; /* swap */
            }
        }
        steps += 2; /* Terminating increment + compare */

        steps += 2; /* next loop increment + compare */
    }
    return steps;
}

int main()
{
    ofstream ofile("pairs.csv");
    for (int i = 10; i < 10000; i += 50)
    {
        int *arr = new int[i];
        for (int j = 0; j < i; j++)
        {
            arr[j] = rand() % i;
        }

        ofile << i << "," << selectionSort(arr, i) << "," << i * i << endl;
        delete[] arr;
    }
}