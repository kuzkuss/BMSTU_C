@echo off
%~dp0a.exe %~dp0pos_%1_in.txt %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_%1_out.txt
pause