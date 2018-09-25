#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <pthread.h>
#include <unistd.h>

using namespace std;

int evaluate(vector<int> &bit)
{
    int i, j, score,carry;
    for (i = 0; i < 25; i++)
    {
        bit.assign(i-1,0);
        for (j = 0; j <i;j++)
        {
            bit[j]=!bit[j];
        }
           
    }
     return score;
}

int main()
{
    vector<int> ini_bit1, ini_bit2, ini_bit3, ini_bit4;
    int i, j, r;
    srand(time(NULL));
    ini_bit1.resize(25);
    ini_bit2.resize(25);
    ini_bit3.resize(25);
    ini_bit4.resize(25);
    ini_bit1 = {0};
    ini_bit2 = {0};
    ini_bit3 = {0};
    ini_bit4 = {0};

    system("pause");
    return 0;
}