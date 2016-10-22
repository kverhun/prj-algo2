#pragma once

#if BINARY_HEAP_LIBRARY
#define BINARYHEAP_API __declspec(dllexport)
#else
#define BINARYHEAP_API __declspec(dllimport)
#endif
