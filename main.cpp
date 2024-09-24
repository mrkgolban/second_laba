#include <iostream>
#include<math.h>

#include <iomanip>
#include <limits>
#include <numbers>
long double param;
long double f(long double x)
{
  return std::sin(x) - param;
}



long double solve_bls(long double a, long double b, long double eps, long double param)
{
  long double c = 0;
  for (int i = 0; i < eps * 10; i++)
  {
    c = (a + b) / 2;
    if (f(c) * f(b) < 0)
    {
        a = c;
    }
    else 
    {
      b = c;
    }
  }
  std::cout << std::setprecision(eps) << c << "\n";
  return 0;
}

long double solve_chord(long double a, long double b, long double eps, long double param)
{
  for (int i = 0; i < eps * 10; i++)
  {
    a = (f(b) * a - f(a) * b)/(f(b) - f(a));
  }
  std::cout << std::setprecision(eps) << a << "\n";
  return 0;

}

int solve(int method, long double a, long double b, long double eps, long double param)
{
  if (f(a) * f(b) < 0)
  {
    switch (method)
    {
    case 1:
      solve_bls(a, b, eps, param);
      break;
    case 2:
      solve_chord(a, b, eps, param);
    case 3:
      solve_bls(a, b, eps, param);
      solve_chord(a, b, eps, param);
      break;
    default:
      std::cout << "Wrong input(" << std::endl;
    }
    return 0;
  }
  else
  {
    return 1;
  }
}

int main()
{

  long double a, b, eps;
  int method;
  std::cout << "Метод: ";
  std::cin >> method;
  std::cout << "a = ";
  std::cin >> a;
  std::cout << "b = ";
  std::cin >> b;
  std::cout << "eps = ";
  std::cin >> eps;
  std::cout << "Параметр = ";
  std::cin >> param;
  return solve(method, a, b, eps, param);
  

}