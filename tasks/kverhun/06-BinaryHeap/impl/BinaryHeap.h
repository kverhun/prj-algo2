#pragma once

#include "_Library.h"

#include <vector>

class BINARYHEAP_API BinaryHeap
{
public:
    BinaryHeap(size_t i_initial_size = 0);

    void Insert(size_t i_element);
    
    size_t Pop();

    std::vector<size_t> GetHeap() const;

private:
    void _FixupOrderAsParent(size_t i_element_index);
    void _FixupOrderAsChild(size_t i_element_index);

    std::pair<size_t, size_t> _GetChildrenIndexes(size_t i_element_index) const;
    size_t _GetParentIndex(size_t i_element_index) const;

private:
    std::vector<size_t> m_elements;
};
