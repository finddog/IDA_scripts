// fold common inlined functions (win32)

#include <idc.idc>

static main()
{
	auto ea,cont;

	ea = FirstSeg();
	cont = 1;
	while (cont==1) 
	{

/*
8B FE      mov     edi, esi
83 C9 FF   or      ecx, 0FFFFFFFFh
33 C0      xor     eax, eax
F2 AE      repne scasb
F7 D1      not     ecx
49         dec     ecx
*/
		ea = FindBinary (ea,SEARCH_DOWN,"83 C9 FF F2 AE F7 D1 49");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 8, "ecx=strlen (edi)", "", "", -1);
		ea=ea+8;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) 
	{
/*
 C1 E9 02    shr     ecx, 2
 F3 A5       rep movsd
 8B C8       mov     ecx, eax
 33 C0       xor     eax, eax
 83 E1 03    and     ecx, 3
 F3 A4       rep movsb
*/	
		ea = FindBinary (ea,SEARCH_DOWN,"C1 E9 02 F3 A5 8B C8 33 C0 83 E1 03 F3 A4");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 14, "memcpy (edi, esi, ecx); eax=0", "", "", -1);
		ea=ea+14;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) 
	{
/*
 C1 E9 02    shr     ecx, 2
 F3 A5       rep movsd
 8B C8       mov     ecx, eax
 83 E1 03    and     ecx, 3
 F3 A4       rep movsb
*/	
		ea = FindBinary (ea,SEARCH_DOWN,"C1 E9 02 F3 A5 8B C8 83 E1 03 F3 A4");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 12, "memcpy (edi, esi, ecx)", "", "", -1);
		ea=ea+12;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
/*
 8A 10                                mov     dl, [eax]
 3A 11                                cmp     dl, [ecx]
 75 1A                                jnz     short loc_10027FA0
 84 D2                                test    dl, dl
 74 12                                jz      short loc_10027F9C
 8A 50 01                             mov     dl, [eax+1]
 3A 51 01                             cmp     dl, [ecx+1]
 75 0E                                jnz     short loc_10027FA0
 83 C0 02                             add     eax, 2
 83 C1 02                             add     ecx, 2
 84 D2                                test    dl, dl
 75 E4                                jnz     short loc_10027F80

                      loc_10027F9C:                           ; CODE XREF: f1+448j
 33 C0                                xor     eax, eax
 EB 05                                jmp     short loc_10027FA5
                      ; ---------------------------------------------------------------------------

                      loc_10027FA0:                           ; CODE XREF: f1+444j
                                                              ; f1+450j
 1B C0                                sbb     eax, eax
 83 D8 FF                             sbb     eax, 0FFFFFFFFh
*/
		ea = FindBinary (ea,SEARCH_DOWN,"8A 10 3A 11 75 1A 84 D2 74 12 8A 50 01 3A 51 01 75 0E 83 C0 02 83 C1 02 84 D2 75 E4 33 C0 EB 05 1B C0 83 D8 FF");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 37, "eax=strcmp (eax, ecx)", "", "", -1);
		ea=ea+37;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
/*
 8A 19                                mov     bl, [ecx]
 3A 1A                                cmp     bl, [edx]
 75 1A                                jnz     short loc_1002B6C4
 84 DB                                test    bl, bl
 74 12                                jz      short loc_1002B6C0
 8A 59 01                             mov     bl, [ecx+1]
 3A 5A 01                             cmp     bl, [edx+1]
 75 0E                                jnz     short loc_1002B6C4
 83 C1 02                             add     ecx, 2
 83 C2 02                             add     edx, 2
 84 DB                                test    bl, bl
 75 E4                                jnz     short loc_1002B6A4

                      loc_1002B6C0:                           ; CODE XREF: set_val1+2Cj
 33 C9                                xor     ecx, ecx
 EB 05                                jmp     short loc_1002B6C9
                      ; ---------------------------------------------------------------------------

                      loc_1002B6C4:                           ; CODE XREF: set_val1+28j
                                                              ; set_val1+34j
 1B C9                                sbb     ecx, ecx
 83 D9 FF                             sbb     ecx, 0FFFFFFFFh
*/
		ea = FindBinary (ea,SEARCH_DOWN,"8A 19 3A 1A 75 1A 84 DB 74 12 8A 59 01 3A 5A 01 75 0E 83 C1 02 83 C2 02 84 DB 75 E4 33 C9 EB 05 1B C9 83 D9 FF");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 37, "ecx=strcmp (ecx, edx)", "", "", -1);
		ea=ea+37;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
/*
 8A 10                             mov     dl, [eax]
 8A CA                             mov     cl, dl
 3A 16                             cmp     dl, [esi]
 75 1C                             jnz     short loc_4052AA
 84 C9                             test    cl, cl
 74 14                             jz      short loc_4052A6
 8A 50 01                          mov     dl, [eax+1]
 8A CA                             mov     cl, dl
 3A 56 01                          cmp     dl, [esi+1]
 75 0E                             jnz     short loc_4052AA
 83 C0 02                          add     eax, 2
 83 C6 02                          add     esi, 2
 84 C9                             test    cl, cl
 75 E0                             jnz     short loc_405286

                   loc_4052A6:                             ; CODE XREF: sub_405110+180
 33 C0                             xor     eax, eax
 EB 05                             jmp     short loc_4052AF
                   ; ---------------------------------------------------------------------------

                   loc_4052AA:                             ; CODE XREF: sub_405110+17C
                                                           ; sub_405110+18A
 1B C0                             sbb     eax, eax
 83 D8 FF                          sbb     eax, 0FFFFFFFFh
*/
		ea = FindBinary (ea,SEARCH_DOWN,"8A 10 8A CA 3A 16 75 1C 84 C9 74 14 8A 50 01 8A CA 3A 56 01 75 0E 83 C0 02 83 C6 02 84 C9 75 E0 33 C0 EB 05 1B C0 83 D8 FF");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 40, "ecx=strcmp (eax, esi)", "", "", -1);
		ea=ea+40;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
/*
8A 10                             mov     dl, [eax]
8A 1E                             mov     bl, [esi]
8A CA                             mov     cl, dl
3A D3                             cmp     dl, bl
75 1E                             jnz     short loc_402DF6
84 C9                             test    cl, cl
74 16                             jz      short loc_402DF2
8A 50 01                          mov     dl, [eax+1]
8A 5E 01                          mov     bl, [esi+1]
8A CA                             mov     cl, dl
3A D3                             cmp     dl, bl
75 0E                             jnz     short loc_402DF6
83 C0 02                          add     eax, 2
83 C6 02                          add     esi, 2
84 C9                             test    cl, cl
75 DC                             jnz     short loc_402DCE

                  loc_402DF2:                             ; CODE XREF: sub_402D70+6A
33 FF                             xor     edi, edi
EB 05                             jmp     short loc_402DFB
                  ; ---------------------------------------------------------------------------

                  loc_402DF6:                             ; CODE XREF: sub_402D70+66
                                                          ; sub_402D70+76
1B FF                             sbb     edi, edi
83 DF FF                          sbb     edi, 0FFFFFFFFh
*/
		ea = FindBinary (ea,SEARCH_DOWN,"8A 10 8A 1E 8A CA 3A D3 75 1E 84 C9 74 16 8A 50 01 8A 5E 01 8A CA 3A D3 75 0E 83 C0 02 83 C6 02 84 C9 75 DC 33 FF EB 05 1B FF 83 DF FF");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 45, "edi=strcmp (eax, esi)", "", "", -1);
		ea=ea+45;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
/*
8A 10                             mov     dl, [eax]
8A 1E                             mov     bl, [esi]
8A CA                             mov     cl, dl
3A D3                             cmp     dl, bl
75 1E                             jnz     short loc_402DF6
84 C9                             test    cl, cl
74 16                             jz      short loc_402DF2
8A 50 01                          mov     dl, [eax+1]
8A 5E 01                          mov     bl, [esi+1]
8A CA                             mov     cl, dl
3A D3                             cmp     dl, bl
75 0E                             jnz     short loc_402DF6
83 C0 02                          add     eax, 2
83 C6 02                          add     esi, 2
84 C9                             test    cl, cl
75 DC                             jnz     short loc_402DCE

                  loc_402DF2:                             ; CODE XREF: sub_402D70+6A
33 F6                             xor     esi, esi
EB 05                             jmp     short loc_402DFB
                  ; ---------------------------------------------------------------------------

                  loc_402DF6:                             ; CODE XREF: sub_402D70+66
                                                          ; sub_402D70+76
1B F6                             sbb     esi, esi
83 DE FF                          sbb     esi, 0FFFFFFFFh
*/
		ea = FindBinary (ea,SEARCH_DOWN,"8A 10 8A 1E 8A CA 3A D3 75 1E 84 C9 74 16 8A 50 01 8A 5E 01 8A CA 3A D3 75 0E 83 C0 02 83 C6 02 84 C9 75 DC 33 F6 EB 05 1B F6 83 DE FF");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 45, "esi=strcmp (eax, esi)", "", "", -1);
		ea=ea+45;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
/*
8A 10                             mov     dl, [eax]
8A 1E                             mov     bl, [esi]
8A CA                             mov     cl, dl
3A D3                             cmp     dl, bl
75 1E                             jnz     short loc_402DF6
84 C9                             test    cl, cl
74 16                             jz      short loc_402DF2
8A 50 01                          mov     dl, [eax+1]
8A 5E 01                          mov     bl, [esi+1]
8A CA                             mov     cl, dl
3A D3                             cmp     dl, bl
75 0E                             jnz     short loc_402DF6
83 C0 02                          add     eax, 2
83 C6 02                          add     esi, 2
84 C9                             test    cl, cl
75 DC                             jnz     short loc_402DCE

                  loc_402DF2:                             ; CODE XREF: sub_402D70+6A
33 C0                             xor     eax, eax
EB 05                             jmp     short loc_402DFB
                  ; ---------------------------------------------------------------------------

                  loc_402DF6:                             ; CODE XREF: sub_402D70+66
                                                          ; sub_402D70+76
1B C0                             sbb     eax, eax
83 D8 FF                          sbb     eax, 0FFFFFFFFh
*/
		ea = FindBinary (ea,SEARCH_DOWN,"8A 10 8A 1E 8A CA 3A D3 75 1E 84 C9 74 16 8A 50 01 8A 5E 01 8A CA 3A D3 75 0E 83 C0 02 83 C6 02 84 C9 75 DC 33 C0 EB 05 1B C0 83 D8 FF");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 45, "eax=strcmp (eax, esi)", "", "", -1);
		ea=ea+45;
	}

	ea = FirstSeg();
	while (1) 
	{
/*
 83 C9 FF                          or      ecx, 0FFFFFFFFh
 33 C0                             xor     eax, eax
 F2 AE                             repne scasb
 F7 D1                             not     ecx
 2B F9                             sub     edi, ecx
 8B C1                             mov     eax, ecx
 8B F7                             mov     esi, edi
 8B FA                             mov     edi, edx
 C1 E9 02                          shr     ecx, 2
 F3 A5                             rep movsd
 8B C8                             mov     ecx, eax
 83 E1 03                          and     ecx, 3
 F3 A4                             rep movsb
*/
		ea = FindBinary (ea,SEARCH_DOWN,"83 C9 FF 33 C0 F2 AE F7 D1 2B F9 8B C1 8B F7 8B FA C1 E9 02 F3 A5 8B C8 83 E1 03 F3 A4");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 29, "strcpy (edx, edi)", "", "", -1);
		ea=ea+29;
	};

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
		ea = FindBinary (ea,SEARCH_DOWN,"8A 18 8A CB 3A 1E 75 1C 84 C9 74 14 8A 58 01 8A CB 3A 5E 01 75 0E 83 C0 02 83 C6 02 84 C9 75 E0 33 C0 EB 05 1B C0 83 D8 FF");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 41, "eax=strcmp (esi, eax)", "", "", -1);
		ea=ea+41;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
		ea = FindBinary (ea,SEARCH_DOWN,"8A 17 3A 16 75 1A 0A D2 74 12 8A 57 01 3A 56 01 75 0E 83 C7 02 83 C6 02 0A D2 75 E4 33 C0 EB 05 1B C0 83 C8 01");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 37, "ecx=strcmp (edi, esi)", "", "", -1);
		ea=ea+37;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
		ea = FindBinary (ea,SEARCH_DOWN,"8B D1 C1 E9 02 F3 A5 8B CA 83 E1 03 F3 A4");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 14, "memcpy (edi, esi, ecx)", "", "", -1);
		ea=ea+14;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
		ea = FindBinary (ea,SEARCH_DOWN,"83 C9 FF 8B FA F2 AE F7 D1 49");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 10, "ecx=strlen (edx)", "", "", -1);
		ea=ea+10;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
		ea = FindBinary (ea,SEARCH_DOWN,"8B FE 83 C9 FF 33 C0 F2 AE F7 D1 49");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 12, "ecx=strlen (esi)", "", "", -1);
		ea=ea+12;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
		ea = FindBinary (ea,SEARCH_DOWN,"33 C0 8A 37 8B CF 84 F6 74 0C 83 C1 01 83 C0 01 8A 11 84 D2 75 F4");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 22, "eax=strlen (edi)", "", "", -1);
		ea=ea+22;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
		ea = FindBinary (ea,SEARCH_DOWN,"03 C0 03 C0 03 C0 03 C0 03 C0 03 C0");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 12, "eax=eax*64", "", "", -1);
		ea=ea+12;
	}

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
		ea = FindBinary (ea,SEARCH_DOWN,"03 C0 03 C0 03 C0 03 C0 03 C0");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 10, "eax=eax*32", "", "", -1);
		ea=ea+10;
	}

	ea = FirstSeg();
	while (1) 
	{
		ea = FindBinary (ea,SEARCH_DOWN,"33 C0 85 C9 74 11 8A 06 2A 07 75 0B 83 C6 01 83 C7 01 83 E9 01 75 EF 0F 97 C0 0F 92 C1 2A C1 0F BE C0");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 34, "eax=memcmp (esi, edi, ecx)", "", "", -1);
		ea=ea+34;
	};

	ea = FirstSeg();
	while (1) 
	{
		ea = FindBinary (ea,SEARCH_DOWN,"33 C0 8B E5 5D C3");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 6, "return 0", "", "", -1);
		ea=ea+6;
	};

	ea = FirstSeg();
	while (1) 
	{
		ea = FindBinary (ea,SEARCH_DOWN,"31 C0 89 EC 5D C3");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 6, "return 0", "", "", -1);
		ea=ea+6;
	};

	ea = FirstSeg();
	while (1) 
	{
		ea = FindBinary (ea,SEARCH_DOWN,"B8 01 00 00 00 8B E5 5D C3");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 9, "return 1", "", "", -1);
		ea=ea+9;
	};

	ea = FirstSeg();
	while (1) 
	{
		ea = FindBinary (ea,SEARCH_DOWN,"B8 01 00 00 00 89 EC 5D C3");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 9, "return 1", "", "", -1);
		ea=ea+9;
	};

	ea = FirstSeg();
	while (1) 
	{
		ea = FindBinary (ea,SEARCH_DOWN,"31 C0 8A 37 89 F9 84 F6 74 0C 83 C1 01 83 C0 01 8A 11 84 D2 75 F4");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 22, "eax=strlen (edi)", "", "", -1);
		ea=ea+22;
	};

	ea = FirstSeg();
	while (1) 
	{
		ea = FindBinary (ea,SEARCH_DOWN,"8A 17 83 C7 01 88 16 83 C6 01 84 D2 75 F2");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 14, "strcpy (esi, edi)", "", "", -1);
		ea=ea+14;
	};

	ea = FirstSeg();
	while (1) 
	{
		ea = FindBinary (ea,SEARCH_DOWN,"8A 02 83 C2 01 88 07 83 C7 01 84 C0 75 F2");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 14, "strcpy (edi, edx)", "", "", -1);
		ea=ea+14;
	};

	ea = FirstSeg();
	while (1) 
	{
		ea = FindBinary (ea,SEARCH_DOWN,"31 C0 85 C9 74 11 8A 06 2A 07 75 0B 83 C6 01 83 C7 01 83 E9 01 75 EF 0F 97 C0 0F 92 C1 28 C8 0F BE C0");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 34, "eax=memcmp (esi, edi, ecx)", "", "", -1);
		ea=ea+34;
	};

	ea = FirstSeg();
	while (1) 
	{
		ea = FindBinary (ea,SEARCH_DOWN,"8B C1 C1 E9 02 F3 A5 8B C8 83 E1 03 F3 A4");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 14, "memcpy (edi, esi, ecx)", "", "", -1);
		ea=ea+14;
	};

	ea = FirstSeg();
	while (1) 
	{
		ea = FindBinary (ea,SEARCH_DOWN,"8B FA 83 C9 FF 33 C0 F2 AE F7 D1");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 11, "ecx=strlen (edx)", "", "", -1);
		ea=ea+11;
	};

	ea = FirstSeg();
	cont = 1;
	while (cont==1) {
		ea = FindBinary (ea,SEARCH_DOWN,"51 C1 E9 02 F3 A5 59 83 E1 03 F3 A4");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea +12, "memcpy (edi, esi, ecx)", "", "", -1);
		ea=ea+12;
	}

 	Message("\n" + "Search Complete\n");
}