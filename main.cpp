// Programmer: Sophia Bhoria
// Date: Nov 05, 2024
// Purpose: Defines a Dimensions class with overloaded operators to add and subtract dimensions. 

#include <iostream>
using namespace std;

class Dimensions {
private:
    int length; // Stores the length of the Dimensions object
    int width;  // Stores the width of the Dimensions object

public:
    /*
    General Description: Initializes a Dimensions object with given length and width values.
    Precondition: Length and width should be non-negative values (default values are 0)
    Postcondition: A Dimensions object is created with the specified length and width, cast to int.
     */
    Dimensions(const double length = 0, const double width = 0) : length(static_cast<int>(length)), width(static_cast<int>(width)) {}

    /*
     * General Description: Adds the length and width of another Dimensions object to the calling object.
     * Precondition: The parameter `dim` must be a valid Dimensions object.
     * Postcondition: The calling object's length and width are incremented by `dim`'s length and width.
     */
    Dimensions& operator +=(const Dimensions &dim) {
        length += dim.length;
        width += dim.width;
        return *this;
    }

    /*
     * General Description: Adds the length and width of another Dimensions object and returns a new Dimensions object.
     * Precondition: The parameter `dim` must be a valid Dimensions object.
     * Postcondition: A new Dimensions object is returned with its length and width as the sum of the calling object and `dim`.
     */
    Dimensions operator +(const Dimensions &dim) const {
        return Dimensions(length + dim.length, width + dim.width);
    }

    /*
     * General Description: Subtracts a given value from both length and width of the calling object.
     * Precondition: The parameter `val` should be a non-negative double value.
     * Postcondition: The calling object's length and width are reduced by `val`, cast to int.
     */
    Dimensions& operator -=(const double val) {
        length -= static_cast<int>(val);
        width -= static_cast<int>(val);
        return *this;
    }

    /*
     * General Description: Subtracts a given value from both length and width of the calling object and returns a new object.
     * Precondition: The parameter `val` should be a non-negative double value.
     * Postcondition: A new Dimensions object is returned with length and width reduced by `val`, cast to int. 
     */
    Dimensions operator -(const double val) const {
        return Dimensions(length - static_cast<int>(val), width - static_cast<int>(val));
    }

    /* 
     * General Description: Outputs the length and width of a Dimensions object in a specific format.
     * Precondition: The parameter `dim` should be a valid Dimensions object.
     * Postcondition: The length and width of `dim` are output in the format "length: x, width: y".
     */
    friend ostream &operator<<(ostream &output, const Dimensions &dim) {
        output << "length: " << dim.length << ", width: " << dim.width;
        return output;
    }
};

int main() {
    //Create 4 objects of class Dimensions with specified initial values.
    Dimensions obj1(50, 40), obj2(10, 5), obj3, obj4;

    // Output initial values of obj1 and obj2.
    cout << "Initial values of obj1 and obj2:" << endl;
    cout << obj1 << endl;
    cout << obj2 << endl;
    cout << endl;

    //Perform obj1 += obj2, and display updated obj1.
    obj1 += obj2;
    cout << "After performing obj1 += obj2, obj1 is" << endl;
    cout << obj1 << endl;
    cout << endl;

    //Perform obj3 = obj1 + obj2, and display obj3.
    obj3 = obj1 + obj2;
    cout << "After performing obj3 = obj1 + obj2, obj3 is" << endl;
    cout << obj3 << endl;
    cout << endl;

    //Subtract 5 from obj1 using obj1 -= 5, and display updated obj1.
    obj1 -= 5;
    cout << "After performing obj1 -= 5, obj1 is" << endl;
    cout << obj1 << endl;
    cout << endl;

    //Perform obj4 = obj1 - 10, and display obj4.
    obj4 = obj1 - 10;
    cout << "After performing obj4 = obj1 - 10, obj4 is" << endl;
    cout << obj4 << endl;

    return 0;
}
