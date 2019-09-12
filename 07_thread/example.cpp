#include <iostream>
#include <thread>
#include <boost/thread/thread.hpp>

namespace ns_foo
{
    class Person
    {
        public:
        void display()
        {
            std::cout << "Hello from ns_foo::person::display()" << std::endl;
        }
    };
    class Superhero : public Person
    {
        public:
        void yell()
        {
            std::cout << "I am Iron Man." << std::endl;
        }
        void count(int x)
        {
            for(int i=0; i<x; i++)
            {
                std::cout << "Count: " << i << std::endl;
                boost::this_thread::sleep( boost::posix_time::seconds(1) );
            }
        }
    };
}

void foo(int x)
{
    for(int i=0; i<x; i++)
    {
        std::cout << "Count: " << i << std::endl;
        boost::this_thread::sleep( boost::posix_time::seconds(1) );
    }
}


int main(int argc, char *argv[])
{
    ns_foo::Superhero iron_man;
    std::thread t1(&iron_man::count, 5);
    //std::thread t1(&ns_foo::Superhero::count, 5);
    //std::thread first (iron_man.count,5);
    iron_man.display();
    iron_man.yell();

    //std::thread iron_man.count(5);
    //first.join();                // pauses until first finishes

    std::cout << "foo and bar completed.\n";

    return 0;
}
