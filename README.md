# Project Euler Template

# ATTENTION !!

# NEVER UPLOAD CODE SOLUTIONS TO A PUBLIC REPOSITORY!!

## Project Euler consists of challenges

**Do not upload answers**

You don't want to be that guy to ruin such a nice project, do you?

## DISCLAIMER

From the webpage: https://projecteuler.net/about

The popularity of Project Euler has increased tremendously over the years since its inception through the concerted effort of numerous people.

Members have generally taken pride in showing their achievements. The obvious place to do so is the forum that is set up for each problem. However the increasing popularity has also been attracting people with a different agenda. With so many internet sites publishing answers for the PE problems instead of using the forum on this site, some people now seem to take pride in gathering and submitting those answers for whatever reason.

It is humanly impossible for Project Euler, or indeed any member, to reliably differentiate those people from members that have solved the problems under their own steam. The ranking lists on Project Euler should be interpreted for what they are: an indication of the number of correct answers submitted by the member in question and validated by our answer checker. Individual members themselves know best what they have achieved on their own. Laying too much stress on competition might spoil the fun of problem solving which is one of the purposes of Project Euler. Also, any claim from a member about his own achievement cannot be supported as trustworthy by Project Euler. If critical, other means from third parties would be required to verify such claims.

Providing quality problems for entertainment and educational purposes will continue to be the main goal of Project Euler, regardless of the intentions of a minority of the members.


## Files

* peN.c : template to start your solution
* projecteuler.h : a library to set up things easy
* projecteuler.c : functions you collect while learning

## Usage

* To create your first exercise using `make`. Suppose you are programming exercise number 1154. Then do:
    - make euler N=1154

This will copy and correct automatically the name of the exercise to a new file:

```
pe1154.c
```

where you will create your master piece to solve problem number 1154!

* What now?

    - Open the file `pe1154.c` with your preferred editor (`vim`, of course ;)
    - Don't change _anything_ in function `main()`. Let it there as it is. Your project starts in the function `PEN()` bellow `main()`.
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
        + If it is an integer, just do: `D=SOMETHING=INTEGER`
        + If you want a char, then: `D="SOMETHING=\'A\'"`
    - To see more options, `vi makefile` and look the variables there.

# Author & License

* This document and templates were created by:
* Prof. Ruben Carlo Benante
* Email. rcb at beco dot cc
* Date: 2017-12-01
* License: GPL v3

