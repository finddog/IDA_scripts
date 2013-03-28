// fold common inlined functions (win32)

#include <idc.idc>

static main()
{
	auto ea,cont;

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
		ea = FindBinary (ea,SEARCH_DOWN,"C1 E9 02 F3 A5 8B C8 33 C0 83 E1 03 F3 A4");

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
		ea = FindBinary (ea,SEARCH_DOWN,"8A 10 8A CA 3A 16 75 1C 84 C9 74 14 8A 50 01 8A CA 3A 56 01 75 0E 83 C0 02 83 C6 02 84 C9 75 E0 33 C0 EB 05 1B C0 83 D8 FF");

		if( ea == -1) 
		{
			cont=0;
			break;
		}
		HideArea(ea, ea + 40, "ecx=(w?)strcmp (eax, esi)", "", "", -1);
		ea=ea+40;
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
/*
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
*/
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
		ea = FindBinary (ea,SEARCH_DOWN,"83 C9 FF 33 C0 F2 AE F7 D1 2B F9 8B C1 8B F7 8B FA C1 E9 02 F3 A5 8B C8 83 E1 03 F3 A4");

		if(ea == -1) 
			break;

		HideArea(ea, ea + 29, "strcpy (edx, edi)", "", "", -1);
		ea=ea+29;
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