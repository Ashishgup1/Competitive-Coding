
// C++ program to sort an array of positive 
// and negative numbers using bucket sort 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to sort arr[] of size n using 
// bucket sort 
void bucketSort(vector<float> &arr, int n) 
{ 
    // 1) Create n empty buckets 
    vector<float> b[n]; 
  
    // 2) Put array elements in different 
    //    buckets 
    for (int i=0; i<n; i++) 
    { 
        int bi = n*arr[i]; // Index in bucket 
        b[bi].push_back(arr[i]); 
    } 
  
    // 3) Sort individual buckets 
    for (int i=0; i<n; i++) 
        sort(b[i].begin(), b[i].end()); 
  
    // 4) Concatenate all buckets into arr[] 
    int index = 0; 
    arr.clear(); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
            arr.push_back(b[i][j]); 
} 
  
// This function mainly slpits array into two 
// and then calls bucketSort() for two arrays. 
void sortMixed(float arr[], int n) 
{ 
    vector<float>Neg ; 
    vector<float>Pos; 
  
    // traverse array elements 
    for (int i=0; i<n; i++) 
    { 
        if (arr[i] < 0) 
  
            // store -Ve elements by 
            // converting into +ve element 
            Neg.push_back (-1 * arr[i]) ; 
        else
            // store +ve elements 
            Pos.push_back (arr[i]) ; 
    } 
  
    bucketSort(Neg, (int)Neg.size()); 
    bucketSort(Pos, (int)Pos.size()); 
  
    // First store elements of Neg[] array 
    // by converting into -ve 
    for (int i=0; i < Neg.size(); i++) 
        arr[i] = -1 * Neg[ Neg.size() -1 - i]; 
  
    // store +ve element 
    for(int j=Neg.size(); j < n; j++) 
        arr[j] = Pos[j - Neg.size()]; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    float arr[] = {-0.897, 0.565, 0.656, 
                   -0.1234, 0, 0.3434}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    sortMixed(arr, n); 
  
    cout << "Sorted array is \n"; 
    for (int i=0; i<n; i++) 
        cout << arr[i] << " "; 
    return 0; 
} 
