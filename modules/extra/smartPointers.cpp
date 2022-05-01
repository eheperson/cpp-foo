#include <iostream>
#include <memory>
class CruiseControl{
    public:
        CruiseControl(){
            std::cout << "CruiseControl object created" << std::endl;
        };

        ~CruiseControl(){
            std::cout << "CruiseControl object destroyed" << std::endl;
        }

        void increaseSpeedTo(int speed){
            std::cout << "Speed at " << speed << std::endl;
        };
};



int main (){
    // make_unique is an C++14 feature 

    // -------------------------------------------------------------------------------------------------------------------

    // unique_ptr example in action
    // The executable that was run shows that the object is deallocated at the end of the current scope
    std::cout << "unique_ptr test started" << std::endl;
    std::unique_ptr<CruiseControl> cruiseControl_1 = std::make_unique<CruiseControl>();
    cruiseControl_1->increaseSpeedTo(12);
    std::cout << "unique_ptr test finished" << std::endl;

    // -------------------------------------------------------------------------------------------------------------------

    // another example with unique_ptr shows its behavior with arrays
    // there will be three objects of the CruiseControl type that have been allocated and then released.
    std::cout << "unique_ptr test started" << std::endl;
    std::unique_ptr<CruiseControl[]> cruiseControl_2 = std::make_unique<CruiseControl[]>(3);
    cruiseControl_2[1].increaseSpeedTo(12);
    std::cout << "unique_ptr test finished" << std::endl;
    
    // -------------------------------------------------------------------------------------------------------------------

    // shared_ptr example in action
    std::cout << "shared_ptr test started" << std::endl;

    // we defined a cruiseControlMaster variable pointing to nullptr
    std::shared_ptr<CruiseControl> cruiseControlMaster(nullptr);
    {
        // At this point, the object allocated has two pointers:
        //      'cruiseControlMaster' and 'cruiseControlSlave' .
        std::shared_ptr<CruiseControl> cruiseControlSlave =
        std::make_shared<CruiseControl>();
        cruiseControlMaster = cruiseControlSlave;
    } 
    // When this block is closed, the cruiseControlSlave destructor is called 
    //but the object is not freed as it is still used by another one: cruiseControlMaster !

    std::cout << "shared_ptr test finished" << std::endl;

    return 0;
}