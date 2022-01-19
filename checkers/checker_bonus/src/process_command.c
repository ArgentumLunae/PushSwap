/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_command.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 09:03:42 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/19 09:06:58 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pschecker.h"
#include "../hdr/get_next_line.h"
#include "../incl/libft/libft.h"

static int	validate_cmnd(char *cmnd, char *cmnds[11])
{
	int	cnt;
	int	len;

	cnt = 0;
	while (cnt < 11)
	{
		len = ft_strlen(cmnds[cnt]);
		if (!ft_strncmp(cmnd, cmnds[cnt], len))
			return (cnt);
		cnt++;
	}
	return (-1);
}

int	read_cmnd(char **cmnds, t_func *func, t_stk *stk[2])
{
	char	*cmnd;
	int		cmndnr;
	int		cnt;

	cnt = 0;
	while (get_next_line(0, &cmnd))
	{
		cmndnr = validate_cmnd(cmnd, cmnds);
		if (cmndnr < 0 || cmndnr > 10)
			found_error(1);
		else
			func[cmndnr / 3](stk, (cmndnr % 3));
		cnt++;
	}
	return (cnt);
}