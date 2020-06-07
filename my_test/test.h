/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhodizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:28:55 by gkhodizo          #+#    #+#             */
/*   Updated: 2020/06/07 16:09:26 by gkhodizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../get_next_line.h"
#include "color.h"

/* read single line tests */

void	test_case_1();
void	test_case_2();
void	test_case_3();
void	test_case_4();
void	test_case_5();
void	test_case_6();

/* read the entire document tests */

void	test_case_7();
void	test_case_8();

#endif
