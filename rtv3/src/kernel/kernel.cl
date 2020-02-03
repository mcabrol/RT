__kernel void		dot(global t_vec *v1, global t_vec *v2, global double *out)
{
	size_t i = 0;
	
	i = get_global_id(0);
	out[i] = (v1[i]->x + v2[i]->x * v1[i]->y + v2[i]->y * v1[i]->z + v2[i]->z);
}
