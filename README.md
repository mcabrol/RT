# 💥 Ray Tracer v1

Simple **ray pathing** algorithm written in C for _OS X_ distribution.

## Install

### Compile

The program requires the installation of **gcc** and **cmake**.

```shell
brew install gcc cmake
```
## Run

```shell
./rtv1 [files]
```

## File

The configuration file is in _.rt_ extension.

| Options       	   | Sphere 	 | Plane  	| Cylinder	| Cone	| Box	  | Camera	|
| ------------------ | --------- | -------- | --------- | ----- | ----- | ------- |
| radius (_double_)	 | *Yes*		     | _No_   		| *Yes*		    | _No_	  | _No_	  | _No_      |
| height (_double_)	 | _No_		     | _No_		    | *Yes* 	    	| *Yes*  	| _No_  	| _No_  		|
| position (_t_vec_) | *Yes*		     | *Yes*		    | *Yes*		    | *Yes*	  | *Yes*	  | *Yes*     |
| direction (_t_vec_)| *Yes*		 | *Yes*		| *Yes*		| *Yes*	| *Yes*	| *Yes*		|
| emission (_t_vec_) | *Yes*		 | *Yes*		| *Yes*		| *Yes*	| *Yes*	| _No_		|
| reflect (_int_)    | *Yes*		 | *Yes*		| *Yes*		| *Yes*	| *Yes*	| _No_		|
| color (_t_vec_)	 | *Yes*		 | *Yes*		| *Yes*		| *Yes*	| *Yes*	| _No_		|
| angle (_double_)	 | _No_		 | _No_		| _No_		| *Yes*	| _No_	| _No_		|
| a (_double_)		 | _No_		 | _No_		| _No_		| _No_	| *Yes*	| _No_		|
| b (_double_)		 | _No_		 | _No_		| _No_		| _No_	| *Yes*	| _No_		|
| c (_double_)		 | _No_		 | _No_		| _No_		| _No_	| *Yes*	| _No_		|
| fov (_double_)	 | _No_		 | _No_		| _No_		| _No_	| _No_	| *Yes*		|

## Architecture

_file.c_ todo

| Algorithm     | Objects Manager   | Math         | Graphic   | Kernel     |
| ------------- | ----------------- | ------------ | --------- | ---------- |
| intersect.c   | scene.c           | vetor.c      | mlx.c     | opencl.c   |
| radiance.c    | sphere.c          | operator.c   | _gui.c_   | kernel.cl  |
| ray.c         | _cone.c_          | calcul.c     | _text.c_  |            |
| rtv1.c        | _cylinder.c_      | sample.c     |           |            |
| specular.c    | _cube.c_          |              |           |            |
| srand48.c     | _plan.c_          |              |           |            |
