#include <stdio.h>

void est_var(float *pcot, float *observ, float *nmi, float *FREGULAR, unsigned int J, unsigned int N, unsigned int T, float *nsigma)
{
    float snum[N], sden, soma, prod;
    int i, j, n, m, index_n, index_j, index_t, sub;
    int ind_pcot[J][T], ind_observ[T][N], ind_nmi[J][N], ind_nsigma[J][N];

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

    m = J;
    n = N;
    for (i=0; i < m; i++)
    {
        for (j=0; j < n; j++)
        {  
            sub = i + j*m;
            ind_nsigma[i][j] = sub;
            ind_nmi[i][j] = sub;
        }
    }
    
    // Estimação da variância para cada codeword 
    for (index_j=0; index_j < J; index_j++) 
    {
       for (index_n=0; index_n < N; index_n++)
           snum[index_n] = 0;
       
       sden = 0;
       
       for (index_t=0; index_t < T; index_t++)
       {
           for (index_n=0; index_n <  N; index_n++)
           {    
               prod = observ[ ind_observ[index_t][index_n] ]  -  nmi[ ind_nmi[index_j][index_n] ]; 
               soma =  pcot[ ind_pcot[index_j][index_t] ] * prod * prod ;
               snum[index_n] = snum[index_n] + soma;
           }
            
           sden = sden + pcot[ ind_pcot[index_j][index_t] ];
       }

       for (index_n=0; index_n < N; index_n++)
           nsigma[ ind_nsigma[index_j][index_n] ] = FREGULAR[0] + ( snum[index_n] / sden );
    }
    
}//%input pcot(J,T)
//%input observ(T,N)
//%input nmi(J,N)
//%input FREGULAR(1)
//%output nsigma(J,N)
