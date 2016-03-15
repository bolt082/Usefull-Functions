#define getcx getchar//_unlocked
inline int inp()
{
    int n=0;
    int ch=getcx();int sign=1;
    
    while( ch < '0' || ch > '9' )
    {
        if(ch=='-')
            sign=-1; 
        ch=getcx();
    }
    
    while( ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    
    n=n*sign;
    
    return n;
}
 
#define pc putchar//_unlocked
inline void write(int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}