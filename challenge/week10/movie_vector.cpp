#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Movie {
   public:
    string name;
    float star;

    Movie() {
        name = "";
        star = 0;
    }
    Movie(string name, float star) {
        this->name = name;
        this->star = star;
    }

    void Print() {
        cout << name << " : " << star << endl;
    }
};

int main() {
    vector<Movie> movies;

    movies.push_back(Movie("Titinic", 9.9));
    movies.push_back(Movie("Gone with the wind", 9.6));
    movies.push_back(Movie("Terminator", 9.7));

    for (Movie c : movies) {
        c.Print();
    }

    return 0;
}