#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include "trapezoid.h"

// ����� ���� ������
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
  // ����������� �� ���������
  TLinkedList();
  // ����������� �����������
  TLinkedList( const TLinkedList & other );
  // �����, ������������ ������ ������ ������
  const Trapezoid & First();
  // �����, ������������ ��������� ������ ������
  const Trapezoid & Last();
  // �����, ����������� ������� � ������ ������
  void InsertFirst( const Trapezoid & trapezoid );
  // �����, ����������� ������ � ����� ������
  void InsertLast( const Trapezoid & trapezoid );
  // �����, ����������� ������ � ������������ ����� ������
  void Insert( const Trapezoid & trapezoid, size_t position );
  // �����, ��������� ������ ������� ������
  void RemoveFirst();
  // �����, ��������� ��������� ������� ������
  void RemoveLast();
  // �����, ��������� ������������ ������� ������
  void Remove( size_t position );
  // ����� ��������� ������ ������ �� �������.
  const Trapezoid & GetItem( size_t idx );
  // �����, ����������� ������� ������
  bool Empty() const;
  // �����, ������������ ����� �������
  size_t Length() const;
  // �������� ������ ��� ������� � �������:
  // "S1 -> S2 -> ... -> Sn", ��� Si - ������� ������
  friend std::ostream & operator << ( std::ostream & os, const TLinkedList & list );
  // �����, ��������� ��� �������� ����������,
  // �� ����������� ������������ ��.
  void Clear();
  // ����������
  virtual ~TLinkedList();
};

#endif /* TLINKEDLIST_H */
