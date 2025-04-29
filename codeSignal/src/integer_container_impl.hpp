#ifndef INTEGER_CONTAINER_IMPL_HPP_
#define INTEGER_CONTAINER_IMPL_HPP_

#include "integer_container.hpp"
#include <set>

class IntegerContainerImpl : public IntegerContainer {
    public:
    int Add(int value);
    bool Delete(int value);
    std::optional<int> GetMedian();
    
    private:
    std::set<int> backup;
};

#endif  // INTEGER_CONTAINER_IMPL_HPP_
