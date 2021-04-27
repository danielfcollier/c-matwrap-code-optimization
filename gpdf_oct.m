function g=gpdf_oct(observ, mi, Sigma)
% observ: sinal observado
% mi: vetor média
% Sigma: vetor com a diagonal da matrix de covariância
N=length(observ); %comprimento do vetor de dados
g= exp(-0.5* (observ - mi)' * diag(Sigma)^-1 * (observ - 
mi))/((2*pi)^(N/2) * prod(Sigma).^0.5);


