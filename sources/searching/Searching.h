#ifndef SEARCHING_H
#define SEARCHING_H

#include <tuple>
#include <vector>

namespace Algorithms
{
	namespace Searching
	{
		std::tuple<int, int, int> find_max_crossing_subarray(std::vector<int>& v, unsigned int low, unsigned int mid, unsigned int high)
		{
			int left_sum = INT_MIN;
			int right_sum = INT_MIN;

			int sum = 0;
			int max_left = 0;
			int max_right = 0;
			for (int i = mid; i > low; --i)
			{
				sum = sum + v[i];
				if (sum > left_sum)
				{
					left_sum = sum;
					max_left = i;
				}
			}

			sum = 0;
			for (int j = mid + 1; j < high; ++j)
			{
				sum = sum + v[j];
				if (sum > right_sum)
				{
					right_sum = sum;
					max_right = j;
				}
			}
			return std::make_tuple(max_left, max_right, left_sum + right_sum);
		}

		std::tuple<int, int, int> find_maximum_subarray(std::vector<int>& v, unsigned int low, unsigned int high)
		{
			if (high == low)
			{
				return std::make_tuple(low, high, v[low]);
			}
			else
			{
				int mid = (low + high) / 2;
				std::tuple<int, int, int> maxLeft = find_maximum_subarray(v, low, mid);
				std::tuple<int, int, int> maxRight = find_maximum_subarray(v, mid+1, high);
				std::tuple<int, int, int> maxCrossing = find_max_crossing_subarray(v, low, mid, high);
				int& left_low = std::get<0>(maxLeft);
				int& left_high = std::get<1>(maxLeft);
				int& left_sum = std::get<2>(maxLeft);

				int& right_low = std::get<0>(maxRight);
				int& right_high = std::get<1>(maxRight);
				int& right_sum = std::get<2>(maxRight);

				int& cross_low = std::get<0>(maxCrossing);
				int& cross_high = std::get<1>(maxCrossing);
				int& cross_sum = std::get<2>(maxCrossing);

				if (left_sum >= right_sum && left_sum >= cross_sum)
				{
					//return std::make_tuple(left_low, left_high, left_sum);
					return maxLeft;
				}
				else if (right_sum >= left_sum && right_sum >= cross_sum)
				{
					//return std::make_tuple(right_low, right_high, right_sum);
					return maxRight;
				}
				else
				{
					//return std::make_tuple(cross_low, cross_high, cross_sum);
					return maxCrossing;
				}
			}
		}
		std::vector<int> find_maximum_subarray(std::vector<int>& v, int& sum)
		{
			std::tuple<int, int, int> result = find_maximum_subarray(v, 0, v.size()-1);
			int& minIndex = std::get<0>(result);
			int& maxIndex = std::get<1>(result);
			sum = std::get<2>(result);
			std::vector<int> retval;
			retval.resize(maxIndex - minIndex + 1);
			for (int i = 0; i < retval.size(); ++i)
			{
				retval[i] = v[i + minIndex];
			}
			return retval;

		}
	};

};
#endif