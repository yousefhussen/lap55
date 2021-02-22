
#include "LazyTree.h"
#include <iostream>

using namespace std;

int main()
{
    LazyTree l1;
    l1.insert(22);
    l1.insert(12);
    l1.insert(16);
    l1.insert(14);
    l1.insert(20);
    l1.insert(18);
    l1.insert(6);
    l1.insert(8);
    l1.insert(10);
    l1.insert(4);
    l1.insert(2);
    l1.insert(32);
    l1.insert(24);
    l1.insert(28);
    l1.insert(26);
    l1.insert(30);
    l1.insert(38);
    l1.insert(34);
    l1.insert(36);
    l1.insert(42);
    l1.insert(40);
    //cout << l1.size() << endl;
    //cout << l1.height() << endl;
   // l1.erase(16);
     //l1.erase(18);
   // l1.erase(4);
   // cout << l1.member(4);
    // cout << l1.front() << endl;
  l1.erase(22);
  l1.erase(12);
  l1.erase(24);
  l1.erase(10);
  l1.erase(42);


  l1.insert(22);
  l1.insert(24);
  l1.insert(10);
  l1.insert(12);
  l1.insert(42);
 
   // cout << l1.back()->data << endl;
      //l1.clean();
     // cout << l1.size() << endl;
    //  l1.clear();
     // cout << l1.size() << endl;
   l1.breadth_first_traversal();


}


