@echo off
%~dp0app.exe %~dp0pos_%1_in.txt %~dp0f_out.txt descending
fc %~dp0pos_%1_out.txt %~dp0f_out.txt
pause