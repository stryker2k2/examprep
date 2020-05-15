C:\Users\journeyman\source\repos\nasm_assycode>objdump -d -M intel GetK32FASM.exe

GetK32FASM.exe:     file format pei-i386


Disassembly of section .flat:

00401000 <.flat>:
  401000:       50                      push   eax
  401001:       53                      push   ebx
  401002:       51                      push   ecx
  401003:       52                      push   edx
  401004:       56                      push   esi
  401005:       57                      push   edi
  401006:       55                      push   ebp
  401007:       89 e5                   mov    ebp,esp
  401009:       83 ec 18                sub    esp,0x18
  40100c:       31 f6                   xor    esi,esi
  40100e:       56                      push   esi
  40100f:       6a 63                   push   0x63
  401011:       66 68 78 65             pushw  0x6578
  401015:       68 57 69 6e 45          push   0x456e6957
  40101a:       89 65 fc                mov    DWORD PTR [ebp-0x4],esp
  40101d:       31 f6                   xor    esi,esi
  40101f:       64 8b 5e 30             mov    ebx,DWORD PTR fs:[esi+0x30]
  401023:       8b 5b 0c                mov    ebx,DWORD PTR [ebx+0xc]
  401026:       8b 5b 14                mov    ebx,DWORD PTR [ebx+0x14]
  401029:       8b 1b                   mov    ebx,DWORD PTR [ebx]
  40102b:       8b 1b                   mov    ebx,DWORD PTR [ebx]
  40102d:       8b 5b 10                mov    ebx,DWORD PTR [ebx+0x10]
  401030:       89 5d f8                mov    DWORD PTR [ebp-0x8],ebx
  401033:       8b 43 3c                mov    eax,DWORD PTR [ebx+0x3c]
  401036:       01 d8                   add    eax,ebx
  401038:       8b 40 78                mov    eax,DWORD PTR [eax+0x78]
  40103b:       01 d8                   add    eax,ebx
  40103d:       8b 48 24                mov    ecx,DWORD PTR [eax+0x24]
  401040:       01 d9                   add    ecx,ebx
  401042:       89 4d f4                mov    DWORD PTR [ebp-0xc],ecx
  401045:       8b 78 20                mov    edi,DWORD PTR [eax+0x20]
  401048:       01 df                   add    edi,ebx
  40104a:       89 7d f0                mov    DWORD PTR [ebp-0x10],edi
  40104d:       8b 50 1c                mov    edx,DWORD PTR [eax+0x1c]
  401050:       01 da                   add    edx,ebx
  401052:       89 55 ec                mov    DWORD PTR [ebp-0x14],edx
  401055:       8b 50 14                mov    edx,DWORD PTR [eax+0x14]
  401058:       31 c0                   xor    eax,eax
  40105a:       8b 7d f0                mov    edi,DWORD PTR [ebp-0x10]
  40105d:       8b 75 fc                mov    esi,DWORD PTR [ebp-0x4]
  401060:       31 c9                   xor    ecx,ecx
  401062:       fc                      cld
  401063:       8b 3c 87                mov    edi,DWORD PTR [edi+eax*4]
  401066:       01 df                   add    edi,ebx
  401068:       66 83 c1 08             add    cx,0x8
  40106c:       f3 a6                   repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
  40106e:       74 0a                   je     0x40107a
  401070:       40                      inc    eax
  401071:       39 d0                   cmp    eax,edx
  401073:       72 e5                   jb     0x40105a
  401075:       83 c4 26                add    esp,0x26
  401078:       eb 3f                   jmp    0x4010b9
  40107a:       8b 4d f4                mov    ecx,DWORD PTR [ebp-0xc]
  40107d:       8b 55 ec                mov    edx,DWORD PTR [ebp-0x14]
  401080:       66 8b 04 41             mov    ax,WORD PTR [ecx+eax*2]
  401084:       8b 04 82                mov    eax,DWORD PTR [edx+eax*4]
  401087:       01 d8                   add    eax,ebx
  401089:       31 d2                   xor    edx,edx
  40108b:       52                      push   edx
  40108c:       68 2e 65 78 65          push   0x6578652e
  401091:       68 63 61 6c 63          push   0x636c6163
  401096:       68 6d 33 32 5c          push   0x5c32336d
  40109b:       68 79 73 74 65          push   0x65747379
  4010a0:       68 77 73 5c 53          push   0x535c7377
  4010a5:       68 69 6e 64 6f          push   0x6f646e69
  4010aa:       68 43 3a 5c 57          push   0x575c3a43
  4010af:       89 e6                   mov    esi,esp
  4010b1:       6a 0a                   push   0xa
  4010b3:       56                      push   esi
  4010b4:       ff d0                   call   eax
  4010b6:       83 c4 46                add    esp,0x46
  4010b9:       5d                      pop    ebp
  4010ba:       5f                      pop    edi
  4010bb:       5e                      pop    esi
  4010bc:       5a                      pop    edx
  4010bd:       59                      pop    ecx
  4010be:       5b                      pop    ebx
  4010bf:       58                      pop    eax
  4010c0:       c3                      ret
