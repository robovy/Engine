#include "src/graphics/window.h"

int main()
{
        using namespace engine;
        using namespace graphics;
        
        Window window("Engine Test", 800, 600);
        
        while(!window.closed())
        {
                window.update();
        }
        
        return 0;
}
