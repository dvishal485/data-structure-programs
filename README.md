# Data Structures

**Table of Contents**
- [Data Structures](#data-structures)
  - [Data Structure Implementations in C](#data-structure-implementations-in-c)
  - [Miscellaneous Programs](#miscellaneous-programs)
  - [DTU DS (CO201) Programs and File](#dtu-ds-co201-programs-and-file)
    - [Lab File](#lab-file)
    - [Programs included in the file](#programs-included-in-the-file)
    - [Assignment Questions](#assignment-questions)

---

## Data Structure Implementations in C

1. [Stack](./programs/stack_impl.c)

    | Function      | Return Type   | Parameters           |
    | :------------ | :------------ | :------------------- |
    | `createStack` | `stack*`      | `int capacity`       |
    | `readStack`   | `void`        | `stack* s`           |
    | `pop`         | `void`        | `stack* s`           |
    | `push`        | `void`        | `stack* s, int data` |
    | `top`         | `int`         | `stack* s`           |
    | `isFull`      | `char` (bool) | `stack* s`           |
    | `isEmpty`     | `char` (bool) | `stack* s`           |
    | `size`        | `int`         | `stack* s`           |

1. [Queue](./programs/queue_impl.c)

    | Function       | Return Type   | Parameters            |
    | :------------- | :------------ | :-------------------- |
    | `createQ`      | `queue*`      | `int capacity`        |
    | `showQ`        | `void`        | `queue* q`            |
    | `dequeue`      | `void`        | `queue* q`            |
    | `enqueue`      | `void`        | `queue* q, int value` |
    | `peek`         | `int`         | `queue* q`            |
    | `isQueueFull`  | `char` (bool) | `queue* q`            |
    | `isQueueEmpty` | `char` (bool) | `queue* q`            |

1. [Circular Queue](./programs/circularQ_impl.c)

    | Function   | Return Type   | Parameters                |
    | :--------- | :------------ | :------------------------ |
    | `createQ`  | `circularQ*`  | `int capacity`            |
    | `showQ`    | `void`        | `circularQ* q`            |
    | `dequeue`  | `void`        | `circularQ* q`            |
    | `enqueue`  | `void`        | `circularQ* q, int value` |
    | `peek`     | `int`         | `circularQ* q`            |
    | `isQFull`  | `char` (bool) | `circularQ* q`            |
    | `isQEmpty` | `char` (bool) | `circularQ* q`            |
    | `qSize`    | `int`         | `circularQ* q`            |

1. [Deque](./programs/deque_impl.c)

    | Function      | Return Type   | Parameters            |
    | :------------ | :------------ | :-------------------- |
    | `createDeque` | `deque*`      | `int capacity`        |
    | `showFullQ`   | `void`        | `deque* q`            |
    | `pop_back`    | `void`        | `deque* q`            |
    | `pop_front`   | `void`        | `deque* q`            |
    | `push_back`   | `void`        | `deque* q, int value` |
    | `push_front`  | `void`        | `deque* q, int value` |
    | `peek_back`   | `int`         | `deque* q`            |
    | `peek_front`  | `int`         | `deque* q`            |
    | `isQFull`     | `char` (bool) | `deque* q`            |
    | `isQEmpty`    | `char` (bool) | `deque* q`            |

1. [Linked List](./programs/ll_impl.c)

    | Function          | Return Type   | Parameters                                 |
    | :---------------- | :------------ | :----------------------------------------- |
    | `createNode`      | `node*`       | `int value`                                |
    | `insertAtEnd`     | `node*`       | `node **pointer_to_head, int value`        |
    | `insertAtStart`   | `node*`       | `node **pointer_to_head, int value`        |
    | `insertFromStart` | `node*`       | `node **pointer_to_head, int n, int value` |
    | `deleteNode`      | `char` (bool) | `node *prev_node`                          |
    | `deleteFromStart` | `node*`       | `node **pointer_to_head, int n`            |
    | `deleteAtStart`   | `node*`       | `node **pointer_to_head`                   |
    | `deleteFromEnd`   | `node*`       | `node **pointer_to_head, int n`            |
    | `printLL`         | `node*`       | `node *head`                               |
    | `arrayToLL`       | `node*`       | `int arr[], int size`                      |

1. [Binary Tree](./programs/bt_impl.c)

    | Function            | Return Type   | Parameters                               |
    | :------------------ | :------------ | :--------------------------------------- |
    | `createBtNode`      | `btNode*`     | `int value`                              |
    | `inOrderTraversal`  | `void`        | `btNode *root`                           |
    | `preOrderTraversal` | `void`        | `btNode *root`                           |
    | `btCountNodes`      | `void`        | `btNode *root, int *internal, int *leaf` |
    | `btHeight`          | `int`         | `btNode *root`                           |
    | `flattenToLL`       | `int`         | `btNode *root, node **flatten`           |
    | `areEquivalentBT`   | `char` (bool) | `btNode *t1, btNode *t2`                 |

    [For `flattenToLL`, refer here](./programs/misc/bt_to_ll.c) 

---

## Miscellaneous Programs

1. [Write a program to implement insertion sort using linked list without destroying the original linked list.](./programs/misc/insertion_sort_ll.c)
1. [Write a program to merge two linked list sorted in ascending order into one sorted linked list, and return it's head.](./programs/misc/merge_two_sorted.c)
1. [Write a program to flatten a Binary Tree into a Linked List in order.](./programs/misc/bt_to_ll.c)
1. [Write a program to check if given Binary Tree is a Binary Search Tree or not.](./programs/misc/checkBST.c)
1. [Write a function which takes input a binary search tree T1 and returns a duplicate tree T2.](./programs/misc/copy_bt.c)
1. [Write a program to remove all characters other than alphabets from string with fixed amount of additional storage area.](./programs/misc/remove_char.c)
1. [Write an program to concatenate two doubly circular linked lists l1 and l2.](./programs/misc/concat_circularLL.c)
1. [Write a program to construct Binary Tree from Preorder and Inorder Traversal.](./programs/misc/generateBT.c)
1. [Write a program to generate a mirror image of given binary tree.](./programs/misc/mirror_bt.c)

---

## DTU DS (CO201) Programs and File

Delhi Technological University Lab Programs & Assignment Programs for Data Structures (Second Year) for the course CO201 submitted by Vishal Das

### Lab File

Lab File submitted by Vishal Das, for Data Structures (Second Year) for the course CO201
- [Document Format](./ds_lab_file.docx)
- [PDF Format](./ds_lab_file.pdf)

### Programs included in the file

1. Write a program to Implement Linear Search.
    - [Implementation in C](./programs/program_01.c)
    - [Implementation in C++](./programs/program_01.cpp)
    - [Implementation in Rust](./programs/program_01.rs)
1. Write a program to Implement Binary Search.
    - [Implementation in C](./programs/program_02.c)
    - [Implementation in C++](./programs/program_02.cpp)
    - [Implementation in Rust](./programs/program_02.rs)
1. Write a program to insert an element at the mid-position in the One-dimensional array.
    - [Implementation in C](./programs/program_03.c)
    - [Implementation in C++](./programs/program_03.cpp)
    - [Implementation in Rust](./programs/program_03.rs)
1. Write a program to delete a given row in the two-dimensional array.
    - [Implementation in C](./programs/program_04.c)
    - [Implementation in C++](./programs/program_04.cpp)
1. Write a program to implement a stack data structure and perform its operations.
    - [Implementation in C](./programs/program_05.c)
    - [Implementation in C++](./programs/program_05.cpp)
    - [Implementation in Rust](./programs/program_05.rs)
1. Write a program to implement two stacks using a single array.
    - [Implementation in C](./programs/program_06.c)
    - [Implementation in C++](./programs/program_06.cpp)
1. Write a program to find the minimum element of the stack in constant time with using extra space.
    - [Implementation in C](./programs/program_07.c)
    - [Implementation in C++](./programs/program_07.cpp)
1. Write a  program to find the minimum element of the stack in constant time without using extra space.
    - [Implementation in C](./programs/program_08.c)
    - [Implementation in C++](./programs/program_08.cpp)
1. Write a program to create a sparse matrix using arrays.
    - [Implementation in C](./programs/program_09.c)
    - [Different approach in C](./programs/sparse_matrix.c)
    - [Different approach in C++](./programs/sparse_matrix.cpp)
1. Write a program to perform the addition, multiplication and transpose operations on sparse matrix given in compact form.
    - [Implementation in C](./programs/program_10.c)
1. Write a program to implement Queue Data structure.
    - [Implementation in C](./programs/program_11.c)
1. Write a  program to reverse the first k elements of a given Queue.
    - [Implementation in C](./programs/program_12.c)
1. Write a program to check whether the given string is Palindrome or not using Double Ended Queue (DEQUE).
    - [Implementation in C](./programs/program_13.c)
1. Write a program to implement Tower of Hanoi Problem using Stack.
    - [Implementation in C](./programs/program_14.c)
1. Write a program to implement the Linked List Data structure and insert a new node at the beginning, and at a given position.
    - [Implementation in C](./programs/program_15.c)
1. Write a program to split a given linked list into two sub-list as Front sub-list and Back sub-list, if odd number of the element then add the last element into the front list.
    - [Implementation in C](./programs/program_16.c)
1. Given a Sorted doubly linked list of positive integers and an integer, finds all the pairs (sum of two nodes data part) that is equal to the given integer value.
    - [Implementation in C](./programs/program_17.c)
1. Write a program to implement Stack Data Structure using Queue.
    - [Implementation in C](./programs/program_18.c)
1. Write a program to implement Queue Data Structure using Stack.
    - [Implementation in C](./programs/program_19.c)
1. Write a program to implement the Binary Tree using linked list and perform In-order traversal.
    - [Implementation in C](./programs/program_20.c)
1. Write a program to check whether the given tree is a Binary Search Tree or not.
    - [Implementation in C](./programs/program_21.c)
1. [AVL Tree Implementation in C](./programs/program_22-24.c)
    1. Write a program to implement insertion in the AVL tree.  
    1. Write a program to Delete a key from the AVL tree.
    2. Write a program to count the number of leaf nodes in an AVL tree.

---

### Assignment Questions

1. [Given the head of a linked list and an integer n, write a program to delete nth
node from the end of linked list and return the head of new list.](./programs/assignments/assignment_01.c)
1. [We have discussed the problem of implementing Queue using two stacks using an
approach where the enqueue operation is constant time while dequeue operation
takes O(n) time. Think about a different approach of implementing queue using
two stacks where enqueue operation may be costly but the dequeue operation
remains O(1). Write the enqueue and dequeue operations code for this new
approach.](./programs/assignments/assignment_02.c)
1. [Given a linked list, write a program to swap every two adjacent nodes and return
its head. You must solve the problem without modifying the values in the linked
list nodes. For a linked list with odd number of nodes, last node should not be
swapped.](./programs/assignments/assignment_03.c)
1. [Write a program to check if one tree appears in another tree.](./programs/assignments/assignment_04.c)
1. [Write a program to construct binary search tree on given pre-order traversal of the tree
and print the nodes level wise top to down and left to right.](./programs/assignments/assignment_05.cpp)
1. [Write a program to Implement Heap Sort.](./programs/assignments/assignment_06.c)

---
