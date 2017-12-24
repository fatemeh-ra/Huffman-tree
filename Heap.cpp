#include <iostream>
#include "Header.h"

using namespace std;

BaseNode* Heap::FindMin()
{
    return array[0];
}

void Heap::insert(BaseNode *x)
{
    array[size] = x;
    int s = size;
    for (int i = size/2; i >= 0; i /= 2)
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
    size++;
}

BaseNode* Heap::ExtractMin()
{
    auto m = array[0];
    array[0] = array[--size];
    bool result;
    if(size > 1) result = update(0, 1);
    if(size > 2 && !result) update(0, 2);
    return m;
}

bool Heap::update(int root, int child)
{
    if (array[root]->getValue() > array[child]->getValue())
    {
        auto tmp = array[root];
        array[root] = array[child];
        array[child] = tmp;
        bool result;
        if(size > child*2)
        {
            result = update(child, child*2);
        }
        if(size >= child*2 && !result)
        {
            update(child, child*2 -1);
        }
        return true;
    }
    return false;
}