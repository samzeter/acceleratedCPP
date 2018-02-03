#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main()
{
  //ask for the student's name
  std::cout << "What is your name? " << "\n";
  std::string name;
  std::cin >> name;
  std::cout << "Hello " << name << "\n";

  //ask for and read the midterm and final grades
  std::cout << "Please enter your midterm and final  grades" << "\n";
  double midterm, final;
  std::cin >> midterm >> final;

  //ask for a read the homework grades
  std::cout << "Enter all your homework grades ,"
    "followed by end-of-file: ";

  std::vector<double> homework;
  double x;

  //invariant: homework contains all the homework grades read so far
  while (std::cin >> x)
    homework.push_back(x);

  //check that the student entered some homework grades
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = homework.size();
  if (size == 0)
    {
      std::cout << "You must enter your grades" << std::endl;
      std::cout << "Please try again" << std::endl;
      return 1;
    }

  //sort the grades
  std::sort(homework.begin(), homework.end());

  //compute the median homework grade
  vec_sz mid = size / 2;
  double median;
  median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
    : homework[mid];

  //compute and write the final grade
  std::streamsize prec = std::cout.precision();
  std::cout << "Your final grade is " << std::setprecision(3)
            << 0.2 * midterm + 0.4 * final + 0.4 * median
            << std::setprecision(prec) << "\n";
  return 0;
}
