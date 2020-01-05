#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

namespace Tools
{
    template<typename RandIt>
    void print(RandIt begin, RandIt end, std::string separator = " ")
    {
        using value_type = typename std::iterator_traits<RandIt>::value_type;
        std::copy(begin, end, std::ostream_iterator<value_type>(std::cout, separator.c_str()));
        std::cout << std::endl;
    }

    template<typename Container>
    void print(const Container& container, std::string separator = " ")
    {
        print(std::begin(container), std::end(container), separator);
    }

	void generateRandomVector(std::vector<int>& v, unsigned int n, int lower_bound, int upper_bound);

    int random(int lower_bound, int upper_bound);

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