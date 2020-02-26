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

| Options       	 | Sphere	 | Plane	| Cylinder	| Cone	| Box	| Camera	|
| ------------------ | --------- | -------- | --------- | ----- | ----- | --------- |
| radius (_double_)	 | Yes		 | No		| Yes		| No	| No	| No		|
| height (_double_)	 | No		 | No		| Yes 		| Yes	| No	| No		|
| position (_t_vec_) | Yes		 | Yes		| Yes		| Yes	| Yes	| Yes 		|
| direction (_t_vec_)| Yes		 | Yes		| Yes		| Yes	| Yes	| Yes		|
| emission (_t_vec_) | Yes		 | Yes		| Yes		| Yes	| Yes	| No		|
| reflect (_int_)    | Yes		 | Yes		| Yes		| Yes	| Yes	| No		|
| color (_t_vec_)	 | Yes		 | Yes		| Yes		| Yes	| Yes	| No		|
| angle (_double_)	 | No		 | No		| No		| Yes	| No	| No		|
| a (_double_)		 | No		 | No		| No		| No	| Yes	| No		|
| b (_double_)		 | No		 | No		| No		| No	| Yes	| No		|
| c (_double_)		 | No		 | No		| No		| No	| Yes	| No		|
| fov (_double_)	 | No		 | No		| No		| No	| No	| Yes		|

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

# Options

## Object

When your **right-click** on object:

**g**: for hasardly moving

| g > x                  | g > y                  | g > z                  |
| ---------------------- | ---------------------- | ---------------------- |
| move on the **x** axis | move on the **y** axis | move on the **z** axis |

**s** for scaling

**r** for hasardly moving

| r > x                    | r > y                    | r > z                    |
| ------------------------ | ------------------------ | ------------------------ |
| rotate on the **x** axis | rotate on the **y** axis | rotate on the **z** axis |

## Camera

**middle-click** for rotate scene

**scroll** for zoom into scene
