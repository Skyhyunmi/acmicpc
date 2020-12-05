#include <stdio.h>
// #import<ios>
main(){
    int n,i,r,t,p;
    scanf("%d",&n);
    for(i=n-70;++i<n&&!p;r=p=r+i-n?0:i)
        do r+=t%10;while(t/=10);
    printf("%d",p);}

// int n,i,s,p,t;
// main(){
//     for(scanf("%d",&n); ++i<n && !p ;s=p=s+i-n?0:i)
//         for(t=i;t;t/=10)
//             s+=t%10;
//     printf("%d",p);
// }

// #include<stdio.h>
// main(){
//     int n,i,r,t;
//     scanf("%d",&n);
//     for(i=n-70;i<n&&!t;t=i+r-n,r=0,i++)
//         for(t=i;t;t/=10) r+=t%10;
//     printf("%d\n",t);
// }