#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
    Heap h;
    string in;
    in = input();
    makeTree(h, in);
    InternalNode* x = (InternalNode*)h.FindMin();
    output(h.FindMin(), "");
}

string input()
{
    fstream in;
    in.open("in.txt", ios::in);
    string a, result;
    while(getline(in,a))
    {
        result = result + a;
    }
    return result;
}

int countChar(string in, char target)
{
    int result = 0;
    for(auto i: in)
    {
        if(i == target) result++;
    }
    return result;
}

void makeTree(Heap h, string in)
{
    for(int i = 'A'; i <= 'Z'; i++)
    {
        int x = countChar(in, i);
        if(x != 0)
        {
            LeafNode *l = new LeafNode(i, x);
            h.insert((BaseNode*)l);
        }
    }
    while(h.getSize() > 1)
    {
        auto a = h.ExtractMin();
        auto b = h.ExtractMin();
        InternalNode *n = new InternalNode(a->getValue()+b->getValue(),a,b);
        h.insert((BaseNode*)n);
    }
}

void output(BaseNode * node, string out)
{
    if(node->isLeaf())
    {
        LeafNode * x = (LeafNode*)node;
        cout << x->getElement() << " = " << out << endl;
        return;
    }
    InternalNode *x = (InternalNode*)node;
    output(x->getLeft(), out + "0");
    output(x->getRight(), out+ "1");
    return;
}
