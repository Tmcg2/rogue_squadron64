# MIPS to C

Please forgive this document.
This tool is made by-me-for-me so explaining its usage to others is a bit difficult.
It not complex or anything, its just idiosyncratic.

[m2c_helper.sh](/docs/mips_to_c) is a utility I wrote to make the use of m2c a bit easier.
Its a tool from my time working on the [Mario Kart 64 decompilation](https://github.com/n64decomp/mk64) that has seen some modifications to fit this project better.

To use the tool properly you must:

1) Use splat to split the ROM apart first
2) Clone m2c's source repository (<https://github.com/matt-kempster/m2c>)
3) Have a file named `ctx.c`

The script itself has a couple different variables that can be used to configure it.
So you can put the `m2c` source repo and the `ctx.c` file wherever you want.

I have provided the [ctx.c](/docs/mips_to_c/ctx.c) I used to generate some of the C files for functions mentioned elsewhere in the documenation.
Its there both as an example of what a context file should look like, and as a good starting point for any decomp attempts.

The high level idea of the script is to make it easy to give `m2c` context.
`m2c` works better when it knows what types each function takes/returns, and it works even better when it knows what those types look like.

Basic usage:

```bash
./m2c_helper.sh <overlay name here> <name of function here>
```

Example usage:

```bash
./m2c_helper.sh mission_overlay load_hmt_and_hob
```
