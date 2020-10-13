![RT](https://raw.githubusercontent.com/mcabrol/RT/master/img/Present.png)

# 💥 Ray Tracer

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

| Options       	   | Sphere 	 | Plane  	| Cylinder	| Cone	  | Box	    | Camera	|
| ------------------ | --------- | -------- | --------- | ------- | ------- | ------- |
| radius (_float_)	 | **Yes**   | _No_   	| **Yes**	  | _No_	  | _No_	  | _No_    |
| height (_float_)	 | _No_		   | _No_		  | **Yes**  	| **Yes** | _No_  	| _No_  	|
| width (_float_)		 | _No_		   | _No_		  | _No_		  | _No_	  | **Yes**	| _No_		|
| height (_float_)   | _No_		   | _No_		  | _No_		  | _No_	  | **Yes**	| _No_		|
| depth (_float_)	   | _No_		   | _No_		  | _No_		  | _No_	  | **Yes**	| _No_		|
| position (_t_vec_) | **Yes**	 | **Yes**	| **Yes**		| **Yes**	| **Yes**	| **Yes** |
| direction (_t_vec_)| **Yes**	 | **Yes**	| **Yes**		| **Yes**	| **Yes**	| **Yes**	|
| emission (_t_vec_) | **Yes**	 | **Yes**	| **Yes**		| **Yes**	| **Yes**	| _No_		|
| reflect (_int_)    | **Yes**	 | **Yes**	| **Yes**		| **Yes**	| **Yes**	| _No_		|
| color (_t_vec_)	   | **Yes**	 | **Yes**	| **Yes**		| **Yes**	| **Yes**	| _No_		|
| angle (_float_)	   | _No_		   | _No_		  | _No_		  | **Yes**	| _No_	  | _No_		|
| fov (_float_)	     | _No_		   | _No_		  | _No_		  | _No_	  | _No_	  | **Yes**	|

## Architecture

_main.c_ 
_debbug.c_ 
_free.c_

| Algorithm          | Objects Manager   | Math         | Graphic      | File         |
| ------------------ | ----------------- | ------------ | ------------ | ------------ |
| camera.c           | obj_opt.txt       | convert.c    | button.c     | file.c       |
| cubemap.c          | obj_type.txt      | hex_conv.c   | display.c    | file_error.c |
| intersect.c        | object.c          | quadratic.c  | event.c      | parse.c      |
| intersect_form.c   | scene.c           | rotate.c     | gui.c        | parse_2.c    |
| light.c            | setter_opt.c      | vetor.c      | hover.c      | setter.c     |
| radiance.c         |                   | operator.c   | gui.c        | setter_2.c   |
| ray.c              |                   | clamp.c      | image.c      | setter_3.c   |
| reflect.c          |                   | calcul.c     | key.c        | setter_4.c   |
| rtv1.c             |                   | sample.c     | list.txt     |              |
| texture.c          |                   | distance.c   | mouse.c      |              |
| uv.c               |                   | normal.c     | pixel.c      |              |
| srand48.c          |                   |              | render.c     |              |
| srand48.c          |                   |              | setting.c    |              |
| srand48.c          |                   |              | window.c     |              |


## Reflect




