

//------------------------------------------------------------------------------------------------------------------------------------------------------------


/*

    BINARY TREE 




*/



//------------------------------------------------------------------------------------------------------------------------------------------------------------





//------------------------------------------------------------------------------------------------------------------------------------------------------------


/*

    STEPS TO STUDY 

    TREE 
    BINARY TREE 
    BINARY  TREE SEARTH
    BINARY TREE VS BINATY TREE SEATH(BTS)





*/



//------------------------------------------------------------------------------------------------------------------------------------------------------------






//------------------------------------------------------------------------------------------------------------------------------------------------------------


/*


    GRAFO 
    In mathematics, graph theory is the study of graphs, which are mathematical structures used to model pairwise relations between objects. A graph in this context is made up of vertices which are connected by edges







*/



//------------------------------------------------------------------------------------------------------------------------------------------------------------














//------------------------------------------------------------------------------------------------------------------------------------------------------------


/*
    TREE 






    Tree Data Structure


    We read the linear data structures like an array, linked list, stack and queue in which all the elements are arranged in a sequential manner. The different data structures are used for different kinds of data.

    Some factors are considered for choosing the data structure:
      What type of data needs to be stored?: It might be a possibility that a certain data structure can be the best fit for some kind of data.
      
      Cost of operations: If we want to minimize the cost for the operations for the most frequently performed operations. For example, we have a simple list on which we have to perform the search operation; then, we can create an array in which elements are stored in sorted order to perform the binary search. The binary search works very fast for the simple list as it divides the search space into half.
      
      Memory usage: Sometimes, we want a data structure that utilizes less memory.





    A tree is also one of the data structures that represent hierarchical data. Suppose we want to show the employees and their positions in the hierarchical form then it can be represented as shown below:

    The above tree shows the organization hierarchy of some company. In the above structure, john is the CEO of the company, and John has two direct reports named as Steve and Rohan. Steve has three direct reports named Lee, Bob, Ella where Steve is a manager. Bob has two direct reports named Sal and Emma. Emma has two direct reports named Tom and Raj. Tom has one direct report named Bill. This particular logical structure is known as a Tree. Its structure is similar to the real tree, so it is named a Tree. In this structure, the root is at the top, and its branches are moving in a downward direction. Therefore, we can say that the Tree data structure is an efficient way of storing the data in a hierarchical way.






    Some basic terms used in Tree data structure.


    Root: The root node is the topmost node in the tree hierarchy. In other words, the root node is the one that doesn't have any parent. In the above structure, node numbered 1 is the root node of the tree. If a node is directly linked to some other node, it would be called a parent-child relationship.
    Child node: If the node is a descendant of any node, then the node is known as a child node.
    Parent: If the node contains any sub-node, then that node is said to be the parent of that sub-node.
    Sibling: The nodes that have the same parent are known as siblings.
    Leaf Node:- The node of the tree, which doesn't have any child node, is called a leaf node. A leaf node is the bottom-most node of the tree. There can be any number of leaf nodes present in a general tree. Leaf nodes can also be called external nodes.
    Internal nodes: A node has atleast one child node known as an internal
    Ancestor node:- An ancestor of a node is any predecessor node on a path from the root to that node. The root node doesn't have any ancestors. In the tree shown in the above image, nodes 1, 2, and 5 are the ancestors of node 10.
    Descendant: The immediate successor of the given node is known as a descendant of a node. In the above figure, 10 is the descendant of node 5.




    Applications of trees
    The following are the applications of trees:

    Storing naturally hierarchical data: Trees are used to store the data in the hierarchical structure. For example, the file system. The file system stored on the disc drive, the file and folder are in the form of the naturally hierarchical data and stored in the form of trees.
    Organize data: It is used to organize data for efficient insertion, deletion and searching. For example, a binary tree has a logN time for searching an element.
    Trie: It is a special kind of tree that is used to store the dictionary. It is a fast and efficient way for dynamic spell checking.
    Heap: It is also a tree data structure implemented using arrays. It is used to implement priority queues.
    B-Tree and B+Tree: B-Tree and B+Tree are the tree data structures used to implement indexing in databases.
    Routing table: The tree data structure is also used to store the data in routing tables in the routers.



    Types of Tree data structure

    General tree: The general tree is one of the types of tree data structure. In the general tree, a node can have either 0 or maximum n number of nodes. There is no restriction imposed on the degree of the node (the number of nodes that a node can contain). The topmost node in a general tree is known as a root node. The children of the parent node are known as subtrees.


    Binary tree: Here, binary name itself suggests two numbers, i.e., 0 and 1. In a binary tree, each node in a tree can have utmost two child nodes. Here, utmost means whether the node has 0 nodes, 1 node or 2 nodes.


    Binary Search tree: Binary search tree is a non-linear data structure in which one node is connected to n number of nodes. It is a node-based data structure. A node can be represented in a binary search tree with three fields, i.e., data part, left-child, and right-child. A node can be connected to the utmost two child nodes in a binary search tree, so the node contains two pointers (left child and right child pointer).
    Every node in the left subtree must contain a value less than the value of the root node, and the value of each node in the right subtree must be bigger than the value of the root node.    


    AVL tree
    It is one of the types of the binary tree, or we can say that it is a variant of the binary search tree. AVL tree satisfies the property of the binary tree as well as of the binary search tree. It is a self-balancing binary search tree that was invented by Adelson Velsky Lindas. Here, self-balancing means that balancing the heights of left subtree and right subtree. This balancing is measured in terms of the balancing factor.



    B-tree
    B-tree is a balanced m-way tree where m defines the order of the tree. Till now, we read that the node contains only one key but b-tree can have more than one key, and more than 2 children. It always maintains the sorted data. In binary tree, it is possible that leaf nodes can be at different levels, but in b-tree, all the leaf nodes must be at the same level.







    REFERENCE: 
    https://www.javatpoint.com/tree




*/



//------------------------------------------------------------------------------------------------------------------------------------------------------------
















//------------------------------------------------------------------------------------------------------------------------------------------------------------


/*

    TREE 2:


    Tree Data Structure

    We all are familiar with trees in real life, aren’t we? It’s fascinating to know that with the observation of leaves and branches of a tree, one came up with a structure to store and organise data in the real world which now is widely being used in multiple application libraries and has really changed the world.

    Well, coming back to a tree. Observing one, we can conclude that a tree has leaves, branches, roots and stems. If observed more carefully, each leaf, following it’s stems and branches,when traced, can take us to its roots.

    In real life, this fine observation can be used to structure a basic family history in the form of the hierarchy where leaves can be considered as children and tracing leaf with it’s stems and branches can lead to its earliest known roots i.e. parents to grandparents to earliest known grandparents.    



    Let's understand some key points of the Tree data structure.

    A tree data structure is defined as a collection of objects or entities known as nodes that are linked together to represent a hierarchy.
    It's a non linear data structure as it does not store data in a sequential manner, but stores in a hierarchical fashion.
    In the Tree data structure, the first node is known as a root node i.e. from which the tree originates. Each node contains some data and also contains references to child nodes. A root node can never have a parent node.


    Tree Data Structure Terminologies

    Tree is a hierarchical data structure that is defined as a collection of nodes. In a tree nodes represent the values and are connected by edges. Following are the terminologies and properties of a tree:






    Properties of Trees in Data Structure
    Recursive Data Structure: a recursive method is the one that calls itself. Similarly a recursive data structure is the one that contains itself. A tree can be viewed as a recursive data structure, as even though a tree has only one root node, each node acts as a root node to another sub-tree. For example:

    Following is a tree that has ‘A’ as the root node. Similarly if we look at ‘C’ node, that is another tree in itself. And the tree no 3 i.e. that starts with ‘D’ node is also a tree in itself.

    And that is how a tree contains multiple trees in itself, and this proves that it's a recursive data structure as a recursive data structure contains itself.

    Note: Even the leaf nodes are a tree in itself i.e. they can be seen from a perspective as trees without any child nodes.

    Number of edges: If there are ‘n’ nodes in a tree then there would be ‘n-1’ edges. Each edge is the line-arrow connecting two nodes.

    Depth of node x: Depth of a specific node x is defined as the length from root till this x node. One edge contributes to one unit in the length. Hence depth of a node x can also be considered as the number of nodes from root node till this x node. Or depth of a node x can also be considered as the level L at which this node is, and adding 1 to it i.e. depth = L + 1. It is because the first level starts with 0.

    Height of node x: Height of a node represents the number of edges on the longest path between that node and a leaf.



    Applications of Trees in Data Structure


    Traversing: One of the best examples for traversing is DocumentObjectModel. With such a structure, it becomes simpler to “traverse” through the tree in order for the programmers to access related nodes. It allows access to all siblings of a currently selected node. The tree structure becomes a route for the html interpreter that can be followed to traverse throughout the HTML document.


    Search: As a tree is a hierarchical data structure, each node is connected to another node, hence it allows it to reach a specific data node easily and efficiently. Consider a binary search tree, which is a more refined version of a tree as each node has at most 2 child nodes (a left node and a right node).
    A left node will contain data that is less than the data in the current node and right node will contain data greater than data than the current node. Hence a specific data is easy to search in a binary search tree. Even though a binary search tree allows efficient searching, extra effort that is required to create a binary search tree shall also be considered.
    As the time complexity of searching an element in the binary search tree is O(H), where H is the height of the tree, that not only makes searching efficient but also makes insertion and deletion possible at any node in the tree.
    Hence organising data in a tree also becomes feasible with efficient insertion and deletion at any node.


    Decision Making: Picture tree as a structure where each node depicts a decision made by the user. Each node provides us with two choices and as the user chooses one, it moves down the tree with one step. As we reach a leaf, we reach a final decision. Hence all the flows in any application can all be picturised in a tree as each and every flow is defined and there are not infinite flows in an application (unless they’re circular). For example the following diagram represents multiple decisions that a user has to make while selecting a movie. Hence, flows to reach a movie that a user wants to watch are very limited. From the client’s side or the user’s perspective this may not seem like the same construct. But from the application’s program/code’s perspective there is some tree-like data structure that is following a similar construct as below.
    Hence a tree data structure can provide us with an algorithm that can allow a user to explore movie streaming applications in such a way that they can reach a movie that might be best recommended for them.




    Types Of Trees in Data Structure

    General tree: In the general tree, each node has either 0 or n number of nodes. In this tree, there is no limitation to the number of nodes. It starts with a root node and the children of the parent node make another general sub tree. Hence eachnode is a root of another sub-tree i.e. there can be `n number of subtrees in a general tree. All the subtrees are unordered in a general tree.


    Binary Tree: In a binary tree, each node can have at most 2 children (i.e. either 0, 1, 2). There is no restriction as to what data will be in the left child or right child.

    Binary Search Tree: A binary search tree just like a binary tree can have at most 2 children. It can have n nodes and also each node can be defined as a data part that holds the data, left child and the right node.
    Left child holds reference to the node that contains data which is immediately lesser than the data in the current node and similarly the right child contains the reference to the node that contains data which is just greater than the data in the current node.
    Every node in the left subtree must contain a value less than the value of the root node, and the value of each node in the right subtree must be bigger than the value of the root node. Relating to the above representation, a node can be programmatically defined as:    


    AVL Tree: It can be considered as a binary tree and also a type of binary search tree. It satisfies features of both binary tree and binary search tree.
    It's a self balancing tree i.e. balancing heights of left subtree and right subtree. This balancing is measured by something called balancing factor.
    A tree is considered as an AVL tree if it satisfies properties of both a binary search tree and the balancing factor. Difference between the height of the left subtree and the right subtree is considered as the height of the AVL tree.The value of the balancing factor must be 0, 1 or -1 for each node in an AVL tree.














    REFERENCE: 
    https://www.cs.cmu.edu/~clo/www/CMU/DataStructures/Lessons/lesson4_1.htm
    https://www.scaler.com/topics/data-structures/tree-data-structure/******************* VERY GOOD LINK 




*/



//------------------------------------------------------------------------------------------------------------------------------------------------------------










//------------------------------------------------------------------------------------------------------------------------------------------------------------


/*

    Everything you need to know about tree data structures



    Definition
    When starting out programming, it is common to understand better the linear data structures than data structures like trees and graphs.

    Trees are well-known as a non-linear data structure. They don’t store data in a linear way. They organize data hierarchically.


    Let’s dive into real life examples!
    What do I mean when I say in a hierarchical way?

    Imagine a family tree with relationships from all generation: grandparents, parents, children, siblings, etc. We commonly organize family trees hierarchically.





    A technical definition
    A tree is a collection of entities called nodes. Nodes are connected by edges. Each node contains a value or data, and it may or may not have a child node .




    All Tree nodes are connected by links called edges. It’s an important part of trees, because it’s manages the relationship between nodes.


    Leaves are the last nodes on a tree. They are nodes without children. Like real trees, we have the root, branches, and finally the leaves.





    Other important concepts to understand are height and depth.

    The height of a tree is the length of the longest path to a leaf.

    The depth of a node is the length of the path to its root.




    Terminology summary
    Root is the topmost node of the tree
    Edge is the link between two nodes
    Child is a node that has a parent node
    Parent is a node that has an edge to a child node
    Leaf is a node that does not have a child node in the tree
    Height is the length of the longest path to a leaf
    Depth is the length of the path to its root




    Binary trees
    Now we will discuss a specific type of tree. We call it thebinary tree.

    “In computer science, a binary tree is a tree data structure in which each node has at the most two children, which are referred to as the left child and the right child.” — Wikipedia
    So let’s look at an example of a binary tree.





    Now we have to think about tree traversal.

    We have two options here: Depth-First Search (DFS) and Breadth-First Search (BFS).

    DFS “is an algorithm for traversing or searching tree data structure. One starts at the root and explores as far as possible along each branch before backtracking.” — Wikipedia
    BFS “is an algorithm for traversing or searching tree data structure. It starts at the tree root and explores the neighbor nodes first, before moving to the next level neighbors.” — Wikipedia



    Depth-First Search (DFS)
    DFS explores a path all the way to a leaf before backtracking and exploring another path. Let’s take a look at an example with this type of traversal.


    Now that we are familiar with this traversal algorithm, we will discuss types of DFS: pre-order, in-order, and post-order.


Pre-order
This is exactly what we did in the above example.

    Print the value of the node.
    Go to the left child and print it. This is if, and only if, it has a left child.
    Go to the right child and print it. This is if, and only if, it has a right child.




    Breadth-First Search (BFS)
    BFS algorithm traverses the tree level by level and depth by depth.










    Binary Search tree

    A Binary Search Tree is sometimes called ordered or sorted binary trees, and it keeps its values in sorted order, so that lookup and other operations can use the principle of binary search” — Wikipedia


    An important property of a Binary Search Tree is that the value of a Binary Search Tree nodeis larger than the value of the offspring of its left child, but smaller than the value of the offspring of its right child.”









    REFERENCE: 
    https://www.freecodecamp.org/news/all-you-need-to-know-about-tree-data-structures-bceacb85490c/







*/



//------------------------------------------------------------------------------------------------------------------------------------------------------------
















//------------------------------------------------------------------------------------------------------------------------------------------------------------


/*

    Binary Tree in Data Structure



    Overview
    A binary tree is a tree-type non-linear data structure with a maximum of two children for each parent. Every node in a binary tree has a left and right reference along with the data element. The node at the top of the hierarchy of a tree is called the root node.


    What are Binary Trees?




    Terminologies in Binary Trees
    1. Nodes – Nodes are the building blocks of any data structure. They majorly contain some data and link to the next/previous nodes. In the case of binary trees, they contain the address of the left and the right child respectively.

    2. Root – The topmost node in a tree is known as the root node. A tree can have at most one root node.

    3. Parent Node – A node (except the root) that has a succeeding node is known as a parent node.

    4. Child Node – A node that has a preceding node is known as a child node. A node can be both parent and child depending on the node that is in context.

    5. Leaf Node – A node with no children.

    6. Internal Node – A node that has at least one child node is known as an internal node.

    7. Depth of a Binary Tree – The number of edges from a node in the tree to the root node.

    8. Height of a Binary Tree – The number of edges from the deepest node in the tree to the root node.





    Types of Binary Trees


    Binary Trees are of many types, and each of these trees has its own properties and characteristics.

    Let’s discuss some of them in detail –

    1. Full Binary Tree
    A full binary tree, also known as a proper binary tree, is a tree in which each internal node has either zero or two children nodes is known as a full binary tree.

    In other words, if in a binary tree a node contains only one child node, it is not a full binary tree.


    Notice how each node has either zero or two children nodes.

    In a full binary tree, if there are n number of total nodes –

    The number of internal nodes is given by (n-1)/2
    The number of leaf nodes is given by (n+1)/2




    2. Complete Binary Tree


    A complete binary tree is a binary tree in which all the elements are arranged without missing any sequence.

    In a complete binary tree –

    All the levels are completely filled except the last level that may or may not be completely filled.
    Elements are filled from left to right.



    3. Perfect Binary Trees
    If in a tree all the internal nodes have exactly two children nodes, it is known as a perfect binary tree.

    In a perfect binary tree, all the leaf nodes are on the same level.


    Consider a perfect binary tree with height h, the total number of nodes in this case is given by 2h – 1.



    4. Degenerate Binary Trees

    If in a binary tree each node contains only one child node either on the left side or the right side of the tree, it is known as a degenerate binary tree.

    Degenerate binary trees are equal to linked lists in terms of performance. The following tree shows a degenerate binary tree –

    Degenerate binary trees can also be classified into two types –
    a. Left-skewed – A degenerate binary tree in which all the nodes lean towards the left side of the tree. The following diagram shows a left-skewed degenerate binary tree –

    b. Right-skewed – A degenerate binary tree in which all the nodes lean towards the right side of the tree. The following diagram shows a right-skewed degenerate binary tree –


    5. Balanced Binary Trees

    A binary tree is said to be balanced if the height of the left and the right subtrees differ by 0 or 1.

    In a balanced binary tree, both the left and right trees are also balanced. The following diagram shows a balanced binary tree –


    Benefits of Binary Trees
    Binary trees are used in binary search trees. It helps in searching for elements in a faster and efficient way.

    Binary trees are also used in heaps that are special kind of binary trees. Heaps are used in heap sort, which is an efficient sorting algorithm. Heaps are also used in building priority queues in which elements are arranged in the order of their priorities.

    Binary trees are used in converting different prefix and postfix expressions.

    Binary trees are also used in graph traversal algorithms like Dijkastra’s algorithm.

    Some real-life applications of binary trees include virtual memory management, and 3D where faster rendering of objects is required.

    Binary tree Time Complexity
    Searching: Worst case complexity of O(n). Insertion: Worst case complexity of O(n). Deletion: Worst case complexity of O(n).

    Binary tree Space Complexity
    Searching: O(n). Insertion: O(n). Deletion: O(n).













    REFERENCE: 
    https://www.scaler.com/topics/data-structures/binary-tree-in-data-structure/




*/



//------------------------------------------------------------------------------------------------------------------------------------------------------------













//------------------------------------------------------------------------------------------------------------------------------------------------------------


/*

    REFERENCE: 
    https://www.javatpoint.com/binary-search-tree




*/



//------------------------------------------------------------------------------------------------------------------------------------------------------------









