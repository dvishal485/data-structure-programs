# Data Structures and Algorithms

**Table of Contents**
- [Data Structures and Algorithms](#data-structures-and-algorithms)
  - [Data Structure Implementations in C](#data-structure-implementations-in-c)
  - [Miscellaneous Programs](#miscellaneous-programs)
  - [DTU DS (CO201) Programs](#dtu-ds-co201-programs)
    - [Programs included in the file](#programs-included-in-the-file)
    - [Assignment Questions](#assignment-questions)

---

## Data Structure Implementations in C

1. [Stack](./programs/stack_impl.c)

    | Function      | Return Type | Parameters           |
    | :------------ | :---------- | :------------------- |
    | `createStack` | `stack*`    | `int capacity`       |
    | `readStack`   | `void`      | `stack* s`           |
    | `pop`         | `void`      | `stack* s`           |
    | `push`        | `void`      | `stack* s, int data` |
    | `top`         | `int`       | `stack* s`           |
    | `isFull`      | `char`      | `stack* s`           |
    | `isEmpty`     | `char`      | `stack* s`           |

1. [Queue](./programs/queue_impl.c)

    | Function       | Return Type | Parameters            |
    | :------------- | :---------- | :-------------------- |
    | `createQ`      | `queue*`    | `int capacity`        |
    | `showQ`        | `void`      | `queue* q`            |
    | `dequeue`      | `void`      | `queue* q`            |
    | `enqueue`      | `void`      | `queue* q, int value` |
    | `peek`         | `int`       | `queue* q`            |
    | `isQueueFull`  | `char`      | `queue* q`            |
    | `isQueueEmpty` | `char`      | `queue* q`            |

1. [Circular Queue](./programs/circularQ_impl.c)

    | Function   | Return Type  | Parameters                |
    | :--------- | :----------- | :------------------------ |
    | `createQ`  | `circularQ*` | `int capacity`            |
    | `showQ`    | `void`       | `circularQ* q`            |
    | `dequeue`  | `void`       | `circularQ* q`            |
    | `enqueue`  | `void`       | `circularQ* q, int value` |
    | `peek`     | `int`        | `circularQ* q`            |
    | `isQFull`  | `char`       | `circularQ* q`            |
    | `isQEmpty` | `char`       | `circularQ* q`            |

1. [Deque](./programs/deque_impl.c)

    | Function      | Return Type | Parameters            |
    | :------------ | :---------- | :-------------------- |
    | `createDeque` | `deque*`    | `int capacity`        |
    | `showFullQ`   | `void`      | `deque* q`            |
    | `pop_back`    | `void`      | `deque* q`            |
    | `pop_front`   | `void`      | `deque* q`            |
    | `push_back`   | `void`      | `deque* q, int value` |
    | `push_front`  | `void`      | `deque* q, int value` |
    | `peek_back`   | `int`       | `deque* q`            |
    | `peek_front`  | `int`       | `deque* q`            |
    | `isQFull`     | `char`      | `deque* q`            |
    | `isQEmpty`    | `char`      | `deque* q`            |

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

    | Function           | Return Type | Parameters                               |
    | :----------------- | :---------- | :--------------------------------------- |
    | `createBtNode`     | `btNode*`   | `int value`                              |
    | `inOrderTraversal` | `void`      | `btNode *root`                           |
    | `btCountNodes`     | `void`      | `btNode *root, int *internal, int *leaf` |
    | `btHeight`         | `int`       | `btNode *root`                           |
    | `flattenToLL`      | `int`       | `btNode *root, node **flatten`           |
    | `areEquivalentBT`  | `char`      | `btNode *t1, btNode *t2`                 |

    [For `flattenToLL`, refer here](./programs/bt_to_ll.c) 

---

## Miscellaneous Programs

1. [Write a program to implement insertion sort using linked list without destroying the original linked list.](./programs/insertion_sort_ll.c)
1. [Write a program to merge two linked list sorted in ascending order into one sorted linked list, and return it's head.](./programs/merge_two_sorted.c)
1. [Write a program to flatten a Binary Tree into a Linked List in order.](./programs/bt_to_ll.c)
1. [Write a program to check if given Binary Tree is a Binary Search Tree or not.](./programs/checkBST.c)
1. [Write a function which takes input a binary search tree T1 and returns a duplicate tree T2.](./programs/copy_bt.c)

---

## DTU DS (CO201) Programs

Delhi Technological University Lab Programs & Assignment Programs for Data Structures (Second Year) for the course CO201 submitted by Vishal Das

### Programs included in the file

1. Write a C/C++ program to Implement Linear Search.
    - [Implementation in C](./programs/program_01.c)
    - [Implementation in C++](./programs/program_01.cpp)
1. Write a C/C++ program to Implement Binary Search.
    - [Implementation in C](./programs/program_02.c)
    - [Implementation in C++](./programs/program_02.cpp)
1. Write a C/C++ program to insert an element at the mid-position in the One-dimensional array.
    - [Implementation in C](./programs/program_03.c)
    - [Implementation in C++](./programs/program_03.cpp)
1. Write a C/C++ program to delete a given row in the two-dimensional array.
    - [Implementation in C](./programs/program_04.c)
    - [Implementation in C++](./programs/program_04.cpp)
1. Write a C/C++ program to implement a stack data structure and perform its operations.
    - [Implementation in C](./programs/program_05.c)
    - [Implementation in C++](./programs/program_05.cpp)
1. Write a C/C++ program to implement two stacks using a single array.
    - [Implementation in C](./programs/program_06.c)
    - [Implementation in C++](./programs/program_06.cpp)
1. Write a C/C++ program to find the minimum element of the stack in constant time with using extra space.
    - [Implementation in C](./programs/program_07.c)
    - [Implementation in C++](./programs/program_07.cpp)
1. Write a C/C++  program to find the minimum element of the stack in constant time without using extra space.
    - [Implementation in C](./programs/program_08.c)
    - [Implementation in C++](./programs/program_08.cpp)
1. Write a C/C++ program to create a sparse matrix using arrays.
    - [Implementation in C](./programs/program_09.c)
    - [Different approach in C](./programs/sparse_matrix.c)
    - [Different approach in C++](./programs/sparse_matrix.cpp)
1. Write a C/C++ program to perform the addition, multiplication and transpose operations on sparse matrix given in compact form.
    - [Implementation in C](./programs/program_10.c)
1. Write a C/C++ program to implement Queue Data structure.
    - [Implementation in C](./programs/program_11.c)
1. Write a  C/C++ program to reverse the first k elements of a given Queue.
    - [Implementation in C](./programs/program_12.c)
1. Write a C/C++ program to check whether the given string is Palindrome or not using Double Ended Queue (DEQUE).
    - [Implementation in C](./programs/program_13.c)
1. Write a C/C++ program to implement Tower of Hanoi Problem using Stack.
1. Write a C/C++ program to implement the Linked List Data structure and insert a new node at the beginning, and at a given position.
    - [Implementation in C](./programs/program_15.c)
1. Write a C/C++ program to split a given linked list into two sub-list as Front sub-list and Back sub-list, if odd number of the element then add the last element into the front list.
    - [Implementation in C](./programs/program_16.c)
1. Given a Sorted doubly linked list of positive integers and an integer, finds all the pairs (sum of two nodes data part) that is equal to the given integer value.
    - [Implementation in C](./programs/program_17.c)

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

---
