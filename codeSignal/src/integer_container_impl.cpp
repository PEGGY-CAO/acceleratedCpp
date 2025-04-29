#include "integer_container_impl.hpp"

// TODO: implement interface methods here

int IntegerContainerImpl::Add(int value) {
    backup.insert(value);
    return backup.size();
}

bool IntegerContainerImpl::Delete(int value) {
    if (backup.size() == 0 || backup.find(value) == backup.end()) {
        return false;
    }
    auto it = backup.find(value);
    backup.erase(it);
    return true;
}

std::optional<int> IntegerContainerImpl::GetMedian() {
    if (backup.size() == 0) {
        return std::nullopt;
    }
    int index;
    if (backup.size() % 2 == 0) {
        index = backup.size() / 2 - 1;
    } else {
        index = backup.size() / 2;
    }
    
    auto it = backup.begin();
    std::advance(it, index);
    int x = *it;
    return x;
}