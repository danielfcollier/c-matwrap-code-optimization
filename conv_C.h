// conv_C.h
#include <stdio.h>

void conv_C(float *x, float *h, unsigned int tam_h, unsigned int tam_x, float *y)
{   
    // Calcula a convolução linear entre 2 sinais finitos usando a definição.    
    int index_l, index_n, n_length, aux;
    float sum;
    
    n_length = tam_x + tam_h - 1;
    
    for ( index_n=0; index_n < n_length; ++index_n ) 
    {
        for ( sum=0, index_l=0; index_l < tam_x; ++index_l ) 
        {
            aux = index_n - index_l;
            if ( (aux >= 0) && (aux < tam_h) )
                sum += x[index_l] * h[index_n - index_l]; 
        }
        y[index_n] = sum;
    }   
}//%input x(tam_x)
//%input h(tam_h)
//%output y(tam_x + tam_h - 1)
