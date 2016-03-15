vector<int> primes;
int isPrime[1000005];

void sieve(){
    for(int i = 0; i < 1000005; ++i){
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    fori(i, 2, 1000005){
        if(isPrime[i]){
            primes.pb(i);
            int j = 2*i;
            while(j < 1000005){
                isPrime[j] = false;
                j += i;
            }
        }
    }
}

vector<ll> divisors;

void getDivisors(ll n){
    for(ll i = 1; i*i <= n; ++i){

        if(n%i == 0){
            //cout<<i<<endl;
            divisors.pb(i);
            if(n/i != i){
                divisors.pb(n/i);
            }
        }
    }
}
//Number of Factors
int up = sqrt(x);
for(int i = 0; i < primes.size() && primes[i] <= up; ++i){
    if(x%primes[i] == 0){
    //    cout<<primes[i]<<endl;
        int pw = 0;
        while(x%primes[i] == 0){
            x /= primes[i];
            pw++;
        }
        ans *= (pw+1);
    }
}
if(x != 1){
    ans *= 2;
}
