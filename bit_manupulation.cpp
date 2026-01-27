https://medium.com/techie-delight/top-bit-manipulation-hacks-a9a1c5536dc9

1. Check no is even or odd

 if (n & 1) {
        cout << n << " is odd";
    }
    else {
        cout << n << " is even";
    }


2. Swap two numbers without using any third variable


x = x ^ y;
y = x ^ y;
x = x ^ y;


3.  Turn of kth bit from right

int turnOffKthBit(int n, int k) {
    return n & ~(1 << (k - 1));
}
 

4. int turnOnKthBit(int n, int k) {
    return n | (1 << (k - 1));
}
 

 5. int isKthBitSet(int n, int k) {
    return n & (1 << (k - 1));
}


6. int toggleKthBit(int n, int k) {
    return n ^ (1 << (k - 1));
}



7. check power of two 

The expression n & (n-1) will turn off the rightmost set bit of a number n. The exprsession n -1 
will have all the bits flipped after the righmost set bit of n (inclluding the rightmost set bit). So, n 
& (n-1) will result in the last bit flipped of n. Consider



00010000    &                (n = 16, only one set bit)
00001111                     (n-1 = 15)
~~~~~~~~
00000000


If the number is a power of 2, it has only a 1-bit set  and n & (n-1) will unset the only set bit.  
So, we can say that n & (n-1) returns 0 if n is a power of 2; otherwise it's not a power of 2

'bool isPowerOfTwo(unsigned n)
{
	cout << n << " in binary is " << bitset<8>(n) << "\n";
	cout << n - 1 << " in binary is " << bitset<8>(n-1) << "\n\n";

	return !(n & (n - 1));
}


8. Count set bits in integer:

while (x)
{
x &= (x-1);
count++;
}

9. Stripping off the lowest set bit :

x = x & (x-1)

10. Find the position of the rightmost set bit


The idea is to unset the rightmost bit of a number n and XOR the result with n. Then the rightmost 
set bit in n will be the position of the only set bit in the result. Note that if n is odd, we can  
directly return 1 as the first bit is always set for odd numbers.0

00010100    &                (n = 20)
00010011                     (n-1 = 19)
~~~~~~~~
00010000    ^                (XOR result number with n)
00010100
~~~~~~~~
00000100  ——  rightmost set bit will tell us the position

int positionOfRightmostSetBit(int n)
{
    // if the number is odd, return 1
    if (n & 1) {
        return 1;
    }
 
    // unset rightmost bit and xor with the number itself
    n = n ^ (n & (n - 1));
 
    // find the position of the only set bit in the result;
    // we can directly return `log2(n) + 1` from the function
    int pos = 0;
    while (n)
    {
        n = n >> 1;
        pos++;
    }
    return pos;
}


//Alternative solution:

The idea is to negate n and perform bitwise AND operation with itself, ie. n & -n. Then the  
position of the rightmost set bit in n will be the positon of the only set bit in the result. We can 
also use this hack for problem 1. If (n & -n) == n , then the positive interger n is a power of 2  

00…0010100   &                    (n = 20)
11…1101100                        (-n = -20)
~~~~~~~~~~
00…0000100


int positionOfRightmostSetBit(int n)
{
    // if the number is odd, return 1
    if (n & 1) {
        return 1;
    }
 
    return log2(n & -n) + 1;
}



11. Find postion of only set bit in a number  


The idea is to unset the rightmost bit of a number n and check if it becomes 0 or not. If if is nonn-
zero we know that there is another set bit persent and we have invalid input. If it becomes 0, then  
we can find the positon of the only set bit by processig every bit of n one by one or directly using log2(n) +1 


int positionOfSetBit(int n)
{
    // unset the rightmost bit and check if the number is non-zero
    if (n & (n - 1))
    {
        cout << "Wrong input";
        return 1;
    }
 
    return log2(n) + 1;
}
