#include <iostream>
#include "Header.h"

using namespace std;

BaseNode* Heap::FindMin()
{
    return array[1];
}

void Heap::insert(BaseNode *x)
{
    array[++size] = x;
    int s = size;
    for (int i = size/2; i > 0; i /= 2)
    {
        if (array[i]->getValue() > array[s]->getValue())
        {
            auto tmp = array[s];
            array[s] = array[i];
            array[i] = tmp;
            s = i;
        }
        else break;
    }
}

BaseNode* Heap::ExtractMin()
{
    auto m = array[1];
    array[1] = array[size--];
    if(size == 2) update(1, 2);
    else if(size > 2 && array[2]->getValue() <= array[3]->getValue()) update(1, 2);
    else if(size > 2 && array[3]->getValue() < array[2]->getValue()) update(1, 3);
    return m;
}

void Heap::update(int root, int child)
{
    if (array[root]->getValue() > array[child]->getValue())
    {
        auto tmp = array[root];
        array[root] = array[child];
        array[child] = tmp;
        bool result;
        if (size == child*2) update(child, child*2);
        else if (size > child*2 && array[child*2]->getValue() <= array[child*2 + 1]->getValue()) 
            update(child, child*2);
        else if (size > child*2 && array[child*2 + 1]->getValue() < array[child*2]->getValue()) 
            update(child, child*2 + 1);
    }
}