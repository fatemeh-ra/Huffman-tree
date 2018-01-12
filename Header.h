#ifndef HEADER_H
#define HEADER_H
#include <string>

using namespace std;

class BaseNode
{
public:
    virtual int getValue(){;}
};

class LeafNode: public BaseNode
{
    char element;
    int value;
public:
    LeafNode(char e, int v)
    {
        element = e;
        value = v;
    }
    char getElement(){return element;}
    int getValue(){return value;}
};

class InternalNode : public BaseNode
{
    int value;
    BaseNode * left;
    BaseNode * right;
public:
    InternalNode(int v, BaseNode *l, BaseNode *r)
    {
        left = l;
        right = r;
        value = v;
    }
    BaseNode* getLeft(){return left;}
    BaseNode* getRight() {return right;}
    int getValue(){return value;}
};

class Heap
{
    BaseNode ** array;
    int size;
    void update(int root, int child);
public:
    Heap()
    {
        array = new BaseNode* [26];
        size = 0;
    }
    int getSize(){return size;}
    void insert(BaseNode*);
    BaseNode* ExtractMin();
    BaseNode* FindMin();
};

void makeTree(Heap *h, string in);
string input();
void output(BaseNode * node, string out);

#endif /* HEADER_H */
