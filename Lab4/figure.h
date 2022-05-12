#ifndef FIGURE_H
#define FIGURE_H

#include<cstdlib>
#include<iostream>
#include<cmath>

// �������������� �����, �� ������ ������� MACHINE_ZERO
// ��������� ������� ����
#define MACHINE_ZERO 1e-11

using namespace std;

// ����������, ������������� ��� ������������ ��������� � ��������
class FigException {
public:
  string message;
  FigException( string m ) {
    message = m;
  }
};

// ��������������� �������, ����������� ����� ������� ��
// (x1, y1) �� (x2, y2)
double getLength( double x1, double y1, double x2, double y2 ); 

// ��������������� �������, ����������� �������������� �������� 
// (x1, y1) � (x2, y2)
bool isVectorsParallel( double x1, double y1, double x2, double y2 );

// �������� ��������� ���� �����
bool isDoubleZero( double a );

// �������� ��������� ���� �����
bool isDoublesEqual( double a, double b );

// ���������� ��������������� ������� � ������������
// (x0, y0), (x1, y1), (x2, y2). ���� ����� ������ ��
// ������� ������� - ������� �������������.
double getOrArea( double x0, double y0, double x1, double y1, 
                  double x2, double y2 ); 

// �����������, ������������ �� �������������� �������
// (x0,y0)-(x1,y1) � (x2,y2)-(x3,y3)
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
