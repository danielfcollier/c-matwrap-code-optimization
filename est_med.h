#include <stdio.h>

void est_med(float *pcot, float *observ, float *mi, float *Sigma, unsigned int J, unsigned int N, unsigned int T, float *nmi)
{
    int m, n, i ,j, sub;
    int ind_pcot[J][T], ind_observ[T][N], ind_mi[J][N];
    int index_n, index_j, index_t;
    float snum[N], sden[N], deltami[N];

    // Construção de matrizes cujos elementos indicam sua posição linear 
    m = J;
    n = T;
    for (i=0; i < m; i++)
    {
        for (j=0; j < n; j++)
        {   
            sub = i + j*m;
            ind_pcot[i][j] = sub;
        }
    }
    //
    m = T;
    n = N;
    for (i=0; i < m; i++)
    {
        for (j=0; j < n; j++)
        {   
            sub = i + j*m;
            ind_observ[i][j] = sub;
        }
    }
    //
    m = J;
    n = N;
    for (i=0; i < m; i++)
    {
        for (j=0; j < n; j++)
        {   
            sub = i + j*m;
            ind_mi[i][j] = sub; // ind_mi == ind_nmi == ind_Sigma
        }
    }
    
    // Função:
    
    for (index_n=0; index_n < N; index_n++)
    {
        snum[index_n] = 0;
        sden[index_n] = 0;
    }
    
    for (index_t=0; index_t < T; index_t++)
    {
        for (index_j=0; index_j < J; index_j++)
        {
            for (index_n=0; index_n < N; index_n++)
            {
                snum[index_n] = snum[index_n] + pcot[ ind_pcot[index_j][index_t] ] * ( ( observ[ ind_observ[index_t][index_n] ]  - mi[ ind_mi[index_j][index_n] ] )) / ( Sigma[ ind_mi[index_j][index_n] ] ) ;
                sden[index_n] = sden[index_n] + ( pcot[ ind_pcot[index_j][index_t] ]/ Sigma[ ind_mi[index_j][index_n] ] );
                deltami[index_n] = snum[index_n] / sden[index_n];
            }
        }
    }
    
    for (index_j=0; index_j < J; index_j++)
    {
        for(index_n=0; index_n < N; index_n++)
        {
            nmi[ ind_mi[index_j][index_n] ] = mi[ ind_mi[index_j][index_n] ] + deltami[index_n]; 
        }
    }



}//%input pcot(J,T)
//%input observ(T,N)
//%input mi(J,N)
//%input Sigma(J,N)
//%output nmi(J,N)
