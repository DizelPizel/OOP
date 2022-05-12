#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include "trapezoid.h"

//  ласс узла списка
class TNode {
private:
  Trapezoid t;
  TNode * next;
public:
  TNode( const Trapezoid t );
  ~TNode();
  TNode * getNext();
  void setNext( TNode * newNext );
  Trapezoid & val();
};

class TLinkedList {
private:
  size_t len;
  TNode * first;
public:
  //  онструктор по умолчанию
  TLinkedList();
  //  онструктор копировани€
  TLinkedList( const TLinkedList & other );
  // ћетод, возвращающий первую фигуру списка
  const Trapezoid & First();
  // ћетод, возвращающий последнюю фигуру списка
  const Trapezoid & Last();
  // ћетод, добавл€ющий элемент в начало списка
  void InsertFirst( const Trapezoid & trapezoid );
  // ћетод, добавл€ющий фигуру в конец списка
  void InsertLast( const Trapezoid & trapezoid );
  // ћетод, добавл€ющий фигуру в произвольное место списка
  void Insert( const Trapezoid & trapezoid, size_t position );
  // ћетод, удал€ющий первый элемент списка
  void RemoveFirst();
  // ћетод, удал€ющий последний элемент списка
  void RemoveLast();
  // ћетод, удал€ющий произвольный элемент списка
  void Remove( size_t position );
  // ћетод получени€ фигуры списка по индексу.
  const Trapezoid & GetItem( size_t idx );
  // ћетод, провер€ющий пустоту списка
  bool Empty() const;
  // ћетод, возвращающий длину массива
  size_t Length() const;
  // ќператор вывода дл€ массива в формате:
  // "S1 -> S2 -> ... -> Sn", где Si - площадь фигуры
  friend std::ostream & operator << ( std::ostream & os, const TLinkedList & list );
  // ћетод, удал€ющий все элементы контейнера,
  // но позвол€ющий пользоватьс€ им.
  void Clear();
  // ƒеструктор
  virtual ~TLinkedList();
};

#endif /* TLINKEDLIST_H */
