@echo off
%~dp0app.exe %~dp0neg_%1_in.txt > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_%1_out.txt
pause