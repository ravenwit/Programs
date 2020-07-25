
test:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400238 <.interp>:
  400238:	2f                   	(bad)  
  400239:	6c                   	ins    BYTE PTR es:[rdi],dx
  40023a:	69 62 36 34 2f 6c 64 	imul   esp,DWORD PTR [rdx+0x36],0x646c2f34
  400241:	2d 6c 69 6e 75       	sub    eax,0x756e696c
  400246:	78 2d                	js     400275 <_init-0x363>
  400248:	78 38                	js     400282 <_init-0x356>
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
  400283:	00 d3                	add    bl,dl
  400285:	84 75 b3             	test   BYTE PTR [rbp-0x4d],dh
  400288:	a8 1d                	test   al,0x1d
  40028a:	8c 9c 8f d5 d5 e4 18 	mov    WORD PTR [rdi+rcx*4+0x18e4d5d5],ds
  400291:	d7                   	xlat   BYTE PTR ds:[rbx]
  400292:	f9                   	stc    
  400293:	38 07                	cmp    BYTE PTR [rdi],al
  400295:	36                   	ss
  400296:	1a                   	.byte 0x1a
  400297:	b6                   	.byte 0xb6

Disassembly of section .gnu.hash:

0000000000400298 <.gnu.hash>:
  400298:	03 00                	add    eax,DWORD PTR [rax]
  40029a:	00 00                	add    BYTE PTR [rax],al
  40029c:	09 00                	or     DWORD PTR [rax],eax
  40029e:	00 00                	add    BYTE PTR [rax],al
  4002a0:	01 00                	add    DWORD PTR [rax],eax
  4002a2:	00 00                	add    BYTE PTR [rax],al
  4002a4:	06                   	(bad)  
  4002a5:	00 00                	add    BYTE PTR [rax],al
  4002a7:	00 88 c0 20 01 00    	add    BYTE PTR [rax+0x120c0],cl
  4002ad:	04 40                	add    al,0x40
  4002af:	09 09                	or     DWORD PTR [rcx],ecx
  4002b1:	00 00                	add    BYTE PTR [rax],al
  4002b3:	00 0b                	add    BYTE PTR [rbx],cl
  4002b5:	00 00                	add    BYTE PTR [rax],al
  4002b7:	00 0d 00 00 00 42    	add    BYTE PTR [rip+0x42000000],cl        # 424002bd <_end+0x41dff255>
  4002bd:	45 d5                	rex.RB (bad) 
  4002bf:	ec                   	in     al,dx
  4002c0:	bb e3 92 7c d8       	mov    ebx,0xd87c92e3
  4002c5:	71 58                	jno    40031f <_init-0x2b9>
  4002c7:	1c b9                	sbb    al,0xb9
  4002c9:	8d                   	(bad)  
  4002ca:	f1                   	icebp  
  4002cb:	0e                   	(bad)  
  4002cc:	eb d3                	jmp    4002a1 <_init-0x337>
  4002ce:	ef                   	out    dx,eax
  4002cf:	0e                   	(bad)  

Disassembly of section .dynsym:

00000000004002d0 <.dynsym>:
	...
  4002e8:	2b 00                	sub    eax,DWORD PTR [rax]
  4002ea:	00 00                	add    BYTE PTR [rax],al
  4002ec:	12 00                	adc    al,BYTE PTR [rax]
	...
  4002fe:	00 00                	add    BYTE PTR [rax],al
  400300:	1b 00                	sbb    eax,DWORD PTR [rax]
  400302:	00 00                	add    BYTE PTR [rax],al
  400304:	12 00                	adc    al,BYTE PTR [rax]
	...
  400316:	00 00                	add    BYTE PTR [rax],al
  400318:	60                   	(bad)  
  400319:	00 00                	add    BYTE PTR [rax],al
  40031b:	00 12                	add    BYTE PTR [rdx],dl
	...
  40032d:	00 00                	add    BYTE PTR [rax],al
  40032f:	00 23                	add    BYTE PTR [rbx],ah
  400331:	00 00                	add    BYTE PTR [rax],al
  400333:	00 12                	add    BYTE PTR [rdx],dl
	...
  400345:	00 00                	add    BYTE PTR [rax],al
  400347:	00 67 00             	add    BYTE PTR [rdi+0x0],ah
  40034a:	00 00                	add    BYTE PTR [rax],al
  40034c:	12 00                	adc    al,BYTE PTR [rax]
	...
  40035e:	00 00                	add    BYTE PTR [rax],al
  400360:	0c 00                	or     al,0x0
  400362:	00 00                	add    BYTE PTR [rax],al
  400364:	20 00                	and    BYTE PTR [rax],al
	...
  400376:	00 00                	add    BYTE PTR [rax],al
  400378:	51                   	push   rcx
  400379:	00 00                	add    BYTE PTR [rax],al
  40037b:	00 12                	add    BYTE PTR [rdx],dl
	...
  40038d:	00 00                	add    BYTE PTR [rax],al
  40038f:	00 3f                	add    BYTE PTR [rdi],bh
  400391:	00 00                	add    BYTE PTR [rax],al
  400393:	00 12                	add    BYTE PTR [rdx],dl
	...
  4003a5:	00 00                	add    BYTE PTR [rax],al
  4003a7:	00 79 00             	add    BYTE PTR [rcx+0x0],bh
  4003aa:	00 00                	add    BYTE PTR [rax],al
  4003ac:	10 00                	adc    BYTE PTR [rax],al
  4003ae:	19 00                	sbb    DWORD PTR [rax],eax
  4003b0:	60                   	(bad)  
  4003b1:	10 60 00             	adc    BYTE PTR [rax+0x0],ah
	...
  4003c0:	8c 00                	mov    WORD PTR [rax],es
  4003c2:	00 00                	add    BYTE PTR [rax],al
  4003c4:	10 00                	adc    BYTE PTR [rax],al
  4003c6:	1a 00                	sbb    al,BYTE PTR [rax]
  4003c8:	68 10 60 00 00       	push   0x6010
	...
  4003d5:	00 00                	add    BYTE PTR [rax],al
  4003d7:	00 80 00 00 00 10    	add    BYTE PTR [rax+0x10000000],al
  4003dd:	00 1a                	add    BYTE PTR [rdx],bl
  4003df:	00 60 10             	add    BYTE PTR [rax+0x10],ah
  4003e2:	60                   	(bad)  
	...
  4003ef:	00 33                	add    BYTE PTR [rbx],dh
  4003f1:	00 00                	add    BYTE PTR [rax],al
  4003f3:	00 12                	add    BYTE PTR [rdx],dl
  4003f5:	00 0b                	add    BYTE PTR [rbx],cl
  4003f7:	00 d8                	add    al,bl
  4003f9:	05 40 00 00 00       	add    eax,0x40
	...
  400406:	00 00                	add    BYTE PTR [rax],al
  400408:	39 00                	cmp    DWORD PTR [rax],eax
  40040a:	00 00                	add    BYTE PTR [rax],al
  40040c:	12 00                	adc    al,BYTE PTR [rax]
  40040e:	0f 00 c4             	sldt   esp
  400411:	08 40 00             	or     BYTE PTR [rax+0x0],al
	...

Disassembly of section .dynstr:

0000000000400420 <.dynstr>:
  400420:	00 6c 69 62          	add    BYTE PTR [rcx+rbp*2+0x62],ch
  400424:	63 61 6c             	movsxd esp,DWORD PTR [rcx+0x6c]
  400427:	63 2e                	movsxd ebp,DWORD PTR [rsi]
  400429:	73 6f                	jae    40049a <_init-0x13e>
  40042b:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
  40042e:	67 6d                	ins    DWORD PTR es:[edi],dx
  400430:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  400431:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  400432:	5f                   	pop    rdi
  400433:	73 74                	jae    4004a9 <_init-0x12f>
  400435:	61                   	(bad)  
  400436:	72 74                	jb     4004ac <_init-0x12c>
  400438:	5f                   	pop    rdi
  400439:	5f                   	pop    rdi
  40043a:	00 61 64             	add    BYTE PTR [rcx+0x64],ah
  40043d:	64 5f                	fs pop rdi
  40043f:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  400440:	75 6d                	jne    4004af <_init-0x129>
  400442:	00 6d 75             	add    BYTE PTR [rbp+0x75],ch
  400445:	6c                   	ins    BYTE PTR es:[rdi],dx
  400446:	5f                   	pop    rdi
  400447:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  400448:	75 6d                	jne    4004b7 <_init-0x121>
  40044a:	00 73 75             	add    BYTE PTR [rbx+0x75],dh
  40044d:	62                   	(bad)  
  40044e:	5f                   	pop    rdi
  40044f:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  400450:	75 6d                	jne    4004bf <_init-0x119>
  400452:	00 5f 69             	add    BYTE PTR [rdi+0x69],bl
  400455:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  400456:	69 74 00 5f 66 69 6e 	imul   esi,DWORD PTR [rax+rax*1+0x5f],0x696e6966
  40045d:	69 
  40045e:	00 64 69 76          	add    BYTE PTR [rcx+rbp*2+0x76],ah
  400462:	5f                   	pop    rdi
  400463:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  400464:	75 6d                	jne    4004d3 <_init-0x105>
  400466:	00 6c 69 62          	add    BYTE PTR [rcx+rbp*2+0x62],ch
  40046a:	63 2e                	movsxd ebp,DWORD PTR [rsi]
  40046c:	73 6f                	jae    4004dd <_init-0xfb>
  40046e:	2e 36 00 5f 5f       	cs add BYTE PTR ss:[rdi+0x5f],bl
  400473:	69 73 6f 63 39 39 5f 	imul   esi,DWORD PTR [rbx+0x6f],0x5f393963
  40047a:	73 63                	jae    4004df <_init-0xf9>
  40047c:	61                   	(bad)  
  40047d:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  40047e:	66 00 70 72          	data16 add BYTE PTR [rax+0x72],dh
  400482:	69 6e 74 66 00 5f 5f 	imul   ebp,DWORD PTR [rsi+0x74],0x5f5f0066
  400489:	6c                   	ins    BYTE PTR es:[rdi],dx
  40048a:	69 62 63 5f 73 74 61 	imul   esp,DWORD PTR [rdx+0x63],0x6174735f
  400491:	72 74                	jb     400507 <_init-0xd1>
  400493:	5f                   	pop    rdi
  400494:	6d                   	ins    DWORD PTR es:[rdi],dx
  400495:	61                   	(bad)  
  400496:	69 6e 00 5f 65 64 61 	imul   ebp,DWORD PTR [rsi+0x0],0x6164655f
  40049d:	74 61                	je     400500 <_init-0xd8>
  40049f:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
  4004a2:	62 73                	(bad)  
  4004a4:	73 5f                	jae    400505 <_init-0xd3>
  4004a6:	73 74                	jae    40051c <_init-0xbc>
  4004a8:	61                   	(bad)  
  4004a9:	72 74                	jb     40051f <_init-0xb9>
  4004ab:	00 5f 65             	add    BYTE PTR [rdi+0x65],bl
  4004ae:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  4004af:	64 00 47 4c          	add    BYTE PTR fs:[rdi+0x4c],al
  4004b3:	49                   	rex.WB
  4004b4:	42                   	rex.X
  4004b5:	43 5f                	rex.XB pop r15
  4004b7:	32 2e                	xor    ch,BYTE PTR [rsi]
  4004b9:	37                   	(bad)  
  4004ba:	00 47 4c             	add    BYTE PTR [rdi+0x4c],al
  4004bd:	49                   	rex.WB
  4004be:	42                   	rex.X
  4004bf:	43 5f                	rex.XB pop r15
  4004c1:	32 2e                	xor    ch,BYTE PTR [rsi]
  4004c3:	32 2e                	xor    ch,BYTE PTR [rsi]
  4004c5:	35                   	.byte 0x35
	...

Disassembly of section .gnu.version:

00000000004004c8 <.gnu.version>:
  4004c8:	00 00                	add    BYTE PTR [rax],al
  4004ca:	00 00                	add    BYTE PTR [rax],al
  4004cc:	00 00                	add    BYTE PTR [rax],al
  4004ce:	02 00                	add    al,BYTE PTR [rax]
  4004d0:	00 00                	add    BYTE PTR [rax],al
  4004d2:	02 00                	add    al,BYTE PTR [rax]
  4004d4:	00 00                	add    BYTE PTR [rax],al
  4004d6:	03 00                	add    eax,DWORD PTR [rax]
  4004d8:	00 00                	add    BYTE PTR [rax],al
  4004da:	01 00                	add    DWORD PTR [rax],eax
  4004dc:	01 00                	add    DWORD PTR [rax],eax
  4004de:	01 00                	add    DWORD PTR [rax],eax
  4004e0:	01 00                	add    DWORD PTR [rax],eax
  4004e2:	01 00                	add    DWORD PTR [rax],eax

Disassembly of section .gnu.version_r:

00000000004004e8 <.gnu.version_r>:
  4004e8:	01 00                	add    DWORD PTR [rax],eax
  4004ea:	02 00                	add    al,BYTE PTR [rax]
  4004ec:	47 00 00             	rex.RXB add BYTE PTR [r8],r8b
  4004ef:	00 10                	add    BYTE PTR [rax],dl
  4004f1:	00 00                	add    BYTE PTR [rax],al
  4004f3:	00 00                	add    BYTE PTR [rax],al
  4004f5:	00 00                	add    BYTE PTR [rax],al
  4004f7:	00 17                	add    BYTE PTR [rdi],dl
  4004f9:	69 69 0d 00 00 03 00 	imul   ebp,DWORD PTR [rcx+0xd],0x30000
  400500:	91                   	xchg   ecx,eax
  400501:	00 00                	add    BYTE PTR [rax],al
  400503:	00 10                	add    BYTE PTR [rax],dl
  400505:	00 00                	add    BYTE PTR [rax],al
  400507:	00 75 1a             	add    BYTE PTR [rbp+0x1a],dh
  40050a:	69 09 00 00 02 00    	imul   ecx,DWORD PTR [rcx],0x20000
  400510:	9b                   	fwait
  400511:	00 00                	add    BYTE PTR [rax],al
  400513:	00 00                	add    BYTE PTR [rax],al
  400515:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .rela.dyn:

0000000000400518 <.rela.dyn>:
  400518:	f8                   	clc    
  400519:	0f 60 00             	punpcklbw mm0,DWORD PTR [rax]
  40051c:	00 00                	add    BYTE PTR [rax],al
  40051e:	00 00                	add    BYTE PTR [rax],al
  400520:	06                   	(bad)  
  400521:	00 00                	add    BYTE PTR [rax],al
  400523:	00 06                	add    BYTE PTR [rsi],al
	...

Disassembly of section .rela.plt:

0000000000400530 <.rela.plt>:
  400530:	18 10                	sbb    BYTE PTR [rax],dl
  400532:	60                   	(bad)  
  400533:	00 00                	add    BYTE PTR [rax],al
  400535:	00 00                	add    BYTE PTR [rax],al
  400537:	00 07                	add    BYTE PTR [rdi],al
  400539:	00 00                	add    BYTE PTR [rax],al
  40053b:	00 01                	add    BYTE PTR [rcx],al
	...
  400545:	00 00                	add    BYTE PTR [rax],al
  400547:	00 20                	add    BYTE PTR [rax],ah
  400549:	10 60 00             	adc    BYTE PTR [rax+0x0],ah
  40054c:	00 00                	add    BYTE PTR [rax],al
  40054e:	00 00                	add    BYTE PTR [rax],al
  400550:	07                   	(bad)  
  400551:	00 00                	add    BYTE PTR [rax],al
  400553:	00 02                	add    BYTE PTR [rdx],al
	...
  40055d:	00 00                	add    BYTE PTR [rax],al
  40055f:	00 28                	add    BYTE PTR [rax],ch
  400561:	10 60 00             	adc    BYTE PTR [rax+0x0],ah
  400564:	00 00                	add    BYTE PTR [rax],al
  400566:	00 00                	add    BYTE PTR [rax],al
  400568:	07                   	(bad)  
  400569:	00 00                	add    BYTE PTR [rax],al
  40056b:	00 03                	add    BYTE PTR [rbx],al
	...
  400575:	00 00                	add    BYTE PTR [rax],al
  400577:	00 30                	add    BYTE PTR [rax],dh
  400579:	10 60 00             	adc    BYTE PTR [rax+0x0],ah
  40057c:	00 00                	add    BYTE PTR [rax],al
  40057e:	00 00                	add    BYTE PTR [rax],al
  400580:	07                   	(bad)  
  400581:	00 00                	add    BYTE PTR [rax],al
  400583:	00 04 00             	add    BYTE PTR [rax+rax*1],al
	...
  40058e:	00 00                	add    BYTE PTR [rax],al
  400590:	38 10                	cmp    BYTE PTR [rax],dl
  400592:	60                   	(bad)  
  400593:	00 00                	add    BYTE PTR [rax],al
  400595:	00 00                	add    BYTE PTR [rax],al
  400597:	00 07                	add    BYTE PTR [rdi],al
  400599:	00 00                	add    BYTE PTR [rax],al
  40059b:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 4005a1 <_init-0x37>
  4005a1:	00 00                	add    BYTE PTR [rax],al
  4005a3:	00 00                	add    BYTE PTR [rax],al
  4005a5:	00 00                	add    BYTE PTR [rax],al
  4005a7:	00 40 10             	add    BYTE PTR [rax+0x10],al
  4005aa:	60                   	(bad)  
  4005ab:	00 00                	add    BYTE PTR [rax],al
  4005ad:	00 00                	add    BYTE PTR [rax],al
  4005af:	00 07                	add    BYTE PTR [rdi],al
  4005b1:	00 00                	add    BYTE PTR [rax],al
  4005b3:	00 07                	add    BYTE PTR [rdi],al
	...
  4005bd:	00 00                	add    BYTE PTR [rax],al
  4005bf:	00 48 10             	add    BYTE PTR [rax+0x10],cl
  4005c2:	60                   	(bad)  
  4005c3:	00 00                	add    BYTE PTR [rax],al
  4005c5:	00 00                	add    BYTE PTR [rax],al
  4005c7:	00 07                	add    BYTE PTR [rdi],al
  4005c9:	00 00                	add    BYTE PTR [rax],al
  4005cb:	00 08                	add    BYTE PTR [rax],cl
	...

Disassembly of section .init:

00000000004005d8 <_init>:
  4005d8:	48 83 ec 08          	sub    rsp,0x8
  4005dc:	48 8b 05 15 0a 20 00 	mov    rax,QWORD PTR [rip+0x200a15]        # 600ff8 <_DYNAMIC+0x1e0>
  4005e3:	48 85 c0             	test   rax,rax
  4005e6:	74 05                	je     4005ed <_init+0x15>
  4005e8:	e8 93 00 00 00       	call   400680 <div_num@plt+0x10>
  4005ed:	48 83 c4 08          	add    rsp,0x8
  4005f1:	c3                   	ret    

Disassembly of section .plt:

0000000000400600 <sub_num@plt-0x10>:
  400600:	ff 35 02 0a 20 00    	push   QWORD PTR [rip+0x200a02]        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400606:	ff 25 04 0a 20 00    	jmp    QWORD PTR [rip+0x200a04]        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40060c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000400610 <sub_num@plt>:
  400610:	ff 25 02 0a 20 00    	jmp    QWORD PTR [rip+0x200a02]        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400616:	68 00 00 00 00       	push   0x0
  40061b:	e9 e0 ff ff ff       	jmp    400600 <_init+0x28>

0000000000400620 <add_num@plt>:
  400620:	ff 25 fa 09 20 00    	jmp    QWORD PTR [rip+0x2009fa]        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400626:	68 01 00 00 00       	push   0x1
  40062b:	e9 d0 ff ff ff       	jmp    400600 <_init+0x28>

0000000000400630 <printf@plt>:
  400630:	ff 25 f2 09 20 00    	jmp    QWORD PTR [rip+0x2009f2]        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400636:	68 02 00 00 00       	push   0x2
  40063b:	e9 c0 ff ff ff       	jmp    400600 <_init+0x28>

0000000000400640 <mul_num@plt>:
  400640:	ff 25 ea 09 20 00    	jmp    QWORD PTR [rip+0x2009ea]        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400646:	68 03 00 00 00       	push   0x3
  40064b:	e9 b0 ff ff ff       	jmp    400600 <_init+0x28>

0000000000400650 <__libc_start_main@plt>:
  400650:	ff 25 e2 09 20 00    	jmp    QWORD PTR [rip+0x2009e2]        # 601038 <_GLOBAL_OFFSET_TABLE_+0x38>
  400656:	68 04 00 00 00       	push   0x4
  40065b:	e9 a0 ff ff ff       	jmp    400600 <_init+0x28>

0000000000400660 <__isoc99_scanf@plt>:
  400660:	ff 25 da 09 20 00    	jmp    QWORD PTR [rip+0x2009da]        # 601040 <_GLOBAL_OFFSET_TABLE_+0x40>
  400666:	68 05 00 00 00       	push   0x5
  40066b:	e9 90 ff ff ff       	jmp    400600 <_init+0x28>

0000000000400670 <div_num@plt>:
  400670:	ff 25 d2 09 20 00    	jmp    QWORD PTR [rip+0x2009d2]        # 601048 <_GLOBAL_OFFSET_TABLE_+0x48>
  400676:	68 06 00 00 00       	push   0x6
  40067b:	e9 80 ff ff ff       	jmp    400600 <_init+0x28>

Disassembly of section .plt.got:

0000000000400680 <.plt.got>:
  400680:	ff 25 72 09 20 00    	jmp    QWORD PTR [rip+0x200972]        # 600ff8 <_DYNAMIC+0x1e0>
  400686:	66 90                	xchg   ax,ax

Disassembly of section .text:

0000000000400690 <_start>:
  400690:	31 ed                	xor    ebp,ebp
  400692:	49 89 d1             	mov    r9,rdx
  400695:	5e                   	pop    rsi
  400696:	48 89 e2             	mov    rdx,rsp
  400699:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
  40069d:	50                   	push   rax
  40069e:	54                   	push   rsp
  40069f:	49 c7 c0 c0 08 40 00 	mov    r8,0x4008c0
  4006a6:	48 c7 c1 50 08 40 00 	mov    rcx,0x400850
  4006ad:	48 c7 c7 86 07 40 00 	mov    rdi,0x400786
  4006b4:	e8 97 ff ff ff       	call   400650 <__libc_start_main@plt>
  4006b9:	f4                   	hlt    
  4006ba:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

00000000004006c0 <deregister_tm_clones>:
  4006c0:	b8 67 10 60 00       	mov    eax,0x601067
  4006c5:	55                   	push   rbp
  4006c6:	48 2d 60 10 60 00    	sub    rax,0x601060
  4006cc:	48 83 f8 0e          	cmp    rax,0xe
  4006d0:	48 89 e5             	mov    rbp,rsp
  4006d3:	76 1b                	jbe    4006f0 <deregister_tm_clones+0x30>
  4006d5:	b8 00 00 00 00       	mov    eax,0x0
  4006da:	48 85 c0             	test   rax,rax
  4006dd:	74 11                	je     4006f0 <deregister_tm_clones+0x30>
  4006df:	5d                   	pop    rbp
  4006e0:	bf 60 10 60 00       	mov    edi,0x601060
  4006e5:	ff e0                	jmp    rax
  4006e7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
  4006ee:	00 00 
  4006f0:	5d                   	pop    rbp
  4006f1:	c3                   	ret    
  4006f2:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  4006f6:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  4006fd:	00 00 00 

0000000000400700 <register_tm_clones>:
  400700:	be 60 10 60 00       	mov    esi,0x601060
  400705:	55                   	push   rbp
  400706:	48 81 ee 60 10 60 00 	sub    rsi,0x601060
  40070d:	48 c1 fe 03          	sar    rsi,0x3
  400711:	48 89 e5             	mov    rbp,rsp
  400714:	48 89 f0             	mov    rax,rsi
  400717:	48 c1 e8 3f          	shr    rax,0x3f
  40071b:	48 01 c6             	add    rsi,rax
  40071e:	48 d1 fe             	sar    rsi,1
  400721:	74 15                	je     400738 <register_tm_clones+0x38>
  400723:	b8 00 00 00 00       	mov    eax,0x0
  400728:	48 85 c0             	test   rax,rax
  40072b:	74 0b                	je     400738 <register_tm_clones+0x38>
  40072d:	5d                   	pop    rbp
  40072e:	bf 60 10 60 00       	mov    edi,0x601060
  400733:	ff e0                	jmp    rax
  400735:	0f 1f 00             	nop    DWORD PTR [rax]
  400738:	5d                   	pop    rbp
  400739:	c3                   	ret    
  40073a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000400740 <__do_global_dtors_aux>:
  400740:	80 3d 19 09 20 00 00 	cmp    BYTE PTR [rip+0x200919],0x0        # 601060 <__TMC_END__>
  400747:	75 11                	jne    40075a <__do_global_dtors_aux+0x1a>
  400749:	55                   	push   rbp
  40074a:	48 89 e5             	mov    rbp,rsp
  40074d:	e8 6e ff ff ff       	call   4006c0 <deregister_tm_clones>
  400752:	5d                   	pop    rbp
  400753:	c6 05 06 09 20 00 01 	mov    BYTE PTR [rip+0x200906],0x1        # 601060 <__TMC_END__>
  40075a:	f3 c3                	repz ret 
  40075c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000400760 <frame_dummy>:
  400760:	bf 10 0e 60 00       	mov    edi,0x600e10
  400765:	48 83 3f 00          	cmp    QWORD PTR [rdi],0x0
  400769:	75 05                	jne    400770 <frame_dummy+0x10>
  40076b:	eb 93                	jmp    400700 <register_tm_clones>
  40076d:	0f 1f 00             	nop    DWORD PTR [rax]
  400770:	b8 00 00 00 00       	mov    eax,0x0
  400775:	48 85 c0             	test   rax,rax
  400778:	74 f1                	je     40076b <frame_dummy+0xb>
  40077a:	55                   	push   rbp
  40077b:	48 89 e5             	mov    rbp,rsp
  40077e:	ff d0                	call   rax
  400780:	5d                   	pop    rbp
  400781:	e9 7a ff ff ff       	jmp    400700 <register_tm_clones>

0000000000400786 <main>:
  400786:	55                   	push   rbp
  400787:	48 89 e5             	mov    rbp,rsp
  40078a:	48 83 ec 10          	sub    rsp,0x10
  40078e:	bf d4 08 40 00       	mov    edi,0x4008d4
  400793:	b8 00 00 00 00       	mov    eax,0x0
  400798:	e8 93 fe ff ff       	call   400630 <printf@plt>
  40079d:	48 8d 55 f8          	lea    rdx,[rbp-0x8]
  4007a1:	48 8d 45 fc          	lea    rax,[rbp-0x4]
  4007a5:	48 89 c6             	mov    rsi,rax
  4007a8:	bf e8 08 40 00       	mov    edi,0x4008e8
  4007ad:	b8 00 00 00 00       	mov    eax,0x0
  4007b2:	e8 a9 fe ff ff       	call   400660 <__isoc99_scanf@plt>
  4007b7:	8b 55 f8             	mov    edx,DWORD PTR [rbp-0x8]
  4007ba:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  4007bd:	89 d6                	mov    esi,edx
  4007bf:	89 c7                	mov    edi,eax
  4007c1:	e8 5a fe ff ff       	call   400620 <add_num@plt>
  4007c6:	89 c6                	mov    esi,eax
  4007c8:	bf ee 08 40 00       	mov    edi,0x4008ee
  4007cd:	b8 00 00 00 00       	mov    eax,0x0
  4007d2:	e8 59 fe ff ff       	call   400630 <printf@plt>
  4007d7:	8b 55 f8             	mov    edx,DWORD PTR [rbp-0x8]
  4007da:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  4007dd:	89 d6                	mov    esi,edx
  4007df:	89 c7                	mov    edi,eax
  4007e1:	e8 2a fe ff ff       	call   400610 <sub_num@plt>
  4007e6:	89 c6                	mov    esi,eax
  4007e8:	bf fb 08 40 00       	mov    edi,0x4008fb
  4007ed:	b8 00 00 00 00       	mov    eax,0x0
  4007f2:	e8 39 fe ff ff       	call   400630 <printf@plt>
  4007f7:	8b 55 f8             	mov    edx,DWORD PTR [rbp-0x8]
  4007fa:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  4007fd:	89 d6                	mov    esi,edx
  4007ff:	89 c7                	mov    edi,eax
  400801:	e8 3a fe ff ff       	call   400640 <mul_num@plt>
  400806:	89 c6                	mov    esi,eax
  400808:	bf 0b 09 40 00       	mov    edi,0x40090b
  40080d:	b8 00 00 00 00       	mov    eax,0x0
  400812:	e8 19 fe ff ff       	call   400630 <printf@plt>
  400817:	8b 45 f8             	mov    eax,DWORD PTR [rbp-0x8]
  40081a:	66 0f ef c9          	pxor   xmm1,xmm1
  40081e:	f3 0f 2a c8          	cvtsi2ss xmm1,eax
  400822:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  400825:	66 0f ef c0          	pxor   xmm0,xmm0
  400829:	f3 0f 2a c0          	cvtsi2ss xmm0,eax
  40082d:	e8 3e fe ff ff       	call   400670 <div_num@plt>
  400832:	f3 0f 5a c0          	cvtss2sd xmm0,xmm0
  400836:	bf 1e 09 40 00       	mov    edi,0x40091e
  40083b:	b8 01 00 00 00       	mov    eax,0x1
  400840:	e8 eb fd ff ff       	call   400630 <printf@plt>
  400845:	b8 00 00 00 00       	mov    eax,0x0
  40084a:	c9                   	leave  
  40084b:	c3                   	ret    
  40084c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000400850 <__libc_csu_init>:
  400850:	41 57                	push   r15
  400852:	41 56                	push   r14
  400854:	41 89 ff             	mov    r15d,edi
  400857:	41 55                	push   r13
  400859:	41 54                	push   r12
  40085b:	4c 8d 25 9e 05 20 00 	lea    r12,[rip+0x20059e]        # 600e00 <__frame_dummy_init_array_entry>
  400862:	55                   	push   rbp
  400863:	48 8d 2d 9e 05 20 00 	lea    rbp,[rip+0x20059e]        # 600e08 <__init_array_end>
  40086a:	53                   	push   rbx
  40086b:	49 89 f6             	mov    r14,rsi
  40086e:	49 89 d5             	mov    r13,rdx
  400871:	4c 29 e5             	sub    rbp,r12
  400874:	48 83 ec 08          	sub    rsp,0x8
  400878:	48 c1 fd 03          	sar    rbp,0x3
  40087c:	e8 57 fd ff ff       	call   4005d8 <_init>
  400881:	48 85 ed             	test   rbp,rbp
  400884:	74 20                	je     4008a6 <__libc_csu_init+0x56>
  400886:	31 db                	xor    ebx,ebx
  400888:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
  40088f:	00 
  400890:	4c 89 ea             	mov    rdx,r13
  400893:	4c 89 f6             	mov    rsi,r14
  400896:	44 89 ff             	mov    edi,r15d
  400899:	41 ff 14 dc          	call   QWORD PTR [r12+rbx*8]
  40089d:	48 83 c3 01          	add    rbx,0x1
  4008a1:	48 39 eb             	cmp    rbx,rbp
  4008a4:	75 ea                	jne    400890 <__libc_csu_init+0x40>
  4008a6:	48 83 c4 08          	add    rsp,0x8
  4008aa:	5b                   	pop    rbx
  4008ab:	5d                   	pop    rbp
  4008ac:	41 5c                	pop    r12
  4008ae:	41 5d                	pop    r13
  4008b0:	41 5e                	pop    r14
  4008b2:	41 5f                	pop    r15
  4008b4:	c3                   	ret    
  4008b5:	90                   	nop
  4008b6:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  4008bd:	00 00 00 

00000000004008c0 <__libc_csu_fini>:
  4008c0:	f3 c3                	repz ret 

Disassembly of section .fini:

00000000004008c4 <_fini>:
  4008c4:	48 83 ec 08          	sub    rsp,0x8
  4008c8:	48 83 c4 08          	add    rsp,0x8
  4008cc:	c3                   	ret    

Disassembly of section .rodata:

00000000004008d0 <_IO_stdin_used>:
  4008d0:	01 00                	add    DWORD PTR [rax],eax
  4008d2:	02 00                	add    al,BYTE PTR [rax]
  4008d4:	45 6e                	rex.RB outs dx,BYTE PTR ds:[rsi]
  4008d6:	74 65                	je     40093d <__GNU_EH_FRAME_HDR+0xd>
  4008d8:	72 20                	jb     4008fa <_IO_stdin_used+0x2a>
  4008da:	74 77                	je     400953 <__GNU_EH_FRAME_HDR+0x23>
  4008dc:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  4008dd:	20 6e 75             	and    BYTE PTR [rsi+0x75],ch
  4008e0:	6d                   	ins    DWORD PTR es:[rdi],dx
  4008e1:	62                   	(bad)  
  4008e2:	65 72 20             	gs jb  400905 <_IO_stdin_used+0x35>
  4008e5:	3a 20                	cmp    ah,BYTE PTR [rax]
  4008e7:	00 25 64 20 25 64    	add    BYTE PTR [rip+0x64252064],ah        # 64652951 <_end+0x640518e9>
  4008ed:	00 41 64             	add    BYTE PTR [rcx+0x64],al
  4008f0:	64 69 74 69 6f 6e 09 	imul   esi,DWORD PTR fs:[rcx+rbp*2+0x6f],0x6425096e
  4008f7:	25 64 
  4008f9:	0a 00                	or     al,BYTE PTR [rax]
  4008fb:	53                   	push   rbx
  4008fc:	75 62                	jne    400960 <__GNU_EH_FRAME_HDR+0x30>
  4008fe:	74 72                	je     400972 <__GNU_EH_FRAME_HDR+0x42>
  400900:	61                   	(bad)  
  400901:	63 74 69 6f          	movsxd esi,DWORD PTR [rcx+rbp*2+0x6f]
  400905:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  400906:	09 25 64 0a 00 4d    	or     DWORD PTR [rip+0x4d000a64],esp        # 4d401370 <_end+0x4ce00308>
  40090c:	75 6c                	jne    40097a <__GNU_EH_FRAME_HDR+0x4a>
  40090e:	74 69                	je     400979 <__GNU_EH_FRAME_HDR+0x49>
  400910:	70 6c                	jo     40097e <__GNU_EH_FRAME_HDR+0x4e>
  400912:	69 63 61 74 69 6f 6e 	imul   esp,DWORD PTR [rbx+0x61],0x6e6f6974
  400919:	09 25 64 0a 00 44    	or     DWORD PTR [rip+0x44000a64],esp        # 44401383 <_end+0x43e0031b>
  40091f:	69 76 69 73 69 6f 6e 	imul   esi,DWORD PTR [rsi+0x69],0x6e6f6973
  400926:	09 25 2e 35 66 0a    	or     DWORD PTR [rip+0xa66352e],esp        # aa63e5a <_end+0xa462df2>
	...

Disassembly of section .eh_frame_hdr:

0000000000400930 <__GNU_EH_FRAME_HDR>:
  400930:	01 1b                	add    DWORD PTR [rbx],ebx
  400932:	03 3b                	add    edi,DWORD PTR [rbx]
  400934:	34 00                	xor    al,0x0
  400936:	00 00                	add    BYTE PTR [rax],al
  400938:	05 00 00 00 d0       	add    eax,0xd0000000
  40093d:	fc                   	cld    
  40093e:	ff                   	(bad)  
  40093f:	ff 80 00 00 00 60    	inc    DWORD PTR [rax+0x60000000]
  400945:	fd                   	std    
  400946:	ff                   	(bad)  
  400947:	ff 50 00             	call   QWORD PTR [rax+0x0]
  40094a:	00 00                	add    BYTE PTR [rax],al
  40094c:	56                   	push   rsi
  40094d:	fe                   	(bad)  
  40094e:	ff                   	(bad)  
  40094f:	ff a8 00 00 00 20    	jmp    FWORD PTR [rax+0x20000000]
  400955:	ff                   	(bad)  
  400956:	ff                   	(bad)  
  400957:	ff c8                	dec    eax
  400959:	00 00                	add    BYTE PTR [rax],al
  40095b:	00 90 ff ff ff 10    	add    BYTE PTR [rax+0x10ffffff],dl
  400961:	01 00                	add    DWORD PTR [rax],eax
	...

Disassembly of section .eh_frame:

0000000000400968 <__FRAME_END__-0xf0>:
  400968:	14 00                	adc    al,0x0
  40096a:	00 00                	add    BYTE PTR [rax],al
  40096c:	00 00                	add    BYTE PTR [rax],al
  40096e:	00 00                	add    BYTE PTR [rax],al
  400970:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  400973:	00 01                	add    BYTE PTR [rcx],al
  400975:	78 10                	js     400987 <__GNU_EH_FRAME_HDR+0x57>
  400977:	01 1b                	add    DWORD PTR [rbx],ebx
  400979:	0c 07                	or     al,0x7
  40097b:	08 90 01 07 10 14    	or     BYTE PTR [rax+0x14100701],dl
  400981:	00 00                	add    BYTE PTR [rax],al
  400983:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  400986:	00 00                	add    BYTE PTR [rax],al
  400988:	08 fd                	or     ch,bh
  40098a:	ff                   	(bad)  
  40098b:	ff 2a                	jmp    FWORD PTR [rdx]
	...
  400995:	00 00                	add    BYTE PTR [rax],al
  400997:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
  40099a:	00 00                	add    BYTE PTR [rax],al
  40099c:	00 00                	add    BYTE PTR [rax],al
  40099e:	00 00                	add    BYTE PTR [rax],al
  4009a0:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
  4009a3:	00 01                	add    BYTE PTR [rcx],al
  4009a5:	78 10                	js     4009b7 <__GNU_EH_FRAME_HDR+0x87>
  4009a7:	01 1b                	add    DWORD PTR [rbx],ebx
  4009a9:	0c 07                	or     al,0x7
  4009ab:	08 90 01 00 00 24    	or     BYTE PTR [rax+0x24000001],dl
  4009b1:	00 00                	add    BYTE PTR [rax],al
  4009b3:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  4009b6:	00 00                	add    BYTE PTR [rax],al
  4009b8:	48 fc                	rex.W cld 
  4009ba:	ff                   	(bad)  
  4009bb:	ff 80 00 00 00 00    	inc    DWORD PTR [rax+0x0]
  4009c1:	0e                   	(bad)  
  4009c2:	10 46 0e             	adc    BYTE PTR [rsi+0xe],al
  4009c5:	18 4a 0f             	sbb    BYTE PTR [rdx+0xf],cl
  4009c8:	0b 77 08             	or     esi,DWORD PTR [rdi+0x8]
  4009cb:	80 00 3f             	add    BYTE PTR [rax],0x3f
  4009ce:	1a 3b                	sbb    bh,BYTE PTR [rbx]
  4009d0:	2a 33                	sub    dh,BYTE PTR [rbx]
  4009d2:	24 22                	and    al,0x22
  4009d4:	00 00                	add    BYTE PTR [rax],al
  4009d6:	00 00                	add    BYTE PTR [rax],al
  4009d8:	1c 00                	sbb    al,0x0
  4009da:	00 00                	add    BYTE PTR [rax],al
  4009dc:	44 00 00             	add    BYTE PTR [rax],r8b
  4009df:	00 a6 fd ff ff c6    	add    BYTE PTR [rsi-0x39000003],ah
  4009e5:	00 00                	add    BYTE PTR [rax],al
  4009e7:	00 00                	add    BYTE PTR [rax],al
  4009e9:	41 0e                	rex.B (bad) 
  4009eb:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  4009f1:	02 c1                	add    al,cl
  4009f3:	0c 07                	or     al,0x7
  4009f5:	08 00                	or     BYTE PTR [rax],al
  4009f7:	00 44 00 00          	add    BYTE PTR [rax+rax*1+0x0],al
  4009fb:	00 64 00 00          	add    BYTE PTR [rax+rax*1+0x0],ah
  4009ff:	00 50 fe             	add    BYTE PTR [rax-0x2],dl
  400a02:	ff                   	(bad)  
  400a03:	ff 65 00             	jmp    QWORD PTR [rbp+0x0]
  400a06:	00 00                	add    BYTE PTR [rax],al
  400a08:	00 42 0e             	add    BYTE PTR [rdx+0xe],al
  400a0b:	10 8f 02 42 0e 18    	adc    BYTE PTR [rdi+0x180e4202],cl
  400a11:	8e 03                	mov    es,WORD PTR [rbx]
  400a13:	45 0e                	rex.RB (bad) 
  400a15:	20 8d 04 42 0e 28    	and    BYTE PTR [rbp+0x280e4204],cl
  400a1b:	8c 05 48 0e 30 86    	mov    WORD PTR [rip+0xffffffff86300e48],es        # ffffffff86701869 <_end+0xffffffff86100801>
  400a21:	06                   	(bad)  
  400a22:	48 0e                	rex.W (bad) 
  400a24:	38 83 07 4d 0e 40    	cmp    BYTE PTR [rbx+0x400e4d07],al
  400a2a:	72 0e                	jb     400a3a <__GNU_EH_FRAME_HDR+0x10a>
  400a2c:	38 41 0e             	cmp    BYTE PTR [rcx+0xe],al
  400a2f:	30 41 0e             	xor    BYTE PTR [rcx+0xe],al
  400a32:	28 42 0e             	sub    BYTE PTR [rdx+0xe],al
  400a35:	20 42 0e             	and    BYTE PTR [rdx+0xe],al
  400a38:	18 42 0e             	sbb    BYTE PTR [rdx+0xe],al
  400a3b:	10 42 0e             	adc    BYTE PTR [rdx+0xe],al
  400a3e:	08 00                	or     BYTE PTR [rax],al
  400a40:	14 00                	adc    al,0x0
  400a42:	00 00                	add    BYTE PTR [rax],al
  400a44:	ac                   	lods   al,BYTE PTR ds:[rsi]
  400a45:	00 00                	add    BYTE PTR [rax],al
  400a47:	00 78 fe             	add    BYTE PTR [rax-0x2],bh
  400a4a:	ff                   	(bad)  
  400a4b:	ff 02                	inc    DWORD PTR [rdx]
	...

0000000000400a58 <__FRAME_END__>:
  400a58:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .init_array:

0000000000600e00 <__frame_dummy_init_array_entry>:
  600e00:	60                   	(bad)  
  600e01:	07                   	(bad)  
  600e02:	40 00 00             	add    BYTE PTR [rax],al
  600e05:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .fini_array:

0000000000600e08 <__do_global_dtors_aux_fini_array_entry>:
  600e08:	40 07                	rex (bad) 
  600e0a:	40 00 00             	add    BYTE PTR [rax],al
  600e0d:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .jcr:

0000000000600e10 <__JCR_END__>:
	...

Disassembly of section .dynamic:

0000000000600e18 <_DYNAMIC>:
  600e18:	01 00                	add    DWORD PTR [rax],eax
  600e1a:	00 00                	add    BYTE PTR [rax],al
  600e1c:	00 00                	add    BYTE PTR [rax],al
  600e1e:	00 00                	add    BYTE PTR [rax],al
  600e20:	01 00                	add    DWORD PTR [rax],eax
  600e22:	00 00                	add    BYTE PTR [rax],al
  600e24:	00 00                	add    BYTE PTR [rax],al
  600e26:	00 00                	add    BYTE PTR [rax],al
  600e28:	01 00                	add    DWORD PTR [rax],eax
  600e2a:	00 00                	add    BYTE PTR [rax],al
  600e2c:	00 00                	add    BYTE PTR [rax],al
  600e2e:	00 00                	add    BYTE PTR [rax],al
  600e30:	47 00 00             	rex.RXB add BYTE PTR [r8],r8b
  600e33:	00 00                	add    BYTE PTR [rax],al
  600e35:	00 00                	add    BYTE PTR [rax],al
  600e37:	00 0c 00             	add    BYTE PTR [rax+rax*1],cl
  600e3a:	00 00                	add    BYTE PTR [rax],al
  600e3c:	00 00                	add    BYTE PTR [rax],al
  600e3e:	00 00                	add    BYTE PTR [rax],al
  600e40:	d8 05 40 00 00 00    	fadd   DWORD PTR [rip+0x40]        # 600e86 <_DYNAMIC+0x6e>
  600e46:	00 00                	add    BYTE PTR [rax],al
  600e48:	0d 00 00 00 00       	or     eax,0x0
  600e4d:	00 00                	add    BYTE PTR [rax],al
  600e4f:	00 c4                	add    ah,al
  600e51:	08 40 00             	or     BYTE PTR [rax+0x0],al
  600e54:	00 00                	add    BYTE PTR [rax],al
  600e56:	00 00                	add    BYTE PTR [rax],al
  600e58:	19 00                	sbb    DWORD PTR [rax],eax
  600e5a:	00 00                	add    BYTE PTR [rax],al
  600e5c:	00 00                	add    BYTE PTR [rax],al
  600e5e:	00 00                	add    BYTE PTR [rax],al
  600e60:	00 0e                	add    BYTE PTR [rsi],cl
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
  600e7f:	00 08                	add    BYTE PTR [rax],cl
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
  600ea7:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 600ead <_DYNAMIC+0x95>
  600ead:	00 00                	add    BYTE PTR [rax],al
  600eaf:	00 20                	add    BYTE PTR [rax],ah
  600eb1:	04 40                	add    al,0x40
  600eb3:	00 00                	add    BYTE PTR [rax],al
  600eb5:	00 00                	add    BYTE PTR [rax],al
  600eb7:	00 06                	add    BYTE PTR [rsi],al
  600eb9:	00 00                	add    BYTE PTR [rax],al
  600ebb:	00 00                	add    BYTE PTR [rax],al
  600ebd:	00 00                	add    BYTE PTR [rax],al
  600ebf:	00 d0                	add    al,dl
  600ec1:	02 40 00             	add    al,BYTE PTR [rax+0x0]
  600ec4:	00 00                	add    BYTE PTR [rax],al
  600ec6:	00 00                	add    BYTE PTR [rax],al
  600ec8:	0a 00                	or     al,BYTE PTR [rax]
  600eca:	00 00                	add    BYTE PTR [rax],al
  600ecc:	00 00                	add    BYTE PTR [rax],al
  600ece:	00 00                	add    BYTE PTR [rax],al
  600ed0:	a7                   	cmps   DWORD PTR ds:[rsi],DWORD PTR es:[rdi]
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
  600ee7:	00 15 00 00 00 00    	add    BYTE PTR [rip+0x0],dl        # 600eed <_DYNAMIC+0xd5>
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
  600f10:	a8 00                	test   al,0x0
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
  600f2f:	00 30                	add    BYTE PTR [rax],dh
  600f31:	05 40 00 00 00       	add    eax,0x40
  600f36:	00 00                	add    BYTE PTR [rax],al
  600f38:	07                   	(bad)  
  600f39:	00 00                	add    BYTE PTR [rax],al
  600f3b:	00 00                	add    BYTE PTR [rax],al
  600f3d:	00 00                	add    BYTE PTR [rax],al
  600f3f:	00 18                	add    BYTE PTR [rax],bl
  600f41:	05 40 00 00 00       	add    eax,0x40
  600f46:	00 00                	add    BYTE PTR [rax],al
  600f48:	08 00                	or     BYTE PTR [rax],al
  600f4a:	00 00                	add    BYTE PTR [rax],al
  600f4c:	00 00                	add    BYTE PTR [rax],al
  600f4e:	00 00                	add    BYTE PTR [rax],al
  600f50:	18 00                	sbb    BYTE PTR [rax],al
  600f52:	00 00                	add    BYTE PTR [rax],al
  600f54:	00 00                	add    BYTE PTR [rax],al
  600f56:	00 00                	add    BYTE PTR [rax],al
  600f58:	09 00                	or     DWORD PTR [rax],eax
  600f5a:	00 00                	add    BYTE PTR [rax],al
  600f5c:	00 00                	add    BYTE PTR [rax],al
  600f5e:	00 00                	add    BYTE PTR [rax],al
  600f60:	18 00                	sbb    BYTE PTR [rax],al
  600f62:	00 00                	add    BYTE PTR [rax],al
  600f64:	00 00                	add    BYTE PTR [rax],al
  600f66:	00 00                	add    BYTE PTR [rax],al
  600f68:	fe                   	(bad)  
  600f69:	ff                   	(bad)  
  600f6a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
  600f6d:	00 00                	add    BYTE PTR [rax],al
  600f6f:	00 e8                	add    al,ch
  600f71:	04 40                	add    al,0x40
  600f73:	00 00                	add    BYTE PTR [rax],al
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
  600f8f:	00 c8                	add    al,cl
  600f91:	04 40                	add    al,0x40
	...

Disassembly of section .got:

0000000000600ff8 <.got>:
	...

Disassembly of section .got.plt:

0000000000601000 <_GLOBAL_OFFSET_TABLE_>:
  601000:	18 0e                	sbb    BYTE PTR [rsi],cl
  601002:	60                   	(bad)  
	...
  601017:	00 16                	add    BYTE PTR [rsi],dl
  601019:	06                   	(bad)  
  60101a:	40 00 00             	add    BYTE PTR [rax],al
  60101d:	00 00                	add    BYTE PTR [rax],al
  60101f:	00 26                	add    BYTE PTR [rsi],ah
  601021:	06                   	(bad)  
  601022:	40 00 00             	add    BYTE PTR [rax],al
  601025:	00 00                	add    BYTE PTR [rax],al
  601027:	00 36                	add    BYTE PTR [rsi],dh
  601029:	06                   	(bad)  
  60102a:	40 00 00             	add    BYTE PTR [rax],al
  60102d:	00 00                	add    BYTE PTR [rax],al
  60102f:	00 46 06             	add    BYTE PTR [rsi+0x6],al
  601032:	40 00 00             	add    BYTE PTR [rax],al
  601035:	00 00                	add    BYTE PTR [rax],al
  601037:	00 56 06             	add    BYTE PTR [rsi+0x6],dl
  60103a:	40 00 00             	add    BYTE PTR [rax],al
  60103d:	00 00                	add    BYTE PTR [rax],al
  60103f:	00 66 06             	add    BYTE PTR [rsi+0x6],ah
  601042:	40 00 00             	add    BYTE PTR [rax],al
  601045:	00 00                	add    BYTE PTR [rax],al
  601047:	00 76 06             	add    BYTE PTR [rsi+0x6],dh
  60104a:	40 00 00             	add    BYTE PTR [rax],al
  60104d:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .data:

0000000000601050 <__data_start>:
	...

0000000000601058 <__dso_handle>:
	...

Disassembly of section .bss:

0000000000601060 <__bss_start>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
   5:	28 44 65 62          	sub    BYTE PTR [rbp+riz*2+0x62],al
   9:	69 61 6e 20 36 2e 31 	imul   esp,DWORD PTR [rcx+0x6e],0x312e3620
  10:	2e 31 2d 31 31 29 20 	xor    DWORD PTR cs:[rip+0x20293131],ebp        # 20293148 <_end+0x1fc920e0>
  17:	36 2e 31 2e          	ss xor DWORD PTR cs:[rsi],ebp
  1b:	31 20                	xor    DWORD PTR [rax],esp
  1d:	32 30                	xor    dh,BYTE PTR [rax]
  1f:	31 36                	xor    DWORD PTR [rsi],esi
  21:	30 38                	xor    BYTE PTR [rax],bh
  23:	30 32                	xor    BYTE PTR [rdx],dh
	...
