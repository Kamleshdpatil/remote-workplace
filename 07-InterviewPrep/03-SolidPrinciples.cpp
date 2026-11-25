/*
                                    ||| SOLID PRINCIPLES |||
    -> Set of 5 design principles aimed at improving 1) Maintainability, 2) Scalability, 3) Robustness 
    of our object oriented software(Application).

    1] Single Responsibility Principle (SRP)
        Only one reason to chnage, and single responsibility.
        Ex. Logger class

    2] Open/Closed Principle (O/CP)
        Open for extension and close for modification.
        Ex. Shape class (Abstract class) - Should not be modify, but it could be extend to use.
    
    3] Liksow Substitution Principles(LSP)
        Subtypes should be substituable for thier base types without affecting the correctness 
        of the program.
    
    4] Interface Segregation Principle (ISP)
        A class/Client should not be forced to implement interfaces it does not use.
        - Many client specific interface are better than our general purpose interface.


    5] Dependency Inversion Principle (DIP)
        High-level modules should not depend on low-level modules. Both should depend on abstractions.
    
    The SOLID principles help in building scalable, maintainable, and flexible software.
        SRP - ensures that classes have a single responsibility.
        OCP - allows extending functionality without modifying existing code.
        LSP - ensures that subclasses do not break the behavior of base classes.
        ISP - prevents forcing classes to implement unnecessary methods.
        DIP - promotes dependency on abstractions rather than concrete implementations.


    LSP Guidelines:
        1) Signature Rule:
            - Method Argument Rule: Member Function parameters type should be same.
            - Return Type Rule: Retuen type of member function should be same or narrow type. Should not be different.
            - Exception Rule: Handle only parent type exception in child
            
            |-- std::logic_error            <-- For logical errors detected before runtime
            |   |-- std::invalid_argument       <-- Invalid function argument
            |   |-- std::domain_error           <-- Fucntion argument domain error
            |   |-- std::length_error           <-- Exceeding valid length limits
            |   |-- std::out_of_range           <-- Array or container index out of bounds
            |
            |-- std::runtime_error          <-- For errors that occurs at runtime
            |   |-- std::range_error            <-- Numeric result out of range
            |   |-- std::overflow_error         <-- Arithmatic overflow
            |   |-- std::underflow_error        
            |

        2) Property Rule:
            a) Class Invariant:
                - Class Invariant of a parent class object should not be broken by child class object.
                - Hence child class can either maintain or strengthen the invariant but never narrows it down. 

            b) History Constraint:
                - Sub class methods should not be allowed state changes what Base class never allowed.

        3) Method Rule:
            a) Pre-condition
                - Subclass methods can weak pre-conditions but not strengthen.

            b) Post-condition
                - Subclass methods can add contraints but do not weak.

        
*/

