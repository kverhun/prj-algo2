#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "../impl/Graph.h"
#include "../impl/GraphAlgorithms.h"

using namespace Graphs;

TEST_CASE("ShortestPath_Dijkstra_Test1")
{
    Graph graph = Graph({ 1, 2 }, { {1, 2, 2.} });

    auto shortest_path = GetShortestPathDijkstra(graph, 1, 2);
    REQUIRE(2. == shortest_path.second);
}

TEST_CASE("ShortersPath_Dijkstra_Test2")
{
    Graph graph = Graph(
        { 1, 2, 3, 4 },
        { {1, 2, 50.}, {1, 3, 1.}, {2, 4, 20.}, {3, 4, 100.} }
    );

    auto sh_path_12 = GetShortestPathDijkstra(graph, 1, 2);
    REQUIRE(50. == sh_path_12.second);
    
    auto sh_path_13 = GetShortestPathDijkstra(graph, 1, 3);
    REQUIRE(1. == sh_path_13.second);
    
    auto sh_path_24 = GetShortestPathDijkstra(graph, 2, 4);
    REQUIRE(20. == sh_path_24.second);

    auto sh_path_34 = GetShortestPathDijkstra(graph, 3, 4);
    REQUIRE(100. == sh_path_34.second);

    auto sh_path_14 = GetShortestPathDijkstra(graph, 1, 4);
    REQUIRE(70. == sh_path_14.second);
}

TEST_CASE("ShortestPath_Dijkstra_Test3")
{
    Graph graph = Graph(
        {1, 2, 3, 4}, 
        { {1, 2, 10}, {1, 3, 50}, {2, 3, 25}, {2, 4, 80}, {3, 4, 20} }
    );

    auto sh_path_14 = GetShortestPathDijkstra(graph, 1, 4);
    REQUIRE(55. == sh_path_14.second);

    auto sh_path_24 = GetShortestPathDijkstra(graph, 2, 4);
    REQUIRE(45. == sh_path_24.second);
}

TEST_CASE("ShortestPath_Dijkstra_Test4")
{
    Graph graph = Graph(
        {1, 2, 3, 4, 5, 6},
        { {1, 2, 5}, {1, 4, 15}, {1, 5, 60}, {2, 3, 5}, {3, 4, 10}, {5, 4, 5}, {4, 6, 100}, {5, 6, 20} }
    );

    auto sh_path_16 = GetShortestPathDijkstra(graph, 1, 6);
    auto sh_path_14 = GetShortestPathDijkstra(graph, 1, 4);
    auto sh_path_46 = GetShortestPathDijkstra(graph, 4, 6);
    auto sh_path_56 = GetShortestPathDijkstra(graph, 5, 6);

    REQUIRE(80. == sh_path_16.second);
    REQUIRE(15. == sh_path_14.second);
    REQUIRE(100. == sh_path_46.second);
    REQUIRE(20. == sh_path_56.second);

}