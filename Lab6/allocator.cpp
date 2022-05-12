#include"allocator.h"
#include"figure.h"






// Конструктор
Allocator::Allocator( size_t blockSize, size_t chunkSize ) {
  if ( blockSize == 0 ) {
    throw FigException( "Allocator with zero block size" );
  }
  if ( chunkSize == 0 ) {
    throw FigException( "Allocator with zero chunk size" );
  }
  this->blockSize = blockSize;
  this->chunkSize = chunkSize;

  // Создаем стеки кусочков. При исчерпании памяти
  // для хранения объектов-кусочков память будет добавляться
  // наборами по blockSize объектов.
  freeChunks = new TStack<void *>( blockSize );
  usedChunks = new TStack<void *>( blockSize );
  // Создаем стек используемых блоков
  usedBlocks = new TStack<void *>( 1 );

  // Создаем первый блок из blockSize кусочков
  void * block = new char[ blockSize * chunkSize ];
  if ( block == NULL ) {
    throw FigException( "Not enough memory" );
  }
  // Добавляем к набору свободных кусочков все blockSize кусочков
  // нового блока
  for ( size_t i = 0; i < blockSize; i++ ) {
    void * p = static_cast<void *> ( static_cast<char *>( block ) + i * chunkSize );
    freeChunks->push( p );
  }
  // Сам блок добавляем к списку используемых блоков
  usedBlocks->push( block );
}

// Деструктор
Allocator::~Allocator() {
  // Освобождаем память всех используемых блоков
  while ( usedBlocks->Length() > 0 ) {
    delete [] static_cast<char *>( usedBlocks->top() );
    usedBlocks->pop();
  }
  // Удаляем стеки
  delete freeChunks;
  delete usedChunks;
  delete usedBlocks;
}


// Выделитель кусочка памяти
void * Allocator::allocate() {
  // Если свободного кусочка памяти нет
  if ( freeChunks->Length() == 0 ) {
    // Создаем новый блок из blockSize кусочков
    void * block = new char[ blockSize * chunkSize ];
    if ( block == NULL ) {
      throw FigException( "Not enough memory" );
    }
    // Добавляем к набору свободных кусочков все blockSize кусочков
    // нового блока
    for ( size_t i = 0; i < blockSize; i++ ) {
      void * p = static_cast<void *>( static_cast<char *> ( block ) + i * chunkSize );
      freeChunks->push( p );
    }
    // Сам блок добавляем к списку используемых блоков
    usedBlocks->push( block );
  }
  // Получаем кусочек из стека свободных
  void * fChunk = freeChunks->top();
  // Удаляем кусочек из стека свободных
  freeChunks->pop();
  // Добавляем кусочек в стек занятых
  usedChunks->push( fChunk );
  // Возврат кусочка
  return fChunk;
}

// Освободитель кусочка памяти
void Allocator::deallocate( void * p ) {
  // Вспомогательный стек для извлечения элемента p из списка занятых кусочков
  TStack<void * > tmpStack( blockSize );
  // Флаг обнаружения кусочка
  bool foundChunk = false;

  // Извлекаем кусочки из списка занятых 
  while ( usedChunks->Length() > 0 ) {
    void * uChunk = usedChunks->top();
    usedChunks->pop();
    // Если извлеченный кусочек совпадает с освобождаемым
    if ( uChunk == p ) {
      // Сохраняем его в стеке свободных кусочков
      freeChunks->push( uChunk );
      // Кусочек найден
      foundChunk = true;
      // Прерываем цикл
      break;
    }
    // Добавляем кусочек во временный стек
    tmpStack.push( uChunk );
  }
  if ( ! foundChunk ) {
    throw FigException( "Allocator::deallocate - freeing not allocated chunk of memory" );
  }

  // Содержимое временного стека помещаем обратно в стек используемых
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
