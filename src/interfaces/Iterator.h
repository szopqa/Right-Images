#pragma once

template <typename T>
class Iterator
{
protected:
  T currentElement;
public:
  virtual T getNext() = 0;
  virtual bool hasNext() = 0;
};
