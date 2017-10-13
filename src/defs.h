#pragma once

#include <string>
using namespace std;

#if WINDOWS
#include <Windows.h>
#endif

#ifndef NDEBUG
#define DEBUG 1
#endif

inline void DBG(string s)
{
#if DEBUG
#if WINDOWS
    OutputDebugString(s.c_str());
#else
    cout << s;
#endif
#endif
}
