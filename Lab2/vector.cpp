
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief prints elements in the vector and their memory locations
 *
 * @param v - vector of integers (read-only)
 */
void printMemVec(const vector<int>& v){
    cout << "Vector — Each int is worth " << sizeof(int) << " bytes\n";
    for (size_t i = 0; i < v.size(); ++i){
        cout << "Value: " << v[i]
             << " at Memory Location: " << &v[i]
             << endl;
    }
}

/**
 * @brief increments each element in the vector by 10
 *
 * @param v - vector of integers (passed by reference; we mutate it)
 */
void incVecBy10(vector<int>& v){
    for (size_t i = 0; i < v.size(); ++i){
        v[i] += 10;
    }
}

int main() {
    // create a constant integer called SIZE that is of value 5
    const int SIZE = 5;

    // create a vector of integers called vec that can hold up to 5 elements
    vector<int> vec;
    vec.reserve(SIZE);

    // use a for loop to populate vec with the values 100 to 104
    for (int i = 0; i < SIZE; ++i){
        vec.push_back(100 + i);
    }

    cout << "Before Increment------------\n";
    printMemVec(vec);

    // call incVecBy10(...) on vec
    incVecBy10(vec);

    cout << "After Increment-------------\n";
    printMemVec(vec);

    // remove last element of vec
    vec.pop_back();

    cout << "After Pop-------------------\n";
    printMemVec(vec);

    // append 101 and 102 at the end of vec
    vec.push_back(101);
    vec.push_back(102);

    cout << "After Push------------------\n";
    printMemVec(vec);

    return 0;
}
