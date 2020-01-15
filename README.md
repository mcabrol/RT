# Ray Tracer v1

Simple **ray pathing** algorithm written in C.

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

## Architecture

| Algorithm     | Objects Manager   | Math         | Graphic   | Kernel     |
| ------------- | ----------------- | ------------ | --------- | ---------- |
| intersect.c   | scene.c           | vetor.c      | mlx.c     | opencl.c   |
| radiace.c     | sphere.c          | operator.c   |           |            |
| ray.c         |                   | calcul.c     |           |            |
| rtv1.c        |                   | sample.c     |           |            |
| specular.c    |                   |              |           |            |
| srand48.c     |                   |              |           |            |
