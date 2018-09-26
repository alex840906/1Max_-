#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <pthread.h>
#include <unistd.h>

using namespace std;
vector<int> sum(26, 0), ini_bit;
int h_score = 0;

int main()
{
    vector<int> B;
    int i, j;
    ini_bit.resize(50);
    B.resize(50);
    ini_bit = {0};
    ini_bit[39] = 1;
    B[39] = 1;
    int n = 40;

    while (h_score <= 40)
    {
        int carry = 0, score = 0;

        for (i = n - 1; i >= 0; i--)
        {
            ini_bit[i] = ini_bit[i] ^ B[i];
            carry = ini_bit[i] & B[i];
            ini_bit[i - 1] = carry;
        }
        for (i = 0; i <= n; i++)
        {
            printf("%d ", ini_bit[i]);
            
            //cout<<"123"<<endl;
        }
        cout<<endl;
        for (i = 0; i < n; i++)
        {
            if (ini_bit[i] == 1)
                score++;
        }
        if (score > h_score)
        {
            h_score = score;
        }
        //cout << endl;
        sleep(1);
    }

    system("pause");
    return 0;
}