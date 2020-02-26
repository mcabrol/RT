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
| radius (_double_)	 | ✔️		     | ❌   		| ✔️		    | ❌	  | ❌	  | ❌      |
| height (_double_)	 | ❌		     | ❌		    | ✔️ 	    	| ✔️  	| ❌  	| ❌  		|
| position (_t_vec_) | ✔️		     | ✔️		    | ✔️		    | ✔️	  | ✔️	  | ✔️     |
| direction (_t_vec_)| ✔️		 | ✔️		| ✔️		| ✔️	| ✔️	| ✔️		|
| emission (_t_vec_) | ✔️		 | ✔️		| ✔️		| ✔️	| ✔️	| ❌		|
| reflect (_int_)    | ✔️		 | ✔️		| ✔️		| ✔️	| ✔️	| ❌		|
| color (_t_vec_)	 | ✔️		 | ✔️		| ✔️		| ✔️	| ✔️	| ❌		|
| angle (_double_)	 | ❌		 | ❌		| ❌		| ✔️	| ❌	| ❌		|
| a (_double_)		 | ❌		 | ❌		| ❌		| ❌	| ✔️	| ❌		|
| b (_double_)		 | ❌		 | ❌		| ❌		| ❌	| ✔️	| ❌		|
| c (_double_)		 | ❌		 | ❌		| ❌		| ❌	| ✔️	| ❌		|
| fov (_double_)	 | ❌		 | ❌		| ❌		| ❌	| ❌	| ✔️		|

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
