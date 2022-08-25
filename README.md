# data-structures-in-c

A1: Array ADT and its application

Design the algorithm and implement in C.
1. Create an ADT for an array data structure with the following functions:
a. insertAt(A[],size,pos,data)thatinsertsdataatpositionposinthearrayA[size]and
returns size of the array if successful or -1 if not successful.
b. search(A[ ], pos, key) that searches key in A[size] starting from pos and return the index
of key if found or 0 if not found
c. size(A[ ]) that returns the length of the array a
2. Store arrayADT operations in Array.h
3. Use Array.h and write an application (main.c) for the following:
a. CreateauserinterfacethatinsertsasetofintegersinarrayADT.Donottakesizeofthe
array as input.
b. Implement insertafterdata(a[ ], data1, data2) that inserts data2 after every occurrence
of data1 ina.
c. Writeafunction printArray(a[])thatprintstheintegers in awithitspositionhorizontally




A2: List ADT using pointers and its application

Design the algorithm and implement in C. 
1. Create anADTfor aList data structure using pointers, withthefollowing functions (List.h):
a. Create a linked list of names (Max. size of the string is 4)
b. Create the followingoperations
insertLast (linklist, item) to insert the item in the end
insertFirst (linklist, item) to insert the item in the front
deleteMiddle(linklist, item) to delete the first occurrence of the item
deleteFirst (linklist) to delete thefirst node and return the item
deleteLast (linklast) to delete the last node and return the item
insertMiddle(linklist, item1,item2) toinsertitem2afterthelastoccurrenceof

item1

search (linklist, item) to return TRUE/FALSE if found/not found
length (linklist) to return the length of the list
getData (linklist) to returnthename inthe node pointed by

linklist

2. Use List.h and write an application (a2List.c) for the following:
a. WriteanapplicationprograminCthatincludesoptions(12options)toreaditems of
lists, to test each of the list operations and the application operation.
b. Implementreverse(linklist)toreturnthereverseoftheitemsinthegivenlinklistwithout
creating a new linked list
c. ImplementcreateSorted(linklist,item)thatinsertsaniteminthelistsuchthatallthe
items in the list are in lexically ascending order
d. Write a function display(linklist) to display the items in the list
e. Write a function rotateLeft(linklist) that rotates the items to the left
f. Test your program with the test data given below and check your results with the


3. Define an ADT for Polynomial using linked list with the following operations (Poly.h):
a. InsertOrder(poly,coefft,expt) to insert the term with coefft and expt in the
right position so that all the terms in the
polynomialpolyareintheorderoftheexpt
b. Coefft(poly,expt) to return the coefficient of the term with expt
4. Use Poly.h and write an application (a2Poly.c) for the following:
a. Create a user interface to read the polynomial terms given by the user
b. Implementdisplay(poly)todisplayallthetermsinthepolynomial -displayitintheform
of a X n + b X n-1 + ...+ c
c. Implement sumPoly(poly1, poly2) to return a polynomial that is the sum of poly1 and
poly2



A3: Applications of types of linked lists - CLL, DLL, CDLL

Write algorithms for all theoperations and applications in question 1 and 2 and trace them with an
example. Inspect the steps using the diagrammatic representation of the list.
1. Create an ADTfor a Circula rlinked list(CLL) of integers where CLL is a pointer to the lastnode.


a) Add the followingoperations:
insertFirst(CLL, item), insertLast(CLL, item), deleteFirst(CLL), deleteLast(CLL)
b) Write an application for the following that uses CLL
I. rotate(CLL,direction, count) that rotates the integers in the list by left or right
(direction is -1 for left; +1 for right) by count number of positions.
II. display(CLL) that displays the integers in the CLL
c) Demonstrate the CLL operations and applications with suitable test cases
2. CreateanADTforadoubly linkedlist(DLL) ofintegerswhereDLLis apointerto thefirstnodeof
theDLL. (CO1, K3)
a) Add the followingoperations:
insertFirst(DLL, item), insertLast(DLL, item), deleteFirst(DLL), deleteLast(DLL)
b) Write an application for the following that uses DLL
I. display(DLL) that displays the integers in the DLL
II. shift(DLL, direction, count) that rotates the integers in the list by left or right
(direction is -1 for left; +1 for right) by count number of positions.

A4: Applications of Stacks and Queues

Write algorithms for applications in question 1 and 2 and trace them with an example. Inspect the
steps usingthe diagrammatic representation of theStack / Queue.
1. Create an ADT for a Stack of strings (string.h) implemented using arrays. (CO1,K3)
a) Add the followingoperations:
push, pop, isFull, isEmpty, getTop
b) Write an application for the following that uses the stack (a4stack.c)
I. Given an arithmetic expression, convert to postfix and evaluate it.
II. Given an expression with two types of parenthesis ( [ ] ), check whether the
parenthesis are balanced.

c) Demonstrate the stack operations and applications with suitable test cases

2. Create an ADT for Queue of integers implemented using a circular array (Queue.h) (CO1,K3)
a) Add the followingoperations:
enqueue. dequeue, isFull, isEmpty, getRear,getFront
b) Write an application for the following that uses the Queue (a4q.c)
Consider a Printer Spooler for a network printer — jobs submitted to a printer form a
queue for that printer and the job are printed in spooled order. The interface for the
printer spooler has the operations: spool, print, list. Implement them using the Queue
ADT.
1. spool(q, jobID) adds a job to q.
2. print(q) removes the job to be printed from q.
3. list(q) lists the jobs in q in the spooled order.

A5: Applications of Binary Trees


Write algorithms for applications and trace them with an example. Inspect the steps using the
diagrammatic representation of the tree.
1. Create an ADT for a binary tree (BinTree.h) (CO2, K3)
a) Add the followingoperations:
Construct, inorder, preorder, postorder, levelorder
b) Write an application for the following that uses the binary tree (a5binTree.c)
I. Given an arithmetic expression, convert to postfix (use stack.h)
II. Represent the postfix expression as a binary tree
III. Evaluatetheexpressionrepresentedby thetree(Optional–useinteger stackand
test with expressions involving integers not variables)
IV. Traverse thetree in inorder, preorder, and postorder.(Level order optionally)
c) Demonstrate the binary tree operations and applications with the following test cases

A6: Applications of Binary Search Trees


Write algorithms for applications and trace them with an example. Inspect the steps using the
diagrammatic representation of the tree.
1. Create an ADT for a binary search tree (bst.h). (CO2,K3)
a) Add the followingoperations:
Insert, delete, inorder, preorder, postorder, levelorder (optional), search, maximum,
minimum
b) Write an application for the following (a6bst.c)
I. Check whether two BSTs areidentical
II. Print the number of leaf nodes, non-leaf nodes, total number of nodes
c) Demonstrate the binary search tree operations and applications with the followingtest
cases

A7: Applications of AVL Trees


Write algorithms for applications and trace them with an example. Inspect the steps using the
diagrammatic representation of the tree.
1. Create an ADT for a AVL tree (avl.h). (CO2, K3)
a) Add the followingoperations:
Insert, inorder, search, height
b) Implement a simple telephone directory manager using AVL Tree Data Structure and provide
thefollowinginterfaces.Assumethateachdirectoryentryholdsthenameofthepersonand
his telephone number for simplicity. (a7avl.c)
A. Print_Dir() to print the directory in sorted order of names.
B. Add_Phone() to include a person and phone number
c) Demonstrate the binary search tree operations and applications with the following test case:

A7: Priority Queue - Application of Binary Heap


Write algorithms for applications and trace them with an example. Inspect the steps usingthe
diagrammatic representation of the tree.
1. Create an ADT for a binary heap (heap.h). (CO2, K3)
a) Add the followingoperations:
buildHeap, Insert, deleteMin
b) Implement a priority Queue of beneficiaries of below poverty line families based on their
income. (a8PQ.c).Itisrequiredtofindbeneficiariesbelowthespecifiedlimitofthesalary.
Write an appropriatefunction.


A9: Learning to implement and traverse graphs and their applications

Write algorithms for applications and trace them with an example. Inspect the steps using the
diagrammaticrepresentationofthetree. 
1. CreateagraphasanadjacencymatrixandtraverseitusingDFS(recursive)andBFS
(iterative).
2. Test bfs() for a disconnected graph
3. YouaregivenasetofpersonsPandtheirfriendshiprelationR.Thatis,(a,b)∈Riffaisa
friend of b.You must find a way to introduce person x to person y through a chain of
friends. Model this problem with a graph and solve the problem.
4. Youaregivenasetofcitiesandaircraftsroutes.Modeltheroutesusingagraph.Given
twocities,findwhetherthereexistsadirectflightbetweentwocities;ifnotuseasearch
algorithm and show the hops and connecting flights. (OPTIONAL)


A10: Searching and Sorting - Applications


Writealgorithms for applications. Designproper adequate test caseswithexpectedoutput.
(CO4, K3)
1. Givenanarrayofsortedintegerswithduplicateelements,writeefficientCfunction
getfirstOccur(a[],size,target)thatreturnstheindexofthefirstoccurrenceoftarget
element in thearray
getlastOccur(a[ ], size, target) that returns the index of the last occurrence of target
element in thearray
Example: A[ ] = {2, 34, 45, 47, 53, 53, 53, 53, 64, 64, 76, 89, 97}
getfirstOccur(A[ ], 13, 64) returns 8
getlastoccur(A[ ], 13, 53) returns 7
getfirstOccur(A[ ], 13, 18) returns -1 (Not found)
2. WriteanefficientfunctioninCCountOnes(a[],size)thatcountsthenumberof1’sina
sorted binary array.


A11: Dijkstra’s shortest path finding technique

Given a graph G, implement Dijkstra’s shortest path technique to find shortest path
between a given node and the rest of the nodes. Print the path too.
Sample graph:


A12: Applications of hash table


1. In Open Addressing, all elements are stored in the hash table itself. So at any point, size of table
mustbegreaterthanorequaltototalnumberofkeys(Notethatwecanincreasetablesizeby
copying old data if needed).
• Insert(k)–Keepprobinguntilanemptyslotisfound.Onceanemptyslotisfound,insert
k.
• Search(k)–Keepprobinguntil slot’skeydoesn’tbecomeequaltokoranemptyslotis
reached.
• Delete(k)–Deleteoperationis interesting.Ifwesimplydeleteakey,thensearchmay
fail. So slots of deleted keys are marked specially as “deleted”.
