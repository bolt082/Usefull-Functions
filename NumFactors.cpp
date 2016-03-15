//Number of Factors in O(1)
int p[1000006];

void pre()
{
    fori(i,1,1001) {
        p[i]++;
        fori(j,2*i,1000001) {
          //  if(j == 42) p(p[42]);
            p[j]++;
            if(i != j/i && j/i > 1000) p[j]++;
            j += i-1;
        }
    }
}


