#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ShlObj.h>

int main() {
    BOOL isAdmin = IsUserAnAdmin();
	int MSG_BOX = MessageBox(NULL, L"??", L"??", MB_OK);
	if (isAdmin) {
		if (MSG_BOX == IDOK)
			printf("[+] Run-As [Administrator]\n\n\n\tWELCOME TO MY PLACE");
			goto return_function;

	} else if (MSG_BOX == IDOK) {
			printf("[+] Run-As [User]\n\n\n\tRUN ADMINISTRATOR FOR KEY-GEN ACTIVATION");
			goto return_function;
	}
return_function:
    return isAdmin ? 0 : 1;
}


// ACCESS TOKEN

/***
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ShlObj.h>

int main() {
    BOOL isAdmin = IsUserAnAdmin();
	// int MSG_BOX = MessageBox(NULL, L"MESSAGE FROM AGENT_47", L"PRIVESC PROGRAM", MB_OKCANCEL);
	int MSG_BOX = MessageBox(NULL, L"", L"", NULL);
	if (isAdmin) {
		if (MSG_BOX == IDOK)
			printf("[+] Run-As [Administrator]\n");
			goto return_function;
	}
	else if (MSG_BOX == IDOK) { // alternative IDOK -> IDCANCEL
			printf("[+] Run-As [User]\n");
			goto return_function;
	}
return_function:
    return isAdmin ? 0 : 1;
}
 ***/