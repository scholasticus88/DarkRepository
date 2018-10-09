@echo off
rem ANTLR SETUP:   https://tomassetti.me/category/language-engineering/antlr/#setup-antlr
rem                https://github.com/antlr/antlr4/blob/master/doc/getting-started.md
rem ANTLR DWNLD:   http://www.antlr.org/download/
rem ANTLR RUNTIME: http://www.antlr.org/download/
rem MEGA TUTORIAL: https://tomassetti.me/antlr-mega-tutorial/

rem ==========================================================================
rem ==========================================================================

SET ANTLR_PATH="C:\Program Files\Java\libs\"
SET ANTLR_JAR="antlr-4.7.1-complete.jar"
SET ANTLR="%ANTLR_PATH%%ANTLR_JAR%"
SET CLASSPATH=.;%ANTLR%;%CLASSPATH%
SET TESTRIG=org.antlr.v4.gui.TestRig

SET PROJECT=%1
SET RULE=%2

SET OUTDIR="%PROJECT%\Genegated"
SET OUTDIR_CODE="%OUTDIR%\Code"
SET OUTDIR_BIN="%OUTDIR%\Bin"

rem ==========================================================================
rem ==========================================================================

IF NOT EXIST %OUTDIR% (
   echo Directory %OUTDIR% doesn't exist.
   goto error;
)

cd %OUTDIR_BIN%

java %TESTRIG% %PROJECT% %RULE% -tree -gui -tokens

cd ..\..\..