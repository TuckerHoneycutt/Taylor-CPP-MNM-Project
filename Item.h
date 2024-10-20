#ifndef ITEM_H
#define ITEM_H
#include <cstring>

struct Item {
    char    m_sItemName[65];
    int     m_iType;
    double  m_dValue;
    double  m_dWeight;
};

#endif
