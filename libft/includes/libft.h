/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:25:51 by jwinthei          #+#    #+#             */
/*   Updated: 2021/02/11 12:37:12 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <errno.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <wchar.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "ft_printf.h"
# include "t_data.h"

typedef uint8_t			t_bool;
typedef __int128_t		t_int128;
typedef __uint128_t		t_uint128;

# define FAILURE		(int8_t)-1
# define SUCCESS		(int8_t)0

# define FALSE			(t_bool)0
# define TRUE			(t_bool)1

# define BYTE_SIZE  	(uint8_t)8
# define BIT_16			(uint8_t)16
# define BIT_32			(uint8_t)32
# define BIT_64			(uint8_t)64
# define BIT_128		(uint8_t)128
# define BYTE_16		(uint8_t)(BIT_16 / BYTE_SIZE)
# define BYTE_32		(uint8_t)(BIT_32 / BYTE_SIZE)
# define BYTE_64		(uint8_t)(BIT_64 / BYTE_SIZE)
# define BYTE_128		(uint8_t)(BIT_128 / BYTE_SIZE)

# define MIN_INT16		(uint16_t)0x8000
# define MAX_INT16		(uint16_t)0x7fff
# define MAX_UINT16		(uint16_t)0xffff
# define MIN_INT32 		(uint32_t)0x80000000
# define MAX_INT32 		(uint32_t)0x7fffffff
# define MAX_UINT32 	(uint32_t)0xffffffff
# define MIN_INT64 		(uint64_t)0x8000000000000000
# define MAX_INT64 		(uint64_t)0x7fffffffffffffff
# define MAX_UINT64		(uint64_t)0xffffffffffffffff
# define MAX_INT128 	(t_uint128)0x7fffffffffffffffffffffffffffffff
# define MIN_INT128 	(t_uint128)0x80000000000000000000000000000000
# define MAX_UINT128	(t_uint128)0xffffffffffffffffffffffffffffffff

# define BUF_SIZE  		4096
# define BUFF_SIZE 		1
# define MAX_FD    		15000

# define BELL			'\a'

# define DEFAULT		"\033[0m"
# define GRAY_B			"\033[1;30m"
# define GRAY_D			"\033[2;30m"
# define GRAY_L			"\033[90m"
# define GRAY			GRAY_B
# define RED_B			"\033[1;31m"
# define RED_D			"\033[2;31m"
# define RED_L			"\033[91m"
# define RED			RED_L
# define GREEN_B		"\033[1;32m"
# define GREEN_D		"\033[2;32m"
# define GREEN_L		"\033[92m"
# define GREEN			GREEN_L
# define YELLOW_B		"\033[1;33m"
# define YELLOW_D		"\033[2;33m"
# define YELLOW_L		"\033[93m"
# define YELLOW			YELLOW_L
# define BLUE_B 		"\033[1;34m"
# define BLUE_D 		"\033[2;34m"
# define BLUE_L 		"\033[94m"
# define BLUE		    BLUE_L
# define MAGENTA_B 		"\033[1;35m"
# define MAGENTA_D 		"\033[2;35m"
# define MAGENTA_L 		"\033[95m"
# define MAGENTA		MAGENTA_L
# define CYAN_B 		"\033[1;36m"
# define CYAN_D 		"\033[2;36m"
# define CYAN_L 		"\033[96m"
# define CYAN		    CYAN_L
# define ERR			RED
# define ERR2			RED_B
# define WARN			YELLOW
# define WARN2			YELLOW_B
# define OK				GREEN
# define OK2			GREEN_B

# define RAND_DIR		"/dev/urandom"

# define SHIFTR(x, n)	((x) >> (n))
# define SHIFTL(x, n)	((x) << (n))
# define ROTR(b, x, n)	(((x) >> (n)) | ((x) << ((b) - (n))))
# define ROTL(b, x, n)	(((x) << (n)) | ((x) >> ((b) - (n))))
# define ROTR32(x, n)	(((x) >> (n)) | ((x) << (32 - (n))))
# define ROTL32(x, n)	(((x) << (n)) | ((x) >> (32 - (n))))
# define ROTR64(x, n)	(((x) >> (n)) | ((x) << (64 - (n))))
# define ROTL64(x, n)	(((x) << (n)) | ((x) >> (64 - (n))))

# define IND(x)			((x) ? ((x) - 1) : (x))
# define IS_FLG(x, flg)	(((flg) == ((x) & (flg))) ? TRUE : FALSE)
# define BYTELEN(x)		(((x) + 0xFF - 1) / 0xFF)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_display_file(const char *src);
void				ft_swap(int *a, int *b);
void				ft_lswap(size_t *a, size_t *b);
void				ft_pswap(void **p1, void **p2);

void				ft_bzero(void *dst, size_t n);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_wcsdel(wchar_t **aw);
void				ft_putnendl(const char *s, size_t n);

void				ft_u8from32(uint8_t *dst, uint32_t src);
void				ft_u8nfrom32(uint8_t *dst, size_t n, uint32_t src);
void				ft_u8from64(uint8_t *dst, uint64_t src);
void				ft_u8nfrom64(uint8_t *dst, size_t n, uint64_t src);
void				ft_u8from_any(uint8_t *dst, size_t src, uint8_t size);
void				ft_u8nfrom_any(uint8_t *dst, size_t n,\
									size_t src, uint8_t size);

void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);

void				ft_hexdump_fd(int fd, const void *data, size_t n,\
									uint8_t n_bytes);

void				*ft_realloc(void *dst, size_t nd,\
								const void *src, size_t ns);
void				*ft_rrealloc(void *dst, size_t nd,\
								const void *src, size_t ns);
void				*ft_memdup(const void *src, size_t n);
void				*ft_memjoin(const void *p1, size_t n1,\
								const void *p2, size_t n2);
void				*ft_memsub(const void *src, size_t start, size_t n);

void				*ft_memset(void *dst, int c, size_t n);
void				*ft_memnset(void *dst, int c, size_t nc, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memxor(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);

void				*ft_rand_fill(void *dst, size_t n,\
									uint8_t lower, uint8_t upper);

const void			*ft_getmemp(const void *data, size_t n);
const void			*ft_getcmemp(const void *data, size_t n, uint8_t c);
const void			*ft_getcmpmemp(const void *data, size_t n,\
									const void *cmp, size_t cmp_n);
const void			*ft_getrcmpmemp(const void *data, size_t n,\
									const void *cmp, size_t cmp_n);

t_bool				ft_iswhitespace(int c);
t_bool				ft_ishex(int c);
t_bool				ft_fileexist(const char *file_name);
t_bool				ft_isprime_mr(uint64_t n, uint32_t k);

uint8_t				ft_fromhex(int c);

int					ft_atoi(const char *src);
int					ft_patoi(const char **src);
int					ft_fileopen(const char *file_name, int oflag);
int					pratoi(char **src, int *pr_nb);
int					pratoi_hex(char **src, int *pr_nb);
int					ft_putchari(int c, int fd);
int					ft_putchari_fd(int c, int fd);
int					get_next_line(const int fd, char **line);
int					ft_pow(int n, int power);
int					ft_isprime(int n);
int					ft_sqrt(int	n);
int					ft_err(int retv, void **p);
int					ft_errno(const char *file_name);
int					ft_masserr(int retv, int **m);
int					ft_nmasserr(int retv, int ***nm, size_t n);
int					ft_strerr(int retv, char **s);
int					ft_nstrerr(int retv, char ***ns);
int					ft_puterr(int retv, const char *s);
int					ft_chrcnt(const char *src, char c);
int					ft_memcmp(const void *src1, const void *src2, size_t n);
int					ft_strcmp(const char *src1, const char *src2);
int					ft_strcmpi(const char *src1, const char *src2);
int					ft_strncmp(const char *src1, const char *src2, size_t n);
int					ft_strncmpi(const char *src1, const char *src2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);

unsigned int		ft_abs(int a);
uint32_t			ft_swapint32(uint32_t x);
uint32_t			ft_u32from8(const uint8_t *src, size_t n);
uint32_t			ft_u32pad8(const uint8_t *src, size_t n, uint8_t pad);

long long			ft_max(long long a, long long b);
long long			ft_max3(long long a, long long b, long long c);
long long			ft_lmax(long long a, long long b);
long long			ft_lpow(long long n, long long power);
long long			ft_labs(long long a);
long long			ft_latoi(const char *src);
int64_t				ft_filesize(int fd);

uint64_t			ft_lsqrt(uint64_t n);
uint64_t			ft_swapint64(uint64_t x);
uint64_t			ft_ufrom8(const uint8_t *src, size_t n);
uint64_t			ft_u64from8(const uint8_t *src, size_t n);
uint64_t			ft_u64pad8(const uint8_t *src, size_t n, uint8_t pad);
uint64_t			ft_rand(uint64_t lower, uint64_t upper);
uint64_t			ft_rand_prime(uint64_t lower, uint64_t upper,\
									uint8_t bits, uint32_t k);
uint64_t			ft_modpow(uint64_t n, uint64_t pow, uint64_t mod);
uint64_t			ft_modmult(uint64_t a, uint64_t b, uint64_t mod);
uint64_t			ft_modmult_inv(uint64_t a, uint64_t mod);

unsigned long long	ft_gcd(unsigned long long a, unsigned long long b);

size_t				ft_bitlen(const void *data, size_t n);
size_t				ft_umax(size_t a, size_t b);
size_t				ft_umax3(size_t a, size_t b, size_t c);
size_t				ft_putchar_fd(int c, int fd);
size_t				ft_putunichar_fd(int c, int fd);
size_t				ft_putstr_fd(const char *s, int fd);
size_t				ft_putunistr_fd(const int *s, int fd);
size_t				ft_putendl_fd(const char *s, int fd);
size_t				ft_putchar(int c);
size_t				ft_putunichar(int c);
size_t				ft_putstr(const char *s);
size_t				ft_putunistr(const int *s);
size_t				ft_putendl(const char *s);
size_t				ft_putlower(const char *src);
size_t				ft_putupper_fd(const char *src, int fd);
size_t				ft_putupper(const char *src);
size_t				ft_strlchr(const char *src, char c);
size_t				ft_strlen(const char *src);
size_t				ft_unistrlen(const int *src);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);

t_bool				ft_isprime_mr128(t_uint128 n, uint32_t k);
t_uint128			ft_modpow128(t_uint128 n, t_uint128 pow, t_uint128 mod);
t_uint128			ft_modmult128(t_uint128 a, t_uint128 b, t_uint128 mod);
t_uint128			ft_rand128(t_uint128 lower, t_uint128 upper);

double				ft_fabs(double a);
double				ft_fpow(double n, long long pow);

const char			*ft_getstrp(const char *src);

char				*ft_strfnew(size_t size, char c);
char				*ft_strrealloc(char *dst, const char *src, size_t n);
char				*ft_strcrealloc(char *dst, const char *src, size_t n,\
																	int c);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, \
								const char *needle, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strcsub(const char *s, unsigned int start, size_t len,\
																		int c);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				*ft_itoa(int n);

char				**ft_nstrnew(size_t size);
char				**ft_strsplit(const char *s, char c);

wchar_t				*ft_wcsdup(const wchar_t *src);
wchar_t				*ft_wcsnew(size_t size);

t_data				*ft_randn(size_t n);
#endif
