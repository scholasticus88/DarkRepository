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
SET LANG="CSharp"
SET PROJECT_DIR=%1
SET OUTPUT_DIR=%PROJECT_DIR%\Generated

rem ==========================================================================
rem ==========================================================================

SET GRAMMAR_EXT=%~x2
IF NOT "%GRAMMAR_EXT%" == ".g4" (
   echo Wrong file "%2" as input.
   goto error;
)
SET GRAMMAR=%2

java -jar %ANTLR% %PROJECT_DIR%\%GRAMMAR% -Dlanguage=%LANG% -visitor -o %OUTPUT_DIR%

:error
