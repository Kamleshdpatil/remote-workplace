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
        Subtypes should be substituable for thier base types without affecting the correctness of the program.
    
    4] Interface Segregation Principle (ISP)
        A class should not be forced to implement interfaces it does not use.

    5] Dependency Inversion Principle (DIP)
        High-level modules should not depend on low-level modules. Both should depend on abstractions.
    
    The SOLID principles help in building scalable, maintainable, and flexible software.
        SRP - ensures that classes have a single responsibility.
        OCP - allows extending functionality without modifying existing code.
        LSP - ensures that subclasses do not break the behavior of base classes.
        ISP - prevents forcing classes to implement unnecessary methods.
        DIP - promotes dependency on abstractions rather than concrete implementations.
*/

