#include <iostream>
#define MAX 999

using namespace std;
//fibonacci
// Abordagem TOP DOWN
int memorizacao[MAX] = {0};
int fib_mem (int n) {
    if (memorizacao[n])
        return memorizacao[n];
    int f;
    if (n <= 2) f = 1;
    else f = fib_mem(n - 1) + fib_mem(n - 2);

    memorizacao[n] = f;
    return f;
}

// Abordagem BOTTOM UP
int fibonnaci[MAX] = {0};
int fib_bottom_up (int n) {
    fibonnaci[0] = 0;
    fibonnaci[1] = 1;
    for (int i = 2; i <= n; ++i)
        fibonnaci[i] = fibonnaci[i - 1] + fibonnaci[i - 2];
    return fibonnaci[n];
}

int main()
{
    int f;
    cin >> f;
    cout << "TOP DOWN: " << fib_mem(f)
         << endl
         << "BOTTOM UP: " << fib_bottom_up(f)
         << endl;
    return 0;
}
