
add:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400238 <.interp>:
  400238:	2f                   	(bad)  
  400239:	6c                   	ins    BYTE PTR es:[rdi],dx
  40023a:	69 62 36 34 2f 6c 64 	imul   esp,DWORD PTR [rdx+0x36],0x646c2f34
  400241:	2d 6c 69 6e 75       	sub    eax,0x756e696c
  400246:	78 2d                	js     400275 <_init-0x153>
  400248:	78 38                	js     400282 <_init-0x146>
  40024a:	36 2d 36 34 2e 73    	ss sub eax,0x732e3436
  400250:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  400251:	2e 32 00             	xor    al,BYTE PTR cs:[rax]

Disassembly of section .note.ABI-tag:

0000000000400254 <.note.ABI-tag>:
  400254:	04 00                	add    al,0x0
  400256:	00 00                	add    BYTE PTR [rax],al
  400258:	10 00                	adc    BYTE PTR [rax],al
  40025a:	00 00                	add    BYTE PTR [rax],al
  40025c:	01 00                	add    DWORD PTR [rax],eax
  40025e:	00 00                	add    BYTE PTR [rax],al
  400260:	47                   	rex.RXB
  400261:	4e 55                	rex.WRX push rbp
  400263:	00 00                	add    BYTE PTR [rax],al
  400265:	00 00                	add    BYTE PTR [rax],al
  400267:	00 02                	add    BYTE PTR [rdx],al
  400269:	00 00                	add    BYTE PTR [rax],al
  40026b:	00 06                	add    BYTE PTR [rsi],al
  40026d:	00 00                	add    BYTE PTR [rax],al
  40026f:	00 20                	add    BYTE PTR [rax],ah
  400271:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .note.gnu.build-id:

0000000000400274 <.note.gnu.build-id>:
  400274:	04 00                	add    al,0x0
  400276:	00 00                	add    BYTE PTR [rax],al
  400278:	14 00                	adc    al,0x0
  40027a:	00 00                	add    BYTE PTR [rax],al
  40027c:	03 00                	add    eax,DWORD PTR [rax]
  40027e:	00 00                	add    BYTE PTR [rax],al
  400280:	47                   	rex.RXB
  400281:	4e 55                	rex.WRX push rbp
  400283:	00 ce                	add    dh,cl
  400285:	e8 b3 01 c5 55       	call   5605043d <_end+0x55a4f3fd>
  40028a:	04 71                	add    al,0x71
  40028c:	80 81 7f 32 40 b0 30 	add    BYTE PTR [rcx-0x4fbfcd81],0x30
  400293:	ef                   	out    dx,eax
  400294:	47 d7                	rex.RXB xlat BYTE PTR ds:[rbx]
  400296:	7b 63                	jnp    4002fb <_init-0xcd>

Disassembly of section .gnu.hash:

0000000000400298 <.gnu.hash>:
  400298:	01 00                	add    DWORD PTR [rax],eax
  40029a:	00 00                	add    BYTE PTR [rax],al
  40029c:	01 00                	add    DWORD PTR [rax],eax
  40029e:	00 00                	add    BYTE PTR [rax],al
  4002a0:	01 00                	add    DWORD PTR [rax],eax
	...

Disassembly of section .dynsym:

00000000004002b8 <.dynsym>:
	...
  4002d0:	0b 00                	or     eax,DWORD PTR [rax]
  4002d2:	00 00                	add    BYTE PTR [rax],al
  4002d4:	12 00                	adc    al,BYTE PTR [rax]
	...
  4002e6:	00 00                	add    BYTE PTR [rax],al
  4002e8:	12 00                	adc    al,BYTE PTR [rax]
  4002ea:	00 00                	add    BYTE PTR [rax],al
  4002ec:	12 00                	adc    al,BYTE PTR [rax]
	...
  4002fe:	00 00                	add    BYTE PTR [rax],al
  400300:	24 00                	and    al,0x0
  400302:	00 00                	add    BYTE PTR [rax],al
  400304:	20 00                	and    BYTE PTR [rax],al
	...

Disassembly of section .dynstr:

0000000000400318 <.dynstr>:
  400318:	00 6c 69 62          	add    BYTE PTR [rcx+rbp*2+0x62],ch
  40031c:	63 2e                	movsxd ebp,DWORD PTR [rsi]
  40031e:	73 6f                	jae    40038f <_init-0x39>
  400320:	2e 36 00 70 72       	cs add BYTE PTR ss:[rax+0x72],dh
  400325:	69 6e 74 66 00 5f 5f 	imul   ebp,DWORD PTR [rsi+0x74],0x5f5f0066
  40032c:	6c                   	ins    BYTE PTR es:[rdi],dx
  40032d:	69 62 63 5f 73 74 61 	imul   esp,DWORD PTR [rdx+0x63],0x6174735f
  400334:	72 74                	jb     4003aa <_init-0x1e>
  400336:	5f                   	pop    rdi
  400337:	6d                   	ins    DWORD PTR es:[rdi],dx
  400338:	61                   	(bad)  
  400339:	69 6e 00 5f 5f 67 6d 	imul   ebp,DWORD PTR [rsi+0x0],0x6d675f5f
  400340:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  400341:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  400342:	5f                   	pop    rdi
  400343:	73 74                	jae    4003b9 <_init-0xf>
  400345:	61                   	(bad)  
  400346:	72 74                	jb     4003bc <_init-0xc>
  400348:	5f                   	pop    rdi
  400349:	5f                   	pop    rdi
  40034a:	00 47 4c             	add    BYTE PTR [rdi+0x4c],al
  40034d:	49                   	rex.WB
  40034e:	42                   	rex.X
  40034f:	43 5f                	rex.XB pop r15
  400351:	32 2e                	xor    ch,BYTE PTR [rsi]
  400353:	32 2e                	xor    ch,BYTE PTR [rsi]
  400355:	35                   	.byte 0x35
	...

Disassembly of section .gnu.version:

0000000000400358 <.gnu.version>:
  400358:	00 00                	add    BYTE PTR [rax],al
  40035a:	02 00                	add    al,BYTE PTR [rax]
  40035c:	02 00                	add    al,BYTE PTR [rax]
	...

Disassembly of section .gnu.version_r:

0000000000400360 <.gnu.version_r>:
  400360:	01 00                	add    DWORD PTR [rax],eax
  400362:	01 00                	add    DWORD PTR [rax],eax
  400364:	01 00                	add    DWORD PTR [rax],eax
  400366:	00 00                	add    BYTE PTR [rax],al
  400368:	10 00                	adc    BYTE PTR [rax],al
  40036a:	00 00                	add    BYTE PTR [rax],al
  40036c:	00 00                	add    BYTE PTR [rax],al
  40036e:	00 00                	add    BYTE PTR [rax],al
  400370:	75 1a                	jne    40038c <_init-0x3c>
  400372:	69 09 00 00 02 00    	imul   ecx,DWORD PTR [rcx],0x20000
  400378:	33 00                	xor    eax,DWORD PTR [rax]
  40037a:	00 00                	add    BYTE PTR [rax],al
  40037c:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .rela.dyn:

0000000000400380 <.rela.dyn>:
  400380:	f8                   	clc    
  400381:	0f 60 00             	punpcklbw mm0,DWORD PTR [rax]
  400384:	00 00                	add    BYTE PTR [rax],al
  400386:	00 00                	add    BYTE PTR [rax],al
  400388:	06                   	(bad)  
  400389:	00 00                	add    BYTE PTR [rax],al
  40038b:	00 03                	add    BYTE PTR [rbx],al
	...

Disassembly of section .rela.plt:

0000000000400398 <.rela.plt>:
  400398:	18 10                	sbb    BYTE PTR [rax],dl
  40039a:	60                   	(bad)  
  40039b:	00 00                	add    BYTE PTR [rax],al
  40039d:	00 00                	add    BYTE PTR [rax],al
  40039f:	00 07                	add    BYTE PTR [rdi],al
  4003a1:	00 00                	add    BYTE PTR [rax],al
  4003a3:	00 01                	add    BYTE PTR [rcx],al
	...
  4003ad:	00 00                	add    BYTE PTR [rax],al
  4003af:	00 20                	add    BYTE PTR [rax],ah
  4003b1:	10 60 00             	adc    BYTE PTR [rax+0x0],ah
  4003b4:	00 00                	add    BYTE PTR [rax],al
  4003b6:	00 00                	add    BYTE PTR [rax],al
  4003b8:	07                   	(bad)  
  4003b9:	00 00                	add    BYTE PTR [rax],al
  4003bb:	00 02                	add    BYTE PTR [rdx],al
	...

Disassembly of section .init:

00000000004003c8 <_init>:
  4003c8:	48 83 ec 08          	sub    rsp,0x8
  4003cc:	48 8b 05 25 0c 20 00 	mov    rax,QWORD PTR [rip+0x200c25]        # 600ff8 <_DYNAMIC+0x1d0>
  4003d3:	48 85 c0             	test   rax,rax
  4003d6:	74 05                	je     4003dd <_init+0x15>
  4003d8:	e8 43 00 00 00       	call   400420 <__libc_start_main@plt+0x10>
  4003dd:	48 83 c4 08          	add    rsp,0x8
  4003e1:	c3                   	ret    

Disassembly of section .plt:

00000000004003f0 <printf@plt-0x10>:
  4003f0:	ff 35 12 0c 20 00    	push   QWORD PTR [rip+0x200c12]        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4003f6:	ff 25 14 0c 20 00    	jmp    QWORD PTR [rip+0x200c14]        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4003fc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000400400 <printf@plt>:
  400400:	ff 25 12 0c 20 00    	jmp    QWORD PTR [rip+0x200c12]        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400406:	68 00 00 00 00       	push   0x0
  40040b:	e9 e0 ff ff ff       	jmp    4003f0 <_init+0x28>

0000000000400410 <__libc_start_main@plt>:
  400410:	ff 25 0a 0c 20 00    	jmp    QWORD PTR [rip+0x200c0a]        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400416:	68 01 00 00 00       	push   0x1
  40041b:	e9 d0 ff ff ff       	jmp    4003f0 <_init+0x28>

Disassembly of section .plt.got:

0000000000400420 <.plt.got>:
  400420:	ff 25 d2 0b 20 00    	jmp    QWORD PTR [rip+0x200bd2]        # 600ff8 <_DYNAMIC+0x1d0>
  400426:	66 90                	xchg   ax,ax

Disassembly of section .text:

0000000000400430 <_start>:
  400430:	31 ed                	xor    ebp,ebp
  400432:	49 89 d1             	mov    r9,rdx
  400435:	5e                   	pop    rsi
  400436:	48 89 e2             	mov    rdx,rsp
  400439:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
  40043d:	50                   	push   rax
  40043e:	54                   	push   rsp
  40043f:	49 c7 c0 e0 05 40 00 	mov    r8,0x4005e0
  400446:	48 c7 c1 70 05 40 00 	mov    rcx,0x400570
  40044d:	48 c7 c7 26 05 40 00 	mov    rdi,0x400526
  400454:	e8 b7 ff ff ff       	call   400410 <__libc_start_main@plt>
  400459:	f4                   	hlt    
  40045a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000400460 <deregister_tm_clones>:
  400460:	b8 3f 10 60 00       	mov    eax,0x60103f
  400465:	55                   	push   rbp
  400466:	48 2d 38 10 60 00    	sub    rax,0x601038
  40046c:	48 83 f8 0e          	cmp    rax,0xe
  400470:	48 89 e5             	mov    rbp,rsp
  400473:	76 1b                	jbe    400490 <deregister_tm_clones+0x30>
  400475:	b8 00 00 00 00       	mov    eax,0x0
  40047a:	48 85 c0             	test   rax,rax
  40047d:	74 11                	je     400490 <deregister_tm_clones+0x30>
  40047f:	5d                   	pop    rbp
  400480:	bf 38 10 60 00       	mov    edi,0x601038
  400485:	ff e0                	jmp    rax
  400487:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
  40048e:	00 00 
  400490:	5d                   	pop    rbp
  400491:	c3                   	ret    
  400492:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  400496:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  40049d:	00 00 00 

00000000004004a0 <register_tm_clones>:
  4004a0:	be 38 10 60 00       	mov    esi,0x601038
  4004a5:	55                   	push   rbp
  4004a6:	48 81 ee 38 10 60 00 	sub    rsi,0x601038
  4004ad:	48 c1 fe 03          	sar    rsi,0x3
  4004b1:	48 89 e5             	mov    rbp,rsp
  4004b4:	48 89 f0             	mov    rax,rsi
  4004b7:	48 c1 e8 3f          	shr    rax,0x3f
  4004bb:	48 01 c6             	add    rsi,rax
  4004be:	48 d1 fe             	sar    rsi,1
  4004c1:	74 15                	je     4004d8 <register_tm_clones+0x38>
  4004c3:	b8 00 00 00 00       	mov    eax,0x0
  4004c8:	48 85 c0             	test   rax,rax
  4004cb:	74 0b                	je     4004d8 <register_tm_clones+0x38>
  4004cd:	5d                   	pop    rbp
  4004ce:	bf 38 10 60 00       	mov    edi,0x601038
  4004d3:	ff e0                	jmp    rax
  4004d5:	0f 1f 00             	nop    DWORD PTR [rax]
  4004d8:	5d                   	pop    rbp
  4004d9:	c3                   	ret    
  4004da:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

00000000004004e0 <__do_global_dtors_aux>:
  4004e0:	80 3d 51 0b 20 00 00 	cmp    BYTE PTR [rip+0x200b51],0x0        # 601038 <__TMC_END__>
  4004e7:	75 11                	jne    4004fa <__do_global_dtors_aux+0x1a>
  4004e9:	55                   	push   rbp
  4004ea:	48 89 e5             	mov    rbp,rsp
  4004ed:	e8 6e ff ff ff       	call   400460 <deregister_tm_clones>
  4004f2:	5d                   	pop    rbp
  4004f3:	c6 05 3e 0b 20 00 01 	mov    BYTE PTR [rip+0x200b3e],0x1        # 601038 <__TMC_END__>
  4004fa:	f3 c3                	repz ret 
  4004fc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000400500 <frame_dummy>:
  400500:	bf 20 0e 60 00       	mov    edi,0x600e20
  400505:	48 83 3f 00          	cmp    QWORD PTR [rdi],0x0
  400509:	75 05                	jne    400510 <frame_dummy+0x10>
  40050b:	eb 93                	jmp    4004a0 <register_tm_clones>
  40050d:	0f 1f 00             	nop    DWORD PTR [rax]
  400510:	b8 00 00 00 00       	mov    eax,0x0
  400515:	48 85 c0             	test   rax,rax
  400518:	74 f1                	je     40050b <frame_dummy+0xb>
  40051a:	55                   	push   rbp
  40051b:	48 89 e5             	mov    rbp,rsp
  40051e:	ff d0                	call   rax
  400520:	5d                   	pop    rbp
  400521:	e9 7a ff ff ff       	jmp    4004a0 <register_tm_clones>

0000000000400526 <main>:
  400526:	55                   	push   rbp
  400527:	48 89 e5             	mov    rbp,rsp
  40052a:	48 83 ec 10          	sub    rsp,0x10
  40052e:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [rbp-0x4],0x2
  400535:	c7 45 f8 03 00 00 00 	mov    DWORD PTR [rbp-0x8],0x3
  40053c:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [rbp-0xc],0x0
  400543:	8b 55 fc             	mov    edx,DWORD PTR [rbp-0x4]
  400546:	8b 45 f8             	mov    eax,DWORD PTR [rbp-0x8]
  400549:	01 d0                	add    eax,edx
  40054b:	89 45 f4             	mov    DWORD PTR [rbp-0xc],eax
  40054e:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
  400551:	89 c6                	mov    esi,eax
  400553:	bf f4 05 40 00       	mov    edi,0x4005f4
  400558:	b8 00 00 00 00       	mov    eax,0x0
  40055d:	e8 9e fe ff ff       	call   400400 <printf@plt>
  400562:	b8 00 00 00 00       	mov    eax,0x0
  400567:	c9                   	leave  
  400568:	c3                   	ret    
  400569:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000400570 <__libc_csu_init>:
  400570:	41 57                	push   r15
  400572:	41 56                	push   r14
  400574:	41 89 ff             	mov    r15d,edi
  400577:	41 55                	push   r13
  400579:	41 54                	push   r12
  40057b:	4c 8d 25 8e 08 20 00 	lea    r12,[rip+0x20088e]        # 600e10 <__frame_dummy_init_array_entry>
  400582:	55                   	push   rbp
  400583:	48 8d 2d 8e 08 20 00 	lea    rbp,[rip+0x20088e]        # 600e18 <__init_array_end>
  40058a:	53                   	push   rbx
  40058b:	49 89 f6             	mov    r14,rsi
  40058e:	49 89 d5             	mov    r13,rdx
  400591:	4c 29 e5             	sub    rbp,r12
  400594:	48 83 ec 08          	sub    rsp,0x8
  400598:	48 c1 fd 03          	sar    rbp,0x3
  40059c:	e8 27 fe ff ff       	call   4003c8 <_init>
  4005a1:	48 85 ed             	test   rbp,rbp
  4005a4:	74 20                	je     4005c6 <__libc_csu_init+0x56>
  4005a6:	31 db                	xor    ebx,ebx
  4005a8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
  4005af:	00 
  4005b0:	4c 89 ea             	mov    rdx,r13
  4005b3:	4c 89 f6             	mov    rsi,r14
  4005b6:	44 89 ff             	mov    edi,r15d
  4005b9:	41 ff 14 dc          	call   QWORD PTR [r12+rbx*8]
  4005bd:	48 83 c3 01          	add    rbx,0x1
  4005c1:	48 39 eb             	cmp    rbx,rbp
  4005c4:	75 ea                	jne    4005b0 <__libc_csu_init+0x40>
  4005c6:	48 83 c4 08          	add    rsp,0x8
  4005ca:	5b                   	pop    rbx
  4005cb:	5d                   	pop    rbp
  4005cc:	41 5c                	pop    r12
  4005ce:	41 5d                	pop    r13
  4005d0:	41 5e                	pop    r14
  4005d2:	41 5f                	pop    r15
  4005d4:	c3                   	ret    
  4005d5:	90                   	nop
  4005d6:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  4005dd:	00 00 00 

00000000004005e0 <__libc_csu_fini>:
  4005e0:	f3 c3                	repz ret 

Disassembly of section .fini:

00000000004005e4 <_fini>:
  4005e4:	48 83 ec 08          	sub    rsp,0x8
  4005e8:	48 83 c4 08          	add    rsp,0x8
  4005ec:	c3                   	ret    

Disassembly of section .rodata:

00000000004005f0 <_IO_stdin_used>:
  4005f0:	01 00                	add    DWORD PTR [rax],eax
  4005f2:	02 00                	add    al,BYTE PTR [rax]
  4005f4:	25                   	.byte 0x25
  4005f5:	64                   	fs
	...

Disassembly of section .eh_frame_hdr:

00000000004005f8 <__GNU_EH_FRAME_HDR>:
  4005f8:	01 1b                	add    DWORD PTR [rbx],ebx
  4005fa:	03 3b                	add    edi,DWORD PTR [rbx]
  4005fc:	34 00                	xor    al,0x0
  4005fe:	00 00                	add    BYTE PTR [rax],al
  400600:	05 00 00 00 f8       	add    eax,0xf8000000
  400605:	fd                   	std    
  400606:	ff                   	(bad)  
  400607:	ff 80 00 00 00 38    	inc    DWORD PTR [rax+0x38000000]
  40060d:	fe                   	(bad)  
  40060e:	ff                   	(bad)  
  40060f:	ff 50 00             	call   QWORD PTR [rax+0x0]
  400612:	00 00                	add    BYTE PTR [rax],al
  400614:	2e ff                	cs (bad) 
  400616:	ff                   	(bad)  
  400617:	ff a8 00 00 00 78    	jmp    FWORD PTR [rax+0x78000000]
  40061d:	ff                   	(bad)  
  40061e:	ff                   	(bad)  
  40061f:	ff c8                	dec    eax
  400621:	00 00                	add    BYTE PTR [rax],al
  400623:	00 e8                	add    al,ch
  400625:	ff                   	(bad)  
  400626:	ff                   	(bad)  
  400627:	ff 10                	call   QWORD PTR [rax]
  400629:	01 00                	add    DWORD PTR [rax],eax
	...

Disassembly of section .eh_frame:

0000000000400630 <__FRAME_END__-0xf0>:
  400630:	14 00                	adc    al,0x0
  400632:	00 00                	add    BYTE PTR [rax],al
  400634:	00 00                	add    BYTE PTR [rax],al
  400636:	00 00                	add    BYTE PTR [rax],al
  400638:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  40063b:	00 01                	add    BYTE PTR [rcx],al
  40063d:	78 10                	js     40064f <__GNU_EH_FRAME_HDR+0x57>
  40063f:	01 1b                	add    DWORD PTR [rbx],ebx
  400641:	0c 07                	or     al,0x7
  400643:	08 90 01 07 10 14    	or     BYTE PTR [rax+0x14100701],dl
  400649:	00 00                	add    BYTE PTR [rax],al
  40064b:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  40064e:	00 00                	add    BYTE PTR [rax],al
  400650:	e0 fd                	loopne 40064f <__GNU_EH_FRAME_HDR+0x57>
  400652:	ff                   	(bad)  
  400653:	ff 2a                	jmp    FWORD PTR [rdx]
	...
  40065d:	00 00                	add    BYTE PTR [rax],al
  40065f:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
  400662:	00 00                	add    BYTE PTR [rax],al
  400664:	00 00                	add    BYTE PTR [rax],al
  400666:	00 00                	add    BYTE PTR [rax],al
  400668:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  40066b:	00 01                	add    BYTE PTR [rcx],al
  40066d:	78 10                	js     40067f <__GNU_EH_FRAME_HDR+0x87>
  40066f:	01 1b                	add    DWORD PTR [rbx],ebx
  400671:	0c 07                	or     al,0x7
  400673:	08 90 01 00 00 24    	or     BYTE PTR [rax+0x24000001],dl
  400679:	00 00                	add    BYTE PTR [rax],al
  40067b:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  40067e:	00 00                	add    BYTE PTR [rax],al
  400680:	70 fd                	jo     40067f <__GNU_EH_FRAME_HDR+0x87>
  400682:	ff                   	(bad)  
  400683:	ff 30                	push   QWORD PTR [rax]
  400685:	00 00                	add    BYTE PTR [rax],al
  400687:	00 00                	add    BYTE PTR [rax],al
  400689:	0e                   	(bad)  
  40068a:	10 46 0e             	adc    BYTE PTR [rsi+0xe],al
  40068d:	18 4a 0f             	sbb    BYTE PTR [rdx+0xf],cl
  400690:	0b 77 08             	or     esi,DWORD PTR [rdi+0x8]
  400693:	80 00 3f             	add    BYTE PTR [rax],0x3f
  400696:	1a 3b                	sbb    bh,BYTE PTR [rbx]
  400698:	2a 33                	sub    dh,BYTE PTR [rbx]
  40069a:	24 22                	and    al,0x22
  40069c:	00 00                	add    BYTE PTR [rax],al
  40069e:	00 00                	add    BYTE PTR [rax],al
  4006a0:	1c 00                	sbb    al,0x0
  4006a2:	00 00                	add    BYTE PTR [rax],al
  4006a4:	44 00 00             	add    BYTE PTR [rax],r8b
  4006a7:	00 7e fe             	add    BYTE PTR [rsi-0x2],bh
  4006aa:	ff                   	(bad)  
  4006ab:	ff 43 00             	inc    DWORD PTR [rbx+0x0]
  4006ae:	00 00                	add    BYTE PTR [rax],al
  4006b0:	00 41 0e             	add    BYTE PTR [rcx+0xe],al
  4006b3:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  4006b9:	7e 0c                	jle    4006c7 <__GNU_EH_FRAME_HDR+0xcf>
  4006bb:	07                   	(bad)  
  4006bc:	08 00                	or     BYTE PTR [rax],al
  4006be:	00 00                	add    BYTE PTR [rax],al
  4006c0:	44 00 00             	add    BYTE PTR [rax],r8b
  4006c3:	00 64 00 00          	add    BYTE PTR [rax+rax*1+0x0],ah
  4006c7:	00 a8 fe ff ff 65    	add    BYTE PTR [rax+0x65fffffe],ch
  4006cd:	00 00                	add    BYTE PTR [rax],al
  4006cf:	00 00                	add    BYTE PTR [rax],al
  4006d1:	42 0e                	rex.X (bad) 
  4006d3:	10 8f 02 42 0e 18    	adc    BYTE PTR [rdi+0x180e4202],cl
  4006d9:	8e 03                	mov    es,WORD PTR [rbx]
  4006db:	45 0e                	rex.RB (bad) 
  4006dd:	20 8d 04 42 0e 28    	and    BYTE PTR [rbp+0x280e4204],cl
  4006e3:	8c 05 48 0e 30 86    	mov    WORD PTR [rip+0xffffffff86300e48],es        # ffffffff86701531 <_end+0xffffffff861004f1>
  4006e9:	06                   	(bad)  
  4006ea:	48 0e                	rex.W (bad) 
  4006ec:	38 83 07 4d 0e 40    	cmp    BYTE PTR [rbx+0x400e4d07],al
  4006f2:	72 0e                	jb     400702 <__GNU_EH_FRAME_HDR+0x10a>
  4006f4:	38 41 0e             	cmp    BYTE PTR [rcx+0xe],al
  4006f7:	30 41 0e             	xor    BYTE PTR [rcx+0xe],al
  4006fa:	28 42 0e             	sub    BYTE PTR [rdx+0xe],al
  4006fd:	20 42 0e             	and    BYTE PTR [rdx+0xe],al
  400700:	18 42 0e             	sbb    BYTE PTR [rdx+0xe],al
  400703:	10 42 0e             	adc    BYTE PTR [rdx+0xe],al
  400706:	08 00                	or     BYTE PTR [rax],al
  400708:	14 00                	adc    al,0x0
  40070a:	00 00                	add    BYTE PTR [rax],al
  40070c:	ac                   	lods   al,BYTE PTR ds:[rsi]
  40070d:	00 00                	add    BYTE PTR [rax],al
  40070f:	00 d0                	add    al,dl
  400711:	fe                   	(bad)  
  400712:	ff                   	(bad)  
  400713:	ff 02                	inc    DWORD PTR [rdx]
	...

0000000000400720 <__FRAME_END__>:
  400720:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .init_array:

0000000000600e10 <__frame_dummy_init_array_entry>:
  600e10:	00 05 40 00 00 00    	add    BYTE PTR [rip+0x40],al        # 600e56 <_DYNAMIC+0x2e>
	...

Disassembly of section .fini_array:

0000000000600e18 <__do_global_dtors_aux_fini_array_entry>:
  600e18:	e0 04                	loopne 600e1e <__do_global_dtors_aux_fini_array_entry+0x6>
  600e1a:	40 00 00             	add    BYTE PTR [rax],al
  600e1d:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .jcr:

0000000000600e20 <__JCR_END__>:
	...

Disassembly of section .dynamic:

0000000000600e28 <_DYNAMIC>:
  600e28:	01 00                	add    DWORD PTR [rax],eax
  600e2a:	00 00                	add    BYTE PTR [rax],al
  600e2c:	00 00                	add    BYTE PTR [rax],al
  600e2e:	00 00                	add    BYTE PTR [rax],al
  600e30:	01 00                	add    DWORD PTR [rax],eax
  600e32:	00 00                	add    BYTE PTR [rax],al
  600e34:	00 00                	add    BYTE PTR [rax],al
  600e36:	00 00                	add    BYTE PTR [rax],al
  600e38:	0c 00                	or     al,0x0
  600e3a:	00 00                	add    BYTE PTR [rax],al
  600e3c:	00 00                	add    BYTE PTR [rax],al
  600e3e:	00 00                	add    BYTE PTR [rax],al
  600e40:	c8 03 40 00          	enter  0x4003,0x0
  600e44:	00 00                	add    BYTE PTR [rax],al
  600e46:	00 00                	add    BYTE PTR [rax],al
  600e48:	0d 00 00 00 00       	or     eax,0x0
  600e4d:	00 00                	add    BYTE PTR [rax],al
  600e4f:	00 e4                	add    ah,ah
  600e51:	05 40 00 00 00       	add    eax,0x40
  600e56:	00 00                	add    BYTE PTR [rax],al
  600e58:	19 00                	sbb    DWORD PTR [rax],eax
  600e5a:	00 00                	add    BYTE PTR [rax],al
  600e5c:	00 00                	add    BYTE PTR [rax],al
  600e5e:	00 00                	add    BYTE PTR [rax],al
  600e60:	10 0e                	adc    BYTE PTR [rsi],cl
  600e62:	60                   	(bad)  
  600e63:	00 00                	add    BYTE PTR [rax],al
  600e65:	00 00                	add    BYTE PTR [rax],al
  600e67:	00 1b                	add    BYTE PTR [rbx],bl
  600e69:	00 00                	add    BYTE PTR [rax],al
  600e6b:	00 00                	add    BYTE PTR [rax],al
  600e6d:	00 00                	add    BYTE PTR [rax],al
  600e6f:	00 08                	add    BYTE PTR [rax],cl
  600e71:	00 00                	add    BYTE PTR [rax],al
  600e73:	00 00                	add    BYTE PTR [rax],al
  600e75:	00 00                	add    BYTE PTR [rax],al
  600e77:	00 1a                	add    BYTE PTR [rdx],bl
  600e79:	00 00                	add    BYTE PTR [rax],al
  600e7b:	00 00                	add    BYTE PTR [rax],al
  600e7d:	00 00                	add    BYTE PTR [rax],al
  600e7f:	00 18                	add    BYTE PTR [rax],bl
  600e81:	0e                   	(bad)  
  600e82:	60                   	(bad)  
  600e83:	00 00                	add    BYTE PTR [rax],al
  600e85:	00 00                	add    BYTE PTR [rax],al
  600e87:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  600e8a:	00 00                	add    BYTE PTR [rax],al
  600e8c:	00 00                	add    BYTE PTR [rax],al
  600e8e:	00 00                	add    BYTE PTR [rax],al
  600e90:	08 00                	or     BYTE PTR [rax],al
  600e92:	00 00                	add    BYTE PTR [rax],al
  600e94:	00 00                	add    BYTE PTR [rax],al
  600e96:	00 00                	add    BYTE PTR [rax],al
  600e98:	f5                   	cmc    
  600e99:	fe                   	(bad)  
  600e9a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  600e9d:	00 00                	add    BYTE PTR [rax],al
  600e9f:	00 98 02 40 00 00    	add    BYTE PTR [rax+0x4002],bl
  600ea5:	00 00                	add    BYTE PTR [rax],al
  600ea7:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 600ead <_DYNAMIC+0x85>
  600ead:	00 00                	add    BYTE PTR [rax],al
  600eaf:	00 18                	add    BYTE PTR [rax],bl
  600eb1:	03 40 00             	add    eax,DWORD PTR [rax+0x0]
  600eb4:	00 00                	add    BYTE PTR [rax],al
  600eb6:	00 00                	add    BYTE PTR [rax],al
  600eb8:	06                   	(bad)  
  600eb9:	00 00                	add    BYTE PTR [rax],al
  600ebb:	00 00                	add    BYTE PTR [rax],al
  600ebd:	00 00                	add    BYTE PTR [rax],al
  600ebf:	00 b8 02 40 00 00    	add    BYTE PTR [rax+0x4002],bh
  600ec5:	00 00                	add    BYTE PTR [rax],al
  600ec7:	00 0a                	add    BYTE PTR [rdx],cl
  600ec9:	00 00                	add    BYTE PTR [rax],al
  600ecb:	00 00                	add    BYTE PTR [rax],al
  600ecd:	00 00                	add    BYTE PTR [rax],al
  600ecf:	00 3f                	add    BYTE PTR [rdi],bh
  600ed1:	00 00                	add    BYTE PTR [rax],al
  600ed3:	00 00                	add    BYTE PTR [rax],al
  600ed5:	00 00                	add    BYTE PTR [rax],al
  600ed7:	00 0b                	add    BYTE PTR [rbx],cl
  600ed9:	00 00                	add    BYTE PTR [rax],al
  600edb:	00 00                	add    BYTE PTR [rax],al
  600edd:	00 00                	add    BYTE PTR [rax],al
  600edf:	00 18                	add    BYTE PTR [rax],bl
  600ee1:	00 00                	add    BYTE PTR [rax],al
  600ee3:	00 00                	add    BYTE PTR [rax],al
  600ee5:	00 00                	add    BYTE PTR [rax],al
  600ee7:	00 15 00 00 00 00    	add    BYTE PTR [rip+0x0],dl        # 600eed <_DYNAMIC+0xc5>
	...
  600ef5:	00 00                	add    BYTE PTR [rax],al
  600ef7:	00 03                	add    BYTE PTR [rbx],al
	...
  600f01:	10 60 00             	adc    BYTE PTR [rax+0x0],ah
  600f04:	00 00                	add    BYTE PTR [rax],al
  600f06:	00 00                	add    BYTE PTR [rax],al
  600f08:	02 00                	add    al,BYTE PTR [rax]
  600f0a:	00 00                	add    BYTE PTR [rax],al
  600f0c:	00 00                	add    BYTE PTR [rax],al
  600f0e:	00 00                	add    BYTE PTR [rax],al
  600f10:	30 00                	xor    BYTE PTR [rax],al
  600f12:	00 00                	add    BYTE PTR [rax],al
  600f14:	00 00                	add    BYTE PTR [rax],al
  600f16:	00 00                	add    BYTE PTR [rax],al
  600f18:	14 00                	adc    al,0x0
  600f1a:	00 00                	add    BYTE PTR [rax],al
  600f1c:	00 00                	add    BYTE PTR [rax],al
  600f1e:	00 00                	add    BYTE PTR [rax],al
  600f20:	07                   	(bad)  
  600f21:	00 00                	add    BYTE PTR [rax],al
  600f23:	00 00                	add    BYTE PTR [rax],al
  600f25:	00 00                	add    BYTE PTR [rax],al
  600f27:	00 17                	add    BYTE PTR [rdi],dl
  600f29:	00 00                	add    BYTE PTR [rax],al
  600f2b:	00 00                	add    BYTE PTR [rax],al
  600f2d:	00 00                	add    BYTE PTR [rax],al
  600f2f:	00 98 03 40 00 00    	add    BYTE PTR [rax+0x4003],bl
  600f35:	00 00                	add    BYTE PTR [rax],al
  600f37:	00 07                	add    BYTE PTR [rdi],al
  600f39:	00 00                	add    BYTE PTR [rax],al
  600f3b:	00 00                	add    BYTE PTR [rax],al
  600f3d:	00 00                	add    BYTE PTR [rax],al
  600f3f:	00 80 03 40 00 00    	add    BYTE PTR [rax+0x4003],al
  600f45:	00 00                	add    BYTE PTR [rax],al
  600f47:	00 08                	add    BYTE PTR [rax],cl
  600f49:	00 00                	add    BYTE PTR [rax],al
  600f4b:	00 00                	add    BYTE PTR [rax],al
  600f4d:	00 00                	add    BYTE PTR [rax],al
  600f4f:	00 18                	add    BYTE PTR [rax],bl
  600f51:	00 00                	add    BYTE PTR [rax],al
  600f53:	00 00                	add    BYTE PTR [rax],al
  600f55:	00 00                	add    BYTE PTR [rax],al
  600f57:	00 09                	add    BYTE PTR [rcx],cl
  600f59:	00 00                	add    BYTE PTR [rax],al
  600f5b:	00 00                	add    BYTE PTR [rax],al
  600f5d:	00 00                	add    BYTE PTR [rax],al
  600f5f:	00 18                	add    BYTE PTR [rax],bl
  600f61:	00 00                	add    BYTE PTR [rax],al
  600f63:	00 00                	add    BYTE PTR [rax],al
  600f65:	00 00                	add    BYTE PTR [rax],al
  600f67:	00 fe                	add    dh,bh
  600f69:	ff                   	(bad)  
  600f6a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  600f6d:	00 00                	add    BYTE PTR [rax],al
  600f6f:	00 60 03             	add    BYTE PTR [rax+0x3],ah
  600f72:	40 00 00             	add    BYTE PTR [rax],al
  600f75:	00 00                	add    BYTE PTR [rax],al
  600f77:	00 ff                	add    bh,bh
  600f79:	ff                   	(bad)  
  600f7a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  600f7d:	00 00                	add    BYTE PTR [rax],al
  600f7f:	00 01                	add    BYTE PTR [rcx],al
  600f81:	00 00                	add    BYTE PTR [rax],al
  600f83:	00 00                	add    BYTE PTR [rax],al
  600f85:	00 00                	add    BYTE PTR [rax],al
  600f87:	00 f0                	add    al,dh
  600f89:	ff                   	(bad)  
  600f8a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  600f8d:	00 00                	add    BYTE PTR [rax],al
  600f8f:	00 58 03             	add    BYTE PTR [rax+0x3],bl
  600f92:	40 00 00             	add    BYTE PTR [rax],al
	...

Disassembly of section .got:

0000000000600ff8 <.got>:
	...

Disassembly of section .got.plt:

0000000000601000 <_GLOBAL_OFFSET_TABLE_>:
  601000:	28 0e                	sub    BYTE PTR [rsi],cl
  601002:	60                   	(bad)  
	...
  601017:	00 06                	add    BYTE PTR [rsi],al
  601019:	04 40                	add    al,0x40
  60101b:	00 00                	add    BYTE PTR [rax],al
  60101d:	00 00                	add    BYTE PTR [rax],al
  60101f:	00 16                	add    BYTE PTR [rsi],dl
  601021:	04 40                	add    al,0x40
  601023:	00 00                	add    BYTE PTR [rax],al
  601025:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .data:

0000000000601028 <__data_start>:
	...

0000000000601030 <__dso_handle>:
	...

Disassembly of section .bss:

0000000000601038 <__bss_start>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
   5:	28 44 65 62          	sub    BYTE PTR [rbp+riz*2+0x62],al
   9:	69 61 6e 20 36 2e 31 	imul   esp,DWORD PTR [rcx+0x6e],0x312e3620
  10:	2e 31 2d 31 31 29 20 	xor    DWORD PTR cs:[rip+0x20293131],ebp        # 20293148 <_end+0x1fc92108>
  17:	36 2e 31 2e          	ss xor DWORD PTR cs:[rsi],ebp
  1b:	31 20                	xor    DWORD PTR [rax],esp
  1d:	32 30                	xor    dh,BYTE PTR [rax]
  1f:	31 36                	xor    DWORD PTR [rsi],esi
  21:	30 38                	xor    BYTE PTR [rax],bh
  23:	30 32                	xor    BYTE PTR [rdx],dh
	...
