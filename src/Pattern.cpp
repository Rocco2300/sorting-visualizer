#include "Pattern.h"

Pattern::Pattern()
{
}

int Pattern::getListNumber()
{
    return listNumber;
}

void Pattern::setPointers(std::vector<ElementList>& elLists, int& elems)
{
    elemLists = &elLists;
    elements = &elems;
}

void Pattern::setDescending(bool desc)
{
    descending = desc;
}