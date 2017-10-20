#include <iostream>

unsigned long pyramidsCount(unsigned long countOfCubes){

    auto **dp_table = new unsigned long *[countOfCubes+1];

    for(unsigned long i = 0; i <= countOfCubes; ++i) {
        dp_table[i] = new unsigned long [countOfCubes+1];
        dp_table[0][i] = 1;
        dp_table[i][1] = 1;
    }

    for(unsigned long remains = 1; remains <= countOfCubes; ++remains)
        for(unsigned long width = 2; width <= countOfCubes; ++width){

            dp_table[remains][width] = dp_table[remains][width - 1];

            if(remains > width)
                dp_table[remains][width] += dp_table[remains-width][width];
        }

    unsigned long result = dp_table[countOfCubes][countOfCubes];

    for(unsigned long i = 0; i <= countOfCubes; i++)
        delete [] dp_table[i];

    delete [] dp_table;

    return result;
}

int main() {

    unsigned long input;
    std::cin >> input;
    std::cout << pyramidsCount(input);

}

/*
    0  1  2  3  4  5   6  7
    ------------------------
 0| 1  1  1  1  1  1   1  1
 1|    1  1  1  1  1   1  1
 2|    1  2  2  2  2   2  2
 3|    1  2  3  3  3   3  3
 4|    1  3  4  5  5   5  5
 5|    1  3  5  6  7   7  7
 6|    1  4  7  9  10 11 11
 7|    1  4  8  11 13 14 15



==
===

=
=
===

=
==
==

=
=
=
==

=
=
=
=
=


*/
