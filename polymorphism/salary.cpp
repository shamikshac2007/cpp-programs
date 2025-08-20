#include <iostream>
using namespace std ;

//Interface
//Pure Abstract Base Class
class IWorker{

    public :
    virtual void doWork()=0;
    virtual void fillTimesheet()=0;
    virtual void applyForLeave()=0;
    virtual void IsAvailableToWork()=0;
};


class Employee
{
    public:
    float basicSalary;
    float incomeTax;
    virtual float computePay()=0;  //pure virutal function
    void showBasicInome(){
        float package = basicSalary-incomeTax;
        cout << "Basic Income: " << package << endl;

    }
};

class Manager : public Employee,IWorker
{
    public:
    float incentive ;

    float computePay() override //enforce 
    {
        float package = basicSalary-incomeTax+incentive ;
        cout << "manager take home salary : " << package << endl;
    } 
    void doWork() override
    {}

 
     void fillTimesheet() override  { 

     }
    void applyForLeave() override  {

    }
    void IsAvailableToWork() override {

    }
};

int main()
{

    Manager mgr ;
    Employee * pEmployee=&mgr;

    pEmployee->basicSalary = 34000 ;
    pEmployee->incomeTax = 5000 ;
    pEmployee->computePay() ; //polymorphism

   
 

    return 0 ;

}