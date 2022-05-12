#ifndef TSTACK_H
#define TSTACK_H

#include<cstdlib>
using namespace std;

template<typename T>
class TStack {
  size_t len;
  size_t blockLen;
  size_t capacity;
  T * array;
public:
  TStack( size_t blockLen );
  ~TStack();
  size_t Length() const;
  T & top();
  void push( T & t );
  void pop();
  void print();
};

#endif /* TSTACK_H */
