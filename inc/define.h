/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:51:59 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 15:50:25 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define THREAD					16

# define H_MAIN					80
# define W_MAIN					544

# define H_SETTING				340
# define W_SETTING				276

# define PATH_SPRITE			"./src/sprite/"

# define BLANK					0.0, 0.0, 0.0
# define FALSE					0
# define TRUE					1
# define CONTINUE				0
# define STOP					1

# define SETUP					0
# define RENDER					1
# define ERROR					2
# define SAMPLE 				3
# define FORMAT					4


# define MAIN					0
# define RENDER 				1
# define SETTING 				2

# define OBJ_TYPE				6
# define OBJ_TYPE_STR			"SPHERE PLANE CYLINDER CONE BOX CAMERA"
# define OBJ_OPT_STR			"POSITION DIRECTION EMISSION COLOR REFLECTION RADIUS ANGLE HEIGHT WIDTH DEPTH FOV AMBIENT ROTATION TEXTURE SCALE INDEX MAP"

# define LIST_HOVER				"save render retry setup display"
# define LIST_DISABLED			"setup sample format render display save x8 x20 x200 x500 x1000 x5000 320x240 854x480 1024x768 1280x720 1400x1050 1920x1080"
# define LIST_HOVER_DISABLED	"save render display"

# define SPHERE					0
# define PLANE					1
# define CYLINDER				2
# define CONE					3
# define BOX					4
# define CAMERA					5

# define DIFF					0
# define SPEC					1
# define REFR					2

# define MAX_WIN	 			50

# define GAMMA 					2.2
# define T_MIN					0.01
# define T_MAX 					1e20

# define ACTIVE					TRUE
# define DISABLE 				FALSE

# define	TEXTURE				0
# define ENVIRONMENT			1

# define NORMAL					-1
# define RIGHT					0
# define LEFT					1
# define TOP					2
# define BOTTOM					3
# define FRONT					4
# define BACK					5

# define P_SETUP				"90, 181, 0, 80"
# define P_RETRY				"181, 272, 0, 80"
# define P_SAVE					"272, 362, 0, 80"
# define P_DISPLAY				"362, 453, 0, 80"
# define P_RENDER				"453, 544, 0, 80"

# define P_CLOSE_SETTING		"0, 92, 0, 80"
# define P_SAMPLE				"92, 183, 0, 80"
# define P_FORMAT				"183, 276, 0, 80"
# define P_X8					"0, 276, 79, 122"
# define P_X20					"0, 276, 122, 164"
# define P_X200					"0, 276, 164, 207"
# define P_X500					"0, 276, 207, 251"
# define P_X1000				"0, 276, 251, 294"
# define P_X5000				"0, 276, 294, 340"

# define MINI(X, Y) 				(((X) < (Y)) ? (X) : (Y))
# define MAXI(X, Y) 				(((X) > (Y)) ? (X) : (Y))

typedef int 					BOOL;

#endif
