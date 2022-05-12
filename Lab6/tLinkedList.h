#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include<memory>
#include"figure.h"

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

// ��������������� ���������� ������
template <typename T> class TLinkedList;

// ������������ ���������� ������ ���������� ������� ������������� �������
template <typename T>
std::ostream & operator << ( std::ostream & os, const TLinkedList<T> & list );

// ������������ ���������� ������ ���������� ������� ������������� �������
template <typename T>
bool operator == ( const typename TLinkedList<T>::Iterator & a, 
                   const typename TLinkedList<T>::Iterator & b );
// ������������ ���������� ������ ���������� ������� ������������� �������
template <typename T>
bool operator != ( const typename TLinkedList<T>::Iterator & a, 
                   const typename TLinkedList<T>::Iterator & b );

template <typename T> 
class TLinkedList {
private:
  size_t len;
  TNode<T> * first;
public:
  // ��������� ���������
  class Iterator {
  private:
    // ������� �������� � idx-���� ���� ����������
    TNode<T> * getNode( TNode<T> * first, size_t len, size_t idx );

    // ������� ���� ����������
    TNode<T> * curNode;
    // ������ �������� ����
    size_t curIdx;
    // ����� ���������� ���������
    size_t curLen;

    // ����������� ���������
    Iterator( TNode<T> * first, size_t len, size_t idx );

    // �������� ������������� ���������� ������ �� �������� � ���������� ������
    shared_ptr<T> & operator * () const;
    // �������� �������� ��������� �� �������� � ���������� ������
    shared_ptr<T> operator -> ();
    // ���������� �������� ������������� ��������� ( ++it )
    Iterator & operator ++ ();
    // ����������� �������� ������������� ��������� ( it++ ), ���������� �����
    // ��������� ���������, ���������� �������� �������� �� ���� ������� ������
    Iterator operator ++ ( int );
    // �������� ��������� ����������
    friend bool operator == <T> ( typename const TLinkedList<T>::Iterator & a, 
	                              typename const TLinkedList<T>::Iterator & b );
    friend bool operator != <T> ( typename const TLinkedList<T>::Iterator & a, 
	                              typename const TLinkedList<T>::Iterator & b );
  };


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
