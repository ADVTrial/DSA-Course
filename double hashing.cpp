/*
Write a program to implement hashing by double hashing and search for an element in it.

Hint :

Hash Function1 =key%TABLE_SIZE;

Hash Fucntion 2 = 7-(key %7);

Note: Consider the table size as 10.

 Input Format 
The first line of the input consists of the value of n.

The next n inputs are the elements.

The last input is the element to be searched.

 Output Format 
The first line of the output prints the result of the search.

The output prints the hash table.

Refer to the sample input and output for formatting specifications.

 Sample Input 
3
12 22 32
22
Sample Output
value is found at index 8
Element at position 0: 0
Element at position 1: 0
Element at position 2: 12
Element at position 3: 0
Element at position 4: 0
Element at position 5: 32
Element at position 6: 0
Element at position 7: 0
Element at position 8: 22
Element at position 9: 0

 Sample Input   
5
12 98 45 36 77
88
Sample Output
value is not found
Element at position 0: 0
Element at position 1: 0
Element at position 2: 12
Element at position 3: 0
Element at position 4: 0
Element at position 5: 45
Element at position 6: 36
Element at position 7: 77
Element at position 8: 98
Element at position 9: 0
*/
/*Double Hashing*/
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

int hashFunction1(int key) {
    return key % TABLE_SIZE;
}

int hashFunction2(int key) {
    return 7 - (key % 7);
}

void insertIntoHashTable(int table[], int key) {
    int index = hashFunction1(key);
    if (table[index] == 0) {
        table[index] = key;
    } else {
        int index2 = hashFunction2(key);
        int i = 1;
        while (true) {
            int newIndex = (index + i * index2) % TABLE_SIZE;
            if (table[newIndex] == 0) {
                table[newIndex] = key;
                break;
            }
            i++;
        }
    }
}

bool searchInHashTable(int table[], int key) {
    int index = hashFunction1(key);
    if (table[index] == key) {
        cout << "value is found at index " << index << endl;
        return true;
    } else {
        int index2 = hashFunction2(key);
        int i = 1;
        while (true) {
            int newIndex = (index + i * index2) % TABLE_SIZE;
            if (table[newIndex] == key) {
                cout << "value is found at index " << newIndex << endl;
                return true;
            }
            if (table[newIndex] == 0 || i == TABLE_SIZE) {
                break;
            }
            i++;
        }
    }
    cout << "value is not found" << endl;
    return false;
}

void displayHashTable(int table[]) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "Element at position " << i << ": " << table[i] << endl;
    }
}

int main() {
    int n, searchKey;
    cin >> n;
    int table[TABLE_SIZE] = {0};

    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;
        insertIntoHashTable(table, key);
    }

    cin >> searchKey;
    searchInHashTable(table, searchKey);
    displayHashTable(table);

    return 0;
}
