#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include<cstdlib>
#include<memory>
#include"tStack.h"

using namespace std;

// Класс аллокатор для выделения кусочков памяти.
// Память распределяется кусочками фиксированного размера.
// Память хранится блоками из фиксированного числа кусочков.
// При исчерпании свободных кусочков выделяется очередной блок.
class Allocator {
  // Размер блока памяти (в кусочках)
  size_t blockSize;
  // Размер кусочка памяти (в байтах)
  size_t chunkSize;
  // Стек указателей на свободные кусочки
  TStack<void *> * freeChunks;
  // Стек указателей на занятые кусочки
  TStack<void *> * usedChunks;
  // Стек указателей на выделенные блоки памяти
  TStack<void *> * usedBlocks;

public:
  // Конструктор
  Allocator( size_t blockSize, size_t chunkSize );
  // Деструктор
  ~Allocator();
  // Выделитель кусочка памяти
  void * allocate();
  // Освободитель кусочка памяти
  void deallocate( void * p );
  friend bool operator == ( const Allocator & a1, const Allocator & a2 );
  friend bool operator != ( const Allocator & a1, const Allocator & a2 );
};

bool operator == ( const Allocator & a1, const Allocator & a2 );
bool operator != ( const Allocator & a1, const Allocator & a2 );


#endif /* ALLOCATOR_H */
