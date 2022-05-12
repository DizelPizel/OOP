#include"allocator.h"
#include"figure.h"






// �����������
Allocator::Allocator( size_t blockSize, size_t chunkSize ) {
  if ( blockSize == 0 ) {
    throw FigException( "Allocator with zero block size" );
  }
  if ( chunkSize == 0 ) {
    throw FigException( "Allocator with zero chunk size" );
  }
  this->blockSize = blockSize;
  this->chunkSize = chunkSize;

  // ������� ����� ��������. ��� ���������� ������
  // ��� �������� ��������-�������� ������ ����� �����������
  // �������� �� blockSize ��������.
  freeChunks = new TStack<void *>( blockSize );
  usedChunks = new TStack<void *>( blockSize );
  // ������� ���� ������������ ������
  usedBlocks = new TStack<void *>( 1 );

  // ������� ������ ���� �� blockSize ��������
  void * block = new char[ blockSize * chunkSize ];
  if ( block == NULL ) {
    throw FigException( "Not enough memory" );
  }
  // ��������� � ������ ��������� �������� ��� blockSize ��������
  // ������ �����
  for ( size_t i = 0; i < blockSize; i++ ) {
    void * p = static_cast<void *> ( static_cast<char *>( block ) + i * chunkSize );
    freeChunks->push( p );
  }
  // ��� ���� ��������� � ������ ������������ ������
  usedBlocks->push( block );
}

// ����������
Allocator::~Allocator() {
  // ����������� ������ ���� ������������ ������
  while ( usedBlocks->Length() > 0 ) {
    delete [] static_cast<char *>( usedBlocks->top() );
    usedBlocks->pop();
  }
  // ������� �����
  delete freeChunks;
  delete usedChunks;
  delete usedBlocks;
}


// ���������� ������� ������
void * Allocator::allocate() {
  // ���� ���������� ������� ������ ���
  if ( freeChunks->Length() == 0 ) {
    // ������� ����� ���� �� blockSize ��������
    void * block = new char[ blockSize * chunkSize ];
    if ( block == NULL ) {
      throw FigException( "Not enough memory" );
    }
    // ��������� � ������ ��������� �������� ��� blockSize ��������
    // ������ �����
    for ( size_t i = 0; i < blockSize; i++ ) {
      void * p = static_cast<void *>( static_cast<char *> ( block ) + i * chunkSize );
      freeChunks->push( p );
    }
    // ��� ���� ��������� � ������ ������������ ������
    usedBlocks->push( block );
  }
  // �������� ������� �� ����� ���������
  void * fChunk = freeChunks->top();
  // ������� ������� �� ����� ���������
  freeChunks->pop();
  // ��������� ������� � ���� �������
  usedChunks->push( fChunk );
  // ������� �������
  return fChunk;
}

// ������������ ������� ������
void Allocator::deallocate( void * p ) {
  // ��������������� ���� ��� ���������� �������� p �� ������ ������� ��������
  TStack<void * > tmpStack( blockSize );
  // ���� ����������� �������
  bool foundChunk = false;

  // ��������� ������� �� ������ ������� 
  while ( usedChunks->Length() > 0 ) {
    void * uChunk = usedChunks->top();
    usedChunks->pop();
    // ���� ����������� ������� ��������� � �������������
    if ( uChunk == p ) {
      // ��������� ��� � ����� ��������� ��������
      freeChunks->push( uChunk );
      // ������� ������
      foundChunk = true;
      // ��������� ����
      break;
    }
    // ��������� ������� �� ��������� ����
    tmpStack.push( uChunk );
  }
  if ( ! foundChunk ) {
    throw FigException( "Allocator::deallocate - freeing not allocated chunk of memory" );
  }

  // ���������� ���������� ����� �������� ������� � ���� ������������
  while ( tmpStack.Length() > 0 ) {
    void * uChunk = tmpStack.top();
    tmpStack.pop();
    usedChunks->push( uChunk );
  }
}

bool operator == ( const Allocator & a1, const Allocator & a2 ) {
  return true;
}
bool operator != ( const Allocator & a1, const Allocator & a2 ) {
  return false;
}
