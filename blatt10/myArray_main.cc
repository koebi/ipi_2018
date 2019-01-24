#include "myArray.h"
#include <iostream>

using namespace std;


int main()
{
      
  // zu Teilaufgabe a)

  TwoDBoolArray matrix1 = TwoDBoolArray(2, 3);

  cout << "Initialisierte Matrix: " << endl;
  for (int i = 0; i < matrix1.rows(); i++)
  {
    for (int j = 0; j < matrix1.cols(); j++)
    {
      cout << matrix1[i][j] << " ";
    }
    cout << endl;
  }

  matrix1[0][0] = 1;
  matrix1[0][2] = 1;
  matrix1[1][1] = 1;
  cout << "Matrix nach dem Schreiben: " << endl;
  for (int i = 0; i < matrix1.rows(); i++)
  {
    for (int j = 0; j < matrix1.cols(); j++)
    {
      cout << matrix1[i][j] << " ";
    }
    cout << endl;
  }
  

  // zu Teilaufgabe b)
        
  TwoDBoolArray matrix2 = TwoDBoolArray();
  cout << "Operator>> von matrix2:" << endl;
  cin >> matrix2;
  cout << "Operator<< von matrix2:" << endl;
  cout << matrix2;

  return 0;
}
