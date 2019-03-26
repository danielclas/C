#include <stdio.h>
#include <stdlib.h>

int obtenerMaximo (int x, int y, int z);

int main()
{
    printf("%d", obtenerMaximo(5,7,9));

    return 0;
}

int obtenerMaximo (int x, int y, int z)
{
    int mayor;

    mayor=x;

    if(y>x && y>z)
    {
        mayor=y;
    }
    else
    {
      if(z>x)
      {
          mayor=z;
      }
    }

    return mayor;
}

