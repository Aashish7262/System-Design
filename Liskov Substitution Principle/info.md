### SUBCLASSES SHOULD BE SUBSTITUTABLE FOR THEIR BASE CLASSES
client  - > A 

           B 



           example UML diagram 
           
           <<abstract>>              Client
                                     vector<> acounts
           Account
           Deposite();
           withdraw();
             |                    |                          FixedDepositeAccount
                                                             Deposite();
        <!-- Saving_Account          Current_Account              Withdraw(){ throw expection };  --> client was not ready
        deposite                   deposite
        withdraw                   withdraw 

        Non- withdrawable Account


        Liskov Substitution Principle 


        client -> A  -> m1,m2,m3
                 |
                 B  -> m1,m2,m3 


                 Signature Rule      Broad -> Parent class and Narrow -> Child Class 
                 Property Rule       

    Signature class Example
    class Parent {
      void solve(string s){
        something
      }
    };

    class Child : class Parent{
      @Override
      void solve(string s){
        
      }
    };

    <!-- always keep in the mind that signature always matter -->


    Return Type Rule 
    class Parent {
       Animal random(){
                                                  <-   Client 
       }
    };

    class Child : public Parent{
      Animal random() {

      }
    };

    Exception Rule 

    Parent 

    Child 

    logic-error -> out of range example

    Parent 

      | 
    
    Child 
    
    