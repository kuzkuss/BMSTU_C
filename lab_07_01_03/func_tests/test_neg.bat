@echo off
a.exe neg_%1_in.txt > f_out.txt
fc f_out.txt neg_%1_out.txt
pause