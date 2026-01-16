# gcc for ASAP.

ASAP = Atari Simplified Architecture Processor.

This is a ressurecton of version 1.40 of gcc originally modified in the early 1990's. The
modifications were to make it produce and emit macas assembler syntax output. One
has to use the the assembler kit [HERE](https://github.com/daveshepperd/macxx.git) and
linker kit [HERE](https://github.com/daveshepperd/llf.git)
I.e. it does not include a Gnu assembler and linker.

The changes made to this code from the original 1990's images are function prototypes
and header files were added in order to get a build without warnings under Ubuntu 2404LTS.
And I made some tweaks to the config.gcc file. The original unmodified (by me) files are
in the **original** branch.

To build with the object files in a separate directory (recommened approach):

```
mkdir asap-objs
cd asap-objs
<path-to-source>/config.gcc asap
make
```

It creates two files needed to do the job: gca and cc1. Copy those to someplace
where there's an entry in your PATH pointing to them:

```
cp gca cc1 ~/bin
```

Then to get a file to assemble and link (foo.c is the ASAP program):

```
gca -S foo.c
macas -out -lis foo.s
llf foo
```
etc.

A **very** inportant note. This kit purposely does not build a 1.40 version of the C preprocessor.
The gca program will just call the current version of cpp which works just fine as is
except it will, by default, look for any include files in the normal Linux trees. If you haven't specified
the include directory with a -I when invoking gca and your source file has a #include, expect
to get zillions of perhaps confusing errors and warnings. I.e., make certain you provide a -I with a
path where you've built the the cross_clib_asap/crtl.lib file if any of the ASAP source files have a #include
directive in them.
