#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <telebot.h>

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

void printHelp(void) {
printf(
"-----------------------------------------------------------------------------\n"
"| sstgb: simply sender telegram bot                                          |\n"
"-----------------------------------------------------------------------------\n"
"\n"
"This telegram bot sends text and pictures according to command line paramaters\n"
"To use this bot there are should be two files:\n"
"1) .token - text file where first string is telegram bot ID\n"
"2) .group - text file where first string is chat ID\n"
"\n"
"Usage: sstgb <command> <parameter>\n"
"\n"
"Commands:\n"
  "--sendtext <text>        Send text to chat\n"
  "--sendpic  <filename>    Send picture to chat\n"
"\n"
);

}

int main(int argc, char *argv[])
{
    if (argc < 3) {

    	printf("Not enough command line parameters\n");
    printHelp();
    	return -1;
    }

    FILE *fp = fopen(".token", "r");
    if (fp == NULL) {
        printf("Failed to open token file\n");
        return -1;
    }

    char token[1024];
    if (fscanf(fp, "%s", token) == 0) {
        printf("Reading token failed\n");
        printHelp();
        fclose(fp);
        return -1;
    }

    fclose(fp);

    fp = fopen(".group", "r");
    if (fp == NULL) {
        printf("Failed to open group file\n");
        printHelp();
        return -1;
    }

    long long group_id;

    if (fscanf(fp, "%lld", &group_id) == 0) {
        printf("Reading group failed\n");
        fclose(fp);
        return -1;
    }
    fclose(fp);

    telebot_handler_t handle;
    if (telebot_create(&handle, token) != TELEBOT_ERROR_NONE) {
        printf("Telebot create failed\n");
        return -1;
    }

    telebot_error_e ret;


    if (!strcmp(argv[1],"--sendtext")) {
    		ret = telebot_send_message(handle, group_id, argv[2], "", false, false, 0, "");
    		if (ret != TELEBOT_ERROR_NONE) {
    			printf("Failed to send text message: %d \n", ret);
    		}
    } else if (!strcmp(argv[1],"--sendpic")) {
    	ret = telebot_send_photo(handle, group_id, argv[2], true, NULL, false, 0, NULL);
    	if (ret != TELEBOT_ERROR_NONE) { printf("Failed to send picture: %d \n", ret); }
    } else {
    	printf("Unrecognized command\n");
        printHelp();
    }

    telebot_destroy(handle);


    return 0;
}
