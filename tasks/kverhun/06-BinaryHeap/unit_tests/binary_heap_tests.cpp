#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "../impl/BinaryHeap.h"

TEST_CASE("BinaryHeapTest1")
{
    BinaryHeap heap;

    heap.Insert(5);
    auto heap_vec = heap.GetHeap();
    REQUIRE(heap_vec[1] == 5);
    heap.Insert(6);
    heap_vec = heap.GetHeap();
    REQUIRE(heap_vec[1] == 6);
    REQUIRE(heap_vec[2] == 5);

    heap.Insert(4);
    heap_vec = heap.GetHeap();
    REQUIRE(heap_vec[1] == 6);
    REQUIRE(heap_vec[2] == 5);
    REQUIRE(heap_vec[3] == 4);

    heap.Insert(7);
    heap_vec = heap.GetHeap();
    REQUIRE(heap_vec[1] == 7);
    REQUIRE(heap_vec[2] == 6);
    REQUIRE(heap_vec[3] == 4);
    REQUIRE(heap_vec[4] == 5);
}

TEST_CASE("BinaryHeapTest2")
{
    BinaryHeap heap;

    heap.Insert(4);
    heap.Insert(5);
    heap.Insert(6);

    auto heap_vec = heap.GetHeap();
    REQUIRE(heap_vec[1] == 6);
    REQUIRE(heap_vec[2] == 4);
    REQUIRE(heap_vec[3] == 5);
    
    heap.Insert(7);
    heap_vec = heap.GetHeap();
    REQUIRE(heap_vec[1] == 7);

    auto root = heap.Pop();
    REQUIRE(root == 7);

    heap_vec = heap.GetHeap();
    REQUIRE(heap_vec[1] == 6);
    REQUIRE(heap_vec[2] == 4);
    REQUIRE(heap_vec[3] == 5);



}