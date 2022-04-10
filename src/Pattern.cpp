#include "Pattern.h"

Pattern::Pattern()
{
}

void Pattern::setElements(int& elemNo)
{
    elements = &elemNo;
}

int Pattern::getListNumber()
{
    return listNumber;
}