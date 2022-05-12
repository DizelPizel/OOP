#include"figure.h"

// ��������������� �������, ����������� ����� ������� ��
// (x1, y1) �� (x2, y2)
double getLength( double x1, double y1, double x2, double y2 ) {
  return sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) );
}

// ��������������� �������, ����������� �������������� �������� 
// (x1, y1) � (x2, y2)
bool isVectorsParallel( double x1, double y1, double x2, double y2 ) {
  return isDoubleZero( x1 * y2 - y1 * x2 );
}

// �������� ��������� ���� �����
bool isDoubleZero( double a ) {
  return fabs( a ) < MACHINE_ZERO;
}

// �������� ��������� ���� �����
bool isDoublesEqual( double a, double b ) {
  return isDoubleZero( a - b );
}

// ���������� ��������������� ������� � ������������
// (x0, y0), (x1, y1), (x2, y2). ���� ����� ������ ��
// ������� ������� - ������� �������������.
double getOrArea( double x0, double y0, double x1, double y1, 
                  double x2, double y2 ) {
  double v1x = x1-x0;
  double v1y = y1-y0;
  double v2x = x2-x1;
  double v2y = y2-y1;
  return ( v1x * v2y - v1y * v2x ) / 2.0;
}

// �����������, ������������ �� �������������� �������
// (x0,y0)-(x1,y1) � (x2,y2)-(x3,y3)
bool isIntersect( double x0, double y0, double x1, double y1, 
                  double x2, double y2, double x3, double y3 ) {
  // ����� ����������� ����� ������ ������� � ��������� (1-d1):d1 ��� 0 <= d1 <= 1
  // ����� ����������� ����� ������ ������� � ��������� (1-d2):d2 ��� 0 <= d2 <= 1
  double c11 = x0 - x1;
  double c12 = x3 - x2;
  double c21 = y0 - y1;
  double c22 = y3 - y2;
  double b1 = x3 - x1;
  double b2 = y3 - y1;
  // ��� ����� ����������� ����������� �������
  // c11 * d1 + c12 * d2 = b1
  // c21 * d1 + c22 * d2 = b2

  // ������������ �������, �� ������ ���� ��-�� ���������������� ��������
  double det = c11 * c22 - c12 * c21;
  // �������� ���������� d1 � d2 �� �������� �������
  double det1 = b1 * c22 - b2 * c12;
  double det2 = c11 * b2 - c21 * b1;
  double d1 = det1 / det;
  double d2 = det2 / det;
  // ���� ����� ����������� ������, ���������� ������� � ����� ����
  // ����� �� ����� ��������
  if ( ( 0.0 <= d1 ) && ( d1 <= 1.0 ) && ( 0.0 <= d2 ) && ( d2 <= 1.0 ) )
    return true;
  return false;
}

Figure::~Figure() { }
