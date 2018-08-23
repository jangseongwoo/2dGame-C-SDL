// debug.h

#include <windows.h>
#include <tchar.h>

#define DEBUG_PRINTF(format, ...)     {fprintf (stderr, format, ##__VA_ARGS__); TCHAR __debugStr[1000]; _stprintf(__debugStr, _T(format), ##__VA_ARGS__); OutputDebugString(__debugStr);}
