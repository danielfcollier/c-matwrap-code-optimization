function nmi = est_med_oct(pcot, observ, mi, Sigma)

J = 200;
T = 350;
N = 100;
%===========
%Estimação da nova média (eq. 16 e 17)
deltami=zeros(N,1);
nmi=zeros(J,N);
snum=0;sden=0;
for t=1:T
for j=1:J
    snum=snum+pcot(j,t)*((observ(t,:)-mi(j,:))./(Sigma(j,:)));%Sigma já 
%é a variância (s^2)
    sden=sden+pcot(j,t)./(Sigma(j,:));
end
end
deltami=snum./sden;
nmi=mi+repmat(deltami,J,1);

