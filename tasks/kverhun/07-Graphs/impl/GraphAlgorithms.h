#pragma once

#include "_Library.h"

#include "Graph.h"

namespace Graphs
{
    using TPath = std::vector<Graph::TVertex>;

    std::pair<TPath, double> GRAPHS_API GetShortestPathDijkstra(const Graph& i_graph, const Graph::TVertex& i_from, const Graph::TVertex& i_to);

}