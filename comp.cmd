@echo off
rem ANTLR SETUP:   https://tomassetti.me/category/language-engineering/antlr/#setup-antlr
rem                https://github.com/antlr/antlr4/blob/master/doc/getting-started.md
rem ANTLR DWNLD:   http://www.antlr.org/download/
rem ANTLR RUNTIME: http://www.antlr.org/download/
rem MEGA TUTORIAL: https://tomassetti.me/antlr-mega-tutorial/

rem ==========================================================================
rem ==========================================================================

SET ANTLR_PATH="C:\Program Files\Java\libs"
SET ANTLR_JAR="antlr-4.7.1-complete.jar"
SET ANTLR="C:\Program Files\Java\libs\antlr-4.7.1-complete.jar"
SET CLASSPATH=.;%ANTLR%;%CLASSPATH%
SET TESTRIG=org.antlr.v4.gui.TestRig
SET LANG="Java"

SET PROJECT=%1
SET OUTDIR="%PROJECT%\Genegated"
SET OUTDIR_CODE="%OUTDIR%\Code"
SET OUTDIR_BIN="%OUTDIR%\Bin"

rem ==========================================================================
rem ==========================================================================

SET GRAMMAR_EXT=%~x2
IF NOT "%GRAMMAR_EXT%" == ".g4" (
   echo Wrong file "%2" as input.
   goto error;
)
SET GRAMMAR=%2

IF EXIST %OUTDIR% (
   echo Directory %OUTDIR% already exists.
   goto error;
)
mkdir %OUTDIR%

IF EXIST %OUTDIR_CODE% (
   echo Directory %OUTDIR_CODE% already exists.
   goto error;
)
mkdir %OUTDIR_CODE%

IF EXIST %OUTDIR_BIN% (
   echo Directory %OUTDIR_BIN% already exists.
   goto error;
)
mkdir %OUTDIR_BIN%

java -jar %ANTLR% %PROJECT%\%GRAMMAR% -Dlanguage=%LANG% -no-listener -visitor -o %OUTDIR_CODE%
copy %OUTDIR_CODE%\%PROJECT%\*.* %OUTDIR_CODE%
rmdir %OUTDIR_CODE%\%PROJECT% /S /Q

rem IF %LANG% == "Java" (
rem 	javac -d %OUTDIR_BIN% %OUTDIR_CODE%\*.java
rem )

:error
