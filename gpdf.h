#include <stdio.h>
#include <math.h>

void gpdf_c(float *observ, unsigned int length_o, float *mi, unsigned int length_m, float *sigma, unsigned int length_s, float *g)
{
    // pdf de uma var. gaussiana, considerando Sigma diagonal
    // observ: sinal observado
    // mi: vetor média
    // Sigma: vetor com a diagonal da matrix de covariância
    
    int index;
    float det_sigma=1, aux[length_o], arg=0, N;
    
    for (index=0; index < length_o; index++)
    {
        aux[index] = observ[index] - mi[index];
        arg += aux[index] *  (1 / sigma[index]) * aux[index] * (-0.5);
        det_sigma *= sigma[index];
    }
    
    N = length_o; 

    g[0]= exp(arg) / ( pow( (4*acos(0)),(N/2)) * sqrt(det_sigma));
    
}//%input observ(length_o)
//%input mi(length_m)
//%input sigma(length_s)
//%output g(1)
