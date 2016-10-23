#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <limits.h>

#include "../impl/BinaryHeap.h"

static const size_t g_zero_element_heap = std::numeric_limits<size_t>::max();

namespace
{
    void _AreEqual(const std::vector<size_t>& i_vector, const std::initializer_list<size_t>& i_list)
    {
        auto it_vec = i_vector.begin();
        auto it_list = i_list.begin();
        for (; it_vec < i_vector.end() && it_list < i_list.end(); ++it_vec, ++it_list)
        {
            REQUIRE(*it_vec == *it_list);
        }
    }
}

TEST_CASE("BinaryHeapTest1")
{
    BinaryHeap heap;

    heap.Insert(5);
    _AreEqual(heap.GetHeap(), {g_zero_element_heap, 5});
    
    heap.Insert(6);
    _AreEqual(heap.GetHeap(), { g_zero_element_heap, 6, 5 });

    heap.Insert(4);
    _AreEqual(heap.GetHeap(), { g_zero_element_heap, 6,5,4 });

    heap.Insert(7);
    _AreEqual(heap.GetHeap(), { g_zero_element_heap, 7,6,4,5 });
}

TEST_CASE("BinaryHeapTest2")
{
    BinaryHeap heap;

    heap.Insert(4);
    heap.Insert(5);
    heap.Insert(6);

    _AreEqual(heap.GetHeap(), { g_zero_element_heap, 6, 4, 5 });
    
    heap.Insert(7);
    _AreEqual(heap.GetHeap(), { g_zero_element_heap, 7, 6, 5, 4 });

    REQUIRE(heap.Pop() == 7);

    _AreEqual(heap.GetHeap(), { g_zero_element_heap, 6, 4 ,5 });

    heap.Insert(7);
    heap.Insert(8);
    heap.Insert(9);

    REQUIRE(heap.Pop() == 9);
    _AreEqual(heap.GetHeap(), { g_zero_element_heap, 8, 7, 5, 4, 6 });
}