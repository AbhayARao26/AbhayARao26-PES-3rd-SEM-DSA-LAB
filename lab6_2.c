/*
 Binary Search Tree (BST)
 
 You are given a sequence of numbers representing a BST in level order traversal with -1 indicating the absence of a node. You need to construct the BST from this input. Once the BST is constructed, you will receive a series of queries, each of which is either a search operation or a delete operation. You need to perform the corresponding operation and return the result.

 Input Format:
    The first line contains an integer, n, representing the number of elements in the level order traversal (1 ≤ n ≤ 1000).
    The second line contains n space-separated integers, representing the level order traversal of the BST. The values are in the range [-10^9, 10^9], and -1 indicates an empty node.
    The third line contains an integer, q (1 ≤ q ≤ 1000), representing the number of queries to be performed.
    The next q lines contain queries in the following format:

 ‘0 x’: A search operation. You need to determine if the value ‘x’ is present in the BST and print "YES" if it is, "NO" otherwise. ‘1 x’: A delete operation. You need to delete the node with the value ‘x’ from the BST.

 Constraints

 None

 Output Format

 For each search query, print "YES" if the element is found in the BST, "NO" if it's not.

 Sample Input 0

 10
 4 2 6 1 3 5 7 -1 -1 -1
 5
 0 3
 0 8
 1 4
 0 4
 0 2
 Sample Output 0

 YES
 NO
 NO
 YES
*/
