/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhodizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 15:30:39 by gkhodizo          #+#    #+#             */
/*   Updated: 2020/06/07 21:01:41 by gkhodizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** ISSUES:
** 1. Makefile does not compile with -D BUFFER_SIZE=32s flag
** 2. How to close fd, so no reference to it is left?
** 3. Color of system leak report is inherited and is not reset.
*/

#include "test.h"

int main(void)
{
	test_case_1();
	test_case_2();
	test_case_3();
	test_case_4();
	test_case_5();
	//test_case_6();
	test_case_7();
	test_case_8();

	/* SYSTEM LEAKS */
	system("leaks gnl");
	
	return (0);
}