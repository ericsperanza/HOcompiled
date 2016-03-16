1-
El proceso consta de cuatro etapas:
	- En la primera (preprocesador) se procesan las directivas #include y los macros. Se ejecuto mediante:
		$ gcc -E calculator.c -o calculator.pp_c
	donde el flag -E inidca que solo se realiza esta etapa y la salida es un archio .pp_c
	- En la siguiente etapa (compilacion I) se pasa el codigo en C a assembler, mediante:
		$ gcc -S calculator.c -o calculator.asm
	donde el archivo de salida esta en codigo assembler.
	- En la tercera etapa (compilacion II) pasamos del codigo assembler a lenguaje de maquina:
		$ gcc -c calculator.c -o calculator.o
	Asi se crea el binario "calculator.o" que ya no es legible. Con el comando "nm calculator.o" podemos ver descriptores que indican, en este caso, las funciones visibles definidas por el programa (T) y las no definidas (U):
		00000043 T add_numbers
		00000000 T main
        		 U printf
	- Finalmente en la ultima etapa, el linkeo, se vincula a las librerias que fueran necesarias (donde estan las funciones marcadas con el descriptor U) y se genera un ejecutable:
		$ gcc -v calculator.c -o calculator.e
	Al ejecutar este comando se ve una larga lista de librerias vinculadas por el linker.

2-
Agrego todo lo que tienen las directivas #include de los archivos "calculator.c" y "calculator.h", por ejemplo:
	# 1 "/usr/include/stdio.h" 1 3 4
	# 27 "/usr/include/stdio.h" 3 4
	# 1 "/usr/include/features.h" 1 3 4
	# 374 "/usr/include/features.h" 3 4
	# 1 "/usr/include/i386-linux-gnu/sys/cdefs.h" 1 3 4
	# 385 "/usr/include/i386-linux-gnu/sys/cdefs.h" 3 4
	# 1 "/usr/include/i386-linux-gnu/bits/wordsize.h" 1 3 4
	# 386 "/usr/include/i386-linux-gnu/sys/cdefs.h" 2 3 4
	# 375 "/usr/include/features.h" 2 3 4
	# 398 "/usr/include/features.h" 3 4
	# 1 "/usr/include/i386-linux-gnu/gnu/stubs.h" 1 3 4

3- 
"main" aparece en las lineas 7-8:
	.globl	main
	.type	main, @function
y luego con la etiqueta .LFE0:
	.LFE0:
		.size	main, .-main
		.globl	add_numbers
		.type	add_numbers, @function
"add+numbers" es llamada en la linea 25 (call	add_numbers) y aparece con la etiqueta .LFE1:
	.LFE1:
		.size	add_numbers, .-add_numbers
		.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
		.section	.note.GNU-stack,"",@progbits

4 y 5:
Los simbolos son descriptores que indican en el caso de "calculator.o" citado arriba, cuales son las funciones definidas en el programa y cuales estan definidas por fuera del mismo. Al aplicar el comando "nm" sobre el ejecutable tenemos muchas mas entradas (ver abajo) porque ya esta linkeado. La mayuscula y minuscula en los descriptores indica si las funciones o variables son visibles o no. Los "t" "T" indican funciones definidas en el programa, "d" "D" son variables, "r" "R" son constantes y "u" "U" son funciones no definidas en el programa.
0804843e T add_numbers
0804972c B __bss_start
0804972c b completed.6279
08049724 D __data_start
08049724 W data_start
08048340 t deregister_tm_clones
080483b0 t __do_global_dtors_aux
08049618 t __do_global_dtors_aux_fini_array_entry
08049728 D __dso_handle
08049620 d _DYNAMIC
0804972c D _edata
08049730 B _end
080484c4 T _fini
080484d8 R _fp_hw
080483d0 t frame_dummy
08049614 t __frame_dummy_init_array_entry
08048610 r __FRAME_END__
0804970c d _GLOBAL_OFFSET_TABLE_
         w __gmon_start__
08048294 T _init
08049618 t __init_array_end
08049614 t __init_array_start
080484dc R _IO_stdin_used
         w _ITM_deregisterTMCloneTable
         w _ITM_registerTMCloneTable
0804961c d __JCR_END__
0804961c d __JCR_LIST__
         w _Jv_RegisterClasses
080484c0 T __libc_csu_fini
08048450 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
080483fb T main
         U printf@@GLIBC_2.0
08048370 t register_tm_clones
08048300 T _start
0804972c D __TMC_END__
08048330 T __x86.get_pc_thunk.bx

## Pregunta 4
4. Los simbolos que se crean en el objeto son descriptores (funciones). Las mayusculas significan
que son accesibles desde fuera del programa.
   Las u corresponden a variables no definidas.
        000000000000003c T add_numbers
        0000000000000000 T main
                         U printf
## Pregunta 5
5. A primera vista (Usando "nm") pueden verse muchos más simbolos, entre los que se encuentran los del .o. Por ejemplo, U printf, ahora contiene el @ y donde buscarla.
   El resto de los simbolos corresponden a funciones necesarias para que el programa en binario pueda ser ejecutado por el sistema operativo para que fue compilado.

```
0000000000400569 T add_numbers
0000000000601040 B __bss_start
0000000000601040 b completed.6973
0000000000601030 D __data_start
0000000000601030 W data_start
0000000000400470 t deregister_tm_clones
00000000004004e0 t __do_global_dtors_aux
0000000000600e18 t __do_global_dtors_aux_fini_array_entry
0000000000601038 D __dso_handle
0000000000600e28 d _DYNAMIC
0000000000601040 D _edata
0000000000601048 B _end
00000000004005f4 T _fini
0000000000400500 t frame_dummy
0000000000600e10 t __frame_dummy_init_array_entry
0000000000400778 r __FRAME_END__
0000000000601000 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
00000000004003e0 T _init
0000000000600e18 t __init_array_end
0000000000600e10 t __init_array_start
0000000000400600 R _IO_stdin_used
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
0000000000600e20 d __JCR_END__
0000000000600e20 d __JCR_LIST__
                 w _Jv_RegisterClasses
00000000004005f0 T __libc_csu_fini
0000000000400580 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
000000000040052d T main
                 U printf@@GLIBC_2.2.5
00000000004004a0 t register_tm_clones
0000000000400440 T _start
0000000000601040 D __TMC_END__
```
