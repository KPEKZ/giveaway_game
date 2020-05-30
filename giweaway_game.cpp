#include "PCH.h"

int main() {

   
    Manager manager;
    if (!manager.Init()) {

        std::cout << " try again!" << std::endl;
        return 0;
    }
    while (!manager.gGameFinished) {
        manager.MakeMove();
    }
   
    return 0;
}