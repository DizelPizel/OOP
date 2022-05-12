#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include<cstdlib>
#include<memory>
#include"tStack.h"

using namespace std;

// ����� ��������� ��� ��������� �������� ������.
// ������ �������������� ��������� �������������� �������.
// ������ �������� ������� �� �������������� ����� ��������.
// ��� ���������� ��������� �������� ���������� ��������� ����.
class Allocator {
  // ������ ����� ������ (� ��������)
  size_t blockSize;
  // ������ ������� ������ (� ������)
  size_t chunkSize;
  // ���� ���������� �� ��������� �������
  TStack<void *> * freeChunks;
  // ���� ���������� �� ������� �������
  TStack<void *> * usedChunks;
  // ���� ���������� �� ���������� ����� ������
  TStack<void *> * usedBlocks;

public:
  // �����������
  Allocator( size_t blockSize, size_t chunkSize );
  // ����������
  ~Allocator();
  // ���������� ������� ������
  void * allocate();
  // ������������ ������� ������
  void deallocate( void * p );
  friend bool operator == ( const Allocator & a1, const Allocator & a2 );
  friend bool operator != ( const Allocator & a1, const Allocator & a2 );
};

bool operator == ( const Allocator & a1, const Allocator & a2 );
bool operator != ( const Allocator & a1, const Allocator & a2 );


#endif /* ALLOCATOR_H */
