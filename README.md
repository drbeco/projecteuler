# Project Euler Template

## Files

* peN.c : template to start your solution
* projecteuler.h : a library to set up things easy
* projecteuler.c : functions you collect while learning

## Usage

* To create your first exercise using `make`. Suppose you are programming exercise number 1154. Then do:
    - make euler N=1154

This will copy and correct automatically the name of the exercise. It would be the same as manually do:

* Copy peN.c as your new exercise. Suppose your are now solving the exercise number 1154, then do:

```
$ cp peN.c pe1154.c
```

Now open it with your preferred text editor that I'm sure is `vi`:

```
$ vi pe1154.c
```

* In the file `pe1154.c`:

    - In the comments, right at the second line, don't forget to correct the file name by changing `PEN.c` to `pe1154.c`
    - Line number 32, you will find a `#define` that needs also to reflect the exercise number you are solving.

Change it from:

```
#define PEN pe ## N
```

to:

```
#define PEN pe ## 1154
```

* What now?

    - Don't change _anything_ in function `main()`. Let it there as is. Your project starts in the function `PEN()` bellow `main()`.
    - Immediately before function `PEN()`, copy and paste as a comment the _Project Euler Question Text_, that is, the **description** of the problem you need to solve.
    - Go for it! You can write your code all inside `PEN()` or create bellow it as many auxiliary functions as you need.

* File `projecteuler.c` and `projecteuler.h`:
    - If, while solving one hard problem, you come up with a nice math function that you suppose you will need again soon, don't hesitate to update the library and add your contribution to it. Next exercise you do, you will be able to just use whatever you created before.

## Compile

* There is a makefile there to help you. To compile, use:

```
$ make pe1154.x SRC=projecteuler.c
```

* If you are into `versions`, you can set them as:

```
$ make pe1154.x SRC=projecteuler.c MAJOR=4 MINOR=2
```

* If `scanf()` gives you _warnings_ you don't care about (return value ignored for `scanf` or such), you can easy it by:

```
$ make pe1154.x SRC=projecteuler.c MAJOR=4 MINOR=2 FORTIFY=0
```

* There are other options you might want:
    - Turn off `DEBUG` mode and compile with fast optimizations with: `DEBUG=0`
    - Define something on your own. 
        + If it is an integer, just do: D=SOMETHING=INTEGER
        + If you want a char, then: D="SOMETHING=\'A\'"
    - To see more options, `vi makefile` and look the variables there.

# Author & License

* This document and templates were created by:
* Prof. Ruben Carlo Benante
* Email. rcb at beco dot cc
* Date: 2017-11-30
* License: GPL v3

