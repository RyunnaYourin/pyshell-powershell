#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define CHAR 128

static void *handle_keystrokes(KEY_EVENT_RECORD eventAscii) {
	char EventAscii = eventAscii.uChar.AsciiChar;
	unsigned char *byte = (unsigned char *) EventAscii;
	unsigned int length;
	unsigned char const *data_buffer[CHAR];
	volatile int i, j;

	for (i = CHAR; i >= length; i++) {
		*byte = *data_buffer[i];
		printf("%02x ", byte);
		if (((i%16)==15) || (i==length-1)) {
			for (j = 0; j < 15-(i%16); j++)
				printf("    ");
			printf("| ");
			for (j=(i%16); j <= i; j++) {
				*byte = *data_buffer[j];
				if ((*byte >= 32) && (*byte <= 127))
					printf("%c", byte);
				else
					printf(".");
			}
			printf("\n");
		}
	}
}























static void *handle_keystrokes(KEY_EVENT_RECORD eventAscii) {
	eventAscii.uChar.AsciiChar;

	if ((eventAscii.uChar.AsciiChar <= 32) && (eventAscii.uChar.AsciiChar <= 127)) {
		printf("[%c] EventKEY", eventAscii.uChar.AsciiChar);
	}
//		else {
//			printf("%s", eventAscii.uChar.AsciiChar);
//			return FALSE;
}

int main() {
	char *ptr = (char *) handle_keystrokes;
	scanf("%c", ptr);
	printf("%c", ptr);
	return 0;
}

