#include "application.h"
#include <heap_memory_track_component.h>

#ifdef DEBUG_MODE
// TRACK_HEAP_AND_LEAKS() // start tracking heap
// StackMemoryTracker gstack_memory_tracker; // create a stack memory tracker
#endif /* DEBUG_MODE */

int main(int argc, char* argv[])
{
    Application* App = Application::GetInstance();
    if(!App->Init())
    {
        std::cout << "Application count not Init!" << std::endl;
    }
    App->Update();
    return EXIT_SUCCESS;
}

