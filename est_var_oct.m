function nsigma = est_var_oct(pcot, observ, nmi, FREGULAR)

[J, T] = size(pcot);
[T, N] = size(observ);

nsigma=zeros(J,N);
for j=1:J
    snum=0;sden=0;
    for t=1:T
        soma = pcot(j,t)*( observ(t,:) - nmi(j,:) ) .^2;
        snum=snum+soma;
        sden=sden+pcot(j,t);
    end
    nsigma(j,:)=FREGULAR+snum/sden;
end


