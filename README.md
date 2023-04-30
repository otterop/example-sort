# Introduction

This repository contains an example of [OtterOP](https://github.com/otterop/otterop) usage to transpile a program.

The program sorts string using either the quicksort or the heapsort in-place algorithm.

# Usage

Initialize repo, including git submodules

```sh
make init
```

Build Java code, transpile and build the rest of the languages.

```sh
make
```

Run generated code in all the languages:

```sh
./run.sh quick 3 2 1
```

or

```sh
./run.sh heap 3 2 1
```
