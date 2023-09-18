//-------------------------------------------------------
// dato de entrada: n (int)
// Dato de Salida: arreglo (int), aM5 (int), am7 (int)
//-------------------------------------------------------


#include <iostream>
#include <iomanip>
using namespace std;

int  *  dimensionar(int n);
void llenarDatos(int *pMiArreglo, int n );
void imprimir(int *pMiArreglo, int n );
int contarMultiplos( int *pA, int n, int multiplo);
void  llenarMultiplos(int * pArreglo, int  n, int * pMul, int  multiplo);
void liberarMemoria( int * & pA );

int main()
{ int n;
    cout << "Numero de elementos del arreglo : ";
    cin >> n;
    int *pArreglo =  dimensionar(n);
    llenarDatos(pArreglo, n);
    imprimir(pArreglo, n);
    int m5 = contarMultiplos( pArreglo, n, 5);
    int m7 = contarMultiplos( pArreglo, n, 7);
    cout << "\n\nNumero de datos que son multiplos de 5: " << m5 << "\n";
    cout << "Numero de datos que son multiplos de 7: " << m7 << "\n";
    int *pM5 = dimensionar(m5);
    int *pM7 = dimensionar(m7);
    llenarMultiplos( pArreglo, n, pM5, 5);
    llenarMultiplos(pArreglo, n, pM7, 7);
    cout << "\n";
    cout << "Arreglo con los multiplos de 5\n";
    imprimir(pM5, m5);
    cout << "\n";
    cout << "Arrglo con los multiplos de 7\n";
    imprimir(pM7,m7);
    liberarMemoria(pArreglo);
    liberarMemoria(pM7);
    liberarMemoria(pM5);
    return 0;
}

void liberarMemoria( int * & pA )
{
   delete []pA;
   pA = nullptr;
}


/* i    0  1   2  3 4   5    6  7   8  9  10 11   12  13  14
 *    23  45  6 79 60  65  23  25  90 56 55 12   34  42  450
 *
 * mi   0    1    2   3  4  5   6
 *
 */


void  llenarMultiplos(int * pArreglo, int  n, int * pMul, int  multiplo)
{
  int mi =0;
  for(int i=0; i<n; i++)
      if( pArreglo[i] % multiplo == 0)
          pMul[mi++] = pArreglo[i];
}


int contarMultiplos( int *pA, int n, int multiplo)
{
    int c=0;
    for(int i=0; i<n; i++)
        if( pA[i] % multiplo ==0)
            c++;
    return c;
}


int  *  dimensionar(int n)
{
  return ( new int[n]);
}

void llenarDatos(int *pMiArreglo, int n )
{
    for(int i=0; i<n; i++)
        pMiArreglo[i] = rand() % 1000;
}


void imprimir(int *pMiArreglo, int n )
{
    for(int i=0; i<n; i++)
        cout << setw(5) << pMiArreglo[i];
}