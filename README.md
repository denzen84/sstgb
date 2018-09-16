# sstgb
simply sender telegram bot
# Overview
Simply bot to send text and photo through command line interface. Requires Telebot library (https://github.com/smartnode/telebot)
# Usage
Put two text files in the directory with bot:
1) .token - text file where first string is telegram bot ID
2) .group - text file where first string is chat ID

## Command line interface
sstgb <command> <parameter>

## Commands:
`--sendtext <text>        Send text to chat
--sendpic  <filename>    Send picture to chat`
