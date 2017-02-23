#include "ft_printf.h"

char	*ft_get_n_conv(t_datas *datas)
{
	*datas->tmp_len = datas->len;
	datas->args = datas->args->next;
	return (datas->result);
}
