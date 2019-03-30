#pragma once
#include "Iterator.cpp"

template <typename T>
class Iterable
{
public:
  Iterable();
  virtual Iterator<T>* getIterator() = 0;
};

template <typename T>
Iterable<T>::Iterable(){ }
