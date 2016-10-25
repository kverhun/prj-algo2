#include "GraphAlgorithms.h"

#include <map>
#include <queue>
#include <algorithm>
#include <tuple>

namespace Graphs
{

    std::pair<TPath, double> GetShortestPathDijkstra(const Graph& i_graph, const Graph::TVertex& i_from, const Graph::TVertex& i_to)
    {
        TPath path;

        double length = 0.;

        TPath visited_vertexes;
        
        using TQueueElement = std::tuple<
            Graph::TVertex,               // vertex "to"
            double,                       // current distance
            Graph::TVertex                // vertex "from"
        >;

        auto compare_vertexes_with_distance = [](const TQueueElement& i_left, const TQueueElement& i_right)
        {
            return std::get<1>(i_left) > std::get<1>(i_right);
        };
        std::priority_queue<TQueueElement, std::vector<TQueueElement>, decltype(compare_vertexes_with_distance)> queue(compare_vertexes_with_distance);
        queue.push(TQueueElement(i_from, 0, i_from));

        auto visit = [&](const Graph::TVertex& i_vertex, double i_current_distance)
        {
            auto incident_edges = i_graph.GetEdgesIncidentTo(i_vertex);
            for (const auto& edge : incident_edges)
            {
                if (std::count(visited_vertexes.begin(), visited_vertexes.end(), edge.m_to) == 0)
                {
                    queue.push(TQueueElement(edge.m_to, i_current_distance + edge.m_weight, i_vertex));
                }
            }
            visited_vertexes.push_back(i_vertex);
        };

        std::map<Graph::TVertex, double> distances_to;

        while (!queue.empty())
        {
            auto next_vertex_to_visit = queue.top();
            distances_to[std::get<0>(next_vertex_to_visit)] = std::get<1>(next_vertex_to_visit);
            
            queue.pop();
            if (std::count(visited_vertexes.begin(), visited_vertexes.end(), std::get<0>(next_vertex_to_visit)) == 0)
            {
                visit(std::get<0>(next_vertex_to_visit), std::get<1>(next_vertex_to_visit));
            }
        }

        return std::make_pair(path, distances_to[i_to]);
    }
}