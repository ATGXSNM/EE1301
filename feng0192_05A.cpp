#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int s()

{

    int t = 0;


    int d1 = rand() % 6 + 1;


    int d2 = rand() % 6 + 1;

    t = d1 + d2;

    if (t == 12)

        return 1 + s();

    return t;

}

int main()

{

    int n = 1000000;

    srand(time(0));

    int max = 0;

    float p[100] = {0};


    for (int i = 0; i < n; i++)

    {

        int score = s();

        if (max < score)

            max = score;


        p[score]++;

    }


    for (int i = 2; i <= max; i++)

    {

        p[i] /= float(n);

        p[i] *= 100;

    }


    for (int i = 2; i <= max; i++)

    {

        cout << i << " happened " << p[i]<<"%" << endl;

    }

}
