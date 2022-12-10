@echo off
a.exe pos_%1_in.txt f_out.txt
fc f_out.txt pos_%1_out.txt
pause