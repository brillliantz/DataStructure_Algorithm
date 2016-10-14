# Chapter 2 Assignments

## Exercise 1
Find the complexity of the function used to find the kth smallest integer in an unordered array of integers

```c++
int selectkth ( int a[], int k, int n){
 int i, j, mini, temp;
    for ( i = 0; i < k; i++){
        mini = i;
        for ( j = i+1; j < n; j++)
            if ( a[j] < a[mini])
                mini = j;
        tmp = a[i];
        a[i] = a[mini];
        a[mini] = tmp;
    }
    return a[k-1];
}
```


The number of basic operations:  
$$
T(n)=
\sum_{i=0}^{k-1}(1 + \sum_{j=i+1}^{n-1}(1 + 1) + 3)
\\= 4k + 2 \sum_{i=0}^{k-1} \sum_{j=i+1}^{n-1}1
\\\sim 2 \sum_{i=0}^{k-1} (n-1-i)
\\= 2 \frac{(n-1-0 + n-k) * k}{2}
\\\sim kn
$$

Time complexity is $O(n)$.

## Excercise 2
Find the computational complexity for the following four loops:

### c)
```c++
for (cnt3=0, i =1; i<=n; i*=2)
    for (j=1; j<=n; j++)
        cnt3++;
```
$$
T(n) =
log_2(n) * n * 1
$$

Time complexity is $O[nlog(n)]$.

### d)
```c++
for (cnt4=0, i=1; i<=n; i*=2)
    for (j=1; j<=i; j++)
        cnt4++;
```

$$
T(n) = 
\sum_{i=0}^{log_2{n}} i
\\
= \frac{(1 - 2^{log_2{n}})}{1 - 2}
\\
= n - 1
$$

Time complexity is $O(n)$.

## Exercise 3
For each of the following two program fragments, give an analysis of the running time (Big-Oh will do).

### 1) 
```c++
sum = 0;
for( i = 0; i < n; i++ )
    for( j = 0; j <i*i; j++ )
        for( k = 0; k <j; k++ )
            sum++;
```

$$
T(n) = 
\sum_{i=1}^{n-1} \sum_{j=0}^{i^2-1} \sum_{k=0}^{j-1} 1
\\
= \sum_{i=1}^{n-1} \sum_{j=0}^{i^2-1} j
\\
= \sum_{i=1}^{n-1} \frac{(0 + (i^2-1)) * i^2}{2}
\\
= \sum_{i=1}^{n-1} (i^4 - i^2)/2
\\
\sim \sum_{i=1}^{n-1} i^4/2
$$

We know that:  
$$\sum_{k=1}^{n} k^4 = \frac{6n^5+15n^4+10n^3-n}{30}$$
So the time complexity is $O(n^5)$.

### 2) 
```c++
sum = 0;
for( i = 1; i < n; i++ )
    for( j = 0; j < i*i; j++ )
        if( j % i == 0 )
            for( k = 0; k < j; k++ )
                sum++;
```

$$
T(n) = 
\sum_{i=1}^{n-1} \sum_{ \substack{j=0\\ j~mod~i=0}}^{i^2-1} \sum_{k=0}^{j-1} 1
\\
= \sum_{i=1}^{n-1} \sum_{ \substack{j=0\\ j~mod~i=0}}^{i^2-1} j
\\
= \sum_{i=1}^{n-1} [0 + i + 2i + 3i + \dots +(i-1)i]
\\
= \sum_{i=1}^{n-1} i \sum_{j=0}^{i-1} j
\\
= \sum_{i=1}^{n-1} i * (i-1)i/2
\\
\sim \frac{1}{2} \sum_{i=1}^{n-1} i^3
$$

We know that
$$ \sum_{k=1}^{n}k^3	=	\frac{n^4+2n^3+n^2}{4} $$
Therefore the time complexity is $O(n^4)$

## Excercise 4
Assume n is an integer, please analyze the number of excution times of underline commands in the following scripts.

### 1) 
```c++
for (int i = 1; i <= n; i++)
    for (int j = 1; j<=n; j++) {
        c[i][j] = 0.0;
        for ( int k = 1; k <= n; k++)
            c[i][j] = c[i][j]+a[i][k]*b[k][j];    \\ this line
}
```

$$
\sum_{i=1}^{n} \sum_{j=1}^{n} \sum_{k=1}^{n} 1 = n^3
$$


### 2)
```c++
x = 0; y = 0;
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
        for (int k = 1; k <= j; k++)
            x = x+y;                    \\ this line
```

$$
\sum_{i=1}^{n} \sum_{j=1}^{i} \sum_{k=1}^{j} 1
\\
= \sum_{i=1}^{n} \sum_{j=1}^{i} j
\\
= \sum_{i=1}^{n} i(i+1)/2
\\
= \frac{1}{2} \left( \sum_{i=1}^{n} i^2 + \sum_{i=1}^{n} i \right)
\\
= \frac{1}{2} \left( \frac{n(n+1)(2n+1)}{6} + \frac{n(n+1)}{2} \right)
\\
= \frac{n^3 + 3n^2 + 2n}{6}
\\
= \frac{n(n+1)(n+2)}{6}
$$

### 3) 
```c++
int x = 91, y = 100;
while(y>0) {
    if(x>100) { x -= 10; y--; }    \\ this line
    else x++;                      \\ this line
}
```

d
```c++
int x = 91, y = 100;
for (y = 100; y > 0; y--) {
    if (x > 100) 
```
$$




# test

