#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long binarySearch(vector<long long> & arr, long long x);
void funSort(vector<long long> & arr);
void printArray(vector<long long> & arr);

/** TESTS HERE *********/
void smallDistinct();   
void largeDistinct();
void smallRepeats();
/***********************/


int main()
{
    #ifdef DEBUG
    // run tests
    smallDistinct();
    largeDistinct();
    smallRepeats();
    #else 

    long long n;
    cin >> n;
    vector<long long> arr; 

    while (n--)
    {
        long long v;
        cin >> v;
        arr.push_back(v);
    }
    high_resolution_clock::time_point start = high_resolution_clock::now();
    funSort(arr);
    high_resolution_clock::time_point end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( end - start ).count();
    #endif

    // if time build print exec time
    #ifdef TIMED
    cout << duration << endl;
    #endif

    // if reg build print value
    #ifndef TIMED
    printArray(arr);
    #endif
    
    
    return 0;
}

long long binarySearch(vector<long long> & arr, long long x)
{
    long long l = 0;
    long long r = arr.size();

    while (r > l)
    {
        long long m = (l + r) / 2;
        if (x <= arr[m])
            r = m;
        else
            l = m + 1;
    }
    
    return r;
    /* We want to just return the index of "where we should have found it"
     * so that we can kind of... force it into its correct spot in funSort */ 
}


void funSort(vector<long long> & arr)
{
    /* funSort is an invarent of insertion sort*/
    
    for (long long i = 0; i < arr.size(); i++) 
    {
        long long h = binarySearch(arr, arr[i]);
        //cout << "i: " << i << " h: " << h << endl;
        while (arr[h] != arr[i])
        {
            if (i < h - 1)
                swap(arr[i], arr[h-1]);
            else if (h < i)
                swap(arr[h], arr[i]);

            //cout << "i: " << i << endl;
            //printArray(arr);
            h = binarySearch(arr, arr[i]);
            //cout << " new h: " << h << endl;
        }
    }
}

void printArray(vector<long long> & arr)
{
    for (long long i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void smallDistinct()
{
    vector<long long> arr = {1, 0, 2, 3};
    vector<long long> copy = arr;
    std::sort(copy.begin(), copy.end());
    funSort(arr);
    cout << "Testing case small distinct: ";
    if (arr == copy)
        cout << "pass" << endl;
    else
        cout << "FAIL" << endl;
    printArray(arr);
    cout << endl;
}

void largeDistinct()
{
    vector<long long> arr = {100000, 200000, 400000, -500000};
    vector<long long> copy = arr;
    std::sort(copy.begin(), copy.end());
    funSort(arr);
    cout << "Testing case large distinct: ";
    if (arr == copy)
        cout << "pass" << endl;
    else
        cout << "FAIL" << endl;
    printArray(arr);
    cout << endl;
}

void smallRepeats()
{
    vector<long long> arr = {2, 2, 3, 1};
    vector<long long> copy = arr;
    std::sort(copy.begin(), copy.end());
    funSort(arr);
    cout << "Testing case small repating: ";
    if (arr == copy)
        cout << "pass" << endl;
    else
        cout << "FAIL" << endl;
    printArray(arr);
    cout << endl;
}
