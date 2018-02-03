/*
  ""The complete framing program"" from Accelerated C++, Koenig & Moo, 2000.
   Describes for and while loops for learning purposes.
   -Sam Zeter, Janurary 2018
*/

#include <iostream>
#include <string.h>

int main()
{
//ask for the person's name
    std::cout << "Please enter your first name" << std::endl;

    // read the name
    std::string name;
    std::cin >> name;

    // build the message we intend to write
    // whenever we need the local variable to hold the size
    // of a string - use string::size_type
    const std::string greeting = "Hello " + name + "!\n";

    // number of blanks either side of greeting
    const int pad = 1 ;

    // number of rows and columns to write
    const int rows = pad * 2 + 3;
    const std::string::size_type cols = greeting.size() + pad * 2 + 2;

    // write a blank line to separate the output from the input
    std::cout << std::endl;

    // invariant: we have written r rows so far
    // invariant = a property that we assert will be true about a while
    // each time it is about to test its condition
    for (int r = 0; r!= rows; ++r)
    {
        std::string::size_type c = 0;
        // invariant: we have written c characters so far in the current row
        while (c != cols)
        {
            //is it time to write the greeting?
            if (r == pad + 1 && c == pad +1)
            {
                std::cout << greeting;
                c += greeting.size();
            } else
            {
                // are we on the border?
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    std::cout << "*";
                else
                    std::cout << " ";
                ++c;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
