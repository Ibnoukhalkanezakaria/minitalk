CC = gcc
CFLAGS = -Wall -Wextra -Werror
var = ft_printf/ft_putchar.c ft_printf/ft_printf_s.c ft_printf/ft_printf_d.c ft_printf/ft_printf_p.c ft_printf/ft_printf_u.c ft_printf/ft_printf_x.c ft_printf/ft_printf_xx.c ft_printf/ft_printf.c

all: client server 

bonus: client_bonus server_bonus

client_bonus: client_bonus.c ft_atoi.c 
	$(CC) $(CFLAGS) $^ $(var) -o $@

server_bonus: server_bonus.c ft_atoi.c
	$(CC) $(CFLAGS) $^ $(var) -o $@

client: client.c ft_atoi.c
	$(CC) $(CFLAGS) $^ $(var) -o $@

server: server.c ft_atoi.c
	$(CC) $(CFLAGS) $^ $(var) -o $@

clean:
	rm -f client server client_bonus server_bonus 