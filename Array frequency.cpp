#include <iostream>
using namespace std;

const int MAX_SIZE = 10000; // Maximum size for the array, adjust according to the constraints if needed

int mostFrequent(int arr[], int size) {
    int freq[MAX_SIZE] = {0};

    int maxFreq = 0;
    int frequentElement = arr[0]; // Initialize with the first element

    for (int i = 0; i < size; ++i) {
        freq[arr[i]]++;

        if (freq[arr[i]] > maxFreq || (freq[arr[i]] == maxFreq && i < size - 1 && arr[i] != arr[i + 1])) {
            maxFreq = freq[arr[i]];
            frequentElement = arr[i];
        }
    }

    return frequentElement;
}

int main() {
    int n;
    cin >> n;

    int arr[MAX_SIZE];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = mostFrequent(arr, n);
    cout << result << endl;

    return 0;
}
