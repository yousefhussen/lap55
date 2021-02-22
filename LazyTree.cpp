#include "LazyTree.h"
#include <bitset>

LazyTree::LazyTree()
{
    root = NULL;
}

LazyTree::LazyTree(NodePointer node)
{
    root = node;
}
//lazytree t1(New node(value));
bool LazyTree::insert(ElementType dataVal)
{
    
    NodePointer z = new Node(dataVal);
    
    if (root == NULL) {
        root = z;
        nodesCounter++;
        if (root->isErased) {
            root->isErased = false;
            return true;
        }
        return true;
    }

    NodePointer parent = NULL, x = root;
    while (x != NULL) {
        parent = x;

        if (x->data > dataVal) {
            x = x->Left;
            

        }
        else if(x->data < dataVal) {
            x = x->Right;
           
        }
        else
        {
            break;
        }

    }

    if (dataVal < parent->data) {

        parent->Left = z;
        nodesCounter++;
        mySize++;
      
       
        
        return true;

    }
    else if (dataVal > parent->data) {
        parent->Right = z;
        nodesCounter++;
        mySize++;
      
        
        
        return true;

    }
    else if (dataVal == parent->data)
    {
       
        if (parent->isErased)
        { 
            parent->isErased = false;
            nodesCounter++;
            mySize++;
        }
    }

    return false;
}

bool LazyTree::erase(ElementType data)
{
    if (root == NULL)
    {
        return false;
    }
    NodePointer node = root;
    while (node != NULL)
    {
        if (node->data == data)
        {
            if (node->isErased == false)
            {
                node->isErased = true;
                deletedCounter++;
                nodesCounter--;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (node->data < data)
        {
            node = node->Right;
        }
        else if (node->data > data)
        {
            node = node->Left;
        }
    }
    return false;
}

bool LazyTree::empty() const
{
    return nodesCounter == 0;
}

int LazyTree::size() const
{
    
   // cout << "deleted counter" << deletedCounter << endl;
    return nodesCounter;
}
int LazyTree::deleted() const
{
    return deletedCounter;
}




int LazyTree::height(NodePointer node) const
{

    if (node == NULL || node== nullptr)
    {
        return 0;
    }
    if (node->data == -1)
    {
        node = root;
    }
    int left_side;
    int right_side;
    left_side = height(node->Left);
    right_side = height(node->Right);
    if (left_side > right_side)
    {
        return left_side + 1;
    }
    else
    {
        return right_side + 1;
    }

}

bool LazyTree::member(ElementType const& obj) const
{

    if (obj < 1 || obj >99)
    {
        cerr << "not valid number" << endl;
        return 0;
    }

    //return false is the tree is empty
    if (empty())
    {
        return false;
    }
    NodePointer node = root;

    //iterate through the BST
    while (node != NULL)
    {
        if (obj == node->data)
        {
            if (node->isErased == false)
                return true;
            else
                return false;
        }
        else if (obj < node->data)
            node = node->Left;
        else if (obj > node->data)
            node = node->Right;
    }
    return false;
}

LazyTree::Node* LazyTree::front(NodePointer node ) const
{
    if (node == nullptr)
    {
        return NULL;
    }
    if (node->data == -1)
    {
        node = root;
    }

    if (front(node->Left)!= NULL)
    {
        return front(node->Left);
    }
    else if (!node->isErased)
    {
        return node;
    }
    else
    {
        return front(node->Right);
    }

    return NULL;

}

LazyTree::Node* LazyTree::front2(NodePointer node, NodePointer pre) const
{
    NodePointer post = node->Left;

    while (post!=nullptr)
    {
        pre = node;
        node = post;
        post = node->Left;
    }
    if (pre->Left == node)
    {
        pre->Left = NULL;
    }
    else
    {
        pre->Right = NULL;
    }
    return node;
    
   

}

LazyTree::Node* LazyTree::back(NodePointer node) const
{
    if (node == nullptr)
    {
        return NULL;
    }
    if (node->data == -1)
    {
        node = root;
    }

    if (back(node->Right)!=NULL)
    {
        return back(node->Right);
    }
    else if (!node->isErased  )
    {
        return node;
    }
    else
    {
        return back(node->Left);
    }
   
    return NULL;
}
LazyTree::Node* LazyTree::back2(NodePointer node, NodePointer pre) const
{
    NodePointer post = node->Right;
    int i = 0;


    while (post != nullptr)
    {
        pre = node;
        node = post;
        post = node->Right;
       
    }
    if (pre->Left == node)
    {
        pre->Left = NULL;
    }
    else
    {
        pre->Right = NULL;
    }

    return node;

}

void LazyTree::breadth_first_traversal(NodePointer node, ElementType level) const
{
    if (node->data == -1)
    {

        node = root;
    }
    if (empty()) { return; }
    //print first node ya nigga
    if (level == -1)
    {
        if (node->isErased)
        {
            cout << node->data << "x " << " ";
        }
        else
        {
            cout << node->data << " ";
        }
        breadth_first_traversal(node, level + 1);
        return;
    }
    int numofnodes = pow(2, level);
  
    
    if (level <=4)
    {
        bool skip = false;
        string s;
        for (int i = 0; i < numofnodes * 2; i++)
        {
            node = root;
            s = bitset<32>(i).to_string();
            s = s.substr(s.length() - level - 1);

            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == '0' && node->Left != nullptr)
                {
                    node = node->Left;
                }
                else if (s[j] == '1' && node->Right != nullptr)
                {
                    node = node->Right;
                }
                else 
                {
                    skip = true;
                    break;
                }
            }
            if (node->isErased && !(skip))
            {
                cout << node->data << "x " << " ";
            }
            else if (!(skip))
                cout << node->data << " ";
            else
            {
                skip = false;
            }
        }
        breadth_first_traversal(node, level + 1);
    }
}


//btm3s7 kolo 
void LazyTree::clear(NodePointer node)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->data == -1)
    {
      
        node = root;
    }
    clear(node->Left);
    clear(node->Right);
    if (node->isErased)
    {
        deletedCounter--;
    }
    else
    {
        nodesCounter--;
    }
    
    delete node;



}
//btm37 gz2 mno
void LazyTree::clean(NodePointer node , NodePointer pre)
{
   
    if (node == nullptr)
    {
        return;
    }
    if (node->data == -1)
    {
        node = root;
    }
    
    clean(node->Left ,node );
    clean(node->Right , node);
    
    if (node->isErased)
    {
        if (node->Left == nullptr && node->Right == nullptr)
        { 
            
            if (pre->Left == node)
            {
                pre->Left = NULL;
            }
            else
            {
                pre->Right = NULL;
            }
           
            
            

        }
        else if (node->Left == nullptr || node->Right == nullptr)
        {
           

            if (node->Left == nullptr)
            {
                node->data = front2(node->Right, node)->data;
                node->isErased = false;
                
               
              
            }
            else
            {
                node->data = back2(node->Left, node)->data;
                node->isErased = false;

            }
        }
        else
        {
           

            node->data = front2(node->Right, node)->data;
            node->isErased = false;

           
        }
    }
}








