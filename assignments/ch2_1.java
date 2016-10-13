int selectkth ( int a[], int k, int n){
    int i, j, mini, temp;                   // declaration no time
    for ( i = 0; i < k; i++){               // k times
        mini = i;               //
        for ( j = i+1; j < n; j++)
            if ( a[j] < a[mini])
                mini = j;
        tmp = a[i];
        a[i] = a[mini];
        a[mini] = tmp;
    }
    return a[k-1];
}
