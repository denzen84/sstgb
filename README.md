# sstgb
simply sender telegram bot
# Overview
Simply bot to send text and photo through command line interface. Requires Telebot library (https://github.com/smartnode/telebot)
# Usage
Put two text files in the directory with bot:
1) .token - text file where first string is telegram bot ID
2) .group - text file where first string is chat ID

## Command line interface
`Usage: sstgb <command> <parameter> [options]`

## Commands:
```--sendtext <text>        Send text to user ID```
```--sendpic  <filename>    Send picture to user ID```
```--sendvideo <filename>   Send video to user ID```

## Options:
```--token <token>          Bot token```
```--userid <id>            User ID```
```--fileconfigs            Read bot token and userid from files .token and .userid accordingly```
```--remove                 Remove file after use for --sendpic, --sendvideo, be careful!```
```To use --fileconfigs there are should be two files:```
```1) .token  - text file where first string is telegram bot token```
```2) .userid - text file where first string is user ID```
