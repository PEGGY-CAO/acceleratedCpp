#ifndef INTEGER_CONTAINER_IMPL_HPP_
#define INTEGER_CONTAINER_IMPL_HPP_

#include "integer_container.hpp"
#include <set>

class IntegerContainerImpl : public IntegerContainer {
public:
    int Add(int value) override;
    bool Delete(int value) override;
    std::optional<int> GetMedian() override;
    
private:
    std::multiset<int> backup;

};

#endif  // INTEGER_CONTAINER_IMPL_HPP_
