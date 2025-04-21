# Leetcode-1110.-Delete-Nodes-And-Return-Forest

This repository provides a solution to the problem of deleting specific nodes from a binary tree and returning the resulting forest (a list of disjoint trees).

🚩 Problem Statement
Given the root of a binary tree and a list of node values to delete, delete the nodes and return the forest (i.e., a list of remaining tree roots). After a node is deleted:

Its left and right children (if not deleted themselves) become new roots in the forest.

💡 Approach
The algorithm uses post-order traversal (DFS) to:

Recurse through the tree's left and right children.

At each node:

If it's marked for deletion:

Add its non-null children to the result list.

Remove the node by returning NULL.

Otherwise, return the current node as is.

If the root is not deleted, add it to the result forest at the end.

✨ Key Features
Efficient Set Lookup: Uses unordered_set for O(1) deletion checks.

Post-order DFS: Ensures children are processed before the parent.

Pointer Manipulation: Adjusts tree structure in-place.

🧠 Example
cpp
Input:
Tree = [1,2,3,4,5,6,7], to_delete = [3,5]

Output:
[[1,2,null,4], [6], [7]]

Explanation:
- Delete 3 → 6 and 7 become new roots
- Delete 5 → no children to add
⏱️ Time & Space Complexity
Time: O(N) — where N is the number of nodes

Space: O(N) — for the result vector and recursion stack


🧩 Applications
Forest-based partitioning of tree data

Selective pruning in tree data structures

Hierarchical decompositions
