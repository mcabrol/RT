/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:45:31 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/17 21:43:43 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define FILE_SIZE 200

void 	print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_printf("tab[%d] = %s\n", i, tab[i]);
		i++;
	}
}

// void 	kernel_src(t_opencl *cl)
// {
// 	int fd;
// 	int rt;
// 	char tmp[195];
//
// 	fd = open("/Users/mcabrol/Documents/rtv1/src/kernel/kernel.cl", O_RDONLY);
// 	rt = read(fd, tmp, FILE_SIZE);
// 	cl->kernel_src = ft_strsplit(tmp, '\n');
// 	print_tab(cl->kernel_src);
// 	close(fd);
// }
//
// void 	init_opencl(t_opencl *cl)
// {
// 	dispatch_queue_t 	queue;
// 	cl_device_id 		gpu;
// 	// cl_program 			kernelProgram;
// 	char 				name[128];
// 	// double 			*mem_in;
// 	// double 			*mem_out;
//
// 	kernel_src(cl);
// 	queue = gcl_create_dispatch_queue(CL_DEVICE_TYPE_GPU, NULL);
// 	if (queue == NULL) {
// 		ft_dprintf(2, "openCL GPU desactivé -> utilise openCL CPU\n");
//         queue = gcl_create_dispatch_queue(CL_DEVICE_TYPE_CPU, NULL);
//     }
// 	gpu = gcl_get_device_id_with_dispatch_queue(queue);
//    	clGetDeviceInfo(gpu, CL_DEVICE_NAME, 128, name, NULL);
//    	ft_dprintf(2, "Created a dispatch queue using the %s\n", name);
//
// 	// Create array of calc
//
// 	// mem_in = gcl_malloc(sizeof(cl_float), SIZE, test_in, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR);
// 	// mem_out = gcl_malloc(sizeof(cl_float), SIZE, NULL, CL_MEM_WRITE_ONLY);
// 	//
// 	// kernelProgram = clCreateProgramWithSource(context, 4, kernelSource, 0, 0);
// 	//
// 	// gcl_free(mem_in);
//     // gcl_free(mem_out);
// }
