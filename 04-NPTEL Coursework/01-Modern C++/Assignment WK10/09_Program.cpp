#include <iostream>
using namespace std;

class Resource
{
public:
    Resource() { std::cout << "#1" << " "; }
    Resource(const Resource &) { std::cout << "#2" << " "; }
    Resource(Resource &&) noexcept { std::cout << "#3" << " "; }
    Resource &operator=(const Resource &)
    {
        std::cout << "#4" << " ";
        return *this;
    }
    Resource &operator=(Resource &&) noexcept { std::cout << "#5" << " "; }
};

Resource createResource()
{
    Resource r;
    return r;
}

int main()
{
    Resource r1;
    r1 = createResource();
    Resource r2 = r1;

    Resource r3 = std::move(r2);
    return 0;
}
