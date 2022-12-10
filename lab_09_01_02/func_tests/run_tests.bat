@echo off
cls
for %%i in (01 02 03) do call %~dp0test_pos.bat %%i
%~dp0app.exe %~dp0pos_04_in.txt ox > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_04_out.txt
pause
%~dp0app.exe %~dp0pos_05_in.txt ALL > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_05_out.txt
pause
%~dp0app.exe %~dp0pos_06_in.txt ksdv > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_06_out.txt
pause
%~dp0app.exe %~dp0pos_07_in.txt bo > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_07_out.txt
pause

for %%i in (01 02 03 04 05 06 07) do call %~dp0test_neg.bat %%i
%~dp0app.exe > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_08_out.txt
pause
%~dp0app.exe %~dp0neg_09_in.txt ksdv skdjvb > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_09_out.txt
pause