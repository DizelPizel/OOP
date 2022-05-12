#include"tLinkedList.h"
#include"figure.h"


TNode::TNode( const Trapezoid t ) {
  this->t = t;
  next = NULL;
}

TNode * TNode::getNext() {
  return next;
}

void TNode::setNext( TNode * newNext ) {
  next = newNext;
}

Trapezoid & TNode::val() {
  return t;
}

TNode::~TNode() { }

TLinkedList::TLinkedList() {
  first = NULL;
  len = 0;
}

TLinkedList::~TLinkedList() {
  Clear();
}

size_t TLinkedList::Length() const {
  return len;
}

bool TLinkedList::Empty() const {
  return len == 0;
}
  
void TLinkedList::Clear() {
  TNode * tn = first;
  while ( tn != NULL ) {
    TNode * next = tn->getNext();
    delete tn;
    tn = next;
  }
  len = 0;
  first = NULL;
}

const Trapezoid & TLinkedList::First() {
  if ( len == 0 ) {
    throw FigException( "TLinkedList::First: cannot return first element of empty list" );
  }
  return first->val();
}

const Trapezoid & TLinkedList::Last() {
  if ( len == 0 ) {
    throw FigException( "TLinkedList::First: cannot return last element of empty list" );
  }
  return GetItem( len - 1 );
}

const Trapezoid & TLinkedList::GetItem( size_t idx ) {
  if ( idx >= len ) {
    throw FigException( "TLinkedList::GetItem: cannot return nonexistent element of list" );
  }
  TNode * tn = first;
  while ( idx-- > 0 ) {
    TNode * next = tn->getNext();
    tn = next;
  }
  return tn->val();
}

void TLinkedList::InsertFirst( const Trapezoid & trapezoid ) {
  TNode * newNode = new TNode( trapezoid );
  newNode->setNext( first );
  first = newNode;
  len++;
}

void TLinkedList::InsertLast( const Trapezoid & trapezoid ) {
  TNode * newNode = new TNode( trapezoid );
  if ( len == 0 ) {
    first = newNode;
    len++;
    return;
  }
  TNode * tn = first;
  while ( tn->getNext() != NULL ) {
    TNode * next = tn->getNext();
    tn = next;
  }
  tn->setNext( newNode );
  len++;
}

void TLinkedList::RemoveFirst() {
  if ( len == 0 ) {
    throw FigException( "TLinkedList::RemoveFirst: cannot return first element of empty list" );
  }
  TNode * newFirst = first->getNext();
  delete first;
  first = newFirst;
  len--;
}

void TLinkedList::RemoveLast() {
  if ( len == 0 ) {
    throw FigException( "TLinkedList::RemoveFirst: cannot return last element of empty list" );
  } else if ( len == 1 ) {
    delete first;
    first = NULL;
    len = 0;
    return;
  }
  TNode * tn = first;
  while ( tn->getNext()->getNext() != NULL ) {
    TNode * next = tn->getNext();
    tn = next;
  }
  delete tn->getNext();
  tn->setNext( NULL );
  len--;
}

void TLinkedList::Insert( const Trapezoid & trapezoid, size_t position ) {
  if ( position > len ) {
    throw FigException( "TLinkedList::Insert: cannot add new element to too short list" );
  }
  if ( position == 0 ) {
    InsertFirst( trapezoid );
    return;
  } else if ( position == len ) {
    InsertLast( trapezoid );
    return;
  }
  TNode * tn = first;
  while ( position -- > 1 ) {
    TNode * next = tn->getNext();
    tn = next;
  }
  TNode * next = tn->getNext();
  TNode * newNode = new TNode( trapezoid );
  newNode->setNext( next );
  tn->setNext( newNode );
  len++;
}
  
void TLinkedList::Remove( size_t position ) {
  if ( position + 1 > len ) {
    throw FigException( "TLinkedList::Remove: cannot remove nonexistent element" );
  }
  if ( position == 0 ) {
    RemoveFirst();
    return;
  } else if ( position == len-1 ) {
    RemoveLast();
    return;
  }
  TNode * tn = first;
  while ( position -- > 1 ) {
    TNode * next = tn->getNext();
    tn = next;
  }
  TNode * next = tn->getNext();
  tn->setNext( tn->getNext()->getNext() );
  delete next;
  len--;
}

TLinkedList::TLinkedList( const TLinkedList & other ) {
  TLinkedList * o = const_cast<TLinkedList*> ( & other );
  first = NULL;
  len = 0;
  if ( other.Length() == 0 ) 
    return;
  size_t oLen = other.Length();
  for ( size_t i = 0; i < oLen; i++ ) {
    InsertLast( o->GetItem( i ) );
  }
}
  
std::ostream & operator << ( std::ostream & os, const TLinkedList & list ) {
  TNode * tn = list.first;
  size_t len = list.Length();
  if ( len == 0 )
    return os;
  os << tn->val().Area();
  tn = tn->getNext();
  while ( tn != NULL ) {
    os << " -> " << tn->val().Area();
    tn = tn->getNext();
  }
  return os;
}
