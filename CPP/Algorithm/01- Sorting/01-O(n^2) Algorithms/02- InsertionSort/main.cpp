#include <iostream>
#include <assert.h>
#include <fstream>
using namespace std;

/************* Insertion Sort *******************/
/* Algorithm: Compare each element the previous */
/* and shift until finding bigger               */
/* Complexity ==> O(n^2)                        */
/************************************************/

int insertSort(int arr[], int length)
{
    int steps = 1;
    assert(arr != nullptr);
    steps += 2; /* assert + next compare */
    if (length < 2)
    {
        return steps;
    }
    steps += 2; /* init + compare */
    for (int i = 1; i < length; i++)
    {
        bool changing = false;
        steps += 2;           /* compare + increment */
        int currVal = arr[i]; /* Save the current value */
        int j = i - 1;        /* Assign index to the previous value */
        steps += 2;           /* The previous assignments */

        while (currVal < arr[j] && j >= 0) /* cond 1: shifting till finding greater value
                                              cond 2: if the current value was in the correct place */
        {
            changing = true;
            /* Shifting */
            arr[j + 1] = arr[j];
            j--;
            steps += 3; /* The previous assignments */
            steps += 2; /* The next loop compare */
        }
        steps += 2; /* terminating compare */

        steps++;      /* next compare */
        if (changing) /* only if there is a change */
        {
            arr[j + 1] = currVal; /* put value in the correct place */
            steps++;              /* Previous assignment */
        }
    }
    steps += 2; /* The terminating increment and compare */
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

        ofile << i << "," << insertSort(arr, i) << "," << i * i << endl;
        delete[] arr;
    }
}