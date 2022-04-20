#include "Pattern.h"

Pattern::Pattern()
{
}

int Pattern::getListNumber()
{
    return listNumber;
}

void Pattern::setPointer(std::vector<ElementList>& elLists)
{
    elemLists = &elLists;
}

void Pattern::setDescending(bool desc)
{
    descending = desc;
}

void Pattern::setElementNo(int elementNo)
{
    elements = elementNo;
}