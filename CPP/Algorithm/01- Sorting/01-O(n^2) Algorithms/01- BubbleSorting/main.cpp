
#include <assert.h>
#include <fstream>
using namespace std;

/**************** Bubble Sort ****************/
/* Algorithm: Compare each element with      */
/* with the next one if and swap             */
/* Complexity ==> O(n^2)                     */
/*********************************************/

int BubbleSort(int arr[], int length)
{
    int steps = 1;
    assert(arr != nullptr);
    steps++; /* assert */
    if (length < 2)
    {
        return steps;
    }

    bool sorted = true;
    for (int i = 0; i < length - 1; i++)
    {
        steps += 2; /* compare + increment */
        for (int j = i + 1; j < length; j++)
        {
            steps += 2; /* compare + increment */
            if (arr[i] > arr[j])
            {
                steps += 1; /* Compare */
                sorted = false;

                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                steps += 4; /* sorted boolean + 3 for swap */
            }
            steps += 1; /* Last compare */
        }
        steps++; /* "sorted" compare */
        if (sorted)
        {
            steps++;
            break;
        }
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

        ofile << i << "," << BubbleSort(arr, i) << "," << i * i << endl;
        delete[] arr;
    }
}