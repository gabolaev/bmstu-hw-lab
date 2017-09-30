#include <iostream>
#include <cassert>

using namespace std;

struct vertex{
    float x = 0;
    float y = 0;
    vertex() = default;
};

float orientedArea(vertex figure[], int countOfVertexes){
    float result = 0;
    for(int iter = 0; iter < countOfVertexes; iter++)
        result += ((figure[iter].y + figure[iter+1].y)/2 * -(figure[iter].x-(figure[iter+1].x)));
    return result;
}

int main() {

    int countOfVertexes;
    std::cin >> countOfVertexes;
    assert(countOfVertexes > 1);
    auto figure = new vertex[countOfVertexes+1];

    std::cin >> figure[0].x >> figure[0].y;
    figure[countOfVertexes] = figure[0];

    for (int i = 1; i < countOfVertexes; ++i) {
        std::cin >> figure[i].x >> figure[i].y;
    }

    std::cout << orientedArea(figure, countOfVertexes);

    delete [] figure;
    return 0;
}