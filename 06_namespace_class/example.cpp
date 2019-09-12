#include <iostream>

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
    };
}


int main(int argc, char *argv[])
{
    ns_foo::Superhero iron_man;
    iron_man.display();
    iron_man.yell();

    return 0;
}
