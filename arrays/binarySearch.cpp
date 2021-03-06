#include <iostream>
using namespace std;

int binary_search( int * arr, int start, int end, int key){

    int mid;

    if(start <= end && key >= arr [start] && key <= arr[end]) {

        mid = (start + end) /2;
        cout << mid << endl;

        if(arr[mid] == key){
            return mid;
        }

        if(arr[mid] < key){
            return binary_search(arr, mid + 1, end, key);
        }

        if(arr[mid] > key){
            return binary_search(arr, start, mid - 1, key);
        }
    }

    return -1;
}

// => time complexity of O(log2 N)
int binary_search_second( int * arr, int n, int key){

    int start = 0;
    int end = n-1;
    int mid;

    while(start <= end) {
        mid = (start + end) /2;

        // cout << mid << endl;
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] > key){
            end = mid - 1;
        } else {
            start = mid + 1 ;
        }
    }

    return -1;
}

int main () {

    int arr[] = {2,34,35,45};

    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "enter any number to find in array." << endl;
    cin>> key;

    int index = binary_search(arr, 0, n-1, key);
    if(index !=-1){
        cout << key << " is found at index " << index << endl;
    }else{
        cout << "Element not found" <<endl;
    }

        

    return 0;
}