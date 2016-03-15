#define MAX 10000000
#define LMT 3200

unsigned flag[MAX/64];
unsigned prime[664581], total;

void sieve()
{
        unsigned int i, j, k;
        for (i = 3; i < LMT; i += 2)
            if((flag[i>>6] & (1<<((i>>1)&31))) == 0)
                for(j = i*i, k = i<<1; j < MAX; j += k)
                    (flag[j>>6]|=(1<<((j>>1)&31)));
        prime[1] = 2;
        for(i = 3, j = 2; i < MAX; i += 2) {
                if((flag[i>>6]&(1<<((i>>1)&31))) == 0)
                    prime[j++] = i;
        }
        total = j;
}