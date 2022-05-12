#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include<memory>
#include"figure.h"

using namespace std;

// Класс узла списка
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

// Предварительное объявление класса
template <typename T> class TLinkedList;

// Предваряющее объявление класса объявление шаблона дружественной функции
template <typename T>
std::ostream & operator << ( std::ostream & os, const TLinkedList<T> & list );

// Предваряющее объявление класса объявление шаблона дружественной функции
template <typename T>
bool operator == ( const typename TLinkedList<T>::Iterator & a, 
                   const typename TLinkedList<T>::Iterator & b );
// Предваряющее объявление класса объявление шаблона дружественной функции
template <typename T>
bool operator != ( const typename TLinkedList<T>::Iterator & a, 
                   const typename TLinkedList<T>::Iterator & b );

template <typename T> 
class TLinkedList {
private:
  size_t len;
  TNode<T> * first;
public:
  // Структура итератора
  class Iterator {
  private:
    // Функция перехода к idx-тому узлу контейнера
    TNode<T> * getNode( TNode<T> * first, size_t len, size_t idx );

    // Текущий узел контейнера
    TNode<T> * curNode;
    // Индекс текущего узла
    size_t curIdx;
    // Общее количество элементов
    size_t curLen;

    // Конструктор итератора
    Iterator( TNode<T> * first, size_t len, size_t idx );

    // Операция разыменования возвращает ссылку на хранимый в контейнере объект
    shared_ptr<T> & operator * () const;
    // Операция возврата указателя на хранимый в контейнере объект
    shared_ptr<T> operator -> ();
    // Префиксная операция инкрементации итератора ( ++it )
    Iterator & operator ++ ();
    // Постфиксная операция инкрементации итератора ( it++ ), возвращает копию
    // исходного итератора, передвигая исходный итератор на одну позицию вперед
    Iterator operator ++ ( int );
    // Операции сравнения итераторов
    friend bool operator == <T> ( typename const TLinkedList<T>::Iterator & a, 
	                              typename const TLinkedList<T>::Iterator & b );
    friend bool operator != <T> ( typename const TLinkedList<T>::Iterator & a, 
	                              typename const TLinkedList<T>::Iterator & b );
  };


  // Конструктор по умолчанию
  TLinkedList();
  // Конструктор копирования
  TLinkedList( const TLinkedList & other );
  // Метод, возвращающий первую фигуру списка
  const shared_ptr<T> First();
  // Метод, возвращающий последнюю фигуру списка
  const shared_ptr<T> Last();
  // Метод, добавляющий элемент в начало списка
  void InsertFirst( const T & t );
  void InsertFirst( const shared_ptr<T> t );
  // Метод, добавляющий фигуру в конец списка
  void InsertLast( const T & t );
  void InsertLast( const shared_ptr<T> t );
  // Метод, добавляющий фигуру в произвольное место списка
  void Insert( const T & t, size_t position );
  void Insert( const shared_ptr<T> t, size_t position );
  // Метод, удаляющий первый элемент списка
  void RemoveFirst();
  // Метод, удаляющий последний элемент списка
  void RemoveLast();
  // Метод, удаляющий произвольный элемент списка
  void Remove( size_t position );
  // Метод получения фигуры списка по индексу.
  const shared_ptr<T> GetItem( size_t idx );
  // Метод, проверяющий пустоту списка
  bool Empty() const;
  // Метод, возвращающий длину массива
  size_t Length() const;
  // Оператор вывода для массива в формате:
  // "S1 -> S2 -> ... -> Sn", где Si - площадь фигуры
  friend std::ostream & operator << <T> ( std::ostream & os, const TLinkedList<T> & list );
  // Метод, удаляющий все элементы контейнера,
  // но позволяющий пользоваться им.
  void Clear();
  // Деструктор
  virtual ~TLinkedList();
};

#endif /* TLINKEDLIST_H */
