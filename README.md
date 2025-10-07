# Binary-Search-Tree
This project was carried out as part of the undergraduate course “Computers II (Υπολογιστές ΙΙ)” of the 4th year of my undergraduate studies in the Department of Physics In UoA. The main aim of this project is the creation of a Binary Search Tree in C Programming Language.  Binary Search Tree (BST) is a type of binary tree(a hierarchical data structure where each node has at most two children, referred to as the left child and the right child) data structure composed of nodes in which each node contains a unique key, each having up to two children, forming a tree-like hierarchy with a single root node at the top. For each node the corresponding nodes in its left subtree contain values strictly less than its value and all the corresponding modes in its right subtree contain values strictly larger than its value. 

Some operations that are enabled by BST, especially when this is balanced (where the height difference between the left and right subtrees of every node is at most 1), are Insertion, Searching and Deletion. These operations if BST is balanced performed in O(log n) time. In the worst-case (unbalanced), these degrade to O(n). 

Regarding the nodes, a root node is the first or topmost node of a tree and has never previously been connected to another node in a tree. In every tree, there is always one root node. The node which is a predecessor of another node is known as a parent node. The node which is the descendant(node which follows another node) of any node on a tree is known as a child node. A leaf node is a node that does not have any child node. 

 


In this project the following operations are implemented (**https://github.com/DimOriCoding/Binary-Search-Tree-/blob/main/Binary_Search_Tree.c**):
  
1)**Insertion** 
  
A new key is always inserted at the leaf by maintaining the property of the binary search tree. The searching for a key starts from the root until a leaf node is found. 
Once a leaf node is found, the new node is added as a child of the leaf node. The below steps are followed in order to insert a node into a binary search tree (**https://www.geeksforgeeks.org/dsa/insertion-in-binary-search-tree/**):
           Initilize the current node (say, currNode or node) with root node
           Compare the key with the current node.
           Move left if the key is less than or equal to the current node value.
           Move right if the key is greater than current node value.
           Repeat steps 2 and 3 until you reach a leaf node.
           Attach the new key as a left or right child based on the comparison with the leaf node's value.


2)**Searching**
  
The searching algorithm for a node with a value X consists of the following steps (**https://www.geeksforgeeks.org/dsa/binary-search-tree-set-1-search-and-insertion/**):
           Firstly if the value of the root node is NULL, the node is not existing
           The value to be searched is compared with the value of the root. If it's equal the node is found if it's smaller the search continue to the left subtree because 
           in a binary search tree all the elements in the left subtree are smaller and all the elements in the right subtree are larger. Repeat the above step till no more 
           traversal is possible.
           If at any iteration, key is found, return True. Else False.

  3)**Deletion**
  
  About Deletion operation there are 3 cases(**https://www.geeksforgeeks.org/dsa/deletion-in-binary-search-tree/**):

  
         1) Delete a leaf Node, where the node is simply removed from the tree. The parent node of the deleted node must have its corresponding child pointer set to NULL to reflect the change in the tree.
         2) Delete a node with one children, where its child is promoted to replace the deleted node. The parent node of the deleted node must have its corresponding child pointer updated to point to the promoted child.
         3) Delete a node with two children, where the replacement node can be found by either selecting the minimum value from the right subtree or the maximum value from the left subtree of the node to be deleted. After finding the replacement node, it can be promoted to replace the deleted node. The left subtree of the replacement node (if it exists) must be attached to the left child of the promoted node, and the right subtree of the replacement node (if it exists) must be attached to the right child of the promoted node. The parent node of the deleted node must have its corresponding child pointer updated to point to the promoted node.
  The deletion of a root node falls under one of the above cases, depending on whether the root node has children or not.



  4)**In-Order Traversal**
  This operation performs tree traversal with tree elements in ascending order. Firstly the traversal process is called recursively for the left subtree, then the root node is traversed and finally the traversal process is called recursively for the right subtree. 

