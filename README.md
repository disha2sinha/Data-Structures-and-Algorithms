# Dynamic-Programming


**Chain Matrix Multiplication**
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same.


**Algorithm:**
Array p{1...n+1] contains sizes of matrices to be multiplied where is n is the number of matrices
**Matrix-chain-multiplication(array p[1...n, int n)**
 1. Declare two arrays m[1...n,1...n]  and b[1....n,1....n];
 
 
 2. for i=1 to n do m[i,i]=0;
 
 
 3. for l=2 to n
 
 4.do{
 
 5.    for  i=1 to n-l+1 
 
 6.    do{
 
 7.         j=i+l-1;
 
 8.         m[i,j]=infinity;
 
 9.         for k=i to j-1 
 
 10.        do{
 
 11.              q=m[i,k]+m[k+1,j]+p[i-1]* p[j]* p[k];
 
 12.              if(q<m[i,j]) do{ 
 
                         m[i,j]=q;
                         
                         b[i,j]=k;
                    }
 
 13.           }
 
 14.     }
 
 15. }
 
 16.  return m[1,n];
 
 
 17. STOP;
 
 **Time Complexity:** O(n^3)
 

