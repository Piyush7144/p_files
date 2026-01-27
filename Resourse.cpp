#include <bits/stdc++.h>

using namespace std;

//prefix sum
const int N = 1e5+10;
int a[N];
int pf[N];
 
int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
    pf[i] = pf[i-1] + a[i];
  }
  int q;
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >> r;
  //Calculating sum from r to l.
    cout << pf[r] - pf[l-1] << endl;
     
  }
   return 0;
}


//sqrt(N) implementation
bool isPrime(int n)
{
	if(n ==1 ) return false;

	for(int i =2; i*i <= n; i++)
	{
		if(n % i ==0)
			return false;
	}
	return true;
}


//sieve of eratosthenes

Preprocessing O(Nlog(log(N)))
Answer Query: O(1)
Extra space : O(N)


int is_prime[1000001];

void seive()
{
	int maxN = 1000000;

	for(int i = 1; i<= maxN; i++) is_prime[i] = 1;

	is_prime[0] =  is_prime[1] = 0;

	for(int i = 2; i*i <= maxN; i++)
	{
		if(is_prime[i])
		{
			for(int j = i*i, j<= maxN; j*= i)
				is_prime[j] = 0;
		}
	}
}


//Prime factorization in O(sqrt(N))

void primeFact(int N)
{
	for(int i = 2; i*i <= N; i+=)
		if(N %i == 0)
		{
			int cnt = 0;
			while(N % i == 0)
		    {
		    	cnt++;
		    	N /= i;
		    }
		    cout<<i<<"^"<<cnt<<endl;
		}

		if(N > 1)
			cout<<N<<"^"<<endl;
}


// Binary Exponentiation, a ^ N in O(log n) Power calculation

int power(int a, int n)
{
	int result = 1;

	while(n != 0)
	{
		if(n % 2 == 1)
		{
			result *= a;
			n--;
		}
		else
		{
			a *= a;
			n /= 2;
		}
	}
	return res;
}

//Matrix exponentiation
// Brute force O(M^3 * N)
// This methong O(M^3 *Log(N))

//[F1, F2] X {{0,1}, {1,1}}^ (n-1) = [Fn , Fn+1] in log(N)
//F1 = 1, F2 =1





//Euclid division lemma
/* 
   A = B*q +r , where o<= r < B

   (N1+N2) % mod = (N1 % mod + N2 % mod) % mod,
   (N1*N2) % mod = ((N1%mod) * (N2%mod)) % mod.


*/

int gcd (int a, int b) {
	if(b == 0)
		return a;
	else
		return gcd( b, a%b);
}


//modular arithmatic
/*
Modular congruences  a = b(mod N)


if( a = b (mod N))
 then 
   a -b = 0(mod N)
   a -b is divisible by N


If a*b = c
then

 a(modN) *b(modN) = c(modN)

 eg: res = a*b
     res = ((a%N) * (b%N))%N


  if a = b(modN ) then
     a^k = b^k (modN)


     
*/


//Modulo multiplicative inverse

(A/B) %P = (A*X) %P = ((A%P) * (X%P))%P


A*X = 1(modP)

MOdulo inverse of A, under modulo P exist if GCD(A, P) = 1


//Ways to calculate modulo  inverse
//1 using fermat little theoram
//2 using extended euclidean theoram


Fermat''s little theorem

a^(m-1) = 1 mod m , gcd(a, m = 1), m = prime

so a^(m-2) = a^(-1) mod m


//Total number of divisors from prime factorization

if N = p1^(y1)* p2^(y2) * p3^(y3) .... pn^(yn)

	Total divisors = (y1+1)* (y2+1)* (Y3+1)... (yn+1)



//Euler totient function  o(n) = no of positive integers coprime upto n with n; 
o(5) = 4;
O(prime) = prime -1

O(prime^x ) = Prime^(x-1)(Prime -1)


O(N) = N* (P1-1) *  (P2-1)* (Pn-1)
            P1         P2     Pn
P1 Pn prime number which divide N;(from prime factorization)



int main()

{

	return 0;
}


//segmented seive
void init(int L , int R)
{
	if(L == 1) L++;
 
	int maxN = R - L + 1;
	vi ar(maxN , 0);
 
	for(lli p : primes)// Primes are generated using seive
	if(p*p <= R)
	{
		int i = (L / p) * p;
		if(i < L) i += p;
 
		for(;i<=R;i+=p)
		{
			if(i != p)
			ar[i-L] = 1;
		}
	}
 
	for(int i=0;i<maxN;i++)
	if(ar[i] == 0)
	cout<<L + i<<endl;
}
 