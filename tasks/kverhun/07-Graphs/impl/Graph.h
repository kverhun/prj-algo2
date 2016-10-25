#pragma once

#include "_Library.h"

#include <vector>

namespace Graphs
{
    class GRAPHS_API Graph
    {
    public:
        using TVertex = size_t;

        struct WeigtedEdge
        {
            TVertex m_from;
            TVertex m_to;
            double m_weight;
        };

        using TVertexList = std::vector<TVertex>;
        using TWeightedEdgeList = std::vector<WeigtedEdge>;

    public:
        Graph(const TVertexList& i_vertexes, const TWeightedEdgeList& i_edges);

        const TVertexList& GetVertexes() const;
        const TWeightedEdgeList& GetEdges() const;

        TWeightedEdgeList GetEdgesIncidentTo(const TVertex& i_vertex) const;

    private:
        TVertexList m_vertexes;
        TWeightedEdgeList m_edges;
    };
}