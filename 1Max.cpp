#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <pthread.h>
#include <unistd.h>

using namespace std;
//vector<int> sum(26, 0), ini_bit;


int main()
{
    //vector<int> B;
    int h_score = 0;
    int i, j;
    int ini_bit[100]={0},B[100]={0};
    //ini_bit.resize(50);
    //B.resize(50);
    //ini_bit = {0};
    //ini_bit[99] = 1;
    B[99] = 1;
    int n = 100, tmp;

    while (h_score <= 50)
    {
        int carry = 0, score = 0;

        for (i = n - 1; i >= 0; i--)
        {
            tmp = ini_bit[i] ^ B[i] ^ carry;
            carry = (ini_bit[i] & B[i]) | (ini_bit[i] & carry) | (B[i] & carry);
            ini_bit[i] = tmp;
        }

        for (i = 0; i < n; i++)
            if (ini_bit[i] == 1)
                score++;

        if (score > h_score)
        {
            h_score = score;
            cout<<h_score<<endl;
        }
    }

    system("pause");
    return 0;
}