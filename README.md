# Binary-Search-Tree
This project was carried out as part of the undergraduate course “Computers II (Υπολογιστές ΙΙ)” of the 4th year of my undergraduate studies in the Department of Physics In UoA. The main aim of this project is the creation of a Binary Search Tree in C Programming Language.  Binary Search Tree (BST) is a type of binary tree(a hierarchical data structure where each node has at most two children, referred to as the left child and the right child) data structure composed of nodes in which each node contains a unique key, each having up to two children, forming a tree-like hierarchy with a single root node at the top. For each node the corresponding nodes in its left subtree contain values strictly less than its value and all the corresponding modes in its right subtree contain values strictly larger than its value. 

Some operations that are enabled by BST, especially when this is balanced (where the height difference between the left and right subtrees of every node is at most 1), are Insertion, Searching and Deletion. These operations if BST is balanced performed in O(log n) time. In the worst-case (unbalanced), these degrade to O(n). 

Regarding the nodes, a root node is the first or topmost node of a tree and has never previously been connected to another node in a tree. In every tree, there is always one root node. The node which is a predecessor of another node is known as a parent node. The node which is the descendant(node which follows another node) of any node on a tree is known as a child node. A leaf node is a node that does not have any child node. 

 


In this project the following operations are implemented:
  1)**Insertion**

      A new key is always inserted at the leaf by maintaining the property of the binary search tree. We start searching for a key from the root until we hit a leaf node. 
      Once a leaf node is found, the new node is added as a child of the leaf node. The below steps are followed while we try to insert a node into a binary search tree (**https://www.geeksforgeeks.org/dsa/insertion-in-binary-search-tree/**):
           Initilize the current node (say, currNode or node) with root node
           Compare the key with the current node.
           Move left if the key is less than or equal to the current node value.
           Move right if the key is greater than current node value.
           Repeat steps 2 and 3 until you reach a leaf node.
           Attach the new key as a left or right child based on the comparison with the leaf node's value.

  2)**Searching**

  3)**Deletion**

  4)**In-Order Traversal**

