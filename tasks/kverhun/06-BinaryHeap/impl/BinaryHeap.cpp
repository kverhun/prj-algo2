#include "BinaryHeap.h"

#include <algorithm>
#include <limits.h>

BinaryHeap::BinaryHeap(size_t i_size)
    : m_elements(i_size + 1, std::numeric_limits<size_t>::max())
{
}

void BinaryHeap::Insert(size_t i_element)
{
    m_elements.push_back(i_element);
    _FixupOrderAsChild(m_elements.size() - 1);
}

size_t BinaryHeap::Pop()
{
    auto root_element = m_elements[1];
    m_elements[1] = m_elements.back();
    m_elements.erase(m_elements.end() - 1, m_elements.end());
    _FixupOrderAsParent(1);
    return root_element;
}

std::vector<size_t> BinaryHeap::GetHeap() const
{
    return m_elements;
}

std::pair<size_t, size_t> BinaryHeap::_GetChildrenIndexes(size_t i_element_index) const
{
    return std::make_pair(i_element_index * 2, i_element_index * 2 + 1);
}

size_t BinaryHeap::_GetParentIndex(size_t i_element_index) const
{
    return i_element_index / 2;
}

void BinaryHeap::_FixupOrderAsParent(size_t i_element_index)
{
    auto heap_size = m_elements.size();

    auto children_indexes = _GetChildrenIndexes(i_element_index);
    while (children_indexes.first < heap_size)
    {
        auto max_children_index = children_indexes.first;
        if (children_indexes.second < heap_size && m_elements[children_indexes.first] < m_elements[children_indexes.second])
            max_children_index = children_indexes.second;

        if (m_elements[i_element_index] < m_elements[max_children_index])
            std::swap(m_elements[i_element_index], m_elements[max_children_index]);

        i_element_index = max_children_index;
        children_indexes = _GetChildrenIndexes(i_element_index);
    }
}

void BinaryHeap::_FixupOrderAsChild(size_t i_element_index)
{
    while (i_element_index > 1 && m_elements[i_element_index] > m_elements[_GetParentIndex(i_element_index)])
    {
        std::swap(m_elements[i_element_index], m_elements[_GetParentIndex(i_element_index)]);
        i_element_index = _GetParentIndex(i_element_index);
    }
}