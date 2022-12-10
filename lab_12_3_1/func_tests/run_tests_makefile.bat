@echo off
cls
for %%i in (01 02 03 04 05 06) do call %~dp0test_pos_makefile.bat %%i
%~dp0a.exe %~dp0pos_07_in.txt %~dp0f_out.txt f
fc %~dp0f_out.txt %~dp0pos_07_out.txt
pause
%~dp0a.exe %~dp0pos_08_in.txt %~dp0f_out.txt f
fc %~dp0f_out.txt %~dp0pos_08_out.txt
pause
%~dp0a.exe %~dp0pos_09_in.txt %~dp0f_out.txt f
fc %~dp0f_out.txt %~dp0pos_09_out.txt
pause
%~dp0a.exe %~dp0pos_10_in.txt %~dp0f_out.txt f
fc %~dp0f_out.txt %~dp0pos_10_out.txt
pause
for %%i in (01 02 05) do call %~dp0test_neg_makefile.bat %%i
%~dp0a.exe %~dp0neg_06_in.txt %~dp0neg_06_out.txt f > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_06_out.txt
%~dp0a.exe %~dp0neg_07_in.txt %~dp0neg_07_out.txt ksvb > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_07_out.txt
pause