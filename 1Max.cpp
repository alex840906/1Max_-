#include <stdlib.h>
#include <iostream>
#include <vector>
#include <pthread.h>
#include <unistd.h>
#include <ctime>

using namespace std;

int main()
{
    int h_score = 0;
    int i, j;
    clock_t start, stop;
    int ini_bit[100] = {0};
    int n = 100, tmp;
    start = clock();
    
    while (h_score <= 50)
    {
        int carry = 0, score = 0;

        i=n-1;
        tmp = ini_bit[i] ^ 1 ^ carry;
        carry = (ini_bit[i] & 1) | (ini_bit[i] & carry) | (1 & carry);
        ini_bit[i] = tmp;

        for (i = n - 2; i >= 0; i--)
        {
            tmp = ini_bit[i] ^ 0 ^ carry;
            carry = (ini_bit[i] & 0) | (ini_bit[i] & carry) | (0 & carry);
            ini_bit[i] = tmp;
        }

        for (i = 0; i < n; i++)
            score = ini_bit[i] & 1 ? score + 1 : score;

        stop = clock();
        if (score > h_score)
        {
            h_score = score;
            cout << "highest score :" << h_score << endl;
            cout << "execution time :" << (stop - start) / (double)(CLOCKS_PER_SEC) << endl
                 << endl;
        }
    }

    system("pause");
    return 0;
}