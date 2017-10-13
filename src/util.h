#pragma once

#include <vector>
#include <sstream>

#include "defs.h"

namespace exemplar
{
    template <class T> void printVector(const vector<T>& v)
    {
        for (auto x : v) {
            stringstream ss;
            ss << x << " ";
            DBG(ss.str());
        }
        DBG("\n");
    }
}