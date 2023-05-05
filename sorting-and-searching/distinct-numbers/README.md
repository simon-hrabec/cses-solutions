# Distinct Numbers - solution

[Link to code - implementation (hasthtable)](https://github.com/simon-hrabec/cses-solutions/blob/master/sorting-and-searching/distinct-numbers/distinct-numbers-hashtable.cpp)

[Link to code - implementation (BST)](https://github.com/simon-hrabec/cses-solutions/blob/master/sorting-and-searching/distinct-numbers/distinct-numbers-bst.cpp)

[Link to code - implementation (sorting)](https://github.com/simon-hrabec/cses-solutions/blob/master/sorting-and-searching/distinct-numbers/distinct-numbers-sorting.cpp)

This problem can be solved using 3 ways:

## Hashtable
In order to have expected linear time complexity, we can use hashtable which is in C++ represented as `unordered_set<int>`. However, this code will TLE on the last test case. A possible solution is to set the size of the hashtable at the beginning using `nums.rehash(200'000);`. This makes it pass.

## BST
Another way is to use a binary search tree. This has `O(n*log n)` time complexity.  BST in C++ is represented as `set<int>`.

## Sorting
To get the number of unique elements, we first need to sort the array. Then, we can check how many disctinct values are there by checking if neighbouring elements differ. It is possible to use a manual loop or get the number by calling checking the distance between the start of the array and the iterator returned by calling `std::unique`.