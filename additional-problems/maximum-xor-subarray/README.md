## # Maximum Xor Subarray

[Link to code - implementation](https://github.com/simon-hrabec/cses-solutions/blob/master/additional-problems/maximum-xor-subarray/maximum-xor-subarray.cpp)

This problem is of a medium difficulty and can be solved rather easily when combining multiple techniques together.

## Input size and complexity
Size of the the array can be up to 200'000 (2\*10^5^), which signals that we cannot use approach with quadratic complexity (aka O(n^2^)), but rather we are expected to use either a linear or O(n\*log(n)) approach.

## High level approach
We want to consider all possible subarrays, but iterating manually over all the combination is not feasible. Hence, we need to construct some kind of datastructure, that will allow us to check multiple combination at the same time or pick the best one among a group.

## XOR prefixes
When it comex to XOR subarrays, we can always get any subarray XOR by combining two array prefixes. For example, having an array:
 `5 1 5 9 13 2 8`
The XOR of the subarray
`9 13`
Can be calculating as XOR of subarray `5 1 5 9 13` XOR the XOR of subarray `5 1 5`.

##  Iterating
We can iterate over the array and consider all potential candidates that are subarrays ending at that index. We take the XOR of the processed prefix and all we need to do is to find the best prefix (seen so far) to maximize the result. The question is what datastructure to use to allow for efficient queries.

## Trie
Trie is normally used for text processing, but in this scenario, we can use it to represent individual bits. As we process a XOR of a array prefix (subarray that starts at the beginning), we insert its binary representation into the trie.

## Quering
Now we have a XOR of the array prefix and we are trying to find a XOR of smaller prefix, that, when combined (XOR), will give the best number. We can just go bit by bit (trie node by trie node). Each trie node represents a subset of the seen XORs. We are trying to maximuze the XOR, hence if we have a chance, we want the resulting number to have 1 bits (at the leading places). Hence, when we have a trie node with both 1 and 0 child, we pick the opposite value from what our current XOR is. If the trie node has only 1 child, then we have to pick it.

## Solution complexity
By this, we achieve a linear memory/running time complexity.
