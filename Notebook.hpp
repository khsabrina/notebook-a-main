#include <iostream>
#include "Direction.hpp"
using ariel::Direction;
using namespace std;

namespace ariel {
	class Notebook {
        public:
            Notebook();
            void write(int col, int row,int page, Direction dir, string str);
            string read(int col,int row,int page, Direction dir , int size);
            void erase(int col,int row,int page, Direction dir , int size);
            void show(int page);
        
    };
}