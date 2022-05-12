#ifndef FIGURE_H
#define FIGURE_H

#include<cstdlib>
#include<iostream>
#include<cmath>

// Действительные числа, по модулю меньшие MACHINE_ZERO
// считаются равными нулю
#define MACHINE_ZERO 1e-11

using namespace std;

// Исключение, выбрасываемое при недопустимых операциях с фигурами
class FigException {
public:
  string message;
  FigException( string m ) {
    message = m;
  }
};

// Вспомогательная функция, вычисляющая длину отрезка от
// (x1, y1) до (x2, y2)
double getLength( double x1, double y1, double x2, double y2 ); 

// Вспомогательная функция, проверяющая параллельность векторов 
// (x1, y1) и (x2, y2)
bool isVectorsParallel( double x1, double y1, double x2, double y2 );

// Проверка равенства нулю числа
bool isDoubleZero( double a );

// Проверка равенства двух чисел
bool isDoublesEqual( double a, double b );

// Вычисление ориентированной площади с координатами
// (x0, y0), (x1, y1), (x2, y2). Если обход вершин по
// часовой стрелке - площадь положительная.
double getOrArea( double x0, double y0, double x1, double y1, 
                  double x2, double y2 ); 

// Определение, пересекаются ли непараллельные отрезки
// (x0,y0)-(x1,y1) и (x2,y2)-(x3,y3)
bool isIntersect( double x0, double y0, double x1, double y1, 
                  double x2, double y2, double x3, double y3 );

class Figure {
public:
  virtual size_t VertexesNumber() const = 0;
  virtual double Area() const = 0;
  virtual void Print( std::ostream & os ) const = 0;
  virtual ~Figure();
};

#endif /* FIGURE_H */
