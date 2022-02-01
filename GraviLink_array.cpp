// GraviLink_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Task:
Write a function that takes an array of strings as input, and
returns the same array, but without those strings that are in the original array
there was an even number.
The solution must be optimized for speed. You can write to
any of the popular high-level programming languages ​​(selected
language must be specified).
*/

#include <iostream>
#include <unordered_map>
using namespace std;
/*
               | map                   | unordered_map
-------------------------------------------------------- -
Ordering       | increasing  order     | no ordering
               | (by default)          |

Implementation | Self balancing BST    | Hash Table
               | like Red - Black Tree |

search time    | log(n)                | O(1)->Average
               |                       | O(n)->Worst Case

Insertion time | log(n) + Rebalance    | Same as search

Deletion time  | log(n) + Rebalance    | Same as search

=> Assess the algorithmic complexity of following implementation is ~O(n) in average
*/

unordered_map<string, int> getFrequencies(vector<string> array) {
    unordered_map<string, int> counter;

    for (auto value : array){
        if (counter.find(value) == counter.end()){
            counter[value] = 1; 
        }
        else{
            counter[value]++;
        }
    }

    return counter;
}


int main()
{
    vector<string> stringVector{ "Cat","Cat","Cat","Dog","Dog","Lizard" };

    unordered_map<string, int> counter = getFrequencies(stringVector);
     
    vector<string> result_array;

    for (auto const& value : counter)
    {
        if (value.second & 1 != 0) {
            for (int i = 0; i < value.second; i++) {
                result_array.push_back(value.first);
            }
        }
    }
    for (auto value : result_array)
        cout << value << ' ';
}
