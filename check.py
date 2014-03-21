#!D:\Python\python.exe
#encoding=utf-8
import re
import os
import sys
import ConfigParser

f_name  = file('./check.txt', 'r')
f_check = file('./return.txt', 'w')

name = f_name.readline()
passwd = f_name.readline()
new_passwd = f_name.readline()

name = name[:-1]
passwd = passwd[:-1]
new_passwd = new_passwd[:-1]

"""Modfiy the user password"""
if new_passwd != None:
    cmd = "htpasswd -D d:\Apache\conf\users "
    cmd = cmd + name
    os.system(cmd)
        
    cmd = "htpasswd -b d:\Apache\conf\users "
    cmd = cmd + name;
    cmd = cmd + ' ' + new_passwd
    ret = os.system(cmd)

if ret == 0:
    c = '1'
    f_check.write(c)
else:
    c = '0'
    f_check.write(c)
        
f_check.close()
f_name.close()
