/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:45:31 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/15 17:54:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define SIZE 3000

char 	**kernel_dot(void)
{
	char **k;

	k = NULL;
	k[0] = "__kernel void		dot(global t_vec *v1, global t_vec *v2, global double *out)\n";
	k[0] = "{																			   \n";
	k[1] = "	size_t i = 0;															   \n";
	k[2] = "	i = get_global_id(0);													   \n";
	k[3] = "	out[i] = (v1[i]->x + v2[i]->x * v1[i]->y + v2[i]->y * v1[i]->z + v2[i]->z) \n";
	k[4] = "}																			   \n";
	return (k);
}

void 	opencl(void)
{
	char *k[5];
	dispatch_queue_t queue;
	// cl_program kernelProgram;
	char name[128];
	// double *mem_in;
	// double *mem_out;

	k[0] = "__kernel void		dot(global t_vec *v1, global t_vec *v2, global double *out)\n";
	k[0] = "{																			   \n";
	k[1] = "	size_t i = 0;															   \n";
	k[2] = "	i = get_global_id(0);													   \n";
	k[3] = "	out[i] = (v1[i]->x + v2[i]->x * v1[i]->y + v2[i]->y * v1[i]->z + v2[i]->z) \n";
	k[4] = "}																			   \n";

	queue = gcl_create_dispatch_queue(CL_DEVICE_TYPE_GPU, NULL);
	if (queue == NULL) {
		ft_dprintf(2, "openCL GPU desactivé -> utilise openCL CPU\n");
        queue = gcl_create_dispatch_queue(CL_DEVICE_TYPE_CPU, NULL);
    }
	cl_device_id gpu = gcl_get_device_id_with_dispatch_queue(queue);
   	clGetDeviceInfo(gpu, CL_DEVICE_NAME, 128, name, NULL);
   	ft_dprintf(2, "Created a dispatch queue using the %s\n", name);

	// Create array of calc

	// mem_in = gcl_malloc(sizeof(cl_float), SIZE, test_in, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR);
	// mem_out = gcl_malloc(sizeof(cl_float), SIZE, NULL, CL_MEM_WRITE_ONLY);
	//
	// //kernelProgram = clCreateProgramWithSource(context, 4, kernelSource, 0, 0);
	//
	// gcl_free(mem_in);
    // gcl_free(mem_out);
}
