#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>


using namespace std;
using namespace std::chrono;

int binarySearch(vector<int> & arr, int x);
void funSort(vector<int> & arr);
void printArray(vector<int> & arr);

int main()
{
    
    int n;
    cin >> n;
    vector<int> arr; 
    
    while (n--)
    {
        int v;
        cin >> v;
        arr.push_back(v);
    }
    
    printArray(arr);
    //high_resolution_clock::time_point start = high_resolution_clock::now();
    funSort(arr);
    //high_resolution_clock::time_point finish = high_resolution_clock::now();
    
    //auto timeElapsed = duration_cast<nanoseconds>( finish - start ).count();
    
    printArray(arr);
    cout << endl;
    
    //cout << timeElapsed << endl;
    
    return 0;
}

int binarySearch(vector<int> & arr, int x)
{
    int l = 0;
    int r = arr.size();

    while (r > l)
    {
        int m = (l + r) / 2;
        if (x <= arr[m])
            r = m;
        else
            l = m + 1;
    }
    
    return r;
    /* We want to just return the index of "where we should have found it"
     * so that we can kind of... force it into its correct spot in funSort */ 
}


void funSort(vector<int> & arr)
{
    /* funSort is an invarent of insertion sort*/
    
    for (int i = 0; i < arr.size(); i++) 
    {
        int h = binarySearch(arr, arr[i]);
        cout << "i: " << i << " h: " << h << endl;
        while (arr[h] != arr[i])
        {
            if (i < h - 1)
                swap(arr[i], arr[h-1]);
            else if (h < i)
                swap(arr[h], arr[i]);

            cout << "i: " << i << endl;
            printArray(arr);
            h = binarySearch(arr, arr[i]);
            cout << " new h: " << h << endl;
        }
    }
}

void printArray(vector<int> & arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
