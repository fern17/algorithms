#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>


/**
\brief A namespace that stores all the Tools used by other classes and functions.
**/
namespace Tools
{
    /**
    \brief A function that prints the content of a container in the range [begin,end) with the given separator.
    **/
    template<typename RandIt>
    void print(RandIt begin, RandIt end, std::string separator = " ")
    {
        using value_type = typename std::iterator_traits<RandIt>::value_type;
        std::copy(begin, end, std::ostream_iterator<value_type>(std::cout, separator.c_str()));
        std::cout << std::endl;
    }

    /**
    \brief A function that prints the content of a container from its begin to its end (however it is defined when calling std::begin(container), with the given separator.
    **/
    template<typename Container>
    void print(const Container& container, std::string separator = " ")
    {
        print(std::begin(container), std::end(container), separator);
    }

    /**
    \brief A function that generates a random vector of n integers in the range [lower_bound, upper_bound].
    **/
	void generateRandomVector(std::vector<int>& v, unsigned int n, int lower_bound, int upper_bound);
    
    /**
    \brief A function that generates a random vector of n doubles in the range [lower_bound, upper_bound].
    **/
    void generateRandomVector(std::vector<double>& v, unsigned int n, double lower_bound, double upper_bound);

    /**
    \brief A function that generates a random integer value in the range [lower_bound, upper_bound].
    **/
    int random(int lower_bound, int upper_bound);
    
    /**
    \brief A function that generates a random double value in the range [lower_bound, upper_bound].
    **/
    double random(double lower_bound, double upper_bound);

    /**
    \brief A function that returns true if the given vector is sorted. False otherwise.
    **/
    template<typename Container>
    bool is_sorted(std::vector<Container>& v)
    {
        auto beg = std::begin(v);
        auto end = std::end(v);
        auto i = beg;
        auto j = beg;
        ++j;
        while (j != end && *i <= *j )
        {
            ++i;
            ++j;
        }
        if (j == end)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif