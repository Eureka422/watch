#ifndef __PAGE_MANAGER_H__
#define __PAGE_MANAGER_H__

#include "page_base.h"
#include <vector>

class PageManager
{
public:
    PageManager(void) {}
    ~PageManager() {}

public:
    std::vector<PageBase*> pages;
};

#endif // __PAGE_MANAGER_H__