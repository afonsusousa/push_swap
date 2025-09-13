/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:57:37 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/03 20:04:20 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_gnl_list
{
	int					fd;
	char				*str;
	struct s_gnl_list	*next;
}	t_gnl_list;

char	*ft_strcnpy(t_gnl_list *lst, char *dest, int fd);
int		ft_newlen(char *str);
t_gnl_list	*ft_gnl_lstlast(t_gnl_list *lst, int fd);
void	ft_gnl_add_back(t_gnl_list **lst, char *str, int fd);
void	ft_gnl_freelist(t_gnl_list **lst, int fd);
int		ft_gnl_foundnew(t_gnl_list *lst, int fd);
void	get_list(t_gnl_list **dest, int fd);
char	*serve_line(t_gnl_list *lst, int fd);
void	clean_list(t_gnl_list **lst, int fd);
char	*get_next_line(int fd);

#endif
