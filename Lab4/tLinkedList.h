#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include<memory>

using namespace std;

//  ласс узла списка
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
  //  онструктор по умолчанию
  TLinkedList();
  //  онструктор копировани€
  TLinkedList( const TLinkedList & other );
  // ћетод, возвращающий первую фигуру списка
  const shared_ptr<T> First();
  // ћетод, возвращающий последнюю фигуру списка
  const shared_ptr<T> Last();
  // ћетод, добавл€ющий элемент в начало списка
  void InsertFirst( const T & t );
  void InsertFirst( const shared_ptr<T> t );
  // ћетод, добавл€ющий фигуру в конец списка
  void InsertLast( const T & t );
  void InsertLast( const shared_ptr<T> t );
  // ћетод, добавл€ющий фигуру в произвольное место списка
  void Insert( const T & t, size_t position );
  void Insert( const shared_ptr<T> t, size_t position );
  // ћетод, удал€ющий первый элемент списка
  void RemoveFirst();
  // ћетод, удал€ющий последний элемент списка
  void RemoveLast();
  // ћетод, удал€ющий произвольный элемент списка
  void Remove( size_t position );
  // ћетод получени€ фигуры списка по индексу.
  const shared_ptr<T> GetItem( size_t idx );
  // ћетод, провер€ющий пустоту списка
  bool Empty() const;
  // ћетод, возвращающий длину массива
  size_t Length() const;
  // ќператор вывода дл€ массива в формате:
  // "S1 -> S2 -> ... -> Sn", где Si - площадь фигуры
  friend std::ostream & operator << <T> ( std::ostream & os, const TLinkedList<T> & list );
  // ћетод, удал€ющий все элементы контейнера,
  // но позвол€ющий пользоватьс€ им.
  void Clear();
  // ƒеструктор
  virtual ~TLinkedList();
};

#endif /* TLINKEDLIST_H */
