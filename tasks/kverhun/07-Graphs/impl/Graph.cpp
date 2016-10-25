#include "Graph.h"

using namespace Graphs;

Graph::Graph(const TVertexList& i_vertexes, const TWeightedEdgeList& i_edges)
    : m_vertexes(i_vertexes)
    , m_edges(i_edges)
{

}

const Graph::TVertexList& Graph::GetVertexes() const
{
    return m_vertexes;
}

const Graph::TWeightedEdgeList& Graph::GetEdges() const
{
    return m_edges;
}

Graph::TWeightedEdgeList Graph::GetEdgesIncidentTo(const TVertex& i_vertex) const
{
    TWeightedEdgeList incident_edges;

    for (const auto& edge : m_edges)
        if (edge.m_from == i_vertex)
            incident_edges.push_back(edge);

    return incident_edges;
}