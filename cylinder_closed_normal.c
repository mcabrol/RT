void 	cylinder_normal_closed(t_obj *cylinder, t_ray *ray)
{
	t_vec 	tmp_dir;

	tmp_dir = cylinder->direction;
	if (cylinder->intersect_type == 1)
		cylinder_normal(cylinder, ray);
	else if (cylinder->intersect_type == 2 || cylinder->intersect_type == 3)
		plane_normal(cylinder, ray);
	cylinder->direction = tmp_dir;
}
