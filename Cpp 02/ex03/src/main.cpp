/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:29:32 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 13:29:33 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

bool check_points(int a[2], int b[2], int c[2], int point[2])
{
	Point first(a[0], a[1]);
	Point second(b[0], b[1]);
	Point third(c[0], c[1]);
	Point to_check(point[0], point[1]);

	/*std::cout << first.getX() << first.getY() << std::endl;
	std::cout << second.getX() << second.getY() << std::endl;
	std::cout << third.getX() << third.getY() << std::endl;
	std::cout << to_check.getX() << to_check.getY() << std::endl;*/

	return bsp(first, second, third, to_check);
}

int *getArray(int a, int b)
{
	int *array = new int[2];
	array[0] = a;
    array[1] = b;
	return (array);
}

int main(void)
{
	std::cout << check_points(getArray(0, 0), getArray(4, 0), getArray(2, 4),getArray(1, 1)) << std::endl;
	std::cout << check_points(getArray(0, 0), getArray(4, 0), getArray(2, 4),getArray(50, 50)) << std::endl;

}
