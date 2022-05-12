#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include<memory>

using namespace std;

// ����� ���� ������
template <typename T> 
class TNode {
private:
  shared_ptr<T> t;
  TNode<T> * next;
public:
  TNode( const T & t );
  TNode( const shared_ptr<T> t );
  ~TNode();
  TNode<T> * getNext();
  void setNext( TNode<T> * newNext );
  shared_ptr<T> & val();
};

template <typename T> class TLinkedList;

template <typename T>
std::ostream & operator << ( std::ostream & os, const TLinkedList<T> & list );

template <typename T> 
class TLinkedList {
private:
  size_t len;
  TNode<T> * first;
public:
  // ����������� �� ���������
  TLinkedList();
  // ����������� �����������
  TLinkedList( const TLinkedList & other );
  // �����, ������������ ������ ������ ������
  const shared_ptr<T> First();
  // �����, ������������ ��������� ������ ������
  const shared_ptr<T> Last();
  // �����, ����������� ������� � ������ ������
  void InsertFirst( const T & t );
  void InsertFirst( const shared_ptr<T> t );
  // �����, ����������� ������ � ����� ������
  void InsertLast( const T & t );
  void InsertLast( const shared_ptr<T> t );
  // �����, ����������� ������ � ������������ ����� ������
  void Insert( const T & t, size_t position );
  void Insert( const shared_ptr<T> t, size_t position );
  // �����, ��������� ������ ������� ������
  void RemoveFirst();
  // �����, ��������� ��������� ������� ������
  void RemoveLast();
  // �����, ��������� ������������ ������� ������
  void Remove( size_t position );
  // ����� ��������� ������ ������ �� �������.
  const shared_ptr<T> GetItem( size_t idx );
  // �����, ����������� ������� ������
  bool Empty() const;
  // �����, ������������ ����� �������
  size_t Length() const;
  // �������� ������ ��� ������� � �������:
  // "S1 -> S2 -> ... -> Sn", ��� Si - ������� ������
  friend std::ostream & operator << <T> ( std::ostream & os, const TLinkedList<T> & list );
  // �����, ��������� ��� �������� ����������,
  // �� ����������� ������������ ��.
  void Clear();
  // ����������
  virtual ~TLinkedList();
};

#endif /* TLINKEDLIST_H */
