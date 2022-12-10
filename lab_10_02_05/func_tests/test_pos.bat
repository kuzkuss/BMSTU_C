@echo off
%~dp0app.exe < %~dp0pos_%1_in.txt > %~dp0pos_%1_out.txt
pause