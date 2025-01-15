/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:04:19 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/15 13:30:46 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define DEBUG 1
#define TROLL "Some smart ancient said \"Even if you only drive backward, the mileage grow positive\"\n"

void	hint_ft(int i, const char *func)
{
	if (DEBUG)
	{
		if (i)
			printf("entering in function ");
		else
			printf("leaving function ");
		printf("%s\n", func);
	}
}

void	estimatePrice(int mileAge)
{
	hint_ft(1, __func__);
	{
		static	int thetaZer = 0;
		static	int thetaOne = 0;
		int			estimatePrice = 0;

		estimatePrice = thetaZer + (thetaOne * mileAge);
		printf("\testimatePrice = %d\n", estimatePrice);
	}
	hint_ft(0, __func__);
}

int		promptForMileage(void)
{
	hint_ft(1, __func__);
	int mileAge;
	int	pickyOne = 0;

	{
		mileAge = 0;
		while (mileAge <= 0)
		{
			printf("requested mileage.\n\t> ");
			scanf("%d", &mileAge);
			printf("%d\n", mileAge);
		}
	}
	hint_ft(0, __func__);
	return (mileAge);
}

int		main(int ac, char **av)
{
	hint_ft(1, __func__);
	{
		int	mileAge;
		if (ac == 1)
		{
		// prompt for mileage
			mileAge = promptForMileage();
		// estimate the price for that mileage
			estimatePrice(mileAge);
		}
	}
	hint_ft(0, __func__);
	return (0);
}

/*
scanf has a number of problems--see questions 12.17, 12.18a, and 12.19. Also, its %s format has the same problem that gets() has 
(see question 12.23)--it's hard to guarantee that the receiving buffer won't overflow. [footnote] More generally, scanf is designed 
for relatively structured, formatted input (its name is in fact derived from ``scan formatted''). If you pay attention, it will tell 
you whether it succeeded or failed, but it can tell you only approximately where it failed, and not at all how or why. You have very 
little opportunity to do any error recovery. Yet interactive user input is the least structured input there is. A well-designed user 
interface will allow for the possibility of the user typing just about anything--not just letters or punctuation when digits were 
expected, but also more or fewer characters than were expected, or no characters at all (i.e. just the RETURN key), or premature 
EOF, or anything. It's nearly impossible to deal gracefully with all of these potential problems when using scanf; it's far easier 
to read entire lines (with fgets or the like), then interpret them, either using sscanf or some other techniques. (Functions like 
strtol, strtok, and atoi are often useful; see also questions 12.16 and 13.6.) If you do use any scanf variant, be sure to check 
the return value to make sure that the expected number of items were found. Also, if you use %s, be sure to guard against buffer 
overflow. Note, by the way, that criticisms of scanf are not necessarily indictments of fscanf and sscanf. scanf reads from stdin, 
which is usually an interactive keyboard and is therefore the least constrained, leading to the most problems. When a data file has 
a known format, on the other hand, it may be appropriate to read it with fscanf. It's perfectly appropriate to parse strings with 
sscanf (as long as the return value is checked), because it's so easy to regain control, restart the scan, discard the input if it 
didn't match, etc.
*/