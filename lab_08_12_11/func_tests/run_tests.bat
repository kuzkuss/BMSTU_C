@echo off
cls
%~dp0app.exe a %~dp0pos_01_in1.txt %~dp0pos_01_in2.txt %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_01_out.txt
pause
%~dp0app.exe a %~dp0pos_02_in1.txt %~dp0pos_02_in2.txt %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_02_out.txt
pause
%~dp0app.exe a %~dp0pos_03_in1.txt %~dp0pos_03_in2.txt %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_03_out.txt
pause
%~dp0app.exe m %~dp0pos_04_in1.txt %~dp0pos_04_in2.txt %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_04_out.txt
pause
%~dp0app.exe m %~dp0pos_05_in1.txt %~dp0pos_05_in2.txt %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_05_out.txt
pause
%~dp0app.exe m %~dp0pos_06_in1.txt %~dp0pos_06_in2.txt %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_06_out.txt
pause
for %%i in (07 08 09 10) do call %~dp0test_pos.bat %%i

for %%i in (01 07 10 11 12 13 14) do call %~dp0test_neg.bat %%i
%~dp0app.exe m %~dp0neg_02_in1.txt %~dp0neg_02_in2.txt %~dp0f_out.txt > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_02_out.txt
pause
%~dp0app.exe b %~dp0neg_03_in1.txt %~dp0neg_03_in2.txt %~dp0f_out.txt > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_03_out.txt
pause
%~dp0app.exe o %~dp0neg_04_in1.txt %~dp0f_out.txt > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_04_out.txt
pause
%~dp0app.exe a %~dp0neg_05_in1.txt %~dp0neg_05_in2.txt %~dp0f_out.txt ksjvdb > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_05_out.txt
pause
%~dp0app.exe o %~dp0neg_06_in1.txt %~dp0f_out.txt > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_06_out.txt
pause
%~dp0app.exe m %~dp0neg_08_in1.txt %~dp0neg_08_in2.txt %~dp0f_out.txt > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_08_out.txt
pause
%~dp0app.exe o %~dp0neg_09_in1.txt %~dp0f_out.txt > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_09_out.txt
pause
%~dp0app.exe m %~dp0neg_15_in1.txt %~dp0neg_15_in2.txt %~dp0f_out.txt > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_15_out.txt
pause
%~dp0app.exe o %~dp0neg_16_in1.txt %~dp0f_out.txt > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_16_out.txt
pause

