#pragma once
#include <iostream>

using namespace std;
typedef int ElementType;

class LazyTree
{
private:

    class Node {
    public:
        ElementType data;
        bool isErased;
        Node* Left;
        Node* Right;
        Node() : Right(0), Left(0), isErased(false)
        {

        }
        //is it erased = false
        Node(ElementType dataValue) : data(dataValue), Left(0), Right(0), isErased(false)
        {

        }

    };

    typedef Node* NodePointer;
    NodePointer root;
    int nodesCounter = 0;
    int deletedCounter = 0;
    int mySize;

public:
    LazyTree();
    LazyTree(NodePointer node);
    bool insert(ElementType data);
    bool erase(ElementType data);
    bool empty() const;
    //Return true if the tree is empty(the size is 0). (O(1))
    int size() const;
    // Returns the number of nodes in the tree not including nodes tagged as erased. (O(1))
    int height(NodePointer node = new Node(-1)) const;
    // Returns the height of the tree including nodes tagged as erased. (O(n))
    bool member(ElementType const& obj) const;
    //  Return true if the argument is in the tree and not tagged as erased and false otherwise. (O(h))
    LazyTree::Node* front(NodePointer node = new Node(-1)) const;
    // Return the minimum non - erased object of this tree by calling front on the root node.The object will be the first argument of a pair(*, true) returned by the node member function, and will throw an exception underflow if the second for (*, false) (the tree has size zero).Hint: What type of traversal will you need ? Under what conditions do you continue searching, and under what conditions do you return ? (O(n))
    LazyTree::Node* back(NodePointer node = new Node(-1)) const;
    // Return the maximum non - erased object of this tree by calling back on the root node.The object returned will be a pair of the form(*, true); return the first object.This member function may throw an underflow exception if the tree has zero size. (O(n))
    void breadth_first_traversal(NodePointer node = new Node(-1), ElementType level = -1) const;
    // Perform a breadh - first traversal which prints the objects in the order in which they are visited in a single line(no end - of - line character).If an object is marked as erased, the string "x " is printed immediately following the object, otherwise a string containing a single space " " is printed after the object.You may use the Standard Template Library(STL) std::queue for the queue required for the traversal.For example, valid(ignoring the quotation marks) output may be "3 7x 4x 9 5x " (O(n))
    void clear(NodePointer node = new Node(-1));
    void clean(NodePointer node = new Node(-1) , NodePointer pre = NULL);
    int deleted()const;
    LazyTree::Node* front2(NodePointer node = new Node(-1), NodePointer pre = NULL) const;
    LazyTree::Node* back2(NodePointer node = new Node(-1), NodePointer pre = NULL) const;
};



