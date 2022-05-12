#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include<memory>
#include "trapezoid.h"

// ����� ���� ������
class TNode {
private:
  shared_ptr<Trapezoid> t;
  TNode * next;
public:
  TNode( const Trapezoid & t );
  TNode( const shared_ptr<Trapezoid> t );
  ~TNode();
  TNode * getNext();
  void setNext( TNode * newNext );
  shared_ptr<Trapezoid> & val();
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
  const shared_ptr<Trapezoid> First();
  // �����, ������������ ��������� ������ ������
  const shared_ptr<Trapezoid> Last();
  // �����, ����������� ������� � ������ ������
  void InsertFirst( const Trapezoid & trapezoid );
  void InsertFirst( const shared_ptr<Trapezoid> trapezoid );
  // �����, ����������� ������ � ����� ������
  void InsertLast( const Trapezoid & trapezoid );
  void InsertLast( const shared_ptr<Trapezoid> trapezoid );
  // �����, ����������� ������ � ������������ ����� ������
  void Insert( const Trapezoid & trapezoid, size_t position );
  void Insert( const shared_ptr<Trapezoid> trapezoid, size_t position );
  // �����, ��������� ������ ������� ������
  void RemoveFirst();
  // �����, ��������� ��������� ������� ������
  void RemoveLast();
  // �����, ��������� ������������ ������� ������
  void Remove( size_t position );
  // ����� ��������� ������ ������ �� �������.
  const shared_ptr<Trapezoid> GetItem( size_t idx );
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
