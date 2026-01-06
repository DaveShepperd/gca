#gcc for ASAP (Atari Simplified Architecture Processor).

This is a ressurecton of version 1.40 of gcc originally modified in the early 1990's. The
modifications were to make it produce and emit macas assembler syntax output. One
has to the the assembler in the [HERE](https://github.com/daveshepperd/macxx.git>)
I.e. it does not include a Gnu assembler. It doesn't work right yet and maybe it
never actually did or maybe this is an out of date version than what was eventually
used by Atari. So this remains a work in progress. The changes made to this code from
the original 1990's images are function prototypes and header files were added in
order to get a build without warnings under Ubuntu 2404LTS. And I made some tweaks
to the config.gcc file.

To build with the object files in a separate directory:

mkdir asap-objs
cd asap-objs
<path-to-source>/config.gcc asap
make

It creates two files needed to do the job: gca and cc1. Copy those to someplace
where there's a PATH pointing to them:

cp gca cc1 ~/bin

Then to get a file to assemble and link (foo.c is the ASAP program):

gca -S foo.c
macas -out -lis foo.s
llf foo

etc.
