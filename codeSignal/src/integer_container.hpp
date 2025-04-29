#ifndef INTEGER_CONTAINER_HPP_
#define INTEGER_CONTAINER_HPP_

#include <optional>

/**
 * `IntegerContainer` interface.
 */
struct IntegerContainer {

  /**
   * Should add the specified integer `value` to the container
   * and return the number of integers in the container after the
   * addition.
   */
  virtual int Add(int value) {
    // Default implementation
    return 0;
  }

  /**
   * Should attempt to remove the specified integer `value` from
   * the container.
   * If the `value` is present in the container, remove it and
   * return `true`, otherwise, return `false`.
   */
  virtual bool Delete(int value) {
    // Default implementation
    return false;
  }

  /**
   * Should return the median integer - the integer in the middle
   * of the sequence after all integers stored in the container
   * are sorted in ascending order.
   * If the length of the sequence is even, the leftmost integer
   * from the two middle integers should be returned.
   * If the container is empty, this method should return
   * `std::nullopt`.
   */
  virtual std::optional<int> GetMedian() {
    // Default implementation
    return std::nullopt;
  }

  virtual inline ~IntegerContainer() = 0;
};
IntegerContainer::~IntegerContainer() = default;

#endif  // INTEGER_CONTAINER_HPP_
