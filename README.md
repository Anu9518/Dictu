# Dictu

*What is Dictu?*  
Dictu is a very simple dynamically typed programming language 
built upon the [craftinginterpreters tutorial](http://www.craftinginterpreters.com/contents.html).

*What does Dictu mean?*  
Dictu means `simplistic` in Latin.

### Dictu language examples

*Variable declaration:*
```
var someNumber = 10;
var someString = "hello";
var someOtherString = 'hello';
var someBoolean = true;
var someFalseBoolean = false;
var someNilValue = nil;
var someOtherNilValue; // Variables declared without a value are set to nil
car someList = [1, 2, "hi", 'hi', nil, true, false]; // Lists can hold any value
```
*Operators*
```
var test = 1; // Variable declaration

test = test + 1; // Addition. Variable 'test': 2
test = test - 1; // Subtraction. Variable 'test': 1
++test; // Prefix incremenet. Variable 'test': 2
--test; // Prefix decrement. Variable 'test': 1
test = test * 10; // Multiplication. Variable 'test': 10
test = test / 2; // Division. Variable 'test': 5
```
*Lists*
```
var myList = [1, 2, 3, 4]; // Assigning a list
var someListElement = myList[0]; // Lists are 0 indexed
var someOtherListElement = myList[-1]; // Negative indexes start from the back of the list
push(myList, 10); // Push an element to the end of a list
var aNewListElement = pop(myList); // Pops an element off the end of a list
```
*Comments*
```
// This is a single line comment

/*
this
is
a
multiline
comment
*/
```
*If statements*
``` 
if (false or true) {
    var variable = "Hello";
    print(variable);  // Print is a native function so parenthesis are required
}

// Single line if statement body does not require braces
if (true)
    print("Hello");
```
*Conditional expressions*
```
var someVar = 10;
var someTestVar = 11;

if (someVar == 10 and someTestVar == 11)
    print("True!");
    
if (someVar == 9 or someTestVar == 11)
    print("True!");
    
if (someVar >= 9)
    print("True!");
    
if (someVar <= 9)
    print("False!");
    
if (someVar > 9)
    print("True!");
    
if (someVar < 9)
    print("False!");
    
var someBoolean = false;
someBoolean = !someBoolean;
```
*Loops*
```
// For loop
for (var i = 0; i < 10; ++i) {
    print(i);
}

// While loop
var i = 0;
while (i < 10) {
    print(i);
    ++i;
}

// While 'true' loop
// If no expression is made, true is implicitly assumed
while {
    print("Hello");
}
```
*Functions*
```
//Define the function 
def someFunction() {
    print("Hello!");
}

someFunction(); // Call the function

def someFunctionWithArgs(arg1, arg2) {
    print(arg1 + arg2);
}

someFunctionWithArgs(5, 5); // 10
someFunctionWithArgs("test", "test"); //testtest

def someFunctionWithReturn() {
    return 10;
}

print(someFunctionWithReturn()); // 10
```
*Classes*
```
class SomeClass {
    // Constructor
    init() {
        print("Object created!");
    }
}

var myObject = SomeClass(); // Instantiate the class

class SomeNewClass {
    // Constructor
    init(someArg) {
        this.someArg = someArg;
    }
    
    // 'this' is passed implicitly to all methods
    printSomeArg() {
        print(this.someArg);
    }
}

var myObject = SomeNewClass("Instance variables!!"); // Instantiate the class
myObject.printSomeArg(); // Call the method

class SomeOtherClass {
    init(someArg) {
        this.someArg = someArg;
    }
    
    // 'this' is not passed to static methods
    static printHello() {
        print("Hello");
    }
}

SomeOtherClass.printHello(); // Static methods dont need the object to be instantiated 
```
*Built-in functions*
```
print(10, "test", nil, true); // Each argument is printed
sleep(10); // Pauses execution for time specified (seconds)
assert(true) // Returns a runtime errorr if expression passed is false
push(list, 10); // Push element to the end of a list
var x = pop(list); // Pop element off the end of a list
var x = min(1, 2, 3); // Returns the smallest number of the arguments
var x = min([1, 2, 3]); // min() also accepts lists
var x = max(1, 2, 3); // Returns the largest number of the arguments
var x = max([1, 2, 3]); // max() also accepts lists
var x = average(1, 2, 3); // Returns an average number of the arguments
var x = average([1, 2, 3]); // average() also accepts lists
var x = sum(1, 2, 3); // Returns a sum of all arguments passed
var x = sum([1, 2, 3]); // sum() also accepts lists
var x = floor(17.4); // Returns previous integer: 17
var x = round(17.4); // Rounds to the nearest integer: 17
var x = ceil(17.4); // Returns next integer: 18
var x = abs(-10); // Returns absolute value: 10
var x = time(); // Returns UNIX timestamp
var x = len("test"); // Returns the string length
var x = input(); // Returns user input as a string
var x = input("Input: "); // Returns user input as a string. Can pass an optional prompt
```

## Running Dictu
```bash
$ git clone x
$ cd Dictu
$ make dictu
$ ./dictu examples/guessingGame.du
```
