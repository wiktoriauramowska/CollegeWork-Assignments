"""
Author: Wiktoria Uramowska
Student number: C17742751
Date: 06/11/2018
Program Description:
    This program demonstrates the use of the abstract classes via the abc module.
"""

from abc import ABC, abstractmethod

# The base abstract class that uses the abstract method ABC
class MathsGame(ABC):
    # constructor
    def __init__(self, value):
        self.value = value
        super().__init__()
    """
    The use of super() will allow the rest of the games use the variable value, without the need
    to call the base class directly
    """
    @classmethod
    @abstractmethod
    def do_something(self):
        pass

"""
Class that gives an example how the base abstract class will work for any other games that will be added.
It shows how the base class is being inherited
"""
class AnotherGame(MathsGame):
    def do_something(self):
        self.value = int(self.value) + 42
        print(self.value)

"""
The class responsible for the Fibonacci Game. Inside it, there is a function that takes user input,
as for the number of terms from the Fibonacci sequence to be displayed, and iterates through a while loop
with a condition checking for the value of count variable and number entered bby the user.
"""
class FibonacciGame(MathsGame):

    def do_something(self):
        numberOfTerms = int(self.value)

        # first two terms are initialized as only this can allow to calculate the rest of them
        n1 = 1
        n2 = 1
        count = 0

        # check if the number of terms is valid
        if numberOfTerms <= 0:
            print("Please enter a positive integer!")
        elif numberOfTerms == 1:
            print("Fibonacci sequence up to", numberOfTerms, ":")
            print(n1)
        else:
            print("Fibonacci sequence up to", numberOfTerms, ":")
            while count <= numberOfTerms:
                if count == numberOfTerms:
                    print(n1)
                    break
                else:
                    print(n1, end=' , ')
                    nth = n1 + n2
                    # update values
                    n1 = n2
                    n2 = nth
                    count += 1

"""
After the initialization of the classes, I assigned the FibonacciGame class to a, what allows later on
to display the game. 
To value b, I assigned the AnotherGame class, just to show the inheritance and the purpose of using super(),
in the base class. As the abstract method had a function called do_something, the rest of the functions 
that inherit from there have to be called the same way
"""
print("***That is the Fibonacci game***")
a = FibonacciGame(value = input("How many terms? "))
print(a.do_something())

print("***That is another game example***")
b = AnotherGame(value= input("Input your number: "))
print(b.do_something())
