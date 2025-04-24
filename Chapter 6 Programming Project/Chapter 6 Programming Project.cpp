/*
Project 1. Rectangle Properties
Write a modular program that asks the user to enter the length and width of a rectangle. 
The program then calculates and displays the perimeter and area of the rectangle. 
The program should ask the user if they want to process another rectangle and continue to process rectangles 
until the user until the user decides to quit.

Input Validation: Do not accept negative values for length or the width. 

*/

//Headers files
#include <iostream>
#include <string>

/*
    Function   : getLength_Width
    Purpose    : Prompts the user to enter the length and width of a rectangle.
                 Validates that both values are greater than 0.
    Parameters :
        - double& length: reference to a double that stores the rectangle's length
        - double& width : reference to a double that stores the rectangle's width
    Returns    : Length and Width values returned by reference)
    Preconditions:
        - None
    Postconditions:
        - 'length' and 'width' will both be greater than 0
*/
void getLength_Width(double& length, double& width) {                       //		Pass by reference – length, width
    do {
        std::cout << "Enter length (> 0): ";                                //		User Input – length, width
        std::cin >> length;
        if (length <= 0) {                                                  //		Process – length and width must be > 0.
            std::cout << "Length must be greater than 0. Try again.\n";
        }
    } while (length <= 0);

    do {
        std::cout << "Enter width (> 0): ";                                 //		User Input – length, width
        std::cin >> width;
        if (width <= 0) {                                                   //		Process – length and width must be > 0.
            std::cout << "Width must be greater than 0. Try again.\n";
        }
    } while (width <= 0);
}

/*
    Function   : calcPerimeter
    Purpose    : Calculates the perimeter of a rectangle.
    Parameters :
        - double length: the length of the rectangle
        - double width : the width of the rectangle
    Returns    :
        - double: the perimeter calculated as 2 * (length + width)
    Preconditions:
        - length and width must both be greater than 0
    Postconditions:
        - Returns the computed perimeter
*/
double calcPerimeter(double length, double width) {     //	Input – The length and width of the rectangle
    return 2 * length + 2 * width;                      //  Process & Ouput – perimeter = 2 * length + 2 * width
}                                                       

/*
    Function   : calcArea
    Purpose    : Calculates the area of a rectangle.
    Parameters :
        - double length: the length of the rectangle
        - double width : the width of the rectangle
    Returns    :
        - double: the area calculated as length * width
    Preconditions:
        - length and width must both be greater than 0
    Postconditions:
        - Returns the computed area
*/
double calcArea(double length, double width) {          //	Input – The length and width of the rectangle
    return length * width;                              //	Process & Output - area = length * width
}                                               
                                                 
/*
    Function   : displayProperties
    Purpose    : Displays the perimeter and area of a rectangle.
    Parameters :
        - double perimeter: the perimeter of the rectangle
        - double area     : the area of the rectangle
    Returns    : None
    Preconditions:
        - perimeter and area must be correctly calculated prior to the call
    Postconditions:
        - Outputs perimeter and area to the console
*/
void displayProperties(double Perimeter, double Area) {         //		Input – The perimeter and area of a rectangle
    std::cout << "The perimeter is " << Perimeter << std::endl; //		Output – Displays the perimeter and rectangle
    std::cout << "The area is " << Area << std::endl;

}

/*
    Function   : main
    Purpose    : Runs the rectangle processing loop, calling necessary functions
                 until the user decides to quit.
    Parameters : None
    Returns    :
        - 0 upon successful execution
    Preconditions:
        - None
    Postconditions:
        - Continues to prompt the user until "quit" is entered
*/
int main() {
   
    double length, width;   // Declares variables to store Length and Width values of the rectangle
    std::string input;      // Variable for storing string input for quit condition evaluation
    
    // Runs program once and then checks if user wants to quit or continue
    do {
        getLength_Width(length, width);

        double Perimeter = calcPerimeter(length, width);
        double Area = calcArea(length, width);

        displayProperties(Perimeter, Area);

        std::cout << "Do you want to process another rectangle? (type 'quit' to exit): "; // Asks quit or continue question
        std::cin >> input;  //Stores input for evaluation

    } while (input != "quit"); //If input is quit then program ends. If input is anything else then program loops over again.
    return 0;
}
