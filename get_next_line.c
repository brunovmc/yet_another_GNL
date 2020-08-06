/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:09:20 by bvidigal          #+#    #+#             */
/*   Updated: 2020/08/02 12:26:35 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"


// char	*ft_substr(char *s, int start, size_t len)
// {
// 	char	*dest;
//
// 	if (s == NULL)
// 		return (NULL);
// 	dest = (char *)malloc(sizeof(char) * len + 1);
// 	if (dest == NULL)
// 		return (NULL);
// 	len = (start < ft_strlen(s)) ? len : 0;
// 	ft_memcpy(dest, s + start, len);
// 	dest[len] = '\0';
// 	return (dest);
// }
int     get_next_line(int fd, char **line)
{
    //static char *schar;
    char        buf[BUFFER_SIZE + 1];
    char        *tmp;
    static char        *off;
    int         rd;
    int         i;
    int         j;

    buf[BUFFER_SIZE + 1] = '\0';
    rd = read(fd, buf, BUFFER_SIZE);
    if (fd < 0 || line == NULL || BUFFER_SIZE < 1 )
		return (-1);
    i = 0;
    while (buf[i] != '\n' && buf[i] != '\0')
        i++;
    tmp = malloc(sizeof(char) * i + 1);
    tmp[i + 1] = '\0';
    j = i;
    while (i >= 0)
    {
        tmp[i] = buf[i];
        i--;
    }
    off = malloc(sizeof(char) * ((BUFFER_SIZE + 1) - j));
    while (buf[j] != '\0')
    {
        off[0 + i++] = buf[j];
        j++;
        if(buf[j] == '\n')
            break ;
    }
    printf("off = %s\n", off);
    printf("i = %d\n", i);
    if(rd > 0)
    {
        if (*line != NULL)
        {
                *line = off;
            return (1);
        }
        *line = tmp;
        return (1);
    }
    return (0);
}
