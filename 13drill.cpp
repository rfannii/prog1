
#include "../Simple_window.h"
#include "../Graph.h"
#include <stdlib.h>
#include <ctime>



int main() {
    using namespace Graph_lib;
    Simple_window window{ Point{200,200},800,1000,"Simple_window" };


    int size = 800;
    int gridSpace = 100;
    Lines grid;
    for (int i = gridSpace; i <= size; i += gridSpace)
    {

        grid.add(Point{ i,0 }, Point{ i,size });
        grid.add(Point{ 0,i }, Point{ size,i });
    }
    window.attach(grid);

    vector<Graph_lib::Rectangle*> rectangles;

    for (int i = 0; i < 800; i += 100)
    {
        rectangles.push_back(new Graph_lib::Rectangle(Point{ i,i }, Point{ i + 100,i + 100 }));
        rectangles[rectangles.size() - 1]->set_fill_color(Color::red);
        window.attach(*rectangles[rectangles.size() - 1]);
    }

    Image i1{ Point{0,200},"beka.jpg" };
    window.attach(i1);
    Image i2{ Point{200,0},"beka.jpg" };
    window.attach(i2);
    Image i3{ Point{200,400},"beka.jpg" };
    window.attach(i3);
    Image i4{ Point{400,200},"beka.jpg" };
    window.attach(i4);

    Image i5{ Point{600,600},"beka.jpg" };
    window.attach(i5);
    window.wait_for_button();

    int help1 = 600;
    int help2 = 600;
    for (int i = 0; i < 10; i++)
    {
        
        srand(time(NULL) * sqrt(help1)); 
        i5.move(-help1, -help2); 
        help1 = (rand() % 8) * 100; 
        help2 = (rand() % 8) * 100;  
        i5.move(help1, help2);
        window.wait_for_button();
    }
    return 0;
}