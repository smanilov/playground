Dump of assembler code for function vbo_exec_vtx_flush:
=> 0x00007ffff4b40ae0 <+0>:	push   r15
   0x00007ffff4b40ae2 <+2>:	push   r14
   0x00007ffff4b40ae4 <+4>:	push   r13
   0x00007ffff4b40ae6 <+6>:	mov    r13,rdi                                  ; arg1 is vbo_exec_context
   0x00007ffff4b40ae9 <+9>:	push   r12
   0x00007ffff4b40aeb <+11>:	push   rbp
   0x00007ffff4b40aec <+12>:	mov    ebp,esi                                  ; arg2 is GLboolean
   0x00007ffff4b40aee <+14>:	push   rbx
   0x00007ffff4b40aef <+15>:	sub    rsp,0x48

   0x00007ffff4b40af3 <+19>:	mov    eax,DWORD PTR [rdi+0xe9c]                ; vtx.prim_count == 0?
   0x00007ffff4b40af9 <+25>:	test   eax,eax
   0x00007ffff4b40afb <+27>:	je     L1

   0x00007ffff4b40afd <+29>:	mov    r10d,DWORD PTR [rdi+0x1184]              ; vtx.vert_cout != 0?
   0x00007ffff4b40b04 <+36>:	test   r10d,r10d
   0x00007ffff4b40b07 <+39>:	jne    L2

L1:0x00007ffff4b40b0d <+45>:	test   bpl,bpl                                  ; keepUnmapped != 0?
   0x00007ffff4b40b10 <+48>:	jne    L3

   0x00007ffff4b40b12 <+50>:	mov    ecx,DWORD PTR [r13+0x898]                ; vtx.vertex_size == 0?
   0x00007ffff4b40b19 <+57>:	test   ecx,ecx
   0x00007ffff4b40b1b <+59>:	je     L4

L6:0x00007ffff4b40b1d <+61>:	mov    eax,0x10000
   0x00007ffff4b40b22 <+66>:	sub    eax,DWORD PTR [r13+0xeb0]
   0x00007ffff4b40b29 <+73>:	shl    rcx,0x2
   0x00007ffff4b40b2d <+77>:	xor    edx,edx
   0x00007ffff4b40b2f <+79>:	div    rcx
   0x00007ffff4b40b32 <+82>:	mov    DWORD PTR [r13+0x1188],eax
   0x00007ffff4b40b39 <+89>:	mov    rax,QWORD PTR [r13+0xea0]
   0x00007ffff4b40b40 <+96>:	jmp    L5

        0x00007ffff4b40b42 <+98>:	nop    WORD PTR [rax+rax*1+0x0]

L3:0x00007ffff4b40b48 <+104>:	mov    rax,QWORD PTR [r13+0x890]                ; ? == 0?
   0x00007ffff4b40b4f <+111>:	test   rax,rax
   0x00007ffff4b40b52 <+114>:	je     L4

L7:0x00007ffff4b40b54 <+116>:	mov    ecx,DWORD PTR [rax+0x2c]                 ; vtx.buffer_map != 0?
   0x00007ffff4b40b57 <+119>:	test   ecx,ecx
   0x00007ffff4b40b59 <+121>:	jne    L8

L4:0x00007ffff4b40b5b <+123>:	mov    rax,QWORD PTR [r13+0xea0]
L9:0x00007ffff4b40b62 <+130>:	mov    DWORD PTR [r13+0x1188],0x0               ; vtx.max_vert = 0

L5:0x00007ffff4b40b6d <+141>:	mov    QWORD PTR [r13+0xea8],rax
   0x00007ffff4b40b74 <+148>:	mov    DWORD PTR [r13+0xe9c],0x0
   0x00007ffff4b40b7f <+159>:	mov    DWORD PTR [r13+0x1184],0x0
   0x00007ffff4b40b8a <+170>:	add    rsp,0x48
   0x00007ffff4b40b8e <+174>:	pop    rbx
   0x00007ffff4b40b8f <+175>:	pop    rbp
   0x00007ffff4b40b90 <+176>:	pop    r12
   0x00007ffff4b40b92 <+178>:	pop    r13
   0x00007ffff4b40b94 <+180>:	pop    r14
   0x00007ffff4b40b96 <+182>:	pop    r15
   0x00007ffff4b40b98 <+184>:	ret    
END



           0x00007ffff4b40b99 <+185>:	nop    DWORD PTR [rax+0x0]

L8:0x00007ffff4b40ba0 <+192>:	xor    eax,eax                                  ; 
   0x00007ffff4b40ba2 <+194>:	cmp    QWORD PTR [r13+0xea0],0x0
   0x00007ffff4b40baa <+202>:	je     L9

   0x00007ffff4b40bac <+204>:	mov    rdi,r13
   0x00007ffff4b40baf <+207>:	call   0x7ffff4b40860
   0x00007ffff4b40bb4 <+212>:	mov    rax,QWORD PTR [r13+0xea0]
   0x00007ffff4b40bbb <+219>:	jmp    L9 

        0x00007ffff4b40bbd <+221>:	nop    DWORD PTR [rax]



   
L2:0x00007ffff4b40bc0 <+224>:	sub    eax,0x1
   0x00007ffff4b40bc3 <+227>:	mov    ebx,DWORD PTR [rdi+0x898]
   0x00007ffff4b40bc9 <+233>:	lea    rdx,[rax+rax*2]
   0x00007ffff4b40bcd <+237>:	lea    rdx,[rdi+rdx*8+0x890]
   0x00007ffff4b40bd5 <+245>:	mov    esi,ebx
   0x00007ffff4b40bd7 <+247>:	lea    rdi,[rdi+0x118c]
   0x00007ffff4b40bde <+254>:	imul   esi,DWORD PTR [rdx+0x10]
   0x00007ffff4b40be2 <+258>:	mov    ecx,DWORD PTR [rdx+0x14]
   0x00007ffff4b40be5 <+261>:	mov    rdx,QWORD PTR [r13+0xea0]
   0x00007ffff4b40bec <+268>:	lea    r12,[rdx+rsi*4]
   0x00007ffff4b40bf0 <+272>:	mov    rdx,QWORD PTR [r13+0x0]
   0x00007ffff4b40bf4 <+276>:	cmp    DWORD PTR [rdx+0x4e0],0x9
   0x00007ffff4b40bfb <+283>:	mov    QWORD PTR [rsp+0x28],rdx
   0x00007ffff4b40c00 <+288>:	jbe    0x7ffff4b40e60 <vbo_exec_vtx_flush+896>

   0x00007ffff4b40c06 <+294>:	mov    DWORD PTR [r13+0x19fc],0x0
   0x00007ffff4b40c11 <+305>:	mov    rdi,QWORD PTR [rsp+0x28]
   0x00007ffff4b40c16 <+310>:	xor    edx,edx
   0x00007ffff4b40c18 <+312>:	mov    r15,QWORD PTR [rdi+0xd8b8]
   0x00007ffff4b40c1f <+319>:	mov    rcx,QWORD PTR [r15+0xc48]
   0x00007ffff4b40c26 <+326>:	mov    eax,DWORD PTR [r15+0x1dcc]
   0x00007ffff4b40c2d <+333>:	mov    rsi,QWORD PTR [rcx+0x95b0]
   0x00007ffff4b40c34 <+340>:	mov    DWORD PTR [rsp+0x30],eax
   0x00007ffff4b40c38 <+344>:	lea    rax,[r15+0xc48]
   0x00007ffff4b40c3f <+351>:	test   rsi,rsi
   0x00007ffff4b40c42 <+354>:	je     loop2

   0x00007ffff4b40c48 <+360>:	cmp    rsi,QWORD PTR [rcx+0xa5c0]
   0x00007ffff4b40c4f <+367>:	je     loop2

   0x00007ffff4b40c55 <+373>:	nop    DWORD PTR [rax]
   0x00007ffff4b40c58 <+376>:	mov    ecx,edx
   0x00007ffff4b40c5a <+378>:	shl    rcx,0x6
   0x00007ffff4b40c5e <+382>:	add    rcx,r15
   0x00007ffff4b40c61 <+385>:	mov    QWORD PTR [rax+rdx*8+0x24c0],rcx
   0x00007ffff4b40c69 <+393>:	add    rdx,0x1
   0x00007ffff4b40c6d <+397>:	cmp    rdx,0x11
   0x00007ffff4b40c71 <+401>:	jne    0x7ffff4b40c58 <vbo_exec_vtx_flush+376>
   0x00007ffff4b40c73 <+403>:	xor    dl,dl
   0x00007ffff4b40c75 <+405>:	nop    DWORD PTR [rax]
   0x00007ffff4b40c78 <+408>:	lea    ecx,[rdx+0x11]
   0x00007ffff4b40c7b <+411>:	shl    rcx,0x6
   0x00007ffff4b40c7f <+415>:	add    rcx,r15
   0x00007ffff4b40c82 <+418>:	mov    QWORD PTR [rax+rdx*8+0x2548],rcx
   0x00007ffff4b40c8a <+426>:	add    rdx,0x1
   0x00007ffff4b40c8e <+430>:	cmp    rdx,0x10
   0x00007ffff4b40c92 <+434>:	jne    0x7ffff4b40c78 <vbo_exec_vtx_flush+408>
   0x00007ffff4b40c94 <+436>:	mov    rdi,QWORD PTR [rsp+0x28]
   0x00007ffff4b40c99 <+441>:	lea    r12,[r15+0xbc4]
   0x00007ffff4b40ca0 <+448>:	mov    rdx,QWORD PTR [rdi+0x95b0]
   0x00007ffff4b40ca7 <+455>:	mov    rdx,QWORD PTR [rdx+0x28]
   0x00007ffff4b40cab <+459>:	and    edx,0x20001
   0x00007ffff4b40cb1 <+465>:	cmp    rdx,0x20000
   0x00007ffff4b40cb8 <+472>:	jne    0x7ffff4b40d33 <vbo_exec_vtx_flush+595>
   0x00007ffff4b40cba <+474>:	mov    rdx,QWORD PTR [r15+0x3108]
   0x00007ffff4b40cc1 <+481>:	mov    QWORD PTR [r15+0x3190],rdx
   0x00007ffff4b40cc8 <+488>:	movzx  edx,BYTE PTR [r15+0x2648]
   0x00007ffff4b40cd0 <+496>:	mov    BYTE PTR [r15+0x2648],0x0
   0x00007ffff4b40cd8 <+504>:	mov    BYTE PTR [r15+0x2659],dl
   0x00007ffff4b40cdf <+511>:	mov    rdx,QWORD PTR [r15+0x2760]
   0x00007ffff4b40ce6 <+518>:	mov    QWORD PTR [r15+0x27e8],rdx
   0x00007ffff4b40ced <+525>:	jmp    0x7ffff4b40d33 <vbo_exec_vtx_flush+595>

           0x00007ffff4b40cef <+527>:	nop
           loop2:
           0x00007ffff4b40cf0 <+528>:	mov    ecx,edx
           0x00007ffff4b40cf2 <+530>:	shl    rcx,0x6
           0x00007ffff4b40cf6 <+534>:	add    rcx,r15
           0x00007ffff4b40cf9 <+537>:	mov    QWORD PTR [rax+rdx*8+0x24c0],rcx
           0x00007ffff4b40d01 <+545>:	add    rdx,0x1
           0x00007ffff4b40d05 <+549>:	cmp    rdx,0x11
           0x00007ffff4b40d09 <+553>:	jne    loop2
           loop2end:
           loop2exit:
           
           0x00007ffff4b40d0b <+555>:	xor    dl,dl
           0x00007ffff4b40d0d <+557>:	nop    DWORD PTR [rax]
           loop3:
           0x00007ffff4b40d10 <+560>:	lea    ecx,[rdx+0x21]
           0x00007ffff4b40d13 <+563>:	shl    rcx,0x6
           0x00007ffff4b40d17 <+567>:	add    rcx,r15
           0x00007ffff4b40d1a <+570>:	mov    QWORD PTR [rax+rdx*8+0x2548],rcx
           0x00007ffff4b40d22 <+578>:	add    rdx,0x1
           0x00007ffff4b40d26 <+582>:	cmp    rdx,0xc
           0x00007ffff4b40d2a <+586>:	jne    loop3
           loop3end:
           loop3exit:

           0x00007ffff4b40d2c <+588>:	lea    r12,[r15+0xb40]

   0x00007ffff4b40d33 <+595>:	lea    rdx,[r15+0x1afc]
   0x00007ffff4b40d3a <+602>:	xor    ecx,ecx
   0x00007ffff4b40d3c <+604>:	xor    r14d,r14d
   0x00007ffff4b40d3f <+607>:	mov    QWORD PTR [rsp+0x38],rdx
   0x00007ffff4b40d44 <+612>:	jmp    loop1start

           0x00007ffff4b40d49 <+617>:	nop    DWORD PTR [rax+0x0]
loop1:
           0x00007ffff4b40d50 <+624>:	add    rsi,QWORD PTR [rdi+0x58]
           0x00007ffff4b40d54 <+628>:	mov    QWORD PTR [rbx+0x18],rsi
           0x00007ffff4b40d58 <+632>:	movzx  esi,BYTE PTR [r15+rdx*1+0x2648]
           0x00007ffff4b40d61 <+641>:	add    rdx,0x68c
           0x00007ffff4b40d68 <+648>:	mov    DWORD PTR [rbx],esi
           0x00007ffff4b40d6a <+650>:	mov    edi,DWORD PTR [r15+0x14e0]
           0x00007ffff4b40d71 <+657>:	shl    edi,0x2
           0x00007ffff4b40d74 <+660>:	mov    DWORD PTR [rbx+0x10],edi
           0x00007ffff4b40d77 <+663>:	mov    edi,DWORD PTR [r15+0x14e0]
           0x00007ffff4b40d7e <+670>:	shl    edi,0x2
           0x00007ffff4b40d81 <+673>:	mov    DWORD PTR [rbx+0xc],edi
           0x00007ffff4b40d84 <+676>:	mov    edi,DWORD PTR [r15+rdx*4+0xc48]
           0x00007ffff4b40d8c <+684>:	mov    DWORD PTR [rbx+0x4],edi
           0x00007ffff4b40d8f <+687>:	mov    edx,DWORD PTR [r15+rdx*4+0xc48]
           0x00007ffff4b40d97 <+695>:	mov    DWORD PTR [rbx+0x8],0x1908
           0x00007ffff4b40d9e <+702>:	mov    BYTE PTR [rbx+0x20],0x1
           0x00007ffff4b40da2 <+706>:	sub    edx,0x1404
           0x00007ffff4b40da8 <+712>:	cmp    edx,0x1
           0x00007ffff4b40dab <+715>:	setbe  BYTE PTR [rbx+0x22]
           0x00007ffff4b40daf <+719>:	shl    esi,0x2
           0x00007ffff4b40db2 <+722>:	mov    DWORD PTR [rbx+0x28],esi
           0x00007ffff4b40db5 <+725>:	mov    rdx,QWORD PTR [r15+0x14d8]
           0x00007ffff4b40dbc <+732>:	lea    rsi,[rbx+0x30]
           0x00007ffff4b40dc0 <+736>:	cmp    rdx,QWORD PTR [rbx+0x30]
           0x00007ffff4b40dc4 <+740>:	je     0x7ffff4b40de4 <vbo_exec_vtx_flush+772>
           0x00007ffff4b40dc6 <+742>:	mov    rdi,QWORD PTR [rsp+0x28]
           0x00007ffff4b40dcb <+747>:	mov    QWORD PTR [rsp+0x18],rax
           0x00007ffff4b40dd0 <+752>:	mov    QWORD PTR [rsp+0x10],rcx
           0x00007ffff4b40dd5 <+757>:	call   0x7ffff4a6c5a0 <_mesa_reference_buffer_object_>
           0x00007ffff4b40dda <+762>:	mov    rcx,QWORD PTR [rsp+0x10]
           0x00007ffff4b40ddf <+767>:	mov    rax,QWORD PTR [rsp+0x18]
           0x00007ffff4b40de4 <+772>:	mov    edi,DWORD PTR [rsp+0x30]
           0x00007ffff4b40de8 <+776>:	mov    edx,0x1
           0x00007ffff4b40ded <+781>:	shl    rdx,cl
           0x00007ffff4b40df0 <+784>:	or     r14,rdx
           0x00007ffff4b40df3 <+787>:	mov    DWORD PTR [rbx+0x38],edi
           0x00007ffff4b40df6 <+790>:	add    rcx,0x1
           0x00007ffff4b40dfa <+794>:	cmp    rcx,0x21
           0x00007ffff4b40dfe <+798>:	je     loop1exit

loop1start:
           0x00007ffff4b40e04 <+804>:	mov    edx,DWORD PTR [r12+rcx*4]
           0x00007ffff4b40e08 <+808>:	cmp    BYTE PTR [r15+rdx*1+0x2648],0x0
           0x00007ffff4b40e11 <+817>:	je     0x7ffff4b40df6 <vbo_exec_vtx_flush+790>
           0x00007ffff4b40e13 <+819>:	lea    rbx,[rcx+0x72]
           0x00007ffff4b40e17 <+823>:	mov    rsi,QWORD PTR [r15+rdx*8+0x2760]
           0x00007ffff4b40e1f <+831>:	sub    rsi,QWORD PTR [rsp+0x38]
           0x00007ffff4b40e24 <+836>:	shl    rbx,0x6
           0x00007ffff4b40e28 <+840>:	add    rbx,rax
           0x00007ffff4b40e2b <+843>:	mov    QWORD PTR [rax+rcx*8+0x24c0],rbx
           0x00007ffff4b40e33 <+851>:	mov    rdi,QWORD PTR [r15+0x14d8]
           0x00007ffff4b40e3a <+858>:	test   rdi,rdi
           0x00007ffff4b40e3d <+861>:	je     0x7ffff4b40e4c <vbo_exec_vtx_flush+876>
           0x00007ffff4b40e3f <+863>:	mov    r9d,DWORD PTR [rdi+0x2c]
           0x00007ffff4b40e43 <+867>:	test   r9d,r9d
           0x00007ffff4b40e46 <+870>:	jne    0x7ffff4b40d50 <vbo_exec_vtx_flush+624>
           0x00007ffff4b40e4c <+876>:	add    rsi,QWORD PTR [r15+0x1ae8]
           0x00007ffff4b40e53 <+883>:	mov    QWORD PTR [rbx+0x18],rsi
           0x00007ffff4b40e57 <+887>:	jmp    0x7ffff4b40d58 <vbo_exec_vtx_flush+632>
loop1end:

           0x00007ffff4b40e5c <+892>:	nop    DWORD PTR [rax+0x0]

call handler:
           0x00007ffff4b40e60 <+896>:	mov    esi,DWORD PTR [rdx+0x4e0]
           0x00007ffff4b40e66 <+902>:	lea    rdx,[rip+0x14270f]        # 0x7ffff4c8357c
           0x00007ffff4b40e6d <+909>:	movsxd rsi,DWORD PTR [rdx+rsi*4]
           0x00007ffff4b40e71 <+913>:	add    rdx,rsi
           0x00007ffff4b40e74 <+916>:	jmp    rdx

dead code:
                   0x00007ffff4b40e76 <+918>:	test   cl,0x1
                   0x00007ffff4b40e79 <+921>:	je     0x7ffff4b40e8a <vbo_exec_vtx_flush+938>
                   0x00007ffff4b40e7b <+923>:	lea    rax,[rax+rax*2]
                   0x00007ffff4b40e7f <+927>:	lea    edx,[rcx-0x1]
                   0x00007ffff4b40e82 <+930>:	mov    DWORD PTR [r13+rax*8+0x8a4],edx
                   0x00007ffff4b40e8a <+938>:	test   ecx,ecx
                   0x00007ffff4b40e8c <+940>:	jne    0x7ffff4b410fa <vbo_exec_vtx_flush+1562>
                   0x00007ffff4b40e92 <+946>:	mov    rdi,QWORD PTR [r13+0x0]
                   0x00007ffff4b40e96 <+950>:	mov    QWORD PTR [rsp+0x28],rdi
                   0x00007ffff4b40e9b <+955>:	jmp    0x7ffff4b40c06 <vbo_exec_vtx_flush+294>

                   0x00007ffff4b40ea0 <+960>:	test   cl,0x1
                   0x00007ffff4b40ea3 <+963>:	je     0x7ffff4b40c06 <vbo_exec_vtx_flush+294>

some loop:
           0x00007ffff4b40ea9 <+969>:	sub    ecx,0x1
           0x00007ffff4b40eac <+972>:	mov    edx,ebx
           0x00007ffff4b40eae <+974>:	mov    r15d,0x1
           0x00007ffff4b40eb4 <+980>:	imul   ebx,ecx
           0x00007ffff4b40eb7 <+983>:	shl    rdx,0x2
           0x00007ffff4b40ebb <+987>:	lea    rsi,[r12+rbx*4]
           0x00007ffff4b40ebf <+991>:	call   0x7ffff4a54b80 <memcpy@plt>
           0x00007ffff4b40ec4 <+996>:	mov    eax,DWORD PTR [r13+0x1184]
           0x00007ffff4b40ecb <+1003>:	cmp    eax,r15d
           0x00007ffff4b40ece <+1006>:	mov    DWORD PTR [r13+0x19fc],r15d
           0x00007ffff4b40ed5 <+1013>:	je     0x7ffff4b40b0d <vbo_exec_vtx_flush+45>
           0x00007ffff4b40edb <+1019>:	mov    rdi,QWORD PTR [r13+0x0]
           0x00007ffff4b40edf <+1023>:	mov    QWORD PTR [rsp+0x28],rdi
           0x00007ffff4b40ee4 <+1028>:	jmp    0x7ffff4b40c11 <vbo_exec_vtx_flush+305>

           0x00007ffff4b40ee9 <+1033>:	test   ecx,ecx
           0x00007ffff4b40eeb <+1035>:	je     0x7ffff4b40c06 <vbo_exec_vtx_flush+294>
           0x00007ffff4b40ef1 <+1041>:	jmp    0x7ffff4b40ea9 <vbo_exec_vtx_flush+969>


dead code:
                   0x00007ffff4b40ef3 <+1043>:	test   ecx,ecx
                   0x00007ffff4b40ef5 <+1045>:	je     0x7ffff4b40c06 <vbo_exec_vtx_flush+294>
                   0x00007ffff4b40efb <+1051>:	cmp    ecx,0x1
                   0x00007ffff4b40efe <+1054>:	xchg   ax,ax
                   0x00007ffff4b40f00 <+1056>:	je     0x7ffff4b4116b <vbo_exec_vtx_flush+1675>
                   0x00007ffff4b40f06 <+1062>:	mov    r14d,ebx
                   0x00007ffff4b40f09 <+1065>:	mov    rsi,r12
                   0x00007ffff4b40f0c <+1068>:	mov    DWORD PTR [rsp+0x10],ecx
                   0x00007ffff4b40f10 <+1072>:	lea    r15,[r14*4+0x0]
                   0x00007ffff4b40f18 <+1080>:	mov    rdx,r15
                   0x00007ffff4b40f1b <+1083>:	call   0x7ffff4a54b80 <memcpy@plt>
                   0x00007ffff4b40f20 <+1088>:	mov    ecx,DWORD PTR [rsp+0x10]
                   0x00007ffff4b40f24 <+1092>:	lea    rdi,[r13+r14*4+0x118c]
                   0x00007ffff4b40f2c <+1100>:	mov    rdx,r15
                   0x00007ffff4b40f2f <+1103>:	mov    r15d,0x2
                   0x00007ffff4b40f35 <+1109>:	sub    ecx,0x1
                   0x00007ffff4b40f38 <+1112>:	imul   ebx,ecx
                   0x00007ffff4b40f3b <+1115>:	lea    rsi,[r12+rbx*4]
                   0x00007ffff4b40f3f <+1119>:	call   0x7ffff4a54b80 <memcpy@plt>
                   0x00007ffff4b40f44 <+1124>:	mov    eax,DWORD PTR [r13+0x1184]
                   0x00007ffff4b40f4b <+1131>:	jmp    0x7ffff4b40ecb <vbo_exec_vtx_flush+1003>

                   0x00007ffff4b40f50 <+1136>:	mov    edi,ecx
                   0x00007ffff4b40f52 <+1138>:	and    edi,0x3
                   0x00007ffff4b40f55 <+1141>:	mov    DWORD PTR [rsp+0x30],edi
                   0x00007ffff4b40f59 <+1145>:	je     0x7ffff4b40c06 <vbo_exec_vtx_flush+294>
                   0x00007ffff4b40f5f <+1151>:	sub    ecx,edi
                   0x00007ffff4b40f61 <+1153>:	mov    r15d,ebx
                   0x00007ffff4b40f64 <+1156>:	xor    r14d,r14d
                   0x00007ffff4b40f67 <+1159>:	imul   ecx,ebx
                   0x00007ffff4b40f6a <+1162>:	shl    r15,0x2
                   0x00007ffff4b40f6e <+1166>:	mov    QWORD PTR [rsp+0x28],r15
                   0x00007ffff4b40f73 <+1171>:	xor    r15d,r15d
                   0x00007ffff4b40f76 <+1174>:	mov    DWORD PTR [rsp+0x24],ecx
                   0x00007ffff4b40f7a <+1178>:	nop    WORD PTR [rax+rax*1+0x0]
                   0x00007ffff4b40f80 <+1184>:	mov    eax,r14d
                   0x00007ffff4b40f83 <+1187>:	mov    rdx,QWORD PTR [rsp+0x28]
                   0x00007ffff4b40f88 <+1192>:	add    r15d,0x1
                   0x00007ffff4b40f8c <+1196>:	lea    rdi,[r13+rax*4+0x118c]
                   0x00007ffff4b40f94 <+1204>:	mov    eax,DWORD PTR [rsp+0x24]
                   0x00007ffff4b40f98 <+1208>:	add    eax,r14d
                   0x00007ffff4b40f9b <+1211>:	add    r14d,ebx
                   0x00007ffff4b40f9e <+1214>:	lea    rsi,[r12+rax*4]
                   0x00007ffff4b40fa2 <+1218>:	call   0x7ffff4a54b80 <memcpy@plt>
                   0x00007ffff4b40fa7 <+1223>:	cmp    r15d,DWORD PTR [rsp+0x30]
                   0x00007ffff4b40fac <+1228>:	jne    0x7ffff4b40f80 <vbo_exec_vtx_flush+1184>

                   0x00007ffff4b40fae <+1230>:	mov    eax,DWORD PTR [r13+0x1184]
                   0x00007ffff4b40fb5 <+1237>:	jmp    0x7ffff4b40ecb <vbo_exec_vtx_flush+1003>

                   0x00007ffff4b40fba <+1242>:	mov    eax,ecx
                   0x00007ffff4b40fbc <+1244>:	mov    r14d,0xaaaaaaab
                   0x00007ffff4b40fc2 <+1250>:	mul    r14d
                   0x00007ffff4b40fc5 <+1253>:	shr    edx,1
                   0x00007ffff4b40fc7 <+1255>:	lea    eax,[rdx+rdx*2]
                   0x00007ffff4b40fca <+1258>:	mov    edx,ecx
                   0x00007ffff4b40fcc <+1260>:	sub    edx,eax
                   0x00007ffff4b40fce <+1262>:	mov    DWORD PTR [rsp+0x24],edx
                   0x00007ffff4b40fd2 <+1266>:	je     0x7ffff4b40c06 <vbo_exec_vtx_flush+294>
                   0x00007ffff4b40fd8 <+1272>:	sub    ecx,edx
                   0x00007ffff4b40fda <+1274>:	mov    r15d,ebx
                   0x00007ffff4b40fdd <+1277>:	xor    r14d,r14d
                   0x00007ffff4b40fe0 <+1280>:	imul   ecx,ebx
                   0x00007ffff4b40fe3 <+1283>:	shl    r15,0x2
                   0x00007ffff4b40fe7 <+1287>:	mov    QWORD PTR [rsp+0x30],r15
                   0x00007ffff4b40fec <+1292>:	xor    r15d,r15d
                   0x00007ffff4b40fef <+1295>:	mov    DWORD PTR [rsp+0x28],ecx
                   0x00007ffff4b40ff3 <+1299>:	nop    DWORD PTR [rax+rax*1+0x0]
                   0x00007ffff4b40ff8 <+1304>:	mov    eax,r14d
                   0x00007ffff4b40ffb <+1307>:	mov    rdx,QWORD PTR [rsp+0x30]
                   0x00007ffff4b41000 <+1312>:	add    r15d,0x1
                   0x00007ffff4b41004 <+1316>:	lea    rdi,[r13+rax*4+0x118c]
                   0x00007ffff4b4100c <+1324>:	mov    eax,DWORD PTR [rsp+0x28]
                   0x00007ffff4b41010 <+1328>:	add    eax,r14d
                   0x00007ffff4b41013 <+1331>:	add    r14d,ebx
                   0x00007ffff4b41016 <+1334>:	lea    rsi,[r12+rax*4]
                   0x00007ffff4b4101a <+1338>:	call   0x7ffff4a54b80 <memcpy@plt>
                   0x00007ffff4b4101f <+1343>:	cmp    r15d,DWORD PTR [rsp+0x24]
                   0x00007ffff4b41024 <+1348>:	jne    0x7ffff4b40ff8 <vbo_exec_vtx_flush+1304>
                   0x00007ffff4b41026 <+1350>:	jmp    0x7ffff4b40fae <vbo_exec_vtx_flush+1230>

   0x00007ffff4b41028 <+1352>:	nop    DWORD PTR [rax+rax*1+0x0]

loop1exit:
   0x00007ffff4b41030 <+1360>:	mov    rdi,QWORD PTR [rsp+0x28]
   0x00007ffff4b41035 <+1365>:	mov    rsi,r14
   0x00007ffff4b41038 <+1368>:	call   0x7ffff4af1660 <_mesa_set_varying_vp_inputs>
   0x00007ffff4b4103d <+1373>:	mov    rdi,QWORD PTR [rsp+0x28]
   0x00007ffff4b41042 <+1378>:	mov    r8d,DWORD PTR [rdi+0xd7ac]
   0x00007ffff4b41049 <+1385>:	mov    eax,DWORD PTR [rdi+0xd7b4]
   0x00007ffff4b4104f <+1391>:	or     DWORD PTR [rdi+0xd7b0],eax
   0x00007ffff4b41055 <+1397>:	test   r8d,r8d
   0x00007ffff4b41058 <+1400>:	jne    if1body
endif1:
   0x00007ffff4b4105e <+1406>:	mov    rax,QWORD PTR [r13+0x890]
   0x00007ffff4b41065 <+1413>:	test   rax,rax
   0x00007ffff4b41068 <+1416>:	je     skip_call1
   
   0x00007ffff4b4106a <+1418>:	mov    edi,DWORD PTR [rax+0x2c]
   0x00007ffff4b4106d <+1421>:	test   edi,edi
   0x00007ffff4b4106f <+1423>:	je     skip_call1

   0x00007ffff4b41071 <+1425>:	mov    rdi,r13
call1:
   0x00007ffff4b41074 <+1428>:	call   0x7ffff4b40860

skip_call1:
   0x00007ffff4b41079 <+1433>:	mov    rdi,QWORD PTR [rsp+0x28]
   0x00007ffff4b4107e <+1438>:	mov    ecx,DWORD PTR [r13+0x1184]
   0x00007ffff4b41085 <+1445>:	xor    r9d,r9d
   0x00007ffff4b41088 <+1448>:	mov    edx,DWORD PTR [r13+0xe9c]
   0x00007ffff4b4108f <+1455>:	lea    rsi,[r13+0x89c]
   0x00007ffff4b41096 <+1462>:	mov    r8d,0x1
   0x00007ffff4b4109c <+1468>:	mov    rax,QWORD PTR [rdi+0xd8b8]
   0x00007ffff4b410a3 <+1475>:	sub    ecx,0x1
   0x00007ffff4b410a6 <+1478>:	mov    QWORD PTR [rsp+0x8],0x0
   0x00007ffff4b410af <+1487>:	mov    DWORD PTR [rsp],ecx
   0x00007ffff4b410b2 <+1490>:	xor    ecx,ecx
   0x00007ffff4b410b4 <+1492>:	call   QWORD PTR [rax+0x5d70]
   0x00007ffff4b410ba <+1498>:	mov    rax,QWORD PTR [r13+0x890]
   0x00007ffff4b410c1 <+1505>:	test   rax,rax
   0x00007ffff4b410c4 <+1508>:	je     0x7ffff4b40b0d <vbo_exec_vtx_flush+45> // skip_call2:

   0x00007ffff4b410ca <+1514>:	mov    esi,DWORD PTR [rax+0x2c]
   0x00007ffff4b410cd <+1517>:	test   esi,esi
   0x00007ffff4b410cf <+1519>:	je     0x7ffff4b40b0d <vbo_exec_vtx_flush+45> // skip_call2:

   0x00007ffff4b410d5 <+1525>:	test   bpl,bpl
   0x00007ffff4b410d8 <+1528>:	jne    0x7ffff4b40ba0 <vbo_exec_vtx_flush+192> // skip_call2:

   0x00007ffff4b410de <+1534>:	mov    rdi,r13
call2:
   0x00007ffff4b410e1 <+1537>:	call   0x7ffff4b40960 <vbo_exec_vtx_map>
   0x00007ffff4b410e6 <+1542>:	jmp    0x7ffff4b40b12 <vbo_exec_vtx_flush+50>
L2exit:

if1body:
   0x00007ffff4b410eb <+1547>:	nop    DWORD PTR [rax+rax*1+0x0]
   0x00007ffff4b410f0 <+1552>:	call   0x7ffff4af1640 <_mesa_update_state>
   0x00007ffff4b410f5 <+1557>:	jmp    endif1

dead code:
                   0x00007ffff4b410fa <+1562>:	cmp    ecx,0x1
                   0x00007ffff4b410fd <+1565>:	mov    DWORD PTR [rsp+0x28],0x1
                   0x00007ffff4b41105 <+1573>:	je     0x7ffff4b41117 <vbo_exec_vtx_flush+1591>
                   0x00007ffff4b41107 <+1575>:	mov    r14d,ecx
                   0x00007ffff4b4110a <+1578>:	and    r14d,0x1
                   0x00007ffff4b4110e <+1582>:	add    r14d,0x2
                   0x00007ffff4b41112 <+1586>:	mov    DWORD PTR [rsp+0x28],r14d
                   0x00007ffff4b41117 <+1591>:	sub    ecx,DWORD PTR [rsp+0x28]
                   0x00007ffff4b4111b <+1595>:	mov    r15d,ebx
                   0x00007ffff4b4111e <+1598>:	xor    r14d,r14d
                   0x00007ffff4b41121 <+1601>:	shl    r15,0x2
                   0x00007ffff4b41125 <+1605>:	mov    QWORD PTR [rsp+0x30],r15
                   0x00007ffff4b4112a <+1610>:	xor    r15d,r15d
                   0x00007ffff4b4112d <+1613>:	imul   ecx,ebx
                   0x00007ffff4b41130 <+1616>:	mov    DWORD PTR [rsp+0x24],ecx
                   0x00007ffff4b41134 <+1620>:	nop    DWORD PTR [rax+0x0]
                   0x00007ffff4b41138 <+1624>:	mov    eax,r14d
                   0x00007ffff4b4113b <+1627>:	mov    rdx,QWORD PTR [rsp+0x30]
                   0x00007ffff4b41140 <+1632>:	add    r15d,0x1
                   0x00007ffff4b41144 <+1636>:	lea    rdi,[r13+rax*4+0x118c]
                   0x00007ffff4b4114c <+1644>:	mov    eax,DWORD PTR [rsp+0x24]
                   0x00007ffff4b41150 <+1648>:	add    eax,r14d
                   0x00007ffff4b41153 <+1651>:	add    r14d,ebx
                   0x00007ffff4b41156 <+1654>:	lea    rsi,[r12+rax*4]
                   0x00007ffff4b4115a <+1658>:	call   0x7ffff4a54b80 <memcpy@plt>
                   0x00007ffff4b4115f <+1663>:	cmp    r15d,DWORD PTR [rsp+0x28]
                   0x00007ffff4b41164 <+1668>:	jne    0x7ffff4b41138 <vbo_exec_vtx_flush+1624>
                   0x00007ffff4b41166 <+1670>:	jmp    0x7ffff4b40fae <vbo_exec_vtx_flush+1230>

                   0x00007ffff4b4116b <+1675>:	mov    edx,ebx
                   0x00007ffff4b4116d <+1677>:	mov    rsi,r12
                   0x00007ffff4b41170 <+1680>:	mov    r15d,0x1
                   0x00007ffff4b41176 <+1686>:	shl    rdx,0x2
                   0x00007ffff4b4117a <+1690>:	call   0x7ffff4a54b80 <memcpy@plt>
                   0x00007ffff4b4117f <+1695>:	mov    eax,DWORD PTR [r13+0x1184]
                   0x00007ffff4b41186 <+1702>:	jmp    0x7ffff4b40ecb <vbo_exec_vtx_flush+1003>

End of assembler dump.
