@echo off
mkdir ressources
cls
echo Install the following dependancies (All the link are also in the README):
echo Python: https://www.python.org/ftp/python/3.9.5/python-3.9.5-amd64.exe
echo Ghost Script/ps2pdf: https://ghostscript.com/pipermail/gs-devel/2009-April/008314.html
echo Gnuplot (64 bit only): https://sourceforge.net/projects/gnuplot/files/gnuplot/5.4.1/gp541-win64-mingw.exe/download
echo.
echo Appuyer quand les dependances sont installees
echo.
pause

echo Enter the location of python (exemple: C:\Users\%USER%\AppData\Local\Programs\Python\Python39):
set /p Python_Location=
echo Enter the location of GhostScript
set /p GhostScript_Location=
echo Enter the location of Gnuplot
set /p Gnuplot_Location=
echo Enter QT binary location (exemple: C:\Program Files (x86)\QT\5.15.2\mingw81_64\bin )
set /p QT_Location=

setx GNUPLOT_PATH "%Gnuplot_Location%"
setx QT_PATH "%QT_location%"
setx GHOSTSCRIPT_PATH "%GhostScript_Location%"
setx PYTHON_PATH "%Python_Location%"
pause
set PATH="%Python_Location%";"%PATH%"
python -m pip install -U pip
python -m pip install -U matplotlib
python -m pip install PyQt5
echo.
echo Installation completed.
pause
