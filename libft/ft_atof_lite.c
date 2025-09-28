/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_lite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:04:01 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/28 00:44:04 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(const char **nptr)
{
	if (**nptr == '-')
	{
		++(*nptr);
		return (-1);
	}
	else if (**nptr == '+')
		++(*nptr);
	return (1);
}

static double	process_integer_part(const char **nptr)
{
	double	res;

	res = 0.0;
	while (ft_isdigit(**nptr))
	{
		res = res * 10.0 + ft_ascii_to_num(**nptr);
		++(*nptr);
	}
	return (res);
}

static double	process_decimal_part(const char **nptr, double *decimal_fractor)
{
	double	fraction;

	fraction = 0.0;
	*decimal_fractor = 1.0;
	if (**nptr == '.')
	{
		++(*nptr);
		while (ft_isdigit(**nptr))
		{
			fraction = fraction * 10.0 + ft_ascii_to_num(**nptr);
			*decimal_fractor *= 10.0;
			++(*nptr);
		}
	}
	return (fraction);
}

double	ft_atof_lite(const char *nptr)
{
	int		sign;
	double	integer_part;
	double	fraction_part;
	double	decimal_factor;

	while (ft_isspace(*nptr))
		nptr++;
	sign = get_sign(&nptr);
	integer_part = process_integer_part(&nptr);
	fraction_part = process_decimal_part(&nptr, &decimal_factor);
	return (sign * (integer_part + fraction_part / decimal_factor));
}

// static int	get_sign(const char **nptr)
// {
// 	if (**nptr == '-')
// 	{
// 		(*nptr)++;
// 		return (-1);
// 	}
// 	else if (**nptr == '+')
// 		(*nptr)++;
// 	return (1);
// }

// static double get_value(const char **nptr, double *decimal_factor)
// {
// 	double	res;
// 	int		is_decimal;

// 	res = 0.0;
// 	is_decimal = 0;
// 	while (**nptr)
// 	{
// 		if (ft_isdigit(**nptr))
// 		{
// 			res = res * 10.0 + ft_ascii_to_num(**nptr);
// 			if (is_decimal)
// 				*decimal_factor *= 10.0;
// 		}
// 		else if (**nptr == '.' && !is_decimal)

// 	}
// }

// double	ft_atof(const char *nptr)
// {
// 	double	res;
// 	int		sign;
// 	double	decimal_factor;

// 	decimal_factor = 1.0;
// 	while (ft_isspace(*nptr))
// 		nptr++;
// 	sign = get_sign(&nptr);
// 	res = get_value(&nptr, &decimal_factor);
// 	res = get_exponent(&nptr, res);
// }
//
// #include <stdio.h>
// int main(void)
// {
// 	// 様々な入力でテスト
// 	printf("Test 1: %.1lf\n", ft_atof_lite("789.2"));      // 789.2
// 	printf("Test 2: %.3lf\n", ft_atof_lite("-123.456"));   // -123.456
// 	printf("Test 3: %.1lf\n", ft_atof_lite("+0.5"));       // 0.5
// 	printf("Test 4: %.0lf\n", ft_atof_lite("42"));         // 42
// 	printf("Test 5: %.4lf\n", ft_atof_lite("  -0.0001")); // -0.0001
// 	printf("Test 6: %.2lf\n", ft_atof_lite(".25"));        // 0.25

// 	// %g を使うと自動的に適切な桁数で表示
// 	printf("\nUsing %%g format:\n");
// 	printf("Test 1: %g\n", ft_atof_lite("789.2"));         // 789.2
// 	printf("Test 2: %g\n", ft_atof_lite("-123.456"));      // -123.456
// 	printf("Test 3: %g\n", ft_atof_lite("42"));            // 42

// 	return 0;
// }
