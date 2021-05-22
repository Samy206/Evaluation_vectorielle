set PATH="%GHOSTSCRIPT_PATH%\bin";"%GHOSTSCRIPT_PATH%\lib"
gswin64c -q -P- -dSAFER -dNOPAUSE -dBATCH -sDEVICE=pdfwrite -sOutputFile=%2 -c -f %1
gswin32c -q -P- -dSAFER -dNOPAUSE -dBATCH -sDEVICE=pdfwrite -sOutputFile=%2 -c -f %1
exit