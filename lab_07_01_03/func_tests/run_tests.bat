@echo off
cls
for %%i in (01 02 03 04 05 06) do call test_pos.bat %%i
a.exe pos_07_in.txt f_out.txt f
fc f_out.txt pos_07_out.txt
pause
a.exe pos_08_in.txt f_out.txt f
fc f_out.txt pos_08_out.txt
pause
a.exe pos_09_in.txt f_out.txt f
fc f_out.txt pos_09_out.txt
pause
a.exe pos_10_in.txt f_out.txt f
fc f_out.txt pos_10_out.txt
pause
for %%i in (01 02 05) do call test_neg.bat %%i
a.exe neg_06_in.txt neg_06_out.txt f > f_out.txt
fc f_out.txt neg_06_out.txt
a.exe neg_07_in.txt neg_07_out.txt ksvb > f_out.txt
fc f_out.txt neg_07_out.txt
pause